#ifndef L_05_CHAPTER_02_H
#define L_05_CHAPTER_02_H

#include <iostream>
#include <assert.h>
#include <algorithm>
#include <memory>

template<typename T1, typename T2>
void construct (T1* ptr, const T2& value) {
    new (ptr) T1(value);
}

template<typename T>
void destroy(T* ptr) {
    ptr->~T();
}

template<typename FIter>
void destroy(FIter first, FIter last) {
    while (first != last) {
        try {
            destroy(&*first);
        } catch (...) {
            std::cout << "Catching...\n";
        }
        ++first;
    }
}

template<typename T>
void swap(T& a, T& b) {
    T tmp(a);
    a = b;
    b = tmp;
}

template<typename T>
class StackImpl {
public:
    StackImpl(size_t stackSize) : size(stackSize), used(0) {
        std::cout << "StackImpl constructor.\n";
        if (size != 0) data = new T[stackSize]; else
            data = nullptr;
    }

    ~StackImpl() {
        std::cout << "StackImpl destructor.\n";
        destroy(data, data + used);
        operator delete( data );
    }

    void swapStack(StackImpl& rv) throw () {
        swap(data, rv.data);
        swap(size, rv.size);
        swap(used, rv.used);
    }

    T* data;
    size_t size, used;
private:
    StackImpl(const StackImpl&);
    StackImpl& operator=(const StackImpl&);
};

template<typename T>
class Stack {               //  Third variant was with ' : public StackImpl<T>'
public:
    /*
    Stack(size_t nSize) : StackImpl<T>(nSize) {
        std::cout << "Stack constructor.\n";
        // data = new T[size];
    }
    */

    Stack(size_t nSize) : impl(nSize) {}

    T* newStack(const T* source, size_t sSize, size_t dSize) {
        assert( dSize >= sSize);
        T* destintation = new T[dSize];
        try {
            std::copy(source, source + sSize, destintation);
        } catch (...) {
            std::cout << "Catching throw, no memory leak.\n";
            delete [] destintation;
            throw;
        }
        return destintation;
    }

    ~Stack() {
        std::cout << "Stack destructor.\n";
        // Using destructor in StackImpl.
        /*
        delete [] data;
        used = 0;
        */
    }

    Stack(const Stack& rv) : impl(rv.used) {            // StackImpl<T>(rv.used).
        std::cout << "Stack copy constructor.\n";
        // Not compile, but IDE found it. May be need a proper declaration of 'StackImpl<T>'.
        while (impl.used < rv.used) {
            construct(impl.data + impl.used, rv.data[impl.used]);
            ++impl.used;
        }
        /* Third variant.
        while (StackImpl<T>::used < rv.used) {
            construct(StackImpl<T>::data + StackImpl<T>::used, rv.data[StackImpl<T>::used]);
            ++StackImpl<T>::used;
        }
        */
        /*  Second variant.
        data = newStack(rv.data, rv.size, rv.size);
        size = rv.size;
        used = rv.used;
        */
        /*  First variant.
        data = new T[size];
        for (int i = 0; i < used; i++) data[i] = rv.data[i];
        used = rv.used;
        size= rv.size;
        */
    }

    Stack& operator=(const Stack& rv) {
        std::cout << "Stack, operator=().\n";
        Stack tmp(rv);
        impl.swapStack(tmp);
        /* Second variant.
        if ( this != rv ) {
            T* newData = newStack(rv.data, rv.size, rv.size);
            delete [] data;
            data = newData;
            size = rv.size;
            used = rv.used;
        }
        */
        /* First variant.
        data = new T[size];
        size = rv.size;
        used = rv.used;
        for (int i = 0; i < used; i++) data[i] = rv.data[i];
        */
        return *this;
    }

    size_t count() const {
        return impl.used;
        // return StackImpl<T>::used;
    }

    void push(const T& value) {
        if ( impl.used == impl.size ) {
            Stack tmp(impl.size*2 + 1);
            while ( tmp.count() < impl.used )
                tmp.push(impl.data[tmp.count()]);
            tmp.push(value);
            swapStack(tmp);
        } else {
            construct(impl.data + impl.used, value);
            ++impl.used;
        }
        /* Third variant.
        if ( StackImpl<T>::used == StackImpl<T>::size ) {
            Stack tmp(StackImpl<T>::size*2 + 1);
            while ( tmp.count() < StackImpl<T>::used )
                tmp.push(StackImpl<T>::data[tmp.count()]);
            tmp.push(value);
            swapStack(tmp);
        } else {
            construct(StackImpl<T>::data + StackImpl<T>::used, value);
            ++StackImpl<T>::used;
        }
        */
        /* Second variant.
        if ( StackImpl<T>::used == StackImpl<T>::size ) {
            size_t newSize = StackImpl<T>::size * 2 + 1;
            T* newData = newStack(StackImpl<T>::data, StackImpl<T>::size, newSize);
            delete [] StackImpl<T>::data;
            StackImpl<T>::data = newData;
        }
        StackImpl<T>::data[StackImpl<T>::used] = value;
        ++StackImpl<T>::used;
        */
        // if (used != size) data[used++] = value;
    }

    void pop() {
        if ( impl.used == 0 ) {
            throw "Stack is empty.";
        } else {
            --impl.used;
            destroy(impl.data + impl.used);
        }
        // Third version.
        /*
        if ( StackImpl<T>::used == 0 ) {
            throw "Stack is empty.";
        } else {
            --StackImpl<T>::used;
            destroy(StackImpl<T>::data + StackImpl<T>::used);
        }
        */
        // Second version.
        /*
        if ( used == 0 ) throw "Stack is empty."; else {
             T value = data[used-1];
             --used;
             return value;
        }
        */
        // First version.
        /*
        assert( used > 0);
        return (data[--used]);
        */
    }

    const T& top() const {
        if ( impl.used == 0) throw "Stack is empty."; else
            return impl.data[impl.used-1];
        /* Third variant.
        if ( StackImpl<T>::used == 0) throw "Stack is empty."; else
            return StackImpl<T>::data[StackImpl<T>::used-1];
            */
    }

    bool empty() const {
        return (impl.used == 0);
        // return (StackImpl<T>::used == 0);
    }

    void swapStack(Stack& rv) throw () {
        swap(impl.data, rv.impl.data);
        swap(impl.size, rv.impl.size);
        swap(impl.used, rv.impl.used);
    }

    void print() const {
        for (int i = 0; i < impl.used; i++) std::cout << impl.data[i] << " ";
    }

private:
    StackImpl<T> impl;      // Fourth variant.
    /*  First variant.
    T* data;
    size_t size, used;
    */
};

std::string function_4(std::string s);

class Class_2_1 {
public:
    Class_2_1(bool isException);
    ~Class_2_1();
};

class Class_2_2 {
public:
    Class_2_2(bool isException = false);
    ~Class_2_2();
};

class Class_2_3 : private Class_2_1 {
public:
    Class_2_3(bool isException = false);
private:
    Class_2_2 obj;
};

class Class_2_4 : private Class_2_1 {
private:
    int* i;
    char* c;
public:
    Class_2_4(bool isException = false);
    ~Class_2_4();
};

#endif
