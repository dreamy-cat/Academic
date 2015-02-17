#ifndef CHAPTER_09_H
#define CHAPTER_09_H

#include <iostream>
#include "memory.h"

// Chapter 10, task 10.

static int chapter10Int = 0;

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
    friend struct Structure_9_8_1;
    struct Structure_9_8_1 {
    private:
        Structure_9_8* h;
        int* p;
    public:
        Structure_9_8_1(Structure_9_8* rv) {
            h = rv;
            p = rv->a;
        }

        void next() {
            if (p < &(h->a[sz-1])) p++;
        }

        void previous() {
            if (p > &(h->a[0])) p--;
        }

        void top() {
            p = &(h->a[0]);
        }

        void end() {
            p = &(h->a[sz-1]);
        }

        int read() {
            return *p;
        }

        void set(int i) {
            *p = i;
        }
    };
};

class StringStack9 {
public:
    StringStack9() : index(0) { memset(stack, 0, size * sizeof(std::string*)); }
    void push(const std::string* s) { if (index < size) stack[index++] = s; }
    const std::string* pop() {
        if (index > 0) {
            const std::string* r = stack[--index];
            stack[index] = 0;
            return r;
        }
        return 0;
    }

private:
    static const int size = 5;
    const std::string* stack[size];
    int index;
};

class Color9 {
public:
    enum Hue { red, blue, yellow };
    Color9(Hue cl) : clr(cl) {}
    void color (Hue cl) { clr = cl; }
    Hue color () { return clr; }
private:
    Hue clr;
};

class Class_9_13 {
public:
    Class_9_13() {}
    void function_1 () { function_2(); }
    void function_2 () { std::cout << "Class_9_13, function_2." << std::endl; }
};

class Class_9_14_1 {
public:
    Class_9_14_1 () { std::cout << "Class_9_14_1 constructor." << std::endl; }
};

class Class_9_14_2 {
public:
    Class_9_14_2 () { std::cout << "Class_9_14_2 constructor." << std::endl; }
    Class_9_14_1 obj;
};

#endif // CHAPTER_09_H
