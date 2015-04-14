#ifndef CHAPTER_15_H
#define CHAPTER_15_H

#include <iostream>
#include <vector>
#include <string>

class Shape_1 {
public:
    Shape_1();
    virtual void draw();
};

class Circle_1 : public Shape_1 {
public:
    void draw();
};

class Square_1 : public Shape_1 {
public:
    void draw();
};

class Triangle_1 : public Shape_1 {
public:
    void draw();
};

void function_15_1 (Shape_1& shp);

class Class_15_A {
public:
    Class_15_A(int ii) : i(ii) {}
    ~Class_15_A() {}
    void f() const {}
private:
    int i;
};

class Class_15_B {
public:
    Class_15_B(int ii) : i(ii) {}
    ~Class_15_B() {}
    virtual void f() const;
private:
    int i;
};

class Class_15_C : public Class_15_B {
public:
    Class_15_C(int ii) : Class_15_B(ii), a(ii) {}
    ~Class_15_C() {}
    void f() const;
private:
    Class_15_A a;
};

class Instrument_5 {
public:
    virtual void play(int note) const;
    virtual void prepare() const;
};

class Wind_5 : public Instrument_5 {
public:
    void play(int note) const;
};

void function_15_5(Instrument_5& i);

class Rodent {
public:
    virtual void run() = 0;
    virtual void eat() = 0;
    virtual ~Rodent() = 0;
};

class Mouse : public Rodent {
public:
    ~Mouse();
    void run();
    void eat();
};

class Gerbil : public Rodent {
public:
    ~Gerbil();
    void run();
    void eat();

};

class Hamster : public Rodent {
public:
    ~Hamster();
    void run();
    void eat();
};

class BlueHamster : public Hamster {
public:
    void run();
    void eat();
};

class Aircraft {
public:
    virtual void takeoff() = 0;
    virtual void toland() = 0;
};

class Aircraft_A : public Aircraft {
public:
    void takeoff();
    void toland();
};

class Aircraft_B : public Aircraft {
public:
    void takeoff();
    void toland();
};

class Tower {
public:
    Tower(int units);
    void open();
    void close();
    ~Tower();
private:
    std::vector<Aircraft*> storage;
};

class Plant {
public:
    virtual void seat() = 0;
    virtual void fertilize() = 0;
};

class Cactus : public Plant {
public:
    void seat();
    void fertilize();
};

class Flower : public Plant {
public:
    void seat();
    void fertilize();
};

class Pet {
public:
    Pet(const std::string& name);
    virtual std::string name() const = 0;
    virtual std::string speak() const = 0;
private:
    std::string pname;
};

class Dog : public Pet {
public:
    Dog(std::string name);
    virtual std::string name() const;
    std::string speak() const;
};

class Class_15_14 {
public:
    Class_15_14();
    virtual void function_1();
};

class Class_15_14_1 : public Class_15_14 {
public:
    Class_15_14_1();
    void function_1();
    void function_2();
};

class Base_15 {
public:
    virtual ~Base_15();
    virtual void function();
};

class Derived_15_1 : public Base_15 {
public:
    ~Derived_15_1();
    void function();
};

class Derived_15_2 : public Derived_15_1 {
public:
    ~Derived_15_2();
    void function();
};

class Base_18_1 {
public:
    int i;
};

class Derived_15_18 : public Base_18_1 {
public:
    int i2;
};

void function_15_18(Base_18_1 obj);

class Class_15_20 {
public:
    virtual void function_1() = 0;
    void function_2();
};

class Class_15_20_1 : public Class_15_20 {
public:
    void function_1();
};

class Base_15_21 {
public:
    Base_15_21();
    virtual ~Base_15_21();
    virtual void function() = 0;
};

class Member_15_21_1 {
public:
    Member_15_21_1();
    ~Member_15_21_1();
};

class Member_15_21_2 {
public:
    Member_15_21_2();
    ~Member_15_21_2();
};

class Derived_15_21_1 : public Base_15_21 {
public:
    Derived_15_21_1();
    ~Derived_15_21_1();
    void function();
private:
    Member_15_21_1 m1;
};

class Derived_15_21_2 : public Derived_15_21_1 {
public:
    Derived_15_21_2();
    ~Derived_15_21_2();
    void function();
private:
    Member_15_21_2 m2;
};

class Class_15_22 {
public:
    virtual void function(int i);
    virtual void function(char c);
    virtual void function(float f);
};

class Class_15_22_1 : public Class_15_22 {
public:
    // void function(char c);
};

#endif
