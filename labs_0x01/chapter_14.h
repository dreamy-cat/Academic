#ifndef CHAPTER_14_H
#define CHAPTER_14_H

#include <iostream>

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

#endif
