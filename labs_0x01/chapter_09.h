#ifndef CHAPTER_09_H
#define CHAPTER_09_H

#include <iostream>
#include "memory.h"

void function_9_4_1();

inline void function_9_4_2() {
    int a = 1, b = 2, c = 3;
    a = b * c;
    b = c + a;
    c = b - a;
}

class Class_9_6 {
public:
    Class_9_6() : i(0) {}
    int f() const { return g() + 1; }
    int g() const { return i; }
    int t () { std::cout << (long)this; }
private:
    int i;
};

class Class_9_7 {
public:
    inline Class_9_7(char ci) { memset((void*)text,ci,8); }
    inline void print () { std::cout << text << std::endl; }
private:
    char text[8];
};

struct Structure_9_8 {
private:
    static const int sz = 5;
    int a[sz];
public:
    Structure_9_8() { memset(a, 0, sz * sizeof(int)); }
    struct Structure_9_8_1;
};

#endif // CHAPTER_09_H
