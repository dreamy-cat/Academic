#include "chapter_14.h"

using namespace std;

Vehicle_14::Vehicle_14(int ii) : i(ii) {
    cout << "Vehicle_14 constructor, int = " << i << endl;
}

Car_14::Car_14(int ii) : Vehicle_14(ii) {
    cout << "Car_14 constructor." << endl;
}

Class_14_2_1::Class_14_2_1() {
    cout << "Class_14_2_1 constructor." << endl;
}

Class_14_2_2::Class_14_2_2() {
    cout << "Class_14_2_2 constructor." << endl;
}

Class_14_3_1::Class_14_3_1() {
    cout << "Class_14_3_1 constructor." << endl;
}

Class_14_3_1::~Class_14_3_1() {
    cout << "Class_14_3_1 destructor." << endl;
}

Class_14_3_2::Class_14_3_2() {
    cout << "Class_14_3_2 constructor." << endl;
}

Class_14_3_2::~Class_14_3_2() {
    cout << "Class_14_3_2 destructor." << endl;
}

Class_14_3_3::Class_14_3_3() {
    cout << "Class_14_3_3 constructor." << endl;
}

Class_14_3_3::~Class_14_3_3() {
    cout << "Class_14_3_3 destructor." << endl;
}

Combined_A::Combined_A(int ii) : i(ii) { cout << "Combined_A constructor." << endl; }

Combined_A::~Combined_A() { cout << "Combined_A destructor." << endl; }

Combined_B::Combined_B(int ii) : i(ii) { cout << "Combined_B constructor." << endl; }

Combined_B::~Combined_B() { cout << "Combined_B destructor." << endl; }

Combined_C::Combined_C(int ii) : Combined_B(ii), a(ii) { cout << "Combined_C constructor." << endl; }

Combined_C::~Combined_C() { cout << "Combined_C destructor." << endl; }

void Combined_C::function_1() const {
    cout << "Combined_C, function_1." << endl;
    a.function_1();
    Combined_B::function_1();
}

Combined_D::Combined_D(int ii) : Combined_B(ii), a2(ii) { cout << "Combined_D constructor." << endl; }

Combined_D::~Combined_D() { cout << "Combined_D destructor." << endl; }

Base_6::Base_6(int ii) { cout << "Base_6 constructor." << endl; }

Base_6::~Base_6() { cout << "Base_6 destructor." << endl; }

Member_6_1::Member_6_1(int ii) { cout << "Member_6_1 constructor." << endl; }

Member_6_1::~Member_6_1() { cout << "Member_6_1 destructor." << endl; }

Member_6_2::Member_6_2(int ii) { cout << "Member_6_2 constructor." << endl; }

Member_6_2::~Member_6_2() { cout << "Member_6_2 destructor." << endl; }

Derived_6_1::Derived_6_1(int ii) : Base_6(ii), m1(ii) { cout << "Derived_6_1 constructor." << endl; }

Derived_6_1::~Derived_6_1() { cout << "Derived_6_1 destructor." << endl; }

Derived_6_2::Derived_6_2(int ii) : Derived_6_1(ii), m2(ii) { cout << "Derived_6_2 constructor." << endl; }

Derived_6_2::~Derived_6_2() { cout << "Derived_6_2 destructor." << endl; }

Derived_6_3::Derived_6_3(int ii) : Derived_6_2(ii), m1(ii), m2(ii) { cout << "Derived_6_3 constructor." << endl; }

Derived_6_3::~Derived_6_3() { cout << "Derived_6_3 destructor." << endl; }

int Base_7::f() const {
    cout << "Base_7::f()." << endl;
    return 1;
}

int Base_7::f(std::string) const { return 1; }

int Base_7::h(int) {
    cout << "int Base_7::h(int)." << endl;
    return 5;
}

int Derived_7_1::h(int) {
    cout << "int Derived_7_1::h(int)." << endl;
    return 6;
}

int Derived_7_2::f() const {
    cout << "Derived_7_2::f()." << endl;
    return 2;
}

void Derived_7_3::f() const { cout << "Derived_7_3::f()." << endl; }

int Derived_7_4::f(int) const {
    cout << "Derived_7_4::f()." << endl;
    return 4;
}

StringStack::StringStack() {
    storage.clear();
}

void StringStack::push_back(std::string* string) {
    storage.push_back(string);
}

const std::string* StringStack::operator[](int index) const {
    return storage[index];
}

Class_14_10::Class_14_10(long i) { l = long(i); }
