#include <iostream>
#include <chrono>
#include <future>
#include <climits>

#include "BinaryTree.hpp"

//  Бинарное дерево поиска с динамической памятью, потоки дополнительно, компиляция в 32 бита.
//  Все ограничения по памяти и индексам 16 бит и/или 64(32)кб - 1, по объектам - 8 бит или 256 байт.
//  Операторы сравнения, для класса или встроенного типа должны быть определены.
//  Методы учаавствуют как в поиске элемента, так и полном обходе дерева.
//  Конвертация объекта в строку оформлено в виде перегрузки оператора "std::to_string" в
// пространстве имён ODT.
//  Встроенные классы "Узлов" и "Итераторов" реализованы с минимальным набором методов.

//  Исходное задание, лабораторная №2, 3-ий семестр.
//  Реализовать шаблонный класс потокобезопасного двоичного дерева поиска (BST) со следующими методами:
// a) конструктор, по умолчанию, конструктор копирования, конструктор перемещения,
//конструктор со списком инициализации, конструктор с итераторами, деструктор;
// b) различные обходы ЛКП и так далее, элементы помещать в контейнер;
// c) добавление нового элемента, добавление поддерева add();
// d) добавление перегрузкой оператора << (одного элемента и поддерева);
// e) найти элемент find();
// f) вернуть поддерево (задается корень поддерева) findTree();
// g) распечатать (перенаправление вывода <<);
// h) удалить элемент и очистить дерево delete(), clear();
// i) для обработки ошибок используйте исключения;
// j) операторы сравнения == и !=;
//  Выделить методы, которые не кидают исключения и константные методы. Проверить работу структуры
// на типах int, double, class c операторами сравнения. Дерево должно использоваться несколькими потоками.
// Протестировать все методы и сделать бенчмарки.

using namespace std;

BinarySearchTree<float> returnTree(BinarySearchTree<short> tree)
{
    cout << "\nDebug copy and moving constructor for BST objects, check copied tree:\n" << tree;
    BinarySearchTree<float> movingFloatTree(BinarySearchTree<float>::Object::Float);
    movingFloatTree.add(0.5); movingFloatTree.add(0.2); movingFloatTree.add(0.7);
    return movingFloatTree;
}

