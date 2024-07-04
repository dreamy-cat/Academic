#ifndef PART_04
#define PART_04

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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
//    unsigned char* storage;
    std::vector<unsigned char> storage;
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

char* function_4_1(const char* original);

// Task 19.

struct structure_4_2 {
    int n1;
    void printN();
    struct structure_4_2_1 {
        int n2;
        void printN();
    } substructure;
};

// Task 20.

struct structure_4_3 {
    int a;
    char c;
};

struct structure_4_4 {
    void alpha();
    void beta();
};

struct structure_4_5 {

};

// Task 21.

enum enum_1 {alpha, beta, gamma};
union union_4_1 {
    int a;
    char c;
};

// Task 22.

struct Stash3 {
    std::string text;
};

struct Stack3 {
    Stash3** mem;
    int maxSz, stackPointer;
    void init(int size);
    void push(Stash3 element);
    Stash3 pop();
};

// Task 23.

struct structure_4_6 {
    Stack3 stack;
    void wrapinit(int size);
    void wrapPush(Stash3& element);
    Stash3 wrapPop();
};

// Task 24.

struct List {
    int n;
    List* next;
    void createList(List* start, int size);
    void printList(List* start);
};

#endif
