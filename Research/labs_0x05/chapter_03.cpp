#include "chapter_03.hpp"

using namespace std;

Complex::Complex(double real, double imaginary) : r(real), i(imaginary) {}

const Complex operator+(const Complex& lv, const Complex& rv) {
    Complex r(lv);
    r += rv;
    return r;
}

ostream& operator << (ostream& os, const Complex& value) {
    cout << "Complex number, real " << value.r << ", imaginary " << value.i << endl;
}

Complex& Complex::operator+=(const Complex& rv) {
    r += rv.r;
    i += rv.i;
    return *this;
}

Complex& Complex::operator++() {
    ++r;
    return *this;
}

Complex Complex::operator++(int) {
    Complex tmp(*this);
    ++*this;
    return tmp;
}

Class_3_2::~Class_3_2() { cout << "Class_3_2 destructor.\n"; }

void Class_3_2::function_1(int) { cout << "Class_3_2::function_1(int).\n"; }

void Class_3_2::function_1(double) { cout << "Class_3_2::function_1(double).\n"; }

void Class_3_2::function_2(int i) { cout << "Class_3_2::function_2(int), i = " << i << endl; }

void Class_3_2_1::function_1(std::complex<double>) { cout << "Class_3_2_1::function_1(complex<double>.\n"; }

void Class_3_2_1::function_2(int i) { cout << "Class_3_2_1::function_2(int i), i = " << i << endl; }

bool Struct_3_3::filter(const std::string& str) { return true; }

Class_3_3::Class_3_3() {}

Class_3_3::~Class_3_3() {}

bool Class_3_3::process(const std::vector<std::string>& table) { return true; }

Class_3_A::~Class_3_A() { cout << "Class_3_A destructor.\n"; }

string Class_3_A::word() { return printWord(); }

string Class_3_A::printWord() { return "Class_3_A.\n"; }

string Class_3_B::printWord() { return "Class_3_B.\n"; }

string Class_3_C::printWord() { return "Class_3_C.\n"; }

string Class_3_D::printWord() { return "Class_3_D."; }

void function_3_1(const std::string& comment, Class_3_A& value) { cout << comment << value.word() << endl; }

void function_3_2(const std::string& comment, Class_3_B& value) { cout << comment << value.word() << endl; }

void function_3_3(const std::string& comment, Class_3_C& value) { cout << comment << value.word() << endl; }

void Base_3_9A::function() { cout << "Base_3_9A.\n"; }

void Base_3_9B::function() { cout << "Base_3_9B.\n"; }

void Derived_3_9A::function() { cout << "Derived_3_9A.\n"; }

void Derived_3_9B::function() { cout << "Derived_3_9B.\n"; }

void Base_3_9C::function() { return function_A(); }

void Base_3_9D::function() { return function_B(); }

void Derived_3_9B::function_A() { cout << "Derived_3_9B::function_A().\n"; }

void Derived_3_9B::function_B() { cout << "Derived_3_9B::function_B().\n"; }

Base_3_10::~Base_3_10() { "Base_3_10, public pure virtual destructor.\n"; }

bool Base_3_10::function() { return true; }

Derived_3_10::Derived_3_10() { cout << "Derived_3_10, constructor.\n"; }

Derived_3_10::~Derived_3_10() { cout << "Derived_3_10, destructor.\n"; }

bool Derived_3_10::function() { cout << "Default function of base class, returning " << Base_3_10::function() << endl; }

bool Base_3_10::function_1() {
    cout << "This pure virtual function shouldn't call.\n";
    /*   Some funny methods to exit.
     * memset(0, 1, 1);
     * abort();
     * static_cast<char*>(0) = 0;
     * static_cast<void>(*)()>(0)();
     * class LocalClass {}
     * throw LocalClass();
     * throw std::logic_error();
     * throw 0;
     * */
}

bool Derived_3_10::function_1() { cout << "Derived_3_10::function_1().\n"; }

void Derived_3_10::function_2() { cout << "Derived_3_10::function_2().\n"; }

void function_3_4(Base_3_10& base) {
    cout << "Function_3_4, calling base->function_2(). ";
    base.function_2();
}
