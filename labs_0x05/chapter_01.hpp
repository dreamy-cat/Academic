#ifndef L_05_CHAPTER_01_H
#define L_05_CHAPTER_01_H

#include <string>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <assert.h>

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

std::string& function_1_6(std::list<std::string> &source, std::string &value);

std::string function_1_7(const std::list<std::string> &source, const std::string &value);

template<typename I, typename O>
void function_1_8(I& in, O& out)
{
    std::cout << "Function_1_8: " << in << " " << out << std::endl;
}

template<typename I>
I removeValue(I first, I last, size_t n)
{
    return (std::remove(first, last, n));        // Simple solution.
}

class Class_1_9 {
public:
    Class_1_9(size_t n) : iter(0), max(n) {}
    template<typename T>
    bool operator() (const T&) { return (++iter == max); }
private:
    size_t iter, max;
};

template<typename I>
I removeValueRange (I first, I last, size_t n)
{
    assert(std::distance(first, last) >= n);
    std::advance(first, n);
    if (first != last) {
        I dst = first;
        return std::copy(++first, last, dst);
    }
    return last;
}

template<typename I, typename P>
I find_10(I first, I last, P predic)
{
    while (first != last && !predic(*first)) first++;
    return first;
}

bool greaterSeven(int i);

bool isGreater_1(std::vector<int>& source);

class Greater_1 : public std::unary_function<int, bool> {
public:
    bool operator()(int i) const;
};

bool isGreater_2(std::vector<int>& source);

class Greater_2 : public std::unary_function<int, bool> {
public:
    Greater_2(int rv);
    bool operator()(int i) const;
private:
    const int value;
};

bool isGreater_3(std::vector<int>& source);

template<typename T>
class Greater_3 : public std::unary_function<int, bool> {
public:
    Greater_3(T rv) : value(rv) {}
    bool operator()(const T& t) const { return t > value; }
private:
    const int value;
};

bool isGreater_4(std::vector<int>& source);

#endif
