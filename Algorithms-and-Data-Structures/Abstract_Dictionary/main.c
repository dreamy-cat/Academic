#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/* Лабораторная работа 1. Абстрактный словарь с динамической памятью. Условие как есть.
 *
 *  Реализовать абстрактную структуру данных словарь (коллекция ключ-значение) на языке Си.
 *  Ключ - Си-строка. Значение может быть любым. Для работы необходимо реализовать две
 * структуры и функции, которые работают с ними.
 *  1. Структура 'keyvalue' для хранения ключа и значения(рекомендация char* и void*) и
 * следующие функции: создание; уничтожение; копирование; сравнение.
 *  2. Структура dictionary для реализации списка и функции: создание; уничтожение;
 * копирование; добавление элемента(realloc); удаление элемента; поиск элемента; печать(если базовый тип).
 *  Использовать модульный подход.
 *
 *  Комментарий.
 *   Задание крайне неопределенное, и в общем виде слишком объёмное для простой лабораторной.
 *  Также не заданы ограничение и форматы структур. Пара ключ значение, удобней было бы хранить вместе с
 *  дополнительной информацией о размере и типе. Все адреса расчитаны на вывод под 32-битный
 *  компилятор и выводятся в скобках. Проверено на GCC 8.1.0, библиотеки: stdio, stdlib, memory.
 *
 * */

enum data_types { undefined, byte, word, floating, text };                      // Типы допустимые для печати в словаре.
static const char* type_names[] = { "data", "byte", "word", "float", "text" };  // Их названия для удобства вывода.

struct dictionary {                                                             // Главная структура словаря.
    unsigned int elements, dict_size, *sizes;                                   // Общее количество элементов, размер словаря в байтах, динамический массив размеров пар.
    struct key_value {                                                          // Сразу объявляем структуру пары ключ-значение.
        char* key;                                                              // Обычная Си-строка, под динамическое выделение.
        void* value;                                                            // Адрес на динамический блок памяти, тип неопределен.
    }* data;                                                                    // Динамический массив пар, выделяется или освобождается по мере необходимости.
    enum data_types* types;                                                     // Дополнительный динамический массив с типами, для вывода и сравнения.
};

int create_key_value(struct key_value* pair, char* key, void* value, unsigned int val_size)
{   // Функция создания пары ключ-значеие. Память для ключа и значения выделяется динамически. Параметры копируются полностью в новую память.
    // Адреса ключа и значение новой пары должны быть занулены, иначе они рассматриваются как занятые.
    if (pair == NULL || key == NULL || value == NULL || val_size == 0) {        // Все объекты должны существовать и быть определены. Размер занимаемой памяти не 0.
        printf("Pair, key or value adresses is NULL or incorrect object size.\n");
        return -1;
    }
    unsigned int size = 0;                                                      // Определим размер ключа Си-строки в байтах.
    while (key[size] != '\0')
        ++size;
    if (pair->key != NULL || pair->value != NULL) {                             // Проверим, если под ключ и значение уже была выделена память.
        printf("Warning, key is already created or one of adresses is NULL.\n");
        return -1;
    }
    pair->key = (char*)malloc(size + 1);                                        // Выделяем динамическую память под ключ и значения из кучи.
    pair->value = malloc(val_size);
    if (pair->value == NULL || pair->key == NULL) {                             // Проверяем успешность выделения памяти.
        printf("Error memory allocating for pair structure (%p) or key (%p) or value (%p).\n", pair, pair->key, pair->value);
        exit(-1);
    }
    memccpy(pair->key, key, '\0', size + 1);                                    // Копируем содержимое памяти ключа и значения в новое место.
    memcpy(pair->value, value, val_size);
    printf("New pair (%p) created, key at (%p) size %u and value at (%p).\n", pair, pair->key, size, pair->value);
    return 0;                                                                   // Всё успешно, выходим.
}

