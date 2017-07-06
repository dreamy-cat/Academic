#ifndef L_05_CHAPTER_01_H
#define L_05_CHAPTER_01_H

#include <string>
#include <iostream>

class StringInsens {
public:
    StringInsens(const char *str);
    const char* getData() const;
    friend int operator==(const StringInsens& lv, const char* rv);
private:
    const char* text;
};

template<typename T, size_t size>
class Vector_1 {
public:
    Vector_1(T start) {
        std::cout << "Vector_1 constructor." << std::endl;
        for (int i = 0; i < size; i++) data[i] = T(start++);
    }

    Vector_1(const Vector_1& rv) {
        for (int i = 0; i < size; ++i) data[i] = rv.data[i];
    }

    Vector_1& operator=(const Vector_1& rv) {
        for (int i = 0; i < size; ++i) data[i] = rv.data[i];
        return *this;
    }

    void elements() {
        std::cout << "Elements in vector: ";
        for (int i = 0; i < size; ++i) std::cout << data[i] << " ";
        std::cout << std::endl;
    }

    void function_1(Vector_1 v) {
        std::cout << "Vector_1::function_1. ";
        v.elements();
    }

    typedef T* iterator;
    typedef const T* const_iterator;
    T* begin() { return  data; }
    T* end() { return data + size; }
    const T* begin() const { return data;  }
    const T* end() const { return data + size; }
private:
    T data[size];
};

#endif
