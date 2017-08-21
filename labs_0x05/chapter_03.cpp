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

