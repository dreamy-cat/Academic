#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// Дополнительная задача "Очередь" со структурами, после изучения массива.
// Реализовать абстрактную очередь со структурами, используя для размещения в памяти статичный массив байт заданного размера.
// Каждую функцию протестировать, придумав по одному тесту с учетом отказа кода и его устойчивости. Весь вывод в консоль сделать подробным в каждой функции, все параметры.
// Примерные данные и структура аналогичны стеку. Формат очереди, от большего к меньшему или наоборот - по желанию.

/*

#define QUEUE_MAX 256

unsigned char queue[QUEUE_MAX];
int queue_size;

struct queue_object {
    short code;
    char name;
};

void queue_init(void)
{
    printf("Initialization of queue, size zero and clear all data.\n");
    queue_size = 0;
    for (int i = 0; i < QUEUE_MAX; ++i)
        queue[i] = 0;
}

void queue_print(int field, int is_all)
{
    printf("Print queue, size %d.\n", queue_size);
    printf("Index:\tDH:\tDL:\tCode:\t\tName:\n");
    const int size = sizeof(struct queue_object), base = 10;
    for (int i = 0; i < queue_size * size || (is_all && i < QUEUE_MAX); i += size) {
        struct queue_object obj;
        obj.code = queue[i] + (queue[i + sizeof(char)] << CHAR_BIT);
        obj.name = queue[i + sizeof(short)];
        printf("%d\t%d\t%d\t", i, queue[i + sizeof(char)], queue[i]);
        char code[QUEUE_MAX];
        code[field] = '\0';
        for (int j = field - 1; j >= 0; --j) {    // while (field) { // or obj.code
            code[j] = '0' + obj.code % base;
            obj.code /= base;
        }
        printf("%s\t%c\n", code, obj.name);
    }
}

int queue_first(struct queue_object* object)
{
    if (!queue_size) {
        printf("Queue is empty, error reading first element.\n");
        return -1;
    }
    object->code = queue[0] + (queue[sizeof(char)] << CHAR_BIT);
    object->name = queue[sizeof(short)];
    printf("First element of queue has %d code and name '%c'.\n", object->code, object->name);
    return 0;
}

int queue_last(struct queue_object* object)
{
    if (!queue_size) {
        printf("Queue is empty, error reading last element.\n");
        return -1;
    }
    int last = queue_size - sizeof(struct queue_object);
    object->code = queue[last] + (queue[last + sizeof(char)] << CHAR_BIT);
    object->name = queue[last + sizeof(short)];
    printf("Last element of queue has %d code and name '%c'.\n", object->code, object->name);
    return 0;
}

int queue_push(struct queue_object* object)
{
    if (queue_size == QUEUE_MAX / sizeof(struct queue_object)) {
        printf("Queue is full, size %d. Can't push new element.\n", queue_size);
        return -1;
    }
    const int size = sizeof(struct queue_object);
    for (int next = (queue_size + 1) * size; next >= size; --next)
        queue[next] = queue[next - size];
    unsigned char dh = (object->code >> CHAR_BIT), dl = object->code & UCHAR_MAX;
    queue[0] = object->code & UCHAR_MAX;
    queue[sizeof(char)] = (object->code >> CHAR_BIT);
    queue[sizeof(short)] = object->name;
    queue_size++;
    printf("Push new element to start queue, code %d(DH = %d, DL = %d), name '%c' and new size is %d.\n",
           object->code, dh, dl, object->name, queue_size);
    return 0;
}

int queue_pop(struct queue_object* object)
{
    if (!queue_size) {
        printf("Queue is empty, nothing to pop.\n");
        return -1;
    }
    int last = (--queue_size) * sizeof(struct queue_object);
    object->code = queue[last] + (queue[last + sizeof(char)] << CHAR_BIT);
    object->name = queue[last + sizeof(short)];
    printf("Pop last element from queue, code %d, name '%c' and new size is %d.\n",
           object->code, object->name, queue_size);
    return 0;
}

int queue_reverse(void)
{
    if (queue_size < 2) {
        printf("Queue is empty or has less than two elements, nothing to reverse.\n");
        return -1;
    }
    printf("Reverse elements in queue.\n");
    struct queue_object obj;
    const int size = sizeof(struct queue_object);
    for (int i = 0; i < queue_size / 2; ++i) {
        int idx_a = i * size, idx_b = (queue_size - 1 - i) * size;
        obj.code = queue[idx_a] + (queue[idx_a + sizeof(char)] << CHAR_BIT);
        obj.name = queue[idx_a + sizeof(short)];
        printf("Left element, code %d, name '%c' at index data %d.\n", obj.code, obj.name, idx_a);
        obj.code = queue[idx_b] + (queue[idx_b + sizeof(char)] << CHAR_BIT);
        obj.name = queue[idx_b + sizeof(short)];
        printf("Right element, code %d, name '%c' at index data %d.\n", obj.code, obj.name, idx_b);
        for (int j = 0; j < size; ++j)
            queue[idx_b + j] = queue[idx_a + j];
        queue[idx_a] = obj.code & UCHAR_MAX;
        queue[idx_a + sizeof(char)] = obj.code >> CHAR_BIT;
        queue[idx_a + sizeof(short)] = obj.name;
    }
    return 0;
}

void queue_and_array(void)
{
    const int debug_elements = 5;
    struct queue_object obj;
    printf("Simple queue with structures.\n");
    printf("Size of structure %u, size of char %u, size of short %u, bits in char %u, uchar max %u.\n",
           sizeof(struct queue_object), sizeof(char), sizeof(short), CHAR_BIT, UCHAR_MAX);
    printf("Name:\tOffset:\t\tSize:\n");
    printf("Code:\t%p\t%u\n", NULL, sizeof(obj.code));
    printf("Name:\t%p\t%u\n\n", (void*)((void*)&obj.name - (void*)&obj), sizeof(obj.name));
    for (int i = 0; i < debug_elements; ++i) {
        obj.code = rand() % SHRT_MAX;
        obj.name = 'A' + rand() % 26;
        printf("\nAdding element to queue, code %d and name '%c'.\n", obj.code, obj.name);
        queue_push(&obj);
        queue_print(8, 0);
    }
    printf("\n");
    queue_first(&obj);
    queue_last(&obj);
    printf("\nPop elements from queue, size %d.\n\n", queue_size);
    for (int i = 0; i < debug_elements - 4; ++i) {
        printf("Pop %d element from queue tail.\n", i);
        queue_pop(&obj);
    }
    printf("\n");
    queue_print(8, 0);
    printf("\n");
    queue_reverse();
    printf("\n");
    queue_print(8, 0);
    printf("\n");
}

//


*/


