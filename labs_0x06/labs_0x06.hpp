#ifndef LABS_0x06_HPP
#define LABS_0x06_HPP

#include <iostream>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <complex>
#include <assert.h>
#include <memory.h>

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

class Base_3 {
public:
    Base_3(const std::string& s);
    std::string getString();
};

class Derived_3 : public Base_3 {
public:
    Derived_3();
private:
    std::string data;
};

class Base_3a {
public:
    Base_3a();
};

class Base_3b {
public:
    Base_3b();
};

class Base_3c {
public:
    Base_3c();
};

class Virtual_3a : public Base_3a {
public:
    Virtual_3a();
};

class Virtual_3b : public Base_3a, public Base_3b {
public:
    Virtual_3b();
};

class Derived_3a : virtual public Virtual_3a {
public:
    Derived_3a();
};

class Derived_3b : virtual public Virtual_3b, public Base_3c {
public:
    Derived_3b();
};

class Class_6 : public Derived_3a, public Derived_3b {
public:
    char a, b;
};

class Class_7 {
public:
    Class_7(char ai) : a(ai) {}
    template<class T>
    void function(const T& value) {
        std::cout << "Class_7, function, parameter " << a << std::endl;
    }
    friend void function_12(Class_7& value);
private:
    char a;
};

namespace {
    struct Struct_2 {};
} template<> void Class_7::function(const Struct_2&) {
    std::cout << "In Class_7, parameter " << a << std::endl;
}

void function_12(Class_7& value);

class Base_4 {
private:
    virtual void function();
};

class Derived_4 : public Base_4 {
    void function();
};

class Class_8;

typedef int (Class_8::*PtrMem)(int);

class Class_8 {
public:
    PtrMem getPtr();
    double multiply(double d);
private:
    int multiply(int i);
    std::complex<float> multiply(std::complex<float> c);
};

template<class T, class U>
class Pair {
public:
    Pair() : deleted(false) {}
    void setDeleted() { deleted = true; }
    bool isDeleted() { return deleted; }
    T& first();
    U& second();
private:
    bool deleted;
    T firstP;
    U secondP;
};

class Class_9 {
public:
    Class_9(char i);
    char getChar() const;
    char c1;
protected:
    char getCharP() const;
    char c2;
private:
    char c3, c4;
};

class Base_5 {
public:
    Base_5();
    int process(const std::string &name);
    virtual ~Base_5();
private:
    virtual int processA(const std::string& name);
    virtual int processB(const std::string& name);
    virtual bool ready();
};

class Derived_5 : public Base_5 {
public:
    Derived_5();
    ~Derived_5();
    int processA(const std::string &name);
};

class Derived_6;
class Base_6 {
public:
    // virtual Base_6& operator=(const Derived_6&) throw(int);
    virtual ~Base_6() throw(int);
};

class Derived_6 : public Base_6 {
public:
    class Data {
    public:
        Data& operator=(const Data&) throw(char);
        ~Data() throw(int);
    };
    Data d;
    ~Derived_6();
    // ~Derived_6() throw(int, char);
};

class Base_7 {
public:
    Base_7(int a, int b);
    virtual ~Base_7();
private:
    Base_7(const Base_7&);
    Base_7& operator=(const Base_7&);
};

class Derived_7 : private virtual Base_7 {
public:
    Derived_7(int i, int j);
    int i;
};

struct Struct_3 {
    char c1;
    long l1;
    char c2;
};

struct Struct_4 {
    long l1;
    char c1;
    char c2;
};

class Base_8 {
public:
    static void* operator new(std::size_t, const void*);
};

class Derived_8 : public Base_8 {
public:
    static void* operator new(std::size_t) throw ();
    static void* operator new(std::size_t, const std::nothrow_t&) throw();
    static void* operator new(std::size_t, void*) throw();
};

const char& function_13(const int& i);

void function_14(const int i);

float square(float side);

class BitsVectorChars {
public:
    BitsVectorChars();
    ~BitsVectorChars();
    void append(unsigned char* p, size_t n);
    size_t size() const;
    void get(size_t p, size_t n, unsigned char* d);
    void print() const;
private:
    std::vector<unsigned char> buffer;
    size_t actualSize;
    static const int bitsPerChar = sizeof(char) * 8;
    BitsVectorChars(const BitsVectorChars&);
    BitsVectorChars& operator=(const BitsVectorChars&);
};

class BitsVectorBools {
public:
    BitsVectorBools();
    ~BitsVectorBools();
    void append(unsigned char* p, size_t n);
    void get(size_t p, size_t n, unsigned char* d);
    void print() const;
    size_t size() const;
private:
    std::vector<bool> buffer;
    size_t actualSize;
    static const int bitsPerChar = sizeof(char) * 8;
    BitsVectorBools(const BitsVectorBools&);
    BitsVectorBools& operator=(const BitsVectorBools&);
};

}   // namespace Labs_0x06.

#endif