int destroy_key_value(struct key_value* pair)
{   // Функция уничтожения пары ключ-значение и освобождения динамической памяти.
    if (pair == NULL || pair->key == NULL || pair->value == NULL) {             // Все объекты должны существовать и быть определены в памяти.
        printf("Pair at (%p), key at (%p) or value at (%p) is NULL.\n", pair, pair->key, pair->value);
        return -1;
    }
    free(pair->key);                                                            // Освобождаем память занятую ключем и значением.
    free(pair->value);
    pair->key = NULL;                                                           // Обнулим для дальнейшего использования в других функциях, как флаг.
    pair->value = NULL;
    printf("Destroy pair at (%p), free key and value memory.\n", pair);
    return 0;
}

int copy_key_value(struct key_value* dst, struct key_value* src, unsigned int size)
{   // Функция копирования пары источника в пару назначения. Максимальный размер объекта в байтах.
    // Данные в памяти приёмника полностью освобождаются и создаются заново копированием из источника.
    if (dst == NULL || src == NULL || dst == src || src->key == NULL || src->value == NULL
            || src->key[0] == '\0' || size == 0) {                              // Проверяем параметры на допустимость, кроме памяти под пару назначения.
        printf("dst or src is NULL, or size incorrect;\n");
        return -1;
    }
    if (dst->key != NULL)                                                       // Если пара содержала объекты ключа или значения, то они удаляются и память освобождается.
        free(dst->key);
    if (dst->value != NULL)
        free(dst->value);
    unsigned int len = 0;                                                       // Вычисляем фактическую длину ключа источника.
    while (src->key[len] != '\0')
        ++len;
    if ((dst->key = (char*)malloc(len + 1)) == NULL) {                          // Выделяем память под ключ назначения.
        printf("Error memory allocating for destination key.\n");
        exit(-1);
    }
    memccpy(dst->key, src->key, '\0', len + 1);                                 // Копируем ключ вместе с терминальным символом.
    if ((dst->value = (char*)malloc(size)) == NULL) {                           // Выделяем блок памяти под значение в байтах, с учетом максимально допустимого размера.
        printf("Error memory allocating for destination value.\n");
        exit(-1);
    }
    memcpy(dst->value, src->value, size);                                       // Копируем содержимое значение источника по размеру.
    printf("Copy pair key-value success. New key at (%p), value at (%p), data copied.\n", dst->key, dst->value);
    return 0;
}

int compare_key_value(struct key_value* pair_a, struct key_value* pair_b, enum data_types type, unsigned int size)
{   // Функция сравнения пар ключ-значения, только по значению. Сами ключи игнорируется, проверка на стороне вызова, по желанию.
    // Сравнивается только в пределах типа или по максимальному размеру памяти, если тип не определен, байтовый или текст.
    // Возвращает: 0 - если величины равны, -1 - если 1-е значение меньше 2-го, 1 - если наоборот.
    if (size == 0 || pair_a == NULL || pair_b == NULL || type < undefined || type > text
            || pair_a->key == NULL || pair_a->value == NULL || pair_b->value == NULL || pair_b->key == NULL) {
        printf("Data pair A or pair b is NULL, or other parameters incorrect.\n");
        return -2;                                                              // Проверяем всё на допустимость, чтобы не обратиться к несуществующему объекту в памяти.
    }
    unsigned int r = 0, it;
    printf("Comparing data in pairs 'A' at (%p) and 'B' at (%p), type '%s' and memory size %u, iterations: ",
           pair_a, pair_b, type_names[type], size);
    switch (type) {                                                             // Тип сравнения, реинтерпретация данных как есть.
    case undefined:                                                             // Простое побайтное сравнение.
    case byte:
    case text:
        for (it = 0; it < size && !r; ++it)
            if (*((char*)pair_a->value + it) > *((char*)pair_b->value + it))    // Через базовый тип char.
                r = 1;
            else if (*((char*)pair_a->value + it) < *((char*)pair_b->value + it))
                r = -1;
        break;
    case word:                                                                  // Сравнение по словам, 16 бит.
        for (it = 0; it < size / sizeof(short) && !r; ++it)
            if (*((short*)pair_a->value + it) > *((short*)pair_b->value + it))
                r = 1;
            else if (*((short*)pair_a->value + it) < *((short*)pair_b->value + it))
                r = -1;
        break;
    case floating:                                                              // Сравнение чисел с плавающей точкой.
        for (it = 0; it < size / sizeof(float) && !r; ++it)
            if (*((float*)pair_a->value + it) > *((float*)pair_b->value + it))
                r = 1;
            else if (*((float*)pair_a->value + it) < *((float*)pair_b->value + it))
                r = -1;
        break;
    default:
        break;
    }
    printf("%u, result is %u.\n", it, r);
    return r;
}

