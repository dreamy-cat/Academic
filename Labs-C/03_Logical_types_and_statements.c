#include <stdio.h>
#include <stdlib.h>

// Глава 3. Величины логического типа. Вычисление и составление логических выражений.
// Общие рекомендации. Для решения и отладки удобней использовать вместо типа "bool" - простой целочисленный параметр int и выводить его соответственно. 
// При присвоении параметров переменным использовать 1 если истина, и 0 если ложь. Также при выводе, обозначить условие задания. 
// Удобней сразу с подстановкой 0 или 1. Операторы: "&& - and, || - or, ! - not". Если порядок действий по условию не точен, по порядку действий, то помочь себе скобками.
// Если есть трудности в сложных выражениях, то можно использовать промежуточные переменные в вычислениях. 
// Условные оператор можно не применять и в условиях вида (a > b) можно просто использовать скобки.
// Рекомендуемые стандартные функции в: stdio.h, stdlib.h.

void labs_03(void)
{
    printf("Part 3, logical operators and expressions.\n");
    printf("\nCalculate logical expression.\n");
    int a, b, c, d, e, f, g, h;                             // Все необходимые переменные объвим сразу, лишнее можно уже удалить позже.
    a = 1; b = 0; c = 0;                                    // По условию заданий, "ABC" или "XYZ" для всех используем один набор переменных.
    printf("\n3.1. A = %d, B = %d and C = %d as boolean type.\n", a, b, c);
    d = a || b;                                             // Простое задание, на разминку и знание теории.
    printf("A) A or B = %d or %d = %d.\n", a, b, d);        // Вывод расширенный, вместе с условием.
    d = a && b;
    printf("B) A and B = %d and %d = %d.\n", a, b, d);
    d = b || c;
    printf("V) B or C = %d or %d = %d.\n", b, c, d);
    a = 1; b = 0; c = 0;
    printf("\n3.3. A = %d, B = %d and C = %d as boolean type.\n", a, b, c);     // Чуть сложнее выражения.
    d = !a && b;
    printf("A) not A and B = not %d and %d = %d.\n", a, b, d);
    d = a || !b;
    printf("B) A or not B = %d or not %d = %d.\n", a, b, d);
    d = a && b || c;
    printf("V) A and B or C = %d and %d or %d = %d.\n", a, b, c, d);
    a = 1; b = 0; c = 0;
    printf("\n3.5. A = %d, B = %d and C = %d.\n", a, b, c);                     // Все варианты, множество комбинаций.
    d = a || b && !c;
    printf("A) A or B and not C = %d or %d and not %d = %d.\n", a, b, c, d);
    d = !a && !b;
    printf("B) not A and not B = not %d and not %d = %d.\n", a, b, d);
    d = !(a && c) || b;
    printf("V) not (A and C) or B = not (%d and %d) or %d = %d.\n", a, c, b, d);
    d = a && !b || c;
    printf("G) A and not B or C = %d and not %d or %d = %d.\n", a, b, c, d);
    d = a && (!b || c);
    printf("D) A and (not b or c) = %d and (not %d or %d) = %d.\n", a, b, c, d);
    d = a || (!(b && c));
    printf("E) A or (not (b and c)) = %d or (not (%d and %d)) = %d.\n", a, b, c, d);
    a = 1; b = 0; c = 0;
    printf("\n3.9. A = %d, B = %d and C = %d as boolean types.\n", a, b, c);    // Одна на выбор, чуть уже сложнее.
    d = !a || !b || !c;                                                         // Если строки неудобны, то можно переносить.
    printf("A) not a or not b or not c = not %d or not %d or not %d = %d.\n", a, b, c, d);
    d = (!a || !b) && (a || b);
    printf("B) (not A or not B) and (A or B) = (not %d or not %d) and (%d or %d) = %d.\n", a, b, a, b, d);
    d = (a && b) || (a && c) || !c;
    printf("V) (A and B) or (A and C) or not C = (%d and %d) or (%d and %d) or not %d = %d.\n", a, b, a, c, c, d);
    a = 0; b = 0; c = 1;
    printf("\n3.10. A = %d, B = %d and C = %d.\n", a, b, c);                    // Дополнительная.
    d = (!a || !b) && !c;
    printf("A) (not A or not B) and not C = (not %d or not %d) and not %d = %d.\n", a, b, c, d);
    d = (!a || !b) && (a || b);
    printf("B) (not A or not B) and (A or B) = (not %d or not %d) and (%d or %d) = %d.\n", a, b, a, b, d);
    d = (a && b) || (a && c) || !c;
    printf("V) (A and B) or (A and C) or not C = (%d and %d) or (%d and %d) or not %d = %d.\n", a, b, a, c, c, d);
    a = 1; b = -1;
    d = (a * a + b * b <= 4);
    printf("\n3.11 A = %d, B = %d.\n", a, b);                                   // Вычисление с учетом арифметики и операций сравнения.
    c = (a * a + b * b <= 4);                                                   // Можно использовать напрямую операторы сравнения.
    printf("A) (A ^ 2 + B ^ 2 <= 4) = (%d ^ 2 + %d ^ 2 <= 4) = %d.\n", a, b, c);
    a = 1; b = 2;
    c = (a >= 0) || (b * b != 4);
    printf("B) (A >= 0) or (B ^ 2 not equal 4) = (%d >= 0) or (%d ^ 2 not equal 4) = %d\n", a, b, c);
    a = 1; b = 2;
    c = (a >= 0) && (b * b != 4);
    printf("V) (A >= 0) and (B ^ 2 not equal 4) = (%d >= 0) and (%d ^ 2 not equal 4) = %d.\n", a, b, c);
    a = 2; b = 1;
    c = (a * b != 0) && (b > a);
    printf("G) (A * B not equal 0) and (B > A) = (%d * %d not equal 0) and (%d > %d) = %d.\n", a, b, b, a, c);
    a = 2; b = 1;
    c = (a * b != 0) || (b < a);
    printf("D) (A * B not equal 0) or (B < A) = (%d * %d not equal 0) or (%d < %d) = %d.\n", a, b, b, a, c);
    a = 2; b = 1;
    c = (!(a * b < 0)) && (b > a);
    printf("E) (not(A * B < 0)) and (B > A) = (not(%d * %d < 0)) and (%d > %d) = %d.\n", a, b, b, a, c);
    a = 1; b = 2;
    c = (!(a * b < 0)) || (b > a);
    printf("J) (not(A * B < 0)) or (B > A) = (not(%d * %d < 0)) and (%d > %d) = %d.\n", a, b, b, a, c);
    printf("\n3.13. A) not (A and B) for all combinations A and B.\n");         // Все комбинации параметров A и B:
    a = 0; b = 0; c = !(a && b);                                                // (0, 0), (1, 0), (0, 1), (1, 1).
    printf("A = %d, B = %d. Not (%d and %d) = %d.\n", a, b, a, b, c);
    a = 0; b = 1; c = !(a && b);
    printf("A = %d, B = %d. Not (%d and %d) = %d.\n", a, b, a, b, c);
    a = 1; b = 0; c = !(a && b);
    printf("A = %d, B = %d. Not (%d and %d) = %d.\n", a, b, a, b, c);
    a = 1; b = 1; c = !(a && b);
    printf("A = %d, B = %d. Not (%d and %d) = %d.\n", a, b, a, b, c);
    printf("\n3.17. B) (B or not A) and not B for all combinations A and B.\n");
    a = 0; b = 0;                                           // Аналогичное задание, немного сложнее.
    c = (b || !a) && !b;
    printf("A = %d, B = %d. (%d or not %d) and not %d = %d.\n", a, b, b, a, b, c);
    a = 0; b = 1;
    c = (b || !a) && !b;
    printf("A = %d, B = %d. (%d or not %d) and not %d = %d.\n", a, b, b, a, b, c);
    a = 1; b = 0;
    c = (b || !a) && !b;
    printf("A = %d, B = %d. (%d or not %d) and not %d = %d.\n", a, b, b, a, b, c);
    a = 1; b = 1;
    c = (b || !a) && !b;
    printf("A = %d, B = %d. (%d or not %d) and not %d = %d.\n", a, b, b, a, b, c);
    a = 1; b = 0;                                           // Дополнительное задание, чуть более сложное.
    c = 0; d = !(a && b) && (!a || !c);
    printf("\n3.25. A) not (A and B) and (not A or not C) = "                   
        "not (%d and %d) and (not %d or not %d) = %d.\n", a, b, a, c, d);
    printf("\n3.27. Only true logical statement.\n");       // Только истинные логические выражения.
    a = 3; b = 4;
    c = (a > 2) && (b > 3);
    printf("A) (A > 2) and (B > 3) = (%d > 2) and (%d > 3) = %d.\n", a, b, c);
    a = -2;
    b = (a > 3) || (a < -1);
    printf("G) (A > 3) or (A < -1) = (%d > 3) or (%d < -1) = %d.\n", a, a, b);
    a = 3;
    b = !(a > 0 && a < 5);
    printf("J) not (A > 0 and A < 5) = not (%d > 0 and %d < 5) = %d.\n", a, a, b);
    printf("\n3.29 True logic statements.\n");              // В этом задании условия частично текстом и сразу вывод.
    a = 3; b = 5;
    c = (a % 2 == 1) && (b % 2 == 1);
    printf("A) Every number is odd. (%d mod 2 == 1) and (%d mod 2 == 1) = %d.\n", a, b, c);
    a = 23; b = 19;
    c = ((a < 20) || (b < 20)) && !((a < 20) && (b < 20));
    printf("B) Only one of numbers is less than 20. "
        "((%d < 20) || (%d < 20)) && not ((%d < 20) && (%d < 20)) = %d.\n", a, b, a, b, c);
    a = 5; b = 0;
    c = !a || !b;
    printf("V) Any of two number is zero. not %d or not %d = %d.\n", a, b, c);
    a = -3; b = -1; c = -2;
    d = (a < 0) & (b < 0) & (c < 0);
    printf("G) All of three numbers is negative. (%d < 0) and (%d < 0) and (%d < 0) = %d.\n", a, b, c, d);
    a = 3; b = 7; c = 10;
    d = ((a % 5 == 0) + (b % 5 == 0) + (c % 5 == 0) == 1);
    printf("D) Only one of numbers modulus 5."
        "((%d mod 5 == 0) + (%d mod 5 == 0) + (%d mod 5 == 0) == 1) = %d.\n", a, b, c, d);
    a = 150; b = 120; c = 75;
    d = (a > 100) || (b > 100) || (c > 100);
    printf("E) Any of three numbers is more than 100. "
        "(%d > 100) or (%d > 100) or (%d > 100) = %d.\n", a, b, c, d);
    a = 6;
    printf("\n3.30. Number is %d.\n", a);                   // Простое, с учетом остатка от деления.
    b = (a % 2 == 0) || (a % 3 == 0);
    printf("A) Number is divided by 2 or 3. (%d mod 2 == ) or (%d mod 3 == 0) = %d.\n", a, a, b);
    a = 10;
    b = !(a % 3 == 0) && (a % 10 == 0);
    printf("B) Number is not divided by 3 and last digit is zero. "
        "!(%d mod 3 == 0) and (%d mod 10 == 0) = %d.\n", a, a, b);
    printf("3.32. See figures at book. Using rounded integers instead of floating point parameters.\n");
    a = -4; b = 2;                                          // Рисунки в книге, крайние значения включаются в условия.
    c = (a <= -2) && (b >= 1);
    printf("A) Coordinates [%d,%d]. Point at: (%d <= -2) and (%d >= 1) = %d.\n", a, b, a, b, c);
    a = 5; b = -1;
    c = (b >= -2 && b <= 2);
    printf("B) Coordinates [%d,%d]. Point at: (%d >= -2 and %d <= 2) = %d.\n", a, b, b, b, c);
    a = 1; b = 2;
    c = (a >= 1 && a <= 2 && b <= 4);
    printf("V) Corrdinates [%d,%d]. Point at: (%d >= 1 and %d <= 2 and %d <= 4) = %d.\n", a, b, a, a, b, c);
    a = 3; b = 3;
    c = (a >= 1 && b <= 4 && b >= 2);
    printf("G) Coordinates [%d,%d]. Point at: (%d >= 1 and %d <= 4 and %d >= 2) = %d.\n", a, b, a, b, b, c);
    a = 2; b = -3;
    c = (a >= 2 && b >= 1) || (a >= 1 && b <= -1);
    printf("D) Coordinates [%d,%d]. Point at: (%d >= 2 and %d >= 1) or (%d >= 1 and %d <= -1) = %d.\n", a, b, a, b, a, b, c);
    a = 3; b = 2;
    c = (a >= 2 && (b >= 1 || b <= -2));
    printf("E) Coordinates [%d,%d]. Point at: %d >= 2 and (%d >= 1 or %d <= -2) = %d.\n", a, b, a, b, b, c);
    a = 2; b = -2;
    c = (a >= 1 && a <= 3 && b <= -1 && b >= -2);
    printf("J) Coordinates [%d,%d]. Point at: %d >= 1 and %d <= 3 and %d <= -1 and %d >= -2 = %d.\n", a, b, a, a, b, b, c);
    a = -1; b = 1;
    c = (a < 2 && b >= 0 && b <= 2) || (a >= 2);
    printf("Z) Coordinates [%d, %d]. Point at: (%d < 2 and %d >= 0 and %d <= 2) or (%d >= 2) = %d.\n", a, b, a, b, b, a, c);
    // Дополнительные задания по правилам шахмат. Выход за пределы доски не учитывать. Данные считается корректными.
    // Первый параметр: номер столбца слева направо от 1 до 8 и номер строки снизу-вверх от 1 до 8.
    printf("\n3.34. Chess board vertical column [1..8] and horizontal row [1..8].\n");
    a = 2; b = 2; c = 2; d = 5;
    e = (a == c || b == d);                                 // Ладья атакует позицию.
    printf("A) If rook at [%d,%d] is threat to position [%d,%d]. "
        "Is (%d == %d or %d == %d) = %d.\n", a, b, c, d, a, c, b, d, e);
    a = 7; b = 6; c = 3; d = 2;
    e = (abs(c - a) == abs(d - b));                         // Ладья атакует позицию.
    printf("B) If bishop at [%d,%d] is threat to position [%d,%d]. "
        "Is(abs(% d - % d) == abs(% d - % d)) = % d.\n", a, b, c, d, c, a, d, b, e);
    a = 3; b = 5; c = 2; d = 4;
    e = (abs(c - a) == 1 || abs(d - b) == 1);               // Может-ли король двигаться на позицию, но не соять на месте.
    printf("V) If king at [%d,%d] can move to position [%d,%d]. "
        "Is abs(%d - %d) == 1 or abs(%d - %d) == 1 = %d.\n", a, b, c, d, c, a, d, b, e);
    a = 7; b = 2; c = 2; d = 2;
    e = (a == c || b == d) || (abs(c - a) == abs(d - b));   // Ферзь атакует позицию.
    printf("G) If queen at [%d,%d] is threat to position [%d,%d]. "
        "Is (%d == %d || %d == %d) || (abs(%d - %d) == abs(%d - %d)) = %d.\n",
        a, b, c, d, a, c, b, d, c, a, d, b, e);
    a = 4; b = 3; c = 5; d = 4;
    e = (a == c && d - b == 1);                             // Пешка движется снизу вверх.
    printf("D) If moving pow at [%d,%d] upper to [%d,%d]. "
        "Is (%d == %d and %d - %d == 1) = % d.\n", a, b, c, d, a, c, d, b, e);
    e = (abs(a - c) == 1 && (d - b) == 1);                  // Пешка атакует вверх и в одну из сторон.
    printf("D) If pow attack from [%d,%d] to upper [%d,%d]. "
        "Is (abs(%d - %d) == 1 and (%d - %d) == 1) = %d.\n", a, b, c, d, a, c, d, b, e);
    a = 3; b = 2; c = 5; d = 3;                             // Для коня можно подумать над упрощением.
    e = (abs(a - c) == 1 && abs(b - d) == 1) || (abs(a - c) == 2 && abs(b - d) == 1);
    printf("J) If knight attack from [%d,%d] to [%d,%d]. "
        "Is (abs(%d - %d) == 1 and abs(%d - %d) == 1) or (abs(%d - %d) == 2 and abs(%d - %d) == 1) == %d.\n",
        a, c, b, d, a, c, b, d, a, c, b, d, e);
    // Дополнительная. Вычисления в два этапа, или можно выводить сразу. Допустимость размеров доски не учитывать.
    a = 1; b = 2; c = 4; d = 3; e = 1; f = 6;
    printf("\n3.35. Moving figure from one to other position safe from second figure.\n");
    g = (a == e || b == f);                                 // Допустимость хода для первой фигуры.
    h = (c == e || d == f || abs(e - c) == abs(f - d));     // Допустимость хода для второй фигуры.
    printf("B) Rook at [%d,%d] move to [%d,%d] is safe from queen at [%d,%d].\n", a, b, e, f, c, d);
    printf("Move rook: (%d == %d) or (%d == %d) = %d.\n", a, e, b, f, g);
    printf("Move queen: (%d == %d or %d == %d) or (abs(%d - %d) == abs(%d - %d)) = %d.\n", c, e, d, f, e, c, f, d, h);
    printf("Is rook safe to move: %d.\n", !(g && h));
    a = 2; b = 3; c = 5; d = 3; e = 3; f = 5;
    printf("\nM) Knight at [%d,%d] move to [%d,%d] is safe from bishop at [%d,%d].\n", a, b, e, f, c, d);
    g = (abs(a - e) == 1 && abs(b - f) == 2) || (abs(a - e) == 2 && abs(b - f) == 1);
    h = (abs(c - e) == abs(d - f));
    printf("Move knight: (abs(%d - %d) == 1 and abs(%d - %d) == 2) or (abs(%d - %d) == 2 and abs(%d - %d) == 1) == %d.\n",
        a, e, b, f, a, e, b, f, g);
    printf("Move bishop: abs(%d - %d) == abs(%d - %d) = %d.\n", c, e, d, f, h);
    printf("Is knight safe to move: %d.\n", !(g && h));
    a = 5; b = 3; c = 7; d = 2; e = 6; f = 4;
    printf("\nU) King at [%d,%d] move to [%d,%d] is safe from knight at [%d,%d].\n", a, b, e, f, c, d);
    g = (abs(a - e) == 1 || abs(b - f) == 1);
    h = (abs(c - e) == 1 && abs(d - f) == 2) || (abs(c - e) == 2 && abs(d - f) == 1);
    printf("King move: (abs(%d - %d) == 1) or (abs(%d - %d) == 1) = %d.\n", a, e, b, f, g);
    printf("Knight move: ((abs(%d - %d) == 1 and (abs(%d - %d) == 2) or ((abs(%d - %d) == 2 and (abs(%d - %d) == 1) = %d.\n",
        c, e, d, f, c, e, d, f, h);
    printf("Is king safe to move: %d.\n", !(g && h));
}
