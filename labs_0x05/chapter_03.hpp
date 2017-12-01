#ifndef LAB_05_CHAPTER_03_H
#define LAB_05_CHAPTER_03_H

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

template<class T>
class List {
public:
    bool insert(const T&, size_t idx);
    T access(size_t idx) const;
    size_t size() const;
private:
    T* buffer;
    size_t bufferSize;
};

template<class T>
class Set_1 : private List<T> {
public:
    bool add(const T&);
    T get(size_t idx);
    using List<T>::size;
};

template<class T>
class Set_2 {
public:
    bool add(const T&);
    T get(size_t idx) const;
    size_t size() const;
private:
    List<T> implementation;
};

template< class T, class Impl = List<T> >
class Set_3 {
public:
    bool add(const T&);
    T get(size_t idx) const;
    size_t size() const;
private:
    Impl implementation;
};

class Base_1 {
public:
    virtual int function_1();
protected:
    bool function_2();
private:
    bool function_3();
};

class Derived_1 : private Base_1 {
public:
    int function_1();
};

class Derived_2 : private Base_1 {
public:
    int function_1();
};

class Derived_3 {
private:
    Derived_2 implementation;
};

class Class_3_A {
public:
    virtual ~Class_3_A();
    std::string word();
private:
    virtual std::string printWord();
};

class Class_3_B : virtual public Class_3_A {
private:
    std::string printWord();
};

class Class_3_C : virtual public Class_3_A {
private:
    std::string printWord();
};

class Class_3_D : public Class_3_B, public Class_3_C {
private:
    std::string printWord();
};

class Class_3_E : public Class_3_B {
public:
    class Class_3_F : public Class_3_C {
    public:
        void set(Class_3_E* ptr) { pointer = ptr; }
    private:
        Class_3_E* pointer;
        std::string printWord() { return pointer->printWord(); }
    } obj;
    Class_3_E() { obj.set(this); }
    Class_3_E(const Class_3_E& other) : Class_3_B(other), obj(other.obj) { obj.set(this); }
    Class_3_E& operator=(const Class_3_E& other) {
        Class_3_B::operator=(other);
        obj = other.obj;
        return *this;
    }
    operator Class_3_C&() { return obj; }
    Class_3_C& asClass3C() { return obj; }
private:
    std::string printWord() { return "D"; }
};

void function_3_1(const std::string& comment, Class_3_A& value);

void function_3_2(const std::string& comment, Class_3_B& value);

void function_3_3(const std::string& comment, Class_3_C& value);

class Base_3_9A {
public:
    virtual void function();
};

class Base_3_9B {
public:
    virtual void function();
};

class Derived_3_9A : public Base_3_9A, public Base_3_9B {
public:
    void function();
};

class Base_3_9C : public Base_3_9A {
public:
    virtual void function_A() = 0;
private:
    void function();
};

class Base_3_9D : public Base_3_9B {
public:
    virtual void function_B() = 0;
private:
    void function();
};

class Derived_3_9B : public Base_3_9C, public Base_3_9D {
public:
    void function_A();
    void function_B();
private:
    void function();
};

class Base_3_10 {
public:
    virtual bool function() = 0;
    virtual void function_2() = 0;
    virtual ~Base_3_10() = 0;
private:
    virtual bool function_1() = 0;
};

class Derived_3_10 : public Base_3_10 {
public:
    bool function();
    bool function_1();
    void function_2();
    Derived_3_10();
    ~Derived_3_10();
};

void function_3_4(Base_3_10& base);

#endif