/*  Дополнение к теории или практике. Простой массив с объектами разного размера и
 * размещением их в одномерном массиве, имитируя память, без использования динамической
 * памяти. Реализуются самые простые методы: инициализация(очистка), вывод со смещениями,
 * сохранение объекта на стеке, извлечение объекта со стека, получение размера и
 * свободного места в массиве.
 * */


/*

#define STACK_MAX 32

static unsigned char stack[STACK_MAX];
static unsigned int sp;

enum stack_type { stack_nop, stack_byte, stack_word, stack_dword };

static const char* stack_type_name[] = { "no type", "byte", "word", "dword" };

static const int stack_type_size[] = { 0, sizeof(char), sizeof(short), sizeof(int) };

struct stack_object {
    enum stack_type type;   // Если затруднения, то можно просто расположить объекты в массиве.
    unsigned char type_size;
};

int stack_push(struct stack_object* info, void* data)
{
    if ((info->type <= stack_nop || info->type >= stack_dword) &&
            (sp < (info->type_size + sizeof(struct stack_object)))) {
        printf("Error");
        return -1;
    }
    sp -= sizeof(struct stack_object);

*/
/*
    struct stack_object object;
    object.type = info->type, object.type_size = info->type_size;
    */

/*

    unsigned char* obj_ptr = (unsigned char*)(info), *obj_data = (unsigned char*)data;
    printf("SP_struct %d, type %d, ptr %u.\n", sp, info->type, info->type_size);
    for (unsigned int i = 0; i < sizeof(struct stack_object); ++i, ++sp, ++obj_ptr) {   // memory copy.
        stack[sp] = *obj_ptr;
        printf("info: %d\n", *obj_ptr);
    }
    sp -= (sizeof(struct stack_object) + info->type_size);
    printf("SP_info data %d.\n", sp);
    for (int i = 0, sp_data = sp; i < info->type_size; ++i, sp_data++, obj_data++) {
        stack[sp_data] = *obj_data;
        printf("Data: %d.\n", *obj_data);
    }
    return 0;
}

int stack_pop(void* data)
{

    if (sp == STACK_MAX) {

        return -1;
    }
    return 0;
}

int stack_size()
{
    return STACK_MAX - sp;
}

void stack_print()
{
    printf("All stack data, size of stack: %d.\n", stack_size());
    printf("Index:\tNext:\tType:\tData:\n");
    for (unsigned int idx = STACK_MAX, idx_next; idx > sp; ) {
        printf("%d\t", idx);
        idx -= sizeof(struct stack_object);
        struct stack_object* data = (struct stack_object*)(&(stack[idx]));
        idx_next = idx - data->type_size;
        printf("%d\t%s\t%d\n", idx_next, stack_type_name[data->type], stack[idx_next]);
        // Using function or pointer to function, to print data.
        idx = idx_next;
    }
}

void stack_init()
{
    printf("Stack initialization, clear all data and set stack pointer to %u.\n", STACK_MAX);
    sp = STACK_MAX;
    for (int i = 0; i < STACK_MAX; ++i)
        stack[i] = 0;
}

void stack_and_structures(void)
{
    printf("Simple stack with data types(bytes sizes): ");
    for (enum stack_type t = stack_nop; t <= stack_dword; ++t)
        printf("%s(%d) ", stack_type_name[t], stack_type_size[t]);
    printf("\nSize of structure 'stack_data' and offsets: %u bytes total.\n", sizeof(struct stack_object));
    struct stack_object value = { stack_byte, stack_type_size[stack_byte] };
    printf("Type: offset %lu, size %u bytes.\n", (unsigned long)(&value.type) - (unsigned long)(&value), sizeof(value.type));
    printf("Size: offset %lu, size %u bytes.\n", (unsigned long)(&value.type_size) - (unsigned long)(&value), sizeof(value.type_size));
    printf("\n");
    stack_init();

    unsigned char data[3][sizeof(int)] = { {1, 0, 0, 0}, {2, 3, 0, 0}, {4, 3, 2, 1} };  // 1
    unsigned char word[sizeof(short)] = { 2, 3 };       // 770
    unsigned char dword[sizeof(int)] = { 4, 3, 2, 1 };  // 16777216 + 131072 + 768 + 4 = 16909060
    stack_push(&value, &data);

/*
    stack_print();
    value.type = stack_word;
    value.type_size = sizeof(short);
    short int word = 1024;
    stack_push(&value, &word);
    stack_print();
  */

