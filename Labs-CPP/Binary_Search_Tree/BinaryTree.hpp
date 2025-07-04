#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>

#include "DebugTreeObject.hpp"                                  // Дополнительный пользовательский класс.

// Шаблонный класс двоичного дерева поиска, с ограничениями в 16-ть бит для параметров и памяти.
// Блокировка многопоточности происходит относительно всего дерева на чтение/запись.
// Исключения только по памяти, классы "итератора" и "узла" вложенны.

// Основной класс дерева шаблон по типу, узел создаем по динамической памяти, а объект копированем значения.
template<typename T>
class BinarySearchTree {
public:
    class Node;
    friend class Iterator;
    enum Object { Word = 0, Float = 1, Class = 2, NotO = 3 };
    enum Search { LeftNodeRight = 0, RightNodeLeft = 1, NotS = 3 };
    // Конструктор по умолчанию, тип объекта вспомогательно, с исключением по памяти.
    explicit BinarySearchTree(Object type) {
        if (sizeof(T) > memoryMax)
            throw("Not enough memory for another object or object is more than 32kb.");
        if (type >= Object::NotO)
            objectsType = Object::Word;
        std::cout << "Default BST constructor, just set to defaults, address (" << this << ") " <<
                     "and reset root of nested class 'Node', type " << typeNames[type] << " nodes.\n";
        dataSize = 0;  objectsType = type; root = nullptr; isReadLock = isWriteLock = false;
    }
    // Конструктор со списком инициализации, исключение по памяти.
    explicit BinarySearchTree(Object type, std::initializer_list<T> list) {
        if (sizeof(T) * list.size() > memoryMax)
            throw("Not enough memory for list of objects.");
        if (type >= Object::NotO)
            type = Object::Word;
        std::cout << "BST constructor with initialize list, objects to create " << list.size() <<
                     ", type '" << typeNames[type] << "': ";
        for (const T* it = list.begin(); it != list.end(); ++it)
            std::cout << *it << " ";
        std::cout << ", size of node " << sizeof(Node) << " bytes.\n";
        dataSize = 0; root = nullptr; objectsType = type; isReadLock = isWriteLock = false;
        for (const T* it = list.begin(); it != list.end(); ++it)
            add(*it);
        std::cout << "Initial size of tree using list is " << dataSize <<
                     " nodes and " << sizeof(Node) * dataSize << " bytes.\n";
    }
    // Копирующий конструктор, создание нового объекта, с исклчюением.
    BinarySearchTree(BinarySearchTree& rv) {
        if (rv.size() * sizeof(T) > memoryMax)
            throw("Not enough memory for copy tree, clear some memory.");
        dataSize = 0; objectsType = rv.objectsType;
        root = nullptr; isReadLock = isWriteLock = false;
        if (!rv.isReadLock) {
            std::cout << "Copy BST constructor, create new copy of all " << rv.size() << " elements.\n";
            std::vector<Node*> nodes;
            rv.traverse(nodes);
            std::cout << "Copy all nodes from right-value tree to left-value tree.\n";
            for (short idx = 0; idx < (short)nodes.size(); ++idx)
                add(nodes[idx]->getData());
        } else
            std::cout << "Warning, other object is writing, create only empty copy.\n";
    }
    // Конструктор перемещения, без исключений, т.к. память условно не расходуется на новый объект.
    BinarySearchTree(BinarySearchTree&& rv) noexcept {
        std::cout << "Moving BST constructor, without create new objects in dynamic memory. ";
        isReadLock = rv.isReadLock; isWriteLock = rv.isWriteLock;
        dataSize = 0; root = nullptr; objectsType = rv.objectsType;
        if (rv.size() > 0) {
            std::cout << "Moving root element " << rv.root->getData() << "without others.\n";
            root = new Node(*rv.getRoot());
            delete(rv.getRoot());
        } else
            std::cout << "Tree is empty, nothing to move.\n";
    }
    // Виртуальный деструктор, вызывает функцию по заданию.
    virtual ~BinarySearchTree() {
        std::cout << "Virtual BST destructor, free all objects from dynamic memory.\n";
        if (dataSize > 0)
            clear();
    }
    // Добавление элемента в дерево, блокирует дерево на запись, исключение при нехватке памяти, использует поиск.
    short add(const T& obj) {
        // Добавление объекта в дерево и выделение для него динамической памяти в виде узла(class Node).
        // Исходный объект по адресу должен существовать и правила сравнения объектов определены.
        if ((short)(memorySize + sizeof(T)) < 0) {
            std::cout << "Not enough memory to add object size " << sizeof(T) << ", free memory " << memoryFree << ".\n";
            throw("Not enough memory to add object");
        }
        if (isWriteLock)
            std::cout << "Can't add node and write to tree because other thread is reading this object.\n";
        isReadLock = true;
        std::cout << "Add object " << obj << " to tree size " << size() << ", object '" << obj << "'.\n";
        Node *near, *leaf;
        if (size() > 0) {
            near = search(obj, true);
            if (near->getData() == obj) {                          // Операция сравнения.
                std::cout << "Node, object data is already in tree, nothing to add.\n";
                isReadLock = false;
                return 3;
            } else {
                if (near->getData() > obj) {
                    std::cout << "Nearest node " << *near << " is more than object, add to left leaf.\n";
                    leaf = new Node(obj, near); // for out
                    near->setLeft(leaf);
                    /*
                    std::cout << "Check node: " << *leaf << ", ptrs: " << leaf->getPrevious() << ":" << leaf->getLeft()
                              << ":" << leaf->getRight() << std::endl;
                              */
                }
                if (near->getData() < obj) {
                    std::cout << "Nearest node " << *near << " is less than object, add to right leaf.\n";
                    leaf = new Node(obj, near);
                    near->setRight(leaf);
                    /*
                    std::cout << "Check node: " << *leaf << ", ptrs: " << leaf->getPrevious() << ":" << leaf->getLeft()
                              << ":" << leaf->getRight() << std::endl;
                              */
                }
            }
        } else {
            root = new Node(obj, nullptr);
            std::cout << "Tree is empty add node as root at " << root << "\n";
        }
        dataSize++; memorySize += sizeof(T); memoryFree -= sizeof(T);
        isReadLock = false;
        return 0;
    }
    // Добавление дерева в другое дерево, исключение по памяти.
    void addTree(const BinarySearchTree& tree) {
        if (tree.size() == 0 || (short)(memoryMax - memorySize) < (short)(tree.size() * sizeof(T))) {
            std::cout << "Adder tree is empty or not enough memory " << memoryMax - memorySize << " bytes.\n";
            throw("Adder tree is empty or not enough memory.");
        }
        std::cout << "Add full tree size " << tree.size() << "this tree size " << size() << ".\n";
        std::vector<Node*> nodes;
        tree.traverse(nodes);
        for (short idx = nodes.size() - 1; idx >= 0; --idx)
            add(nodes[idx]->getData());
    }
    // Очистка всех элементов дерева по памяти, зануление параметров самого дерева.
    void clear() noexcept {     // Очистка всех узлов в дереве.
        if (size() == 0) {
            std::cout << "Clear tree not needed, tree is empty.\n";
            return;
        }
        std::cout << "Clear tree, size " << size() << "and memory " << size() * sizeof(T) << " bytes.\n";
        std::vector<Node*> nodes;
        traverse(nodes);
        std::cout << "Clear memory for all nodes:\n";
        for (short idx = 0; idx < (short)nodes.size(); ++idx)
            delete(nodes[idx]);
        root = nullptr; dataSize = 0;
    }
    // Чтение корневого узла, константный метод.
    Node* getRoot() const {                                     // Просто возвращаем корень.
        return root;
    }
    // Поиск поддерева по дереву, без исключений. Создает новый объект дерева.
    unsigned short findTree(BinarySearchTree<T>& src, const T& obj) noexcept {
        if (src.size() == 0 || size() != 0) {
            std::cout << "Get tree error, source is empty or destination not empty.\n";
            return 0;   // Количество узлов.
        }
        Node* leaf = src.search(obj, false);
        if (leaf == nullptr) {
            std::cout << "Error get tree, object " << obj << "not founded in tree.\n";
            return 0;
        }
        root = new Node(*leaf);
        root->setPrevious(nullptr); // cut.
        dataSize = 1;
        std::vector<Node*> nodes;
        short subNodes = traverse(nodes);
        std::cout << "Size of new tree is " << dataSize << std::endl;
        root->setLeft(nullptr); root->setRight(nullptr);    // only object
        for (short i = 1; i < subNodes; ++i)
            add(nodes[i]->getData());
        return 0;
    }
    // Поиск объекта по типу в дереве. Тип обхода по-умолчанию слева-направо. Без исключений.
    // Флаг форсирования необходим для замка, при фактическом вызове функции чтения, чтобы не дублировать код.
    Node* search(const T& obj, bool isOverride, Search type = LeftNodeRight) noexcept {
        if (size() == 0 || type >= NotS) {
            std::cout << "Error search object [" << obj << "] tree is empty or type incorrect.\n";
            return nullptr;
        }
        if (isReadLock && !isOverride)
            std::cout << "Can't search node from tree because other thread is writing to this object.\n";
        isWriteLock = true;
        Node* leaf = root;
        std::cout << "Searching from root [" << root->getData() << "], object [" << obj << "], ";
        bool isLeafExist = true;                           // Результат сравнения и флаг пути или усложнить условие.
        unsigned short it = 0;
        while (!(leaf->getData() == obj) && isLeafExist) {
            if (type == LeftNodeRight) {
                if (leaf->getData() > obj) {
                    ++it;
                    if (leaf->getLeft() != nullptr)
                        leaf = leaf->getLeft();
                    else
                        isLeafExist = false;
                }
                if (leaf->getData() < obj) {
                    ++it;
                    if (leaf->getRight() != nullptr)
                        leaf = leaf->getRight();
                    else
                        isLeafExist = false;
                }
            }
            if (type == RightNodeLeft) {
                if (leaf->getData() < obj) {
                    ++it;
                    if (leaf->getRight() != nullptr)
                        leaf = leaf->getRight();
                    else
                        isLeafExist = false;
                }
                if (leaf->getData() > obj) {
                    ++it;
                    if (leaf->getLeft() != nullptr)
                        leaf = leaf->getLeft();
                    else
                        isLeafExist = false;
                }
            }
        }
        if (isLeafExist)
            std::cout << "leaf is exist, iterations " << it << "\n";
        else
            std::cout << "leaf not exist nearest is " << *leaf << ", iterations " << it << ".\n";
        isWriteLock = false;
        return leaf;
    }
    // Метод получения размера дерева по количеству элементов, константный.
    short size() const {
        return dataSize;
    }
    // Удаление элемента дерева, используем вспомогательную функцию замены узла дерева.
    short sub(const T& obj) noexcept {
        if (isWriteLock)
            std::cout << "Can't sub from tree, because other thread is reading.\n";
        else
            isReadLock = true;
        std::cout << "Sub node [" << obj << "] from tree size " << size() << ".\n";
        if (size() == 0) {
            std::cout << "Error sub node, tree is empty.\n";
            return 1;
        }
        Node* leaf = search(obj, true);
        if (leaf->getData() != obj) {
            std::cout << "Node to sub is not found in tree, nothing to delete.\n";
            return 1;
        }
        std::cout << "Node with object founded in tree, define case of tree subtraction.\n";
        if (leaf->getLeft() == nullptr && leaf->getRight() == nullptr) {
            std::cout << "Both derived nodes are nullptr, so just delete node and free memory.";
            replaceNode(leaf, nullptr);
        } else if (leaf->getLeft() == nullptr && leaf->getRight() != nullptr) {
            std::cout << "Only right derived node is exist, moving it upper to deleted node.\n";
            replaceNode(leaf, leaf->getRight());
        } else if (leaf->getLeft() != nullptr && leaf->getRight() == nullptr) {
            std::cout << "Only left derived node is exist, moving it upper to deleted node.\n";
            replaceNode(leaf, leaf->getLeft());
        } else if (leaf->getLeft() != nullptr && leaf->getRight() != nullptr) {
            std::cout << "Both derived nodes are exists, ";
            if (leaf->getRight()->getLeft() == nullptr)  {
                std::cout << "from right derived -> left-derived not exist, just replace deleted node by right.\n";
                Node *prevR = leaf->getRight(), *prevL = leaf->getLeft();
                replaceNode(leaf, prevR);
                if (prevL != nullptr)
                    prevR->setLeft(prevL);
            } else if (leaf->getRight()->getLeft() != nullptr) {
                std::cout << "from right derived -> left-derived is exist, replace deleted by this node.\n";
                Node *prevR = leaf->getRight(), *prevRL = leaf->getRight()->getLeft(), *prevL = leaf->getLeft();
                replaceNode(leaf, leaf->getRight()->getLeft());
                if (prevL != nullptr)
                    prevRL->setLeft(prevL);
                if (prevR != nullptr)
                    prevRL->setRight(prevR);
                prevR->setLeft(nullptr);
            }
        }
        dataSize--;
        memorySize -= sizeof(T); memoryFree += sizeof(T);
        isReadLock = false;
        return 0;
    }
    // Метод обхода дерева, по заданному типу. По-умолчанию слева-направо. Константный.
    // На вход ссылка массива адресов всех узлов, которые нашлись в дереве.
    unsigned short traverse(std::vector<Node*>& nodes, Search type = Search::LeftNodeRight) const {
        nodes.clear();
        if (size() == 0) {
            std::cout << "Can't traverse tree, tree is empty.\n";
            return 0;
        }
        std::vector<Node*> stack = { root };
        unsigned short iterations = 0, stackTop;
        std::cout << "Traverse tree size " << dataSize << ", using traverse type '" << searchNames[type] << "'.\n";
        Node* leaf;
        for (stackTop = stack.size(); !stack.empty(); ++iterations) {
            if (stackTop <= indexMax && nodes.size() <= indexMax) {
                leaf = stack[stack.size() - 1];
                stack.pop_back();
                std::cout << "Pop leaf object " << leaf->getData()
                          << ", stack size " << stack.size() << std::endl;
                nodes.push_back(leaf);
            } else {
                std::cout << "Error traverse tree, stack << " << stackTop
                          << " or list of nodes << " << nodes.size() << " is full.\n";
                return 0;
            }
            if (type == LeftNodeRight) {                        // remake, works fine.
                if (leaf->getLeft()) {
                    stack.push_back(leaf->getLeft());
                    std::cout << "Push left leaf object " << leaf->getLeft()->getData()
                              << ", stack size " << stack.size() << std::endl;
                }
                if (leaf->getRight()) {
                    stack.push_back(leaf->getRight());
                    std::cout << "Push right leaf object " << leaf->getRight()->getData()
                                 << ", stack size " << stack.size() << std::endl;
                }
            }
            if (type == RightNodeLeft) {
                if (leaf->getRight()) {
                    stack.push_back(leaf->getRight());
                    std::cout << "Push right leaf object " << leaf->getRight()->getData()
                              << ", stack size " << stack.size() << std::endl;
                }
                if (leaf->getLeft()) {
                    stack.push_back(leaf->getLeft());
                    std::cout << "Push left leaf object " << leaf->getLeft()->getData()
                              << ", stack size " << stack.size() << std::endl;
                }
            }
        }
        return iterations;
    }
    // Возвращает имя типа, который был создан для дерева. Для пользовательского класса "Class".
    std::string typeName() const {
        return typeNames[objectsType];
    }
    // Вложенный класс узла данных для дерева. Удобней создавать объекты или удалять их из динамической памяти.
    class Node {
    public:
        // Конструктор, предыдущий элемент может существовать или это условный корень.
        explicit Node(const T& obj, Node* prev = nullptr) {
            std::cout << "Node constructor set object to " << obj <<
                         ", size " << sizeof(T) << " and all pointers to nullptr.\n";
            object = obj; previous = prev; left = right = nullptr;
        }
        // Копирующий конструктор создает объект, оператор присвоения должен быть определен.
        Node(const Node& rv) {
            std::cout << "Copy constructor for node with object " << rv << ".\n";
            object = rv.object; previous = rv.previous; left = rv.left; right = rv.right;
        }
        // Деструктор заполняет параметры указателей, объект удаляется автоматически при освобождении памяти.
        ~Node() {
            std::cout << "Node destructor object " << object << ", set all pointers to nullptr.\n";
            previous = left = right = nullptr;
        }
        // Стандартные методы чтения параметров узла и его указателей, отдельно чуть удобнее.
        const T& getData() const {
            return object;
        }
        Node* getLeft() const {
            return left;
        }
        Node* getPrevious() const {
            return previous;
        }
        Node* getRight() const {
            return right;
        }
        // Стандартные методы записи параметров узла и его указателей, отдельно чуть удобнее.
        void setData(const T& obj) {                            // Вывод требовался для отладки, не обязательно.
            object = obj;
            std::cout << "Set node object to new [" << object << "].\n";
        }
        void setPrevious(Node* pn) {
            if (pn != nullptr)
                std::cout << "Set node " << *this << " previous to " << pn->getData() << ".\n";
            else
                std::cout << "Set node " << *this << " previous to null pointer.\n";
            previous = pn;
        }
        void setLeft(Node* ln) {
            if (ln != nullptr)
                std::cout << "Set node " << *this << " left to " << ln->getData() << ".\n";
            else
                std::cout << "Set node " << *this << " left to null pointer.\n";
            left = ln;
        }
        void setRight(Node* rn) {
            if (rn != nullptr)
                std::cout << "Set node " << *this << " right to " << rn->getData() << ".\n";
            else
                std::cout << "Set node " << *this << " right to null pointer.\n";
            right = rn;
        }
        // Перегрузка операторов сравнения и вывода для узла, также работает и для пользовательского класса.
        friend bool operator<(const Node& lv, const Node& rv) {
            return (lv.object < rv.object);
        }
        friend bool operator>(const Node& lv, const Node& rv) {
            return (lv.object > rv.object);
        }
        friend bool operator==(const Node& lv, const Node& rv) {
            return (lv.object == rv.object);
        }
        friend std::ostream& operator<<(std::ostream& os, const Node& rv) {
            os << "[" << rv.object << "]";
            return os;
        }
    private:                                                    // Данные закрыты, конструктор объекта должен существовать.
        T object;
        Node *previous, *left, *right;
    };
    // Класс итератора, движение только в прямом лево-право направлении по дереву от корня.
    class Iterator {
    public:
        Iterator(BinarySearchTree<T>& t) : tree(t), it(t.root) {
            std::cout << "Iterator constructor, tree root " << it->getData() << "\n";
        }
        void nextL() {                                          // Следующий влево.
            std::cout << "Iterator next to left, object " << it->getData();
            if (it->getLeft() != nullptr) {
                it = it->getLeft();
                std::cout << " to " << it->getData() << std::endl;
            } else
                std::cout << " to nullptr.\n";
        }
        void nextR() {                                          // Следующий вправо.
            std::cout << "Iterator next to right, object " << it->getData();
            if (it->getRight() != nullptr) {
                it = it->getRight();
                std::cout << " to " << it->getData() << std::endl;
            } else
                std::cout << " to nullptr.\n";
        }
        ~Iterator() {
            std::cout << "Iterator default destructor.\n";
        }
        friend T operator*(const Iterator& rv) {                // Оператор взятия содержимого по адресу, или чтения.
            std::cout << "Reading using iterator and overloaded '<<' for object ";
            return rv.it->getData();
        }
    private:
        BinarySearchTree<T>& tree;                              // Ссылки и адреса для удобства.
        Node* it;
    };
    // Перегруженный оператор добавления элемента, аналогичен обычному методу.
    friend void operator<<(BinarySearchTree<T>& tree, const T& object) {
        std::cout << "Add node using overloading operator '<<'.\n";
        tree.add(object);
    }
    // Перегруженный оператор добавления дерева, аналогичен обычному методу.
    friend void operator<<(BinarySearchTree<T>& dst, const BinarySearchTree<T>& src) {
        std::cout << "Add source tree to destination tree using overloaded 'operator<<'.\n";
        dst.addTree(src);
    }
    // Перегруженный оператор вывода дерева, по уровням и точкам, не более 16 уровней, а то выйдем за пределы.
    friend std::ostream& operator<<(std::ostream& os, BinarySearchTree<T>& tree) {
        // Вывод по уровням с отступами.
        std::cout << "Print all " << tree.size() << " nodes in tree type '" << tree.typeName()
                  << "', size in bytes " << tree.size() * sizeof(Node) << ".\n";
        if (tree.dataSize == 0) {
            std::cout << "Tree is empty, nothing to output.\n";
            return os;
        }   // 1, 2(8), 4(16), 8(32), 16(64), 32(128).
        std::vector<Node*> level, prevLevel;
        level.push_back(tree.root);
        unsigned char levTabs = screen, isAnyNode = 1;
        for (short lev = 1, i; lev <= (short)levPrintMax && isAnyNode; ++lev) {
            std::string line(screen, '.');
            unsigned char lPos = screen >> lev;
            for (i = 0; i < (short)level.size(); ++i) {
                if (level[i] != nullptr) {
                    std::string txtObj = DTO::to_string(level[i]->getData());
                    line.replace(lPos, txtObj.size(), txtObj);
                }
                lPos += (levTabs);
            }
            levTabs >>= 0x01;
            std::cout << line << std::endl;
            prevLevel.clear();
            prevLevel = level;
            level.clear();
            for (i = 0; i < (short)prevLevel.size(); ++i) {
                if (prevLevel[i] != nullptr) {
                    level.push_back(prevLevel[i]->getLeft());
                    level.push_back(prevLevel[i]->getRight());
                } else {
                    level.push_back(nullptr);
                    level.push_back(nullptr);
                }
            }
            isAnyNode = 0;
            for (short i = 0; i < (short)level.size() && !isAnyNode; ++i)
                if (level[i] != nullptr)
                    isAnyNode = 1;
        }
        std::cout << std::endl;
        return os;
    }
    // Перегруженный оператор сравнения деревьев.
    friend bool operator==(BinarySearchTree<T>& lv, BinarySearchTree<T>& rv) {
        // Сравнение значений как в строке и если одно дерево больше другого, то только если равны.
        if (lv.size() == 0 || rv.size() == 0 || lv.size() != rv.size()) {
            std::cout << "Comparing trees are empty or not equal in size.\n";
            return false;
        }
        std::cout << "Compare for equality tree with root " << lv.root->getData()
                  << " and with root " << rv.root->getData() << std::endl;
        std::vector<Node*> lNodes, rNodes;
        lv.traverse(lNodes); rv.traverse(rNodes);
        std::cout << "Size of left tree " << lv.size() << " and right " << rv.size() << std::endl;
        bool isEqual = true;
        for (short i = 0, j; i < lv.size() && isEqual; ++i) {
            for (j = 0, isEqual = false; j < rv.size(); ++j)
                if (lNodes[i]->getData() == rNodes[j]->getData())
                    isEqual = true;
        }
        return isEqual;
    }
    // Оператор неравенства, вызвыает сравнение на равенство с отрицанием.
    friend bool operator!=(BinarySearchTree<T>& lv, BinarySearchTree<T>& rv) {
        std::cout << "Comparing trees with operator '!=', using not '=='.\n";
        return !(lv == rv);
    }
    // Статичные константные выражения для пределов и вывода.
    static constexpr unsigned short memoryMax = 0x8000;
    static constexpr unsigned short indexMax = 0x7FFF;
    static constexpr unsigned short objectMax = 0x0100;
    static constexpr const unsigned char levPrintMax = 0x10;
    static constexpr unsigned char typesSupported = 0x03;
    static constexpr unsigned char searchSupported = 0x02;
    static constexpr unsigned char screen = 0x80;
    // Названия методов обхода и поддерживаемых типов данных определены как статичные ниже.
    static unsigned short memorySize, memoryFree;
    static std::vector<std::string> typeNames;
    static std::vector<std::string> searchNames;
private:
    unsigned short dataSize;                                    // Количество элементов.
    Object objectsType;
    Node* root;
    bool isReadLock, isWriteLock;
    BinarySearchTree& operator=(const BinarySearchTree& rv);
    // Вспомогательный метод замены одного узла на другой в дереве при удалении элемента. Переработать.
    void replaceNode(Node* dst, Node* src) noexcept {
        // Замена в дереве узлов, источник после перемещения удаляется или изначально не существует.
        if (dst == nullptr)
            std::cout << "Error node replace, destination node is nullptr.\n";
        Node* prevDst = dst->getPrevious(); // *prevSrc, *leftSrc, *rightSrc;
        /*
        if (src != nullptr) {   // remake.
            // prevSrc = src->getPrevious();
            leftSrc = src->getLeft();
            rightSrc = src->getRight();
        } else
            prevSrc = leftSrc = rightSrc = nullptr;
            */
        if (prevDst != nullptr) {
            // std::cout << "YA! " << src << "\n";
            if (prevDst->getLeft() == dst)
                prevDst->setLeft(src);
            if (prevDst->getRight() == dst)
                prevDst->setRight(src);
        }   // rethink.
        /*
        if (leftSrc == nullptr && dst->getLeft() != nullptr) {
            src->setLeft(dst->getLeft());
            // std::cout << "EW!\n";
            // or for more complex.
            std::cout << "Prev: " << src->getRight()->getPrevious() << ".\n";
            if (prevSrc != dst) {
                std::cout << "PR! " << src << "\n";
                prevSrc->setLeft(rightSrc);
            }
        }*/
        delete(dst);
        if (prevDst == nullptr) {     // if root node.
            root = src;
            std::cout << "Destination is root, new object " << *root << " set as root.\n";
            // std::cout << *getRoot() << ":" << getRoot() << ":" << *dst << std::endl;
        }
        if (src != nullptr)
           src->setPrevious(prevDst);
    }
};

// Статичные атрибуты класса с инициализацией, т.к. класс шаблонный.
template<typename T> unsigned short BinarySearchTree<T>::memorySize = 0;
template<typename T> unsigned short BinarySearchTree<T>::memoryFree = 0;
template<typename T> std::vector<std::string> BinarySearchTree<T>::typeNames =
{ "word", "float", "class", "not an object" };
template<typename T> std::vector<std::string> BinarySearchTree<T>::searchNames =
{ "LeftNodeRight", "RightNodeLeft", "not a search" };
