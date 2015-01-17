#ifndef CHAPTER_04_H
#define CHAPTER_04_H

#include <string>

using namespace std;

struct structure_4_1 {
    int n;
    void function_1(structure_4_1* strucPtr, int m);
    void function_2(structure_4_1* strucPtr);
};

class class_4_1 {
    string s;
public:
    class_4_1();
};

#endif
