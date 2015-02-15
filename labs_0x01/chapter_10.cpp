#include "chapter_10.h"

int Class_10_3::var2 = 0;

int function_10_1(int init[]) {
    static int* elemAddr = 0;
    if (init != 0) {
        elemAddr = init;
        return 0;
    }
    if (*elemAddr != -1) return (*(elemAddr++));
    return 0;
}

int numberFibbonaci(bool reset) {
    static int fn1 = 0;
    static int fn2 = 1;
    if (reset) { fn1 = 0; fn2 = 1; return 0; }
    int number = fn1 + fn2;
    fn1 = fn2;
    fn2 = number;
    return number;
}
