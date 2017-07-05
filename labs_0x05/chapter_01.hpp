#ifndef L_05_CHAPTER_01_H
#define L_05_CHAPTER_01_H

#include <string>
#include <iostream>

class StringInsens {
public:
    StringInsens(const char *str);
    const char* getData() const;
    friend int operator==(const StringInsens& lv, const char* rv);
private:
    const char* text;
};

#endif
