#include "labs_0x07.h"
#include "library.h"

void print_binary_byte(unsigned char byte)
{
    const size_t bin = 2;
    for (int i = CHAR_BIT - 1; i >= 0; --i)
        printf("%d", (byte >> i) % bin);
}

unsigned short int bits_multiply(unsigned char byte_1, unsigned char byte_2)
{
    unsigned short int r = 0;
    size_t bits_8 = CHAR_BIT, bits_16 = CHAR_BIT << 1;
    const size_t binary = 2;
    printf("Multiply bytes %d * %d, %d bits, result will be %d bits.\n", byte_1, byte_2, bits_8, bits_16);
    printf("Binary = %d, bits in char = %d, bits in short int = %d.\n", binary, bits_8, bits_16);
    printf("BYTE_A:\t\t");
    print_binary_byte(byte_1);
    printf("\nBYTE_2:\t\t");
    print_binary_byte(byte_2);
    printf("\nSTEPS:");
    for (size_t i = 0; i < CHAR_BIT; ++i) {
        printf("\t");
        for (size_t j = 0; j < CHAR_BIT - i; ++j)
            printf(" ");
        if ((byte_2 >> i) & 1) {
            r += ((unsigned short int)byte_1) << i;
            print_binary_byte(byte_1);
        } else
            print_binary_byte(0);
/*      // Version with processing and print every bit, slower.
 *      unsigned short int t = 0;
        for (size_t j = 0; j < CHAR_BIT; ++j) {
            unsigned char bit = (byte_2 >> i) & 1;
            t |= (bit << j) & byte_1;
            printf("%d", ((bit << j) &  byte_1) >> j);
        }
        r += t;
        */
        printf("\n");
    }
    printf("RESULT:\t");
    byte_1 = (unsigned char)r & 0xFF;
    byte_2 = (unsigned char)(r >> CHAR_BIT);
    print_binary_byte(byte_2);
    print_binary_byte(byte_1);
    printf(" = %d.\n", r);
    return 0;
}

int simple_multiply(int x, int y)
{
    int r = 0;
    printf("Simple multiply using adding %d * %d: ", x, y);
    for (int i = 0; i < y; ++i) {
        r += x;
        printf("%d:%d ", i, r);
    }
    printf("\n");
    return r;
}

void n_power_2(int a)
{
    int r = 0;
    printf("Power %d to 2, terms: ", a);
    if (a < 0)
        a *= -1;
    for (int i = 1; i < 2 * a; r += i, i += 2)
        printf("%d ", i);
    printf("= %d.\n", r);
}

int n_power_3(int n)
{
    int m = 1, r = 0;
    for (int i = 1; i < n; ++i)
        m += i * 2;
    r += m;
    printf("N = %d to power 3 function: %d ", n, m);
    for (int i = 1; i < n; ++i) {
        m += 2; r += m;
        printf("%d ", m);
    }
    printf("- %d.\n", r);
    return r;
}

double summ_seq_fact(int n)
{
    double r = 1.0, f = 1.0;
    printf("Sequence 1 + 1/1! + 1/2! + ... + 1/N!: ");
    for (int i = 1; i <= n; ++i) {
        r += 1.0 / f; f *= i;
        printf("%.2f[%.2f] ", f, r);
    }
    printf("\n");
    return r;
}

void digits_total(int a)
{
    int r = 0;
    printf("Digits in number %d and summ [result]: ", a);
    while (a) {
        r += a % 10;
        printf("%d[%d] ", a % 10, r);
        a /= 10;
    }
    printf("\n");
}

void calculate_expr_1(void)
{
    printf("Steps and sums before result Index:Value, Previous: ");
    int r = 20*20, prev_r = 20 * 20;
    for (int i = 19; i > 0; --i) {
        r -= i * i;
        printf("I:%d - R:%d ", i, r);
        if (i % 3 == 0) {
            r = prev_r - r *  r ;
            prev_r = r;
            printf("P = %d ", prev_r);
        }
    }
    printf("\n");
}

