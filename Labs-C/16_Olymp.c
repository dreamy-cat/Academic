#include <stdio.h>
#include <stdlib.h>

// Олимпиадные задания школьного уровня, без дополнительных библиотек. Все файлы.

//

void divide_square(void)
{
    unsigned int n = 6, k = 2, r = 0, s;
    printf("Square side N = %u was divided by other square with side K = %u.\n"
           "How many sides will be in common after divided?\n"
           "Conditions K <= N, where K and N in 1..10^4.\n", n, k);
    if (n % k != 0) {
        printf("Parameter N must be divided by K without remains.\n");
        return;
    }
    s = n / k - 1;
    printf("Broken side size %u as vertical and horizontal pieces %u.\n", k, s);
    for (unsigned int i = 0; i < n; ++i)
        r += s;
    r *= 2;
    printf("Result of all sides is %u.\n\n", r);
}

//

void ladder_and_jumps(void)
{
    unsigned int steps = 4, lj = 2, sj = 1, r;
    printf("Ladder has %u steps, short jump is %u steps and %u for long jumps.\n"
           "How many jumps needed?\n", steps, lj, sj);
    r = steps / (lj + sj) * 2;
    steps = steps % (lj + sj);
    printf("Full double jumps (%u + %u) is %u, remains %u steps.\n", lj, sj, r, steps);
    if (steps > lj) { // Если осталось ступенек больше чем длинный прыжок.
        printf("Remainder %u steps, 2 jumps needed.\n", steps);
        r += 2;
    } else if (steps > 0) {
        printf("Remained %u steps, 1 jump needed.\n", steps);
        r += 1;
    }
    printf("All jumps for ladder is %u.\n", r);
}

void olymp(void)
{ // Дополнительные олимпиадные задания условно школьного уровня.
    printf("School olympic tasks.\n\n");

}

