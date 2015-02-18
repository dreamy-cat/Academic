#ifndef CHAPTER_10_H
#define CHAPTER_10_H

#include <iostream>

int function_10_1 (int init[] = 0);
int numberFibbonaci(bool reset = false);

class Class_10_3 {
public:
    Class_10_3(int iVar) : var(iVar) {
        for (int i = 0; i < size; i++) array[i] = i;
    }
    static void printVar2() { std::cout << "Var2 = " << var2; }
    void print() {
        std::cout << "Class_10_3, array : ";
        for (int i = 0; i < size; i++) std::cout << array[i] << " ";
        printVar2();
        std::cout << std::endl;
    }
private:
    static const int size = 5;
    int array[size];
    const int var;
    static int var2;
};

class Class_10_4 {
public:
    Class_10_4 ();
    void count ();
    void print ();
    void decrement();
private:
    static int counter;
};

void function_10_4 ();

class Class_10_5 {
public:
    Class_10_5(Class_10_4* ptr);
    ~Class_10_5();
private:
    Class_10_4* clPtr;
};

void function_10_5 (Class_10_4* ptr);

class Class_10_8 {
public:
    Class_10_8(char cc);
    ~Class_10_8();
private:
    char c;
};

void function_10_8_2();

void function_10_8_1();

class Class_10_11 {
public:
    Class_10_11 (int ii);
    void print ();
private:
    int i;
};

void function_10_13 ();

// Task 13. Undefined reference.
// static void function_10_13 ();

class Class_10_14 {
public:
    Class_10_14();
    // void isr() volatile;
    static void isr();
    char read (int index) const;
private:
    static const unsigned char byte;
    static unsigned char flag;
    enum { bufsize = 100 };
    static unsigned char buf[bufsize];
    static int index;
};

namespace NameSpace_16_1 {
    void function_16_1 ();
    void function_16_2 ();
}

namespace NameSpace_16_2 {
    using namespace NameSpace_16_1;
    void function_16_3();
    void function_16_4();
}

namespace {
    void function_10_17() {
        std::cout << "Function_10_17. Anonymous namespace." << std::endl;
    }
}

void function_10_18 ();

#endif // CHAPTER_10_H
