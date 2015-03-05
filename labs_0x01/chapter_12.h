#ifndef CHAPTER_12_H
#define CHAPTER_12_H

#include <iostream>
#include <vector>

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

class Class_12_9 {
public:
    Class_12_9(char ic);
    const Class_12_9 operator++(int a);
    const Class_12_9 operator--(int a);
    friend std::ostream& operator<<(std::ostream& os, const Class_12_9& value);
    friend std::istream& operator>>(std::istream& is, Class_12_9& value);
private:
    char c;
};

class Number_12 {
public:
    Number_12(double di);
    Number_12(const Number_12& r);
    const Number_12 operator+(const Number_12& right) const;
    const Number_12 operator-(const Number_12& right) const;
    const Number_12 operator*(const Number_12& right) const;
    const Number_12 operator/(const Number_12& right) const;
    Number_12& operator=(const Number_12& rv);
    operator double() const;
    friend std::ostream& operator<<(std::ostream& os, const Number_12& value);
private:
    double d;
};

void function_12_12(double d);

class Class_12_13 {
public:
    Class_12_13(int* ii);
    void print();
    Class_12_13& operator=(const Class_12_13& rv);
private:
    int* i;
};

class Bird_12 {
public:
    Bird_12(int ii = 0);
    Bird_12(Bird_12& rv);
    friend std::ostream& operator<<(std::ostream& os, const Bird_12& value);
    Bird_12& operator=(const Bird_12& rv);
    const Bird_12 operator+(const Bird_12& right) const;
    const Bird_12 operator-(const Bird_12& right) const;
    const Bird_12 operator *(const Bird_12& right) const;
    const Bird_12 operator /(const Bird_12& right) const;
private:
    int i;
    std::string name;
    static int counter;
};

void function_12_14(Bird_12& cl);

class BirdHouse_12 {
public:
    BirdHouse_12(Bird_12& cl1, Bird_12& cl2, Bird_12& cl3, int ii = 0);
    friend std::ostream& operator<<(std::ostream& os, const BirdHouse_12& value);
    BirdHouse_12(const BirdHouse_12& r);
    BirdHouse_12& operator=(const BirdHouse_12& r);
    friend const BirdHouse_12 operator+(const BirdHouse_12& left, const BirdHouse_12& right);
    friend const BirdHouse_12 operator-(const BirdHouse_12& left, const BirdHouse_12& right);
    friend const BirdHouse_12 operator*(const BirdHouse_12& left, const BirdHouse_12& right);
    friend const BirdHouse_12 operator/(const BirdHouse_12& left, const BirdHouse_12& right);
private:
    int i;
    Bird_12 bird_1;
    Bird_12* bird_2;
    Bird_12& bird_3;
};

class Obj_18_1 {
public:
    void f() const;
    void g() const;
private:
    static int i, j;
};

class ObjContainer_18_1 {
public:
    void add(Obj_18_1* obj);
    friend class SmartPointer_18_1;
private:
    std::vector<Obj_18_1*> a;
};

class SmartPointer_18_1 {
public:
    SmartPointer_18_1(ObjContainer_18_1& objC);
    bool operator++();
    bool operator++(int);
    bool operator--();
    bool operator--(int);
    Obj_18_1* operator->() const;
private:
    int index;
    ObjContainer_18_1& oc;
};

#endif
