#ifndef CHAPTER_04_H
#define CHAPTER_04_H

#include <string>

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

#endif
