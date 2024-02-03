#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//  Бинарное дерево поиска с динамической памятью, потоки дополнительно, компиляция GCC, MSVS, 32bits.
//  Все ограничения по памяти и индексам 15 бит и/или 32кб - 1, по объектам - 8 бит или 255 байт максимум.
//  Неопределенные данные сравниваются по-байтно, а символы слова по таблице ASCII аналогично. Число с плавающей точкой
// сравнивается с учетом окрестности точки "эпсилон" задано статично, а текст по аналогии по символам и по всей длине.
//  Добавление элемента с нулевой длинной и не сущуествующего объекта невозможно. Тип объекта и его размер в байтах
// задается для всего дерева сразу. Дерево без элементов, создать невозможно.

//  Максимальный размер памяти и индексов, т.к. 16-ый бит используется для обработки ошибок и как флаг переполнения.
#define MEM_MAX 0x8000
#define IDX_MAX 0x7FFF
#define OBJ_MAX 0xFF

// Встроенные типы объектов для удобного вывода и тестирования. Неопределенные данные по-умолчанию.
enum obj_type { obj_data = 0, obj_text = 1, obj_word = 2, obj_float = 3, obj_not = 4 };
// Тип обхода узлов при поиске элемента для различных обходах дерева.
enum search_type { sr_node_left_right = 0, sr_left_node_right = 1, sr_left_right_node = 2, sr_not = 3 };
// Код возвращаемой ошибки или результат функции.
enum err_type { err_ok = 0, err_incorrect = 1, err_memory = 2, err_already = 3, err_not = 4 };

struct binary_tree {                                            // Главная структура дерева.
    unsigned short data_size;                                   // Количество элементов.
    unsigned short memory_size;                                 // Вспомогательный параметр для отображения.
    unsigned char node_type;                                    // Тип данных.
    unsigned char object_size;                                  // Размер в байтах объекта(данных) или текста.
    struct node {                                               // Вложенная структура также глобально.
        void* object;                                           // Адрес объекта.
        struct node* previous, *left, *right;                   // Предыдущий, слева и справа узлы.
    } *root;                                                    // Корневой объект также является динамическим.
};

// Статичные константы для всей программмы,

// Размеры поддерживаемых типов данных, 1 - означает что размер не определен и высчитывается побайтно.
static const unsigned char obj_type_size[] = { sizeof(unsigned char), sizeof(char), sizeof(short), sizeof(float), 0x00 };
// Имена поддерживаемых типов данных и обходов дерева.
static const char* obj_type_name[] = { "data", "text", "word", "float", "not an object" };

static const char* errors[] = { "No error.", "Incorrect parameters.", "Not enough memory.", "Node already in tree." };
static const float float_eps = 0.01;                            // Задання точность для чисел с плавающей точкой.
static const char hex_tab[] = "0123456789ABCDEF";               // Таблица для вывода данных как есть.
static const unsigned char print_width = 0x80;                  // Ширина вывода в консоль.
static const char print_default_char = '.';                     // Символ по умолчанию при выводе дерева.
static const short rnd_word_max = 10;                           // Максимальное количество случайных чисел для слова.
static const short rnd_char_max = 'z' - 'a';                    // Диапазон случайных букв для символа и текста.
static const char* search_name[] = { "node-left-right or 'pre-order'",
                                     "left-node-right or 'in-order'",
                                     "left-right-node or 'post-order'",
                                     "not a search" };

// Глобальные данные, для всей программы.

static unsigned short memory_used = 0x0000;                     // Используемая память на все объекты.
static unsigned short memory_free = MEM_MAX;                    // Свободная память в байтах.
static enum search_type default_search = sr_node_left_right;    // Тип обхода по умолчанию, если не задано.
static struct node* tree_nodes[MEM_MAX];                        // Элементы дерева после обхода.
static short tree_nodes_size = 0x0000;                          // Количество элементов после обхода или 0, если пусто.
static char txt[OBJ_MAX];                                       // Для текстового преобразования или все локально.

short is_node_correct(struct node* n)
{   // Дополнительная проверка узла на корректность. Связность не учитывается.
    return !(n == NULL || n->object == NULL);
}

short node_to_text(struct binary_tree* tree, struct node* leaf, char* text, short is_clear)
{   // Дополнительная функция преобразования узла в текст, флаг очистки строки, если потребуется наложение текста.
    if (tree == NULL || text == NULL || !is_node_correct(leaf)) {
        printf("Error node to text, tree (%p), text (%p) are null, empty (%hu) or node is incorrect.\n",
               tree, text, tree->data_size);
        return err_incorrect;                                   // Проверка на корректность.
    }
    if (is_clear)                                               // Очистка строки если флаг установлен.
        for (unsigned char idx = 0; idx < OBJ_MAX; ++idx)
            text[idx] = 0;
    unsigned char high_nib_mask = 0xF0, low_nib_mask = 0x0F, nib_size = CHAR_BIT >> 0x01, len;
    switch (tree->node_type) {                                  // Битовые маски или можно арифметикой.
    case obj_data:
        for (unsigned char idx = 0; idx < tree->object_size; ++idx) {
            text[idx << 0x01] = hex_tab[(((unsigned char*)leaf->object)[idx] & high_nib_mask) >> nib_size];
            text[idx << 0x01 | 0x01] = hex_tab[((unsigned char*)leaf->object)[idx] & low_nib_mask];
        }                                                       // Данные как есть в 16-ичной системе.
        break;
    case obj_text:
        for (unsigned char idx = 0; idx < tree->object_size; ++idx)
            text[idx] = ((char*)leaf->object)[idx];             // Текст по умолчанию.
        break;
    case obj_word:
        len = sprintf_s(text, OBJ_MAX, "%hd", *((short*)leaf->object));
        if (!is_clear)                                          // Или можно использовать другую функцию.
            text[len] = print_default_char;
        break;
    case obj_float:
        len = sprintf_s(text, OBJ_MAX, "%.2f", *((float*)leaf->object));
        if (!is_clear)                                          // Преобразование в формате %.2f.
            text[len] = print_default_char;
        break;
    default:
        printf("Warning node to text, node type '%s' in tree is undefined.\n", obj_type_name[tree->node_type]);
        return err_incorrect;                                   // Некорректный(неподдерживаемый) тип данных.
    }
    return err_ok;
}

