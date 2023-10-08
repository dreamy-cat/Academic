#include <stdio.h>
#include <math.h>

// Глава 4. Условный оператор или операторы ветвления.
// Переработать полностью с учетом комменатариев и обновленных планов.

void labs_04(void)
{
    printf("Chapter 4. Branching operators: 'if-else', 'switch-case', 'break' and 'continue'.\n\n");
    int a, b, c, d;                                         // Все переменные, которые будут применяться через главу.
    double e, f, g, h;                                      // Переменные с плавающей точкой.
    const int base = 10;                                    // Основание системы счисления.
    const double pi = acos(-1.0);                           // Константа Пи для удобства использования в формулах.
    e = 5.0;
    printf("4.1. IF X > 0, Y(X) = SIN(X)^2, ELSE Y(X) = 1 - 2 * SIN(X^2) = ");
    if (e > 0) {                                            // Полный условный оператор.
        f = sin(e) * sin(e);
        printf("SIN(%.2f)^2 = %.2f.\n", e, f);
    } else {
        f = 1.0 - 2.0 * sin(e * e);
        printf("1 - 2 * SIN(%.2f)^2 = %.2f.\n", e, f);
    }
    a = 3; b = -3; c = 5;                                   // Рисунок 4.3, стр. 28.
    printf("\n4.5. See figure, ranges [-inf, +%d] and [%d, +inf], X = %d, Y(X) = ", a, a, c);
    if (c <= 3)
        printf("Y(%d) = %d.\n", c, -1 * c);
    else
        printf("Y(%d) = %d.\n", c, -3);
    a = 3; b = 5;                                           // Можно целые числа вместо вещественных.
    if (a > b)
        printf("\n4.6. A-B) Parameter %d more than %d.\n", a, b);
    else if (a < b)
        printf("\n4.6. A-B) Parameter %d less than %d.\n", a, b);
    else
        printf("\n4.6. A-B) Parameter %d is equal than %d.\n", a, b);
    const double m_per_foot = 0.305, m_per_km = 1000.0;
    e = 25.3; f = 45.7;                                     // Километры и футы.
    g = f * m_per_km; h = g * m_per_foot;
    if (g > h)
        printf("\n4.8. Kilometers %.2f and %.2f foots as meters %.2f more than %.2f.\n", e, f, g, h);
    else
        printf("\n4.8. Kilometers %.2f and %.2f foots as meters %.2f less than %.2f.\n", e, f, g, h);
    const double sec_per_hour = 3600.0;
    e = 50.0; f = 4.5;                                      // Километры в час и метры в секунду.
    g = e * m_per_km / sec_per_hour;
    if (g > f)
        printf("\n4.9. Kilometers per hour %.2f, meters per second %.2f more than %.2f.\n", e, g, f);
    else
        printf("\n4.9. Kilometers per hour %.2f, meters per second %.2f less than %.2f.\n", e, g, f);
    e = 3.5; f = 5.5;                                       // Радиус окружности и сторона квадрата.
    g = pi * (e * e); h = f * f;
    if (g > h)
        printf("\n4.10. Radius %.2f of circle, side %.2f of f-square and area %.2f more than %.2f.\n", e, f, g, h);
    else
        printf("\n4.10. Radius %.2f of circle, side %.2f of f-square and area %.2f more than %.2f.\n", e, f, g, h);
    e = 3.1; f = 0.5; g = 2.2; h = 0.7;                     // Объемы и масса двух объектов.
    printf("\n4.11. Mass and volume for objects (%.2f, %.2f) and (%.2f, %.2f) - ", e, f, g, h);
    if (e / f > g / h)
        printf("first density %.2f more than second %.2f.\n", e / f, g / h);
    else
        printf("second density %.2f more than first %.2f.\n", g / h, e / f);
    e = 50.1; f = 2.3; g = 30.5; h = 10.2;                  // Напряжения и сопротивления для двух участков.
    printf("\n4.12. Resistor A = %.2f om, voltage A = %.2f volt, resistor B = %.2f om, voltage B = %.2f volt.\n", e, f, g, h);
    if ((e / f) > (g / h))
        printf("Current %.2f in first circuit is more or equal than in second.\n", (e / f));
    else
        printf("Current %.2f in second circuit is less than in first.\n", (g / h));
    a = 1; b = 5; c = 0;                                    // Квадратное уравнение, классика. Обе задачи вместе.
    d = b * b - 4 * a * c;                                  // Дискриминант.
    printf("\n4.13-14. The equation A*X^2 + B*X + C = %d*X^2 + %d*X + %d, D = %d.\n", a, b, c, d);
    // Дополнительная проверка условий для неполного уравнения.
    if (b == 0) {
        if (c == 0)
            printf("Second(B) and free(C) parameter are zero, result will zero.\n");
        else
            printf("Second(B) parameter is zero, but free(C) parameter is not, result depends on -C/A.\n");
    } else if (c == 0)
        printf("Second(B) parameter is not zero, but free(C) parameter is zero, result will both solutions.\n");
    if (d > 0) {
        double r1 = (-1.0 * (double)b + sqrt(d)) / (2.0 * (double)a);
        double r2 = (-1.0 * (double)b - sqrt(d)) / (2.0 * (double)a);
        printf("Discriminant is positive, first result is %.2f, second result is %.2f.\n", r1, r2);
    } else if (d == 0) {
        double r1 = (-1.0 * (double)b) / (2.0 * (double)a);
        printf("Discriminant is zero, the only result is %.2f.\n", r1);
    } else
        printf("Discriminant is negative, no results for equation.\n");
    e = 3.0 * 3.0 * pi; f = 2.0 * 2.0;                      // Площадь окружности и квадрата.
    printf("\n4.16. Area of circle %.2f, foursquare %.2f.\n", e, f);
    g = sqrt(f) / 2.0; h = sqrt(2.0) / 2.0 * sqrt(f);       // Радиус вписанной и описанной окружности квадрата.
    e = sqrt(e / pi);                                       // Радиус исходной окружности.
    printf("Radius inner %.2f, outer %.2f and actual %.2f.\n", g, h, e);
    if (e <= g)
        printf("A) Minimum radius of inner circle is %.2f, actual radius %.2f can fit in foursquare.\n", g, e);
    else
        printf("A) Minimum radius of inner circle is %.2f, actual radius %.2f can't fit in foursquare.\n", g, e);
    if (e >= h)
        printf("B) Minimum radius of outer circle is %.2f, actual radius %.2f can fit foursquare.\n", h, e);
    else
        printf("B) Minimum radius of outer circle is %.2f, actual radius %.2f can't fit foursquare.\n", h, e);
    e = pi * 4.5 * 4.5; f = 15.0;                           // Площадь круга и равностороннего треугольника.
    printf("\n4.17. Area of circle is %.2f and area of equilateral triangle is %.2f.\n", e, f);
    g = sqrt(e / pi);                                       // Радиус окружности, если требуются вычисления.
    h = sqrt(f * 4.0 / sqrt(3.0));                          // Сторона равностороннего треугольник через частную формулу.
    printf("Radius of circle is %.2f and side of triangle is %.2f.\n", g, h);
    e = sqrt(3.0) / 6.0 * h; f = sqrt(3.0) / 3.0 * h;       // Расчётный радиус вписанной и описанной окружности.
    if (e < g)
        printf("A) Maximum radius of inner circle %.2f is less than actual %.2f, can't fit in triangle.\n", e, g);
    else
        printf("A) Maximum radius of inner circle %.2f is less or equal actual %.2f, can fit in triangle.\n", e, g);
    if (f > g)
        printf("B) Minimum radius of outer circle %.2f is less than actual %.2f, can't fit in circle.\n", f, g);
    else
        printf("B) Minimum radius of outer circle %.2f is more or equal than actual %.2f, can fit in circle.\n", f, g);
    int x1, x2, y1, y2, x3, y3, x4, y4;                     // Переменные и координаты углов прямоугольников.
    x1 = 1; y1 = 2; x2 = 3; y2 = 4;                         // Т.к. массивов еще нет, то считаем, что данные на входе верные.
    x3 = -5; y3 = -4; x4 = -2; y4 = -1;                     // 4.19-ая по аналогии, только прибавить длины сторон.
    printf("\n4.18. 1st recatngle [%d..%d, %d..%d], 2nd rectangle [%d..%d, %d..%d].\n", x1, x2, y1, y2, x3, x4, y3, y4);
    a = (x1 <= x3) ? x1 : x3;
    b = (y1 <= y3) ? y1 : y3;
    c = (x2 >= x4) ? x2 : x4;
    d = (y2 >= y4) ? y2 : y4;
    printf("Minumum rectangle contains both is [%d..%d, %d..%d] area.\n", a, c, b, d);
    // Целочисленная арифметика и условный оператор.
    a = 12; b = 4; c = a / b; d = a % b;                    // Делители и цифры единиц и дестяков.
    printf("\n4.20-21. Numbers A = %d, B = %d, ", a, b);
    if (c == 0)
        printf("A is divided by B, result %d, no remainder.\n", c);
    else
        printf("A is not divided by B, result %d and remained %d.\n", c, d);
    a = 32;
    
    b = a / base; c = a % base;                             // Цифра единиц и цифра дестков.
    printf("\n4.22-4.25. Source number [0..99] is %d, left %d and right %d:\n", a, b, c);
    if (a % 2 == 0)
        printf("Number %d is even, reamainder of div by 2 is zero.\n", a);
    else
        printf("Number %d is odd, remainder of dib by 2 is 1.\n", a);
    if (b > c)
        printf("Left digit %d is more than right %d digit.\n", b, c);
    else if (b < c)
        printf("Left digit %d is less than right %d digit.\n", b, c);
    else
        printf("Left %d and right %d digits are eqaul.\n", b, c);
    d = (b * b * b) + (c * c * c);                          // Сумма кубов цифр.
    if (a * a == d)
        printf("Sum of digits power 3 is %d equal number power 2, %d.\n", d, a * a);
    else
        printf("Sum of digits power 3 is %d not equal number power 2, %d.\n", d, a * a);
    if (b + c >= base)
        printf("Sum of left and right digits %d is 2 digit number.\n", b + c);
    else
        printf("Sum of left and right digits %d is 1 digit number.\n", b + c);
    d = 5;
    if ((b + c) % d == 0)
        printf("Sum of left and right digits %d is divided by %d without remainder.\n", b + c, d);
    else
        printf("Sum of left and right digits %d is not divided by %d, remainder is %d.\n", b + c, d, (b + c) % d);
    a = 823;                                                // Вычисляем сотни, десятки и единицы в исходном числе.
    b = a / (base * base); c = (a / base) % base; d = a % base;
    printf("\n4.27-4.31. Source number %d and digits in order: %d-%d-%d:\n", a, b, c, d);
    if (b == d)
        printf("Yes, source number %d is polyndrome.\n", a);
    else
        printf("No, source number %d is not polyndrome.\n", a);
    if (b >= c && b >= d)
        printf("Maximum digit is first %d.\n", b);
    else if (c >= b && c >= d)
        printf("Maximum digit is second %d.\n", c);
    else if (d >= c && d >= d)
        printf("Maximum digit is third %d.\n", d);
    int sum = (b * b * b) + (c * c * c) + (d * d * d);      // Вспомогательная переменная по ходу исполнения.
    if (a * a == sum)
        printf("Sum of digits power 3 is %d equal number power 2 %d.\n", sum, a * a);
    else
        printf("Sum of digits power 3 is %d not equal number power 2 %d.\n", sum, a * a);
    sum = b + c + d;
    if (sum >= base && sum < base * base)
        printf("Yes, sum of digits %d in range [10..99].\n", sum);
    else 
        printf("No, sum of digits %d not in range [10..99].\n", sum);
    int mult = b * c * d;
    if (mult >= base * base && mult < base * base * base)
        printf("Yes, multiply of digits %d in range [100..999].\n", mult);
    else
        printf("No, multiply of digits %d not in range [100..999].\n", mult);
    if (mult > a)
        printf("Yes, multiply of digits %d is more than source number %d.\n", mult, a);
    else
        printf("No, multiply of digits %d is less or equal than source number %d.\n", mult, a);
    if (sum % 5 == 0)
        printf("Yes, sum of digits %d is divided by 5, no remainder.\n", sum);
    else
        printf("No, sum of digits %d is not divided by 5, remainder %d.\n", sum, sum % 5);
    if (b == c && b == d && c == d)
        printf("All digits in soruce number %d are equal.\n", a);
    else
        printf("Some digits different in source number %d.\n", a);
    if (b == c || c == d || b == d)
        printf("Some digits are equal in source number %d.\n", a);
    else
        printf("All digits are different in source number %d.\n", a);
    d = 5612;                                               // Дополнительное задание.
    int d1 = d / (base * base * base);                      // Тысячи.
    int d2 = d / (base * base) % base;                      // Сотни.
    int d3 = d / base % base;                               // Десятки.
    int d4 = d % base;                                      // Единицы.
    printf("\n4.32. Number %d, and its digits %d-%d-%d-%d:\n", d, d1, d2, d3, d4);
    if (d1 + d2 == d3 + d4)
        printf("A) Sum of first half of digits %d is equal other half of digits %d.\n", d1 + d2, d3 + d4);
    else
        printf("A) Sum of first half of digits %d is not equal other half of digits %d.\n", d1 + d2, d3 + d4);
    if ((d1 + d2 + d3 + d4) % 3 == 0)
        printf("B) Sum of digits %d is divided by 3.\n", d1 + d2 + d3 + d4);
    else
        printf("B) Sum of digits %d is not divided by 3.\n", d1 + d2 + d3 + d4);
    if ((d1 * d2 * d3 * d4) % 4 == 0)
        printf("C) Multiply of digits %d, is divided by 4.\n", d1 * d2 * d3 * d4);
    else
        printf("C) Multiply of digits %d, is not divided by 4.\n", d1 * d2 * d3 * d4);
    // Дополнительное задание на размещение, располагать прямоугольники в пространстве можно только в одном положении.
    // Т.е. комбинации размещения вертикально и горизонтально одновременно недопустимо. Раскладывается вплотную.
    a = 12; b = 8; c = 3; d = 4;
    printf("\n4.35. Table with sizes horizontal %d, vertical %d. And squares with sizes %d and %d, accordingly.\n", a, b, c, d);
    int hor = a / c, ver = b / d, area_h = hor * ver;
    printf("Using horizontal fill %d and vertical %d parts will placed on table, total %d.\n", hor, ver, area_h);
    hor = a / d; ver = b / c;
    int area_v = hor * ver;
    printf("Using vertical fill %d and horizontal %d parts will placed on table, total %d.\n", ver, hor, area_v);
    if (area_h > area_v)
        printf("Horizontal placed on table has more rectangles, total %d.\n", area_h);
    else if (area_h < area_v)
        printf("Vertical placed on table has more rectangles, total %d.\n", area_v);
    else
        printf("Both placing methods has equal rectangles %d.\n", area_h);
    a = 50; b = 3; c = 2;                                   // Можно добавить желтый цвет.
    printf("\n4.36. Time in minutes after hour(0..59). T = %d.\n", a);
    printf("Traffic light scheme in minutes from hour start: green - 3, red - 2:\n");
    d = a % (b + c);
    printf("Remainder of full cycle in %d minutes is %d.\n", a, d);
    if (d < b)
        printf("Light traffic color is green.\n");
    else
        printf("Light traffic color is red.\n");            // С желтым - еще один else-if.
    // Использование сложных условий.
    a = -5;                                                 // Число заведомо, не входящее  в интервал на случай огибки ввода.
    printf("\n4.37. Enter integer value: ");
    // scanf("%d", &a);                                     // Раскоментировать для ввода, дле теста оставить как есть.
    if (a > -5 && a < 3)
        printf("Yes, value %d is in range (-5, 3).\n", a);
    else
        printf("No, value %d is not in range (-5, 3).\n", a);
    a = 3; b = 3; c = -3; d = -3;                           // Координаты для вариантов А и Б соответственно.
    printf("\n4.38. Coordinates for variant A is (%d, %d) for B is (%d, %d), figure 4.4 in book:\n", a, b, c, d);
    if (a >= 3 && b >= 2)
        printf("A) Yes, point is in area [+3, +INF] and [+2, +INF].\n");
    else
        printf("B) No, point is outside area [+3, INF] and [+2, +INF].\n");
    if (c <= -2 && d <= -4)
        printf("B) Yes, point is in area [-INF, -2] and [-INF, -4].\n");
    else
        printf("B) No, point is outside area [-INF, -2] and [-INF, -4].\n");
    a = 3;                                                  // Три интервала смотрим в книге на рисунке.
    printf("\n4.39. Point coordinate (%d), only horizontal, figure 4.5 and three ranges in book:\n", a);
    if (a <= -1)
        printf("Point in first range [-INF, -1].\n");
    else if (a >= 5)
        printf("Point in third range [+5, +INF].\n");
    else
        printf("Point in second range (-1, +5).\n");
    e = 3.2;                                                // Переменная параметр, вещественное.
    if (e >= 2.4 && e <= 5.7)
        printf("\n4.40. Range [-2.4, 5.7], F(X) = X ^ 2 = %.2f ^ 2.0 = %.2f.\n", e, pow(e, 2.0));
    else
        printf("\n4.40. Range not in [-2.4, 5.7], F(X) = F(%.2f) = %.2f.\n", e, 4.0);
    e = 0.5;
    if (e > 0.2 && e < 0.9)
        printf("\n4.41. F(X) = SIN(X), if (0.2 <= X <= 0.9), else F(X) = 1. F(X) = F(%.2f) = %.2f.\n", e, sin(e));
    else
        printf("\n4.41. F(X) = SIN(X), if (0.2 <= X <= 0.9), else F(X) = 1. F(X) = F(%.2f) = %.2f.\n", e, 1.0);
    a = 3.0; b = 4.0; c = 5.0;
    printf("\n4.42. Is inequality correct:\n");
    if (b > a && b < c)
        printf("A) Yes inequality correct, %d < %d < %d.\n", a, b, c);
    else
        printf("A) No inequality is not correct, %d < %d < %d.\n", a, b, c);
    if (b > a && a > c)
        printf("B) Yes inequality correct, %d > %d > %d.\n", b, a, c);
    else
        printf("B) No inequality is not correct, %d > %d > %d.\n", b, a, c);
    a = 7; b = 12;                                          // Предусмотреть все варианты.
    if (a % b == 0 && b % a == 0)
        printf("\n4.43. A and B divived in any order: %d / %d = %d, remainder %d.\n", a, b, a / b, a % b);
    else if (a % b == 0)
        printf("\n4.43. A divided by B: %d / %d = %d, remainder %d.\n", a, b, a / b, a % b);
    else if (b % a == 0)
        printf("\n4.43. B divided by A: %d / %d = %d, remained %d.\n", b, a, b / a, b % a);
    else
        printf("\n4.43. A and B can't divided in any order without remainder: A mod B = %d mod %d = %d.\n", a, b, a % b);
    a = 8; b = 3; c = 2; d = 4;
    if (a % b == c || a % b == d)
        printf("\n4.44 Yes, number %d modulus %d is %d, equal %d or %d.\n", a, b, a % b, c, d);
    else
        printf("\n4.44 No, number %d modulus %d is %d, not equal %d or %d.\n", a, b, a % b, c, d);
    a = 3; b = 2; c = 2;
    if (a == b || a == c || b == c)
        printf("\n4.45 In numbers: %d - %d - %d at least one pair.\n", a, b, c);
    else
        printf("\n4.45 In numbers: %d - %d - %d no pairs founded.\n", a, b, c);
    a = 5; b = 5; c = 5;
    if (a == b && a == c && b == c)
        printf("\n4.46-47. Triangle with sides (%d, %d, %d) is equilateral.\n", a,b ,c);
    else if ((a == b && a == c) || (b == c && b == a) || (c == a && c == b))
        printf("\n4.46-47. Triangle with sides (%d, %d, %d) is isosceles.\n", a, b, c);
    else
        printf("\n4.46-47. Triangle with sides (%d, %d, %d) is triangle.\n", a, b, c);
    a = 5; b = 3; c = 4; d = 6;
    printf("\n4.50. Rectangle with sides %d-%d can fit in any direction in rectangle %d-%d: ", a, b, c, d);
    if ((a <= c && b <= d) || (a <= d && b <= c))
        printf("yes, rectangle can fit.\n");
    else
        printf("no, rectangle can't fit.\n");
    a = 3; b = 5; c = 4;                                    // Длины рёбер кирпича в трех измерениях.
    int side_x = 4, side_y = 2;                             // Размеры отверстия в стене.
    printf("\n4.53. Can brick with sides %d, %d, %d can fit into place with sizes %d, %d in any direction: ",
        a, b, c, side_x, side_y);
    if ((a <= side_x && b <= side_y) || (b <= side_x && c <= side_y) || (a <= side_x && c <= side_y) ||
        (a <= side_y && b <= side_x) || (b <= side_y && c <= side_x) || (a <= side_y && c <= side_x))
        printf("yes, the brick can fit into place.\n");     // Одно большое условие или по частям.
    else
        printf("no, the brick can't fit into place.\n");    // Также можно определить минимальные параметры и сравнивать их.
    a = b = 5261; d = 0;                                    // Исходное число и флаг нахождения.
    while (a > 0 && !d) {
        c = a % base;
        if (c % 3 == 0)
            d = 1;
        a /= base;
    }
    if (d == 1)
        printf("\n4.60. Yes, source number %d contain digit(s) 3, 6 or 9.\n", b);
    else
        printf("\n4.60. No, source number %d does not contain digit(s) 3, 6 or 9.\n", b);
    a = 3553; b = base * base * base; c = base * base;      // 4-ех значное число и делитель для старшего разряда.
    if ((a / b == a % base) && (a / c % base == a / base % base))
        printf("\n4.61. Number %d is polynomial.\n", a);
    else
        printf("\n4.61. Number %d is not polynomial.\n", a);
    a = 1224;                                               // Все цифры должны быть уникальны.
    printf("\n4.63. Digits in number %d: ", a);
    b = a / (base * base) % base;                           // Сотни.
    c = a / base % base;                                    // Десятки.
    d = a % base;                                           // Единицы.
    a = a / (base * base * base);                           // Тысячи.
    if (a != b && a != c && a != d && b != c && b != d && c != d)
        printf("%d, %d, %d, %d are unique.\n", a, b, c, d);
    else
        printf("%d, %d, %d, %d some or all are equal.\n", a, b, c, d);
    a = 2004;                                               // Високосный год.
    if ((a % 400 == 0) || (a % 4 == 0 && a % 100 != 0))
        printf("\n4.65. Year %d is leap year.\n", a);
    else
        printf("\n4.65. Year %d is not a leap year.\n", a);
    // Дополнительные задания сложностью чуть выше, использовать переменные со смысловой нагрузкой.
    int desk_x = 15, desk_y = 12, dom_x = 4, dom_y = 3, dom_z = 2;
    printf("\n4.66. Desk sides %d and %d. Each dominos sides X = %d, Y = %d and Z = %d.\n",
        desk_x, desk_y, dom_x, dom_y, dom_z);
    // Более краткий вариант с учётом данных о соотношении сторон.
    int area_xy = (desk_x / dom_x) * (desk_y / dom_y);
    int area_yx = (desk_x / dom_y) * (desk_y / dom_x);
    int area_xz = (desk_x / dom_x) * (desk_y / dom_z);
    int area_zx = (desk_x / dom_z) * (desk_y / dom_x);
    int area_zy = (desk_x / dom_z) * (desk_y / dom_y);
    int area_yz = (desk_x / dom_y) * (desk_y / dom_z);
    printf("Total dominoes areas: XY:%d, YX:%d, XZ:%d, ZX:%d, ZY:%d, YZ:%d.\n",
        area_xy, area_yx, area_xz, area_zx, area_zy, area_yz);
    if (area_xy >= area_yx && area_xy >= area_xz && area_xy >= area_zx && area_xy >= area_zy && area_xy >= area_yz)
        printf("Largest area of is XY, total %d dominoes.\n", area_xy);
    else if (area_yx >= area_xz && area_yx >= area_zx && area_yx >= area_zy && area_yx >= area_yz)
        printf("Largest area of is YX, total %d dominoes.\n", area_yx);
    else if (area_xz >= area_zx && area_xz >= area_zy && area_xz >= area_yz)
        printf("Largest area of is XZ, total %d dominoes.\n", area_xz);
    else if (area_zx >= area_zy && area_zx >= area_yz)
        printf("Largest area of is ZX, total %d dominoes.\n", area_zx);
    else if (area_zy >= area_yz)
        printf("Largest area of is ZY, total %d dominoes.\n", area_zy);
    else
        printf("Largest area of is YZ, total %d dominoes.\n", area_yz);
    const int days_per_week = 7, work_days = 5;             // С константами.
    a = 12; b = (a - 1) % days_per_week;                    // 
    printf("\n4.67. Day of year %d starts from 1-st january, monday. ", a);
    if (b < work_days)
        printf("It's a working day, %d.\n", b + 1);
    else
        printf("It's a weekend day, %d.\n", b + 1);
    const double grav_accel = 9.80665;
    double target_height = 5.0, target_size = 5.0, angle = pi / 6.0, speed = 27.5, distance = 50.0;
    printf("\n4.68. Figure 4.6, see book.\n");
    printf("Trajectory for bullet, speed V0 = %.2f m/s, G-accel = %.2f m/s^2, angle alpha = %.2f rad, height = %.2f m, "
           "size of target %.2f m, distance %.2f m.\n", speed, grav_accel, angle, target_height, target_size, distance);
    double time = distance / (speed * cos(angle));
    printf("Bullet time to fly distance %.2f, T = distance / (speed * cos(angle)) = %.2f.\n", distance, time);
    double traj_height = speed * time * sin(angle) - ((grav_accel * (time * time)) / 2);
    printf("Trajectory height is %.2f. ", traj_height);
    if (traj_height > target_height && traj_height < target_height + target_size)
        printf("Yes, bullet hit the target.\n");
    else if (traj_height < target_height)
        printf("Bullet is lower than target.\n");
    else
        printf("Bullet is upper than target.\n");
    int r_x1 = 3, r_y1 = 2, r_sx1 = 5, r_sy1 = 7, r_x2 = 3, r_y2 = 3, r_sx2 = 4, r_sy2 = 2;
    printf("\n4.69. First rectangle left-lower [%d, %d] and sizes [%d, %d]. Second left-lower [%d, %d] and sizes [%d, %d].\n",
        r_x1, r_y1, r_sx1, r_sy1, r_x2, r_y2, r_sx2, r_sy2);
    if (r_x1 >= r_x2 && (r_x1 + r_sx1) <= (r_x2 + r_sx2) && (r_y1 >= r_y2) &&  (r_y1 + r_sy1 <= r_y2 + r_sy2))
        printf("A) Yes, all points of first rectangle in second.\n");
    else
        printf("A) No, some or all points of first rectangle not in second.\n");
    if (((r_x1 >= r_x2) && (r_x1 + r_sx1 <= r_x2 + r_sx2) && (r_y1 >= r_y2) && (r_y1 + r_sy1 <= r_y2 + r_sy2)) ||
        ((r_x2 >= r_x1) && (r_x2 + r_sx2 <= r_x1 + r_sx1) && (r_y2 >= r_y1) && (r_y2 + r_sy2 <= r_y1 + r_sy1))) 
        printf("B) Yes, first or second rectangle is in each other.\n");
    else
        printf("B) No, none of rectangles contains each other.\n");
    // r_x1 = 5; r_y1 = 5; r_x2 = 1; r_y2 = 1; r_sx2 = 4; r_sy2 = 4;
    int is_rx = 0, is_ry = 0;                               // Вспомогательные флаги и тестовые параметры, второй ниже и левее первого.
    if (r_x1 <= r_x2) {
        if (r_x1 + r_sx1 >= r_x2)
            is_rx = 1;
    } else {                                                // Внимательнее со скобками.
        if (r_x2 + r_sx2 >= r_x1)
            is_rx = 1;
    }
    if (r_y1 <= r_y2) {
        if (r_y1 + r_sy1 >= r_y2)
            is_ry = 1;
    } else {
        if (r_y2 + r_sy2 >= r_y1)
            is_ry = 1;
    }
    if (is_rx && is_ry)
        printf("V) Yes, rectangles has common area.\n");
    else
        printf("V) No, rectangles has no common area.\n");

    
    return;
}   // 444, 28317. 

