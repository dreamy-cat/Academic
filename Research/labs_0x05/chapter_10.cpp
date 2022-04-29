#include "chapter_10.hpp"

using namespace std;
using namespace NameSpace_3;

int IDCounter = 0;

void function_10(tBool f) { cout << "Trying to compile.\n"; }

Base_10::Base_10(char i) : a(i) {}

Base_10::~Base_10() {}

Derived_10::Derived_10(char i) : Base_10(i), b(i) {}

Derived_10 Derived_10::function() const { return *this; }

Lines::Lines() {
    cout << "Creating Lines class, clear map.\n";
    data.clear();
}

void Lines::addLine(int id, const int size) {
    if (id < 0 || size < 0 || data.find(id) != data.end()) {
        cout << "Can't add new line, parameters not valid.\n";
        return;
    }
    data[id] = size;
}

bool Lines::isExist(const int id) const {
    if (data.find(id) != data.end())
        return true;
    else
        return false;
}

int Lines::getSize() const { return data.size(); }

const Lines operator+(const Lines& lv, const Lines& rv) {
    Lines result;
    int counter = 0;
    cout << "Operator+() for Lines, elements of map: ";
    for (map<int, int>::const_iterator itl = lv.data.begin(), itr; itl != lv.data.end(); ++itl)
        if ((itr = rv.data.find((*itl).first)) != rv.data.end()) {
            result.data[(*itl).first] = (*itl).second + (*itr).second;
            cout << (*itl).first << "[" << result.data[(*itl).first] << "] ";
            counter++;
        }
    cout << "complete operations, " << counter << endl;
    return result;
}

typeBoolC::typeBoolC() : data(0) {}

typeBoolC::typeBoolC(int value) : data(value) {}

typeBoolC& typeBoolC::operator=(int rv) {
    this->data = rv;
    return *this;
}

bool function_10_2a(int a) { cout << "Second function called, parameter " << a << endl; }

bool function_10_2b(const int& b) { return function_10_2a(b); }

typedef int (*Function)(int*);

Function f1(int);

void function_10_3(Text& value) { cout << "The size of vector is " << value.size() << endl; }

int NameSpace_1::function(int a) { return ++a; }

NameSpace_2::Class_10a::Class_10a(int a) { cout << "Class_10a, in NameSpace_2 called, parameter is " << a << endl; }

NameSpace_2::Class_10b::Class_10b(int a) { cout << "Class_10b, in NameSpace_2 called, parameter is " << a << endl; }

int NameSpace_2::function_1() { cout << "NameSpace_2, function without parameters." << endl; }

int NameSpace_2::fucntion_1(int a) { cout << "NameSpace_2, function with int " << a << endl; }

int NameSpace_2::function_2(double d) { cout << "NameSpace_2, function with double " << d << endl; }

NameSpace_3::Class_11a::Class_11a() { cout << "NameSpace_3, class_11a constructor." << endl; }

NameSpace_3::Class_11b::Class_11b() { cout << "NameSpace_3, class_11b constructor." << endl; }

int NameSpace_3::function(double d) { cout << "NameSpace_3, function(double), parameter " << d << endl; }

void function_10e() {
    Class_11a cl1;
    Class_11b cl2;                  // class was not declared in this scope.
    NameSpace_3::function(1.0);     // call of overloaded function is ambigious.
}
