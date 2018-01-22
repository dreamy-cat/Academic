#ifndef LABS_0x06_HPP
#define LABS_0x06_HPP

#include <iostream>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <assert.h>

void labs_0x06();

namespace Labs_0x06 {

void function_1(std::vector<int>& v);

void toString(int i, char* buffer, const int maxSize);

template<class Container, class OutputIt>
OutputIt copyIt(const Container& c, OutputIt result) { return std::copy(c.begin(), c.end(), result); }

class Class_1 {
public:
    Class_1(char i);
    void function();
private:
    char c;
};

class Base_1 {
public:
    virtual void function_1();
    virtual void function_2();
    virtual ~Base_1();
};

class Derived_1 : public Base_1 {
    void function_1();
    void function_2();
public:
};

void function_2(Base_1& value);

class Class_2 {
public:
    void function_1(bool b = true);
    void function_2();
};

class Class_3 {
public:
    void function_1();
    void function_2(double d = 0.0);
};

class Class_4 {
public:
    Class_4(char i);
    void swap(Class_4&);
    char c;
};

template<class T> class Class_5 {
public:
    Class_5();
    // friend void function_5(T* ptr);     // friend declaration declares a non-template function
};

template<class T> class Class_5<T*>  {};

template<> class Class_5<int> {};

template<class T> struct Struct_1 {
    static void function(T value) {
        std::cout << "Function in Struct_1, parameter " << value << std::endl;
    }
};

void function_7() throw(int, char);

void UnxpectedHandler();

void function_8();

int function_9() throw();

int function_10() throw(int, bool);

void function_11() throw(char, bool);

// typedef void (*ptr)() throw(char, bool);     // declared with an exception specification.

class Base_2 {
public:
virtual void function() throw(int, char);
};

class Derived_2 : public Base_2 {
public:
    // void function();        // looser throw specifier.
    void function() throw(int, char);
};

}

#endif