/*

    d1 = 3.2; d2 = 4.1;
    if (d1 >= d2)
        printf("\n4.70. A) First number %.2f more than second %.2f.\n", d1, d2);
    if (d1 >= d2)
        printf("\n4.70. A) First number %.2f less than second %.2f.\n", d1, d2);
    if (d1 >= d2)   // Likely error in book, or using goto. :)
        printf("\n4.70. B) First number %.2f more than second %.2f.\n", d1, d2);
    else
        printf("\n4.70. B) First number %.2f less than second %.2f.\n", d1, d2);
    d1 = 2.4; d2 = 3.2; d3 = 4.0;
    if (d1 >= d2 && d1 >= d3)
        printf("\n4.72. A) First number %.2f is more than others %.2f and %.2f.\n", d1, d2, d3);
    if (d2 >= d1 && d2 >= d3)
        printf("\n4.72. A) Second number %.2f is more than other %.2f and %.2f.\n", d2, d1, d3);
    if (d3 >= d1 && d3 >= d2)
        printf("\n4.72. A) Third number %.2f is more than other %.2f and %.2f.\n", d3, d1, d2);
    if (d1 <= d2 && d1 <= d3)
        printf("B) First number is %.2f is less than others %.2f and %.2f.\n", d1, d2, d3);
    if (d2 <= d1 && d2 <= d3)
        printf("B) Second number is %.2f is less than others %.2f and %.2f.\n", d2, d1, d3);
    if (d3 <= d1 && d3 <= d1)
        printf("B) Third number is %.2f is less than others %.2f and %.2f.\n", d3, d1, d2);
    d1 = -5.5;
    printf("\n4.74. Absolute value of %.2f is ", d1);
    if (d1 < 0)
        d1 *= -1;
    printf("%.2f.\n", d1);
    d1 = -4.5; d2 = 2.3;
    printf("\n4.76. Numbers %.2f and %.2f, ", d1, d2);
    if (fabs(d1) > d2) {
        d1 /= 2.0;
        printf("first absolute is more than second, half of first number is %.2f.\n", d1);
    } else
        printf("first absolute is less than second, nothing to do.\n");
    int e[3] = {3, -2, 5};
    printf("\n4.78-80. All elements in vector E[Index]: ");
    for (int i = 0; i < 3; ++i) {
        printf("%d", e[i]);
        if (e[i] % 2 == 0)
            printf(" is even");
        if (e[i] > 0)
            printf(" positive, in power 2 is %d", e[i] * e[i]);
        if (e[i] >= 1 && e[i] <= 3)
            printf(" in range [1..3]");
        if (e[i] >= 0 && e[i] <= 5)
            printf(" in range [0..5]");
        printf(". ");
    }
    a1 = -1;
    if (a1 < -1)
        printf("\n\n4.85. Function Y(X) = -1, if X < -1, X if X > -1, 1 if X = -1 = Y(%d) = %d.\n", a1, -1);
    else if (a1 > -1)
        printf("\n\n4.85. Function Y(X) = -1, if X < -1, X if X > -1, 1 if X = -1 = Y(%d) = %d.\n", a1, a1);
    else
        printf("\n\n4.85. Function Y(X) = -1, if X < -1, X if X > -1, 1 if X = -1 = Y(%d) = %d.\n", a1, 1);
    a1 = 1;
    if (a1 <= 0)
        printf("\n4.87. Function F(X) = 0, if X <= 0, X if 0 <= X <= 1, X^2 if other = F(%d) = %d.\n", a1, 0);
    else if (a1 > 0 && a1 <= 1)
        printf("\n4.87. Function F(X) = 0, if X <= 0, X if 0 <= X <= 1, X^2 if other = F(%d) = %d.\n", a1, a1);
    else
        printf("\n4.87. Function F(X) = 0, if X <= 0, X if 0 <= X <= 1, X^2 if other = F(%d) = %d.\n", a1, a1 * a1);
    printf("\n4.89. Function F(KX) = KX, if K < X, K + X, if K >= X. K(X) = X^2, if SIN(X) < 0, ABS(X) if SIN(X) >= 0.\n");
    d1 = 5.0; d2 = 4.5;
    if (sin(d2) < 0) {
        d1 = d2 * d2;
        printf("\tSIN(%.2f) negative, K pararameter is %.2f.\n", d2, d1);
    } else {
        d1 = fabs(d2);
        printf("\tSIN(%.2f) positive or zero, K pararameter is %.2f.\n", d2, d1);
    }
    if (d1 < d2)
        printf("\tK = %.2f, is less than X = %.2f, F(X) = K * X = %.2f * %.2f = %.2f.\n", d1, d2, d1, d2, d1 * d2);
    else
        printf("\tK = %.2f, is more or equal than X = %.2f, F(X) = K + X = %.2f + %.2f = %.2f.\n", d1, d2, d1, d2, d1 + d2);
    d1 = -3; d2 = 0.5; d3 = 1.5;
    if (d1 < -1)
        printf("\n4.91 A) See figure function in book. Y(X) = Y(%.2f) = %.2f.\n", d1, 0.0);
    else if (d1 >= -1 &&  d1 <= 1)
        printf("\n4.91 A) See figure function in book. Y(X) = Y(%.2f) = %.2f.\n", d1, d1);
    else
        printf("\n4.91 A) See figure function in book. Y(X) = Y(%.2f) = %.2f.\n", d1, 1.0);
    if (d2 < -1)
        printf("4.91 B) See figure function in book. Y(X) = Y(%.2f) = %.2f.\n", d2, 1.0);
    else if (d2 >= -1 && d2 <= 1)
        printf("4.91 B) See figure function in book. Y(X) = Y(%.2f) = %.2f.\n", d2, -1.0 * d2);
    else
        printf("4.91 B) See figure function in book. Y(X) = Y(%.2f) = %.2f.\n", d2, -1.0 * d2);
    if (d3 < -1)
        printf("4.91 C) See figure function in book. Y(X) = Y(%.2f) = %.2f.\n", d3, 1.0);
    else if (d3 >= -1 && d3 <= 1)
        printf("4.91 C) See figure function in book. Y(X) = Y(%.2f) = %.2f.\n", d3, 0.5 + d3);
    else
        printf("4.91 C) See figure function in book. Y(X) = Y(%.2f) = %.2f.\n", d3, 1.0);
    a1 = 1;
    if (a1 == 3)
        printf("\n4.94. Score at football match is %d, it's victory.\n", a1);
    else if (a1 == 1)
        printf("\n4.94. Score at football match is %d, it's even.\n", a1);
    else
        printf("\n4.94. Score at football match is %d, it's lose.\n", a1);
    d1 = 1.0; d2 = 3.0; d3 = 1; d4 = 0.01;
    printf("\n4.96. A * X^2 + B * X + C = 0. %.1f * X^2 + %.1f * X + %.1f.\n", d1, d2, d3);
    d5 = (d2 * d2) - 4 * d1 * d3;
    if (fabs(d5) <= d4) {
        double x = -1 * d2 / 2 * d1;
        printf("Discriminant = %.2f, result = %.2f.\n", d5, x);
    } else if (d5 > d4) {
        double x1 = (-1 * d2 + d5) / (2 * d1), x2 = (-1 * d2 - d5) / (2 * d1);
        printf("Discriminant = %.2f, first result = %.2f, second result = %.2f.\n", d5, x1, x2);
    } else
        printf("Discriminant = %.2f, less than zero, no results.\n", d5);
    d1 = 5.0; d2 = 3.5; d3 = -2.1; d4 = 0.0; d5 = 0.0;
    printf("\n4.98. Values %.2f, %.2f, %.2f, ", d1, d2, d3);
    if (d1 >= d2 && d1 >= d3)
        printf("maximum is %.2f, ", d1);
    else if (d2 >= d1 && d2 >= d3)
        printf("maximum is %.2f, ", d2);
    else
        printf("maximum is %.2f, ", d3);
    if (d1 < d2 && d1 < d3)
        printf("minimum is %.2f.\n", d1);
    else if (d2 < d1 && d2 < d3)
        printf("minimum is %.2f.\n", d2);
    else
        printf("minimum is %.2f.\n", d1);
    d1 = 1.5; d2 = 2.5; d3 = 3.1;
    printf("\n4.100. Values %.2f, %.2f, %.2f. ", d1, d2, d3);
    if (d1 >= d2 && d1 >= d3)
        printf("%.2f and %.2f less than %.2f, multiply is %.2f.\n", d2, d3, d1, d2 * d3);
    else if (d2 >= d1 && d2 >= d3)
        printf("%.2f and %.2f less than %.2f, multiply is %.2f.\n", d1, d3, d2, d1 * d3);
    else
        printf("%.2f and %.2f less than %.2f, multiply is %.2f.\n", d1, d2, d3, d1 * d2);
    a1 = -3; a2 = 5;
    printf("\n4.102. One quarter of 2D dimension, coordinates X = %d, Y = %d, ", a1, a2);
    if (a1 >= 0 && a2 >= 0)
        printf("first quarter.\n");
    else if (a1 >= 0 && a2 <= 0)
        printf("second quarter.\n");
    else if (a1 <= 0 &&  a2 <= 0)
        printf("third quarter.\n");
    else
        printf("fourth quarter.\n");
    a1 = 3; a2 = 10;
    printf("\n4.100. Card indexes %d for suit and %d for value is '", a1, a2);
    switch (a2) {
    case 6:
        printf("Six of ");
        break;
    case 7:
        printf("Seven of ");
        break;
    case 8:
        printf("Eight of ");
        break;
    case 9:
        printf("Nine of ");
        break;
    case 10:
        printf("Ten of ");
        break;
    case 11:
        printf("Jack of ");
        break;
    case 12:
        printf("Queen of ");
        break;
    case 13:
        printf("King of ");
        break;
    case 14:
        printf("Ace of ");
        break;
    default:
        printf("Error, index value must be in [6..14] range. ");
    }
    switch (a1) {
    case 1:
        printf("Pikes'.\n");
        break;
    case 2:
        printf("Clovers'.\n");
        break;
    case 3:
        printf("Tiles'.\n");
        break;
    case 4:
        printf("Hearts'.\n");
        break;
    default:
        printf("Error, index of suit must be in [1..4] range.'\n");
    }
    a1 = 4; a2 = 3;
    printf("\n4.111. A) If K = %d, day and 1-st january is monday, then K-day is ", a1);
    switch ((a1 - 1) % 7) {
    case 0:
        printf("monday.\n");
        break;
    case 1:
        printf("tuesday.\n");
        break;
    case 2:
        printf("wednesday.\n");
        break;
    case 3:
        printf("thursday.\n");
        break;
    case 4:
        printf("friday.\n");
        break;
    case 5:
        printf("saturday.\n");
        break;
    case 6:
        printf("sunday.\n");
        break;
    default:
        printf("something goes very wrong, parameter must be in [0..6] range.\n");
    }
    printf("\n4.111. B) IF K = %d, day and 1-st january is %d-day, then K-day is ", a1, a2);
    switch ((a1 + a2 - 1) % 7) {
    case 0:
        printf("monday.\n");
        break;
    case 1:
        printf("tuesday.\n");
        break;
    case 2:
        printf("wednesday.\n");
        break;
    case 3:
        printf("thursday.\n");
        break;
    case 4:
        printf("friday.\n");
        break;
    case 5:
        printf("saturday.\n");
        break;
    case 6:
        printf("sunday.\n");
        break;
    default:
        printf("something goes very wrong, parameter must be in [0..6] range.\n");
    }
    a1 = 3; a2 = 4; a3 = 5; b1 = 8; b2 = 9;
    int n1 = a3 * 100 + a2 * 10 + a1, n2 = b2 * 10 + b1;
    int n3 = n1 + n2;
    int m1 = a1 + b1;
    int m2 = (a2 + b2) + (m1 / 10);
    int m3 = a3 + m2 / 10;
    int r = m3 + m2 % 10 + m1 % 10;
    printf("\n4.118. Summ of digits for AAA + BB = NNN, %d%d%d + %d%d = %d, = %d.\n",a3, a2 ,a1, b2, b1, n3, r);
    int v1 = 2, v2 = 3, h1 = 3, h2 = 4;
    r = (v1 == v2) || (h1 == h2);
    printf("\n4.119a. Rook at [%d,%d] is dangerous for pawn at [%d,%d] = %d.\n",v1, h1 ,v2 ,h2, r);
    r = abs(v1 - v2) == abs(h1 - h2);
    printf("\n4.119b. Bishop at [%d,%d] is dangerous for pawn at [%d,%d] = %d.\n", v1, h1, v2, h2, r);
    r = (abs(v1 - v2) == 1) && (abs(h1 - h2) == 1);
    printf("\n4.119c. King at [%d,%d] can move to [%d,%d] = %d.\n", v1, h1, v2, h2, r);
    d1 = 3.0; d2 = 4.0; d3 = 5.0;
    double delta = 0.001;
    if ((d1 / d3) - 1 < delta)
            printf("\n4.124a. Triangle with catets %.2f,%.2f and hyp %.2f is rectangular.\n", d1, d2, d3);
    else
        if (d1 / d3 < 1.0 && d2 / d3 < 1.0)
            printf("\n4.124a. Triangle with sizes (%.2f,%.2f,%.2f) is oxygon.\n", d1, d2, d3);
    else
            printf("\n4.124a. Triangle with sizes (%.2f,%.2f,%.2f) is obtuse.\n", d1, d2, d3);
    printf("\n4.125. Age and names form: ");
    for (int n = 1; n < 30; ++n)
        if (n % 10 == 1 && n != 11)
            printf("%d god, ", n);
    else if (n % 10 > 1 && n % 10 < 5 && !(n >= 10 && n <= 20))
            printf("%d goda, ", n);
    else
            printf("%d let, ", n);
    printf("\n");
    n1 = 25;
    n2 = n1 / 12;
    n3 = n1 % 12;

    printf("\n4.128. Age in months %d, it's %d years and %d months.\n", n1, n2, n3);
    a1 = 10; b1 = 30; a2 = 12; b2 = 15; n1 = 12; m1 = 0;
    printf("\n4.132. Train arrived at %2d:%2d and departs at %2d:%2d, passanger time %2d:%2d, ", a1, b1, a2, b2, n1, m1);
    if ((n1 == a1 && m1 >= b1) || (n1 == a2 && m1 <= b2)) {
        printf("in minutes, yes, train at platform.\n");
    } else if (n1 > a1 && n1 < a2)
        printf("in hours, yes, train at platform.\n");
    else
        printf("no train at platform.\n");
    enum Months { January = 1, February, March, April, May, June, July, August, September, October, November, December };
    const int months_in_year = 12;
    const int days_in_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int y = 2020, m = 2, d = 28, y_prev = 0, m_prev = 0, d_prev = 0, y_next = 0, m_next = 0, d_next = 0;
    printf("\n4.134. Year %d, month %d and day %d. ", y, m, d);
    int diff;
    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
        printf("Leap year, using delta = 1.\n");
        diff = 1;
    } else {
        printf("Not a leap year, using delta = 0.\n");
        diff = 0;
    }
    // Better IF expression, using 'days' array, "if (d < days_in_month[m]))...". Using 'days' only for consts.
    d_prev = d - 1; d_next = d + 1;     // Better in if-else statesments, but default (else) here.
    m_prev = m_next = m;                // If not changing, then as current date.
    y_prev = y_next = y;
    if (d == 1) {
        if (m == March)
            d_prev = days_in_month[February] + diff;
        else if ((m == May || m == July || m == October || m == December))
            d_prev = days_in_month[April]; // Or any other 30 day, or better constant with name.
        else
            d_prev = days_in_month[March];    // 31 day.
        // Only if January, then first expression divided will be 1, second will 0. Or just use IF. ;)
        printf("Day was 1, switch to previos month.\n");
        m_prev = ((months_in_year - (m - 1)) / months_in_year) * months_in_year + (m - 1);
        if (m == 1) {
            printf("Month was January, switch to previous year.\n");
            y_prev = y - 1;
            if (y_prev == 0) {
                printf("Changing year scale to BC.\n");
                y_prev = - 1;
            }
        }
    } else {    // One IF possible, other way.
        int l1 = (m == February && d == days_in_month[February] + diff);
        int l2 = ((m == April || m == June || m == September || m == November) && d == days_in_month[April]);
        int l3 = (d == days_in_month[January]); // Any of 31-day month.
        if (l1 || l2 || l3) {
            d_next = 1;
            // (++(m - 1)) % 12 + 1. Next month index, and increment after modulus, as months starts from 1 = January.
            printf("Day was last in month, switch to next.\n");
            m_next = (m % months_in_year) + 1;
            if (m == 12) {
                printf("Month was december, switch to next year.\n");
                y_next = y + 1;
                if (y_next == 0) {
                    printf("Changing year scale to AD.\n");
                    y_next = 1;
                }
            }
        }
    }
    printf("\nPrevious date year %d ", abs(y_prev));
    if (y_prev > 0)
        printf("A.D., ");
    else
        printf("B.C., ");
    printf("month %d, day %d.\n", m_prev, d_prev);
    printf("Next date year %d ", abs(y_next));
    if (y_next > 0)
        printf("A.D., ");
    else
        printf("B.C., ");
    printf("month %d, day %d.\n", m_next, d_next);

    n1 = 18;
    printf("\n4.135. Semaphore lighting scheme G-Y-R = 3-1-2 minutes, at %d minute color is ", n1);
    n2 = n1 % (3 + 1 + 2);
    if (n2 >= 4)
        printf("red.\n");
    else if (n2 >= 3)
        printf("yellow.\n");
    else
        printf("green.\n");
    a1 = 5;
    printf("\n4.140. Sequence 1-2..-9..10-11-..-99..100-101-...-110 the element %d is ", a1);
    if (a1 > 1 && a1 < 10)
        r = a1;
    else if (a1 >= 10 && a1 <= 187) {
        if (a1 % 2 == 0)
            r = (a1-10) / 20 + 1;
        else
            r = ((a1 - 10) % 20) / 2;
    } else if (a1 >= 188 &&  a1 <= 222) {
        a1 = a1 - 188;
        if (a1 % 3 == 0)
            r = 1;
        else if (a1 % 3 == 1)
            r = a1 / 30;
        else
            r = a1 / 3;
    }
    printf("%d.\n", a1);
    */