void create_dictionary(struct dictionary* dict)
{   // Функция создания словаря, инициализация всех данных структуры. Сам объект словаря должен существовать.
    // Если адреса динамических массивов не равны нулю, то считаем что память выделена и
    // необходимо сначала вызвать очистку и уничтожение словаря.
    if (dict->data != NULL || dict->sizes != NULL || dict->types != NULL) {     // Проверяем на допустимость и параметры и занятую память.
        printf("Error, data, sizes or types in dictionary is not NULL, may be memory leaks.\n");
        return;
    }
    printf("Dictionary initialization header at address (%p).\n", dict);
    dict->elements = dict->dict_size = 0;                                       // Обнуляем все параметры.
    dict->data = NULL;
    dict->sizes = NULL;
    dict->types = NULL;
}

void destroy_dictionary(struct dictionary* dict)
{   // Функция уничтожения словаря. Очищаются все элементы словаря, в каждой паре освобождается память занятая данными.
    if (!dict->elements || dict->data == NULL || dict->sizes == NULL || dict->types == NULL) {
        printf("Dictionary is already empty, or some addresses is NULL.\n");    // Словарь должен существовать и в нем должно быть один или более элементов.
        return;
    }
    printf("Destroy dictionary with %d elements, pairs addresses:\n", dict->elements);
    while (dict->elements) {                                                    // Удаляем весь массив пар и освобождаем память, занятую им.
        dict->elements--;
        destroy_key_value(dict->data + dict->elements);
        dict->dict_size -= dict->sizes[dict->elements];
    }
    free(dict->data);                                                           // Освобождаем память самих массивов.
    free(dict->sizes);
    free(dict->types);
    dict->data = NULL;                                                          // Обнулим для дальнейшего использования.
    dict->sizes = NULL;
    dict->types = NULL;
}

void print_dictionary(struct dictionary* dict)
{   // Функция вывода словаря и его содержимого. После типов и значений идет тоже самое, только в виде памяти, шестнадцатиричное представление.
    if (dict == NULL || dict->data == NULL || dict->sizes == NULL || dict->types == NULL) {
        printf("Print dictionary at (%p), data at (%p), sizes at (%p) or types at %p may be NULL.\n",
               dict, dict->data, dict->sizes, dict->types);                     // Проверяем словарь и его динамические массивы, они должны быть определены.
        return;
    }
    printf("\nDictionary elements %u, memory size %u.\n", dict->elements, dict->dict_size);
    printf("Address:\tKey:\tType:\t\tSize:\tValue and memory dump:\n");         // Шапка таблицы, с выравниванием, табуляции можно выставлять по вкусу.
    for (int i = 0; i < dict->elements; ++i) {                                  // Пробежимся по всем парам, которые содержаться в динамическом массиве словаря.
        struct key_value* pair = dict->data + i;
        printf("%p\t'%s'\t%s\t\t%u\t", (void*)pair, pair->key, type_names[dict->types[i]], dict->sizes[i]);
        switch (*(dict->types + i)) {                                           // В зависимости от типа, выводим элементы.
        case undefined:
            break;
        case byte:
            for (int j = 0; j < dict->sizes[i]; ++j)                            // Байт или здесь рассматриваем как простой символ.
                printf("'%c' ", ((char*)pair->value)[j]);
            break;
        case word:                                                              // Слово или короткое целое, 16 бит.
            for (int j = 0; j < dict->sizes[i] / sizeof(short); ++j)
                printf("%d ", ((short*)pair->value)[j]);
            break;
        case floating:                                                          // Число с плавающей точкой.
            for (int j = 0; j < dict->sizes[i] / sizeof(float); ++j)
                printf("%.2f ", ((float*)pair->value)[j]);
            break;
        case text:                                                              // Обычная Си-строка, выводим целиком.
            printf("'%s' ", (char*)pair->value);
            break;
        default:
            printf("Warning, type is unknown, data: ");
        }
        for (int j = 0; j < dict->sizes[i]; ++j)                                // Дополним вывод содержимым памяти.
            printf("0x%x ", *(unsigned char*)(pair->value + j));
        printf("\n");
    }
    printf("\n");
}

