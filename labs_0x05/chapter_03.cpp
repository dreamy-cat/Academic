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
