#include <iostream>

#include "chapter_06.h"

using namespace std;

Simple::Simple(int i) : a(i) {
    cout << "Class Simple constructor has called. Int a = " <<  a << endl;
}

Simple::~Simple() {
    cout << "Class Simple destructor has called. Int a = " << a << endl;
}
