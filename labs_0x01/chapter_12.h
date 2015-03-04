#ifndef CHAPTER_12_H
#define CHAPTER_12_H

#include <iostream>

class Class_12_1 {
public:
    const Class_12_1& operator++();
    const Class_12_1& operator++(int);
};

class Class_12_2 {
public:
    Class_12_2(int ii);
    friend const Class_12_2 operator +(const Class_12_2& left, const Class_12_2& right);
    friend const Class_12_2 operator-(const Class_12_2& left, const Class_12_2& right);
    const Class_12_2 operator-();
    Class_12_2& operator++();
    const Class_12_2 operator++(int);
    friend std::ostream& operator<<(std::ostream& os, Class_12_2& value);
private:
    int i;
};

#endif
