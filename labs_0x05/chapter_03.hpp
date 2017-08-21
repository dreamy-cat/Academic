#ifndef L_05_CHAPTER_03_H
#define L_05_CHAPTER_03_H

#include <iostream>
#include <complex>
#include <vector>
#include <string>

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

class Class_3_2 {
public:
    virtual void function_1(int);
    virtual void function_1(double);
    virtual void function_2(int i = 1);
    virtual ~Class_3_2();
};

class Class_3_2_1 : public Class_3_2 {
public:
    void function_1(std::complex<double>);
    void function_2(int i = 2);
};

class Struct_3_3;

class Class_3_3 {
public:
    Class_3_3();
    ~Class_3_3();
    bool process(const std::vector<std::string>& table);
private:
    Struct_3_3* impl;
};

class Struct_3_3 {
public:
    // virtual Struct_3_3() = 0;        // Not compile, may be misprinting.
    Struct_3_3();
    virtual bool filter(const std::string& str);
    virtual bool processVector(const std::string& key) = 0;
};

#endif
