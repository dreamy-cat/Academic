#ifndef CHAPTER_07_H
#define CHAPTER_07_H

#include <string>
#include <vector>
#include <iostream>

#define TASK_8

class Text {
public:
    Text();
    Text(std::string fileName);
    std::string txt;
};

class Message {
public:
    Message(std::string init);
    void print();
    void print(std::string pr);
private:
    std::string msg;

};

class Class_7_4 {
public:
    void f (int a = 0, int b = 1, int c = 2, int d = 3);
};

void function_7_5 (int a, int);

class Stash7 {
public:
    Stash7(int sz, int initQuantity = 0);
    ~Stash7();
    int add (void* element);
    int count();
    void* fectch(int index);
private:
    void inflate(int increase);
    unsigned char* storage;
    int size;
    int quantity;
    int next;
    const int increment;
};

class Stack7 {
public:
    Stack7();
    Stack7(std::string values[], int size);
    void push(std::string value);
    std::string pop();
private:
    std::vector<std::string> storage;
};

#ifdef TASK_8

class SuperVar {
    union {
        char c;
        int i;
        float f;
    };
public:
    enum vartype { character, integer, floating };
    SuperVar(char ch);
    SuperVar(int ii);
    SuperVar(float ff);
    void print(vartype t);
};

#endif  //Task_8.

class Mem {
public:
    Mem(int sz = 0);
    ~Mem();
    int msize();
    unsigned char* pointer(int minSize = 0);
    bool moved();
private:
    unsigned char* mem, *prevMem;
    int size;
    void ensureMinSize(int minSize);
};

class String_9 {
public:
    String_9();
    String_9(const char* str);
    ~String_9();
    void concat(char* str);
    void print(std::ostream& os);
private:
    Mem* buf;
};

class StashMem {
public:
    StashMem(int sz, int initQuantity = 0);
    ~StashMem();
    int add (void* element);
    int count();
    void* fectch(int index);
private:
    void inflate(int increase);
    Mem* storage;
    int size;
    int quantity;
    int next;
    const int increment;
};

#endif
