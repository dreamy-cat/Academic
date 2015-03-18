#ifndef CHAPTER_13_H
#define CHAPTER_13_H

#include <iostream>
#include <cstring>

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

#endif