short create_node(struct node** dst, void* data, unsigned char size)
{   // Создание узла с выделением динмаической памяти, код ошибки означает условное исключение.
    if (dst == NULL || data == NULL || *dst != NULL || size == 0) {
        printf("Error create node, addresses destination (%p), node (%p), data (%p) or object not empty (%p).\n",
               dst, (*dst), data, (*dst)->object);
        return err_incorrect;                                   // Проверка на корректность.
    }
    if ((short)(memory_used + size) < 0) {                      // Создание только если есть свободная память.
        printf("Not enough free memory %hu for object size %hhu.\n", memory_free, size);
        return err_memory;
    }
    (*dst) = calloc(1, sizeof(struct node));                    // Обычная динамическая память.
    void* new_data = calloc(1, size);
    if (*dst == NULL || new_data == NULL) {                     // Системный выход в случае отказа динамической памяти.
        printf("Can't allocate memory for node or new object data, exit (-1).\n");
        exit(-1);
    }
    (*dst)->object = new_data;
    (*dst)->previous = (*dst)->left = (*dst)->right = NULL;
    for (short mem_idx = 0; mem_idx < size; ++mem_idx)          // Копирование данных как есть.
        ((char*)(*dst)->object)[mem_idx] = ((char*)data)[mem_idx];
    printf("Create node (%p) from data (%p) to object (%p) and size %hhu bytes.\n",
           (*dst), data, (*dst)->object, size);
    memory_used += size; memory_free -= size;
    return err_ok;
}

short copy_node(struct node** dst, struct node* src, unsigned char size)
{   // Копирование узлов дерева из источнка в приёмник, назначение должно быть пустым и достаточно памяти.
    if (!is_node_correct(src) || dst == NULL || *dst != NULL || size == 0) {
        printf("Error copy nodes, destination (%p) or source (%p) are null or destination exist.\n", dst, src);
        return err_incorrect;                                   // Проверка на корректность.
    }
    short r = create_node(dst, src->object, size);
    if (r)                                                      // Если ошибка создания копии.
        return r;
    printf("Copy data node from (%p) to node (%p), data (%p) and size %hhu.\n",
           src->object, *dst, (*dst)->object, size);
    return err_ok;
}

short move_node(struct node** dst, struct node** src)
{   // Перемещение объекта, без дополнительных функций работы с динамической памятью и очисткой источника.
    if (dst == NULL || *dst != NULL || !is_node_correct(*src)) {
        printf("Error moving nodes, destination (%p) is not correct or exist. "
               "Or source (%p) is incorrect.\n", dst, src);
        return err_incorrect;                                   // Проверка на корректность.
    }
    (*dst) = (*src);
    printf("Moving node from (%p) to (%p) object (%p), reset source.\n", *src, *dst, (*dst)->object);
    (*src) = NULL;
    return err_ok;
}

short destroy_node(struct node** dst, unsigned char size)
{   // Удаление объекта узла и установка параметров по умолчанию.
    if (dst == NULL || !is_node_correct(*dst)) {
        printf("Error destroy node, destination (%p) or node (%p) incorrect.\n", dst, (*dst));
        return err_incorrect;                                   // Проверка на корректность.
    }
    printf("Destroy node (%p) with object (%p), size %hhu bytes.\n", *dst, (*dst)->object, size);
    free((*dst)->object);                                       // Освобождение памяти.
    free(*dst);
    *dst = NULL;                                                // Зануляем адрес, для улучшения.
    memory_used -= size; memory_free += size;
    return err_ok;
}

short compare_nodes(struct binary_tree* tree, struct node* left, struct node* right)
{   // Сравнение двух узлов дерева, возвращает -1 если операнд слева меньше чем справа, 0 - если равен и +1 если больше.
    if (!(is_node_correct(left) && is_node_correct(right)) || tree->node_type >= obj_not) {
        printf("Compare error, left or right node is incorrect, check addresses, sizes, or types left-right.\n");
        return err_not;                                         // Проверка на корректность.
    }
    switch (tree->node_type) {
    case obj_data:
    case obj_text:                                              // Данные или текстовая строка.
        for (unsigned short i = 0; i < tree->object_size; ++i)  // Или использовать прямое сравнение по памяти.
            if (((char*)left->object)[i] > ((char*)right->object)[i])
                return 1;
            else if (((char*)left->object)[i] < ((char*)right->object)[i]) {
                // printf("%c-%c\n", ((char*)left->object)[i], ((char*)right->object)[i]);
                return -1;
            }
        break;
    case obj_word:                                              // Сравнение по словам 16-ть бит.
        if (*((short*)left->object) > *((short*)right->object))
            return 1;
        if (*((short*)left->object) < *((short*)right->object))
            return -1;
        break;
    case obj_float:                                             // При сравнении с плавающей точкой в окрестности.
        if (fabsf(*((float*)left->object) - *((float*)right->object)) < float_eps)
            return 0;
        if ((float*)left->object > (float*)right->object)
            return 1;
        if ((float*)left->object < (float*)right->object)
            return -1;
        break;
    default:
        printf("Error compare, object type in both nodes are incorrect.\n");
        return err_not;                                         // Неподдерживаемый тип.
    }
    return err_ok;
}

