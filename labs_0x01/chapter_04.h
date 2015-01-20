#ifndef CHAPTER_04_H
#define CHAPTER_04_H

#include <string>

#define TASK_11

struct structure_4_1 {
    int n;
    void function_1(structure_4_1* strucPtr, int m);
    void function_2(structure_4_1* strucPtr);
};

class class_4_1 {
    std::string s;
public:
    class_4_1();
};

struct Stash {
    int size;
    int quantity;
    int next;
    static const int increment = 4;
    unsigned char* storage;
    void initialize(int sz);
    void cleanup();
    int add(const void* element);
    void* fetch(int index);
    int count();
    void inflate(int increase);
};

struct Stack {
    struct Link {
        double* value;
        Link* next;
    };
    Link* head;
    int size, valSize;
    void initialize();
    void push(double* data);
    double *pop();
};

class Class_4_13 {
public:
    std::string title, customer;
    int period;

    Class_4_13(std::string newTitle);
    void give(std::string cust);
    void get(std::string cust);
    void print();
    ~Class_4_13();
};

class Stack2 {
    int stackPointer;
    const int maxSz;
    Class_4_13** mem;
public:
    Stack2(int maxSize);
    void push(Class_4_13& clPtr);
    Class_4_13 pop();
    ~Stack2();
};

#endif
