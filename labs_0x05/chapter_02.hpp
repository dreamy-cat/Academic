#ifndef L_05_CHAPTER_02_H
#define L_05_CHAPTER_02_H

#include <iostream>
#include <assert.h>
#include <algorithm>
#include <memory>

template<typename T>
class Stack {
public:

    Stack() : data(nullptr), size(5), used(0) {
        std::cout << "Stack constructor.\n";
        data = new T[size];
    }

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
        delete [] data;
        used = 0;
    }

    Stack(const Stack& rv) {
        std::cout << "Stack copy constructor.\n";
        data = newStack(rv.data, rv.size, rv.size);
        size = rv.size;
        used = rv.used;
        /*
        data = new T[size];
        for (int i = 0; i < used; i++) data[i] = rv.data[i];
        used = rv.used;
        size= rv.size;
        */
    }

    Stack& operator=(const Stack& rv) {
        std::cout << "Stack, operator=().\n";
        if ( this != rv ) {
            T* newData = newStack(rv.data, rv.size, rv.size);
            delete [] data;
            data = newData;
            size = rv.size;
            used = rv.used;
        }
        /*
        data = new T[size];
        size = rv.size;
        used = rv.used;
        for (int i = 0; i < used; i++) data[i] = rv.data[i];
        */
        return *this;
    }

    size_t count() const {
        return used;
    }

    void push(const T& value) {
        if ( used == size ) {
            size_t newSize = size * 2 + 1;
            T* newData = newStack(data, size, newSize);
            delete [] data;
            data = newData;
        }
        data[used] = value;
        ++used;
        // if (used != size) data[used++] = value;
    }

    void pop() {
        // Third version.
        if ( used == 0 )throw "Stack is empty."; else --used;
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
        if ( used == 0) throw "Stack is empty."; else
            return data[used-1];
    }

    bool empty() const {
        return (used == 0);
    }

private:
    T* data;
    size_t size, used;
};

// Try to recompile later.

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
        destroy(&*first);
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

    T* data;
    size_t size, used;
private:

};

#endif