int find_in_dictionary(struct dictionary* dict, struct key_value* pair, unsigned int* idx)
{   // Функция поиска элемента в словаре, по ключу. Значение не учитывается.
    // Функция возвращает код ошибки, а найденный индекс в динамическом массиве через адрес на параметр idx.
    if (dict ==  NULL || pair == NULL || idx == NULL) {
        printf("Find in dictioanry, pair or index adresses are NULL.\n");       // Проверка на допустимость адресов.
        return -1;
    }
    unsigned int i = 0, j;
    int is_equal = 0;
    while (i < dict->elements && !is_equal) {                                   // Основной цикл пробегаем линейно по всему массиву пар.
        struct key_value* pair_ptr = (dict->data + i);
        // printf("Key addr in dictionary (%p).\n", pair_ptr);                  // Для отладки.
        for (j = 0; pair_ptr->key[j] != '\0' && pair->key[j] != '\0'; ++j)      // Сравниваем ключи.
            if (pair_ptr->key[j] != pair->key[j])
                break;
        if (pair_ptr->key[j] == pair->key[j]) {                                 // Если ключ найден, то завершаем поиск.
            printf("Key '%s' is founded in pair at (%p) address, index %d.\n", pair->key, pair_ptr, i);
            is_equal = 1;
        } else
            ++i;
    }
    if (is_equal) {                                                             // Если ключ найден, то возвращаем индекс через параметр.
        *idx = i;
        return is_equal;
    } else {
        printf("Key '%s' is not founded at any address in dictionary.\n", pair->key);
        return 0;
    }
}

