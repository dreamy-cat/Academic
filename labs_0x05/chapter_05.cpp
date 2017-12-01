#include "chapter_05.hpp"

using namespace std;

void NameSpace_A::function_1(int i) { cout << "NameSpace_A::function_1().\n"; }

void NameSpace_A::function_2(NameSpace_A::Struct_1 st) { cout << "NameSpace_A::function_2().\n"; }

void NameSpace_B::function_1(int i) { function_1(i); }

void NameSpace_B::function_2(NameSpace_A::Struct_1 st) {
    // function_2(st);  // not compile with gcc.
    NameSpace_A::function_2(st);
    cout << "NameSpace_B::function_2(NameSpace_A::struct_1 st).\n";
}

void NameSpace_B::function_3(NameSpace_A::Struct_2 st) { function_3(st); }

NameSpace_C::Class_5_1::Class_5_1(const char* name, const char* mode) {
    cout << "NameSpace_C::Class_5_1 constructor, parameters " << name << ", " << mode << endl;
}

NameSpace_C::Class_5_1::~Class_5_1() {}

void NameSpace_C::Class_5_1::function_5_1(const NameSpace_C::Class_5_1 &value) {
    cout << "NameSpace_C::Class_5_1 function member.\n";
}

void function_5_1(const NameSpace_C::Class_5_1& value) {
    cout << "Function_5_1, function without namepsace or class.\n";
}

void NameSpace_D::function_5_1(NameSpace_C::Class_5_1& value) {
    cout << "NameSpace_D::function_5_1(...).\n";
}

void NameSpace_D::function_5_2(NameSpace_C::Class_5_1& value) {
    cout << "NameSpace_D::function_5_2(...), calling function_5_1().\n";
    function_5_1(value);
}

ostream& NameSpace_C::Class_5_1::print(ostream&) const { cout << "Class_5_1, print().\n"; }

std::ostream& operator<<(std::ostream& os, NameSpace_C::Class_5_1& value) {
    value.print(os);
}

NameSpace_E::Class_5_2::Class_5_2() : a(0) {}

int NameSpace_E::operator+(int i, Class_5_2 rv) { return rv.a + i; }

int Struct_5A::function_1(int) { cout << "Struct_5A::function_1(int).\n"; }

int Struct_5A::function_1(double) { cout << "Struct_5A::fucntion_1(double).\n"; }

int Struct_5A::function_2(int) { cout << "Struct_5A::function_2(int).\n"; }

int Struct_5B::function_2(string, bool) { cout << "Struct_5B::function_2(string, bool).\n"; }
