#include "chapter_08.h"

using namespace std;

void function_8_13(const char c) {
    // c++;
}

void function_8_14(float f) {
    const float& fr = f;
    cout << "Reference to float = " << fr << endl;
}

Class_8_15::Class_8_15(int ii) : i(ii) {

}

void Class_8_15::modify() {
    i++;
}

Class_8_15 function_8_15_1 () {
    return Class_8_15();
}

const Class_8_15 function_8_15_2() {
    return Class_8_15();
}

void function_8_15_3 (Class_8_15& cl) {
    cl.modify();
}

void function_8_16_1 (int*) {}

void function_8_16_2 (const int* cip) {
    // Assigment of read only location '*cip'
    // *cip = 2;
    int i = *cip;
    // Invalid conversation from 'const int*'
    // int* ip2 = cip;
}

const char* function_8_16_3 () {
    return "result of function_8_16_3";
}

const int* const function_8_16_4() {
    static int i = 1;
    return &i;
}

void function_8_17_1 (int&) {}

void function_8_17_2 (const int& cip) {
    // Assigment of read only location '*cip'
    // cip = 2;
    int i = cip;
    i++;
    // Invalid initialization of reference of type 'int&' from expression of type 'const int'
    // int& ip2 = cip;
}

const char& function_8_17_3 () {
    static const char* r = "result of function_8_16_3";
    const char& rp = *r;
    return rp;
}

const int& function_8_17_4() {
    static int i = 1;
    return i;
}

Class_8_18 function_8_18_1 () {
    return Class_8_18();
}

void function_8_18_2 (Class_8_18&) {}

void function_8_18_3 (const Class_8_18&) {}

Class_8_19::Class_8_19(float f1, float f2) : float1(f1), float2(f2) {
    cout << "Class_8_19 floats : " << float1 << " " << float2 << endl;
}

StringStack8::StringStack8() : index(0) {
    memset(stack, 0, size * sizeof(string*));
}

void StringStack8::push(const string *s) {
    if (index < size) stack[index++] = s;
}

const string* StringStack8::pop() {
    if (index > 0) {
        const string* r = stack[--index];
        stack[index] = 0;
        return r;
    }
    return 0;
}

Class_8_21::Class_8_21(int ia) : a(ia) {}

Class_8_22::Class_8_22(int ii) : i(ii) {}

int Class_8_22::function() const {
    // Prototype for 'int Class_8_22::function()' does not match any in class 'Class_8_22'
    return i;
}

Class_8_23::Class_8_23 () {}

void Class_8_23::function_1() {
    cout << "Class_8_23 function 1." << endl;
}

void Class_8_23::function_2() const {
    cout << "Class_8_23 constant function 2." << endl;
}
