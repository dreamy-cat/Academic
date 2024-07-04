#ifndef CHAPTER_08_H
#define CHAPTER_08_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "memory.h"


const int iTask4 = 1;

namespace Labs_0x01 {

const int int7 = 7;

}

void function_8_13(const char c);

void function_8_14(float f);

class Class_8_15 {
public:
    Class_8_15(int ii = 0);
    void modify();
private:
    int i;
};

Class_8_15 function_8_15_1 ();

const Class_8_15 function_8_15_2 ();

void function_8_15_3 (Class_8_15& cl);

void function_8_16_1 (int*);

void function_8_16_2 (const int* cip);

const char* function_8_16_3 ();

const int* const function_8_16_4();

void function_8_17_1 (int&);

void function_8_17_2 (const int& cip);

const char &function_8_17_3();

const int& function_8_17_4();

class Class_8_18 { };

Class_8_18 function_8_18_1 ();

void function_8_18_2 (Class_8_18&);

void function_8_18_3 (const Class_8_18&);

class Class_8_19 {
public:
    Class_8_19(float f1, float f2);
private:
    float float1;
    const float float2;
};

class StringStack8 {
public:
    StringStack8();
    void push(const std::string* s);
    const std::string* pop();
private:
    static const int size = 5;
    const std::string* stack[size];
    int index;
};

class Class_8_21 {
public:
    Class_8_21(int ia);
private:
    enum { one, two, three };
    const int a;
    char mchar[three];
};

class Class_8_22 {
public:
    Class_8_22(int ii);
    int function() const;
private:
    int i;
};

class Class_8_23 {
public:
    Class_8_23();
    void function_1 ();
    void function_2 () const;
};

class Class_8_24 {
public:
    Class_8_24();
private:
    void function_1 ();
    void function_2 () const;
};

class Class_8_25 {
public:
    Class_8_25 ();
    void function_1 () const;
private:
    int i;
    mutable int j;
};

class Quoter8 {
public:
    Quoter8();
    int lastQuote() const;
    const char* quote() const;
private:
    mutable int lastquote;
};

class Class_8_27 {
public:
    Class_8_27();
    void function_1 ();
    void function_2 () volatile;
private:
    char a;
    volatile char b;
};

class Class_8_28_1 {
public:
    Class_8_28_1();
    void function_1 ();
};

class Class_8_28_2 {
public:
    Class_8_28_2();
};

#define FIELD(a) private: char* a##_string; int a##_size; int a##_index; public: char* a##_get() { return a##_string; }

class Record9 {
public:
    Record9 (char* str) {
        one_string = str;
        two_string = str;
        three_string = str;
    }
    char* select (int index) {
        if (index == 0) return one_string;
        if (index == 1) return two_string;
        if (index == 2) return three_string;
        return 0;
    }
private:
    FIELD(one);
    FIELD(two);
    FIELD(three);
};

#endif // CHAPTER_08_H
