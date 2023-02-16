#include <stdio.h>
#include <math.h>

void part_1(void)
{
    printf("Chapter's 1 tasks.\n\n");
    printf("1.1. Pi number with 2 digits after point: %.2f\n", acos(-1.0));
    int i1 = 1, i2 = 13, i3 = 49;
    // scanf("%d", &i1);                                                        // Scanf simple integer input.
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
    printf("\n1.14. Expressions and results.\n");
    double x1 = 3.3, y1 = 2.1, x2 = -5.3, rf = 0.0;
    printf("A) 2 * X = 2.0 * %.2f = %.2f.\n", x1, 2 * x1);
    printf("D) ABS(X) = ABS(%.2f) = %.2f.\n", x2, fabs(x2));
    printf("Z) 3 * SQRT(X) = 3 * SQRT(%.2f) = %.2f.\n", x1, 3 * sqrt(x1));
    rf = 3.0 * sin(2.0 * x1) * cos(3.0 * y1);
    printf("L) 3 * SIN(2*X) * COS(3*Y) = 3 * SIN(2.0 * %.2f) * COS(3.0 * %.2f) = %.2f.\n", x1, y1, rf);
    rf = sin(x1) * cos(y1) + cos(x1) * sin(y1);
    printf("I) SIN(X) * COS(Y) + COS(X) * SIN(Y) = SIN(%.2f) *  COS(%.2f) + COS(%.2f) * SIN(%.2f) = %.2f.\n", x1, y1, x1, y1, rf);
    i1 = 30; i2 = 24; i3 = 4;
    printf("\n1.15. More expressions with parameters.\n");
    printf("B) A / (B * C) = %d / (%d / %d) = %d.\n", i1, i2, i3, i1 / (i2 *  i3));
    x1 = 5.1; x2 = 7.1;
    double x3 = 2.2;
    rf = ((-1 * x2) + sqrt(x2 * x2 - 4.0 * x1 * x3)) / (2.0 * x1);
    printf("E) (-B + SQRT(B^2 - 4*A*C)) / 2 * A = ");
    printf("(-%.1f + SQRT(%.1f^2 - 4.0 * %.1f * %.1f)) / 2.0 * %.1f = %.2f.\n", x2, x2, x1, x3, x1, rf);
    rf = 1.0 / (1.0 + (x1 + x2) / 2.0);
    printf("Z) 1 / (1 + (A + B) / 2) = 1 / (1 + (%.1f + %.1f) / 2) = %.1f.\n", x1, x2, rf);
    x1 = 3.0; x2 = 2.0;
    rf = pow(2.0, pow(x1, x2));
    printf("K) 2 ^ (M ^ N) = 2 ^ (%.1f ^ %.1f) = %.1f.\n", x1, x2, rf);
    x1 = 3.2; x2 = 2.1; x3 = 5.1; y1 = 1.5;
    double y2 = 7.1;
    printf("\n1.16. Expressions, using double parameters.\n");
    rf = x1 / x2 / x3;
    printf("A) A / B / C = %.1f / %.1f / %.1f = %.1f.\n", x1, x2, x3, rf);
    rf = (x1 + x2) / (x2 + x3);
    printf("D) (A + B) / (B + C) = (%.1f + %.1f) / (%.1f + %.1f) = %.1f.\n", x1, x2, x2, x3, rf);
    rf = (2 * x2 * x3 * cos(x1 / 2.0)) / (x2 + x3);
    printf("K) 2 * B * C * COS(A / 2) / (B + C) = 2 * %.1f * %.1f * COS(%.1f / 2) / (%.1f + %.1f) = %.1f.\n", x2, x3, x1, x2, x3, rf);
    rf = x1 * y1 + x2 / x3 * y1 + y2;
    printf("M) A * X + B / C * X + Y = %.1f * %.1f + %.1f / %.1f * %.1f + %.1f = %.1f.\n", x1, y1, x2, x3, y1, y2, rf);
    printf("\n1.17. A little more expressions with parameters.\n");
    x1 = 1.3; x2 = 2.1; x3 = 4.5; y1 = 0.5; y2 = -4.4;
    rf = x1 * x2 + (x3 * x2 * x2 / 2);
    printf("V) V(0) * T + (A * T^2) / 2 = %.1f * %.1f + (%.1f * POW(%.1f, 2) / 2.0) = %.1f.\n", x1, x2, x3, x2, rf);
    rf = 2 * acos(-1.0) * x1;
    printf("J) 2 * PI * R = 2 * %.1f * %.1f = %.1f.\n", x1, acos(-1.0), rf);
    rf = sqrt(x1 * x1 + x2 * x2 - 2 * x1 * x2 * cos(x3));
    printf("M) SQRT(A^2 + B^2 - 2 * A * B * COS(C)) = SQRT(%.1f^2 + %.1f^2 - 2 * %.1f * %.1f * COS(%.1f) = %.1f.\n", x1, x2, x1, x2, x3, rf);
    rf = fabs(1.0 - fabs(y2));
    printf("T) ABS(1 - ABS(X)) = ABS(1 - ABS(%.1f) = %.1f.\n", y2, rf);
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
    rf = 7.0 * x1 * x1 - 3.0 * x1 + 6.0;
    printf("\n1.22. A) Y = 7 * X^2 - 3 * X + 6 = 7 * %.1f^2 - 3 * %.1f + 6 = %.1f.\n", x1, x1, rf);
    x1 = 1.2;
    rf = (x1 * x1 + 10.0) / (sqrt(x1 * x1 + 1.0));
    printf("\n1.23. Y = (A^2 + 10) / (SQRT(A^2 + 1) = (%.1f^2 + 10) / (SQRT(%.1f^2 + 1)) = %.1f.\n", x1, x1, rf);
    x1 = 3.0;
    rf = sin(3.2 + sqrt(1.0 + x1)) / fabs(5.0 * x1);
    printf("\n1.24. Y = SIN( (3.2 + SQRT(1.0 + X)) / (5.0 * X) = SIN( (3.2 + SQRT(1.0 + %.2f)) / (5.0 * %.2f)) = %.2f.\n", x1, x1, rf);
    x1 = 5.0;
    rf = x1 * 4.0;
    printf("\n1.25. Size of square side is %.1f, perimeter is %.1f.\n", x1, rf);
    x1 = 7.0;
    rf = x1 * x1 * acos(-1.0);
    printf("\n1.26. Radius of circle is %.1f, area of the circle is %.1f.\n", x1, rf);
    x1 = 0.025; x2 = 6350.0;
    rf = sqrt(pow((x1 + x2), 2.0) - x2 * x2);
    printf("\n1.27. Horizon distance from %.3f height and R(Earth) = %.3f, is %.1f km.\n", x1, x2, rf);
    x1 = 5;
    x3 = x1 * x1 * x1; x2 = x1 * x1;
    printf("\n1.28. Edge of the cube is %.1f, area of side %.1f and volume %.1f.\n", x1, x2, x3);
    x1 = 3.7;
    x2 = 2 * acos(-1) * x1; x3 = acos(-1) * x1 * x1;
    printf("\n1.29. Radius of circle %.2f, length %.2f and area %.2f.\n", x1, x2, x3);
    x1 = 3.5; y1 = 5.2;
    rf = (x1 * x1 * x1) - 2.5 * x1 * y1 + 1.78 * x1 * x1 - 2.5 * y1 + 1;
    printf("\n1.30. A) X = %.2f, Y = %.2f, calculate Z = X^3 - 2.5*X*Y + 1.78*X^2 - 2.5*Y + 1 = %.2f.\n", x1, y1, rf);
    x1 = 3.2; x2 = 2.3;
    printf("\n1.31. Pair of double numbers X1 = %.2f, Y = %.2f.\n", x1, x2);
    y1 = (x1 + x2) / 2.0; y2 = (x1 * x2) / 2.0;
    printf("A) Mean of pair is %.2f.\n", y1);
    printf("B) Geometric mean is %.2f.\n", y2);
    x1 = 3.0; x2 = 4.0;
    rf = sqrt(x1 * x1 + x2 * x2);
    printf("\n1.35. Cathets of triangle %.2f and %.2f, hypotenuse %.2f.\n", x1, x2, rf);
    x1 = 2.0; x2 = 2.5;
    rf = fabs(acos(-1.0) * x1 * x1 - acos(-1) * x2 * x2);
    printf("\n1.36. Area of ring with inner radius %.2f and outer radius %.2f is %.2f.\n", x1, x2, rf);
    x1 = 2.0; x2 = 3.0;
    rf = x1 + x2 + sqrt(x1 * x1 + x2 * x2);
    printf("\n1.37. Perimeter of triangle with cathets %.2f and %.2f is %.2f.\n", x1, x2, rf);
    x1 = 3.5; x2 = 4.3;
    y1 = (2.0 / (x1 * x1 + 25.0) + x2) / (sqrt(x2) + (x1 + x2) / 2.0);
    y2 = (fabs(x1) + 2 * sin(x2)) / (5.5 * x1);
    printf("\n1.40. Calculate expressions with A = %.2f and B = %.2f.\n", x1, x2);
    printf("1) X = (2/(A^2+25) + B) / (sqrt(B)+(A+B)/2) = (2/(%.2f^2+25) + %.2f) / (sqrt(%.2f)+(%.2f+%.2f)/2) = %.2f.\n", x1, x2, x2, x1, x2, y1);
    printf("2) Y = (ABS(A)+2*SIN(B)) / (5.5 * A) = (ABS(%.2f)+2*SIN(%.2f)) / (5.5 * %.2f) = %.2f\n", x1, x2, x1, y2);
    x1 = 4.0; x2 = 3.0;
    x3 = sqrt(x1 * x1 + x2 * x2);
    rf = x1 + x2 + x3;
    printf("\n1.44. Sides of right triangle are %.2f and %.2f. Hypotenuse %.2f, perimeter %.2f.\n", x1, x2, x3, rf);
    x1 = 2.0; x2 = 3.0; x3 = 4.0;
    double s = 4 * x2 * x3 + 2 * x2 * x1, v = x1 * x2 * x3;
    printf("\n1.46. Sides of parallelpiped: %.2f, %.2f and %.2f. Surface is %.2f, volume is %.2f.\n", x1, x2, x3, s, v);
    x1 = 3.0; x2 = 4.0; x3 = 5.0;
    double x4 = sqrt(fabs((x1 - x2) *  (x1 - x2)) + x3 * x3);
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
    rf = x3 / (x1 + x2);
    printf("\n1.55. Speed of two cars are %.2f and %.2f km/h. Distance %.2f km. Time before meeting %.2f hours.\n", x1, x2, x3, rf);
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