// }

double line_size(double x1, double y1, double x2, double y2)
{   // Вычисление длины прямой с минимальной проверкой.
    if (x1 == NAN || y1 == NAN || x2 == NAN || y2 == NAN) {
        printf("Some of point coordinates is incorrect, return NAN.\n");
        return NAN;
    }
    return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}

int reverse_value(int value)
{   // Вычисление и возврат обратного числа по цифрам.
    const int base = 10;
    int result = 0, order = 1, val = value;
    while (val > 0) {
        val /= base;
        order *= base;
    }
    while (value > 0) {
        order /= base;
        result += (value % base) * order;
        value /= base;
    }
    return result;
}

void tasks_school(void)
{   // Лабораторные для школы, возможно планировались для Паскаля.
    // 1. Даны координаты двух точек, вычислить длину отрезка между ними и с использованием функции.
    double x1 = 1.2, x2 = 3.6, y1 = 5.8, y2 = 3.4, length;
    length = line_size(x1, x2, y1, y2);
    printf("Points coordinates (%.2f, %.2f) and (%.2f, %.2f). Length of line is %.2f.\n", x1, y1, x2, y2, length);
    // 2. Ввод цифр в прямом порядке и вывод их в обратном формально без использования массива.
    printf("\nEnter integers separated by space or tab, any char for exit: ");
    int right = 80, field = 5, value;
    for (int i = 0, j; scanf("%d", &value) != 0 && i < right / field; ++i) {
        printf("\rIntegers in reverse: ");
        for (j = 0; j < right - i * field; ++j)
            printf(" ");
        printf("%5d", value);
    }
    printf("All integers was written without arrays, but with std buffers.\n");
    // 3. Вывод числа по цифрам, обратного к введенному или заданному.
    value = 12345;
    printf("\nReverse of value %d is %d.\n", value, reverse_value(value));
    // 4. Поиск комбинаций для чисел, через обычный перебор или рекурсию.
    const unsigned int txt_size = 0x100, bits_max = 10;         // Максимальное количество бит, от комбинаций.
    // Макрос для лучшей совместимости с компилятором от МС, или можно использовать константу.
#define TEXT_MAX 0x100
    char txt[TEXT_MAX];
    int limit = 14, programs = 0, is_all = 0;                   // Флаг вывода всех вариантов.
    value = 4; field = 8;
    printf("\nCalculator (0) - increase, (1) - shift left bits, start %d and limit %d.\n",
           value, limit);
    printf("All programs and result of combinations:\n");
    for (int prog_len = 1, prog = 0; prog_len <= bits_max; ++prog_len) {
        for (int i = 0, prog_val, offs; i < (0x01 << prog_len); ++i, ++prog) {
            prog_val = value;
            for (int j = 0; j < prog_len; ++j) {
                offs = j * field;
                switch ((prog >> j) & 0x01) {
                case 0:
                    sprintf_s(&txt[offs], txt_size - offs, "%03d(+1) ", prog_val);
                    prog_val++;
                    break;
                case 1:
                    sprintf_s(&txt[offs], txt_size - offs, "%03d(*2) ", prog_val);
                    prog_val *= 2;
                    break;
                default:
                    printf("Something goes wrong with bit and mask...\n");
                }
            }
            offs = prog_len * field;
            sprintf_s(&txt[offs], txt_size - offs, "= %d", prog_val);
            if (prog_val == limit) {
                programs++;
                printf("%s, yes, program is equal to limit %d;\n", txt, limit);
            } else
                if (is_all)
                    printf("%s, no, program is not equal limit %d;\n", txt, limit);
        }
    }
    printf("Total programs equal to %d is %d.\n", limit, programs);
}

