#ifndef LABS_05_CHAPTER_09_H
#define LABS_05_CHAPTER_09_H

#include <iostream>

class Class_9_1 {
public:
    Class_9_1(char ic);
    Class_9_1(const Class_9_1 &rv);
    Class_9_1(const char* text);
    ~Class_9_1();
    Class_9_1& operator=(const Class_9_1& rv);
    Class_9_1& operator-(const Class_9_1& rv);
    void function();
    char c;
};

class Class_9_2 : public Class_9_1 {
public:
    Class_9_2(char ic);
    Class_9_2& operator=(const Class_9_2& rv);
};

#endif
