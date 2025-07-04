#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>


/*  Лабораторная №4. Наш вариант полинома, выданный вариант в исходнике C++.
 * Реализовать объект полинома с одной переменной, функции работы с ним и динамической памятью.
 * Список и описание функций приведены ниже. Все функции сделать максимально надежными и подробным выводом в консоль.
 * Ограничения для полинома 8-бит для элементов, условное ограничение по памяти до 15 бит, знак - флаг переполнения.
 * Полином классический, коэффициенты целые числа со знаком, степени безнаковые целые.
 * Обработать флаг переполнения или неверного значения, если это возможно.
 * Использовать динамическую память. В случае отказа, просто выйти с exit(-1).
 * Компиляция и запуск GCC, MSVS, x86-64, ограничения в условные 16 бит.
*/

// Ограничение на глобальный размер данных включая текст, необязятельно, но для учебного примера.
#define MEM_MAX 0x0400
#define DATA_MAX 0x100
// Параметры виртуального экрана для вывода.
#define SCR_WIDTH 0x40
#define SCR_HEIGHT 0x20

// Данные статичны, явное обзначение используется на случай если код будет частью другого.
static char screen[SCR_HEIGHT][SCR_WIDTH];                             // Виртуальный экран для вывода в консоль.
static const unsigned char pencil_colors = 5;                          // Общее количество "цветов" карандаша.
static const char pencil[] = { 32, 176, 177, 178, 219 };               // Коды ASCII для рисования по возрастанию.

// Вспомогательное перечисление для всех частей полинома и операции сравнения.
enum flags : unsigned short {   // ': unsigned short' можно отключить для древних компиляторов и автоматически int.
    flag_ok, ply_nop = 0x0000, err_incorrect = 0x0001, err_memory = 0x0002, err_convert = 0x0003,
    err_range = 0x0004, err_compare = 0x0005,
    ply_constant = 0x0008, ply_exponent = 0x0010, ply_equal = 0x0020,
    ply_less = 0x0040, ply_more = 0x0080, ply_full = 0x0100, ply_max = 0x0200, ply_min = 0x0400,
    ply_random = 0x8000, ply_compact = 0x1000,  ply_debug = 0x2000
};

// Статичные константы для всей программы.
static const char* ply_flags_text[] = {                    // Текстовое описание всех флагов.
    "No error.", "Incorrect parameters.", "Not enough memory.", "Indexes is out of range", "Convert failed."
};
// Размеры данных для одного элемента полинома, размещенного в динамической памяти.
static const unsigned char element_size = sizeof(char) + sizeof(unsigned char);
static const unsigned char rnd_consts_max = 5;                  // Максимальные значения случайной генерации.
static const unsigned char rnd_exps_max = 3;
static const double epsilon = 0.01;                             // Заданная точность или приближение, окрестность точки.

// static const unsigned char max_degree =  3; // del
// static const unsigned char rnd_consts_max = 10, rnd_exps_max = max_degree + 1;  // value

// Статичные, глобальные данные доступные для всех функций.
static unsigned short memory = MEM_MAX;
static char element_fmt[] = "[%C%%%E]";                     // Формат элемента при преобразовании по умолчанию.

struct polynomial {                                         // Структура полинома с одной переменной.
    unsigned char size;                                     // Количество элементов в полиноме.
    char* constants;                                        // Динамический массив констант, целые числа со знаком.
    unsigned char* exponents;                               // Динамический массив степеней, целые числа без знака.
};

// Объявление и краткое описание всех функций в алфавитном порядке, подробнее в реализации.
enum flags is_correct(struct polynomial* obj);              // Проверка полинома на корректность.
void clear_screen(char c, short is_debug);                  // Очистка виртуального экрана.
void print_screen();                                        // Вывод виртуального экрана.
enum flags create(struct polynomial* obj, unsigned char size, char* consts, unsigned char* exps, enum flags is_rand);
char* get_constants(struct polynomial* obj, unsigned char index);
enum flags print(struct polynomial* obj, unsigned char endl);
unsigned char size(struct polynomial* obj);
unsigned short to_hw(void* addr);                           // Вспомогательная функция для вывода адресов.
enum flags to_monic(struct polynomial* obj, enum flags type);

// Все функции программы в одном файле, дополнительных файлов/имен не требуется.
void clear_screen(char c, short is_debug)
{   // Функция очистки буфера виртуального экрана заданным символом. Циклами или через адрес по вкусу.
    // Если флаг отладки, то заполнить буфер всеми "цветами", кроме 0-го. Можно по классике, прямоугольниками.
    if (is_debug)
        for (unsigned short i = 0, k = 1; i < SCR_HEIGHT; ++i)
            for (unsigned short j = 0; j < SCR_WIDTH; ++j)
                screen[i][j] = pencil[k + j / ((SCR_WIDTH / (pencil_colors - 1)))];
    else
        for (unsigned short i = 0; i < SCR_HEIGHT; ++i)
            for (unsigned short j = 0; j < SCR_WIDTH; ++j)
                screen[i][j] = c;
}

enum flags create(struct polynomial* obj, unsigned char obj_size, char* consts, unsigned char* exps, enum flags is_rand)
{   // Создание полинома, размер должен быть больше нуля и исходные данные должны существовать или флаг случайных.
    if ((obj == NULL || obj_size == 0) || (!(is_rand & ply_random) && (consts == NULL || exps == NULL)) ||
        (is_correct(obj) != flag_ok) || size(obj) != 0) {
        printf("Error create polynomial [%X], object address, address of constants or exponents are NULL "
               "or size is 0.\n", to_hw(obj));
        return err_incorrect;
    }
    if (memory < obj_size * element_size) {
        printf("Error create polynomial, not enough memory %hu bytes free, needs %hu.\n",
               memory, (unsigned short)(obj_size * element_size));
        return err_memory;
    }
    printf("Create polynomial size %hhu, random flag is %hhd, sources of constants at [%X] and "    // ![X]
           "exponents at [%X].\n", obj_size, is_rand, to_hw(consts), to_hw(exps));
    obj->constants = calloc(obj_size, sizeof(char));
    obj->exponents = calloc(obj_size, sizeof(unsigned char));
    if (obj->constants == NULL || obj->exponents == NULL) {
        printf("Error dynamic memory allocation, exit(-1).\n");
        exit(-1);
    }
    /* Копирование элементов можно всё сразу применяя копирование памяти.
    unsigned int data_obj_size = src_obj_size * element_obj_size;
    memcpy_s((void*)dst->constants, data_obj_size, (void*)src->constants, data_obj_size);
    memcpy_s((void*)dst->exponents, data_obj_size, (void*)src->exponents, data_obj_size);
    */
    for (unsigned char i = 0; i < obj_size; ++i) {
        if (!(is_rand & ply_random)) {                     // ! flag
            obj->constants[i] = consts[i];                  // Выделение памяти под все элементы.
            obj->exponents[i] = exps[i];
        } else {
            obj->constants[i] = rand() % rnd_consts_max;
            obj->constants[i] = rand() % rnd_exps_max;
        }
    }
    obj->size = obj_size;                                   // И сохраняем новый размер полинома.
    memory -= obj_size * element_size;
    printf("Polynomial created, memory check %hu free bytes.\n", memory);
    return flag_ok;
}

enum flags destroy(struct polynomial* obj)  // flags
{   // Уничтожение объекта полинома и освобождение динамической памяти его данных.
    if (is_correct(obj) != flag_ok || obj->size == 0) {       // Проверка на допустимость.
        printf("Errror destroy, polynomial [%X] is incorrect or empty.\n", to_hw(obj)); // ! fix comment
        return err_incorrect;
    }
    printf("Destroy polynomial at [%X], size %u and free %hu bytes of dynamic memory.\n",    // ! fix comment
           to_hw(obj), obj->size, obj->size * element_size);
    memory += obj->size * element_size;
    free(obj->constants);                                   // Освобождение памяти и обнуление размера.
    free(obj->exponents);
    obj->constants = NULL;
    obj->exponents = NULL;                                  // Обнуляем параметры структуры полинома.
    obj->size = 0;
    return flag_ok;
}

void print_screen()
{   // Функция вывода буфера в консоль. Переход на следующую строку после экрана. Можно выводить поэлементно, но медленнее.
    /*
    for (unsigned short i = 0; i < SCR_HEIGHT; ++i)         // Быстрый вывод через форматированную строку.
        printf("%.128s\n", screen[i]);                      // Небольшое неудобство, подставить размеры по горизонтали.
        */
    for (unsigned short i = 0, j; i < SCR_HEIGHT; ++i) {    // Более медленный способ, но универсальный.
        for (j = 0; j < SCR_WIDTH; ++j)
            printf("%c", screen[i][j]);
        printf("\n");
    }
}

