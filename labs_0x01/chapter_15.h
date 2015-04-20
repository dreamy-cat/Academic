#ifndef CHAPTER_15_H
#define CHAPTER_15_H

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

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
    void function(char c);
};

class PetFood_15 {
public:
    virtual std::string foodType() const = 0;
};

class Pet_15 {
public:
    virtual std::string type() const = 0;
    virtual PetFood_15* eats() = 0;
    virtual PetFood_15& eats(bool f) = 0;
};

class Bird_15 : public Pet_15 {
public:
    std::string type() const;
    class BirdFood_15 : public PetFood_15 {
    public:
        std::string foodType() const;
    };
    PetFood_15* eats();
    PetFood_15& eats(bool f);
private:
    BirdFood_15 bf;
};

class Cat_15 : public Pet_15 {
public:
    std::string type() const;
    class CatFood_15 : public PetFood_15 {
    public:
        std::string foodType() const;
    };
    CatFood_15* eats();
    CatFood_15& eats(bool f);
private:
    CatFood_15 cf;
};

class Pet_15_24 {
public:
    virtual std::string speak() const;
};

class Dog_15_24 : public Pet_15_24 {
public:
    std::string speak() const;
};

class Base_15_25 {
public:
    virtual Base_15_25& clone();
    virtual void print() const;
};

class Derived_15_25_1 : public Base_15_25 {
public:
    Derived_15_25_1 &clone();
    void print() const;
};

class Derived_15_25_2 : public Base_15_25 {
public:
    Derived_15_25_2& clone();
    void print() const;
};

class Object_15 {
public:
    virtual ~Object_15() = 0;
};

class Stack_15 {
    struct Link {
        Object_15* data;
        Link* next;
        Link(Object_15* dat, Link* nxt);
    }* head;
public:
    Stack_15();
    ~Stack_15();
    void push(Object_15* dat);
    Object_15* peek() const;
    Object_15* pop();
};

class Class_15_26 {
public:
    Class_15_26(int ii) : i(ii) {}
    int i;
};

class Class_15_26_1 : public Object_15, public Class_15_26 {
public:
    Class_15_26_1(int ii);
    ~Class_15_26_1();
};

#endif

class Matrix;
class Scalar;
class Vector;
class Tensor;

class Math {
public:
    virtual Math& operator*(Math& rv) = 0;
    virtual Math& multiply(Matrix*) = 0;
    virtual Math& multiply(Scalar*) = 0;
    virtual Math& multiply(Vector*) = 0;
    virtual Math& multiply(Tensor*) = 0;
    virtual ~Math();
};

class Matrix : public Math {
public:
    Math& operator*(Math& rv);
    Math& multiply(Matrix*);
    Math& multiply(Scalar*);
    Math& multiply(Vector*);
    Math& multiply(Tensor*);
};

class Scalar : public Math {
public:
    Math& operator*(Math& rv);
    Math& multiply(Matrix*);
    Math& multiply(Scalar*);
    Math& multiply(Vector*);
    Math& multiply(Tensor*);
};

class Vector : public Math {
public:
    Math& operator*(Math& rv);
    Math& multiply(Matrix*);
    Math& multiply(Scalar*);
    Math& multiply(Vector*);
    Math& multiply(Tensor*);
};

class Tensor : public Math {
public:
    Math& operator*(Math& rv);
    Math& multiply(Matrix*);
    Math& multiply(Scalar*);
    Math& multiply(Vector*);
    Math& multiply(Tensor*);
};

class Class_15_28 {
public:
    Class_15_28();
    virtual void function();
};

class Class_15_28_1 : public Class_15_28 {
public:
    Class_15_28_1();
    void function();
};

class Class_15_30 {
public:
    virtual void function();
};

class Class_15_30_1 : public Class_15_30 {
public:
    void function();
};

void function_15_30(Class_15_30 cl);

class Class_15_32_1 {
public:
    virtual void function_1() {}
};

class Class_15_32_2 {
public:
    virtual void function_2() {}
};

class Class_15_32_3 : public Class_15_32_1, public Class_15_32_2 {
public:
    void function_1() {}
    void function_2() {}
};

class Class_15_33 {
public:
    virtual void function_1() {}
    virtual void function_2() {}
    virtual void function_3() {}
    int i,j,k;
};

class Instrument_34 {
public:
    virtual void play(int note) const;
    virtual std::string what() const;
    virtual void adjust(int);
};

class Wind_34 : public Instrument_34 {
public:
     void play(int note) const;
     std::string what() const;
     void adjust(int);
};

class Percussion_34 : public Instrument_34 {
public:
     void play(int note) const;
     std::string what() const;
     void adjust(int);
};


class Stringed_34 : public Instrument_34 {
public:
     void play(int note) const;
     std::string what() const;
     void adjust(int);
};

class Brass_34 : public Wind_34 {
public:
     void play(int note) const;
     std::string what() const;
};

class Woodwind_34 : public Wind_34 {
public:
     void play(int note) const;
     std::string what() const;
};

class Shape_15 {
public:
    enum type { Shape, Circle, Square };
    virtual int whatAmI();
    virtual ~Shape_15() {}
};

class Circle_15 : public Shape_15 {
public:
    int whatAmI();
};

class Square_15 : public Shape_15 {
public:
    int whatAmI();
};

class Other_15 {
};

class Dog_15_36 {
public:
    virtual int run(int i) const;
    virtual int eat(int i) const;
    virtual int sleep(int i) const;

    typedef int (Dog_15_36::*Pointer)(int) const;

    class FunctionObject_15 {
    public:
        FunctionObject_15(Dog_15_36* wp, Pointer pmf);
        int operator()(int i) const;
    private:
        Dog_15_36* ptr;
        Pointer pmem;
    };
    FunctionObject_15 operator->*(Pointer pmf);
};

class Dog_15_36_1 : public Dog_15_36 {
public:
    int run(int i) const;
    int eat(int i) const;
    int sleep(int i) const;

    typedef int (Dog_15_36_1::*Pointer)(int) const;

    class FunctionObject_15 {
    public:
        FunctionObject_15(Dog_15_36_1 *wp, Pointer pmf);
        int operator()(int i) const;
    private:
        Dog_15_36_1* ptr;
        Pointer pmem;
    };
    FunctionObject_15 operator->*(Pointer pmf);
};
