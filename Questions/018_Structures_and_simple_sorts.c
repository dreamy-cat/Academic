#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Лабораторная по структурам данных и простым сортировкам,
// полное условие задания ниже в главной функции 'void sort_structs(void)'.
// Файл в теории компилируется под GCC 8.1.0, 32 бита. Переименовать главную
// функцию в int main() - и скомпилировать. Не нужный вывод по ходу решеения
// можно удалить или добавить по вкусу. :)

#define OBJECTS_MAX 16
#define STRING_MAX 256

struct school_data {
    unsigned char index;
    char principal[STRING_MAX];
    unsigned char staff, students;
};

enum sort_key { index, principal, staff, students };

enum sort_type { ascending, descending };

void string_copy(char src[], char dst[], int limit)
{
    int i = 0;
    while (i < limit && src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

void print_school_data(struct school_data* data)
{
    printf("Index: %u, principal: '%s', staff: %u, students: %u.\n",
           data->index, data->principal, data->staff, data->students);
}

void print_schools_table(struct school_data data[], int size)
{   // Вывод в консоль, в ввиде таблицы.
    printf("\nFull schools table, size %d.\n", size);
    printf("Index:\tPrincipal:\tStaff:\tStudents:\n");
    for (int i = 0; i < size; ++i)
        printf("%u:\t\t'%-12s'\t%u\t\t%u\n", data[i].index, data[i].principal, data[i].staff, data[i].students);
}

// void update_school(struct school_data* update, unsgined char index, char principal_name[],...)
void update_school(struct school_data* update, struct school_data* new, int str_limit)
{   // Можно конструировать структуру из элементарных типов.
    printf("\nUpdate information of school.\n");
    printf("Source school data: ");
    print_school_data(update);
    printf("New school data: ");
    print_school_data(new);
    update->index = new->index;     // Можно использовать копирование памяти напрямую. memcpy...
    string_copy(new->principal, update->principal, str_limit);
    update->staff = new->staff;
    update->students = new->students;
    printf("Updated school data: ");
    print_school_data(update);
}

void xchg_schools(struct school_data* school_a, struct school_data* school_b)
{
    struct school_data t;       // Или можно копировать всю память по мере возможности.
    printf("\nExchange schools with indexes %u and %u, using update function.\n",
           school_a->index, school_b->index);
    update_school(&t, school_a, STRING_MAX);    // Или использовать переменную в качестве предела строки.
    update_school(school_a, school_b, STRING_MAX);
    update_school(school_b, &t, STRING_MAX);
}

int string_cmp(char s1[], char s2[])
{   // Функция сравнения строк, простая. Можно использовать после, как функцию сравнения.
    // Возвращаем: 0 - если строки полностью равны, 1 - первая строка "больше", -1 - первая строка меньше.
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        ++i;
    if (s1[i] > s2[i])  // ASCII сравнение
        return 1;
    if (s1[i] < s2[i])
        return -1;
    return 0;
}

void quick_sort_students(struct school_data data[], int first, int last, enum sort_type type)
{   // Не самая быстрая функция, но зато простая.
    int i, j;
    if (first >= last)
        return;
    xchg_schools(&data[first], &data[(first + last) / 2]);
    j = first;  // Разделитель, опорный элемент по центру и индекс для сравнений.
    for (i = first + 1; i <= last; ++i)
        if ((type == ascending && data[i].students < data[first].students) ||
                (type == descending && data[i].students > data[first].students))
            xchg_schools(&data[++j], &data[i]);
    xchg_schools(&data[first], &data[j]);
    quick_sort_students(data, first, j - 1, type);
    quick_sort_students(data, j + 1, last, type);
}

int sort_schools(struct school_data data[], int size, enum sort_key key, enum sort_type type)
{
    int iter = 0;
    if (size <= 1) {
        printf("Warning, size of data too small to sort.\n");
        return -1;
    }
    switch (key) {
    case index:
        printf("Selection sort, key = index, size of data %u.\n", size);
        for (int i = 0; i < size - 1; ++i) {
            int element = data[i].index, position = i;
            for (int j = i; j < size; ++j) {
                if ((type == ascending && element > data[j].index) ||
                        (type == descending && element < data[j].index)) {
                    element = data[j].index;
                    position = j;
                }
            }
            printf("Sort index %d and position %d.\n", i, position);
            if (position != i) {
                xchg_schools(&data[i], &data[position]);
                ++iter;
            }
        }
        break;
    case principal:
        printf("Insertion sort, key = principal, size of data %u.\n", size);
        for (int i = 1, j, k; i < size; ++i) {
            j = i;
            if (type == ascending)
                while ((j > 0) && string_cmp(data[i].principal, data[j - 1].principal) < 0)
                    --j;
            else if (type == descending)
                while ((j > 0) && string_cmp(data[i].principal, data[j - 1].principal) > 0)
                    --j;
            printf("Sort index %d and position %d.\n", i, j);
            if (i != j) {       // Смещение должно быть по всему массиву.
                // Используем функцию обмена потому что она уже есть.
                // Для оптимизации, если возможно, то лучше смещат массив линейно целиком на заданную позицию J.
                for (k = i; k != j; --k)
                    xchg_schools(&data[k], &data[k - 1]);
                ++iter;
                // print_school_table - если что для отладки.
            }
        }
        break;
    case staff:
        printf("Bubble sort, key = staff, size of data %d.\n", size);
        for (int i = 0, j, is_xchg = 1; i < size - 1 && is_xchg == 1; ++i) {
            for (j = 0, is_xchg = 0; j < size - i - 1; ++j)
                if ((type == ascending && data[j].staff > data[j + 1].staff) ||
                        (type == descending && data[j].staff < data[j + 1].staff)) {
                    xchg_schools(&data[j], &data[j + 1]);
                    iter++;
                    is_xchg = 1;
                }
        }
        break;
    case students:
        printf("Quick sort, key = students, size of data %d.\n", size);
        quick_sort_students(data, 0, size - 1, type);
        break;
    }
    return iter;
}

int sort_structs(void)   // main() - Точка входа в программу, без аргументов, возвращаемое значение целое, код ошибки.
{
    /*Создать массив, элементами которого являются структуры – список школ
     * (номер школы, фамилия директора, кол-во учащихся, кол-во учителей).
     * Создать функцию, сортирующую данную структуру (например, по кол-ву учащихся),
     * и функцию для изменения информации конкретной школы.
     * Использовать эти функции по назначению в программе
     * (для вывода отсортированной информации и изменения нужной информации)
     * */
    printf("Extra task with data structures of schools and sort function.\n");
    printf("From out follower, Sashka0089, march 2021.\n\n");
    struct school_data schools[OBJECTS_MAX];
    printf("Data structure of school:\n");
    printf("Index of school, range [0..%u], size in bytes %u.\n", UCHAR_MAX, sizeof(schools[0].index));
    printf("Principal, maximum string size in char(bytes) %u.\n", STRING_MAX);
    printf("Staff in school, range [0..%u], size in bytes %u.\n", UCHAR_MAX, sizeof(schools[0].staff));
    printf("Students in school, range [0..%u], size in bytes %u.\n", UCHAR_MAX, sizeof(schools[0].students));
    printf("Offsets of data in school structure:\n");
    printf("Index:\t\t+#%p.\n", (void*)(&schools[0].index - &schools[0].index));
    printf("Principal:\t+#%p.\n", (void*)((void*)&schools[0].principal - (void*)&schools[0].index));
    printf("Staff:\t\t+#%p.\n", (void*)(&schools[0].staff - &schools[0].index));
    printf("Students:\t\t+#%p.\n", (void*)(&schools[0].students - &schools[0].index));
    printf("Size of structure %u bytes, elements in array %u and total size %u bytes.\n\n",
           sizeof(struct school_data), OBJECTS_MAX, sizeof(schools));
    const int schools_max = 5, name_size = 5, alphabet = 26;
    printf("Generate list of schools and fills parameters with random values, items = %u.\n", schools_max);
    for (int i = 0; i < schools_max; ++i)   // Иногда лучше использовать отдельную функцию для генерации отдельнлой структуры.
        schools[i].index = (unsigned char)i + 1;
    for (int i = 0; i < schools_max; ++i) { // Параметр по вкусу.
        int pos_a = rand() % schools_max, pos_b = rand() % schools_max;
        unsigned char tmp_index = schools[pos_a].index;
        schools[pos_a].index = schools[pos_b].index;
        schools[pos_b].index = tmp_index;
    }
    for (int i = 0; i < schools_max; ++i) {
        for (int j = 0; j < name_size; ++j)
            schools[i].principal[j] = 'A' + rand() % alphabet;
        schools[i].principal[name_size] = '\0';
        schools[i].staff = rand() % UCHAR_MAX;
        schools[i].students = rand() % UCHAR_MAX;
    }

    // Тестирование отдельных функций.
    /*
    update_school(&schools[0], &schools[1], STRING_MAX);
    print_schools_table(schools, schools_max);
    xchg_schools(&schools[0], &schools[1]);
    print_schools_table(schools, schools_max);
    */

    int iters = 0;

    /*
    printf("\nSort schools, key = index, using selection sort, ascending.\n");
    print_schools_table(schools, schools_max);
    iters = sort_schools(schools, schools_max, index, descending);
    printf("\nIterations %d.\n", iters);
    print_schools_table(schools, schools_max);
    */

    /*
    printf("\nSort schools, key = principal, using selection sort, descending.\n");
    print_schools_table(schools, schools_max);
    iters = sort_schools(schools, schools_max, principal, ascending);
    printf("\nIterations %d.\n", iters);
    print_schools_table(schools, schools_max);
    */

    /*
    printf("\nSort schools, key = staff, using bubble sort, ascending.\n");
    print_schools_table(schools, schools_max);
    iters = sort_schools(schools, schools_max, staff, ascending);
    printf("\nIterations %d.\n", iters);
    print_schools_table(schools, schools_max);
    */

    printf("\nSort schools, key = students, using simple quick sort, ascending.\n");
    print_schools_table(schools, schools_max);
    iters = sort_schools(schools, schools_max, students, ascending);
    printf("\nIterations %d.\n", iters);
    print_schools_table(schools, schools_max);

    return 0;           // Всё удачно, возвращаем 0.
}
