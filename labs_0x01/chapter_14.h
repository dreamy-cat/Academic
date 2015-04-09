#ifndef CHAPTER_14_H
#define CHAPTER_14_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

class Engine_14 {
public:
    void start() const {}
    void rev() const {}
    void stop() const {}
};

class Wheel_14 {
public:
    void inflate(int psi) const {}
};

class Window_14 {
public:
    void rollup() const {}
    void rolldown() const {}
};

class Door_14 {
public:
    Window_14 window;
    void open() const {}
    void close() const {}
};

class Vehicle_14 {
public:
    Vehicle_14(int ii);
    void function_1();
private:
    int i;
};

class Car_14 : public Vehicle_14 {
public:
    Car_14 (int ii);
    Engine_14 engine;
    Wheel_14 wheel[4];
    Door_14 left, right;
};

class Class_14_2_1 {
public:
    Class_14_2_1();
};

class Class_14_2_2 {
public:
    Class_14_2_2();
};

class Class_14_2_3 : public Class_14_2_1 {
public:
    Class_14_2_2 b;
};

class Class_14_3_1 {
public:
    Class_14_3_1();
    ~Class_14_3_1();
};

class Class_14_3_2 : public Class_14_3_1 {
public:
    Class_14_3_2();
    ~Class_14_3_2();
};

class Class_14_3_3 : public Class_14_3_2 {
public:
    Class_14_3_3();
    ~Class_14_3_3();
};

class Combined_A {
public:
    Combined_A(int ii);
    ~Combined_A();
    void function_1() const {}
private:
    int i;
};

class Combined_B {
public:
    Combined_B(int ii);
    ~Combined_B();
    void function_1() const {}
private:
    int i;
};

class Combined_C : public Combined_B {
public:
    Combined_C(int ii);
    ~Combined_C();
    void function_1() const;
private:
    Combined_A a;
};

class Combined_D : public Combined_B {
public:
    Combined_D(int ii);
    ~Combined_D();
    void function_1() const;
private:
    Combined_C a2;
};

class Base_6 {
public:
    Base_6(int ii);
    ~Base_6();
};

class Member_6_1 {
public:
    Member_6_1(int ii);
    ~Member_6_1();
};

class Member_6_2 {
public:
    Member_6_2(int ii);
    ~Member_6_2();
};

class Derived_6_1 : public Base_6 {
public:
    Derived_6_1(int ii);
    ~Derived_6_1();
private:
    Member_6_1 m1;
};

class Derived_6_2 : public Derived_6_1 {
public:
    Derived_6_2(int ii);
    ~Derived_6_2();
private:
    Member_6_2 m2;
};

class Derived_6_3 : public Derived_6_2 {
public:
    Derived_6_3(int ii);
    ~Derived_6_3();
private:
    Member_6_1 m1;
    Member_6_2 m2;
};

class Base_7 {
public:
    int f() const;
    int f(std::string) const;
    void g() {}
    void h() {}
    void h(std::string) {}
    int h(int);
};

class Derived_7_1 : public Base_7 {
public:
    void g() const {}
    int h(int);
};

class Derived_7_2 : public Base_7 {
public:
    int f() const;
};

class Derived_7_3 : public Base_7 {
public:
    void f() const;
};

class Derived_7_4 : public Base_7 {
public:
    int f(int) const;
};

class StringStack : public std::vector<void*> {
public:
    StringStack();
    void push_back(std::string *string);
    const std::string* operator[](int index) const;
private:
    std::vector<std::string*> storage;
};

class Class_14_10 {
public:
    Class_14_10(long i);
private:
    long l;
};

class Asteroid {
public:
    Asteroid();
    ~Asteroid();
//    PStash_14 stash;
};

class PStash_14 {
public:
    PStash_14();
    ~PStash_14();
    int add(void* element);
    void* operator[](int index) const;
    void* remove(int index);
    int count() const;
private:
    int quantity;
    int next;
    void** storage;
    void inflate(int increase);
};

class PStash_14_1 : PStash_14 {
public:
    PStash_14_1();
    ~PStash_14_1();
    int add(Asteroid* element);
    Asteroid* operator[](int index) const;
    Asteroid* remove(int index);
    int count() const;
};

class PStash_14_2 {
public:
    PStash_14_2();
    ~PStash_14_2();
    int add(Asteroid* element);
    Asteroid* operator[](int index) const;
    Asteroid* remove(int index);
    int count() const;
private:
    PStash_14 p;
};

class PStash_14_3 : std::vector<void*> {
public:
    PStash_14_3();
    ~PStash_14_3();
    int add(Asteroid* element);
    Asteroid* operator[](int index) const;
    Asteroid* remove(int index);
    int count() const;
};

class PStash_14_4 {
public:
    PStash_14_4();
    ~PStash_14_4();
    int add(Asteroid* element);
    Asteroid* operator[](int index) const;
    Asteroid* remove(int index);
    int count() const;
private:
    std::vector<void*> v;
};

class Class_14_15_1 {
public:
    static void function_1();
    static void function_2();
};

class Class_14_15_2 : public Class_14_15_1 {
public:
    static void function_2();
};

