#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void part_4()
{
    printf("Chapter's 4 tasks.\n\n");
    int a1 = 3, a2 = 4, a3 = 5, b1 = 8, b2 = 9;
    int n1 = a3 * 100 + a2 * 10 + a1, n2 = b2 * 10 + b1;
    int n3 = n1 + n2;
    int m1 = a1 + b1;
    int m2 = (a2 + b2) + (m1 / 10);
    int m3 = a3 + m2 / 10;
    int r = m3 + m2 % 10 + m1 % 10;
    printf("4.18. Summ of digits for AAA + BB = NNN, %d%d%d + %d%d = %d, = %d.\n",a3, a2 ,a1, b2, b1, n3, r);
    int v1 = 2, v2 = 3, h1 = 3, h2 = 4;
    r = (v1 == v2) || (h1 == h2);
    printf("4.19a. Rook at [%d,%d] is dangerous for pawn at [%d,%d] = %d.\n",v1, h1 ,v2 ,h2, r);
    r = abs(v1 - v2) == abs(h1 - h2);
    printf("4.19b. Bishop at [%d,%d] is dangerous for pawn at [%d,%d] = %d.\n", v1, h1, v2, h2, r);
    r = (abs(v1 - v2) == 1) && (abs(h1 - h2) == 1);
    printf("4.19c. King at [%d,%d] can move to [%d,%d] = %d.\n", v1, h1, v2, h2, r);
    double d1 = 3.0, d2 = 4.0, d3 = 5.0, delta = 0.001;
    if ((d1 / d3) - 1 < delta)
            printf("4.124a. Triangle with catets %.2f,%.2f and hyp %.2f is rectangular.\n", d1, d2, d3);
    else
        if (d1 / d3 < 1.0 && d2 / d3 < 1.0)
            printf("4.124a. Triangle with sizes (%.2f,%.2f,%.2f) is oxygon.\n", d1, d2, d3);
    else
            printf("4.124a. Triangle with sizes (%.2f,%.2f,%.2f) is obtuse.\n", d1, d2, d3);

    printf("4.125. Age and names form: ");
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
    printf("4.128. Age in months %d, it's %d years and %d months.\n", n1, n2, n3);
    a1 = 10; b1 = 30; a2 = 12; b2 = 15; n1 = 12; m1 = 0;
    printf("4.132. Train arrived at %2d:%2d and departs at %2d:%2d, passanger time %2d:%2d, ", a1, b1, a2, b2, n1, m1);
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
    printf("4.134. Year %d, month %d and day %d. ", y, m, d);
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
    printf("Previous date year %d ", abs(y_prev));
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
    printf("4.135. Semaphore lighting scheme G-Y-R = 3-1-2 minutes, at %d minute color is ", n1);
    n2 = n1 % (3 + 1 + 2);
    if (n2 >= 4)
        printf("red.\n");
    else if (n2 >= 3)
        printf("yellow.\n");
    else
        printf("green.\n");
    a1 = 5;
    printf("4.140. Sequence 1-2..-9..10-11-..-99..100-101-...-110 the element %d is ", a1);
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

void part_5()
{
    printf("Chapter's 5 tasks.\n\n");
    printf("Example of random sequence, #include <stdlib.h>: ");
    srand(0);   // Инициализация последовательности случайных чисел любым другим значением
    for (int i = 0; i < 10; ++i) {
        int a = rand() % 100;   // Генерируем числа от 0 до 99.
        printf("%d ", a);
    }
    printf("\n");
}

void labs_0x07()
{
    part_4();
}