enum flags is_correct(struct polynomial* obj)   // Проверка на корректность ОК.
{   // Проверка полинома на корректность, размер и адреса должны сходится.
    if (obj != NULL) {
        if ((obj->size == 0 && (obj->constants != NULL || obj->exponents != NULL)) ||
            (obj->size > 0 && (obj->constants == NULL || obj->exponents == NULL)))
            return err_incorrect;
        else
            return flag_ok;
    } else
        return err_incorrect;
}

unsigned char size(struct polynomial* obj)
{   // Возвращение размера полинома в элементах.
    if (is_correct(obj) != flag_ok) {                       // Без дополнительной проверки адресов данных.
        printf("Size error, polynomial [%X] is incorrect.\n");
        return 0;                                           // Проверка только на адреса объекта полинома.
    } else
        return obj->size;                                   // Возвращаем общее количество элементов.
}

char* get_constants(struct polynomial* obj, unsigned char index)
{   // Получение адреса константы полинома начиная от индекса, вывод только если ошибка.
    if (is_correct(obj) != flag_ok || index >= size(obj)) {
        printf("Error get constants, polynomial [%X] incorrect, empty or wrong index.\n");
        return NULL;                                        // Проверка на допустимость.
    }
    return &(obj->constants[index]);
}

unsigned char* get_exponents(struct polynomial* obj, unsigned char index)
{   // Получение адреса экспоненты полинома, начиная от индекса, вывод только если ошибка.
    if (is_correct(obj) != flag_ok || index >= size(obj)) {
        printf("Error get exponents, polynomial incorrect, empty or index is more than size.\n");
        return NULL;
    }
    return &(obj->exponents[index]);
}

enum flags copy(struct polynomial* dst, struct polynomial* src)
{   // Копирование полинома с полным копированием всех компонентов и выделением динамической памяти в новом назначении.
    if (is_correct(dst) != flag_ok || is_correct(src) != flag_ok ||
        size(src) == 0 || size(dst) != 0 || dst == src) {
        printf("Copy error, source [%X] or destination [%X] polynomials are incorrect. "
               "Or source size %hhu is empty or destination size %hhu is already exist. Or addresses are qual.\n",
               to_hw(src), to_hw(dst), size(src), size(dst));
        return err_incorrect;                                   // Проверка на допустимость и смысл исполнения.
    }
    enum flags r = create(dst, size(src), get_constants(src, 0), get_exponents(src, 0), 0);   // ! to flags
    if (r == flag_ok)
        printf("Copy polynomial succefull from [%X] to [%X], elements %hhu, memory check %hu bytes.\n",
               to_hw(src), to_hw(dst), size(src), memory);                          // ! recheck
    else
        printf("Copy polynomial error, can't create copy, memory check %hu.\n", memory);
    return r;
}

enum flags move(struct polynomial** dst, struct polynomial** src)
{   // Перемещение полинома, без копирования элементов. Объект назначения должен быть пустым, а источник с элементами.
    if (src == NULL || dst == NULL) {                                               // ! divide one to 2 if-s
        printf("Error move, adresses of polynomials [%X] or [%X] are NULL and can't read.\n", to_hw(src), to_hw(dst));
        return err_incorrect;
    }
    if (is_correct(*src) != flag_ok || is_correct(*dst) != flag_ok ||
        *src == *dst || size(*src) == 0 || size(*dst) != 0) {
        printf("Error move, source(empty), destination(not empty) incorrect or equal.\n");
        return err_incorrect;
    }
    unsigned char src_size = size(*src);
    printf("Move polynomial from source at [%X] size %hhu to destination at [%X].\n",
           to_hw(*src), src_size, to_hw(*dst));
    printf("Move from addresses constants [%X] to [%X], exponents [%X] to [%X], memory %hu.\n",
           to_hw((*src)->constants), to_hw((*dst)->constants),              // ! Use just pointer.
           to_hw((*src)->exponents), to_hw((*dst)->exponents), memory);
    // (*dst) = (*src);
    (*dst)->size = size(*src);                                  // Или через копирование структуры полностью.
    (*dst)->constants = (*src)->constants;
    (*dst)->exponents = (*src)->exponents;
    (*src)->size = 0;
    (*src)->constants = NULL;
    (*src)->exponents = NULL;
    return flag_ok;
}

enum flags resize(struct polynomial* obj, unsigned char new_size)
{   // Изменение размера полинома, для нового размера. При расширении, новые элементы равняются нулю.
    if (is_correct(obj) != flag_ok || new_size == 0) {      // fix print
        printf("Error resize, polynomial [%X] incorrect or new size is 0, call destroy instead.\n", to_hw(obj));
        return err_incorrect;
    }
    unsigned char obj_size = size(obj);
    if (new_size != obj_size) {                            // Если размеры не совпадают.
        printf("Resize elements %hhu is not equal %hhu elements in polynomial at [%X], allocate new memory.\n",
               new_size, obj_size, to_hw(obj));                // ! fix comment
        char* consts = get_constants(obj, 0);
        unsigned char* exps = get_exponents(obj, 0);
        obj->constants = (char*)realloc(consts, new_size * sizeof(char));
        obj->exponents = (unsigned char*)realloc(exps, new_size * sizeof(unsigned char));
        if (obj->constants == NULL || obj->exponents == NULL) {     // ! just exit.
            printf("Error in heap, new constants or exponents is NULL, exit(-1).\n");
            exit(-1);
        }                                                   // Или можно использовать простой цикл, верно.
        if (obj_size < new_size) {
            memset(obj->constants + obj_size, 0, (new_size - obj_size) * sizeof(char));
            memset(obj->exponents + obj_size, 0, (new_size - obj_size) * sizeof(unsigned char));
        }
        obj->size = new_size;                               // ! Спустить ниже, стиль.
        memory -= (new_size - obj_size) * element_size;
    } else                                                  // Если количество элементов в полиноме как есть.
        printf("Resize elements %hhu is equal to elements %hhu in polynomial.\n", new_size, obj_size);
    return flag_ok;
}

unsigned char compact(struct polynomial* obj)
{   // Удаление незначимых элементов полинома(коэффициент равняется нулю), уплотнение памяти и возврат нового размера.
    if (is_correct(obj) != flag_ok || size(obj) == 0) {
        printf("Error compact, object [%X] incorrect or polynomial is empty.\n", to_hw(obj));
        return 0;
    }
    unsigned char obj_size = size(obj), compact_size = 0;  // Текушие параметры объекта.
    char* consts = get_constants(obj, 0);
    unsigned char* exps = get_exponents(obj, 0);                // ! fix all with indexes remove IF
    printf("\nCompact zeroes constants, size %hhu index elements to delete: ",
           (unsigned char)(obj_size - compact_size));
    for (unsigned char i = 0, j; i < obj_size - compact_size; ) {
        if (consts[i] == 0) {                               // Уплотнение 0-ых констант.
            printf("[%hhu] ", (unsigned char)(i + compact_size));
            for (j = i; j < obj_size - 1; ++j) {
                consts[j] = consts[j + 1];
                exps[j] = exps[j + 1];
            }
            compact_size++;
        } else
            ++i;
    }
    printf("\nSize after compact is %hhu.\n", (unsigned char)(obj_size - compact_size));
    if (compact_size > 0) {                                 // Изменение размеров в памяти.
        if (obj_size - compact_size > 0) {
            resize(obj, obj_size - compact_size);
        } else {
            destroy(obj);
            return 0;                                       // Объекта не существует или нуль.
        }                                                   // Дополнение блока.
    }
    return size(obj);                                       // Оставшийся актуальный размер.
}

