#ifndef LABS_05_CHAPTER_10_H
#define LABS_05_CHAPTER_10_H

#include <iostream>
#include <map>
#include <cassert>
#include <typeinfo>
#include <string>
#include <vector>

class Base_10 {
public:
    Base_10(char i);
    char a;
    virtual ~Base_10();
};

class Derived_10 : public Base_10 {
public:
    Derived_10(char i);
    Derived_10 function() const;
    char b;
};

class Lines {
public:
    Lines();
    void addLine(int id = 0, const int size = 0);
    bool isExist(int id = 0) const;
    int getSize() const;
    std::map<int, int> data;
};

const Lines operator+(const Lines& lv, const Lines& rv);

class Base_10_1 {
public:
    Base_10_1() : a('a') {}
    char a;
};

class Derived_10_1 : private virtual Base_10_1 {};

class Derived_10_2 : public Base_10_1 {};

class Derived_10_3 : public Derived_10_1, public Derived_10_2 {};

typedef int tBool;

const tBool yep = 1;

const tBool nop = 0;

void function_10(tBool f);

// void function_10_1(int f) {}     // redefinition.

class typeBoolC {
public:
    typeBoolC();
    typeBoolC(int value);
    typeBoolC& operator=(int);
    // oeprator int ();
    // operator void*();
private:
    unsigned char data;
};

bool function_10_2a(int a);

bool function_10_2b(const int &b);

typedef std::vector<std::string> Text;

typedef std::vector<std::string>::iterator TextIterator;

void function_10_3(Text& value);

namespace NameSpace_1 {
    int function(int a);
    static int integer;
}

namespace NameSpace_2 {

class Class_10a {
public:
    Class_10a(int a);
};

class Class_10b {
public:
    Class_10b(int a);
};

    int function_1();
    int fucntion_1(int);
    int function_2(double b);
}

namespace NameSpace_3 {

class Class_11a {
public:
    Class_11a();
};

int function(double d);

}

void function_10e();

namespace NameSpace_3 {

class Class_11b {
public:
    Class_11b();
};

int function(int d);

}

#endif
