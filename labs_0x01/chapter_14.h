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

#endif