enum flags set_constants(struct polynomial* obj, char* src, unsigned char consts_size, unsigned char index)
{   // Установка констант в полином. Стартовый индекс в объекте и количество элементов из исходного массива.
    // Вход: объект, массив констант с размером и первый индекс. Выход: код ошибки.
    if (is_correct(obj) != flag_ok || src == NULL || consts_size == 0) {        // FIX print
        printf("Error set constants, polynomial [%X] or size incorrect. Address may be NULL.\n", to_hw(obj));
        return err_incorrect;
    }
    unsigned char obj_size = size(obj);                                // FIX optimization.
    if (index + consts_size > obj_size) {
        printf("Error set constants, polynomial [%X] index %hhu plus size %hhu is out of range.\n",
               to_hw(obj), index, obj_size);
        return err_range;
    }                                   // FIX print.
    printf("Set constants in polynomial [%X] from source [%X] and size %hhu at index %hhu: ",
           to_hw(obj), to_hw(src), consts_size, index);
    for (unsigned short i = 0; i < consts_size; ++i) {           // Или использовать копирование памяти.
        obj->constants[index + i] = src[i];
        printf("%hhd[%hhu] ", src[i], (unsigned char)(index + i));
    }
    printf("\n");
    return flag_ok;
}

enum flags set_exponents(struct polynomial* obj, unsigned char* src, unsigned char exps_size, unsigned char index)
{   // Установка экспонент в полином. Стартовый индекс и количество элементов в неё из исходного массива.
    // Вход: объект, массив экспонент и его размер, стартовый индекс изменения. Выход: код ошибки.
    if (is_correct(obj) != flag_ok || src == NULL || exps_size == 0) {  // ! FIX if in two
        printf("Error set exponents, polynomial or size incorrect. Address may be NULL.\n");
        return err_incorrect;
    }
    unsigned char obj_size = size(obj);
    if (index + exps_size > size(obj)) {
        printf("Error set exponents, polynomial [%X] index %hhu plus size %hhu is out of range.\n",
               to_hw(obj), index, obj_size);
        return err_range;
    }
    printf("Set exponents in polynomial [%X] from source [%X] and size %hhu at index %hhu: ",
           to_hw(obj), to_hw(src), exps_size, index);
    for (unsigned char i = 0; i < exps_size; ++i) {         // Установка экспонент в полиноме.
        obj->exponents[index + i] = src[i];
        printf("%hhu[%hhu] ", src[i], index + i);
    }
    printf("\n");
    return flag_ok;
}

enum flags print(struct polynomial* obj, unsigned char endl)
{   // Полный вывод полинома в виде: "3*X^2 - 5*X^7". Дополнительный параметр количество перевода строк после вывода.
    if (is_correct(obj) != flag_ok) {                 // Минимальная проверка.
        printf("Error print, polynomial [%X] is incorrect, rechek all parameters.\n", to_hw(obj));
        return err_incorrect;
    }
    unsigned char elements = size(obj);                     // Символичная оптимизация.
    printf("Polynomial at [%X], size %hhu: ", to_hw(obj), elements);    // FIX print
    if (elements > 0) {
        char* consts_ptr = get_constants(obj, 0);
        unsigned char* exps_ptr = get_exponents(obj, 0);
        for (unsigned char idx = 0; idx < elements; ++idx)  // Формат вывода как есть, преобразование отдельно.
            printf("%+hhd*(X)^%hhu ", consts_ptr[idx], exps_ptr[idx]);
    } else
        printf("is empty.");
    while (endl--)
        printf("\n");
    return flag_ok;
}

enum flags to_string(struct polynomial* obj, char* dst)
{   // Преобразование полинома в строку, формат элемента по умолчанию в статичной переменной.
    // Корректность длины строки на стороне вызова, максимальная длина по памяти. Можно через sprintf, sprintf_s.
    if (is_correct(obj) != flag_ok || dst == NULL) {         // Строка назначение должна существовать.
        printf("Error to string, polynomial [%X] incorrect or destination string is null.\n", to_hw(obj));
        return err_incorrect;                         // FIX print
    }
    unsigned char poly_size = size(obj);                    // Параметры исходного объекта.
    char *consts = get_constants(obj, 0);
    unsigned char *exps = get_exponents(obj, 0);
    unsigned short len = 0;                                 // Итоговая длина строки.
    for (short i = 0, j, k; i < poly_size; ++i) {               // !FIX to short.
        for (j = 0, k = 1; element_fmt[j] != '\0'; ++j, k = 1) {
            if (element_fmt[j] == '%' && element_fmt[j + 1] != '\0') {
                switch (element_fmt[j + 1]) {               // Анализируем формат и параметры.
                case 'c':
                case 'C':                                   // Константа со знаком.
                    k = sprintf_s(&dst[len], DATA_MAX - len, "%+hhd", consts[i]);
                    ++j;
                    break;
                case 'e':
                case 'E':                                   // Степень без знака.
                    k = sprintf_s(&dst[len], DATA_MAX - len, "%hhu", exps[i]);
                    ++j;
                    break;
                case '%':                                   // Управляющий символ.
                    dst[len] = '%';
                    ++j;
                    break;
                default:
                    printf("Error to string, format element incorrect after '%%' is '%c'.\n", element_fmt[j + 1]);
                    return err_convert;
                }
            } else
                dst[len] = element_fmt[j];                  // Остальные элементы как есть.
            if (k == -1) {                                  // !FIX Опасное сравнение, но должно сработать.
                printf("Error to string, while converting parameters with 'sprintf'.\n");
                return err_convert;
            }
            len += k;
        }
        if (i < poly_size - 1)
            dst[len++] = ' ';
        else
            dst[len] = '\0';
    }
    printf("Converting polynomial [%X] to string buffer, total size %hd bytes.\n", to_hw(obj), len);
    return flag_ok;
}

enum flags from_string(struct polynomial* obj, char* src)
{   // Преобразование строки в полином, формат элемента по умолчанию в статичной переменной.
    // Корректность строки на стороне вызова, максимальная длина по памяти, лишние символы пропускать.
    if (is_correct(obj) || src == NULL || size(obj) > 0) {
        printf("Error from sting, polynomial [%X] or string is NULL, or polynomial not empty\n", to_hw(obj));
        return err_incorrect;
    }
    unsigned char poly_size = 0;
    printf("\nConverting from string '%s' to polynomial, element format '%s':\n", src, element_fmt);
    char consts[DATA_MAX];
    unsigned char exps[DATA_MAX];
    for (unsigned short i = 0, j, k, is_elem; src[i] != '\0' && i < DATA_MAX; ) {
        for (j = 0, is_elem = 1; is_elem && element_fmt[j] != '\0' && src[i] != '\0' && i < DATA_MAX; ++j, ++i) {
            if (element_fmt[j] == '%') {
                if (toupper(element_fmt[j + 1]) == 'C' || toupper(element_fmt[j + 1] == 'E')) {
                    char num_txt[DATA_MAX];
                    k = 0; num_txt[k] = '\0';
                    if (src[i] == '-' || src[i] == '+')
                        num_txt[k++] = src[i];
                    while (i + k < DATA_MAX && src[i + k] >= '0' && src[i + k] <= '9') {
                        num_txt[k] = src[i + k];
                        k++;
                    }
                    if (((num_txt[0] == '-' || num_txt[0] == '+') && k > 1) ||
                        ((num_txt[0] != '-' && num_txt[0] != '+' && k > 0))) {
                        num_txt[k] = '\0';
                        short num = (short)atoi(num_txt);
                        printf("'%s' at %hd position, short is %hd, ", num_txt, i, num);
                        ++j;
                        if (toupper(element_fmt[j]) == 'C') {
                            consts[poly_size] = (char)num;
                            printf("constant char %hhd;\n", consts[poly_size]);
                        }
                        if (toupper(element_fmt[j]) == 'E') {
                            exps[poly_size] = (unsigned char)num;
                            printf("exponent unsigned char %hhd;\n", exps[poly_size]);
                        }
                    } else
                        printf("'%s' at %hd, number incorrect, text len %hd;\n", num_txt, i, k);
                    i += (k - 1);   // +1 in for.
                } else if (element_fmt[j + 1] == '%' && (j + 1) != '\0') {
                    // printf("CHK: %c, %c\n", element_fmt[j + 1], src[i]);
                    ++j;
                } else {
                    printf("From string erorr, something wrong in element format.\n");
                    return err_convert;
                }
            } else if (element_fmt[j] != src[i]) {
                is_elem = 0;
                printf("First not equal chars are '%c' and '%c' in format;\n", src[i], element_fmt[j]);
            }
        }
        if (is_elem)
            printf("Element is founded, index %hd, polynomial size is %hhu.\n", i, ++poly_size);
    }
    create(obj, poly_size, consts, exps, 0);
    return flag_ok;
}

