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