struct node* search_node(struct binary_tree* tree, struct node* obj)
{   // Поиск узла равного заданному, используя стандартный прямой тип поиска.
    // Если узел не найден, то возвращается ближайший узел по значению.
    if (tree == NULL || tree->data_size == 0 || !is_node_correct(obj)) {
        printf("Error search node, addresses tree (%p), tree is empty or object incorrect.\n", tree);
        return NULL;                                            // Только по адресу.
    }
    struct node* leaf = tree->root;
    short cmp, is_leaf_exist = 1;                               // Результат сравнения и флаг пути или усложнить условие.
    while ((cmp = compare_nodes(tree, leaf, obj)) != 0 && is_leaf_exist) {
        // node_to_text(tree, leaf, txt);
        // printf("\n%hd:(%p):'%s'\n", cmp, leaf, txt);
        if (cmp > 0) {                                          // Если узел больше, то смещаемся влево.
            if (leaf->left != NULL)
                leaf = leaf->left;
            else
                is_leaf_exist = 0;
        }
        if (cmp < 0) {                                          // Если узел больше, то смещаемся вправо.
            if (leaf->right != NULL)
                leaf = leaf->right;
            else
                is_leaf_exist = 0;
        }
    }
    return leaf;                                                // Возвращаем удрес узла, ближайщий или точно найденный.
}

short print(struct binary_tree* tree, unsigned char endl)
{   // Вывод дерева, по центру в позицию по глобальной настройке. Вывод всех поддерживаемых типов данных.
    // Используется стандартный метод обхода в ширину и уровневого стека. Дополнительно колиечество строк после.
    // Еще дополнительно, можно будет добавить проверку на целостность дерева.
    if (tree == NULL) {
        printf("Error print tree, addresses is null.\n");
        return err_incorrect;                                   // Проверка на корректность.
    }
    printf("Print tree at (%p), size %hu, memory %hu bytes. Type '%s' size %hu bytes, %u console width.\n",
           tree, tree->data_size, tree->memory_size, obj_type_name[tree->node_type], tree->object_size, print_width);
    struct node* line[MEM_MAX] = { tree->root }, *next_line[MEM_MAX];
    short line_size = 1, next_line_size = 0, idx, is_empty = 1; // Обход слева на справо, по уровням.
    unsigned char pos = print_width >> 0x01, lev = 1, tab = print_width;
    while (is_empty == 1 && line_size > 0) {
        for (idx = 0; idx < print_width; ++idx)
            txt[idx] = print_default_char;
        txt[print_width] = '\0';
        pos = print_width >> lev;
        for (idx = 0, next_line_size = 0; idx < line_size; ++idx) {
            if (line[idx] != NULL) {                            // Высокий расход памяти, можно подумать еще.
                next_line[next_line_size++] = line[idx]->left;
                next_line[next_line_size++] = line[idx]->right;
            } else {
                next_line[next_line_size++] = NULL;
                next_line[next_line_size++] = NULL;
            }
            if (line[idx] != NULL)
                node_to_text(tree, line[idx], &txt[pos], 0);
            pos += tab;
        }
        printf("%s\n", txt);
        for (idx = 0, line_size = 0, is_empty = 0; idx < next_line_size; ++idx, ++line_size) {
            if (next_line[idx] != NULL)
                is_empty = 1;
            line[line_size] = next_line[idx];
        }
        tab >>= 0x01;
        lev++;
    }
    while (endl--)                                              // Переход на следующие строки.
        printf("\n");
    return err_ok;
}

short add_node(struct binary_tree* tree, void* data)
{   // Добавление узла в дерево и выделение для него памяти, пустой объект добавить невозможно.
    // Исходный объект по адресу должен существовать. Правила сравнения определены выше в функции.
    if (tree == NULL || data == NULL) {
        printf("\nError add node, adresses tree (%p) or data (%p) are null. Or not enough free memory %hu.\n",
               tree, data, memory_free);
        return err_incorrect;                                   // Проверка на корректность.
    }
    struct node* new_leaf = NULL, *near_leaf = NULL;
    short cmp, r;
    r = create_node(&new_leaf, data, tree->object_size);
    if (r) {
        printf("Error add node: '%s'.\n", errors[r]);
        return r;
    }
    node_to_text(tree, new_leaf, txt, 1);
    printf("Add object of type '%s', size %hu to tree and data '%s' at (%p).\n",
           obj_type_name[tree->node_type], tree->object_size, txt, new_leaf);
    if (tree->data_size > 0) {
        near_leaf = search_node(tree, new_leaf);
        if ((cmp = compare_nodes(tree, new_leaf, near_leaf)) != 0) {
            node_to_text(tree, near_leaf, txt, 1);
            if (cmp == +1) {                                    // Если добавляем вправо.
                near_leaf->right = new_leaf;
                printf("Nearest node at (%p), object data '%s', compare flag %hd, add to right.\n",
                       near_leaf, txt, cmp);
            } else if (cmp == -1) {                             // Если добавляем влево.
                near_leaf->left = new_leaf;
                printf("Nearest node at (%p), object data '%s', compare flag %hd, add to left.\n",
                       near_leaf, txt, cmp);
            }
            new_leaf->previous = near_leaf;
        } else {
            printf("Node at (%p), object data '%s' is already in tree, destroy new leaf.\n", near_leaf, txt);
            destroy_node(&new_leaf, tree->object_size);
            return err_already;                                 // Если узел уже находится в дереве.
        }
    } else {
        printf("Tree is empty, nearest node is root, moving new leaf to root.\n");
        r = move_node(&tree->root, &new_leaf);                  // Если дерево пустое, то устанавливаем в корень.
    }
    tree->data_size++; tree->memory_size += tree->object_size;
    return r;
}

