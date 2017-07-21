#ifndef L_05_CHAPTER_01_H
#define L_05_CHAPTER_01_H

#include <string>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
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

template<typename T>
class Counter {
private:
    class Impl {
    public:
        Impl(T* ptr) : p(ptr), references(1) {}
        ~Impl() { delete p; }
        T* p;
        size_t references;
    };
    Impl* impl;
public:
    explicit Counter(T* ptr) : impl(new Impl(ptr)) {}
    ~Counter() { dec(); }
    Counter(const Counter& rv) : impl(rv.impl) { inc(); }
    Counter& operator=(const Counter& rv) {
        if (impl != rv.impl) {
            dec();
            impl = rv.impl;
            inc();
        }
        return *this;
    }
    T* operator->() const { return impl->p; }
    T& operator*() const { return *(impl->p); }
private:
    void dec() {
        std::cout << "Decreasing, references object " << impl->references << std::endl;
        if (--(impl->references) == 0) delete impl; }
    void inc() {
        std::cout << "Increasing, references object " << impl->references << std::endl;
        ++(impl->references);
    }
};

class Greater_4_1 {
public:
    Greater_4_1(size_t n);
    size_t i;
    const size_t m;
};

class Greater_4 {
public:
    Greater_4(size_t n) : impl(new Greater_4_1(n)) {}
    template<typename T>
    bool operator()(const T&) { return (++(impl->i) == impl->m); }
private:
    Counter<Greater_4_1> impl;
};

class Class_2 : public Greater_1 {
public:
    void testing() const;
};

template<typename T>
class Class_3 {
public:
    void function(const T* t) {
        std::cout << "Class_3::function().\n";
        t->testing();
    }
};

template<typename T>
class Class_4 {
public:
    ~Class_4() {
        std::cout << "Class_4, destructor.\n";
        const T t;
        t.testing();
    }
};

template<typename T>
class Class_5 {
public:
    ~Class_5() {
        void (T::*test)() const = &T::testing;
        test;
    }
};

template<typename T>
class Class_6 {
private:
    bool verify() const {
        std::cout << "Class_6, verify.\n";
        T* (T::*vrfy)() const = &T::testing;
        vrfy;
        return true;
    }
public:
    ~Class_6() {
        std::cout << "Class_6, destructor.\n";
        assert(verify());
    }
};

template<typename D, typename B>
class Class_7 {
private:
    class NotDerived {};
    class Derived { NotDerived nd[2]; };
    static Derived verify( B* );
    static NotDerived verify( ... );
public:
    enum { isExist = sizeof(verify(static_cast<D*>(0))) == sizeof(Derived) };
};

template<typename T>
class Class_8 {
private:
    bool verifyRequirments() const {
        std::cout << "Verify requirments for Class_6<Class_2>.\n";
        typedef Class_7<T, Class_2> t;
        assert(t::isExist);
        return true;
    }
public:
    ~Class_8() {
        verifyRequirments();
    }
};

template<typename D, typename B>
class Class_9 {
private:
    static void verifyRequirments(D* ptr) {
        B* pointer = ptr;
        pointer = ptr;
    }
protected:
    Class_9() { void (*p)(D*) = verifyRequirments; }
};

template<typename T>
class Class_10 : Class_9<T, Class_6<Class_2> > {
public:
    Class_10() { std::cout << "Class_10, constructor.\n"; }
};

template<typename D, typename B>
class Class_11 {                    // Variant with both methods.
private:
    class NotDerived {};
    class Derived { NotDerived nd[2]; };
    static Derived verify(B*);
    static NotDerived verify(...);
    static void verifyRequirments(D* p) {
        B* ptr = p;
        ptr = p;
        std::cout << "Class_11::verifyRequirments.\n";
    }
public:
    enum { isExist = sizeof(verify(static_cast<D*>(0))) == sizeof(Derived) };
    Class_11() {
        std::cout << "Class_11, constructor.\n";
        void (*p)(D*) = verifyRequirments;
    }
};

template<typename T, int>
class Class_12 {};

template<typename T>
class Class_12<T, 1> {};

template<typename T>
class Class_13 {
    Class_12<T, Class_11<T, Greater_1>::isExist> impl;
};

template<typename T>
class Class_14 {
public:
    static T* function(const T* ptr) { return new T(*ptr); }
};

class Class_14a : public Class_2 {
public:
    Class_14a();
    static Class_14a* verify();
};

template<>
class Class_14<Class_2> {
public:
    static Class_14a* function(const Class_14a* ptr) { return ptr->verify(); }
};

template<typename T>
class Class_15 {
public:
    typedef T obj;
};

template<typename A, typename B>
class Class_15a : public Class_15<B> {
public:
    bool operator()(const typename Class_15<A>::obj& i) const {
        return i != typename::Class_15<A>::obj();
    }
};

class Class_16 {};

class Class_16a {
public:
    typedef Class_16 cl;
};

template<typename T>
class Class_16b : public T {
public:
    typedef typename T::cl clB;
};

template<typename T>
void function_1(T) { std::cout << "Function(T).\n"; }

void function_1(Class_16);

template<typename T>
void function_2(T& t) {
    typename T::value_type* ptr1 = &t[0];
    typename T::value_type* ptr2 = &*t.begin();
}

int findKey(const int key, int* vecKeys, size_t maxElements);



#endif
