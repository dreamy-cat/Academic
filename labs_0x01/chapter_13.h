#ifndef CHAPTER_13_H
#define CHAPTER_13_H

#include <iostream>

class Counted {
public:
    Counted();
    ~Counted();
    void function_1();
private:
    int id;
    static int count;
};

#endif