enum flags inc_dec_offset(struct polynomial* obj, unsigned char index, unsigned char count,
                          short offs, enum flags parts)
{   // Увеличение или уменьшение константы и/или экспоненты полинома по индексу и счётчику на смещение.
    if (is_correct(obj) != flag_ok || !((parts & ply_constant) || (parts & ply_exponent))) {
        printf("Inc/dec error, polynomial [%X] incorrect or flags not set.\n", to_hw(obj));
        return err_incorrect;
    }
    if (index + count > size(obj)) {
        printf("Inc/dec error, polynomial [%X] index %hhu and counter %hhu out of range.\n",
               to_hw(obj), index, count);
        return err_range;
    }
    printf("Offset %hd for polynomial [%X] from index %hhu, counter %hhu, flags %X in hex.\n",
           offs, to_hw(obj), index, count, parts);
    while (count--) {
        if ((parts & ply_constant) != 0) {
            char *consts = get_constants(obj, index);

            if ((short)(*consts) + offs > CHAR_MAX || (short)(*consts) + offs < CHAR_MIN)
                printf("Inc/dec warning, constant %hhd has overflow %hd.\n",
                       *consts, (short)(*consts) + offs);
            (*consts) = (char)((short)(*consts) + offs);
        }
        if ((parts & ply_exponent) != 0) {
            unsigned char* exps = get_exponents(obj, index);
            if ((short)(*exps) + offs > UCHAR_MAX || (short)(*exps) + offs < 0)
                printf("Inc/dec warning, exponent %hhd has overflow %hd.\n",
                       *exps, (short)(*exps) + offs);
            (*exps) = (unsigned char)((short)(*exps) + offs);
        }
        index++;
    }
    return flag_ok;
}

unsigned char degree(struct polynomial* obj, enum flags type)
{   // Возвращаем условную степень полинома по типу заданному флагом, если флагов много, то первый.
    // Вычисляется полная степень полинома без учета кратности корней, как есть.
    if (is_correct(obj) != flag_ok || size(obj) == 0 ||
        !((type & ply_min) || (type & ply_max) || (type & ply_full))) {  // FIX print
        printf("Degree erorr, polynomial [%X] incorrect, empty or flags not set.\n", to_hw(obj));
        return err_incorrect;
    }
    printf("Degree of polynomial [%X], flags %X in hex.\n", to_hw(obj), type);
    unsigned char poly_size = size(obj);
    unsigned char deg_min = UCHAR_MAX, deg_max = 0, deg_full = 0;
    for (unsigned char i = 0; i < poly_size; ++i) {
        unsigned char* exp = get_exponents(obj, i);
        if (*exp < deg_min)
            deg_min = *exp;
        if (*exp > deg_max)
            deg_max = *exp;
        if (((short)deg_full + (short)*exp) > UCHAR_MAX)
            printf("Warning, full degree has 8-bit type overflow.\n");
        deg_full += *exp;
    }
    if ((type & ply_min) != 0)
        return deg_min;
    else if ((type & ply_max) != 0)
        return deg_max;
    else
        return deg_full;
}

enum flags addition(struct polynomial* left, struct polynomial* right, enum flags monic)
{   // Сложение полиномов, правосторонний прибавляется к левостороннему, нули автоматически удаляются.
    // Допустимо сложение одного и того же объекта, дополнительный флаг - приведение к каноническому виду.
    if (is_correct(left) != flag_ok || is_correct(right) != flag_ok) {
        printf("Error addition, left [%X] or right [%X] polynomials are incorrect.\n", to_hw(left), to_hw(right));
        return err_incorrect;
    }
    printf("Add left [%X] and right [%X] polynomials flags %X in hex:\n", to_hw(left), to_hw(right), monic);
    print(left, 1);
    print(right, 1);
    unsigned char l_size = size(left), r_size = size(right);
    if ((short)l_size + (short)r_size > UCHAR_MAX) {
        printf("Error addition, sizes left %hhu and right %hhu polynomials is out of range.\n", l_size, r_size);
        return err_range;
    }
    if (r_size == 0) {
        printf("Right polynomial is empty, nothing to add to left, flags ignored.\n");
        return flag_ok;
    }
    if (l_size == 0) {
        printf("Left polynomial is empty, just move right to left using 'move' function.\n");
        return move(&left, &right);
    }
    resize(left, l_size + r_size);
    char *r_consts = get_constants(right, 0);
    unsigned char *r_exps = get_exponents(right, 0);
    set_constants(left, r_consts, r_size, l_size);
    set_exponents(left, r_exps, r_size, l_size);
    printf("\n"); print(left, 2);
    to_monic(left, monic);
    return flag_ok;
}

enum flags subtraction(struct polynomial* left, struct polynomial* right, enum flags monic)
{   // Вычитание полинома и сохранение результата в левосторонний объект, с дополнительными флагами.
    // Допустимо вычитание одного и того же объекта.
    if (is_correct(left) != flag_ok || is_correct(right)) {
        printf("Error subtraction, left [%X] or right [%X] polynomial is incorrect.\n", to_hw(left), to_hw(right));
        return err_incorrect;
    }
    if (left == right) {
        printf("Sub polynomials left [%X] and right [%X] are the same, destroy left object.\n",
               to_hw(left), to_hw(right));
        return destroy(left);
    }
    unsigned char r_size = size(right);
    if (r_size == 0) {
        printf("Right polynomial is empty, nothing to sub from left.\n");
        return flag_ok;
    }   // Под вопросом умножение.
    struct polynomial neg_right = { .size = 0, .constants = NULL, .exponents = NULL };
    copy(&neg_right, right);
    for (unsigned char i = 0; i < r_size; ++i)
        *(get_constants(&neg_right, i)) *= -1;
    printf("Subtraction left [%X] and right [%X] polynomials using neg [%X]:\n",
           to_hw(left), to_hw(right), to_hw(&neg_right));
    print(left, 1);
    print(&neg_right, 1);
    enum flags rf = addition(left, right, monic);
    return rf;
}

enum flags multiply(struct polynomial* left, struct polynomial* right)
{   // Умножение или делеение полиномов и сохранение результата в левосторонний объект или самого на себя.
    if (is_correct(left) != flag_ok || is_correct(right) != flag_ok) {
        printf("Error mulyiply, left [%X] or right [%X] polynomials incorrect.\n", to_hw(left), to_hw(right));
        return err_incorrect;
    }
    printf("Multiply polynomials left and right copy in monic:\n");
    struct polynomial right_m = { .size = 0, .constants = NULL, .exponents = NULL };
    struct polynomial left_m = { .size = 0, .constants = NULL, .exponents = NULL };
    copy(&left_m, left);
    copy(&right_m, right);                                  // Вызвать, преобразование.
    print(&left_m, 1);
    print(&right_m, 1);
    unsigned char l_size = size(&left_m), r_size = size(&right_m);
    if ((short)l_size * (short)r_size > UCHAR_MAX) {
        printf("Error multiply, size of result polynomial %hu is out or range.\n", (short)l_size * (short)r_size);
        return err_range;
    }
    if (l_size > 0 && r_size > 0) {
        printf("Both polynomials has elements, multiply all elements to new size %hu.\n", l_size * r_size);
        struct polynomial result = { .size = 0, .constants = NULL, .exponents = NULL }, *res_ptr = &result;
        enum flags rf = create(&result, l_size * r_size, NULL, NULL, ply_random);
        if (rf != flag_ok) {
            printf("Error multiply, can't create result object.\n");
            return rf;
        }
        char *l_consts = get_constants(&left_m, 0), *r_consts = get_constants(&right_m, 0), res_const;
        unsigned char* l_exps = get_exponents(&left_m, 0), *r_exps = get_exponents(&right_m, 0), res_exp;
        printf("Result polynomial: ");
        for (unsigned char i = 0, j, k = 0; i < l_size; ++i) {
            for (j = 0; j < r_size; ++j, k++) {
                if (((short)l_consts[i] * (short)r_consts[j] > CHAR_MAX) ||
                    ((short)l_consts[i] * (short)r_consts[j] < CHAR_MIN))
                    printf("Warning, constants at [%hhu] and [%hhu] is out of range.\n", i, j);
                res_const = l_consts[i] * r_consts[j];
                if ((short)l_exps[i] + (short)r_exps[j] > UCHAR_MAX)
                    printf("Warning, exponents at [%hhu] and [%hhu] is out of range.\n", i, j);
                res_exp = l_exps[i] + r_exps[j];
                set_constants(&result, &res_const, 1, k);
                set_exponents(&result, &res_exp, 1, k);
            }
        }
        print(&result, 2);
        destroy(left);
        move(&left, &res_ptr);
    } else {
        printf("Warning multiply, left %hhu or right %hhu sizes is zero, return empty.\n", l_size, r_size);
        destroy(left);
    }
    destroy(&left_m);
    destroy(&right_m);
    return flag_ok;

