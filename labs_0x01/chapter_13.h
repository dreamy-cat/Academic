#ifndef CHAPTER_13_H
#define CHAPTER_13_H

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include "stdlib.h"

class Counted {
public:
    Counted();
    ~Counted();
    void function_1();
private:
    int id;
    static int count;
};

class PStash {
public:
    PStash();
    ~PStash();
    int add(void* element);
    void* operator[](int index) const;
    void* remove(int index);
    int count() const;
private:
    int quantity;
    int next;
    void** storage;
    void inflate(int increase);
};

class Framis_13 {
public:
    Framis_13();
    ~Framis_13();
    void* operator new(size_t);
    void operator delete(void* m);
private:
    enum { maxSize = 16 };
    char data[4];
    static unsigned char pool[];
    static bool alloc_map[];
};

class Class_13_14 {
public:
    void* operator new(size_t sz, std::string str);
    void operator delete(void* p);
    static std::vector<std::string> storage;
};

class Widget_13 {
public:
    Widget_13();
    ~Widget_13();
    void* operator new(size_t sz);
    void operator delete(void* p);
    void* operator new[](size_t sz);
    void operator delete[](void* p);
    static std::vector<Widget_13*> storage;
private:
    enum { maxSize = 8 };
    int vector[maxSize];

};

class Class_13_11 {
public:
    void* operator new(size_t sz);
    void operator delete(void* p);
    void* operator new[](size_t sz);
    void operator delete[](void* p);
};

#endif
