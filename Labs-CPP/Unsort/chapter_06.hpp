#ifndef LABS_05_CHAPTER_06_H
#define LABS_05_CHAPTER_06_H

#include <iostream>
#include <new>
#include <memory>

class Class_6_1A {
public:
    Class_6_1A() = default;
    virtual ~Class_6_1A();
    static void* operator new(size_t count);
    static void* operator new[](size_t count);
    static void operator delete(void* ptr, size_t ) throw();
    static void operator delete[](void* ptr, size_t ) throw();
    void function(void* ptr, size_t s);
};

class Class_6_1B : public Class_6_1A {
public:
    Class_6_1B() = default;
    ~Class_6_1B();
    static void* operator new(size_t count);
    static void* operator new[](size_t count);
    static void operator delete(void* ptr) throw();
    static void operator delete[](void* ptr) throw();
};

class Class_6_2A {
public:
    static void* operator new(size_t s, int) throw( std::bad_alloc );
    static void operator delete(void* ptr, size_t);
};

class Shared_6 {
public:
    static void* allocate(size_t s);
    static void deallocate(void* p);
};

class Class_6_2B {
public:
    static void* operator new(size_t s, Shared_6& memory);
    static void operator delete(void* ptr, Shared_6& memory) throw ();
};

class Class_6_3 {
public:
    Class_6_3();
    Class_6_3(const Class_6_3&);
    ~Class_6_3();
    Class_6_3& operator=(const Class_6_3&);
private:
    std::unique_ptr<char> ptr;
};

namespace Labs_0x05 {       // see later with other labs.

void function_6_1();

}

void function_6_2();

std::unique_ptr<char> function_6_3();

void function_6_4(std::unique_ptr<char>& ptr);

std::string function_6_5();

template<typename T>
class Adapter {
public:
    Adapter(T* ptr) : pointer(ptr) {}
    ~Adapter() { delete[] pointer; }
private:
    T* pointer;
};

template<typename T>
void function_6_6(size_t n) {
    std::unique_ptr<T> ptr1(new T);
    std::unique_ptr<T> ptr2(new T[n]);
    std::unique_ptr<Adapter<T>> ptr3 ( new Adapter<T>(new T[n]));
    std::cout << "Counter of objects: " << n << std::endl;
}

class Class_6_4 {
public:
    Class_6_4();
    ~Class_6_4();
    static int counter;
private:
    std::string s;
};

class Class_6_5 {
public:
    Class_6_5(char c);
    Class_6_5(const Class_6_5&rv);
    Class_6_5& operator=(const Class_6_5& rv);
    ~Class_6_5();
private:
    char* pointer1;
    std::unique_ptr<char> pointer2;
};

class Class_6_6 {
public:
    std::unique_ptr<Class_6_5> pointer;
};

template<typename T>
class ValuePointer {
public:
    explicit ValuePointer(T* ptr) : pointer(ptr) {}
    ~ValuePointer() { delete pointer; }
    T& operator*() const { return *pointer; }
    T* operator->() const { return pointer; }
    void swap(ValuePointer& rv) { std::swap(pointer, rv.pointer); }
    ValuePointer(const ValuePointer& rv) : pointer(create(*rv.pointer)) {}
    ValuePointer& operator=(const ValuePointer& rv) {
        ValuePointer tmp(rv);
        swap(tmp);
        return *this;
    }
    template<typename U>
    ValuePointer(const ValuePointer<U>& rv) : pointer(create(*rv.pointer)) {}
    template<typename U>
    ValuePointer& operator=(const ValuePointer<U>& other) {
        ValuePointer tmp(other);
        swap(tmp);
        return *this;
    }
private:
    template<typename U>
    T* create(const U* ptr) const { return ptr ? new T(*ptr) : 0; }
    template<typename U> friend class ValuePointer;
    T* pointer;
};

template<typename T>
class Class_6_7 {
public:
    Class_6_7(T* p) : ptr(p) {}
    Class_6_7(const Class_6_7& rv) : ptr(new T(*(rv.ptr))) {}
    void swap(Class_6_7& rv) { ptr.swap(rv.ptr); }
    Class_6_7& operator=(const Class_6_7& rv) {
        Class_6_7 tmp(rv);
        swap(tmp);
        return *this;
    }
    ~Class_6_7() { }
private:
    ValuePointer<char> ptr;
};

#endif