int add_to_dictionary(struct dictionary* dict, struct key_value* pair, enum data_types type, unsigned int type_size)
{   // Функция добавления элемента или пары ключ-значение в словарь. Все размеры динамических массивов изменяются, если необходимо.
    // Тип и его размер можно заполнить в виде ENUM, sizeof(TYPE) при вызове функции.
    if (dict == NULL || pair == NULL || pair->key == NULL || pair->value == NULL || type < undefined || type > text || type_size == 0) {
        printf("Warning, some of adresses are incorrect, check dictionary and pair parameters.\n");
        return -1;                                                              // Проверка на допустимость адресов и параметров, т.к. уже много всего,
    }                                                                           // то возможно стоит оформить отдельную функции проверки целостности словаря.
    unsigned int index = 0, is_equal = find_in_dictionary(dict, pair, &index);  // Поиск ключа, если ключ уже присутствует в словаре, то не добавляем.
    if (!is_equal) {
        printf("Key '%s' is new or dictionary is empty.\n", pair->key);
        if (!dict->elements) {                                                  // Ключ не найден, если словарь пустой, то создаем памяти ровно на один элемент.
            dict->data = (struct key_value*)calloc(1, sizeof(struct key_value));
            dict->sizes = (unsigned int*)calloc(1, sizeof(unsigned int));       // Все адреса должны быть занулены, если словарь не был инициализирован, то не определенное поведение.
            dict->types = (enum data_types*)calloc(1, sizeof(enum data_types));
        } else {                                                                // Ключ не найден, расширяем словарь сохраняя все предыдущие элементы.
            dict->data = (struct key_value*)realloc(dict->data, sizeof(struct key_value) * (dict->elements + 1));
            dict->sizes = (unsigned int*)realloc(dict->sizes, sizeof(unsigned int) * (dict->elements + 1));
            dict->types = (enum data_types*)realloc(dict->types, sizeof(enum data_types) * (dict->elements + 1));
        }
        if (dict->data == NULL || dict->sizes == NULL || dict->types == NULL) { // Если произошла ошибка при выделении памяти из кучи.
            printf("Error, dict (%p), sizes (%p) or types (%p) is NULL.\n", dict->data, dict->sizes, dict->types);
            exit(-1);
        } else
            printf("Memory (re)allocating successfully, new address of pairs: (%p), sizes: (%p) and types: (%p).\n",
                   dict->data, dict->sizes, dict->types);
        struct key_value* new_pair = dict->data + dict->elements;               // Если всё успешно, то формируем новую пару, адрес указывает на следующий элемент в массиве.
        new_pair->key = NULL; new_pair->value = NULL;                           // Обнуляем для гарантии создания ключа.
        if (create_key_value(new_pair, pair->key, pair->value, type_size) == -1) {
            printf("Warning, can't create new pair, free reallocating memory.\n");
            dict->data = (struct key_value*)realloc(dict->data, sizeof(struct key_value) * dict->elements);
            dict->sizes = (unsigned int*)realloc(dict->sizes, sizeof(unsigned int) * dict->elements);
            dict->types = (enum data_types*)realloc(dict->types, sizeof(enum data_types) * dict->elements);
            return -1;                                                          // Если не смогли создать новую пару, то освобождаем выделенную под новый элемент память и выходим.
        }
        printf("New pair successfully added. Key '%s', type '%s' with size %u bytes.\n", new_pair->key, type_names[type], type_size);
        dict->sizes[dict->elements] = type_size;                                // Сохраняем размерность типа данных или массива данных, если было несколько элементов.
        dict->types[dict->elements] = type;                                     // Сохраняем тип данных, который вошел в словарь.
        dict->dict_size += type_size;                                           // Увеличиваем размер словаря на количество байт.
        dict->elements++;                                                       // Увеличиваем количество элментов в словаре.
    } else
        printf("The key '%s' is already in dictioanary.\n", pair->key);
    return 0;
}

int sub_from_dictionary(struct dictionary* dict, struct key_value* pair)
{   // Функция удаления элемента из словаря по ключу. Если ключ не найден или словарь пустой, то изменений не происходит.
    if (dict == NULL || pair == NULL || dict->data == NULL || dict->sizes == NULL || dict->types == NULL
            || pair->key == NULL || pair->value == NULL) {                      // Проверка на допустимость и существования объектов.
        printf("Warning, dictionary or pair adresses is null, or no elements.\n");
        return -1;
    }
    unsigned int idx = 0;
    if (find_in_dictionary(dict, pair, &idx) == 1) {                            // Поиск элемента в словаре.
        printf("Key '%s' is founded in dictionary at index %d, clear pair.\n", pair->key, idx);
        destroy_key_value(&dict->data[idx]);                                    // Если ключ найден, то освобождаем данные динамической памяти в удаленной паре.
        dict->dict_size -= dict->sizes[idx];
        if (idx < dict->elements - 1) {
            printf("Copy last element with key '%s' of dictionary to removed at %p.\n",
                   dict->data[dict->elements - 1].key, &dict->data[idx]);       // Копируем последний элемент словаря на место удаленного элемента.
            copy_key_value(&dict->data[idx], &dict->data[dict->elements - 1], dict->sizes[dict->elements - 1]);
            dict->sizes[idx] = dict->sizes[dict->elements - 1];                 // Дополнительные параметры пары перемещаем аналогично.
            dict->types[idx] = dict->types[dict->elements - 1];
            // print_dictionary(dict);                                          // Дополнительная отладка.
        } else                                                                  // Если в словаре был один элемент, то просто его удаляем.
            printf("Just clear last pair with key '%s', nothing to copy in data.\n", dict->data[dict->elements - 1].key);
        if (--dict->elements) {                                                 // Если было несколько элементов, уплотняем данные.
            destroy_key_value(&dict->data[dict->elements]);                     // Удаляем последний элемент и уплотняем динамические массивы.
            dict->data = (struct key_value*)realloc((void*)dict->data, sizeof(struct key_value) * dict->elements);
            dict->sizes = (unsigned int*)realloc((void*)dict->sizes, sizeof(unsigned int) * dict->elements);
            dict->types = (enum data_types*)realloc((void*)dict->types, sizeof(enum data_types) * dict->elements);
            // print_dictionary(dict);                                          // Дополнительная отладка.
            if (dict->data == NULL || dict->sizes == NULL || dict->types == NULL) {
                printf("Error re(allocating) data at (%p), sizes at (%p) or types at (%p).\n",
                       dict->data, dict->sizes, dict->types);
                exit(-1);
            } else
                printf("Data reallocating succefully, data at (%p), sizes at (%p) and types at (%p).\n",
                       dict->data, dict->sizes, dict->types);
        } else {
            printf("Pair was last in dictionary, clear all data dictionary and free memory.\n");
            destroy_dictionary(dict);                                           // Удаление словаря здесь может быть необязательным.
        }
    } else {                                                                    // Если ключ не был найден или словарь оказался пустой.
        printf("Warning, key '%s' not founded, or dictionary is empty.\n", pair->key);
        return -1;
    }
    return 0;
}

