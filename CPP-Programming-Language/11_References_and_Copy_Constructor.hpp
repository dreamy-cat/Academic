﻿#ifndef CHAPTER_11_H
#define ChAPTER_11_H

#include <iostream>
#include <cstring>
#include <memory>
#include <vector>

int& function_11_4(int& i);

class Class_11_5 {
public:
    Class_11_5();
    void function_1 ();
    void function_2 () const;
};

void function_11_5(Class_11_5& clPtr);

void function_11_6(int*& iRef);

void function_11_7(int**& iRef);

void function_11_8(char& cRef);

class Class_11_9 {
public:
    Class_11_9();
    void function_1();
    void function_2() const;
};

void function_11_9_1(Class_11_9 cl);

void function_11_9_2(Class_11_9& cl);

void function_11_9_3(const Class_11_9& cl);

int function_11_10(int i);

void function_11_11(char c, int i, float f, double d);

double function_11_12(double d);

struct Structure_13 {
    char buf[32];
    int i;
    long l;
};

Structure_13 function_11_13(Structure_13 st);

void function_11_14(int r);

class Class_11_15_1 {
public:
    Class_11_15_1() { std::cout << "Class_11_15_1 constructor." << std::endl; }
    Class_11_15_1(const Class_11_15_1& r) { std::cout << "Copy constructor of Class_11_15_1." << std::endl; t = r.t; }
    int t;
};

class Class_11_15_2 {
public:
    Class_11_15_2() { std::cout << "Class_11_15_2 constructor." << std::endl; }
//    Class_11_15_2(const Class_11_15_2& l) { std::cout << "Making copy of Class_11_15_2." << std::endl; s = l.s; }
    int s;
    Class_11_15_1 clP;
};

void function_11_15(int i, Class_11_15_2 cl);

class Class_11_16 {
public:
    Class_11_16();
    Class_11_16(const Class_11_16&r);
    std::string str;
};

void function_11_16_1(Class_11_16 cl);

Class_11_16 function_11_16_2();

class Class_11_17 {
public:
    Class_11_17(double i);
    Class_11_17(const Class_11_17& l);
    ~Class_11_17();
    double* dPtr;
};

void function_11_17(Class_11_17 value);

class Class_11_18 {
public:
    Class_11_18();
    Class_11_18(const Class_11_18& l, int i = 0);
};

void function_11_18(Class_11_18 value);

class Class_11_19_1 {
public:
    Class_11_19_1();
    Class_11_19_1(const Class_11_19_1&);
};

class Class_11_19_2 {
public:
    Class_11_19_2();
    void function_1(Class_11_19_2 clV);
private:
    Class_11_19_1 cl;
};

class Class_11_20 {
public:
    Class_11_20();
};

Class_11_20 function_11_20_1();

void function_11_20_2(const Class_11_20 &value);

class Class_11_21 {
public:
    Class_11_21();
private:
    Class_11_21(const Class_11_21&);
};

void function_11_21(Class_11_21 cl);

class Class_11_22 {
public:
    Class_11_22();
    Class_11_22* clone() const;
private:
    Class_11_22(const Class_11_22&);
};

void function_11_22(const Class_11_22& value);

class Class_11_24 {
public:
    Class_11_24(double di);
    void print();
    double d;
};

class Class_11_25 {
public:
    Class_11_25(int iAr[]);
    int ar[3];
};

class Class_11_26 {
public:
    int f(float) const { return 1; }
    int f(bool) const { return 3; }
};

class Mem_11 {
public:
    Mem_11(int sz = 0);
    Mem_11(const Mem_11&l);
    ~Mem_11();
    int msize() const;
    unsigned char* pointer(int minSize = 0);
private:
    unsigned char* mem;
    int size;
    void ensureMinSize(int minSize);
};

class String_11 {
public:
    String_11(const char* str = 0);
    String_11(const String_11& l);
    ~String_11();
    void concat(const char* str);
    void print(std::ostream& os);
private:
    Mem_11* buf;
};

void function_11_23_1(String_11 stc);

void function_11_23_2(Mem_11 m);

class Class_11_27;

class Class_11_27 {
public:
    Class_11_27();
    void add(void(Class_11_27::*f)());
    void remove(void (Class_11_27::*f)());
    void run();
    void function_1();
    void function_2();
    void function_3();
private:
    std::vector<void(Class_11_27::*)()> functions;
};

#endif
