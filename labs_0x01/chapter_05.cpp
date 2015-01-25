#include <iostream>
#include "chapter_05.h"

using namespace std;

void Class_5_1::f1() {
    c++;
}

void Class_5_1_2::setString(std::string str, int index) {
    if (index >= 0 && index < 3) s[index] = str;
}

std::string Class_5_1_2::getString(int index) {
    if (index >= 0 && index < 3) return s[index];
}

void function_5_3 (Class_5_3* clPtr) {
    cout << "Private member Class_5_3::int 'a' = " << clPtr->a++ << endl;
}

void Class_5_4_1::f(Class_5_4_2 *ptr) {
    cout << "Class_5_4_1 function." << endl;
}

void Class_5_4_2::f(Class_5_4_1 *ptr) {
    cout << "Class_5_4_2 function." << endl;
}

void Class_5_5_2::printA(Class_5_5_1* ptr) {
    cout << "Class_5_5_2 print 'a' from Class_5_5_1: " << ptr->a << endl;
}

void Class_5_5_3::f(Class_5_5_1* ptr) {
    cout << "Class_5_5_3 print 'a' from Class_5_5_1: " << ptr->a << endl;
}

void Class_5_6_1::display() {
    cout << "Display function of Class_5_6_1. Char from Class_5_6_2 = " << this->cl.a << endl;
}

void Class_5_6_1::print() {
    cout << "Class_5_6_1 char = " << c << endl;
}

void Class_5_6_1::Class_5_6_2::display() {
    cout << "Display function of Class_5_6_1::Class_5_6_2. Char from Class_5_6_3 = " << this->cl.b << endl;
}

void Class_5_6_1::Class_5_6_2::Class_5_6_3::display() {
    cout << "Display function of Class_5_6_1::Class_5_6_2::Class_5_6_3." << endl;
}

void Class_5_8::showMap() {
    cout << "Address of this [Class_5_8] and members: ";
    cout << (long)this << " " << (long)&this->a << " " << (long)&this->b << " " << (long)&this->c << endl;
}

Stack_5::Stack_5(int maxSz) {
    maxSize = maxSz;
    storage = new void*[maxSz];
    sp = 0;
}

void Stack_5::push(void* value) {
    if (sp == maxSize) return;
    storage[sp++] = value;
}

void* Stack_5::pop() {
    if (sp == 0) return NULL;
    return storage[--sp];
}
