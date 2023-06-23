#ifndef L_02_CHAPTER_01_H
#define L_02 CHAPTER_01_H

#include <iostream>
#include <errno.h>
#include <signal.h>
#include <stdexcept>
#include <cstring>
#include <cstdlib>

int function_01_1();
void function_01_2();
void function_01_3(int sig);
void function_01_4();

class Class_01_1 {
public:
    class Class_1 {
    public:
        Class_1(const char* s) : str(s) {}
        const char* str;
    };
    void function_1() throw(Class_1);
};

class PStash_1 {
public:
    PStash_1();
    ~PStash_1();
    int add(void *element);
    void* operator[](int index) const;
    void* remove(int index);
    int count() const;
private:
    void** storage;
    int quantity, next;
    void inflate(int increase);
};

class Class_1_5 {
public:
    Class_1_5();
    static int counter;
    static const int limit = 3;
    void* operator new (size_t);
    void operator delete(void* p);
};

class Class_1_6 {
public:
    Class_1_6();
    ~Class_1_6();
    void function_1();
};

class Class_1_9 : public std::exception {};

void function_01_9(int index) throw(char, int, bool, Class_1_9);

void unexpectedHandler();

class Garage {
public:
    Garage();
    class Car {
    public:
        class Motor {
        public:
            Motor();
        };
        Motor motor_1;
    };
    Car* car_1;
};

#endif
