#include "chapter_11.h"

using namespace std;

int& function_11_4 (int& i) {
    i++;
    return i;
}

Class_11_5::Class_11_5 () {}

void Class_11_5::function_1() {}

void Class_11_5::function_2() const {}

void function_11_5(Class_11_5& clPtr) {
    // passing 'const Class_11_5' as 'this' argument of 'void Class_11_5::function_1()' discards qualifiers
    clPtr.function_1();
    clPtr.function_2();
}
