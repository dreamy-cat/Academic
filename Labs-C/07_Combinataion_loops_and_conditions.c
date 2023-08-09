#include <stdio.h>

// Глава 7. Сочетание оператора цикла и условного оператора.
// Код для базового варианта, пересмотреть полностью.

// Общие рекомендации ко всей главе, отдельно по условным уровням можно посмотреть в файлах описании.

void num_info(int num, int more)
{
    printf("Natural number %d information:\n", num);
    if (num == 0) {
        printf("No information on 0, return.\n");
        return;
    }
    if (num < 0) {
        printf("Warning, number is not natural(negative), using absolute value.\n");
        num *= -1;
    }
    int n = num, div = 1, divs_all = 0, sum = 0, sum_even = 0, divs_odd = 0, divs_even = 0, divs_more = 0;
    printf("All deviders of num: ");
    while (div <= num) {
        if (n % div == 0) {
            printf("%d ", div);
            sum += div;
            if (div % 2 == 0) {
                sum_even += div;
                divs_even++;
            } else
                divs_odd++;
            if (div > more)
                divs_more++;
             divs_all++;
        }
        div++;
    }
    printf("\nSum of all dividers: %d.\n", sum);
    printf("Sum of even dividers: %d.\n", sum_even);
    printf("Total dividers: %d.\n", divs_all);
    printf("Total odd dividers: %d.\n", divs_odd);
    printf("Total dividers more than %d: %d.\n", more, divs_more);
}

int num_sum_digits(int num)
{
    if (num < 0)
        num *= -1;
    int sum = 0;
    const int base = 10;
    while (num) {
        sum += num % base;
        num /= base;
    }
    return sum;
}