int main()
{   // Основной код, тестируем класс бинарного дерева поиска и выводим общую информацию.
    cout << "Binary Search Tree, 16-bits version. Compile GCC 8.1.0, 32 bits.\n";
    // Тестирование кострукторов и деструкторов дерева с использованием короткого целого.
    short i;
    unsigned short r;
    cout << "Supported types for nodes: ";
    for (i = 0; i < (short)BinarySearchTree<short>::typeNames.size() - 1; ++i)
        cout << "'" << BinarySearchTree<short>::typeNames[i] << "' ";
    cout << "\nSupported searches(traverses) types: ";
    for (i = 0; i < (short)BinarySearchTree<short>::searchNames.size() - 1; ++i)
        cout << "'" << BinarySearchTree<short>::searchNames[i] << "' ";
    // Тестирование всех конструкторов. По-умолчанию, со списком, копирующего и перемещающего и декструкторы.
    std::cout << "\n\n\nCalling all constructors and destructors.\n\n\n";
    BinarySearchTree<short> bstA(BinarySearchTree<short>::Object::Word);
    cout << "Check type name of tree: '" << bstA.typeName() << "', size " << bstA.size() << " elements.\n\n";
    initializer_list<short> init = { 8, 3, 5, 4, 6, 7, 2, };
    BinarySearchTree<short> bstB(BinarySearchTree<short>::Object::Word, init);
    cout << "\nCheck tree, printing all elements.\n" << bstB;
    BinarySearchTree<float> bstC = returnTree(bstB);
    cout << "\nCheck tree after moving optimization.\n" << bstC;
    cout << "Testing add trees using operator '<<'.\n\n";
    BinarySearchTree<short> bstD(BinarySearchTree<short>::Object::Word, { 1, 0 });
    vector<BinarySearchTree<short>::Node*> nodes;
    bstB << short(9); bstB << bstD;
    cout << "\nResult tree:\n" << bstB;
    // Обход дерева количество, итераций для каждого из методов.
    cout << "\nTesting all types of traverse tree and performance.\n\n";
    cout << "\nSource tree for all traverses:\n" << bstB;
    r = bstB.traverse(nodes, BinarySearchTree<short>::Search::LeftNodeRight);
    cout << "All nodes(in reverse) object after traverse, iterations " << r << ": ";
    for (i = 0; i < (short)nodes.size(); ++i)
         cout << nodes[i]->getData() << " ";
    cout << "\n\n";
    r = bstB.traverse(nodes, BinarySearchTree<short>::Search::RightNodeLeft);
    cout << "All nodes(in reverse) object after traverse, iterations " << r << ": ";
    for (i = 0; i < (short)nodes.size(); ++i)
         cout << nodes[i]->getData() << " ";
    cout << "\n\n\nTrying to sub nodes with various cases of tree.\n\n";
    cout << "\nSource tree with all elements:\n" << bstB;
    vector<short> delObj = { 9, 2, 0, 5, 3, 8 };
    for (i = 0; i < (short)delObj.size(); ++i) {
        bstB.sub(delObj[i]);
        cout << bstB;
    }
    // Тестирование удаления дерева целиком, очистки всех узлов.
    bstB.clear();
    cout << "\nAfter clear tree and all nodes, free dynamic memory.\n" << bstB << endl;
    // Получение поддерева из исходного дерева, создаем заново исходники.
    cout << "\nGet sub-tree from last tree, new root is 2.\n\n\n";
    BinarySearchTree<short> bstE(BinarySearchTree<short>::Object::Word, { 5, 8, 6, 2, 4, 3, 1 });
    // BinarySearchTree<short> bstF(BinarySearchTree<short>::Object::Word);
    cout << "\n" << bstE;
    bstB.findTree(bstE, 2);
    cout << "\nResult of sub-tree:\n" << bstB;
    // Тестирование произвольного класса и итератора.
    cout << "\n\nTesting tree and custom class with operators '<', '>', '=='.\n\n";
    BinarySearchTree<DebugTreeObject> bstF(BinarySearchTree<DebugTreeObject>::Object::Class);
    string txt = "DBACE";
    for (short i = 0; i < (short)txt.size(); ++i)
        bstF.add(txt[i]);
    cout << "Check with class 'DebugBinaryTree', tree A and iterators:\n" << bstF;
    BinarySearchTree<DebugTreeObject>::Iterator it(bstF);
    it.nextL(); it.nextR();
    cout << *it << endl;
    cout << "\nCreate copy of tree A and compare elements in them.\n\n";
    BinarySearchTree<DebugTreeObject> bstG(bstF);
    cout << "Check with class, tree B.\n" << bstG;
    cout << "\nCompare trees A and B with operator '==' or '!=' as wished.\n\n";
    bool cmp = (bstF == bstG);
    cout << "\nResult of trees compare operator '==': " << cmp << endl;
    // Исключение, попытка сконструировать объект более 32Кб.
    cout << "\n\nCatching exception, trying to construct very big object.\n\n\n";
    try {
        BinarySearchTree<short[USHRT_MAX]> bstI(BinarySearchTree<short[USHRT_MAX]>::Object::Class);
    } catch (const char* error) {
        cout << "Exception: " << error << endl;
    }
    // Тестирование простых замков на чтение или запись, в многопотоке.
    cout << "\n\nSimple threaded demo with locks. Warning, if CPU fast enough,"
         << "lock may be unlocked, check output, if unordered - it's work correctly.\n\n";
    cout << bstE;
    future<void> readingTask = async(launch::async, [&bstE]{
        cout << "\nSearching node in tree in different thread, while calling add object.\n";
        BinarySearchTree<short>::Node* leaf = bstE.search(3, false);
        cout << "\nNode from search (3), check object " << *leaf << ".\n";
    });
    bstE.add(7); readingTask.get();  //  // if defered, sync
    cout << "After threaded reading/writing.\n" << bstE;
    // Условная производительность для базовых операций, только если есть параметр командной строки.
    cout << "\nBenchmark core functions: 'Add', 'Traverse' and 'Sub' in milliseconds.\n\n\n";
    chrono::system_clock::time_point bench[4];
    bench[0] = chrono::high_resolution_clock::now();
    bstE.add(0);
    bench[1] = chrono::high_resolution_clock::now();
    bstE.traverse(nodes);
    bench[2] = chrono::high_resolution_clock::now();
    bstE.sub(5);
    bench[3] = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> bAdd = bench[1] - bench[0], bTraverse = bench[2] - bench[1], bSub = bench[3] - bench[2];
    cout << "\nFunctions performance:\n"
         << "Add object to tree: " << bAdd.count() << " milliseconds\n"
         << "Traverse with default type of search: " << bTraverse.count() << " milliseconds\n"
         << "Sub object from tree: " << bSub.count() << " milliseconds\n";
    cout << "\n\nCalling destructors and free allocataded memory.\n\n";
    return 0;
}
