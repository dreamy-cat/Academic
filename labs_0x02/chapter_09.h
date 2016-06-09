#ifndef L_02_CHAPTER_09_H
#define L_02_CHAPTER_09_H

#include <iostream>

class Class_X {
public:
    Class_X(int) {}
    void function() {}
};

class Class_Y : public Class_X {
public:
    Class_Y(int) : Class_X(0) {}
};

class Class_Z : public Class_X {
public:
    Class_Z(int) : Class_X(0) {}
};

class Class_A : public Class_Y, public Class_Z {
public:
    Class_A() : Class_Y(1), Class_Z(1) {}
    // If we using in both base classes.
    using Class_Y::function;
};

class Animal {
public:
    virtual ~Animal();
    virtual void noise() = 0;
    virtual void move() = 0;
};

class Hero {
public:
    virtual ~Hero();
    virtual void save() = 0;
    virtual void move() = 0;
};

class Bat : public Hero {
public:
    Bat();
    void save();
    void move();
};

class Tarantool : public Hero, public Animal{
public:
    Tarantool();
    void noise();
    void save();
    void move();

};

class FatCat : public Hero, public Animal {
public:
    FatCat();
    void noise();
    void save();
    void move();

};

void noisy(Animal* ptr);

void saves(Hero* ptr);

#endif
