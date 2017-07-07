#ifndef L_05_CHAPTER_01_H
#define L_05_CHAPTER_01_H

#include <string>
#include <iostream>
#include <algorithm>

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
        std::cout << "Vector_1, copy constructor.\n";
        for (int i = 0; i < size; ++i) data[i] = rv.data[i];
    }

    Vector_1& operator=(const Vector_1& rv) {
        std::cout << "Vector_1, operator=().\n";
        for (int i = 0; i < size; ++i) data[i] = rv.data[i];
        return *this;
    }

    void elements() {
        std::cout << "Elements in vector: ";
        for (int i = 0; i < size; ++i) std::cout << data[i] << " ";
        std::cout << std::endl;
    }

    T* begin() { return  data; }
    T* end() { return data + size; }
    const T* begin() const { return data;  }
    const T* end() const { return data + size; }
private:
    T data[size];
};

template<typename T, size_t size>
class Vector_2 {
public:
    Vector_2() : data(new T[size]) { std::cout << "Vector_2, constructor.\n"; }
    ~Vector_2() {
        std::cout << "Vector_2 destructor.\n";
        delete [] data;
    }

    template<typename U, size_t uSize>
    Vector_2(const Vector_2<U, uSize>& rv) : data( new T[size]) {
        std::cout << "Vector_2, copy constructor with template.\n";
        try {
            std::copy(rv.begin(), rv.begin() + std::min(size, uSize), begin());
        } catch (...) { delete [] data; throw; }
    }

    Vector_2(const Vector_2<T, size>& rv) : data( new T[size] ) {
        std::cout << "Vector_2, copy constructor.\n";
        try {
            std::copy(rv.begin(), rv.end(), begin() );
        } catch (...) { delete [] data; throw; }
    }

    void swap( Vector_2<T, size>& rv) throw() { std::swap(data, rv.data); }

    template<typename U, size_t uSize>
    Vector_2<T, size>& operator=(const Vector_2<U, uSize>& rv) {
        std::cout << "Using Vector_2::operator=(), with template.\n";
        Vector_2<T, size> tmp(rv);
        swap(tmp);
        return *this;
    }

    Vector_2<T, size>& operator=(const Vector_2<T, size>& rv)
    {
        std::cout << "Vector_2, operator=().\n";
        Vector_2<T, size> tmp(rv);
        swap(tmp);
        return *this;
    }

    T* begin() { return data; }
    T* end() { return data + size; }
    const T* begin() const { return data; }
    const T* end() const { return data + size; }
private:
    T* data;
};

#endif