void replace_node(struct binary_tree* tree, struct node* dst, struct node* src)
{   // Замена одного узла в дереве на источник с обновлением и сохранением порядка адресов элементов.
    if (tree == NULL || !is_node_correct(dst)) {
        printf("Error node replace, tree or destination node are null or incorrect.\n");
        return;                                                 // Проверка на корректность.
    }
    struct node* prev_dst = dst->previous;
    if (prev_dst != NULL) {                                     // Предыдущий элемент, если не корневой.
        // printf("Update!.\n");
        if (prev_dst->left == dst) {
            prev_dst->left = src;
            // printf("L!:%p.\n", src);
        }
        if (prev_dst->right == dst) {
            prev_dst->right = src;
            // printf("R:%p.\n", src);
        }
    } else {                                                    // Если предыдущий элемент был корневой.
        tree->root = src;
        printf("Destination is root, new object (%p) set as root.\n", tree->root);
    }
    if (dst->left != NULL)                                      // Сохраняем связность обратного направления.
        dst->left->previous = src;
    if (dst->right != NULL)
        dst->right->previous = src;
    if (src != NULL)
        src->previous = prev_dst;                               // Новый предыдущий элемент или корень.
    destroy_node(&dst, tree->object_size);
}

short sub_node(struct binary_tree* tree, void* data)
{   // Удаление узла из дерева, со смещением остальных узлов и освобождением памяти узла.
    // Функция до конца не оттестирована, возможны ошибки. Возможно еще сократить.
    if (tree == NULL || data == NULL || tree->data_size == 0) {
        printf("Error sub node, tree (%p) or data (%p) are null or tree is empty.\n", tree, data);
        return err_incorrect;                                   // Проверка на корректность.
    }
    struct node object = { .object = data, .previous = NULL, .left = NULL, .right = NULL };
    node_to_text(tree, &object, txt, 1);
    printf("Sub node [%s] from tree size %hu.\n", txt, tree->data_size);
    struct node* leaf = search_node(tree, &object);
    if (compare_nodes(tree, leaf, &object) != 0) {              // Если узел не найден в дереве.
        printf("Node to sub is not founded in tree, nothing to delete.\n");
        return err_already;
    }
    // Обрабатываем все возможные случаи удаления и сохраняем порядок, схема по Вики.
    printf("Node with object founded in tree, define case of tree subtraction.\n");
    if (leaf->left == NULL && leaf->right == NULL) {
        printf("Both derived nodes are null, so just delete node and free memory.\n");
        replace_node(tree, leaf, NULL);                         // Оба производных узла не существуют.
    } else if (leaf->left == NULL && leaf->right != NULL) {
        printf("Only right derived node is exist, moving it upper to deleted node.\n");
        replace_node(tree, leaf, leaf->right);                  // Только правый производный узел существует.
    } else if (leaf->left != NULL && leaf->right == NULL) {
        printf("Only left derived node is exist, moving it upper to deleted node.\n");
        replace_node(tree, leaf, leaf->left);                   // Только левый производный узел существует.
    } else if (leaf->left != NULL && leaf->right != NULL) {
        printf("Both derived nodes are exists, ");              // Оба производных узла существуют.
        if (leaf->right->left == NULL)  {
            printf("from right derived -> left-derived not exist, just replace deleted node by right.\n");
            struct node *prev_r = leaf->right, *prev_l = leaf->left;
            replace_node(tree, leaf, prev_r);
            prev_r->left = prev_l;                              // Замена правого пустого на предыдущий слева.

        } else if (leaf->right->left != NULL) {
            printf("from right derived -> left-derived is exist, replace deleted by this node.\n");
            struct node *prev_r = leaf->right, *prev_rl = leaf->right->left, *prev_l = leaf->left;
            struct node *prev_rlr = leaf->right->left->right;
            replace_node(tree, leaf, leaf->right->left);
            prev_rl->left = prev_l;                             // Замена на предыдущий слева.
            prev_rl->right = prev_r;                            // Замена на предыдущий справа.
            prev_r->left = prev_rlr;                            // Замена справа от источника(может нуль) на уровень ниже.
            prev_rlr->previous = prev_r;                        // Возможно лишнее.
        }
    }
    tree->data_size--;                                          // Только параметры памяти дерева и количество.
    tree->memory_size -= tree->object_size;
    return err_ok;
}

struct node* traverse_node(struct binary_tree* tree, struct node* stack[], short* sp,
                           struct node* left, struct node* right)
{   // Вспомогательная функция для обхода со стеком, для компактности кода и вывода.
    if (left != NULL) {                                         // Добавляем и выводим левый элемент.
        stack[(*sp)++] = left;
        node_to_text(tree, left, txt, 1);
        printf("Push left leaf at (%p), object [%s], stack size %hd.\n", left, txt, *sp);
        return left;                                            // Возвращаем левосторонний.
    }
    if (right != NULL) {                                        // Добавляем и выводим правый элемент.
        stack[(*sp)++] = right;
        node_to_text(tree, right, txt, 1);
        printf("Push right leaf at (%p), object [%s], stack size %hd.\n", right, txt, *sp);
        return right;                                           // Возвращаем правосторонний.
    }
    return NULL;
}

struct node* traverse_pop(struct binary_tree* tree, struct node* stack[], short* sp)
{   // Вспомогательная функция для обхода, извлечение элемента из стека и возврат узла.
    struct node* leaf;
    if ((*sp) > 0) {
        leaf = stack[--(*sp)];                                  // Извлекаем из стека или в несколько команд.
        node_to_text(tree, leaf, txt, 1);
        printf("Pop leaf at (%p), object [%s].\n", leaf, txt);
    } else {
        printf("Error traverse tree, stack %hd incorrect.\n", (*sp));
        return NULL;
    }
    return leaf;
}

