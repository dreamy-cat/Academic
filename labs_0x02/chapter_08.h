#ifndef L_02_CHAPTER_08_H
#define L_02_CHAPTER_08_H

#include <iostream>
#include <set>
#include <vector>
#include <typeinfo>
#include <map>

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

template<class T> class AutoCounter {
public:
    AutoCounter() : id(count++) {
        className = typeid(T).name();
        cleanupCheck[className]++;
        std::cout << "AutoCounter::Autocounter(), class: " << className << ", id: " << id << ", counter: " << cleanupCheck.at(className) << std::endl;
    }
    ~AutoCounter() {
        cleanupCheck[className]--;
        std::cout << "AutoCounter::Autocounter(), class: " << className << ", id: " << id << ", counter: " << cleanupCheck.at(className) << std::endl;
    }
    void trace() {
        std::cout << "AutoCounter::Trace(), class: " << className << ", id: " << id << ", counter: " << cleanupCheck.at(className) << std::endl;
    }
    void verify() {
        std::cout << "Autocounter::verify(), size " << cleanupCheck.size() << std::endl;
        for (std::map<std::string, int>::iterator it = cleanupCheck.begin(); it != cleanupCheck.end(); it++)
            std::cout << "Class: " << className << ", id: " << id << ", counter: " << cleanupCheck.at(className) << std::endl;
    }
private:
    static int count;
    int id;
    std::string className;
    static std::map<std::string,int> cleanupCheck;
    AutoCounter(const AutoCounter&);
    void operator=(const AutoCounter&);
};

class Class_2 {
public:
    Class_2();
    ~Class_2();
    AutoCounter<Class_2> debug;
};

class Class_3 {
public:
    Class_3();
    ~Class_3();
    AutoCounter<Class_3> debug;
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

class Pet {
public:
    Pet();
    virtual ~Pet();
    virtual void eat(Food& v);
};

class Dog : public Pet {
public:
    Dog();
    ~Dog();
    void eat(Beef& v);
};

class Cat : public Pet {
public:
     Cat();
    ~Cat();
    void eat(Fish & v);
};

class Horse : public Pet {
public:
    Horse();
    ~Horse();
    void eat(Oats & v);
};

#endif