void part_5()
{
    printf("Chapter's 5 tasks.\n\n");
    int a1 = 10;
    int b1 = 15;
    int r, r1, r2, r3;
    printf("5.3.\tN:\tN^2:\tN^3:\t[%d,%d]:\n", a1, b1);
    for (int i = a1; i < b1; ++i) {
        r1 = i + 10;
        r2 = i * i;
        r3 = r2 * i;
        printf("\t%d\t%d\t%d\t%d\n", r1, r2, r3, i);
    }
    printf("\n5.8-10.\tPounds:\tKilorgams:\tInches:\tCentimeters:\tUSD:\tRUB:\n");
    const double cm_per_inch = 2.54, gram_per_pound = 453.0, gram_per_kg = 1000.0, rub_usd = 69.62;
    for (int i = 1; i < 10; ++i) {
        double kg = i * gram_per_pound / gram_per_kg;
        double cm = (10 + i) * cm_per_inch;
        double rub = i * rub_usd;
        printf("\t%d\t%.2f\t\t%d\t%.2f\t\t%d\t%.2f\n", i, kg, (i + 10), cm, i, rub);
    }
    const double p0 = 1.29, z = 1.25E-4;
    printf("\n5.12. Density of air = p_sea * exp ^ (-h * z), p_sea = %.2f, z = %.2e.\n", p0, z);
    printf("Altitude:\tDensity:\n");
    for (int h = 0; h < 500; h += 100) {
        double density = p0 * exp(-1 * h * z);
        printf("%d\t%.4f\n", h, density);
    }
    a1 = 5;
    printf("\n5.15. N = %d, multiply [1..9]: ", a1);
    for (int i = 1; i < 10; ++i)
        printf("%d ", a1 * i);
    printf("\n\n5.16. Sin(2..20): ");
    for (double a = 2; a < 20; ++a)
        printf("%.2f ", sin(a));
    printf("\n\n5.18. Z(a) = 3.5 * t ^ 2 - 7 * t + 16, t = 4 * a, a [2, 3 ... 7].\n");
    for (int i = 2; i < 7; ++i) {
        double t = 4 * i;
        double z = 3.5 * t * t - 7 * t + 16;
        printf("\tt = 4 * %d = %.2f, Z(a) = 3.5 * %.2f ^ 2 - 7 * %.2f + 16 = %.2f\n", i, t, t, t, z);
    }
    printf("\n5.20. Sqrt(0.1 ... 0.9): ");
    for (double a = 0.1; a < 1; a += 0.1)
        printf("%.2f ", sqrt(a));
    const int price = 5;
    printf("\n\n5.22. Price of candys in kg = %d\nGrams:\tValue:\n", price);
    for (int i = 100; i < 1000; i += 100) {
        double value = i * price / 1000.0;
        printf("%d\t%.2f\n", i, value);
    }
    printf("\n5.24. Sequence: ");
    for (int i  = 2; i < 10; ++i)        // Using range from 4..18 also works.
        printf("3,%d, 3,%d, ", i, i);
    printf("\n\n5.26. Sequence: ");
    for (int i  = 44; i < 65; i += 2)
        printf("%d,%d ", i / 10, i % 10);
    printf("\n\n5.30.(all variants):\n");
    r = 0; a1 = 20; b1 = 40;
    for (int i = a1; i < b1; ++i)
        r += i;
    printf("\tA) Summ of all integers in interval [%d,%d] = %d.\n", a1, b1, r);
    a1 = 40; b1 = 50; r = 0;
    for (int i = a1; i < b1; ++i)
        r += i * i;
    printf("\tB) Summ of all integers power 2 in interval [%d,%d] = %d.\n", a1, b1, r);
    a1 = 1; b1 = 5; r = 0;
    for (int i = a1; i < b1; ++i)
        r += i * i;
    printf("\tC) Summ of all integers power 2 in interval [%d,%d] = %d.\n", a1, b1, r);
    a1 = 5; b1 = 10; r = 0;
    for (int i = a1; i < b1; ++i)
        r += i * i;
    printf("\tD) Summ of all integers power 2 in interval [%d,%d] = %d.\n", a1, b1, r);
    a1 = 5;
    printf("\n5.31-35. Sums all in one loop, values in sequences [0,%d].\n", a1);
    printf("IDX\\Seq:(N+IDX)^2:\t(1/(IDX+1)):\t(IDX+2/IDX+3):\t(1/(3^IDX):\t-1^(IDX+1)*(1/(IDX+1):\n");
    double s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0;
    for (int i = 0; i < a1; ++i) {
        double e1 = (a1 + i) * (a1 + i);
        double e2 = 1.0 / (i + 1);
        double e3 = (double)(i + 2) / (double)(i + 3);
        double e4 = 1.0 / pow(3.0, i);
        double e5 = pow(-1.0, i + 1) * (1.0 / (i + 1));
        s1 += e1; s2 += e2; s3 += e3; s4 += e4; s5 += e5;
        printf("%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", i, e1, e2, e3, e4, e5);
    }
    printf("Sums:\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", s1, s2, s3, s4, s5);
    a1 = 5; s1 = 0;
    printf("\n5.40. [Sum] of sequence size %d: ", a1);
    for (int i = 0; i < a1; ++i) {
        double e = (double)(rand()) / (double)(rand());
        s1 += e;
        printf("%.2f ", e);
    }
    printf("[%.2f]\n", s1);
    r = 0;
    printf("\n5.42. Scores and [sum] on exams: ");
    for (int i = 0; i < 4; ++i) {
        int e = rand() % 4 + 2;
        r += e;
        printf("%d ", e);
    }
    printf("[%d].\n", r);
    s1 = 0;
    printf("\n5.46. Resistance in paralel 1/R[1] + 1/R[2] + ... + 1/R[n]: ");
    for (int i = 0; i < 5; ++i) {
        double r_n = (double)(rand() % 5 + 1);
        s1 += 1.0 / r_n;
        printf("%.2f ", r_n);
    }
    printf("- overall resistance = %.2f.\n", s1);
    a1 = 5; s1 = 0;
    printf("\n5.49. Sum of elements in power of 2: ");
    for (int i = 0; i < a1; ++i) {
        double e = (double)(rand()) / (double)(rand());
        s1 += e;
        printf("%.2f ", e);
    }
    printf("- sum = %.2f.\n", s1);
    a1 = 20; s1 = 0;
    printf("\n5.52. All of %d scores in class: ", a1);
    for (int i = 0; i < a1; ++i) {
        int e = rand() % 4 + 2;
        s1 += e;
        printf("%d ", e);
    }
    printf("- mean = %.2f\n", s1 / (double)a1);
    a1 = 5; s1 = 0;
    printf("\n5.55. All of %d masses in load: ", a1);
    for (int i = 0; i < a1; ++i) {
        int e = rand() % 5 + 1;
        s1 += e;
        printf("%d ", e);
    }
    printf("- mean = %.2f\n", s1 / (double)a1);
    a1 = 5; r1 = 0; r2 = 0;
    printf("\n5.58. Scores of sportsmens in %d types: ", a1);
    for (int i = 0; i < a1; ++i) {
        int e1 = rand() % 10, e2 = rand() % 10;
        r1 += e1; r2 += e2;
        printf("%d-%d ", e1, e2);
    }
    printf("- total scores of athletes %d - %d.\n", r1, r2);
    a1 = 20; s1 = 0; s2 = 0;
    const int base_height = 150, diff_height = 40;
    printf("\n5.61. All heights of students in both classes, sizes %d: ", a1);
    for (int i = 0; i < a1; ++i) {
        int e1 = rand() % diff_height + base_height;
        int e2 = rand() % diff_height + base_height;
        s1 += e1; s2 += e2;
        printf("%d:%d ", e1, e2);
    }
    s1 /= (double)(a1); s2 /= (double)(a1);
    printf("- mean of classes %.2f and %.2f.\n", s1, s2);
    a1 = 12; s1 = 0; s2 = 0;
    printf("\n5.64. Citizens in %d locations and squares: ", a1);
    for (int i = 0; i < a1; ++i) {
        int cit = rand() % 10 + 1, square = rand() % 100 + 1;
        s1 += cit; s2 += square;
        printf("%d:%d ", cit, square);
    }
    printf("- population density = %.2f\n", s1 / s2);
    a1 = 5;
    double d_prev = 1;
    printf("\n5.66.Recurrence relation A[k] = k * A[k-1] + 1 / k, k[1..%d], A[0] = %.2f: ", a1, d_prev);
    for (double i = 1; i <= a1; ++i) {
        double e = i * b1 + 1.0 / d_prev;
        printf("%.2f ", e);
        d_prev = e;
    }
    a1 = 7; b1 = 4; s1 = 2;
    int f0, f1 = 1, f2 = 1;
    printf("\n\n5.67. Fibonacci, N = %d: %d %d ", a1, f2, f1);
    for (int i = 3; i < a1; ++i) {
        f0 = f2 + f1;
        if (i == b1)
            printf("element [%d] founded ", b1);
        printf("%d  ", f0);
        f2 = f1; f1 = f0;
        s1 += f0;
    }
    printf("- sum of sequence %.2f, ", s1);
    if ((int)(s1) % 2 == 0)
        printf("is even.\n");
    else
        printf("is not even.\n");
    int n2 = 1, n1 = 2, n;
    int m2 = 1, m1 = 1, m;
    a1 = 7; b1 = 5; s1 = 0; s2 = 5;
    printf("\n5.68. Sequence of rationals and sum more than %.2f: %d/%d %d/%d ", s2, n2, m2, n1, m1);
    for (int i = 3; i < a1; ++i) {
        n = n1 + n2; m = m1 + m2;
        if (i == b1)
            printf("element [%d] founded ", b1);
        printf("%d/%d ", n, m);
        s1 += (double)n / (double)m;
        n2 = n1; n1 = n; m2 = m1; m1 = m;
    }
    if (s1 >= s2)
        printf("Sum of sequence %.2f is more or equal than %.2f.\n", s1, s2);
    else
        printf("Sum of sequence %.2f is less than %.2f.\n", s1, s2);
    double d1 = 0, d2 = 0, d3 = 1.5;
    a1 = 7;
    printf("\n5.69. Sequence of V(I) = (I - 1) / (I^2 + 1) * V[I-1] - V[I-2] + V[I + 3], I[4,5..%d]: ", a1);
    for (int i = 4; i < a1; ++i) {
        double d4 = (i - 1) / (i*i + 1) * d3 - d2 + d1;
        printf("V[%d] = %.2f, ", i, d4);
        d1 = d2; d2 = d3; d3 = d4;
    }
    a1 = 24;
    int a2 = 0;
    printf("\n\n5.70. Every 3 hours the ameba duplicate, amebes after %d hours: ", a1);
    for (int i = 0; i < 24; ++i) {
        if (i % 3 == 0)
            ++a2;
        printf("%d - %d ", i, a2);
    }
    d1 = 1000; d2 = 0.02; a1 = 12;
    printf("\n\n5.71. In bank deposit %.1f, interest %.2f, total %d months. Month:Profit, Deposit: ", d1, d2, a1);
    for (int i = 1; i <= a1; ++i) {
        d3 = d1 * d2;
        d1 += d3;
        printf("%d:%.2f, %.2f ", i, d1, d3);
    }
    a1 = 10; a2 = 7; d1 = 10.0; d2 = 0.1; d3 = 0;   // Use IF operator for one of the variant.
    printf("\n\n5.72. Sportmen starts with %.2f distance, adding 10%% each next day, after %d days, total before %d day. Day:Distance, Total: ", d1, a1, a2);
    for (int i = 1; i <= a1; ++i) {
        d1 += d1 * d2;
        d3 += d1;
        printf("%d:%.2f, ", i, d1);
        if (i < a2)
            printf("%.2f ", d3);
    }
    d1 = 100; d2 = 20.0; d3 = 0.05; a1 = 8; a2 = 6;
    double d4 = 0.02, d5 = 0.0;
    printf("\n\n5.73. Square of crops %.2f, fertility %.2f, every year crops rising %.2f, fertility rising %.2f.\n", d1, d2, d3, d4);
    printf("%d years of harvest, total after %d. Year:Square[Fertility] - Harvest(Total): ", a1, a2);
    for (int i = 0; i < a1; ++i) {
        d5 += d1 * d2;
        printf("%d:%.2f[%.2f] - %.2f", i, d1, d2, d1 * d2);
        if (i == a2)
            printf("(Check year: %.2f)", d5);
        else
            printf("(%.2f) ", d5);
        d1 += d1 * d3;
        d2 += d2 * d4;
    }
    d1 = 0.5; d2 = 0.1; a1 = 12;
    d3 = 3.14 / 6 *  (d2 * d2 * d2);
    d4 = 0; d5 = d3;
    printf("\n\n5.74. Inner diameter %.2f, spheres total %d. Sphere:Space-previous,Space,Total: ", d2, a1);
    for (int i = 0; i < 12; ++i) {
        printf("%d:%.2f,%.2f,%.2f ", i, d3, d4, d5);
        d4 = 3.14 / 6 *  ((d3 + d1) * (d3 + d1) * (d3 + d1));
        d5 += d4 - d3;
        d3 = d4;
    }
    a1 = 2; a2 = 10; b1 = 0;
    int a3 = 2, b2 = 2;
    printf("\n\n5.75. Sequence and summ 2^I, I = [%d,%d]: ", a1, a2);
    for (int i = a1; i < a2; ++i) {
        b2 *= a3; b1 += b2;
        printf("%d^%d = %d[%d] ", a3, i, b2, b1);
    }
    d1 = 1.2; d2 = d1; a1 = 5;
    printf("\n\n5.76. Sequence of A^1, A^2 ... A^N: ");
    for (int i = 1; i <= a1; ++i) {
        printf("%.2f^%d = %.2f; ", d1, i, d2);
        d2 *= d2;
    }
    a1 = 1; a2 = -1; a3 = 10;
    int a4 = 0, a5 = 0;
    printf("\n\n5.77. Sequence -1^2 + 2^2 - 3^2 + ... + 10^2: ");
    for (int i = a1; i < a3; ++i) {
        a5 = (a1 * a1) * a2; a4 += a5;
        printf("%d,%d ", a1, a4);
        a1++; a2 *= -1;
    }
    d1 = 0.0; a1 = 10; d2 = 3.14 / a1; d3 = 0;
    printf("\n\n5.78. Square of under arc of sinus figure in %d steps: ", a1);
    for (int i = 0; i < a1; ++i) {
        d3 += sin(d1);
        printf("%.2f[%.1f]; ", d1, d3);
        d1 += d2;
    }
    a1 = 3; a2 = 5;
    printf("\n\n5.81. Multiply X and Y with adding.\n");
    simple_multiply(a1, a2); simple_multiply(a2, a1);
    unsigned char byte_1 = 0x9D, byte_2 = 0x0F;
    bits_multiply(byte_1, byte_2);
    a1 = 2; a2 = 4;
    printf("\n5.82. Factorial of N function for values: ");
    printf("F(%d) = %d, F(%d) = %d.\n", a1, factorial(a1), a2, factorial(a2));
    d1 = 3.0; d2 = 2.3; a1 = 5; a2 = 3;
    printf("\n5.83. Power of double pair function F(double,integer): ");
    printf("F(%.2f,%d) = %.2f; F(%.2f,%d) = %.2f.\n", d1, a1, a_power_n(d1,a1), d2, a2, a_power_n(d2,a2));
    printf("\n5.84. Calculate expression ((20^2 - 19^2 - 18^2)^2 - ... - 1^2.");
    calculate_expr_1();     // Not clear in book.
    a1 = 513;
    printf("\n5.85. Reverse number right to left, %d to %d.\n", a1, reverse_integer(a1));
    a1 = 3; a2 = 5; a2 = 7;
    printf("\n5.86. Values to power 2, F(X).\n");
    n_power_2(a1); n_power_2(a2); n_power_2(a3);
    a1 = 2; a2 = 4; a3 = 5;
    printf("\n5.88. Function A^3 without using power from math.\n");
    n_power_3(a1); n_power_3(a2); n_power_3(a3);
    printf("\n5.90. Sequence 1 + 1/1! + 1/2! + ... + 1/N!.\n");
    a1 = 1; a2 = 3; a3 =5;
    summ_seq_fact(a1); summ_seq_fact(a2); summ_seq_fact(a3);
    d1 = 1.0; a2 = 50.0; d3 = 0; d4 = sqrt(50.0);
    printf("\n5.92. SQRT(1 + SQRT(2 + SQRT() ... ) function, range [%d, %d]: ", a1, a2);
    for (double i = a2 - 1; i > 0; --i) {
        d3 = sqrt(i + d4); d4 = d3;
        printf("%.1f ", d3);
    }
    printf("= %.2f\n", d3);
    a1 = 123456; a2 = 321567;
    printf("\n5.94. Summ of all digits in number %d and %d.\n", a1, a2);
    digits_total(a1); digits_total(a2);
}