void num_conver(char num_src[], char num_dst[], unsigned int from, unsigned int to)
{   // Перевод числа из одной системы счисления в другую и простой вывод.
    const unsigned int max_order = 0x19;
    const char tab_digit[] = "0123456789ABCDEFGHIJKLMNO";   // 25 max.
    if (num_src == NULL || from == 0 || from > max_order || to == 0 || to > max_order) {
        printf("Error num_src conversion, incorrect string or orders.\n");
        return;
    }
    printf("\nConversion num_src '%s' from base %u to base %u.\n", num_src, from, to);
    int len = 0, i;
    while (num_src[len] != '\0')
        len++;
    if (len == 0)
        return;
    printf("num_src as base 10, decimal: ");
    unsigned int num = 0, order = 1;
    while (--len >= 0) {
        for (i = 0; i < max_order && num_src[len] != tab_digit[i]; ++i)
            ;
        printf("%c*%u ", tab_digit[i], order);
        num += i * order;
        order *= from;
    }
    printf("- num_src is %u, order %u.\n", num, order);
    printf("num_src as base %u: ", to);
    len = 0;
    while (num > 0) {
        int digit = num % to;
        num_dst[len++] = tab_digit[digit];
        printf("'%c' ", tab_digit[digit]);
        num /= to;
    }
    num_dst[len] = '\0';
    for (i = 0; i < len / 2; ++i) {
        char d = num_dst[i];
        num_dst[i] = num_dst[len - i - 1];
        num_dst[len - i - 1] = d;
    }
    printf("Result of base %u: '%s'.\n", to, num_dst);
}

void labs_15(void)
{   // Дополнительные задания или просто код вызова.
    printf("Extra tasks, some theory or small code review.\n\n");
    // tasks_school();
#define TXT_MAX 0x100
    char dst[TXT_MAX];
    char n0[] = "FFFF";
    num_conver(n0, dst, 16, 2);
    //
    char n1[] = "345";
    for (int i = 6; i <= 9; ++i)
        num_conver(n1, dst, i, 10);
    //
    char n2[] = "194";
    num_conver(n2, dst, 10, 3);
    num_conver(n2, dst, 10, 6);
    //
    num_conver("1230", dst, 7, 10);
    num_conver("124", dst, 7, 10);
    num_conver("600", dst, 7, 10);
    num_conver("530", dst, 7, 10);
}
