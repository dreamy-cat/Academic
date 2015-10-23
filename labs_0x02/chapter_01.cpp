#include <iostream>
#include <errno.h>
#include <signal.h>
#include "chapter_01.h"

using namespace std;

int function_01_1() {
    return 1;
}

void function_01_2() {
    errno = 1;
}

void function_01_3(int sig) {
    cout << "Function 03, signal recieved.\n";
}

void function_01_4() {
    throw 1;
}

void Class_01_1::function_1() throw(Class_1) {
    cout << "Class_01_1. Throw exception.\n";
    throw(Class_1("Exception in function_1."));
}