    // Вариант Дани, второй, мысль верная, но оставим промежуточный вариат с комментарием.

    /*
     Я предлагаю вариант решения через вспомогательный полином, с сильным ограничением по размеру исходных полиномов
    left_size * right_size и в конце вызываю один раз to_monic, add_polynomial я убрал.
    Есть второй вариант решения где не будет такого сильного ограничения по размерам, но там придётся мудрить.
    В нём to_monic буду вызывать после кажного вложенного цикла for (j = 0; j < left_size; ++j, ++left_mul_counter)
    */

    /*
    if (is_correct_polynomial(left) != flag_ok || is_correct_polynomial(right) != flag_ok) {
        printf("error mul: polynomials left [%X] or right [%X] is incorrect;\n", to_hw(left), to_hw(right));
        return err_incorrect;       // Верно!
    }
    printf("\nMultiplication left[%X] and right[%X] same polynomials;\n", to_hw(left), to_hw(right));
    unsigned char left_size = size_polynomial(left);            // Размеры можно после оптимизации.
    unsigned char right_size = size_polynomial(right);
    if (right_size == 0) {              // Не только правый.
        printf("Mul polynomials right [%X] is empty, destroy left polynomial;\n", to_hw(right));
        return destroy_polynomial(left);
    }
    if ((short)left_size * (short)right_size > UCHAR_MAX) { // Верно и сразу на выход.
        printf("error mul: sizes left %hhu and right %hhu is out of range;\n", left_size, right_size);
        return err_range;
    }
    struct polynomial left_mul = {.size = 0};           // Что если умножение само на себя, нет инициализации адресов.
    struct polynomial* ptr_mul = &left_mul;
    unsigned char i, j, left_mul_counter = 0;           // Длинное название переменной.
    char *right_consts = get_constants(right, 0);
    unsigned char *right_exps = get_exponents(right, 0);
    char *left_consts = get_constants(left, 0);
    unsigned char *left_exps = get_exponents(left, 0);      // Random или две функции.
    if (create_polynomial(&left_mul, left_size * right_size, NULL, NULL, ply_rand) != flag_ok) {
        printf("error mul: error creating temporary polynomial;\n");
        return err_memory;
    }
    for (i = 0, left_mul_counter = 0; i < right_size; ++i)      // Перезапись.
        for (j = 0; j < left_size; ++j, ++left_mul_counter) {
            left_mul.constants[left_mul_counter] = left_consts[j] * right_consts[i];
            left_mul.exponents[left_mul_counter] = left_exps [j] + right_exps[i];
        }
    print_polynomial(&left_mul, 1);
    to_monic(&left_mul, ply_more);
    destroy_polynomial(left);                   // Move внимтельней с данными статичного или внешнего объекта.
    move_polynomial(&left, &ptr_mul);
    return flag_ok;
}
*/
}

enum flags divide(struct polynomial* left, struct polynomial* right, struct polynomial* remain)
{   // Деление полиномов и сохранение результата в левосторонний объект, столбиком и/или с остатком.
    if (is_correct(left) != flag_ok || is_correct(right) != flag_ok || is_correct(remain) != flag_ok) {
        printf("Error mulyiply, left [%X] or right [%X] polynomials incorrect or right is empty(divide by zero).\n",
               to_hw(left), to_hw(right), size(right));
        return err_incorrect;
    }
    unsigned char l_size = size(left), r_size = size(right), rem_size = size(remain);
    if  (r_size == 0 || rem_size != 0) {
        printf("Error right size %hhu divide by zero or remain polynomial is not empty.\n", r_size);
        return err_incorrect;
    }
    if (l_size == 0) {
        printf("Left polynomial is empty, nothing to divide, so return as is.\n");
        return flag_ok;
    }
    return flag_ok;
}

double calculate(struct polynomial* obj, double value, enum flags is_debug)
{   // Вычисление полинома целиком по заданному значению, в случае ошибки возвращается NaN.
    double result = NAN;
    if (is_correct(obj) != flag_ok || size(obj) == 0) {
        printf("Error calculate, polynomial [%X] is incorrect or empty, return 'NaN'.", to_hw(obj));
        return result;
    }
    printf("Calculate polynomial [%X] value for X = %.2f, (const, element, result): ", to_hw(obj), value);
    char* consts = get_constants(obj, 0);
    unsigned char* exps = get_exponents(obj, 0);
    unsigned char obj_size = size(obj);
    result = 0.0;
    for (unsigned char i = 0; i < obj_size; ++i) {
        result += (double)consts[i] * pow(value, (double)exps[i]);
        if (is_debug & ply_debug)
            printf("(%.2f, %.2f, %.2f) ", (double)consts[i], pow(value, (double)exps[i]), result);
    }
    printf("%.2f\n", result);
    return result;
}

short is_homogeneous(struct polynomial* obj)
{   // Проверка, является-ли полином однородным, т.е. степени всех элементов равны между собой.
    if (is_correct(obj) != flag_ok || size(obj) == 0) {
        printf("Error is homogeneous, polynomial [%X] incorrect or empty.\n", to_hw(obj));
        return 0;
    }
    unsigned char obj_size = size(obj);
    for (unsigned char i = 0; i < obj_size; ++i)            // Опасное условие, можно заменить на два оператора.
        if ((i > 0) && (*get_exponents(obj, i) != *get_exponents(obj, i - 1)))
            return 0;
    return 1;
}

enum flags to_monic(struct polynomial* obj, enum flags type)
{   // Сложение или преобразование полинома к приведенному виду, с потерей данных и по виду.
    // Флаги: more, less - по возрастанию или убыванию степеней; max, min - привести наибольший или наименьший.
    // Если флаги отутствуют, то оставить порядок и коэфициенты как есть, уплотнение вызывается всегда(или).
    if (is_correct(obj) != flag_ok || size(obj) == 0) {
        printf("Error to monic, polynomial [%X] incorrect or empty.\n", to_hw(obj));
        return err_incorrect;
    }
    printf("Converting a polynomial [%X] to monic, flags %X in hex: ", to_hw(obj), type);
    char* consts = get_constants(obj, 0);
    unsigned char* exps = get_exponents(obj, 0), obj_size = size(obj);
    for (unsigned char i = 0, j; i < obj_size - 1; ++i) {
        printf("%+hhd( ", consts[i]);
        for (j = i + 1; consts[i] != 0 && j < obj_size; ++j)
            if (exps[i] == exps[j] && consts[j] != 0) {
                if ((short)consts[i] + (short)consts[j] > CHAR_MAX ||
                    (short)consts[i] + (short)consts[j] < CHAR_MIN)
                    printf("\nCompact warning, merge constants is out of range.\n");
                consts[i] += consts[j];
                printf(" %+hhd", consts[j]);
                consts[j] = 0;
            }
        printf(" ) ");
    }
    printf("\n"); print(obj, 0); // Дополнительная отладка.
    obj_size = compact(obj);
    if (obj_size > 0) {
        if  ((type & ply_less) || (type & ply_more)) {
            print(obj, 0); printf(", linear sort as flags.\n");
            for (unsigned char i = 0, j = 0, idx_max = 0; i < obj_size - 1; idx_max = ++i) {
                for (j = i + 1; j < obj_size; ++j)
                    if (((type & ply_more) && (exps[j] > exps[idx_max])) ||
                        ((type & ply_less) && (exps[j] < exps[idx_max])))
                        idx_max = j;
                if (idx_max != i) {
                    unsigned char tmp_exp = exps[idx_max];
                    char tmp_const = consts[idx_max];
                    exps[idx_max] = exps[i];
                    consts[idx_max] = consts[i];
                    exps[i] = tmp_exp;
                    consts[i] = tmp_const;
                }
            }
            print(obj, 1);
        }
        if (type & ply_min || type & ply_max) {
            print(obj, 0);
            unsigned char i, j;
            for (i = 0, j = 0; i < obj_size; ++i)
                if (((type & ply_min) && (exps[i] < exps[j])) || ((type & ply_max) & (exps[i] > exps[j])))
                    j = i;
            printf(", minimum or maximum exponent at [%hhu], divider is %hhd and compact: ", j, consts[j]);
            char k = consts[j];
            if (k != 0) {
                for (i = 0; i < obj_size; ++i)
                    consts[i] /= k;
                printf("\n");
                print(obj, 0);
                compact(obj);
            } else
                printf("Compact warning, divider is zero, polynomial as is, may be compiler warning.\n");
        }
    }
    return flag_ok;
}

