#include <stdio.h>
#include <limits.h>
#include <float.h>

void theory_03(void)
{
    // Теоретическое вещание по типам данных, возможна демонстрация ассемблера.
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
