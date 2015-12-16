#ifndef L_02_CHAPTER_05_H
#define L_02_CHAPTER_05_H

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <math.h>

template <typename T> void function_5_1(const T& value) {
    std::cout << "Template function_5_1()." << std::endl;
}

template<> void function_5_1(const int& value);

void function_5_1(const int& value);

template<class T> class Stack_5 {
public:
    void push(const T& value) {
        stack.push_back(value);
    }
    const T pop() {
        T r = stack.back();
        stack.pop_back();
        return r;
    }
    const T back() {
        return stack.back();
    }

private:
    std::vector<T> stack;
};

template<class T, template<class> class S>
class Stack_5_1 {
public:
    void push(const T& value) {
        stack.push(value);
    }
    const T pop() {
        T r = stack.back();
        stack.pop();
        return r;
    }
private:
    S<T> stack;
};

class Class_5_1 {};

struct Hard {
    Class_5_1 cl_1, cl_2;
//    void cmp() { return (cl_1 == cl_2); }
};

template<class T> struct Soft {
    Class_5_1 cl_3, cl_4;
    void nop() {}
    // void cmp() { cl_3 == cl_4; }
};

template<typename T> T function_5_5(T a[], int first, int last, T source = T()) {
    T sum = source;
    for (int i = first; i <= last; i++)
        sum += a[i];
    return sum;
}

int function_5_5(int a[], int first, int last, int source);

double function_5_5(double a[], int first, int last, double source);

class Friendly {};

template<class T> class Class_5_2 {
public:
    void play(Class_5_2<Friendly>& s) { s.i = 7; }
private:
    int i;
};

template<class T> double p_ag(T a, T b, T c) {
    return (-b + sqrt(double(b*b - 4*a*c))) / 2 * a;
}

class Class_5_3 {
public:
    static int a;
    static void function_1();
};

template<int n, int *nPtr, int* sPtr = Class_5_3::a, void (f)() = Class_5_3::function_1()> class class_5_4 {
public:
    int i;
};

template<class P, class Q> class Class_5_5 {
public:
    void function_1() {
        std::cout << "Template<P,Q> Class_5_5::function_1." << std::endl;
    }
};

template<class P> class Class_5_5<P, int> {
public:
    void function_1() {
        std::cout << "Template<P,int> Class_5_5::function_1, parameter = " << p << std::endl;
    }
    static const int p = 1;
};

template<class Q> class Class_5_5<int, Q> {
public:
    void function_1() {
        std::cout << "Template<int,Q> Class_5_5::function_1, parameter = " << p << std::endl;
    }
    static const int p = 2;
};

template<class T> class Class_5_6;

template<class T> class Class_5_6_1 {
public:
    void function_1() {
        std::cout << "template<class T> Class_6_1::function_1()." << std::endl;
    }
    friend class Class_5_6<T>;
};

template<> class Class_5_6_1<int> {
public:
    void function_1() {
        std::cout << "template<int> Class_6_1::function_1()." << std::endl;
    }
    friend class Class_5_6<int>;
};

template<class T> class Class_5_6_2 {
private:
    void function_1() {
        std::cout << "template<class T> Class_6_2::function_1()." << std::endl;
    }
    friend class Class_5_6<T>;
};

template<class T> class Class_5_6 {
public:
    void functionCalls() {
        cl_1.function_1();
        cl_2.function_1();
        cl_3.function_1();
    }
    Class_5_6_1<T> cl_1;
    Class_5_6_1<int> cl_2;
    Class_5_6_2<T> cl_3;
};

#endif
