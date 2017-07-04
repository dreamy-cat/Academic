#ifndef L_05_CHAPTER_01_H
#define L_05_CHAPTER_01_H

#include <string>
#include <iostream>

class StringInsens {
public:
    StringInsens(const char* str);
    char* getData();
    bool operator==(const char* rv);
private:
    char* text;
};

#endif