enum flags compare(struct polynomial* left, struct polynomial* right)
{   // Сравнение полиномов. Размеры должны совпадать, сравниваются только константы при равных степенях.
    // Не является математически верным решением, требуется дополнительное изучение. ;)
    if (is_correct(left) != flag_ok || is_correct(right) != flag_ok) {
        printf("Error compare, left [%X] or right [%X] polynommials are incorrect.\n", to_hw(left), to_hw(right));
        return err_incorrect;
    }
    printf("Compare left [%X] and right [%X] polynomials, using monic and compact function:\n",
           to_hw(left), to_hw(right));
    print(left, 1);
    print(right, 1);
    struct polynomial monic_right = { .size = 0, .constants = NULL, .exponents = NULL };
    struct polynomial monic_left = { .size = 0, .constants = NULL, .exponents = NULL };
    copy(&monic_right, right);
    copy(&monic_left, left);
    to_monic(&monic_right, ply_more);
    to_monic(&monic_left, ply_more);
    unsigned char lm_size = size(&monic_left), rm_size = size(&monic_right);
    // printf("%hhu - %hhu\n", lm_size, rm_size);
    if (lm_size == 0 && rm_size == 0) {
        printf("Warning compare, both polynomials are nulls, no elements so they equal.\n");
        return ply_equal;
    }
    if (lm_size != rm_size) {
        printf("Warning compare, sizes of left %hhu and right %hhu polynomials are different.\n",
               lm_size, rm_size);
        return err_compare;
    }
    char *l_consts = get_constants(&monic_left, 0), *r_consts = get_constants(&monic_right, 0);
    unsigned char* l_exps = get_exponents(&monic_left, 0), *r_exps = get_exponents(&monic_right, 0);
    unsigned char more = 0, less = 0, equal = 0, i;
    for (i = 0; i < lm_size && l_exps[i] == r_exps[i]; ++i) {
        if (l_consts[i] > r_consts[i])
            more++;
        if (l_consts[i] < r_consts[i])
            less++;
        if (l_consts[i] == r_consts[i])
            equal++;
        // printf("LE: %hhu, RE: %hhu\n", l_exps[i + 1], r_exps[i + 1]);
    }
    // printf("I = %hhu - %hhu.\n", i, lm_size);
    if (i == lm_size) {
        // printf("I = %hhu - %hhu, more %hhu, less = %hhu, equal = %hhu.\n", i, lm_size, more, less, equal);
        if (more == i) {
            printf("All left constants with equal exponents are more than right.\n");
            return ply_more;
        }
        if (less == i) {
            printf("All left constants with equal exponents are less than right.\n");
            return ply_less;
        }
        if (equal == i) {
            printf("All left constants with equal exponents are equal than right.\n");
            return ply_equal;
        }
    }
    printf("Warning compare, polynomials are not comparable, exponents not equals.\n");
    return err_compare;
}

/*
unsigned char resolve_recur(struct polynomial* obj, double solutions[], double left, double right)
{   // Рекурсивная версия поиска решений полинома методом деления пополам.
    if (is_correct(obj) != flag_ok) {
        return 0;
    }
    unsigned char sols = 0, i, j;
    return 0;
}
*/

unsigned char resolve(struct polynomial* obj, double solutions[], double left, double right)
{   // Решение полинома, методом деления пополам на заданном интервале, до предела эпсилон.
    // Возвращает количиство корней и сами корни в массиве, контроль размеров на стороне вызова.
    // Функция непрерывна и существует на всём интервале.
    if (is_correct(obj) != flag_ok || size(obj) == 0 || right < left || (right - left) < epsilon) {
        printf("Error resolve, polynomial [%X] incorrect, empty or range error (%.2f, %.2f).\n",
               to_hw(obj), left, right);
        return 0;
    }
    // Если решение затягивается, то размеры можно увеличить и использовать динамическую память.
    double ranges[DATA_MAX] = { left, right }, middle = 0.0, l_val, r_val, m_val;
    unsigned char top = 2, sols =  0, deg_max = degree(obj, ply_max);
    while (top > 0 || sols != deg_max) {                                       // Направление не по знаку, а по модулю значения.
        left = ranges[top - 2], right = ranges[top -1], middle = (right - left) / 2.0;
        l_val = calculate(obj, left, ply_nop), r_val = calculate(obj, right, ply_nop),
            m_val = calculate(obj, middle, ply_nop);
        if (fabs(m_val) < 1.0) {
            solutions[sols++] = middle;
            // del
        }
        if (fabs(m_val) < fabs(l_val) && fabs(m_val) < fabs(r_val)) {   // middle
            ranges[top - 1] = middle;
            ranges[top] = middle;
            ranges[top + 1] = right;
            top += 2;
        } else if (fabs(l_val) < fabs(m_val) && fabs(l_val) < fabs(r_val)) {    // left
            printf("Left value is closer, move right to middle.\n");
        } else if (fabs(r_val) < fabs(m_val) && fabs(r_val) < fabs(l_val)) {    // right
            printf("Right is more, move to middle.\n");
            // ranges[];
        } else
            printf("Something goes wrong with ranges.\n");
    }
    return sols;

/*
    if (is_correct(obj) != flag_ok || size(obj) < 1 || ((right - left) > epsilon)) {
        printf("error resolve: polynomial [%X] or left (%.2f) or right (%.2f) is incorrect;\n",
               to_hw(obj), left, right);
        return err_incorrect;
    }
    unsigned char sol_count = 0;
    double left_val = calculate(obj, left, ply_nop);
    double right_val = calculate(obj, right, ply_nop);
    printf("Resolve polynomial [%X], left = %.2f, right = %.2f;\n", to_hw(obj), left, right);
    if (left_val < epsilon)
        solutions[sol_count++] = left;
    if (right_val < epsilon)
        solutions[sol_count++] = right;
    if (left_val * right_val > 0) {
        printf("There are no roots in a given interval;\n");
        return flag_ok;
    }
    double middle = 0;
    while ((right - left) >= epsilon) {
        middle = (left + right) / 2.0;
        double mid_val = calculate(obj, middle, ply_nop);
        if (mid_val < epsilon) {
            solutions[sol_count++] = middle;
            break;
        } else if (mid_val * left_val < epsilon)
            right = middle;
        else
            left = middle;
    }
    solutions[sol_count++] = middle;
    return flag_ok;
*/
}

unsigned short to_hw(void* addr)
{   // Вспомогательная функция преобразования адреса для 64-бит компиляции, переделать.
    return ((unsigned short)((long long)addr));
}

enum flags derivative(struct polynomial* obj, enum flags monic)
{   // Дифференциал от полинома, сохранение в тот же самый объект.
    if (is_correct(obj) != flag_ok || size(obj) == 0) {
        printf("Derivative error, polynomial [%X] is incorrect or empty.\n", to_hw(obj));
        return err_incorrect;
    }
    printf("Derivative source polynomial [%X]:\n", to_hw(obj));
    print(obj, 1);
    unsigned char obj_size = size(obj); // add obj_deg = degree(obj, ply_full);
    char* consts = get_constants(obj, 0);
    unsigned char* exps = get_exponents(obj, 0);
    for (unsigned char i = 0; i < obj_size; ++i) {
        if ((short)(consts[i] * exps[i]) > CHAR_MAX || (short)(consts[i] * exps[i]) < CHAR_MIN)
            printf("Derivative warning, constant at [%hhu] is out of range.\n", consts[i]);
        consts[i] *= exps[i];
        if (exps[i] > 0)
            exps[i]--;
    }
    print(obj, 1);
    to_monic(obj, monic);
    return flag_ok;

    /*enum flags derivative(struct polynomial* obj)
{   // производная от полинома
    if (is_correct_polynomial(obj) != flag_ok || size_polynomial(obj) == 0) {
        printf("\nerror derivative: polynomial [%X] is incorrect;\n", to_hw(obj));
        return err_incorrect;
    }
    //print_polynomial(obj, 1);
    printf("\nDerivative of a polynomial [%X]: ", to_hw(obj));
    char* consts = get_constants(obj, 0);
    unsigned char* exps = get_exponents(obj, 0);
    unsigned char size = size_polynomial(obj);
    for (unsigned char i = 0; i < size; ++i)
        if (exps[i] == 0)
            printf("+0 ");
        else if (exps[i] == 1)
            printf("%+hhd ", consts[i]);
        else
            printf("%+hd*(X)^%hhu ", consts[i] * exps[i], exps[i] - 1);
    printf("\n");
    return flag_ok;
}
     * */

}