short traverse(struct binary_tree* tree, enum search_type type)
{   // Полный обход дерева заданным методом и сохранением в статичный массив всех адресов и их количества.
    if (tree == NULL || tree->data_size == 0 || type >= sr_not) {
        printf("Error traverse tree at (%p), tree is empty or search type '%s' incorrect.\n", tree, search_name[type]);
        return err_incorrect;                                   // Проверка на корректность.
    }
    struct node* stack[MEM_MAX], *leaf = tree->root;
    short sp;                                                   // Указатель стека.
    printf("Traverse tree at (%p), type '%s', size %hu and type '%s'.\n",
           tree, obj_type_name[type], tree->data_size, search_name[type]);
    tree_nodes_size = 0; stack[0] = leaf, sp = 1;               // Глобальный список очищается.
    while (sp > 0) {
        switch (type) {
        case sr_node_left_right:                                // Прямой обход или "pre-order".
            leaf = traverse_pop(tree, stack, &sp);
            tree_nodes[tree_nodes_size++] = leaf;
            traverse_node(tree, stack, &sp, NULL, leaf->right);
            traverse_node(tree, stack, &sp, leaf->left, NULL);
            break;
        case sr_left_node_right:                                // Центрированный обход "in order".
            while (leaf->left != NULL)
                leaf = traverse_node(tree, stack, &sp, leaf->left, NULL);
            leaf = traverse_pop(tree, stack, &sp);
            tree_nodes[tree_nodes_size++] = leaf;
            if (leaf->right != NULL)
                leaf = traverse_node(tree, stack, &sp, NULL, leaf->right);
            break;
        case sr_left_right_node:                                // Обратный обход "post order".
            while (leaf->left != NULL || leaf->right != NULL) {
                if (leaf->left != NULL)
                    leaf = traverse_node(tree, stack, &sp, leaf->left, NULL);
                if (leaf->right != NULL)
                    leaf = traverse_node(tree, stack, &sp, leaf->right, NULL);
            }
            leaf = traverse_pop(tree, stack, &sp);
            tree_nodes[tree_nodes_size++] = leaf;               // Заполняем статичный массив.
            break;
        default:
            printf("Type of search incorrect in traverse.\n");
            return err_incorrect;                               // Можно дополнить другими типами обходов.
        }
    }
    return err_ok;
}

short create(struct binary_tree* tree, void* data, short objects, unsigned char obj_size, enum obj_type type, short is_random)
{   // Конструктор, на вход: данные для инициализации в виде массива, или NULL, если просто создать.
    // Флаг случайной генерации данных узлов с учетом глобальных параметров ограничения.
    if (tree == NULL || tree->data_size > 0 || type >= obj_not || (!is_random && data == NULL)) {
        printf("Create tree, tree or data(without random) addresses are null. "
               "Tree is not epmty or object type incorrect.\n\n");
        return err_incorrect;                                   // Проверка на корректность.
    }
    tree->node_type = type; tree->object_size = obj_size; tree->root = NULL;
    if (is_random)                                              // Флаг случайной генерации, пределы статичные параметры.
        printf("Create empty tree and add %hd random objects of '%s'.\n\n", objects, obj_type_name[type]);
    else
        printf("Create empty tree and add %hd source objects of '%s'.\n\n", objects, obj_type_name[type]);
    unsigned char rnd_data_text[OBJ_MAX];
    short rnd_word, rnd_sign;
    float rnd_float;
    for (short idx = 0; idx < objects; ++idx) {
        if (is_random) {
            switch (type) {
            case obj_data:
                for (unsigned char cl = 0; cl < obj_size; ++cl)
                    rnd_data_text[cl] = rand() % UCHAR_MAX;
                data = rnd_data_text;
                break;
            case obj_text:
                for (unsigned char cl = 0; cl < obj_size; ++cl)
                    rnd_data_text[cl] = 'A' + (rand() % rnd_char_max);
                data = rnd_data_text;
                break;
            case obj_word:
                rnd_word = (rand() % USHRT_MAX) % rnd_word_max;
                data = &rnd_word;
                break;
            case obj_float:
                rnd_sign = (rand() % 2) ? +1 : -1;              // Знак генерируем отдельно.
                rnd_float = rnd_sign * ((rand() % rnd_word_max) / (rand() % rnd_word_max + 1));
                data = &rnd_float;
                break;
            default:
                printf("Error create random object, type unsupported.\n");
                return err_incorrect;                           // Можно дополнить еще типами данных.
            }
            add_node(tree, data);
        } else
            add_node(tree, (void*)((unsigned char*)data + (idx * obj_size)));
        printf("\n");
    }
    return err_ok;
}

short copy(struct binary_tree* dst, struct binary_tree* src)
{   // Копирования дерева полностью со всеми элементами, выделяется новая память и
    // параметры назначения устанавливаются как в исходном дереве.
    if (dst == NULL || src == NULL || src->data_size == 0 || dst->data_size > 0) {
        printf("Error copy tree from (%p) to (%p), nothing to copy or destination not empty.\n", src, dst);
        return err_incorrect;                                   // Проверка на корректность.
    }
    if (memory_free < src->memory_size) {
        printf("Not enough memory %hu to create new tree size %hu.\n", memory_free, src->memory_size);
        return err_memory;                                      // Если не хватает памяти на новый узел.
    }
    printf("Copy tree from (%p) to (%p), size %hu and allocate %hu bytes new memory from free %hu bytes.\n\n",
           src, dst, src->data_size, src->memory_size, memory_free);
    dst->data_size = dst->memory_size = 0;
    dst->node_type = src->node_type;
    dst->object_size = src->object_size;
    short r = traverse(src, default_search);                    // Код ошибки должен быть ок.
    printf("\nAdd all nodes as is to new tree, check size %hu.\n\n", tree_nodes_size);
    for (short idx = 0; idx < tree_nodes_size && !r; ++idx)
        r = add_node(dst, tree_nodes[idx]->object);
    printf("\nMemory check after copy, memory used %hu and free %hu bytes.\n\n", memory_used, memory_free);
    return r;
}

