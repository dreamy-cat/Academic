#include "chapter_04.hpp"

using namespace std;

Base_4_3::Base_4_3() : objPtr(new Base_4_5) {}

Base_4_3::~Base_4_3() {
    delete objPtr;
    objPtr = nullptr;
}

Class_4_5A::Class_4_5A() { cout << "Class_4_5A, constructor.\n"; }

Class_4_5A::~Class_4_5A() { cout << "Class_4_5A, destructor.\n"; }

Class_4_5B::Class_4_5B() {
    if (sx >= sizeof(Class_4_5A)) cout << "Size of Class_4_5A is more than " << sx << endl;
    new(&obj[0]) Class_4_5A;
}

Class_4_5B::~Class_4_5B() {
    (reinterpret_cast<Class_4_5A*>(&obj[0]))->~Class_4_5A();
}
