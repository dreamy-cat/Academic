#include "labs_0x07.h"

// Все теоретические части, которые были рассмотрены на вещаниях.
// Учебник - Прата(6-ое издание), КиР, стандарт языка и немного видео материалов.
// Для демонстрации использовался GCC 8.1.0, 32-bit, QtCreator.

void theory_03(void)
{
    // Теоретическое вещание по типам данных, небольшая демонстрация ассемблера.
    // Демонстрационная программа на языке, с таблицей данных. Также несколько ссылок на Вики. Вспомнить про ввода-вывод.
    printf("Chapter 3, theory. Types in C language.\n");
    printf("Simple output with format.\n");
    char c1 = 'a';
    short sh1 = 8;
    printf("Signed char: '%c', signed short int: %d\n", c1, sh1);
    float f1 = 1.5;
    double d1 = 0.12345;
    double *d_ptr = &d1;
    // Преобразование типов double, float при выводе в консоль. Предупреждение компилятора.
    printf("%10.10f %3.5g %1.2E %p\n", (double)f1, d1, d1, (void*)d_ptr);
    // Переменные и константы. Здесь только упомянуть.
    int a = 5;
    const int b = 3;
    a++;
    // b--; // error
    // Константа типа перечисление. До них далеко, так что используем сейчас.
    printf("Constant integer %d, can't change, compile error.\n", b);
    enum colors {red, green, blue };
    printf("Enumerate colors: ");
    for (int i = red; i < blue; ++i)
        printf("%d ", i);
    // Ключевые слова для типов данных.
    // Таблица типов данных языка Си и их параметры.
    // printf("INT:\t%u\t%u:\t%d\t\t\t%u\n"; Шаблон.
    printf("Table of types in C language, SIZE_T is %d bytes.\n", sizeof(size_t));
    printf("Type:\t\tSize:\tBits:\tMin:\t\tMax:\n");
    // Про целочисленные. Табличка по развитию стандартов и ключевые слова в нем. Про байты, биты размерности и слова.
    // Кинуть ссылку на канал Computerphile, "Where did Bytes Come From?". https://youtu.be/ixJCo0cyAuA
    unsigned int s_int_size = sizeof(long), s_int_bits = sizeof(int) * __CHAR_BIT__;
    int s_int_min_ = INT_MIN, s_int_max = INT_MAX;
    printf("INT:\t\t%u\t%u:\t%d\t%u\n", s_int_size, s_int_bits, s_int_min_, s_int_max);
    unsigned int u_int_size = sizeof(unsigned int), u_int_bits = sizeof(unsigned int) * __CHAR_BIT__;
    unsigned int u_int_min_ = 0, u_int_max = UINT_MAX;
    printf("UNSIGNED INT:\t%u\t%u:\t%u\t\t%u\n", u_int_size, u_int_bits, u_int_min_, u_int_max);
    unsigned short int s_sh_int_size = sizeof(int), s_sh_int_bits = sizeof(int) * __CHAR_BIT__;
    short int s_sh_int_min_ = SHRT_MIN, s_sh_int_max = SHRT_MAX;
    printf("INT:\t\t%u\t%u:\t%d\t%u\n", s_sh_int_size, s_sh_int_bits, s_sh_int_min_, s_sh_int_max);
    unsigned int s_l_int_size = sizeof(long long int), s_l_int_bits = sizeof(long int) * __CHAR_BIT__;
    long long int s_l_int_min_ = LONG_LONG_MIN, s_l_int_max = INT_MAX;
    printf("INT:\t\t%u\t%u:\t%lld\t%llu\n", s_l_int_size, s_l_int_bits, s_l_int_min_, s_l_int_max);
    // Тип long double, float.h
    unsigned int l_double_size = __SIZEOF_LONG_DOUBLE__, l_double_bits = sizeof(int) * __CHAR_BIT__;
    long double l_double_min_ = LDBL_MIN, l_double_max = LDBL_MAX;
    printf("LONG DOUBLE:\t\t%u\t%u:\t%.Le\t%.Le\n", l_double_size, l_double_bits, l_double_min_, l_double_max);
    // О представлениях целогого числа и чесел с плавающей точкой.
    // Любой целое число кроме unsigned char, делиться на групы битов.
    // Точность и ширина. Разнообразие. Переполнение. _Булев.
    // Пару слов про переносимые типы. int32_t
    int data = 0x55FF00AA;
    printf("Integer %d with sign %d in binary, size of int %d.\n", data, (data < 0), sizeof(data));
    printf("Offset:\tValue:\tBinary(High bit -> low bit):");
    unsigned char* byte;
    for (unsigned int i = 0; i < sizeof(data); ++i) {
        byte = (unsigned char*)(&data) + i;
        printf("\n[+%d]:\t%2X\t", i, *byte);
        for (int j = 0; j < __CHAR_BIT__; ++j) {    // просто порядок битов.
            unsigned char bit = ((*byte << j) & 0x80) >> (__CHAR_BIT__ - 1);
            printf("%d", bit);
        }
    }
    // Про инициалзацию значений и её обьявление и определение. Занимаемая ячейка памяти.
    // Число с плавающей точкой. Про разницу научной и экспоненциальной формы. Константы и символ Е.
    // Про переполнение и потерю точности. Бесконечность и число не существует.
    float f_data = (float)-128.1543;
    int f_size = sizeof(float);
    const int bt_sign = 31, bt_exp = 30, bt_fract = 22;     // float
    printf("\n\nFloat value %.2f as data, size %d.\n", (double)f_data, sizeof(f_data));
    printf("Bits:\t\tBinary(H-L):");
    for (int i = f_size - 1, bt = f_size * __CHAR_BIT__ - 1; i >= 0; --i) {     // bt = 31
        byte = (unsigned char*)(&f_data) + i;
        for (int j = 0; j < __CHAR_BIT__; ++j, --bt) {       // порядок может быть обратным
            if (bt == bt_sign)
                printf("\nSign[%d]:\t\t", bt);
            else if (bt == bt_exp)
                printf("\nExponent[%d..%d]\t", bt_exp, bt_fract + 1);
            else if (bt == bt_fract)
                printf("\nFraction[%d..0]:\t", bt_fract);
            unsigned char bit = ((*byte << j) & 0x80) >> (__CHAR_BIT__ - 1);
            printf("%d", bit);
        }
    }
    printf("\n");
    // Булевы значения. Порядок действий и специальный тип.
    int a1 = 1, a2 = 0, a3 = 1;
    int r = (a1 && !a2) || a3;
    printf("%d AND NOT %d || %d = %d\n", a1, a2, a3, r);
    // Неявное преобразование, использовть тип, который подход. Char, int, double.
    // Управляемые полседовательности и сброс буфера.
}