void labs_07(void)
{
    printf("Part 07. Combine loops and conditions.\n\n");
    int a = 1, b = 9, c = 3, d = 0, s = 0;
    printf("7.2 - 7.4. All numbers from %d to %d, divided by %d: ", a, b, c);
    while (a != b) {
        if (a % 4 == 0)
            s += a;
        if (a % c == 0)
            printf("%d ", a);
        ++a;
    }
    printf("- sum of digits divided by 4 is %d.\n", s);
    a = 1000; b = 9999; c = 133;
    printf("\n7.6. All numbers with 4 digits from %d to %d divided by %d and remainder 111: ", a, b, c);
    while (a != b) {
        if (a % c == 111)
            printf("%d ", a);
        ++a;
    }
    a = 100; b = 999; c = 25; d = 0;
    printf("\n\n7.8. All numbers from %d to %d with sum of digtis %d: ", a, b, c);
    while (a != b) {
        s = num_sum_digits(a);
        if (s == c) {
            printf("%d ", a);
            ++d;
        }
        ++a;
    }
    printf(" - total numbers is %d.\n", d);
    a = 10; b = 99; c = 5;
    printf("\n7.10. All numbers from %d to %d divided by %d or contain %d: ", a, b, c, c);
    while (a != b) {
        if (a % c == 0 || a % 10 == c || a / 10 == c)
            printf("%d ", a);
        ++a;
    }
    a = 31; b = 100; c = 0;
    printf("\n\n7.12. All numbers and sum from %d to %d divided by 3 and with 2, 4, 8 in tail: ", a, b);
    while (a != b) {
        d = a % 10;
        if (a % 3 == 0 && (d == 2 || d == 4 || d == 8)) {
            printf("%d ", a);
            c += a;
        }
        ++a;
    }
    printf("- sum of numbers is %d.\n", c);
    a = 16;
    printf("\n7.13. Natural number %d information using function.\n", a);
    num_info(a, 5);
    // Организация вычислений во время ввода данных.
    double f, g;
    int e[6] = { 1, 2, 3, 4, 5, 6 };
    double h[5] = { 0.1, 0.2, 0.3, 0.4, 0.5 };
    printf("\n\nCalcualations in data input(or arrays), indexes from 0..5.\n");
    printf("Floating point data in array %.3f, %.3f, %.3f, %.3f and %.3f.\n", h[0], h[1], h[2], h[3], h[4]);
    printf("Integer data in array %d, %d, %d, %d and %d.\n", e[0], e[1], e[2], e[3], e[4]);
    printf("\n7.14. Sum of 3 floating point elements more than 10.75:");
    h[1] = 15.5; h[2] = 12.3; f = 0.0;
    for (int i = 0; i < 3; ++i)
        if (h[i] > 10.75) {
            printf(" + %.2f", h[i]);
            f += h[i];
        }
    printf(" = %.2f.\n", f);
    printf("\n7.18. Sum of A[2] + A[4] ... A[2*n], n < 5:");
    s = 0;
    for (int i = 0; i < 5; i++)
        if (i % 2 == 0) {
            printf(" + %d", e[i]);
            s += e[i];
        }
    printf(" = %d.\n", s);
    a = 100; b = 3; s = 0;
    e[0] = 51; e[1] = 121; e[2] = 141;
    printf("\n7.21. Total cost of goods with price more than %d: ", a);
    for (int i = 0; i < b; ++i)
        if (e[i] > a) {
            s += e[i];
            printf("%d[%d] ", e[i], s);
        }
        else
            printf("%d ", e[i]);
    printf("- total costs %d.\n", s);
    a = 5; b = 3; c = 0; e[0] = 3; e[1] = 5; e[2] = 4;
    printf("\n7.25. Student's counter with scores '%d': ", a);
    for (int i = 0; i < b; ++i) {
        if (e[i] == a)
            c++;
        printf("%d ", e[i]);
    }
    printf("- result %d.\n", c);
    a = 5; b = 4; c = 0; d = 0;
    h[0] = -0.5; h[1] = +0.7; h[2] = -1.2; h[3] = -2.3;
    printf("\n7.33. Positive and negative floating point numbers: ");
    for (int i = 0; i < b; ++i) {
        if (h[i] > 0)
            c++;
        else if (h[i] < 0)
            d++;
        printf("%.3f ", h[i]);
    }
    printf("- negative %d and positive %d numbers.\n", c, d);
    a = 4; b = 0; e[0] = 1; e[1] = 3; e[2] = 3; e[3] = 3;
    printf("\n7.35.A) Equal pairs in %d elements: ", a);
    for (int i = 0; i < a - 1; ++i) {
        printf("%d-%d", e[i], e[i + 1]);
        if (e[i] == e[i + 1]) {
            b++;
            printf("(yes) ");
        } else
            printf("(no) ");
    }
    printf("- total equal pairs is %d.\n", b);
    e[0] = 3; e[1] = 1; e[2] = 2;   // Первый треугольник.
    e[3] = 4; e[4] = 5; e[5] = 7;   // Второй треугольник.
    printf("\n7.38. Is triangles correct with sides:\n");
    for (int i = 0, t; i < 2; ++i) {
        t = i * 3;
        printf("%d triangle, sides %d:%d:%d", i, e[t], e[t + 1], e[t + 2]);
        if (e[t] < e[t + 1] + e[t + 2] && e[t + 1] < e[t] + e[t + 2] && e[t + 2] < e[t] + e[t + 1])
            printf(", triangle is correct.\n");
        else
            printf(", triangle is not correct.\n");
    }
    // 7.39 дополнительно.
    a = 0; b = 0; c = 0; d = 0;                             // Количество и общее время удалений игроков.
    e[0] = 1; e[1] = 2; e[2] = 1; e[3] = 5;                 // Первая команда, два удаления на 2 и 5 минут.
    e[4] = 2; e[5] = 10;                                    // Вторая конанда, одно удаление на 10 минут.
    printf("\n7.40. Teams and penalty minutes:\n");
    for (int i = 0; i < 3; ++i) {
        printf("Team %d penalty %d.\n", e[i * 2], e[i * 2 + 1]);
        if (e[i * 2] == 1) {
            ++a;
            b += e[i * 2 + 1];
        } else if (e[i * 2] == 2) {
            ++c;
            d += e[i * 2 + 1];
        }
    }
    printf("Team 1 has %d penalties and %d minutes.\n", a, b);
    printf("Team 2 has %d penalties and %d minutes.\n", c, d);
    a = 5; b = 0; g = 0.0;                                  // Количество элементов, сумма и сами числа.
    h[0] = 7.5; h[1] = 12.3; h[2] = 25.8; h[3] = 18.1; h[4] = -15.5;
    printf("\n7.43. Arithmetical mean of floating point numbers, more than 10.0: ");
    for (int i = 0; i < a; ++i) {
        if (h[i] > 10.0) {
            g += h[i];
            b++;
            printf("%.3f[%.3f] ", h[i], g);
        } else 
            printf("%.3f ", h[i]);
    }
    printf("- result %.3f.\n", g / b);
    a = 5; b = 0; c = 0; d = 2;                             // Количество, сумма и данные.
    e[0] = 5; e[1] = 3; e[2] = 4; e[3] = 8; e[4] = 6;
    printf("\n7.46. Arithmetic mean of integers, mod %d: ", 2);
    for (int i = 0; i < a; ++i) {
        if (e[i] % d == 0) {
            b += e[i]; c++;
            printf("%d mod %d[%d]; ", e[i], d, b);
        } else
            printf("%d; ", e[i]);
    }
    printf("result %d elements, mean %d.\n", c, b / c);
    a = 3; b = -1;
    e[0] = 3; e[1] = -5; e[2] = 1;
    printf("\n7.51. Index of last negative number: ");
    for (int i = 0; i < a; ++i) {
        if (e[i] < 0)
            b = i;
        printf("%d:%d ", i, e[i]);
    }
    printf("- last negative at %d index, number %d.\n", b, e[b]);
}   // 232, 8713.