/*

void task_4_120(void)
{   // Задание на шахматы, классика по правилам, после объединить с четвертой главой в основном репозитории.
    // Все позиции по умолчанию верны относительно размеров доски и положительны.
    int a = 2, b = 2;   // Расположение первой фигуры.
    int c = 5, d = 6;   // Расположение второй фигуры.
    int e = 2, f = 6;   // Позиция хода первой фигуры.
    printf("Classic chess, positions of figures as vertical and horizontal.\n");
    printf("b) Moving Rook from %d:%d to %d:%d, threat from Queen at %d:%d.\n", a, b, e, f, c, d);
    if ((a == e) || (b == f)) {
        printf("Move Rook is correct and ");
        if ((c == e) || (d == f) || (abs(c - e) == abs(d - f)))
            printf("under threat of Queen.\n");
        else
            printf("it's safe from Queen.\n");
    } else
        printf("Move Rook is incorrect.\n");
    a = 2; b = 2; c = 7; d = 7; e = 5; f = 5;
    printf("z) Moving Queen from %d:%d to %d:%d, threat from Bishop at %d:%d.\n", a, b, e, f, c, d);
    if ((abs(a - e) == abs(b - f)) || ((a == e) || (b == f))) {
        printf("Move Queen is correct and ");
        if ((abs(c - e) == abs(d - f)))
            printf("under threat of Bishop.\n");
        else
            printf("it's safe from Bishop.\n");
    } else
        printf("Move Queen is incorrect.\n");
    a = 3; b = 3; c = 6; d = 7; e = 4; f = 5;
    printf("k) Moving Knight from %d:%d to %d:%d, threat from Rook at %d:%d.\n", a, b, e, f, c, d);
    if ((abs(a - e) == 1 && abs(b - f) == 2) || (abs(a - e) == 2 && abs(b - f)) == 1) {
        printf("Move Knight is correct and ");
        if (c == e  || d == f)
            printf("under threat of Rook.\n");
        else
            printf("it's safe from Rook.\n");
    } else
        printf("Move Knight is incorrect.\n");
    a = 3; b = 3; c = 6; d = 5; e = 5; f = 5;
    printf("u) Moving King from %d:%d to %d:%d, threat from Knight at %d:%d.\n", a, b, e, f, c, d);
    if (abs(a - e) <= 1 && abs(b - f) <= 1) {
        printf("Move King is correct and ");
        if ((abs(c - e) == 1 && abs(d - f) == 2) || (abs(c - e) == 2 && abs(d - f)) == 1)
            printf("under threat of Knight.\n");
        else
            printf("it's safe from Knight.\n");
    } else
        printf("Move King is incorrect.\n");
}

void part_4(void)
{
    d1 = 3.2; d2 = 4.1;
    if (d1 >= d2)
        printf("\n4.70. A) First number %.2f more than second %.2f.\n", d1, d2);
    if (d1 <= d2)
        printf("\n4.70. A) First number %.2f less than second %.2f.\n", d1, d2);
    if (d1 >= d2)   // Likely error in book, or using goto. :) Using printf.
        printf("\n4.70. B) First number %.2f more than second %.2f.\n", d1, d2);
    else
        printf("\n4.70. B) First number %.2f less than second %.2f.\n", d1, d2);
    d1 = 2.4; d2 = 3.2; d3 = 4.0;
    if (d1 >= d2 && d1 >= d3)
        printf("\n4.72. A) First number %.2f is more than others %.2f and %.2f.\n", d1, d2, d3);
    if (d2 >= d1 && d2 >= d3)
        printf("\n4.72. A) Second number %.2f is more than other %.2f and %.2f.\n", d2, d1, d3);
    if (d3 >= d1 && d3 >= d2)
        printf("\n4.72. A) Third number %.2f is more than other %.2f and %.2f.\n", d3, d1, d2);
    if (d1 <= d2 && d1 <= d3)
        printf("B) First number is %.2f is less than others %.2f and %.2f.\n", d1, d2, d3);
    if (d2 <= d1 && d2 <= d3)
        printf("B) Second number is %.2f is less than others %.2f and %.2f.\n", d2, d1, d3);
    if (d3 <= d1 && d3 <= d1)
        printf("B) Third number is %.2f is less than others %.2f and %.2f.\n", d3, d1, d2);
    d1 = -5.5;
    printf("\n4.74. Absolute value of %.2f is ", d1);
    if (d1 < 0)
        d1 *= -1;
    printf("%.2f.\n", d1);
    d1 = -4.5; d2 = 2.3;
    printf("\n4.76. Numbers %.2f and %.2f, ", d1, d2);
    if (fabs(d1) > d2) {
        d1 /= 2.0;
        printf("first absolute is more than second, half of first number is %.2f.\n", d1);
    } else
        printf("first absolute is less than second, nothing to do.\n");
    int e[3] = {3, -2, 5};
    printf("\n4.78-80. All elements in vector E[Index]: ");
    for (int i = 0; i < 3; ++i) {
        printf("%d", e[i]);
        if (e[i] % 2 == 0)
            printf(" is even");
        if (e[i] > 0)
            printf(" positive, in power 2 is %d", e[i] * e[i]);
        if (e[i] >= 1 && e[i] <= 3)
            printf(" in range [1..3]");
        if (e[i] >= 0 && e[i] <= 5)
            printf(" in range [0..5]");
        printf(". ");
    }
    a1 = -1;
    if (a1 < -1)
        printf("\n\n4.85. Function Y(X) = -1, if X < -1, X if X > -1, 1 if X = -1 = Y(%d) = %d.\n", a1, -1);
    else if (a1 > -1)
        printf("\n\n4.85. Function Y(X) = -1, if X < -1, X if X > -1, 1 if X = -1 = Y(%d) = %d.\n", a1, a1);
    else
        printf("\n\n4.85. Function Y(X) = -1, if X < -1, X if X > -1, 1 if X = -1 = Y(%d) = %d.\n", a1, 1);
    a1 = 1;
    if (a1 <= 0)
        printf("\n4.87. Function F(X) = 0, if X <= 0, X if 0 <= X <= 1, X^2 if other = F(%d) = %d.\n", a1, 0);
    else if (a1 > 0 && a1 <= 1)
        printf("\n4.87. Function F(X) = 0, if X <= 0, X if 0 <= X <= 1, X^2 if other = F(%d) = %d.\n", a1, a1);
    else
        printf("\n4.87. Function F(X) = 0, if X <= 0, X if 0 <= X <= 1, X^2 if other = F(%d) = %d.\n", a1, a1 * a1);
    printf("\n4.89. Function F(KX) = KX, if K < X, K + X, if K >= X. K(X) = X^2, if SIN(X) < 0, ABS(X) if SIN(X) >= 0.\n");
    d1 = 5.0; d2 = 4.5;
    if (sin(d2) < 0) {
        d1 = d2 * d2;
        printf("\tSIN(%.2f) negative, K pararameter is %.2f.\n", d2, d1);
    } else {
        d1 = fabs(d2);
        printf("\tSIN(%.2f) positive or zero, K pararameter is %.2f.\n", d2, d1);
    }
    if (d1 < d2)
        printf("\tK = %.2f, is less than X = %.2f, F(X) = K * X = %.2f * %.2f = %.2f.\n", d1, d2, d1, d2, d1 * d2);
    else
        printf("\tK = %.2f, is more or equal than X = %.2f, F(X) = K + X = %.2f + %.2f = %.2f.\n", d1, d2, d1, d2, d1 + d2);
    d1 = -3; d2 = 0.5; d3 = 1.5;
    if (d1 < -1)
        printf("\n4.91 A) See figure function in book. Y(X) = Y(%.2f) = %.2f.\n", d1, 0.0);
    else if (d1 >= -1 &&  d1 <= 1)
        printf("\n4.91 A) See figure function in book. Y(X) = Y(%.2f) = %.2f.\n", d1, d1);
    else
        printf("\n4.91 A) See figure function in book. Y(X) = Y(%.2f) = %.2f.\n", d1, 1.0);
    if (d2 < -1)
        printf("4.91 B) See figure function in book. Y(X) = Y(%.2f) = %.2f.\n", d2, 1.0);
    else if (d2 >= -1 && d2 <= 1)
        printf("4.91 B) See figure function in book. Y(X) = Y(%.2f) = %.2f.\n", d2, -1.0 * d2);
    else
        printf("4.91 B) See figure function in book. Y(X) = Y(%.2f) = %.2f.\n", d2, -1.0 * d2);
    if (d3 < -1)
        printf("4.91 C) See figure function in book. Y(X) = Y(%.2f) = %.2f.\n", d3, 1.0);
    else if (d3 >= -1 && d3 <= 1)
        printf("4.91 C) See figure function in book. Y(X) = Y(%.2f) = %.2f.\n", d3, 0.5 + d3);
    else
        printf("4.91 C) See figure function in book. Y(X) = Y(%.2f) = %.2f.\n", d3, 1.0);
    a1 = 1;
    if (a1 == 3)
        printf("\n4.94. Score at football match is %d, it's victory.\n", a1);
    else if (a1 == 1)
        printf("\n4.94. Score at football match is %d, it's even.\n", a1);
    else
        printf("\n4.94. Score at football match is %d, it's lose.\n", a1);
    d1 = 1.0; d2 = 3.0; d3 = 1; d4 = 0.01;
    printf("\n4.96. A * X^2 + B * X + C = 0. %.1f * X^2 + %.1f * X + %.1f.\n", d1, d2, d3);
    d5 = (d2 * d2) - 4 * d1 * d3;
    if (fabs(d5) <= d4) {
        double x = -1 * d2 / 2 * d1;
        printf("Discriminant = %.2f, result = %.2f.\n", d5, x);
    } else if (d5 > d4) {
        double x1 = (-1 * d2 + d5) / (2 * d1), x2 = (-1 * d2 - d5) / (2 * d1);
        printf("Discriminant = %.2f, first result = %.2f, second result = %.2f.\n", d5, x1, x2);
    } else
        printf("Discriminant = %.2f, less than zero, no results.\n", d5);
    d1 = 5.0; d2 = 3.5; d3 = -2.1; d4 = 0.0; d5 = 0.0;
    printf("\n4.98. Values %.2f, %.2f, %.2f, ", d1, d2, d3);
    if (d1 >= d2 && d1 >= d3)
        printf("maximum is %.2f, ", d1);
    else if (d2 >= d1 && d2 >= d3)
        printf("maximum is %.2f, ", d2);
    else
        printf("maximum is %.2f, ", d3);
    if (d1 < d2 && d1 < d3)
        printf("minimum is %.2f.\n", d1);
    else if (d2 < d1 && d2 < d3)
        printf("minimum is %.2f.\n", d2);
    else
        printf("minimum is %.2f.\n", d1);
    d1 = 1.5; d2 = 2.5; d3 = 3.1;
    printf("\n4.100. Values %.2f, %.2f, %.2f. ", d1, d2, d3);
    if (d1 >= d2 && d1 >= d3)
        printf("%.2f and %.2f less than %.2f, multiply is %.2f.\n", d2, d3, d1, d2 * d3);
    else if (d2 >= d1 && d2 >= d3)
        printf("%.2f and %.2f less than %.2f, multiply is %.2f.\n", d1, d3, d2, d1 * d3);
    else
        printf("%.2f and %.2f less than %.2f, multiply is %.2f.\n", d1, d2, d3, d1 * d2);
    a1 = -3; a2 = 5;
    printf("\n4.102. One quarter of 2D dimension, coordinates X = %d, Y = %d, ", a1, a2);
    if (a1 >= 0 && a2 >= 0)
        printf("first quarter.\n");
    else if (a1 >= 0 && a2 <= 0)
        printf("second quarter.\n");
    else if (a1 <= 0 &&  a2 <= 0)
        printf("third quarter.\n");
    else
        printf("fourth quarter.\n");
    a1 = 3; a2 = 10;
    printf("\n4.100. Card indexes %d for suit and %d for value is '", a1, a2);
    switch (a2) {
    case 6:
        printf("Six of ");
        break;
    case 7:
        printf("Seven of ");
        break;
    case 8:
        printf("Eight of ");
        break;
    case 9:
        printf("Nine of ");
        break;
    case 10:
        printf("Ten of ");
        break;
    case 11:
        printf("Jack of ");
        break;
    case 12:
        printf("Queen of ");
        break;
    case 13:
        printf("King of ");
        break;
    case 14:
        printf("Ace of ");
        break;
    default:
        printf("Error, index value must be in [6..14] range. ");
    }
    switch (a1) {
    case 1:
        printf("Pikes'.\n");
        break;
    case 2:
        printf("Clovers'.\n");
        break;
    case 3:
        printf("Tiles'.\n");
        break;
    case 4:
        printf("Hearts'.\n");
        break;
    default:
        printf("Error, index of suit must be in [1..4] range.'\n");
    }
    a1 = 4; a2 = 3;
    printf("\n4.111. A) If K = %d, day and 1-st january is monday, then K-day is ", a1);
    switch ((a1 - 1) % 7) {
    case 0:
        printf("monday.\n");
        break;
    case 1:
        printf("tuesday.\n");
        break;
    case 2:
        printf("wednesday.\n");
        break;
    case 3:
        printf("thursday.\n");
        break;
    case 4:
        printf("friday.\n");
        break;
    case 5:
        printf("saturday.\n");
        break;
    case 6:
        printf("sunday.\n");
        break;
    default:
        printf("something goes very wrong, parameter must be in [0..6] range.\n");
    }
    printf("\n4.111. B) IF K = %d, day and 1-st january is %d-day, then K-day is ", a1, a2);
    switch ((a1 + a2 - 1) % 7) {
    case 0:
        printf("monday.\n");
        break;
    case 1:
        printf("tuesday.\n");
        break;
    case 2:
        printf("wednesday.\n");
        break;
    case 3:
        printf("thursday.\n");
        break;
    case 4:
        printf("friday.\n");
        break;
    case 5:
        printf("saturday.\n");
        break;
    case 6:
        printf("sunday.\n");
        break;
    default:
        printf("something goes very wrong, parameter must be in [0..6] range.\n");
    }
    a1 = 3; a2 = 4; a3 = 5; b1 = 8; b2 = 9;
    int n1 = a3 * 100 + a2 * 10 + a1, n2 = b2 * 10 + b1;
    int n3 = n1 + n2;
    int m1 = a1 + b1;
    int m2 = (a2 + b2) + (m1 / 10);
    int m3 = a3 + m2 / 10;
    int r = m3 + m2 % 10 + m1 % 10;
    printf("\n4.118. Summ of digits for AAA + BB = NNN, %d%d%d + %d%d = %d, = %d.\n",a3, a2 ,a1, b2, b1, n3, r);
    int v1 = 2, v2 = 3, h1 = 3, h2 = 4;
    r = (v1 == v2) || (h1 == h2);
    printf("\n4.119a. Rook at [%d,%d] is dangerous for pawn at [%d,%d] = %d.\n",v1, h1 ,v2 ,h2, r);
    r = abs(v1 - v2) == abs(h1 - h2);
    printf("\n4.119b. Bishop at [%d,%d] is dangerous for pawn at [%d,%d] = %d.\n", v1, h1, v2, h2, r);
    r = (abs(v1 - v2) == 1) && (abs(h1 - h2) == 1);
    printf("\n4.119c. King at [%d,%d] can move to [%d,%d] = %d.\n", v1, h1, v2, h2, r);
    d1 = 3.0; d2 = 4.0; d3 = 5.0;
    double delta = 0.001;
    if ((d1 / d3) - 1 < delta)
            printf("\n4.124a. Triangle with catets %.2f,%.2f and hyp %.2f is rectangular.\n", d1, d2, d3);
    else
        if (d1 / d3 < 1.0 && d2 / d3 < 1.0)
            printf("\n4.124a. Triangle with sizes (%.2f,%.2f,%.2f) is oxygon.\n", d1, d2, d3);
    else
            printf("\n4.124a. Triangle with sizes (%.2f,%.2f,%.2f) is obtuse.\n", d1, d2, d3);
    printf("\n4.125. Age and names form: ");
    for (int n = 1; n < 30; ++n)
        if (n % 10 == 1 && n != 11)
            printf("%d god, ", n);
    else if (n % 10 > 1 && n % 10 < 5 && !(n >= 10 && n <= 20))
            printf("%d goda, ", n);
    else
            printf("%d let, ", n);
    printf("\n");
    n1 = 25;
    n2 = n1 / 12;
    n3 = n1 % 12;
    printf("\n4.128. Age in months %d, it's %d years and %d months.\n", n1, n2, n3);
    a1 = 10; b1 = 30; a2 = 12; b2 = 15; n1 = 12; m1 = 0;
    printf("\n4.132. Train arrived at %2d:%2d and departs at %2d:%2d, passanger time %2d:%2d, ", a1, b1, a2, b2, n1, m1);
    if ((n1 == a1 && m1 >= b1) || (n1 == a2 && m1 <= b2)) {
        printf("in minutes, yes, train at platform.\n");
    } else if (n1 > a1 && n1 < a2)
        printf("in hours, yes, train at platform.\n");
    else
        printf("no train at platform.\n");
    enum Months { January = 1, February, March, April, May, June, July, August, September, October, November, December };
    const int months_in_year = 12;
    const int days_in_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int y = 2020, m = 2, d = 28, y_prev = 0, m_prev = 0, d_prev = 0, y_next = 0, m_next = 0, d_next = 0;
    printf("\n4.134. Year %d, month %d and day %d. ", y, m, d);
    int diff;
    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
        printf("Leap year, using delta = 1.\n");
        diff = 1;
    } else {
        printf("Not a leap year, using delta = 0.\n");
        diff = 0;
    }
    // Better IF expression, using 'days' array, "if (d < days_in_month[m]))...". Using 'days' only for consts.
    d_prev = d - 1; d_next = d + 1;     // Better in if-else statesments, but default (else) here.
    m_prev = m_next = m;                // If not changing, then as current date.
    y_prev = y_next = y;
    if (d == 1) {
        if (m == March)
            d_prev = days_in_month[February] + diff;
        else if ((m == May || m == July || m == October || m == December))
            d_prev = days_in_month[April]; // Or any other 30 day, or better constant with name.
        else
            d_prev = days_in_month[March];    // 31 day.
        // Only if January, then first expression divided will be 1, second will 0. Or just use IF. ;)
        printf("Day was 1, switch to previos month.\n");
        m_prev = ((months_in_year - (m - 1)) / months_in_year) * months_in_year + (m - 1);
        if (m == 1) {
            printf("Month was January, switch to previous year.\n");
            y_prev = y - 1;
            if (y_prev == 0) {
                printf("Changing year scale to BC.\n");
                y_prev = - 1;
            }
        }
    } else {    // One IF possible, other way.
        int l1 = (m == February && d == days_in_month[February] + diff);
        int l2 = ((m == April || m == June || m == September || m == November) && d == days_in_month[April]);
        int l3 = (d == days_in_month[January]); // Any of 31-day month.
        if (l1 || l2 || l3) {
            d_next = 1;
            // (++(m - 1)) % 12 + 1. Next month index, and increment after modulus, as months starts from 1 = January.
            printf("Day was last in month, switch to next.\n");
            m_next = (m % months_in_year) + 1;
            if (m == 12) {
                printf("Month was december, switch to next year.\n");
                y_next = y + 1;
                if (y_next == 0) {
                    printf("Changing year scale to AD.\n");
                    y_next = 1;
                }
            }
        }
    }
    printf("\nPrevious date year %d ", abs(y_prev));
    if (y_prev > 0)
        printf("A.D., ");
    else
        printf("B.C., ");
    printf("month %d, day %d.\n", m_prev, d_prev);
    printf("Next date year %d ", abs(y_next));
    if (y_next > 0)
        printf("A.D., ");
    else
        printf("B.C., ");
    printf("month %d, day %d.\n", m_next, d_next);

    n1 = 18;
    printf("\n4.135. Semaphore lighting scheme G-Y-R = 3-1-2 minutes, at %d minute color is ", n1);
    n2 = n1 % (3 + 1 + 2);
    if (n2 >= 4)
        printf("red.\n");
    else if (n2 >= 3)
        printf("yellow.\n");
    else
        printf("green.\n");
    a1 = 5;
    printf("\n4.140. Sequence 1-2..-9..10-11-..-99..100-101-...-110 the element %d is ", a1);
    if (a1 > 1 && a1 < 10)
        r = a1;
    else if (a1 >= 10 && a1 <= 187) {
        if (a1 % 2 == 0)
            r = (a1-10) / 20 + 1;
        else
            r = ((a1 - 10) % 20) / 2;
    } else if (a1 >= 188 &&  a1 <= 222) {
        a1 = a1 - 188;
        if (a1 % 3 == 0)
            r = 1;
        else if (a1 % 3 == 1)
            r = a1 / 30;
        else
            r = a1 / 3;
    }
    printf("%d.\n", a1);
}

*/