struct color {                                                                  // Дополнительная структура данных, не требуется для самого задания,
    unsigned short red;                                                         // но для демонстрации не совсем корректной работы сравнения пар ключ-значения,
    unsigned char green;                                                        // при условии отсутствия полной инициализации структур.
    // unsigned char extra;                                                        // Если закомментировать эту строку, то будет как раз ошибка, тест ниже.
    unsigned int blue;                                                          // Т.к. образуется один байт не инициализируемых данных.
};

int main(int argc, char* argv[])
{
    printf("Simple dictionary with CString-Data as key-value, using dynamic memory.\n\n");
    struct key_value pair_a = { NULL, NULL }, pair_b = { NULL, NULL };
    const char data_char = 'a';
    const short data_short = 0x1000;
    const float data_float = 0.12345;
    const char data_text[] = "abc";
    int result;

    // Тестирование пары ключ-значение и функций по отдельности.
    printf("Compare pairs of float arrays and data.\n");
    const float floats_a[2] = { 1.1, 1.2 }, floats_b[2] = { 1.1, 1.2 };
    // memcpy((void*)floats_b, (void*)floats_a, sizeof(floats_a));              // Если не использовать инициализацию для второго массива, то просто скопируем память.
    printf("Float array A(%.1f, %.1f); B(%.1f, %.1f)), memory size is %u.\n",
           floats_a[0], floats_a[1], floats_b[0], floats_b[1], sizeof(floats_a));
    create_key_value(&pair_a, "A",(void*)floats_a, sizeof(floats_a));           // Создаем две пары для сравнения.
    create_key_value(&pair_b, "B",(void*)floats_b, sizeof(floats_b));
    result = compare_key_value(&pair_a, &pair_b, floating, sizeof(floats_a));   // Сравнение пар массивов чисел с плавающей точкой.
    printf("Compare array with floatings: %d.\n", result);
    destroy_key_value(&pair_a);                                                 // Очищаем память, закрываем объекты.
    destroy_key_value(&pair_b);

    // Тестирование сравнения двух структур с демонстрацией некорректной работы, без должной инициализации. Результат может быть неопределен.
    printf("\nCompare pairs of structures 'color' with various field size[short, char, int].\n");
    struct color rgb_a[2] = { {1, 2, 3}, {1, 2, 3} }, rgb_b[2] = { {1, 2, 3}, {1, 2, 3} };
    // memcpy((void*)rgb_b, (void*)rgb_a, sizeof(rgb_a));                       // Если использовать копирование именно всей памяти, то сравнение отработает нормально.
    printf("Structure color size is %u with offsets for red: %u, green: %u and blue: %u. Array size %u.\n", sizeof(struct color),
           (void*)&rgb_a[0].red - (void*)&rgb_a[0], (void*)&rgb_a[0].green - (void*)&rgb_a[0], (void*)&rgb_a[0].blue - (void*)&rgb_a[0], sizeof(rgb_a));
    create_key_value(&pair_a, "A",(void*)&rgb_a, sizeof(rgb_a));                // Создаем ключи на базе массива 2 структур.
    create_key_value(&pair_b, "B",(void*)&rgb_b, sizeof(rgb_b));
    result = compare_key_value(&pair_a, &pair_b, undefined, sizeof(rgb_a));     // Сравнение неопределено, даже если использована встроенная инициализация,
    printf("Result of compare is %d.\n", result);                               // необходимо память очистить или использовать копирование памяти с объектами.
    destroy_key_value(&pair_a);
    destroy_key_value(&pair_b);

    // Тестирование создания и уничтожения словаря и остальных функций для ключа и значения.
    struct dictionary dict = { 0, 0, NULL, NULL, NULL };                        // Инициализация обязательна, отвествтенность на стороне вызова.
    struct key_value pair =  { NULL, NULL };
    printf("\nCreate and destroy dictionary and try add to add 2 copy elements and one unique, using one pair.\n");
    printf("Structure of dictionary size %u bytes, key and value pair is %u bytes.\n", sizeof(dict), sizeof(struct key_value));
    create_dictionary(&dict);
    create_key_value(&pair, "A", (void*)&data_char, sizeof(char));              // Создаем активную пару, которой будем производить действия.
    print_dictionary(&dict);
    add_to_dictionary(&dict, &pair, byte, sizeof(char));
    print_dictionary(&dict);                                                    // Попытка добавить один и тот же ключ в словарь дважды.
    add_to_dictionary(&dict, &pair, byte, sizeof(char));
    print_dictionary(&dict);
    destroy_key_value(&pair);
    printf("\nCreate new key, add to dictioanry and delete key, copy must be in dictionary.\n");
    create_key_value(&pair, "B", (void*)&data_short, sizeof(short));            // Создаем пару с коротки целым на 16 бит.
    add_to_dictionary(&dict, &pair, word, sizeof(short));
    destroy_key_value(&pair);                                                   // Уничтожаем объект пары, и проверяем его копию.
    print_dictionary(&dict);
    printf("Destroy dictionary with elements, memory must be free.\n");
    destroy_dictionary(&dict);                                                  // Уничтожаем объект словаря с элементами, память должна полностью освободиться.
    print_dictionary(&dict);

    // Тестирование добавления и удаления элементов словаря со смещением и перераспределением памяти.
    printf("\nAdd 2 elements to dictionary, then try sub non existing element.\n\n");
    // create_dictionary(&dict);
    create_key_value(&pair, "B",(void*)&data_float, sizeof(float));             // Добавляем последовательно три элемента, разных типов.
    add_to_dictionary(&dict, &pair, floating, sizeof(float));
    print_dictionary(&dict);
    destroy_key_value(&pair);
    create_key_value(&pair, "C",(void*)data_text, sizeof(float));
    add_to_dictionary(&dict, &pair, text, sizeof(float));
    print_dictionary(&dict);
    destroy_key_value(&pair);
    create_key_value(&pair, "A",(void*)&data_char, sizeof(char));               // Пытаемся удалить несуществующий элемент.
    sub_from_dictionary(&dict, &pair);
    print_dictionary(&dict);
    destroy_key_value(&pair);
    // Удаляем первый элемент с уплотнением данных копируя последний на место удаленного, т.к. порядок не важен.
    printf("\nSub from dictioanary first two elements and destroy empty with function.\n\n");
    create_key_value(&pair, "B",(void*)&data_float, sizeof(float));             // Удаляем первый элемент и смещаем на его место последний.
    sub_from_dictionary(&dict, &pair);
    print_dictionary(&dict);
    destroy_key_value(&pair);
    create_key_value(&pair, "C",(void*)data_text, sizeof(float));               // Удаляем последний элемент в словаре.
    sub_from_dictionary(&dict, &pair);
    print_dictionary(&dict);
    destroy_key_value(&pair);
    destroy_dictionary(&dict);                                                  // Выходим и смотрим если разрушения памяти. :)
    return 0;
}
