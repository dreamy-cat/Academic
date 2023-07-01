#include <stdio.h>

// Глава 7. Сочетание оператора цикла и условного оператора.
// Код для базового варианта, пересмотреть полностью.

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
}