short move(struct binary_tree** dst, struct binary_tree** src)
{   // Перемещение дерева по адресам, копирования узлов не происходит и в источнике обновляются параметры.
    if (src == NULL || *src == NULL || dst == NULL || *dst == NULL || (*dst)->data_size > 0) {
        printf("Error moving tree, source addresses (%p, %p) or destination (%p, %p) incorrect, or "
               "destination is not empty, possible memory leak.\n", src, *src, dst, *dst);
        return err_incorrect;
    }
    *dst = *src;                                                // Или копировать по элементам структуры.
    *src = NULL;
    printf("\nMemory check after move, memory used %hu and free %hu bytes.\n", memory_used, memory_free);
    return err_ok;
}

short destroy(struct binary_tree* tree)
{   // Освобождение памяти занимаемой объектами и зануление параметров структуры дерева.
    if (tree == NULL) {
        printf("Error destroy, address of tree (%p) is null.\n", tree);
        return err_incorrect;                                   // Проверка на корректность.
    }
    if (tree->data_size > 0) {                                  // Если дерево не пустое, то удаляем все элементы.
        printf("Tree has %hu objects as nodes, free memory %hu for all nodes and set parameters to 0.\n",
               tree->data_size, tree->memory_size);
        short r = traverse(tree, default_search);
        for (short i = 0; i < tree->data_size && !r; ++i)
            destroy_node(&tree_nodes[i], tree->object_size);
    } else
        printf("Tree has no nodes, nothing to free, just set all parameters to 0 or NULL.\n");
    tree->data_size = tree->memory_size = tree->object_size = 0;
    tree->node_type = obj_not;                                  // Сбрасываем все параметры, чтобы всё чисто.
    tree->root = NULL;
    printf("\nMemory check after destroy, memory used %hu and free %hu bytes.\n\n", memory_used, memory_free);
    return err_ok;
}

short compare(struct binary_tree* left, struct binary_tree* right, short is_order)
{   // Сравнение деревьев поэлементно, деревья считаются равными, если они одного размера и элементы равны, порядок по флагу.
    if (left == NULL || right == NULL || left->data_size != right->data_size ||
            left->node_type != right->node_type || left->object_size != right->object_size) {
        printf("Error compare, left (%p) or right (%p) tree addresses is null. ", left, right);
        if (left)                                               // По отдельности, чтобы не было чтения по нуль адресам.
            printf("Left size %hu, type '%s', object size %hu. ",
                   left->data_size, obj_type_name[left->node_type], left->object_size);
        if (right)
            printf("Right size %hu, type '%s', object size %hu. ",
                   right->data_size, obj_type_name[right->node_type], right->object_size);
        printf("\n");
        return err_incorrect;
    }
    printf("Compare trees (%p) and (%p), sizes %hu, node type '%s' and size %hu bytes, is order %hd.\n\n",
           left, right, left->data_size, obj_type_name[left->node_type], left->object_size, is_order);
    short r_left = traverse(left, default_search);
    struct node* tree_nodes_alt[MEM_MAX];                       // Вспомогательный массив адресов и размера,
    short tree_alt_size = tree_nodes_size;                      // оставить здесь или вынести в статику.
    for (short i = 0; i < tree_nodes_size; ++i)
        tree_nodes_alt[i] = tree_nodes[i];                      // Или можно скопировать участок памяти.
    short r_right = traverse(right, default_search);            // Обновляем список узлов, по обходу.
    if (r_left || r_right || tree_nodes_size != left->data_size) {
        printf("Error in tree traverse, left %hd and right %hd codes or sizes.\n", r_left, r_right);
        return err_incorrect;
    }
    printf("\nPair of nodes: ");
    if (is_order) {                                             // Порядок должен быть одинаков.
        for (short i = 0; i < tree_alt_size; ++i) {
            node_to_text(left, tree_nodes_alt[i], txt, 1);
            printf("'%s':", txt);
            node_to_text(right, tree_nodes[i], txt, 1);
            printf("'%s' ", txt);
            if (compare_nodes(left, tree_nodes[i], tree_nodes_alt[i])) {
                printf("\n\n");
                return err_not;
            }
        }
    } else {                                                    // Порядок не имеет значения.
        for (unsigned short i = 0, j, is_found; i < tree_alt_size; ++i) {
            for (j = 0, is_found = 0; j < tree_alt_size && !is_found; ++j)
                if (i != j && compare_nodes(left, tree_nodes_alt[i], tree_nodes[j]) == 0)
                    is_found = 1;
            if (!is_found) {                                    // Не найдено на любой позиции.
                printf("\n");
                return err_not;
            } else {
                node_to_text(left, tree_nodes[i], txt, 1);
                printf("'%s':'%s' ", txt, txt);
            }
        }
    }
    printf("\n\n");
    return err_ok;
}

short balance(struct binary_tree* dst, struct binary_tree* src)
{   // Функция простой балансировки дерева поиска, быстрые методы оставить на десерт.
    if (src == NULL || dst == NULL || src->data_size == 0 || dst->data_size > 0) {
        printf("Error balance tree, source or destination are null or nothing to balance. "
               "Destination tree must be empty.\n");
        return err_incorrect;
    }
    printf("\nBalance tree using simple traverse and linear search elements.\n");
    traverse(src, sr_node_left_right);
    dst->node_type = src->node_type; dst->object_size = src->object_size;
    short i, j, k, more, less, medium, diff;                    // Ищем среднее и раскидываем по направлениям.
    for (k = 0; k < src->data_size; ++k, tree_nodes_size--) {
        medium = 0; diff = src->data_size;
        for (i = 0; i < tree_nodes_size; ++i) {
            more = less = 0;
            for (j = 0; j < tree_nodes_size; ++j) {
                if (i != j) {
                    if (compare_nodes(src, tree_nodes[i], tree_nodes[j]) == +1)
                        more++;
                    else
                        less++;
                }
            }
            if (diff > abs(less - more)) {
                medium = i;
                diff = abs(less - more);
            }
        }
        node_to_text(src, tree_nodes[medium], txt, 1);
        printf("Medium node in tree '%s', index %hd.\n", txt, medium);
        add_node(dst, tree_nodes[medium]->object);
        for (j = medium; j < tree_nodes_size - 1; ++j)
            tree_nodes[j] = tree_nodes[j + 1];
    }
    return err_ok;
}