class GameBoard {
public:
    GameBoard();
    GameBoard(const GameBoard&);
    GameBoard& operator=(const GameBoard&);
    ~GameBoard();
};

class Game {
public:
    Game();
    Game(const Game& g);
    Game(int);
    Game& operator=(const Game& g);
    class Other {};
    operator Other() const;
    ~Game();
private:
    GameBoard gb;
};

class Chess : public Game {
public:
    Chess();
    Chess(const Chess& c);
    Chess& operator=(const Chess& c);
};

void function_14_13(Game::Other);

class Checkers : public Game {
public:
    Checkers();
    Checkers(const Checkers& c);
    Checkers& operator=(const Checkers& c);
};

class Traveler {
public:
    Traveler(std::string s);
    Traveler(const Traveler& r);
    Traveler& operator=(const Traveler& r);
private:
    std::string str;
};

class Pager {
public:
    Pager(std::string s);
    Pager(const Pager& r);
    Pager& operator=(const Pager& r);
private:
    std::string str;
};

class BuisnessTraveler : public Traveler {
public:
    BuisnessTraveler();
    BuisnessTraveler(std::string s);
    BuisnessTraveler(const BuisnessTraveler& r);
    BuisnessTraveler& operator=(const BuisnessTraveler& r);
private:
    Pager one;
};

void function_14_14(BuisnessTraveler v);

class FName : public std::fstream {
public:
    FName(const std::string fname);
    std::string name() const;
    void name(std::string newName);
private:
    std::string fileName;
    bool named;
};

class Class_14_17 {
public:
    Class_14_17(int ii) : i(ii) {}
    int i;
};

class Class_14_17_1 : private Class_14_17 {
public:
    Class_14_17_1(int ii) : Class_14_17(ii) {}
};

class Class_14_17_2 : protected Class_14_17 {
public:
    Class_14_17_2(int ii) : Class_14_17(ii) {}
};

void function_14_17(Class_14_17& c);

class Base_18 {
public:
    Base_18(int ii = 0);
    int value(int m) const;
protected:
    int read() const;
    void set(int ii);
private:
    int i;
};

class Derived_18 : protected Base_18 {
public:
    Derived_18(int jj);
    void change(int x);
    int readvalue() const;
private:
    int j;
};

class SpaceShip {
public:
    void fly();
};

class Shuttle : public SpaceShip {
public:
    void land();
};

class Instrument_14 {
public:
    virtual void play(int) const;
    void prepare();
};

class Wind_14 : public Instrument_14 {
public:
    void play(int) const;
};

void function_14_21(Instrument_14& r);

class Parent_14 {
public:
    Parent_14();
    Parent_14(int ii);
    Parent_14(Parent_14& p);
    friend std::ostream& operator<<(std::ostream& os, const Parent_14& v);
private:
    int i;
};

class Member_14 {
public:
    Member_14(int ii);
    Member_14(const Member_14& p);
    friend std::ostream& operator<<(std::ostream& os, const Member_14& v);
private:
    int i;
};

class Child_14 : public Parent_14 {
public:
    Child_14(int ii);
    Child_14(const Child_14& c);
    friend std::ostream& operator<<(std::ostream& os, const Child_14& v);
private:
    int i;
    Member_14 m;
};

class Toy_14 : public Child_14 {
public:
    Toy_14(int ii);
    Toy_14(const Toy_14& t);
    Toy_14& operator=(const Toy_14& t);
    friend std::ostream& operator<<(std::ostream& os, const Toy_14& v);
private:
    int i;
    Member_14 m;
};

class StringStack_14 {
public:
    void push(std::string* str);
    std::string* pop();
    std::string* peek(int index);
private:
    std::vector<std::string*> storage;
};

class Rock {
public:
    Rock();
    Rock(const Rock& r);
    Rock& operator=(const Rock& r);
    ~Rock();
};

class Subject {
public:
    void f();
    void g();
    void h();
};

class Proxy : public Subject {
public:
    Proxy(Subject* ptr) : subjPtr(ptr) {}
private:
    Subject* subjPtr;
};

class Implementation_1 : public Subject {
public:
    void f1();
    void f2();
    void f3();
};

class Implementation_2 : public Subject {

};

class Widget_14 {
public:
    Widget_14();
    ~Widget_14();
    void* operator new(size_t sz);
    void operator delete(void* p);
    void* operator new[](size_t sz);
    void operator delete[](void* p);
private:
    int i[5];
};

class Class_14_28 : public Widget_14 {
public:
    Class_14_28();
    ~Class_14_28();
    void* operator new(size_t sz);
    void operator delete(void* p);
    void* operator new[](size_t sz);
    void operator delete[](void* p);
};

class Framis_14 {
public:
    Framis_14();
    ~Framis_14();
    void* operator new(size_t);
    void operator delete(void*);
private:
    char c;
    static unsigned char pool[];
    static bool alloc_map[];
    const static int maxSz = 4;
};

class Class_14_29 : public Framis_14 {
public:
    void* operator new (size_t sz);
    void operator delete (void* p);
};

#endif
