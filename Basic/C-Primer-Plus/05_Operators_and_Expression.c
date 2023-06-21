﻿#include <stdio.h>
#include <limits.h>

// Глава 5. Операции, выражения и операторы.
// Вопросы по ходу кода, повторяем с учетом предыдущих глав.

void part_05(void)
{
    // Данные были в предущих главах. Основные арифметические операции, операторы отношения и последовательность действий алгоритмически.
    // Простые циклы через while, для выполнения повторяющихся операций. Одна из операций фактически это условие и переход в ассемблере.
    printf("C Programming Language. Part 5. Operators, Expressions and Statements.\n\n");
    // Циклы, использование оператора while, блок и составной оператор.
    // Повторение: что такое оператор(составной), функция и из чего состоит программа на Си(схема 53).
    int a, b, c, d;                                         // Объявление через запятую.
    a = 3;
    printf("Using while with single line operator: ");
    while (a-- > 0)                                         // Использование цикла без составного оператора.
        printf("%d ", a);
    printf("\n\nUsing while with block of operators:\n");
    a = 1; b = 2; c = 3;
    // Вопрос: что такое while, в понятиях языка, что в скобках, где начинается и заканчивается цикл.
    while (c > 0) {
        printf("%d:\t%d + %d = %d\n", c, a, b, a + b);
        a++;                                                // Тело цикла.
        b++;
        c--;
    }                                                       // Конец цикла, блок оператора цикла или составной оператор.
    // Константы и вычисления можно упустить, лучше позже.
#define MULTIPLIER 5
    const int const_factors = 3 * MULTIPLIER;
    printf("\nDefine MULTIPLIER %d and constant factors %d.\n", MULTIPLIER, const_factors);
    // Фундаментальные и арифметические операции (операторы).
    // Вопрос: смысл оператора присваивания.
    c = a;                                                  // Отметить команду move.
    printf("\nAssign operator '=', A = %d, B = %d, C = A = %d.\n", a, b, c);
    // Правостороннее значение и левосторонее значение. Можно кратко.
    // Вопрос: объект данных, и вспомнить архтектуру.
    // Цитата из стандарта 21:An lvalue is an expression (with an object type other than void) that potentially designates an object;
    // if an lvalue does not designate an object when it is evaluated, the behavior is undefined.
    // Дополнительно: The name "lvalue" comes originally from the assignment expression E1 = E2, in which the left operand E1 is required to
    // be a (modifiable) lvalue. It is perhaps better considered as representing an object "locator value".
    // Левосторонее значение, имя или выражения идентифицируещего конкретный объект в памяти.
    // What is sometimes called "rvalue" is in this document described as the "value of an expression"
    // Правосторонее значение - имя или выражение, которые могут быть присвоены модифицириуемым левосторонним значениям, но таковыми могут не являтся.
    a = 15;                                                 // a - левосторонний объект который указывается на переменную.
    const int e = 7;                                        // e - правосторонний объект, который может быть применен только в правой части.
    // Вопрос: что такое операнды и порядок исполнения.
    a = b = c = e;                                          // Присваивание цепочкой.
    printf("\nAssign using many '=': A = B = C = %d, result A = %d, B = %d and C = %d.\n", e, a, b, c);
    // Арифметика. Операции стандартные, но требуется учитывать размерности и унарные.
    printf("\nSimple arithmetic operators with integers:\n");
    a = 7; b = 3;                                           // Временно создаваемый объект.
    c = a + b + 1;
    printf("A + B + 1 = %d + %d + 1 = %d.\n", a, b, c);
    c = a - b - 1;
    printf("A - B - 1 = %d - %d - 1 = %d.\n", a, b, c);
    c = a * (b + 1) ;
    printf("A * (B + 1) = %d * (%d + 1) = %d.\n", a, b, c);
    c = a / (b - 1);
    printf("A / (B - 1) = %d / (%d - 1) = %d.\n", a, b, c);
    // Вопрос: бинарные и унарные операторы.
    c = -a;
    printf("Unary operator minus, A = %d and -A = %d.\n", a, c);
    printf("\nBits:\tM = 2 ^ N:\n");                        // Таблица степеней 2, в цикле и экмпонента.
    a = 1; b = 2;
    while (a <= 10) {
        printf("%d\t%d\n", a, b);
        b = b * 2;
        a = a + 1;
    }
    // Кратко про правила деления целых чисел и чисел с плавайющей точкой.
    double f = 2.5, g = 0.5, h;
    h = f / g;
    printf("\nDivide floating point %.3f / %.3f = %.2f.\n", f, g, h);
    // Повторение: размерности типов и преобразование автоматически.
    h = f / (double)e;
    printf("Divide floating point %.3f and integer %d = %.3f.\n", f, e, h);
    // Приоритеты операций. Сначала: (), унарные +-, бинарные */, +- бинарные и =.
    // Совместное использование операндов в выражении, асоциативность.
    // Вопрос: составить выражение с вложенными скобками и связным операндом и вычислить.
    // Асоциативность операнда между, поэтому слева направо. При равном приоритете, порядок вычисления не определен.
    a = 3; b = 5; c = -1;
    d = -a * 3 + b * 2 * (3 + (c + 1));
    printf("\nOperators priorites: -A * 3 + B * 2 * (3 + (C + 1)) = -%d * 3 + %d * 2 * (3 + (%d + 1)) = %d.\n", a, b, c, d);
    // Операция sizeof и тип size_t, заглянуть в определение.
    // Доп. вопрос: размерности типов, откуда.
    size_t max = UINT_MAX;                                  // Допустимо без скобок если это объект, или со скобками - если тип.
    printf("\nSizeof of maximum size_t type is %u.\n", max);
    printf("Size of size_t with this compiler is %u bytes.\n", sizeof max);
    printf("Size of unsigned integer using compiler is %u bytes.\n", sizeof(unsigned int));
    // Операция деления по модулю %.
    printf("\nOperator modulus '%%'.\n");
    const int sec_per_min = 60;
    a = 75; b = a / sec_per_min; c = a % sec_per_min;
    printf("Example: seconds %d is %d minutes and modulus result is %d seconds.\n", a, b, c);
    printf("Negative modulus: %d mod %d = %d.\n", -7, -3, -7 % 3);
    // Операции инкремента и декремента. Аналог +1 или команды ассемблера inc, dec.
    //
    a = 0;
    printf("\nIncrement and decrement using prefix and postfix variants A = %d.\n", a);
    b = ++a;
    printf("Prefix increment B = ++A, B = %d, after A = %d.\n", b, a);
    b = a++;
    printf("Postfix increment B = A++, B = %d, after A = %d.\n", b, a);
    b = --a;
    printf("Prefix decrement B = --A, B = %d, after A = %d.\n", b, a);
    b = a--;
    printf("Postfix decrement B = A--, B = %d, after A = %d.\n", b, a);
    // Цикл и операции инкремента и декремента, идиома.
    a = 5; b = -5;
    printf("\nOperator while and increment and decrement, start A = %d, B = %d.\n", a, b);
    printf("A:\tB:\t++A * 2:\tB--");
    /*
    while (a != b) {
    }
    */
    //
}   // 113, 8770.






