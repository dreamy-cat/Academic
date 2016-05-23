#ifndef L_02_CHAPTER_07_H
#define L_02_CHAPTER_07_H

#include <iostream>
#include <algorithm>
#include <list>
#include <stack>

class Noisy {
public:
    Noisy();
    ~Noisy();
    Noisy(const Noisy& rv);
    Noisy& operator=(const Noisy& rv);
    static void report();
    friend bool operator<(const Noisy& lv, const Noisy& rv);
    friend bool operator==(const Noisy& lv, const Noisy& rv);
    friend std::ostream& operator<<(std::ostream& os, const Noisy& value);
private:
    int id;
    static int create, assign, copyCons, destroy;
};

template<typename T>
void function_7_2(T v) {
    std::cout << "Sorting vector and deque, container size " << v.size() << std::endl;
    std::sort(v.begin(), v.end());
}

void function_7_2(std::list<Noisy> v);

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape();
};

class Circle : public Shape {
public:
    void draw();
    ~Circle();
};

class Triangle : public Shape {
public:
    void draw();
    ~Triangle();
};

class Square : public Shape {
public:
    void draw();
    ~Square();
};

void printStack(std::stack<int>& s, std::string name);

void sortStack(std::stack<int>& source, std::stack<int>& sorted, std::stack<int>& tail);

#endif
