#include <iostream>

#include "chapter_06.h"

using namespace std;

Simple::Simple(int i) : a(i) {
    cout << "Class Simple constructor has called. Int a = " <<  a << endl;
}

Simple::~Simple() {
    cout << "Class Simple destructor has called. Int a = " << a << endl;
}

Class_6_6::Class_6_6() {
    simplePtr = new Simple(0);
}

Class_6_6::~Class_6_6() {
    delete simplePtr;
}

int Class_6_6::read() {
    return simplePtr->b;
}

void Class_6_6::change(int value) {
    simplePtr->b = value;
}

Stack6::Stack6() {
    storage.clear();
}

void Stack6::push(string &val){
    storage.push_back(val);
}

string Stack6::pop() {
    if (!storage.empty()) {
        string val = storage.back();
        storage.pop_back();
        return val;
    }
}
