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

#endif
