#ifndef L_02_CHAPTER_05_H
#define L_02_CHAPTER_05_H

#include <iostream>
#include <vector>
#include <list>
#include <stack>

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
private:
    std::vector<T> stack;
};

#endif
