#ifndef CHAPTER_06_H
#define CHAPTER_06_H

#include <vector>
#include <string>

class Simple {
public:
    Simple(int i);
    ~Simple();
    int b;
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

#endif // CHAPTER_06_H
