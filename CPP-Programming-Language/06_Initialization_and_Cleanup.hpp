#ifndef PART_06
#define PART_06

#include <iostream>
#include <vector>
#include <string>

class Simple {
public:
    Simple(int i);
    ~Simple();
    int b;
    void printA ();
private:
    int a;
};

class Class_6_6 {
public:
    Class_6_6 ();
    ~Class_6_6 ();
    int read();
    void change(int value);
private:
    Simple* simplePtr;
};

class Stack6 {
public:
    Stack6();
    void push (std::string& val);
    std::string pop();
private:
    std::vector<std::string> storage;
};

class Class_6_10 {
public:
    Class_6_10(int a);
    void function();

};

#endif // CHAPTER_06_H
