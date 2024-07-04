#ifndef CHAPTER_24_H
#define CHAPTER_24_H

#include <iostream>
#include <set>
#include <vector>
#include <typeinfo>
#include <map>

#include "23_Generic_Containers.hpp"

class Base {
public:
    Base();
    virtual ~Base();
};

class Derived : public Base {
public:
    Derived();
    ~Derived();
};

template<class T> class AutoCounterA {
public:
    AutoCounterA() : id(count++) {
        className = typeid(T).name();
        cleanupCheck[className]++;
        std::cout << "AutoCounterA::AutoCounterA(), class: " << className << ", id: " << id << ", counter: " << cleanupCheck.at(className) << std::endl;
    }
    ~AutoCounterA() {
        cleanupCheck[className]--;
        std::cout << "AutoCounterA::AutoCounterA(), class: " << className << ", id: " << id << ", counter: " << cleanupCheck.at(className) << std::endl;
    }
    void trace() {
        std::cout << "AutoCounterA::Trace(), class: " << className << ", id: " << id << ", counter: " << cleanupCheck.at(className) << std::endl;
    }
    void verify() {
        std::cout << "AutoCounterA::verify(), size " << cleanupCheck.size() << std::endl;
        for (std::map<std::string, int>::iterator it = cleanupCheck.begin(); it != cleanupCheck.end(); it++)
            std::cout << "Class: " << className << ", id: " << id << ", counter: " << cleanupCheck.at(className) << std::endl;
    }
private:
    static int count;
    int id;
    std::string className;
    static std::map<std::string,int> cleanupCheck;
    AutoCounterA(const AutoCounterA&);
    void operator=(const AutoCounterA&);
};

class Class_2 {
public:
    Class_2();
    ~Class_2();
    AutoCounterA<Class_2> debug;
};

class Class_3 {
public:
    Class_3();
    ~Class_3();
    AutoCounterA<Class_3> debug;
};

class Instrument {
public:
    Instrument() {}
    virtual ~Instrument() {}
    void prepare();
};

class Wind : public Instrument {
public:
    Wind() {}
    ~Wind() {}
    virtual void clearValve();
};

class Stringed : public Instrument {
public:
    Stringed() {}
    ~Stringed() {}
};

class Food {
public:

};

class Beef : public Food {

};

class Fish : public Food {

};

class Oats : public Food {

};

#ifndef DANGER_CODE

class Pet_A {
public:
    Pet_A();
    virtual ~Pet_A();
    virtual void eat(Food& v);
};

class Dog_A : public Pet_A {
public:
    Dog_A();
    ~Dog_A();
    void eat(Beef& v);
};

class Cat_A : public Pet_A {
public:
     Cat_A();
    ~Cat_A();
    void eat(Fish & v);
};

class Horse : public Pet_A {
public:
    Horse();
    ~Horse();
    void eat(Oats & v);
};

#endif // DANGER_CODE

void drawQuad(Shape_2 *v);

bool lessShapeType(const Shape_2* lv, const Shape_2* rv);

#endif