int main()
{   // Основная программ, общая информация и тестирование всех функций.
    printf("16-bits Binary Search Tree and various objects, using dynamic memory.\n");
    printf("Size of char %u, short %u, int %u and double %u bytes, address widh %u bits.\n"
           "Memory limit %u bytes and %d maximum indexes for all nodes and data.\n\n",
           sizeof(char), sizeof(short), sizeof(int), sizeof(double), sizeof(char*) * CHAR_BIT, MEM_MAX, SHRT_MAX);
    // Общие переменные для всех сценариев тестирования.
    const unsigned short data_max = 12;
    char* text_data = { "Binary Tree" };
    unsigned short i, j;
    short r, val_a;
    float val_f;
    unsigned char byte_values[3] = { 0x00, 0x1E, 0xFF };
    struct binary_tree tree_a = { .data_size = 0, .memory_size = 0, .node_type = obj_not, .object_size = 0, .root = NULL };
    struct binary_tree tree_b = { .data_size = 0, .memory_size = 0, .node_type = obj_not, .object_size = 0, .root = NULL };
    struct binary_tree *ptr_tree_a = &tree_a, *ptr_tree_b = &tree_b;
    struct node* leaf_a = NULL, *leaf_b = NULL, *leaf_c = NULL, *leaf_d = NULL, *leaf_e = NULL;
    struct node leaf = { .object = NULL, .previous = NULL, .left = NULL, .right = NULL };
    // Данные структуры дерева и его полей.
    printf("Structure 'Binary Trree' size %u bytes and data:\n"
           "Offset:\tSize:\tMin:\tMax:\t\tComment:\n", sizeof(struct binary_tree));
    printf("%u\t%u\t%u\t%u\t\tSize of tree in nodes(leafs);\n", (char*)&tree_a.data_size - (char*)&tree_a,
           sizeof(tree_a.data_size), 0, MEM_MAX);
    printf("%u\t%u\t%u\t%u\t\tSize of tree in bytes, only data counts;\n", (char*)&tree_a.memory_size - (char*)&tree_a,
           sizeof(tree_a.memory_size), 0, MEM_MAX);
    printf("%u\t%u\t'%s'\t'%s'\t\tSupported type nodes;\n", (char*)&tree_a.node_type - (char*)&tree_a,
           sizeof(tree_a.node_type), obj_type_name[obj_data], obj_type_name[obj_float]);
    printf("%u\t%u\t%u\t%u\t\tSize of every object in tree in bytes;\n", (char*)&tree_a.object_size - (char*)&tree_a,
           sizeof(tree_a.object_size), 0, UCHAR_MAX);
    printf("%u\t%u\t%u\t%x\tAddress of 'Node' structure as root of tree.\n", (char*)&tree_a.root - (char*)&tree_a,
           sizeof(tree_a.root), 0, UINT_MAX);
    // Данные структуры узла или листа.
    printf("\nStructure 'Node' size %u bytes and data:\nOffset:\tSize:\tComment:\n", sizeof(struct node));
    printf("%u\t%u\taddress of object, null if not exist;\n", (char*)&leaf.object - (char*)&leaf, sizeof(leaf.object));
    printf("%u\t%u\taddress of previous node, null if not exist;\n", (char*)&leaf.previous - (char*)&leaf, sizeof(leaf.previous));
    printf("%u\t%u\taddress of left node, null if not exist;\n", (char*)&leaf.left - (char*)&leaf, sizeof(leaf.left));
    printf("%u\t%u\taddress of right node, null if not exist.\n", (char*)&leaf.right - (char*)&leaf, sizeof(leaf.right));
    // struct binary_tree *tree_ptr_src = &tree, *tree_ptr_dst = &tree_copy;
    // Тестирование отдельно вспомогательных функция для узлов или листьев.
    printf("\n\nTesting functions for 'Node' structure or nodes(leafs) in tree.\n\n\n");
    printf("Conversion from structure 'Node' to string all object types and node correctness.\n\n");
    tree_a.data_size = 1;
    byte_values[0] = 0x00; byte_values[1] = 0x1E; byte_values[2] = 0xFF;
    create_node(&leaf_a, byte_values, sizeof(byte_values));
    tree_a.node_type = obj_data; tree_a.object_size = sizeof(byte_values);
    node_to_text(&tree_a, leaf_a, txt, 1);
    printf("Source node type '%s' size %u bytes and value in hex %s.\n",
           obj_type_name[obj_data], tree_a.object_size, txt);
    create_node(&leaf_b, text_data, strlen(text_data));
    tree_a.node_type = obj_text; tree_a.object_size = strlen(text_data);
    node_to_text(&tree_a, leaf_b, txt, 1);
    printf("Source node type '%s' size %u bytes and value in text '%s'.\n",
           obj_type_name[obj_text], tree_a.object_size, txt);
    val_a = 5;
    create_node(&leaf_c, &val_a, obj_type_size[obj_word]);
    tree_a.node_type = obj_word; tree_a.object_size = obj_type_size[obj_word];
    node_to_text(&tree_a, leaf_c, txt, 1);
    printf("Source node type '%s' size %u bytes and value in word %s.\n",
           obj_type_name[obj_word], obj_type_size[obj_word], txt);
    val_f = +3.2;
    create_node(&leaf_d, &val_f, obj_type_size[obj_float]);
    tree_a.node_type = obj_float; tree_a.object_size = obj_type_size[obj_float];
    node_to_text(&tree_a, leaf_d, txt, 1);
    printf("Source node type '%s' size %u bytes and value in float %s.\n",
           obj_type_name[obj_float], obj_type_size[obj_float], txt);
    // Тестирование копирования и сравнения узлов, текста, слова и числа с плавающей точкой.
    printf("\nTesting copy nodes and compare with various types.\n"
           "Results may be 0 - equal, 1 - is more, -1 - is less.\n");
    tree_a.node_type = obj_text; tree_a.object_size = strlen(text_data);
    copy_node(&leaf_e, leaf_b, strlen(text_data));
    node_to_text(&tree_a, leaf_e, txt, 1);
    printf("Copy node with text to empty node, result '%s'.\n", txt);
    r = compare_nodes(&tree_a, leaf_b, leaf_e);
    printf("Result of comapare texts %hd.\n", r);
    printf("Trying to copy obect to already exist node, prevent memory leak.\n");
    copy_node(&leaf_e, leaf_d, obj_type_size[obj_float]);
    destroy_node(&leaf_e, strlen(text_data));
    tree_a.node_type = obj_float; tree_a.object_size = obj_type_size[obj_float];
    copy_node(&leaf_e, leaf_d, obj_type_size[obj_float]);
    *((float*)leaf_d->object) += float_eps;
    r = compare_nodes(&tree_a, leaf_e, leaf_d);
    printf("Result of compare floats (%.2f) and (%.2f) with epsiolon (%.2f) is %hd.\n",
           *(float*)leaf_e->object, *(float*)leaf_d->object, float_eps, r);
    printf("\nTesting moving nodes and compare for check.\n");
    destroy_node(&leaf_e, obj_type_size[obj_float]);
    move_node(&leaf_e, &leaf_c);
    tree_a.node_type = obj_word; tree_a.object_size = obj_type_size[obj_word];
    node_to_text(&tree_a, leaf_e, txt, 1);
    printf("Check word object after moving '%s', cleared source address (%p).\n", txt, leaf_c);
    // Тестирование добавления в дерево, поиска элементов и вывода дерева.
    printf("\n\nTesting print tree with nodes and basic search.\n\n");
    tree_a.data_size = 0; tree_a.node_type = obj_text; tree_a.object_size = obj_type_size[obj_text];
    printf("\nCreate tree. Add nodes to empty text tree, just chars size %hu.\n\n", data_max);
    // char data_chars[] = "GEFCLIJDKAHB";
    char data_chars[] = "FBADCEIGHJ";
    create(&tree_a, data_chars, strlen(data_chars), obj_type_size[obj_text], obj_text, 0);
    print(&tree_a, 1);
    // Обход дерева несколькими способами, с выводом результата.
    printf("\nTraverse tree using different types of search.\n\n\n");
    for (i = 0; i < sr_left_right_node; ++i) {
        traverse(&tree_a, i);
        printf("\nAll nodes in tree A, search type '%s': ", search_name[sr_left_node_right]);
        for (j = 0; j < tree_nodes_size; ++j) {
            node_to_text(&tree_a, tree_nodes[j], txt, 1);
            printf("%s ", txt);
        }
        printf("\n\n");
    }
    // Копирование дерева с созданием нового объекта и попытка перемещения.
    printf("\nCopy all nodes tree, creating new object and compare, free memory %hu.\n\n\n", memory_free);
    copy(&tree_b, &tree_a);
    print(&tree_b, 2);
    r = compare(ptr_tree_a, ptr_tree_b, 1);
    if (!r)
        printf("Yes, trees (%p) and (%p) are equal and also with order flag.\n", ptr_tree_a, ptr_tree_b);
    else
        printf("No, trees (%p) and (%p) are not equal with order flag.\n", ptr_tree_a, ptr_tree_b);
    printf("\nTrying to move to existing tree, preventing memory leak.\n\n");
    move(&ptr_tree_a, &ptr_tree_b);
    // Удаление дерева для последующего перемещения.
    printf("\nDestroy copy of tree and free nodes, memory used %hu bytes.\n\n", memory_used);
    destroy(ptr_tree_a);
    printf("\nMoving tree from previous copy to first source and print all nodes.\n\n");
    move(&ptr_tree_a, &ptr_tree_b);
    print(ptr_tree_a, 1);
    // Удаление узлов по всем возможным схемам удаления.
    sub_node(ptr_tree_a, &data_chars[0]);
    print(ptr_tree_a, 1);
    sub_node(ptr_tree_a, &data_chars[4]);
    print(ptr_tree_a, 1);
    sub_node(ptr_tree_a, &data_chars[1]);
    print(ptr_tree_a, 1);
    sub_node(ptr_tree_a, &data_chars[8]);
    print(ptr_tree_a, 1);
    sub_node(ptr_tree_a, &data_chars[2]);
    print(ptr_tree_a, 1);
    sub_node(ptr_tree_a, &data_chars[3]);
    print(ptr_tree_a, 1);
    sub_node(ptr_tree_a, &data_chars[6]);
    print(ptr_tree_a, 1);
    destroy(ptr_tree_a);
    // Создание несбалансированного дерева и его простая балансировка.
    printf("\nCreate unbalance tree and balance it.\n\n\n");
    char data_unbalance[] = "ABCDEFG";
    ptr_tree_a = &tree_a; ptr_tree_b = &tree_b;
    create(ptr_tree_a, &data_unbalance, 7, 1, obj_text, 0);
    print(ptr_tree_a, 1);
    balance(ptr_tree_b, ptr_tree_a);
    print(ptr_tree_b, 1);
    // Удаление дерева, отдельных узлов и очистка памяти с проверкой.
    printf("\nClear all trees, nodes and free dynamic memory.\n\n\n");
    destroy(ptr_tree_a);
    destroy(ptr_tree_b);
    destroy_node(&leaf_a, sizeof(byte_values));
    destroy_node(&leaf_b, strlen(text_data));
    destroy_node(&leaf_c, obj_type_size[obj_word]);
    destroy_node(&leaf_d, obj_type_size[obj_float]);
    destroy_node(&leaf_e, obj_type_size[obj_word]);
    printf("\nCheck memory used before exit %hu, free memory %hu bytes.\n", memory_used, memory_free);
    return 0;
}
