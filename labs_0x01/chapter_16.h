#ifndef CHAPTER_16_H
#define CHAPTER_16_H

#include "memory.h"
#include <iostream>
#include <vector>

class Object {};

class Shape {};

class OShape : public Object, public Shape {};

class Circle : public Shape {};

class Square : public Shape {};

class Triangle : public Shape {};

class OCircle : public OShape, public Circle {};

class OSquare : public OShape, public Square {};

class OTriangle : public OShape, public Triangle {};

template<class T> class TStack {
    struct Link {
        T* data;
        Link* next;
        Link(T* dat, Link* nxt) : data(dat), next(nxt) {}
    }* head;
public:
    TStack() : head(0) {}

    ~TStack() {
        while (head)
            delete pop();

    }

    void push(T* dat) {
        head = new Link(dat, head);
    }

    T* pop() {
        if (head == 0) return 0;
        T* result = head->data;
        Link* oldHead = head;
        head = head->next;
        delete oldHead;
        return result;
    }

    T* peek() const {
        if (head != 0) return head->data; else return 0;
    }

    class iterator;
    friend class iterator;
    class iterator {
    public:
        iterator(const TStack<T>& tl) : sp(tl.head) {}

        iterator(const iterator& tl) : sp(tl.sp) {}

        iterator() : sp(0) {}

        bool operator++() {
            if (sp->next != 0) sp = sp->next; else sp = 0;
            return bool(sp);
        }

        bool operator++(int) {
            return operator++();
        }

        T* current() const {
            if (sp == 0) return 0; else return sp->data;
        }

        T* operator->() const {
            if (sp == 0) return 0; else return current();
        }

        T* operator*() const {
            return current();
        }

        operator bool() const {
            return bool (sp);
        }

        bool operator==(const iterator&) const {
            return (sp == 0);
        }

        bool operator!=(const iterator&) const {
            return (sp != 0);
        }

    private:
        TStack::Link* sp;
    };

    iterator begin() const {
        return iterator(*this);
    }

    iterator end() const {
        return iterator();
    }
};

template<class T> class TPStash_1 {
public:
    TPStash_1() : quantity(0), next(0), storage(0), increase(2) {}
    ~TPStash_1();
    int add(T* element);
    T* operator[](int index) const;
    T* remove(int index);
    int count() const { return next; }
private:
    int quantity;
    int next;
    int increase;
    T** storage;
    void inflate();
};

template<class T> int TPStash_1<T>::add(T* element) {
    if (next >= quantity) inflate();
    storage[next++] = element;
    return (next - 1);
}

template<class T> TPStash_1<T>::~TPStash_1() {
    for (int i = 0; i < next; i++) {
        delete storage[i];
        storage[i] = 0;
    }
    delete []storage;
}

template<class T> T* TPStash_1<T>::operator [](int index) const {
    if (index < 0 || index >= next) return 0;
    return storage[index];
}

template<class T> T* TPStash_1<T>::remove(int index) {
    if (index <= 0 || index >= next) return 0;
    T* value = operator[](index);
    return value;
}

template<class T> void TPStash_1<T>::inflate() {
    T** newStorage = new T*[quantity + increase];
    memset((void*)newStorage, 0, (quantity + increase)*sizeof(T*));
    memcpy((void*)newStorage, (void*)storage, quantity*sizeof(T*));
    quantity += increase;
    std::cout << "TPStash_1::inflate(), increase = " << increase << std::endl;
    increase *= 2;
    delete []storage;
    storage = newStorage;
}

template<typename T> T fibonacci(unsigned char n) {
    if (n == 0) return T(0);
    if (n <= 2) return T(1);
    n -= 2;
    T f1 = 1, f2 = 1, f3 = 1;
    while (n) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
        n--;
    }
    return f3;
}

template<class T> class TSet {
public:
    TSet() { elements.clear(); }

    ~TSet() {}

    bool add(T* element) {
        bool result = true;
        for (typename std::vector<T>::iterator it = elements.begin(); it < elements.end(); it++)
            if (*it == *element) result = false;
        if (result) elements.push_back(*element);
        return result;
    }

    bool remove(T* element) {
        bool result = false;
        for (typename std::vector<T>::iterator it = elements.begin(); it < elements.end(); it++)
            if (*it == *element) {
                result = true;
                elements.erase(it);
            }
        return result;
    }

    class iterator;
    friend class iterator;
    class iterator {
    public:
        iterator(TSet<T>* set) : sp(0), base(&(set->elements)) {}

        iterator(const iterator& v) : sp(v.sp) {}

        iterator() : sp(0) {}

        bool operator++() {
            if (sp < (base->size()-1)) {
                sp++;
                std::cout << "R = " << sp << std::endl;
                return false;
            } else return true;
        }

        bool operator++(int) {
            return operator++();
        }

        T* current() const {
            return &base->operator[](sp);
        }

        T* operator->() const {
            if (sp == 0) return 0; else return current();
        }

        T* operator*() const {
            return current();
        }
    private:
        int sp;
        std::vector<T>* base;
    };

private:
    std::vector<T> elements;
};

#endif
