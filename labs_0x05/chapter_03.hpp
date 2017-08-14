#ifndef L_05_CHAPTER_03_H
#define L_05_CHAPTER_03_H

#include <iostream>

class Complex {
public:
    explicit Complex(double real, double imaginary = 0);
    Complex& operator+=(const Complex& rv);
    friend const Complex operator+(const Complex& lv, const Complex& rv);
    friend std::ostream& operator << (std::ostream& os, const Complex& value);
    Complex& operator++();
    Complex operator++(int);
private:
    double r, i;
};

#endif
