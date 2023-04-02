#include <stdio.h>
#include <math.h>

#include "library.h"

void labs_02(void)
{   // Глава 2. Целочисленная арифметика.
    printf("Part 2. Integer Arithmetic.\n");                                    // Простейшие задачи.
    const int sm_in_meters = 100;                                               // Константы для улучшения читаемости.
    int a = 345, b, c, d, e, f;                                                 // Общие целочисленные переменные.
    b = a / sm_in_meters;                                                       // Почти все вычисления в главе - целочисленные.
    printf("\n2.1. In %d santimeters is %d full meters.\n", a, b);              // Вывод желательно подробнее.
    const int sec_per_min = 60, min_per_hour = 60;                              // Константы параметров времени.
    a = 3675;                                                                   // Общее количество секунд.
    b = a % sec_per_min;
    c = (a / sec_per_min) % min_per_hour;                                       // По вариантам, без изменения исходного значения.
    d = a / (sec_per_min * min_per_hour);
    printf("\n2.6. Seconds start: %d, seconds per minute %d and minutes per hour %d.\n",
           a, sec_per_min, min_per_hour);
    printf("A) Full hours since start is %d.\n", d);                            // Вывод по вариантам.
    printf("B) Full minutes from last hour is %d.\n", c);
    printf("C) Full seconds from last minute is %d.\n", b);
    const int days_per_week = 7;                                                // Календарь можно проверить по системному.
    a = 15; b = 7;
    c = ((a - 1) + (b - 1)) % days_per_week + 1;                                // Или можно поэтапное вычисление.
    printf("\n2.8. Day in year is %d[1..365], first day of week is %d[1..7] and day index of year is %d.\n", a, b, c);
    const int months_per_year = 12;                                             // Месяцы более линейно считаются.
    a = 12; b = 2;
    c = a % months_per_year + 1;
    d = 1990 + a / months_per_year;                                             // Год дополнительно.
    printf("\n2.9. Month %d and day %d from 1990 year, is month index %d in year %d.\n", a, b, c, d);
    const int base = 10;                                                        // Основание системы счисления. Или можно использовать 10, 100 и т.д.
    a = 123;                                                                    // Задание удобней объединить вместе, или если легче - то по отдельности.
    printf("\n2.12-2.18. Source number with three digits is %d.\n", a);
    b = a % base;
    printf("2.12.A) Low digit in number is %d.\n", b);                          // Раскладываем число на отдельные разряды.
    c = a / base % base;
    printf("2.12.B) Medium digit in number is %d.\n", c);
    d = a / (base * base);
    e = b + c + d;
    printf("2.12.V) High digit in number is %d and digits sum is %d.\n", d, e);
    e = b * c * d;
    printf("2.12.G) Multiply all digits, result is %d.\n", e);
    e = (b * base * base) + (c * base) + d;                                     // Собираем число по цифрам, в обратном порядке.
    printf("2.13. Reverse number is %d.\n", e);
    e = (b * base * base) + (d * base) + c;
    printf("2.15. Rotate last digit to first digit, result is %d.\n", e);       // Перестановки цифр в различном порядке.
    e = (c * base * base) + (d * base) + b;
    printf("2.17. Exchange first and second digits, result is %d.\n", e);
    e = (c * base * base) + (b * base) + d;
    f = (d * base * base) + (b * base) + c;
    printf("2.18. Other combinations of number: %d and %d, total 6.\n", e, f);  // Дополняем оставшиеся перестановки до 6, вместе с исходным.
    a = 1234;
    b = a / (base * base * base);
    c = a / (base * base) % base;                                               // Цифры числа по частям.
    printf("\n2.23. In number %d, thousands %d and hundreds are %d.\n", a, b, c);
    printf("\nFind number using information of digits.\n");                     // Восстановление исходного числа по результату.
    e = 237;                                                                    // Результат числа.
    b = e / (base * base);                                                      // Действия, обратные к условию.
    a = e % (base * base) * base;
    d = a + b;                                                                  // Исходное число, 372.
    printf("\n2.24. Result number %d. Last digit moved to first and source divided by 10. Source: %d.\n", e, d);
    e = 564;                                                                    // Исходное число: 456.
    a = e % base; b = e / base;
    d = a * (base * base) + b;
    printf("\n2.26. Result number %d. First digit was clear and other multiply by %d plus first. Source: %d.\n", e, base, d);
    e = 546;                                                                    // Исходное число 456.
    b = e / (base * base);
    a = e / base % base;
    c = e % base;
    d = a * (base * base) + b * base + c;
    printf("\n2.28. Result number %d. First and second digits exchange. Source: %d.\n", e, d);
    e = 456;                                                                    // Исходное число 465.
    a = e / (base * base);
    b = e % base;
    c = e / base % base;
    d = a * (base * base) + b * base + c;
    printf("\n2.30. Result number %d. Exhcange third and second digits. Source: %d.\n", e, d);
    e = 654;                                                                    // Исходное число: 456.
    a = e % base;
    b = e / base % base;
    c = e / (base * base);
    d = a * (base * base) + b * base + c;
    printf("\n2.32. Result number %d. Moved last digit to first and exchange others. Source: %d.\n", e, d);
    printf("\nMore complex examples.\n");                                       // Задания повышенной сложности, дополнительно.
    int a1 = 8, a2 = 5, b1 = 3, b2 = 4;                                         // Значения цифр в числе.
    printf("\n2.35. Digits A1 = %d and B1 = %d - low order, A2 = %d and B2 = %d - high order.\n", a1, b1, a2, b2);
    printf("All digits in sum of A2A1 and B2B1:\n");                            // Вычисление исполняется по разрядам.
    a = (a1 + b1) % base;
    b = (a1 + b1) / base;                                                       // Флаг переноса в разряд десятков.
    printf("Sum of low order: %d + %d = %d digit and overflow is %d.\n", a1, b1, a, b);
    c = (a2 + b2 + b) % base;
    d = (a2 + b2 + b) / base;                                                   // Флаг переноса в разряд сотен.
    printf("Sum of high order with overflow: %d + %d + %d = %d digit and next overflow is %d.\n", a2, b2, b, c, d);
    e = d * (base * base) + c * base + a;                                       // Вычисление суммы дополнительно для проверки, по условию задачи не делать.
    printf("Digits in sum number: %d %d %d, check sum is %d.\n", d, c, a, e);
    // Пример числового ряда, образующего последовательность. Точки только для удобства и в индекс не входят.
    // 10.11.12.13.14.15.16.17.18.19
    // 20.21.22.23.24.25.26.27.28.29
    printf("\n2.37. Sequence: 10.11.12.13 ... 99, and K parameter in [1..180].\n");
    a = 3;                                                                      // Номер пары по индексу цифры. Счет начинается с 1.
    b = a / 2 + 1;
    printf("A) If K = %d, as the digit in pair index %d, starting from 1.\n", a, b);
    a = 21;                                                                     // Двузначное число, образованное парой цифр, куда входит К-ая цифра.
    b = 10 + (a - 1) / 2 + ((a - 1) % 20) / 2;
    printf("B) If K = %d, as digit to number %d.\n", a, b);
    a = 32;                                                                     // Или можно только один вариант - четное или нечетное.
    b = (a - 1) % 20 / 2;                                                       // Если число четное, т.е. вторая цифра двузначного числа.
    printf("V) If K = %d, as even number, digit in sequence is %d.\n", a, b);
    a = 21;                                                                     // Если число нечетное, т.е. первая цифра двузначного числа.
    b = (a - 1) / 20 + 1;
    printf("V) If K = %d, as odd number, digit in sequence is %d.\n", a, b);
    printf("\n2.38. Sequence: 101.102.103. ... 150., K parameter in [1.150].\n");  
    a = 72;                                                                     // Кажется немного проще чем предыдущая.
    b = (a % 30) / 3;                                                           // Единицы, формула может быть различной.
    printf("If K = %d, divided by 3: 0, 3, 6...\nThe digit in sequence is %d.\n", a, b);
    a = 13;
    b = 1;                                                                      // Результат всегда будет 1, т.к. в последовательности последняя цифры 150.
    printf("If K = %d, from: 1, 4, 7...\nThe digit in sequence is always %d.\n", a, b);
    a = 59;
    b = (a + 1) / 30;                                                           // Десятки в цифрах.
    printf("If K = %d, from 2, 5, 8...\nThe digit in sequence is middle %d.\n", a, b);
    double clocks = 215.0, radians = (clocks / 180.0) * acos(-1.0);             // Единственная задача с вещественным числом. Можно использовать, 
    double hours = radians / (acos(-1.0) * 2.0 / 12.0);
    printf("\n2.40. Clocks %.3f and radians is %.3f, hours is %.3f, full hours is %.3f.\n", 
        clocks, radians, hours, floor(hours));
    a = 5; b = 15;
    c = (a % b) * (b % a) + 1;
    printf("\n2.42. Pair of numbers a = %d and b = %d. Are numbers divided a/b or b/a, result: %d\n", a, b, c);
}   
