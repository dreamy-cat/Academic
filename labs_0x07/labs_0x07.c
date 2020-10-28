#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define STRING_MAX 256

void part_1()
{
    printf("Chapter's 1 tasks.\n\n");
    printf("1.1. Pi number with 2 digits after point: %.2f\n", acos(-1));
    int i1 = 1, i2 = 13, i3 = 49;     // Scanf simple integer input.
    // scanf("%d", &i1);
    printf("\n1.3. Integer with scanf function: %d\n", i1);
    printf("\n1.5. Three numbers with spaces: %d %d %d.\n", i1, i2, i3);
    int i4 = 3, i5 = 7, i6 = 8;
    printf("\n1.7. Three numbers with two spaces: %d  %d  %d.\n", i4, i5, i6);
    int i7 = 50, i8 = 10;
    printf("\n1.9. Two numbers printed as column:\n%d\n%d.\n", i7, i8);
    printf("\n1.11. Four numbers printed as column:\n%d\n%d\n%d\n%d\n", i1, i1 + 1, i1 + 2, i1 + 3);
    printf("\n1.13. Simple print strings and data.\n");
    printf("A) '%s'\n%d %d.\n", "2kg", 13, 17);
    printf("B) '%c' %d\n%d '%c'\n", 'a', 1, 19, 'b');
    printf("V) '%c' '%c'\n%d '%c'\n", 'x', 'y', 5, 'y');
    printf("\n1.14 Expressions and results.\n");
    double x1 = 3.3, y1 = 2.1, x2 = -5.3;
    printf("A) 2 * X = 2 * %.2f = %.2f.\n", x1, 2 * x1);
    printf("D) ABS(X) = ABS(%.2f) = %.2f.\n", x2, fabs(x2));
    printf("Z) 3 * SQRT(X) = 3 * SQRT(%.2f) = %.2f.\n", x1, 3 * sqrt(x1));
    double r_d = sin(x1) * cos(y1) + cos(x1) * sin(y1);
    printf("I) SIN(X) * COS(Y) + COS(X) * SIN(Y) = SIN(%.2f) *  COS(%.2f) + COS(%.2f) * SIN(%.2f) = %.2f.\n", x1, y1, x1, y1, r_d);
    i1 = 30; i2 = 24; i3 = 4;
    printf("\n1.15. More expressions with parameters.\n");
    printf("B) A / (B * C) = %d / (%d / %d) = %d.\n", i1, i2, i3, i1 / (i2 *  i3));
    x1 = 5.1; x2 = 7.1;
    double x3 = 2.2;
    r_d = ((-1 * x2) + sqrt(x2 * x2 - 4 * x1 * x3)) / (2 * x1);
    printf("E) (-B + SQRT(B^2 - 4*A*C)) / 2 * A = (-%.1f + SQRT(%.1f^2 - 4 * %.1f * %.1f)) / 2 * %.1f = %.2f.\n", x2, x2, x1, x3, x1, r_d);
    r_d = 1.0 / (1.0 + (x1 + x2) / 2);
    printf("Z) 1 / (1 + (A + B) / 2) = 1 / (1 + (%.1f + %.1f) / 2) = %.1f.\n", x1, x2, r_d);
    x1 = 3.0; x2 = 2.0;
    r_d = pow(2.0, pow(x1, x2));
    printf("K) 2 ^ (M ^ N) = 2 ^ (%.1f ^ %.1f) = %.1f.\n", x1, x2, r_d);
    x1 = 3.2; x2 = 2.1; x3 = 5.1; y1 = 1.5;
    double y2 = 7.1;
    printf("\n1.16. Expressions, using double parameters.\n");
    r_d = x1 / x2 / x3;
    printf("A) A / B / C = %.1f / %.1f / %.1f = %.1f.\n", x1, x2, x3, r_d);
    r_d = (x1 + x2) / (x2 + x3);
    printf("D) (A + B) / (B + C) = (%.1f + %.1f) / (%.1f + %.1f) = %.1f.\n", x1, x2, x2, x3, r_d);
    r_d = (2 * x2 * x3 * cos(x1 / 2.0)) / (x2 + x3);
    printf("K) 2 * B * C * COS(A / 2) / (B + C) = 2 * %.1f * %.1f * COS(%.1f / 2) / (%.1f + %.1f) = %.1f.\n", x2, x3, x1, x2, x3, r_d);
    r_d = x1 * y1 + x2 / x3 * y1 + y2;
    printf("M) A * X + B / C * X + Y = %.1f * %.1f + %.1f / %.1f * %.1f + %.1f = %.1f.\n", x1, y1, x2, x3, y1, y2, r_d);
    printf("\n1.17. A little more expressions with parameters.\n");
    x1 = 1.3; x2 = 2.1; x3 = 4.5; y1 = 0.5; y2 = -4.4;
    r_d = x1 * x2 + (x3 * x2 * x2 / 2);
    printf("V) V(0) * T + (A * T^2) / 2 = %.1f * %.1f + (%.1f * POW(%.1f, 2) / 2.0) = %.1f.\n", x1, x2, x3, x2, r_d);
    r_d = 2 * 3.14 * x1;
    printf("J) 2 * PI * R = 2 * %.1f * %.1f = %.1f.\n", x1, acos(-1), r_d);
    r_d = sqrt(x1 * x1 + x2 * x2 - 2 * x1 * x2 * cos(x3));
    printf("M) SQRT(A^2 + B^2 - 2 * A * B * COS(C)) = SQRT(%.1f^2 + %.1f^2 - 2 * %.1f * %.1f * COS(%.1f) = %.1f.\n", x1, x2, x1, x2, x3, r_d);
    r_d = fabs(1.0 - fabs(y2));
    printf("T) ABS(1 - ABS(X)) = ABS(1 - ABS(%.1f) = %.1f.\n", y2, r_d);
    i1 = 45; i2 = 10;
    printf("\n1.18. Operator '=', with integers S = %d, K = %d, steps variables, variant G):\n", i1, i2);
    i1 = -25;
    printf("S = -25, S = %d, K = %d; ", i1, i2);
    i1 = i1 + i2;
    printf("S = S + K, S = %d.\n", i1);
    i1 = 0; i2 = 30; i3 = i2 - 5;
    printf("\n1.20. Operator '=' integers S = %d, K = %d, D = K - 5 = %d, steps variables, variant B:\n", i1, i2 ,i3);
    i2 = 2 * i3;
    printf("K = 2 * D = %d; ", i2);
    i1 = i2 - 100;
    printf("S = K - 100 = %d.\n", i1);
    x1 = 3.3;
    r_d = 7.0 * x1 * x1 - 3.0 * x1 + 6;
    printf("\n1.22. A) Y = 7 * X^2 - 3 * X + 6 = 7 * %.1f^2 - 3 * %.1f + 6 = %.1f.\n", x1, x1, r_d);
    x1 = 1.2;
    r_d = (x1 * x1 + 10) / (sqrt(x1 * x1 + 1.0));
    printf("\n1.23. Y = (A^2 + 10) / (SQRT(A^2 + 1) = (%.1f^2 + 10) / (SQRT(%.1f^2 + 1)) = %.1f.\n", x1, x1, r_d);
    x1 = 5.0;
    r_d = x1 * 4;
    printf("\n1.25. Size of square side is %.1f, perimeter is %.1f.\n", x1, r_d);
    x1 = 7.0;
    r_d = x1 * x1 * acos(-1);
    printf("\n1.26. Radius of circle is %.1f, area of the circle is %.1f.\n", x1, r_d);
    x1 = 0.025; x2 = 6350.0;
    r_d = sqrt(pow((x1 + x2), 2.0) - x2 * x2);
    printf("\n1.27. Horizon distance from %.3f height and R(Earth) = %.3f, is %.1f km.\n", x1, x2, r_d);
    x1 = 5;
    x3 = x1 * x1 * x1; x2 = x1 * x1;
    printf("\n1.28. Edge of the cube is %.1f, area of side %.1f and volume %.1f.\n", x1, x2, x3);
    x1 = 3.7;
    x2 = 2 * acos(-1) * x1; x3 = acos(-1) * x1 * x1;
    printf("\n1.29. Radius of circle %.2f, length %.2f and area %.2f.\n", x1, x2, x3);
    x1 = 3.5; y1 = 5.2;
    r_d = (x1 * x1 * x1) - 2.5 * x1 * y1 + 1.78 * x1 * x1 - 2.5 * y1 + 1;
    printf("\n1.30. A) X = %.2f, Y = %.2f, calculate Z = X^3 - 2.5*X*Y + 1.78*X^2 - 2.5*Y + 1 = %.2f.\n", x1, y1, r_d);
    x1 = 3.2; x2 = 2.3;
    printf("\n1.31. Pair of double numbers X1 = %.2f, Y = %.2f.\n", x1, x2);
    y1 = (x1 + x2) / 2.0; y2 = (x1 * x2) / 2.0;
    printf("A) Mean of pair is %.2f.\n", y1);
    printf("B) Geometric mean is %.2f.\n", y2);
    x1 = 3.0; x2 = 4.0;
    r_d = sqrt(x1 * x1 + x2 * x2);
    printf("\n1.35. Cathets of triangle %.2f and %.2f, hypotenuse %.2f.\n", x1, x2, r_d);
    x1 = 2.0; x2 = 2.5;
    r_d = fabs(acos(-1) * x1 * x1 - acos(-1) * x2 * x2);
    printf("\n1.36. Area of ring with inner radius %.2f and outer radius %.2f is %.2f.\n", x1, x2, r_d);
    x1 = 2.0; x2 = 3.0;
    r_d = x1 + x2 + sqrt(x1 * x1 + x2 * x2);
    printf("\n1.37. Perimeter of triangle with cathets %.2f and %.2f is %.2f.\n", x1, x2, r_d);
    x1 = 3.5; x2 = 4.3;
    y1 = (2.0 / (x1 * x1 + 25.0) + x2) / (sqrt(x2) + (x1 + x2) / 2.0);
    y2 = (fabs(x1) + 2 * sin(x2)) / (5.5 * x1);
    printf("\n1.40. Calculate expressions with A = %.2f and B = %.2f.\n", x1, x2);
    printf("1) X = (2/(A^2+25) + B) / (sqrt(B)+(A+B)/2) = (2/(%.2f^2+25) + %.2f) / (sqrt(%.2f)+(%.2f+%.2f)/2) = %.2f.\n", x1, x2, x2, x1, x2, y1);
    printf("2) Y = (ABS(A)+2*SIN(B)) / (5.5 * A) = (ABS(%.2f)+2*SIN(%.2f)) / (5.5 * %.2f) = %.2f\n", x1, x2, x1, y2);
    x1 = 4.0; x2 = 3.0;
    x3 = sqrt(x1 * x1 + x2 * x2);
    r_d = x1 + x2 + x3;
    printf("\n1.44. Sides of right triangle are %.2f and %.2f. Hypotenuse %.2f, perimeter %.2f.\n", x1, x2, x3, r_d);
    x1 = 2.0; x2 = 3.0; x3 = 4.0;
    double s = 4 * x2 * x3 + 2 * x2 * x1, v = x1 * x2 * x3;
    printf("\n1.46. Sides of parallelpiped: %.2f, %.2f and %.2f. Surface is %.2f, volume is %.2f.\n", x1, x2, x3, s, v);
    x1 = 3.0; x2 = 4.0; x3 = 5.0;
    double x4 = sqrt((x1 - x2) *  (x1 - x2) + x3 * x3);
    double p = x1 + x2 + 2 * x4;
    printf("\n1.48. Sides of trapezoid %.2f and %.2f, height %.2f. Perimeter is %.2f.\n", x1, x2, x3, p);
    x1 = 1.0; x2 = 1.0; x3 = 5.0; x4 = 5.0;
    double x5 = 10.0, x6 = 1.0;
    printf("\n1.50. Coordinates of triangle: (%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f). ", x1, x2, x3, x4, x5, x6);
    y1 = sqrt((x3 - x1) * (x3 - x1) + (x4 - x2) * (x4 - x2));
    y2 = sqrt((x5 - x3) * (x5 - x3) + (x6 - x4) * (x6 - x4));
    double y3 = sqrt((x5 - x1) * (x5 - x1) + (x6 - x2) * (x6 - x2));
    p = y1 + y2 + y3;
    s = sqrt(p / 2.0 * (p / 2.0 - y1) * (p / 2.0 - y2) * (p / 2.0 - y3));
    printf("Perimeter is %.2f, square of rectangle is %.2f.\n", p, s);
    x1 = 15.0; x2 = 12.0;
    x3 = (x1 + x2) / 2.0;
    x4 = fabs(x1 - x3); x5 = fabs(x2 - x3);
    printf("\n1.54. First age is %.1f, second is %.1f. Avarage %.2f and diffs are %.2f and %.2f.\n", x1, x2, x3, x4, x5);
    x1 = 50.0; x2 = 60.0; x3 = 10.0;
    r_d = x3 / (x1 + x2);
    printf("\nSpeed of two cars are %.2f and %.2f km/h. Distance %.2f km. Time before meeting %.2f hours.\n", x1, x2, x3, r_d);
    double celsius = 25.0, fahrenheit = 0.0, kelvin = 0.0;
    fahrenheit = 9.0 / 5.0 * celsius + 32.0;
    kelvin = celsius + 273.15;
    printf("\n1.57. Temperature in celsius %.2f, in fahrenheit %.2f and kelvin %.2f.\n", celsius, fahrenheit, kelvin);
    fahrenheit = 451.0;
    celsius = fahrenheit - 32.0 * 5.0 / 9.0;
    printf("\n1.58. Temperature %.2f in fahrenheit is %.2f in celsius.\n", fahrenheit, celsius);
    i1 = 5; i2 = 7;
    printf("\n1.59. Pair of variables %d and %d, exchange values using temporary variable. ", i1, i2);
    i3 = i1;
    i1 = i2;
    i2 = i3;
    printf("New values after exchange %d and %d, temporary var is %d.\n", i1, i2, i3);
    i1 = 1; i2 = 2; i3 = 3;
    printf("\n1.60. A = %d, B = %d, C = %d.\nA) First scheme B = C, A = B, C = A, values after ", i1, i2, i3);
    i4 = i2; i2 = i3; i5 = i1; i1 = i4; i3 = i5;
    printf("A = %d, B = %d, C = %d.\n", i1, i2, i3);
    i1 = 1; i2 = 2; i3 = 3;
    printf("B) Second scheme B = A, C = B, A = C, values after ");
    i4 = i2; i2 = i1; i5 = i3; i3 = i4; i1 = i5;
    printf("A = %d, B = %d, C = %d.\n", i1, i2, i3);
    x1 = 2.0;
    printf("\n1.61. Float value X = %.2f, using only multiply.\n", x1);
    x2 = x1 * x1; x3 = x2 * x2;
    printf("A) A ^ 4 = (A * A) * (A * A) = %.2f.\n", x3);
    x4 = x3 * x3;
    printf("G) A ^ 8 = (A * A) * (A * A) * (A * A) = %.2f.\n", x4);
    x2 = x1 * x1 * x1;
    x3 = x2 * x2;
    x4 = x3 * x3 * x2;
    printf("Z) A ^ 15 = ((A ^ 3) ^ 2) ^ 2) * (A ^ 3) = %.2f.\n", x4);
    printf("\n1.62. Float value X = %.2f, using only multiply.\n", x1);
    x2 = x1 * x1;
    x3 = x2 * x2;
    x4 = x3 * x3;
    x5 = x4 * x4 * x3;
    printf("B) A ^ 4 = %.2f, A ^ 20 = %.2f.\n", x3, x5);
    x2 = x1 * x1;   // 2
    x3 = x2 * x2;   // 4
    x4 = x3 * x3;   // 8
    x5 = x4 * x4;   // 16
    x6 = x3 * x1;
    double x7 = x5 * x3 / x1;
    printf("G) A ^ 5 = %.2f, A ^ 19 = %.2f. 5 iterations, if only one.\n", x6, x7);
}

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

int factorial(int n)
{
    int r = 1;
    for (int i = 2; i <= n; ++i)
        r *= i;
    return r;
}

double a_power(double a, int n)
{
    double r = a;
    for (int i = 1; i < n; ++i)
        r *= a;
    return r;
}

void calculate_expr_1()
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

int reverse_integer(int a)
{
    int r = 0;
    while (a) {
        r = r * 10 + a % 10;
        a /= 10;
    }
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
    printf("F(%.2f,%d) = %.2f; F(%.2f,%d) = %.2f.\n", d1, a1, a_power(d1,a1), d2, a2, a_power(d2,a2));
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

void labs_0x07()
{
    part_1();
    // extra_tasks();
}