enum flags draw(struct polynomial* obj, double lx, double rx)
{   // Рисование полинома в виртуальный экран, на заданном интервале, масштаб определить автоматически.
    // Шаг локальный, желательно чтобы получалось без пропусков и все данные по вычислениям вывести.
    // Дополнительно, постараться чтобы количество условных корней на экране было максимальным.
    const double step = 0.01;
    lx = -4.0; rx = +4.0;
    if (is_correct(obj) != flag_ok || lx == NAN || rx == NAN || (rx < lx) || fabs(rx - lx) < step) {    //1
        printf("Draw error, polynomial [%X] or range [%.2f, %.2f] is incorrect.\n", to_hw(obj), lx, rx);
        return err_incorrect;
    }
    printf("Draw polynomial [%X] in virtual screen with sizes (%hu, %hu) chars.\n", to_hw(obj), SCR_WIDTH, SCR_HEIGHT);
    double max = DBL_MIN, min = DBL_MAX, x = lx, value = 0.0;
    while (x < rx) {
        value = calculate(obj, x, ply_nop);
        if (value > max)
            max = value;
        if (value < min)
            min = value;
        x += step;
    }
    if (max == DBL_MIN || min == DBL_MAX || fabs(max - min) < epsilon) {
        printf("Draw error, some values incorrect, can't calculate min or max, so scale Y.\n");
        return err_range;
    }
    double scale_x = ((double)(SCR_WIDTH) / (rx - lx)), scale_y = (double)(SCR_HEIGHT) / (max - min) - epsilon;
    double offs_x = (rx - lx < epsilon) ? 0.0 : rx - ((rx - lx) / 2.0);
    clear_screen(' ', 0);
    printf("Range X to draw (%.2f, %.2f), step %.2f, offset X %.2f. Polynomial minimum is %.2f, maximum %.2f.\n",
           lx, rx, step, offs_x, min, max); // -1 .. +5. offs = 3.0; 3.0 - 1 = 2;
    printf("Screen scale size X: %.2f and Y: %.2f from min to max.\n", scale_x, scale_y);
    unsigned short cx = (SCR_WIDTH / (2.0)) - ((double)SCR_WIDTH * (offs_x / (rx - lx))),
        counter = 0; // cy = SCR_HEIGHT / (- ((double)SCR_HEIGHT * )
    printf("Point (0, 0) is center at (%hu).\n", cx);
    printf("CY: %2.f - %.2f.\n", scale_y * min, scale_y * max);
    // return 0;
    x = lx;
    while (x < rx) {
        short sx = floor(x * scale_x), sy = floor((calculate(obj, x, ply_nop) - min) * scale_y);
        printf("Step: %d, CX + SX: %d + %d = %d, SY: %d.\n",
               counter, cx, sx, cx + sx, sy);   // %d + %d =
        screen[(SCR_HEIGHT - 1) - sy][cx + sx] = pencil[pencil_colors - 1];
        x += step; counter++;
    }
    print_screen();
    return flag_ok;
}

// Вариант Дани.

/*{   // рисование полинома в виртуальный экран на заданном интервале, масштаб по Y автоматом.
    // Шаг локальный, чтобы график был плотный.
/*
    1) масштабирование по X: разница (модулей r_x (макс) и l_x (мин) / (кол-во позиций - 1)). Первый элемент l_x, последний r_x
    2) Если разница между макс и мин меньше чем размер по Y, то просто оставляем пустое пространство выше
    (или можно сместить - тогда ниже). Если разница больше, чем размер экрана по Y, то в верхний - макс, в нижний - мин.
    Значения между ними, как разница (модулей макс и мин / (кол-во позиций - 1))
    3) шаг по x будет расчитан по масштабированию, если только точки ставить, то просто.
    //  придумать полиномы пологие и x - коэфф.
    */
/*
if (is_correct_polynomial(obj) != flag_ok || r_x - l_x < epsilon) {
    printf("error draw: polynomial [%X] is incorrect or left (%.2f) X more than right (%.2f);\n",
           to_hw(obj), l_x, r_x);
    return err_incorrect;
}
printf("Draw polinomial [%X], left coordinate X (%.2f), right coordinate X (%.2f);\n", to_hw(obj), l_x, r_x);
unsigned char i = 0 , j = 0, idx = 0;
double x_nums_on_y[SCR_WIDTH];          // Посчитанные значения полинома для каждой X координаты
double x_nums[SCR_WIDTH] = {[0] = l_x, [SCR_WIDTH - 1] = r_x};  // X координаты. Масштабируем по ширине экран.
// Масштабирование по X
double step_x = fabs(r_x - l_x) / (double)(SCR_WIDTH - 1);  // Верно но неточно!
printf("Step x = %.10f;\nScaled values by X coordinate: ", step_x);
printf("%0.5f ", x_nums[0]);
for (i = 1; i < SCR_WIDTH - 1; ++i) {
    x_nums[i] = x_nums[i - 1] + step_x;
    printf("%0.5f ", x_nums[i]);
}
printf("%0.5f\n", x_nums[SCR_WIDTH - 1]);
// Расчёт значений полинома для каждого значения X + поиск минимального и максимального для Y координаты
x_nums_on_y[0] = calculate_polynomial(obj, x_nums[0]);
double max_y = x_nums_on_y[0];
double min_y = x_nums_on_y[0];
for (i = 1; i < SCR_WIDTH; ++i) {
    x_nums_on_y[i] = calculate_polynomial(obj, x_nums[i]);
    if (max_y < x_nums_on_y[i])
        max_y = x_nums_on_y[i];
    if (min_y > x_nums_on_y[i])
        min_y = x_nums_on_y[i];
}
printf("Calculated values of the polynomial for each number from the range of the X coordinate:\n");
for (i = 0; i < SCR_WIDTH; ++i)
    printf("%.5f ", x_nums_on_y[i]);
printf("\nmax = %.5f, min = %.5f;\n", max_y, min_y);
// Масштабирование по Y: Вверх - max_y, низ - min_y
if (fabs(max_y - min_y) < epsilon) {
    printf("error draw: step y divided by zero;\n");
    return err_incorrect;
}
double step_y = fabs(max_y - min_y) / (double)(SCR_HEIGHT - 1);
double y_nums[SCR_HEIGHT] = {[0] = min_y, [SCR_HEIGHT - 1] = max_y};     // Y координата. Масштабируем по высоте экрана.
printf("step y = %.10f;\nScaled values by Y coordinate: ", step_y);
printf("%0.5f, ", y_nums[0]);
for (i = 1; i < SCR_HEIGHT - 1; ++i) {
    y_nums[i] = y_nums[i - 1] + step_y;
    printf("%0.5f ", y_nums[i]);
}
printf("%0.5f\n", y_nums[SCR_HEIGHT - 1]);
// Формирование виртуального экрана
clear_screen_ply(pencil[0], 0);
double diff = 0;
for (i = 0; i < SCR_WIDTH; ++i) {     // X
    for (j = 0, idx = 0, diff = max_y; j < SCR_HEIGHT; ++j) {
        // Y, идём по Y координатам для каждого X. Ищем число с самой меньшей разницой от посчитанного X и ставим точку графика
        double y_diff = fabs(y_nums[j] - x_nums_on_y[i]);
        //printf("dif = %.5f, y = %.5f, x = %.5f, coord(%d,%d)\n", y_diff, y_nums[j], x_nums_on_y[i], j ,i);
        if (diff > y_diff) {
            diff = y_diff;
            idx = j;
        }
    }
    //printf("point on Y = %d, X = %d;\n\n", idx, i);
    screen[SCR_HEIGHT - idx - 1][i] = pencil[3];
}
printf("Coordinate range: X(%.2f:%.2f) Y(%.2f:%.2f)\n", l_x, r_x, min_y, max_y);
print_polynomial(obj, 1);
print_screen_ply();
return flag_ok;
 *
 * */

