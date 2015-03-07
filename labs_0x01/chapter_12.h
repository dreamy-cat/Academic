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

class Obj_18 {
public:
    void f() const;
    void g() const;
private:
    static int i, j;
};

class ObjContainer_18_1 {
public:
    void add(Obj_18* obj);
    friend class SmartPointer_18_1;
private:
    std::vector<Obj_18*> a;
};

class SmartPointer_18_1 {
public:
    SmartPointer_18_1(ObjContainer_18_1& objC);
    bool operator++();
    bool operator++(int);
    bool operator--();
    bool operator--(int);
    Obj_18* operator->() const;
private:
    int index;
    ObjContainer_18_1& oc;
};

class ObjContainer_18_2 {
public:
    void add(Obj_18* obj);
    class SmartPointer_18_2;
    SmartPointer_18_2 begin();
    friend class SmartPointer_18_2;
    class SmartPointer_18_2 {
    public:
        SmartPointer_18_2(ObjContainer_18_2& objC);
        bool operator++();
        bool operator++(int);
        bool operator--();
        bool operator--(int);
        Obj_18* operator->() const;
    private:
        ObjContainer_18_2& oc;
        int index;
    };
private:
    std::vector<Obj_18*> a;
};

class Class_12_19_1 {
public:
    Class_12_19_1();
};

class Class_12_19_2 {
public:
    Class_12_19_2();
    Class_12_19_2(const Class_12_19_1&);
};

class Class_12_21 {
public:
    Class_12_21(std::string is = "op=call");
    Class_12_21& operator=(Class_12_21& r);
    std::string s;
};

class Dog_12_1 {
public:
    Dog_12_1(const std::string& nm);
    Dog_12_1(const Dog_12_1* dp, const std::string& msg);
    ~Dog_12_1();
    void rename(std::string newName);
    friend std::ostream& operator<<(std::ostream& os, const Dog_12_1& value);
private:
    std::string name;
};

class DogHouse_12_1 {
public:
    DogHouse_12_1(Dog_12_1* dog, const std::string nm);
    DogHouse_12_1(const DogHouse_12_1& r);
    DogHouse_12_1& operator=(const DogHouse_12_1& r);
    void rename(const std::string& newName);
    Dog_12_1* getDog() const;
    ~DogHouse_12_1();
    friend std::ostream& operator<<(std::ostream& os, const DogHouse_12_1& value);
private:
    Dog_12_1* p;
    std::string name;
};

#endif
