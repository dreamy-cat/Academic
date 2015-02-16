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

#endif // CHAPTER_10_H
