#ifndef L_02_CHAPTER_10_H
#define L_02_CHAPTER_10_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Singleton {
public:
    static Singleton& instance();
    static int getValue();
    static void setValue(int x);
private:
    static Singleton single;
    static int i;
    Singleton(int x);
    Singleton& operator=(Singleton&);
    Singleton(const Singleton&);
};

class Class_10_2 {
public:
    static std::string readFile();
    static std::string file;
    static std::fstream text;
private:
    static Class_10_2 reader;
    Class_10_2();
    Class_10_2(const Class_10_2&);
    Class_10_2& operator=(Class_10_2&);
};

class Class_10_3 {
public:
    static void init(int lim);
    static bool create(Class_10_3* newObject);
private:
    static std::vector<Class_10_3*> objects;
    static int counter, limit;
    Class_10_3();
    Class_10_3(const Class_10_3&);
    Class_10_3& operator=(Class_10_3&);
};

class StateRotation {
    class State {
    public:
        virtual void responce() = 0;
    };
    class Object : public State {
    public:
        void responce();
    };
    class Material : public State {
    public:
        void responce();
    };
    class Tool : public State {
    public:
        void responce();
    };
    State* state;
    int iteration, limit;
public:
    StateRotation();
    void function();
    void action();
    // virtual ~StateRotation();
};

#endif
