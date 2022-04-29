#ifndef LABS_05_CHAPTER_08_H
#define LABS_05_CHAPTER_08_H

#include <iostream>
#include <algorithm>

void* function_8_1();

class FunctionPointer;

typedef FunctionPointer (*FPtr)();

class FunctionPointer {
public:
    FunctionPointer(FPtr ptr);
    operator FPtr();
private:
    FPtr p;
};

FunctionPointer function_8_2();

class Outer_8 {
public:
    void function();
    class Nested {
    public:
        int operator()(int k);
    };
    // Actual variant.
    int result, a;
    int add(int k);
    Outer_8(int i);
    operator int() const;
};

#endif
