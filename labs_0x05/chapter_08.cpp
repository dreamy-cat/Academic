#include "chapter_08.hpp"

using namespace std;

void* function_8_1() { return (void*)function_8_1; }

FunctionPointer::FunctionPointer(FPtr ptr) : p(ptr) {}

FunctionPointer::operator FPtr() { return p; }

FunctionPointer function_8_2() {
    cout << "Function returned pointer to itself.\n";
    return function_8_2;
}

int Outer_8::Nested::operator()(int k) { cout << "Outer class and nested operator().\n"; }

void Outer_8::function() {
    class Local {
    public:
        Local(int i, int ai) : localA(i), a(ai) { cout << "Constructor, local class.\n"; }
        // use of local variable with automatic storage.
        // int operator()(int b) { return (localA + b); }
        int operator()(int b) { return (a + b); }
        void function() { cout << "Function of local class.\n"; }
        int a;
    private:
        int localA;
    } cl(1, 1);
    cl.function();
    cout << "Using operator() for local class, result, " << cl(2) << endl;
}

int Outer_8::add(int k) { return (a + k); }

Outer_8::Outer_8(int i) : a(i * 2) {
    a += 5;
    result = add(3);
}

Outer_8::operator int() const { return result; }
