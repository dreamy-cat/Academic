#ifndef CHAPTER_25
#define CHAPTER_25

#include <iostream>
#include <fstream>

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

class Train {
public:
    void stopTrain();
};

class Car {
public:
    void rideCar();
};

class Animal {
public:
    virtual ~Animal();
    virtual void noise() = 0;
    virtual void move() = 0;
};

#ifndef DANGER_CODE

class Hero {
public:
    Hero(int s);
    virtual ~Hero();
    virtual void save() = 0;
    virtual void move() = 0;
    virtual void workout();
    virtual void work();
    int str;
};

class HuntingCat : public Hero {
public:
    HuntingCat(int i);
    ~HuntingCat();
    void work();
    void save();
    void move();
    int s;
};

class Bat : public Hero {
public:
    Bat(int i);
    void save();
    void move();
    void eat(int v);
    void workout();
};

class Tarantool : public Hero, public Animal {
public:
    Tarantool(int i);
    void noise();
    void save();
    void move();

};

class FatCat : virtual public Hero, virtual public Bat {
public:
    FatCat(int i);
    void noise();
    void save();
    void move();
    void eat(char c);
    using Bat::workout;
};

class FunnyFatCat : virtual public FatCat, virtual public Bat {
    // It seems no effect of virtual in this case.
public:
    FunnyFatCat(int i);
    using FatCat::eat;
    FunnyFatCat& operator=(const FunnyFatCat& rv);
    friend std::ostream& operator<<(std::ostream& os, const FunnyFatCat& rv);
};

class SuperCat {
public:
    SuperCat(int i);
    Bat h;
    FatCat fc;
};

#endif  // DANGER_CODE

class Counter {
public:
    int attach(std::string name);
    int detach();
    int refCount() const;
protected:
    Counter(std::string name);
    virtual ~Counter();
private:
    int count;
    static std::fstream log;
    static int globalCount;
};

class Class_15 : public Counter {
public:
    Class_15();
    void create();
    virtual ~Class_15();
};

class Class_16 {
public:
    virtual ~Class_16();
};

class Class_16_1 : virtual public Class_16 {
public:
    void function();
};

class Class_16_2 : virtual public Class_16 {
public:
    void function();
};

class Class_16_3 : public Class_16_1, public Class_16_2 {
public:
    using Class_16_1::function;
};

class Class_16_4 : public Class_16_3 {
public:
    using Class_16_2::function;
};

template<class Animal> void noisy(Animal* ptr) {
    ptr->noise();
}

template<class Animal> void move(Animal* ptr) {
    ptr->move();
}

template<class Animal, class Hero> void move(Animal* ptr_1, Hero* ptr_2) {
    ptr_1->move();
    ptr_2->move();
}

template<class Hero, class Train, class Car> void save(Hero* ptr_1, Train* ptr_2, Car* ptr_3) {
    ptr_1->save();
    ptr_2->stopTrain();
    ptr_3->rideCar();
}

#endif
