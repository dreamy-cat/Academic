#include "chapter_10.h"

using namespace std;

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

int Class_10_4::counter = 0;

Class_10_4::Class_10_4 () {}

void Class_10_4::print () {
    cout << "Counter = " << counter << endl;
}

void Class_10_4::count () {
    counter++;
}

void Class_10_4::decrement() {
    counter--;
}

void function_10_4() {
    static Class_10_4 stat;
    stat.count();
    stat.print();
}

Class_10_5::Class_10_5 (Class_10_4* ptr) {
    cout << "Class_10_5 constructor.\n";
    clPtr = ptr;
    clPtr->count();
    clPtr->print();
}

Class_10_5::~Class_10_5() {
    cout << "Class_10_5 destructor.\n";
    clPtr->decrement();
    clPtr->print();
}

void function_10_5 (Class_10_4* ptr) {
    cout << "In function_10_5.\n";
    static Class_10_5 cl(ptr);
}
