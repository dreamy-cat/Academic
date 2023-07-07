// 11-глава, теория с вопросами.

#include <stdio.h>

#define ARRAY_SIZE 3

void theory_10_1(int data[], int n)
{
    printf("Transfaer array to function as pointer: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", data[i]);
    printf("\n");
}

void theory_10_2(int* first, int* last)
{
    printf("Transfer array to function as first and last element.: ");
    while (first <= last) {         // Быть очень внимательным относительно знаков.
        printf("%d ", *first);
        ++first;
    }
    printf("\n");
}

void print_array_addr(void* data, int elements, int element_size)
{   // Вывод массива с реинтерпретацией данных, использовать позднее в практической части.
    printf("Array with %d elements and memory size is %d.\nAddress:\tData:\n", elements, element_size * elements);
    if (element_size <= 0 || element_size >= 4) {
        printf("Error, element size must be in (1..4).\n");
        return;
    }
    for (int i = 0; i < elements; ++i) {
        printf("%p\t", data);
        switch (element_size) {
        case sizeof(char):
            printf("char: %d, hex(char): %x(%c)", *((char*)data), *((char*)data), *((char*)data));
            // data++; warning: arithmetic on a pointer to void is a GNU extension
            break;
        case sizeof(short):
            printf("short: %hd, hex(char): ", *((short*)data));
            break;
        case sizeof(int):
            printf("int: %d, hex(char): ", *((int*)data));
            break;
        default:
            printf("What element type using 3 bytes...\n");
        }
        for (int j = 0; j < element_size; ++j)
            printf("%x(%c) ", *((char*)data + j), *((char*)data + j));
        data = (void*)((char*)data + element_size);
        printf("\n");
    }
}

void part_10(void)
{
    printf("Theory. Chapter 10, ararays and pointers(addresses).\n\n");
    // Перед вещанием проверить флаги проверки "-Wall -Wextra"
    // Вопрос 1. Что такое массив и как он объявляется в программе на прмере. Размеры по константам и переменным, расчет.
    const int data_size = 3;
    // int data[data_size];  warning: variable length array folded to constant array as an extension
    int v_size = 5;
    // int var_array[v_size];              // warning: variable length array used
    int var_array[sizeof(int) * 3];        // ok, not negative.
    int data[ARRAY_SIZE] = { 1, 2, 3 };       // no warning, init ok or using static.
    printf("Data array of integers with %d elements size in memory is %u bytes.\n", ARRAY_SIZE, sizeof(data));
    // Вопрос 2. Константность и её применение, на примере цветов и автоматическая размерность массива.
    const char* colors[] = { "red", "green", "blue" };
    // colors[0][1] = 'a'; error: read-only variable is not assignable.
    // Вопрос 3. Классы хранения массива и где они располагаются. Автоматическая инициализация и освобождение памяти.
    // Вопрос 4. Инициализация и назначенные инициализаторы.
    short sh_array[ARRAY_SIZE] = { 1, [2] = 5 };
    printf("Uninitialized array of shorts: ");
    for (int i = 0; i < data_size; ++i)
        printf("%d ", sh_array[i]);
    printf("\n");
    // Вопрос 5. Копирование массивов и контроль за выходом за границы массива.
    printf("Offset -1 in array of shorts, value is %hd.\n", sh_array[-1]);   // warning: array index -1 is before the beginning of the array
    // Вопрос 6. Многомерные массивы, инициализация и размерности по возрастанию, отметить про числа с плавающей точкой.
    int matrix[2][ARRAY_SIZE] = { {0, 1, 2}, {3, 4, 5} };   // Большие удобней оформлять в много строчек.
    printf("Array with sizes [2,3], bytes in memory is %u.\n", sizeof(matrix));
    printf("Elements and addresses of array.\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < ARRAY_SIZE; ++j)
            printf("%d[%p]\t", matrix[i][j], (void*)(&matrix[i][j]));
        printf("\n");
    }
    // Вопрос 7. Указатели. Адреса размещения данных в Си, притворяются массивами. Первый элемент.
    // Вопрос 8. Обращение к элементу массива, индес память и смещения элементов в памяти, порядок следования байт.
    printf("Address of array %p, first element address %p.\n", (void*)data, (void*)&data[1]);
    int offset = (int)(&data[1] - data);            // Смещение с реинтепрпритацией данных.
    printf("Offset as difference with integer pointers is %d.\n", offset);
    offset = (int)((char*)&data[1] - (char*)data);
    printf("Offset as difference with char pointers is %d.\n", offset);
    offset = (int)(&sh_array[2] - sh_array);
    printf("Offset in array of short from 2 to 0, %d elements or ", offset);
    // offset = (int)((void*)&sh_array[2] - (void*)sh_array);      // void* as gnu extension.
    offset = (int)((char*)&sh_array[2] - (char*)sh_array);
    printf("%d bytes.\n", offset);          // mov instruction and performance.
    char cube[2][2][2] = { { {'a', 'b'}, {'c', 'd'} }, {{'e', 'f'}, {'g', 'h'}} };  // Простая инициализация.
    printf("Size of cube with side 2 of chars: %u.\n", sizeof(cube));
    char* char_at_cube = cube;      //  warning: incompatible pointer types initializing 'char *' with an expression of type 'char [2][2][2]'
    printf("Using addresses on cube of chars[2, 2, 2] from (a..h), address of start: %p.\n", char_at_cube);
    char_at_cube = char_at_cube + 2 * 1 + 1;
    printf("Char at [0][1][1] as address and value: %c[%p].\n", *char_at_cube, (void*)char_at_cube);
    char_at_cube++;
    printf("Char at [1][0][0] as address and value: %c[%p].\n", *char_at_cube, (void*)char_at_cube);
    char_at_cube = char_at_cube - 2 * 2 + 2;
    printf("Char at [0][1][0] as address and value: %c[%p].\n", *char_at_cube, (void*)char_at_cube);
    // Что такое значение указателя, адреса байта является первым от младшего к старшему.
    if (*(char_at_cube + 2) == 'e')         // Быть осторожным с формой и скобками.
        printf("Yes, cube has 'e' char.\n");
    // Вопрос 9. Массивы, указатели и функции. Передача массива и просто адреса.
    theory_10_1(data, ARRAY_SIZE);
    theory_10_2(&data[0], &data[2]);
    // При передаче использовать лучше массив, по адресам, использование квадратных скобок.
    printf("Second element (%d) using [] and (%d) using *(address + idx).\n", data[1], *(data + 1));
    // Вопрос 10. Операции с указателями, исползовать для вывода %u, %lu, %td, %d, %ld если не поддерживается %p.
    printf("Source array of shorts, size %d.: ", ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; ++i)
        printf("%d ", sh_array[i]);
    printf("\n");
    print_array_addr((void*)sh_array, ARRAY_SIZE, sizeof(short));
    // Все базовые операции с адресами.
    printf("\nAssing ");
    // Указатели доделать часть.
    void* ptr_1 = &v_size;
    char* p_chr = ptr_1;
    printf("%p\n", p_chr);
    // Литералы, в довесок.
    theory_10_1((int [2]){1, 2}, 2);
}