int main()
{   // Основной код программы, общая информация и вывод основной структуры полинома.
    printf("Laboratory 4. Polynomials with signed integer constants and unsigned exponents.\n");
    printf("Size of int %llu, short %llu and char %llu bytes, address width is %llu bits.\n",
           sizeof(int), sizeof(short), sizeof(char), sizeof(char*) * CHAR_BIT);
    printf("Only lower 16 bits of [addresess] will display as '[%%hX]' format.\n");
    printf("Free dynamic 'memory': %u bytes, maximum data objects: %u.\n", MEM_MAX, DATA_MAX);
    printf("Default format to print element is '%s'.\n\n", element_fmt);

    // Вывод базовой информации о структуре полинома и его размеров полей.
    struct polynomial poly_a = { .size = 0, .constants = NULL, .exponents = NULL };
    struct polynomial poly_b = { .size = 0, .constants = NULL, .exponents = NULL };
    struct polynomial poly_c = { .size = 0, .constants = NULL, .exponents = NULL };
    struct polynomial *ptr_a = &poly_a, *ptr_b = &poly_b, *ptr_c = &poly_c;
    printf("Size of structure 'Polynomial' %zu and dynamic element %hu bytes.\n", sizeof(poly_a), element_size);
    printf("Offset:\tType:\t\tSize:\tComment:\n");
    printf("%u\tunsinged char\t%zu\tsize of polynomial in elements;\n",
           to_hw(&poly_a.size) - to_hw(&poly_a), sizeof(poly_a.size));
    printf("%u\tchar ptr\t%zu\tdynamic array of constants;\n",
           to_hw(&poly_a.constants) - to_hw(&poly_a), sizeof(poly_a.constants));
    printf("%u\tunsinged char*\t%zu\tdynamic array of exponents.\n",
           to_hw(&poly_a.exponents) - to_hw(&poly_a), sizeof(poly_a.exponents));

    // Создание, копирование, перемещение, изменение размера, уничтожение и вывода объектов полинома.
    const char data_size = 5;
    char data_consts_a[] = { +3, -4, +3, +2, +1 };
    unsigned char data_exps_a[] = { 1, 1, 0, 3, 1 };
    printf("\n\nCreate, copy, move, resize, compact and destroy polynomial objects.\n\n\n");
    create(ptr_a, data_size, data_consts_a, data_exps_a, 0);
    print(ptr_a, 1);
    printf("Trying to print empty destination polynomial.\n");
    print(ptr_b, 1);
    copy(ptr_b, ptr_a);
    print(ptr_b, 2);
    move(&ptr_c, &ptr_b);
    print(ptr_c, 1);
    printf("Check polynomial object of source after moving to new, must be empty.\n");
    print(ptr_b, 2);
    printf("Resize to size more than source, 5 to 7.\n");
    resize(ptr_a, 7);
    print(ptr_a, 2);
    printf("Compact empty elements from polynomial.\n");
    compact(ptr_a);
    print(ptr_a, 2);
    printf("Resize to size less than source, %hhu to %hhu.\n", size(ptr_a), 1);
    resize(ptr_a, 1);
    print(ptr_a, 2);
    printf("Destroy this polynomial and free memory.\n");
    destroy(ptr_a);

    // Функции конвертации полинома из строки и в строку, установки констант и экспонент.
    printf("\n\nConversions and sets functions tests.\n\n\n");
    printf("Source polynomial and to string conversion.\n");
    print(ptr_c, 2);
    char txt[DATA_MAX];
    to_string(ptr_c, txt);
    printf("Converted string: '%s'.\n", txt);
    char input[DATA_MAX] = "Debug: [-5%3] and [3%+5], plus incorrect [2%%+5).";
    from_string(ptr_b, input);
    printf("Check polynomial after conversion:\n");
    print(ptr_b, 2);
    printf("Set correct constant and incorrect exponent.\n");
    char new_const = +7;
    set_constants(ptr_b, &new_const, 1, 1);
    unsigned char new_exp = 1;
    set_exponents(ptr_b, &new_exp, 1, 8);
    printf("Polynomial after set constant and exponent:\n");
    print(ptr_b, 2);

    // Все арифметические функции, приведение и сравнение.
    printf("\nArithmetic operators, to monic polynomial and compare.\n\n\n");
    char data_consts_b[] = { 2, -1, -2, +5, 0 };
    unsigned char data_exps_b[] = { 2, 1, 3, 3, 2 };
    create(ptr_a, 5, data_consts_b, data_exps_b, ply_nop);
    print(ptr_a, 1);
    inc_dec_offset(ptr_a, 0, size(ptr_a), -1, ply_constant | ply_exponent);
    print(ptr_a, 2);
    to_monic(ptr_a, ply_more | ply_max);
    printf("Check result after to monic:\n");
    print(ptr_a, 2);
    printf("Compare different polynomials include self-compare.\n\n");
    enum flags rf;
    char data_consts_c[] = { +5, -7, +8, -6 };
    unsigned char data_exps_c[] = { 5, 3, 5, 3 };
    resize(ptr_a, 2);
    resize(ptr_c, 2);
    set_constants(ptr_a, &data_consts_c[2], 2, 0);
    set_exponents(ptr_a, &data_exps_c[2], 2, 0);
    set_constants(ptr_c, data_consts_c, 2, 0);
    set_exponents(ptr_c, data_exps_c, 2, 0);
    /*
    print(ptr_a, 2);
    print(ptr_b, 2);
    print(ptr_c, 2);
    */
    rf = compare(ptr_b, ptr_a);
    printf("Result of compare(must be not comparable) in hex %X as flags.\n\n", rf);
    rf = compare(ptr_b, ptr_c);
    printf("Result of compare(must be more) in hex %X as flags.\n\n", rf);
    rf = compare(ptr_b, ptr_b);
    printf("Result of self-compare(must be equal) in hex %X as flags.\n\n", rf);
    printf("Addition and subtraction.\n\n");
    resize(ptr_a, 5);
    resize(ptr_b, 4);
    destroy(ptr_c);
    set_constants(ptr_a, data_consts_b, 5, 0);
    set_exponents(ptr_a, data_exps_b, 5, 0);
    set_constants(ptr_b, data_consts_c, 4, 0);
    set_exponents(ptr_b, data_exps_c, 4, 0);
    printf("\n");
    addition(ptr_a, ptr_b, ply_nop);
    printf("Result of addition left and right:\n");
    print(ptr_a, 2);
    addition(ptr_c, ptr_b, ply_nop);
    printf("Result of addition empty left and right:\n");
    print(ptr_c, 2);
    subtraction(ptr_a, ptr_c, ply_nop);
    print(ptr_a, 2);
    subtraction(ptr_a, ptr_a, ply_nop);
    printf("Result of self-subtraction:\n");
    print(ptr_a, 2);
    // printf("\nSource polynomial for degree:\n");
    print(ptr_c, 1);
    unsigned char deg_min = degree(ptr_c, ply_min);
    unsigned char deg_max = degree(ptr_c, ply_max);
    unsigned char deg_full = degree(ptr_c, ply_full);
    printf("Degrees of polynomial. Min: %hhu, max: %hhu, full: %hhu.\n", deg_min, deg_max, deg_full);

    // На вещании рассмотреть оставшиеся функции: умножение, метод деления пополам, график, однородность.
    printf("Is polynomail homogenous: %hd.\n\n", is_homogeneous(ptr_c));
    derivative(ptr_c, ply_nop);
    print(ptr_c, 2);

    char data_consts_d[] = { 2, 3, 1, -1 };    // { 1, -1, 2 };
    unsigned char data_exps_d[] = { 2, 1, 2, 0};  // { 2, 1, 0 }
    create(ptr_a, 2, data_consts_d, data_exps_d, ply_nop);
    // create(ptr_b, 2, &data_consts_d[2], &data_exps_d[2], ply_nop);
    multiply(ptr_a, ptr_b);

    return 0;

    create(ptr_b, 2, &data_consts_d[2], &data_exps_d[2], ply_nop);
    print(ptr_b, 1);
    double sols[5] = { 0.0, 0.0, 0.0, 0.0, 0.0 };

    unsigned char r = resolve(ptr_b, sols, -0.5, +0.5);
    printf("Result: %hu, %.2f.\n", r, sols[0]);

    // draw(ptr_a, -1.0, +1.0);


    // Освобождение памяти и удаления объектов полиномов.
    printf("\n\nDestroy all polynomials(one incorrect) and free dynamic memory.\n");
    destroy(ptr_a);
    destroy(ptr_b);
    destroy(ptr_c);
    printf("Free memory before exit %hu in hex bytes.\n", memory);

    return 0;
}
