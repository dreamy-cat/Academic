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

class Class_7_11 {
public:
    Class_7_11();
    int priority;
    friend bool operator<(const Class_7_11& lv, const Class_7_11& rv);
    friend std::ostream& operator<<(std::ostream& os, const Class_7_11& value);
};

template<class T> class Ring {
public:
    class iterator;
    friend class iterator;
    class iterator : public std::iterator<std::bidirectional_iterator_tag, T, std::ptrdiff_t> {
    private:
        typename std::deque<T>::iterator it;
        std::deque<T>*  r;
    public:
        iterator(std::deque<T>& lst, const typename std::deque<T>::iterator& i) : r(&lst), it(i) {}

        bool operator==(const iterator& x) const {
            return (it == x.it);
        }

        bool operator!=(const iterator& x) const {
            return !(*this == x.it);
        }

        typename std::deque<T>::reference operator*() const {
            return *it;
        }

        iterator& operator++() {
            ++it;
            if ( it == r->end() )it = r->begin();
            return *this;
        }

        iterator& operator++(int) {
            iterator tmp = *this;
            ++*this;
            return tmp;
        }

        iterator& operator--() {
            if (it == r->begin()) it = r->end();
            --it;
            return *this;
        }

        iterator& operator--(int) {
            iterator tmp = *this;
            --*this;
            return tmp;
        }

        iterator insert(const T& x) {
            return iterator(*r, r->insert(it, x));
        }

        iterator erase() {
            return iterator(*r, r->erase(it));
        }
    };

    void push_back(const T& x) {
        lst.push_back(x);
    }

    iterator begin() {
        return iterator(lst, lst.begin());
    }

    int size() {
        return lst.size();
    }

private:
    std::deque<T> lst;
};

#endif
