#include "labs_0x07.h"

void part_4()
{
    printf("Chapter's 4 tasks.\n\n");
    double d1  = 5, d2, d3, d4;
    printf("4.1. Y(X) = SIN(X)^2, IF X > 0, ELSE Y(X) = 1 - 2 * SIN(X^2) = ");
    if (d1 > 0) {
        d2 = sin(d1) * sin(d1);
        printf("SIN(%.2f)^2 = %.2f.\n", d1, d2);
    } else {
        d2 = 1 - 2 * sin(d1 * d1);
        printf("1 - 2 * SIN(%.2f)^2 = %.2f.\n", d1, d2);
    }
    if (d1 > d2)
        printf("\n4.6. Parameter %.2f more than %.2f.\n", d1, d2);
    else
        printf("\n4.6. Parameter %.2f less than %.2f.\n", d1, d2);
    d1 = 50; d2 = 10;
    if (d1 / 1000.0 * 3600.0 >= d2)
        printf("\n4.9. Speed value %.2f km/h more or equal than speed value %.2f m/sec.\n", d1, d2);
    else
        printf("\n4.9. Speed value %.2f km/h less than speed value %.2f m/sec.\n", d1, d2);
    d1 = 5; d2 = 3; d3 = 10; d4 = 7;
    printf("\n4.12. Resistor A = %.2f om, voltage A = %.2f volt, resistor B = %.2f om, voltage B = %.2f volt.\n", d1, d2, d3, d4);
    if ((d1 / d2) >= (d3 / d4))
        printf("Current %.2f in first circuit is more or equal than in second.\n", (d1 / d2));
    else
        printf("Current %.2f in second circuit is less than in first.\n", (d3 / d4));
    int a1 = 1, a2 = 2, a3 = 1, a4;
    a4 = a2 * a2 - 4 * a1 * a3;
    printf("\n4.13-14. The equation A*X^2 + B*X + C = %d*X^2 + %d*X + %d, D = %d.\n", a1, a2, a3, a4);
    if (a4 > 0) {
        double r1 = (-1.0 * (double)a2 + sqrt(a4)) / (2.0 * (double)a1);
        double r2 = (-1.0 * (double)a2 - sqrt(a4)) / (2.0 * (double)a1);
        printf("Discriminant is positive, first result is %.2f, second result is %.2f.\n", r1, r2);
    } else if (a4 == 0) {
        double r1 = (-1.0 * (double)a2) / (2.0 * (double)a1);
        printf("Discriminant is zero, only result is %.2f.\n", r1);
    } else
        printf("Discriminant is negative, no results for equation.\n");
    d1 = 3.0 * acos(-1) * acos(-1); d2 = 2.0;
    printf("\n4.16. Square of circle %.2f, foursquare %.2f.\n", d1, d2);
    if (d1 / (acos(-1) * acos(-1)) * 2.0 > sqrt(d2))
        printf("Foursquare can be placed in circle.\n");
    else
        printf("Circle can be placed in foursquare.\n");
    a1 = 10; a2 = 3;
    if (a1 % a2 == 0)
        printf("\n4.20. Number %d divided by %d, result %d.\n", a1, a2, a1 / a2);
    else
        printf("\n4.20. Number %d can't divided by %d, modulo %d.\n", a1, a2, a1 % a2);
    a1 = 53;
    if (a1 / 10 > a1 % 10)
        printf("\n4.23. Number %d. First digit %d is more than second digit %d.\n", a1, a1 / 10, a1 % 10);
    else if (a1 / 10 == a1 % 10)
        printf("\n4.23. Number %d. First digit %d is equal to second digit %d.\n", a1, a1 / 10, a1 % 10);
    else
        printf("\n4.23. Number %d. First digit %d is less than second digit %d.\n", a1, a1 / 10, a1 % 10);
    a1 = 32; a2 = 5;
    if (((a1 / 10) + (a1 % 10)) % 3 == 0)
        printf("\n4.26. Number %d, summ of digits %d, is divided by 3.\n", a1, (a1 / 10) + (a1 % 10));
    else
        printf("\n4.26. Number %d, summ of digits %d, is not divided by 3.\n", a1, (a1 / 10) + (a1 % 10));
    if (((a1 / 10) + (a1 % 10)) % a2 == 0)
        printf("\n4.26. Number %d, summ of digits %d, is divided by %d.\n", a1, (a1 / 10) + (a1 % 10), a2);
    else
        printf("\n4.26. Number %d, summ of digits %d, is not divided by %d.\n", a1, (a1 / 10) + (a1 % 10), a2);
    a1 = 123;
    a2 = a1 / 100; a3 = (a1 / 10) % 10; a4 = a1 % 10;
    a2 = a2 * a2 * a2; a3 = a3 * a3 * a3; a4 = a4 * a4 *a4;
    if (a1 * a1 == a2 + a3 + a4)
        printf("\n4.29. Number %d, summ of (digits ^ 3) is %d, is equal %d in power 2.\n", a1, a2 + a3 + a4, a1 * a1);
    else
        printf("\n4.29. Number %d, summ of (digits ^ 3) is %d, is not equal %d in power 2.\n", a1, a2 + a3 + a4, a1 * a1);
    a1 = 2314;
    int b1 = 5, b2, b3;
    a2 = (a1 / 1000); a3 = (a1 / 100 % 10); a4 = (a1 / 10) % 10;
    int a5 = a1 % 10;
    printf("\n4.32. Number %d, and its digits %d-%d-%d-%d.\n", a1, a2, a3, a4, a5);
    if (a2 + a3 == a4 + a5)
        printf("A) Sum of first half of digits %d is equal other half of digits %d.\n", a2 + a3, a4 + a5);
    else
        printf("A) Sum of first half of digits %d is not equal other half of digits %d.\n", a2 + a3, a4 + a5);
    if ((a2 + a3 + a4 + a5) % 3 == 0)
        printf("B) Sum of digits %d is divided by 3.\n", a2 + a3 + a4 + a5);
    else
        printf("B) Sum of digits %d is not divided by 3.\n", a2 + a3 + a4 + a5);
    if ((a2 * a3 * a4 * a5) % 4 == 0)
        printf("C) Multiply of digits %d, is divided by 4.\n", a2 * a3 * a4 * a5);
    else
        printf("C) Multiply of digits %d, is not divided by 4.\n", a2 * a3 * a4 * a5);
    if ((a2 * a3 * a4 * a5) % b1 == 0)
        printf("C) Multiply of digits %d, is divided by %d.\n", a2 * a3 * a4 * a5, b1);
    else
        printf("C) Multiply of digits %d, is not divided by %d.\n", a2 * a3 * a4 * a5, b1);
    a1 = 6; a2 = 4; b1 = 2; b2 = 3;
    printf("\n4.35. Table with sizes horizontal %d, vertical %d. And squares with sizes %d and %d, accordingly.\n", a1, a2, b1, b2);
    a3 = a1 / b1; a4 = a2 / b2;
    a5 = a3 * a4;
    printf("With horizontal fill %d and vertical %d parts will placed on table, total %d, square %d.\n", a3, a4, a5, a5 * b1 * b2);
    a3 = a1 / b2; a4 = a2 / b1;
    b3 = a3 * a4;
    printf("With vertical fill %d and horizontal %d parts will placed on table, total %d, square %d.\n", a3, a4, b3, b3 * b1 * b2);
    if (a5 > b3)
        printf("Horizontal placed on table has more square.\n");
    else
        printf("Vertical placed on table has more square.\n");
    a1 = 0;
    if (a1 >= -5 &&  a1 <= 3)
        printf("\n4.37. Yes, number %d, in range (-5, 3).\n", a1);
    else
        printf("\n4.37. No, number %d, not in range (-5, 3).\n", a1);
    a1 = 3;
    if (a1 >= -1 && a1 <= 5)
        printf("\n4.39. Point with coordinate %d is placed in area II [-1,5], (see figure in book).\n", a1);
    else if (a1 < -1)
        printf("\n4.39. Point with coordinate %d is placed in area III [-INF,-1], (see figure in book).\n", a1);
    else
        printf("\n4.39. Point with coordinate %d is placed in area I [1,+INF], (see figure in book).\n", a1);
    d1 = 0.5;
    if (d1 >= 0.2 && d1 <= 0.9)
        printf("\n4.41. F(X) = SIN(X), if 0.2 <= X <= 0.9, else F(X) = 1. X = %.2f, F(X) = %.2f.\n", d1, sin(d1));
    else
        printf("\n4.41. F(X) = SIN(X), if 0.2 <= X <= 0.9, else F(X) = 1. X = %.2f, F(X) = %.2f.\n", d1, 1.0);
    d1 = 3.0; d2 = 4.0; d3 = 5.0;
    if (d2 > d1 && d2 < d3)
        printf("\n4.42 A) Yes inequality correct, %.2f < %.2f < %.2f.\n", d1, d2, d3);
    else
        printf("\n4.42 A) No inequality is not correct, %.2f < %.2f < %.2f.\n", d1, d2, d3);
    if (d2 > d1 && d1 > d3)
        printf("B) Yes inequality correct, %.2f > %.2f > %.2f.\n", d2, d1, d3);
    else
        printf("B) No inequality is not correct, %.2f > %.2f > %.2f.\n", d2, d1, d3);
    a1 = 8; a2 = 3; b1 = 2; b2 = 4;
    if (a1 % a2 == b1 || a1 % a2 == b2)
        printf("\n4.44 Yes, number %d modulus %d, is %d equal %d or %d.\n", a1, a2, a1 % a2, b1, b2);
    else
        printf("\n4.44 No, number %d modulus %d, is not %d equal %d or %d.\n", a1, a2, a1 % a2, b1, b2);
    d1 = 0.5; d2 = 0.3; d3 = 0.5; d4 = 000.1;
    if (fabs(d1 - d2) < d4 || fabs(d1 - d3) < d4 || fabs(d2 - d3) < d4)
        printf("\n4.45 In numbers: %.2f - %.2f - %.2f at least two are close.\n", d1, d2, d3);
    else
        printf("\n4.45 In numbers: %.2f - %.2f - %.2f no close.\n", d1, d2, d3);
    a1 = 183; a2 = 183; a3 = 183;
    if (a1 == a2 && a2 == a3)
        printf("\n4.48 Heights of three people: %d, %d, %d are equal.\n", a1, a2, a3);
    else
        printf("\n4.48 Heights of three people: %d, %d, %d are not equal.\n", a1, a2, a3);
    a1 = 1; a2 = 2; a3 = 1;
    a4 = a2 * a2 - 4 * a1 * a3;
    printf("\n4.49.(4.13-14) The equation A*X^2 + B*X + C = %d*X^2 + %d*X + %d, D = %d.\n", a1, a2, a3, a4);
    if (a4 > 0) {
        double r1 = (-1.0 * (double)a2 + sqrt(a4)) / (2.0 * (double)a1);
        double r2 = (-1.0 * (double)a2 - sqrt(a4)) / (2.0 * (double)a1);
        printf("Discriminant is positive, first result is %.2f, second result is %.2f.\n", r1, r2);
    } else if (a4 == 0) {
        double r1 = (-1.0 * (double)a2) / (2.0 * (double)a1);
        printf("Discriminant is zero, only result is %.2f.\n", r1);
    } else
        printf("Discriminant is negative, no results for equation.\n");
    d1 = 5.0; d2 = 3.0; d3 = 4.0; d4 = 6.0;
    if ((d1 < d3 && d2 < d4) || (d1 < d4 && d2 < d3))
        printf("\n4.50 Rectangle with sizes [%.2f,%.2f] can fit in rectangle [%.2f,%.2f] in one or other way.\n", d1, d2, d3, d4);
    else
        printf("\n4.50 Rectangle with sizes [%.2f,%.2f] can't fit in rectangle [%.2f,%.2f] in one or other way.\n", d1, d2, d3, d4);
    d1 = 3.0; d2 = 4.0; d3 = 5.0;
    double f1 = 4.5, f2 = 4.0;  // May be other way to solve, but without loops.
    if ((d1 < f1 && d2 < f2) || (d1 < f2 &&  d2 < f1) ||
            (d1 < f1 && d3 < f2) || (d1 < f2 && d3 < f1) ||
            (d2 < f1 && d3 < f2) || (d2 < f2 && d3 < f1))
        printf("\n4.53. Yes the brick with size [%.1f,%.1f,%.1f] can fit in place with sizes [%.1f,%.1f].\n", d1, d2, d3, f1, f2);
    else
        printf("\n4.53. No the brick with size [%.1f,%.1f,%.1f] can't fit in place with sizes [%.1f,%.1f].\n", d1, d2, d3, f1, f2);
    a1 = 2134; b1 = 3;
    a2 = a1 / 1000; a3 = a1 / 100 % 10; a4 = a1 / 10 % 10; a5 = a1 % 10;
    printf("\n4.59 Number %d with digits %d,%d,%d,%d, ", a1, a2, a3, a4, a5);
    if (a2 == 4 || a3 == 4 || a4 == 4 || a5 == 4)
        printf("has digit 4 in sequence and ");
    else
        printf("hasn't digit 4 in sequnce and ");
    if (a2 == b1 || a3 == b1 || a4 == b1 || a5 == b1)
        printf("has digit %d.\n", b1);
    else
        printf("hasn't digit %d.\n", b1);
    a1 = 1221;
    a2 = a1 / 1000; a3 = a1 / 100 % 10; a4 = a1 / 10 % 10; a5 = a1 % 10;
    if (a2 == a5 && a3 == a4)
        printf("\n4.61 Number %d, is palindrome.\n", a1);
    else
        printf("\n4.61 Number %d, is not palindrome.\n", a1);
    a1 = 1234;
    a2 = a1 / 1000; a3 = a1 / 100 % 10; a4 = a1 / 10 % 10; a5 = a1 % 10;
    if (a2 != a3 && a2 != a4 && a2 != a5 && a3 != a4 && a3 != a5 && a4 != a5)
        printf("\n4.63. All digits %d-%d-%d-%d in number %d are different.\n", a2, a3, a4, a5, a1);
    else
        printf("\n4.63. All digits %d-%d-%d-%d in number %d are not different.\n", a2, a3, a4, a5, a1);
    a1 = 2000;
    if (a1 % 4 == 0 && (a1 % 100 == 0 && a1 % 400 == 0))
        printf("\n4.65. Year %d is leap.\n", a1);
    else
        printf("\n4.65. Year %d is not leap.\n", a1);
    a1 = 5; a2 = 3;
    b1 = 1; b2 = 3; b3 = 2;
    int c1 = b1, c2 = b2, c3 = b1, c4 = b3, c5 = b2, c6 = b3;
    printf("\n4.66. Table sizes %d,%d and domino sizes %d,%d,%d.\n", a1, a2, b1, b2, b3);
    printf("All possible sizes to put on table: [%d,%d], [%d,%d] and [%d,%d].\n", c1, c2, c3, c4, c5, c6);
    int s1, s2, s3;
    if ((a1 / c1) * (a2 / c2) >= (a1 / c2) * (a2 / c1)) {
        s1 = (a1 / c1) * (a2 / c2);
        printf("Sizes for first position is [%d,%d] and amount is %d.\n", c1, c2, s1);
    } else {
        s1 = (a1 / c2) * (a2 / c1);
        printf("Sizes for first position is [%d,%d] and amount is %d.\n", c2, c1, s1);
    }
    if ((a1 / c3) * (a2 / c4) >= (a1 / c4) * (a2 / c3)) {
        s2 = (a1 / c3) * (a2 / c4);
        printf("Sizes for second position is [%d,%d] and amount is %d.\n", c3, c4, s2);
    } else {
        s2 = (a1 / c4) * (a2 / c3);
        printf("Sizes for second position is [%d,%d] and amount is %d.\n", c4, c3, s2);
    }
    if ((a1 / c5) * (a2 / c6) >= (a1 / c6) * (a2 / c5)) {
        s3 = (a1 / c5) * (a2 / c6);
        printf("Sizes for third position is [%d,%d] and amount is %d.\n", c5, c6, s3);
    } else {
        s3 = (a1 / c6) * (a2 / c5);
        printf("Sizes for third position is [%d,%d] and amount is %d.\n", c6, c5, s3);
    }
    if (s1 > s2 && s1 > s3)
        printf("First variant with %d domino's is best fit for table.\n", s1);
    else if (s2 > s1 && s2 > s3)
        printf("Second variant with %d domino's is best fit for table.\n", s2);
    else
        printf("Thrid variant with %d domino's is best fit for table.\n", s3);
    a1 = 23;
    printf("\n4.67. Day in year %d, if monday is 1st january, ", a1);
    if (a1 % 7 >= 1 && a1 % 7 <= 5)
        printf("is a [%d] working day.\n", a1 % 7);
    else
        printf("is a [%d] day-off day.\n", a1 & 7);
    d1 = 9.8; d2 = 15.0; d3 = 0.5; d4 = 1.0;
    double d5 = 7, td = 3.5, xd = 0.0, yd = 0.0, dist = 3.0;
    printf("\n4.68. Trajectory for bullet, speed V0 = %.2f, G-constant = %.2f, angle alpha = %.2f,\n", d2, d1, d3);
    td = d5 / (d2 * cos(d3));
    printf("\theight of target H = %.2f and vertical size P = %.2f, distance R = %.2f, time in sec T = %.2f.\n", d4, d5, dist, td);
    xd = dist; yd = d2 * td * sin(d3) - (d1 * td * td) / 2;
    printf("\tX = V0 * T * COS(alpha) = %.2f, Y = V0 * T * SIN(alpha) - (G * T^2) / 2 = %.2f.\n", xd, yd);
    if (yd >= d4 &&  yd <= d5)
        printf("\tYes, bullet will hit the target.\n");
    else
        printf("\tNo, bullet miss the target.\n");
    a1 = 5; a2 = 2; a3 = 2; a4 = 3;
    b1 = 3; b2 = 1; b3 = 4;
    int b4 = 2;
    printf("\n4.69. Rectangle 1 left-bottop position [%d,%d] and sizes %d,%d.\n", a1, a2, a3, a4);
    printf("Rectangle 2 left-bottop position [%d,%d] and sizes %d,%d.\n", b1, b2, b3, b4);
    if (a1 >= b1 && a2 >= b2 && a1 + a3 <= b1 + b3 && a2 + a4 <= b2 + b4)
        printf("A) Yes, all pixels in rectangle one within second rectangle.\n");
    else
        printf("A) No, some or zero pixels of first rectange in second rectangle.\n");
    if ((a1 >= b1 && a2 >= b2 && a1 + a3 <= b1 + b3 && a2 + a4 <= b2 + b4) ||
            (b1 >= a1 && b2 >= a2 && b1 + b3 <= a1 + a3 && b2 + b4 <= a2 + a4))
        printf("B) Yes one of rectangles is within other rectangle.\n");
    else
        printf("B) No, one of rectangles is outside of other.\n");
    if ((a1 + a3 >= b1 && a2 + a4 >= b2) || (b1 + b3 >= a1 + a3 && b2 + b4 >= a2 + a4))
        printf("C) Yes, rectangles has some common area.\n");
    else
        printf("C) No, rectangles has not common areas.\n");
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
}
