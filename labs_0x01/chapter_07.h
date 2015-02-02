#ifndef CHAPTER_07_H
#define CHAPTER_07_H

#include <string>
#include <vector>

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
    Stack7(std::string value, int size);
    void push(std::string value);
    std::string pop();
private:
    std::vector<std::string> storage;
};

#endif
