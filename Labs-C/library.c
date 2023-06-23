#include "library.h"

int factorial(int n)
{
    int r = 1;
    for (int i = 2; i <= n; ++i)
        r *= i;
    return r;
}

double a_power_n(double a, int n)
{
    double r = a;
    for (int i = 1; i < n; ++i)
        r *= a;
    return r;
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