void theory_04(void)
{
    printf("Theory and examples for stream, chapter 4.\n");
    printf("Strings of chars and string format.\n");
    // Небольшое встпуление и создание переменных. Строка как последовательность символов.
    char string[256] = "This is text string.";
    printf("String: '%s'.\n", string);
    // Массив типа чар, нулевой символ и размерность. Посмотрим по адресам и кодам АСКИИ.
    printf("Size of string: %d.\n", sizeof(string));
    printf("Address:\tCode:\tChar:\n");
    for (int i = 0;  i < 25/* string[i] != '\0' */; ++i)
        printf("%u:\t%d\t'%c'\n", (unsigned int)(&string[i]), string[i], string[i]);
    // Строка может быть использована как константа через define и при вызове функции непосредственно.
    // Отметить про ввод строк через сканф, фгетс и через getchar.
    // Различия между строковыми и символьными константами. Каков размер в памяти?
    char c1 = 'a';
    char s1[] = "a";
    printf("Size of char '%c' is %d, size of string '%s' is %d.\n", c1, sizeof(c1), s1, sizeof(s1));
    // Функцию длины строки уже все делали, это классика. string.h или strings.h
    // Про sizeof от типа или конкретного объекта, без скобок не работает.
    // Константы и препроцессор. Магических чисел стоит избегать, кроме обычно -1, 0, 1. Что предпочесть?
    // Читаемость, изменяемость. Препроцессора лучше избегать define - символические константы. Подстановка во время компиляции.
    // Если уж использовать define, то строго прописными буквами, чтобы в глаза бросалось. constexpr в с++.
    const int bits = CHAR_BIT;      // Квалификатор или модификатор, зависит от перевода.
    // Далее про define и limits.h и системное использование. float.h. Отметить про разные платформы и условную компиляцию.
    printf("Bits in one char %d.\n", bits);
    // Функции ввода-вывода, не являются частью языка. Управляющая-строка со спецификаторами преобразования, таблицы разные есть по справочникам.
    printf("Signed integer: %d, hex: 0x%X, double: %.2f, exponent: %.2e.\n", -3, 12, 2.5, 3.5);
    // printf("Specs for %d and %d.\n", 5);     // Неопределенные данные при выводе. Знак % при выводе.
    // Модификаторы спецификаторов для функции вывода, между спецификатором и знаком %. %z - для sizeof.
    printf("Sign: %+-d, field: %5d, precision %.3g, short: %hu, unsigned char: %hhu, unsigned long: %llu.\n", +3, 7, 2.5, 50000, UCHAR_MAX, ULLONG_MAX);
    float f1 = 7.5;     // Немного про форматирование здесь же отметить. Быть осторожным с округлением.
    printf("Float and double: %.2f.\n", f1);    // (double)f1
    // Флаги функции вывода. Не забыть про ведущий пробел.
    printf("Left align: '%-4d', with plus '%+3d', hex with prefix '%#2X', with zeros '%03d'.\n", 15, +5, 28, -7);
    // Вывод строк. Форматирование. Точка для ограничения вывода и знак для выравнивания.
    char s[] = "8-Bit Tea Party!";
    printf("String more than filed: '%3s'.\n", s);
    printf("Field more than string: '%20s'.\n", s);
    printf("String with right align: '%20.5s'.\n", s);
    printf("String with left align: '%-20.5s'.\n", s);
    // Спецификатор преобразования работает из данных в представление, спецификатор не всегда может быть однозначен относительно данных.
    // Знаковое и беззнаковое представление чисел. Предупреждение. Поразрядное дополнение до двух. Почему?
    short int i1 = 49152;       // Не всегда срабатывает отбрасывание знака.
    printf("Short int with sign %hd, unsgined char %hu, sizeof type %d.\n", i1, i1, sizeof(short int));
    unsigned int i2 = 0xFE14A5B1;
    unsigned short int i3 = (unsigned short int)i2;
    unsigned char i4 = (unsigned char)i3;
    printf("Unsigned integer: %X, unsigned short: %hX, unsigned char: %X.\n", i2, i3, i4);
    // Смешение целочисленного типа и типа с плавающей точкой, еще более необычно. Предупреждение компилятора.
    f1 = -1048.576f;            // Оформление буквы.
    printf("Float %.2f as unsigned int %u.\n", f1, f1);
    printf("Unsigned int %u as double %5.5e.\n", i2, i2);
    // Простая реинтерпритация данных, которые расположены в памяти.
    // При передаче printf аргументов работает стек и память выделяется на нём.
    // Возвращаемое значение функции вывода количество всех символов плюс управление, если -1 то ошибка.
    int r = printf("Float %.2f, integer %d.\n", f1, i1);
    printf("Function printf() return %d.\n", r);
    // Разбивка оператора на несколько строк, поддержка компилятором.
    printf("First line string,\n"
            "second line, parameter %d.\n",
           i1);
    // Функция scanf. В целом всё тоже самое. Спецификаторы и модификаторы все в силе.
    char buffer[256];
    printf("Enter integer, float, char and string: ");
    double d1;      // %f - спецификатор по умолчанию ожидает float.
    r = scanf("%hd %lf %c %s", &i1, &d1, &c1, buffer);
    printf("Scanf returns %d and parameters: int %d, float %.2f, char '%c' and string '%s'.\n", r, i1, d1, c1, buffer);
    // Обработка ввода функцией scanf. По поток ввода, пока не найден символ разделитель. Или возврат в поток ввода.
    // Строка считывает фактически слово.
    // Обычные символы интерпретируются как условное форматирование.
    printf("Enter two digits with '-':");
    scanf("%d-%d", &i1, &i2);
    printf("Integers with '-' sep: %d and %d.\n", i1, i2);
    // Модификатор * для определения поля с подстановкой параметра.
    int l1 = 8, l2 = 3;
    printf("Double with parameters of width: %*.*f.\n", l1, l2, d1);
    // Фиксированная длинна/ширина полей для столбцов и таблиц.
    // Про локальную, использовать как есть пока что.
    // Ключевые вопросы: как представлен символ, строка и как они хранятся.
    // define - стараться избегать. Быть осторожным с интерпретацией float и double.
    // Формат строки Си, немного отметить, но подробности в дальнейших главах.
}
