#ifndef CHAPTER_16_H
#define CHAPTER_16_H

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
        Link(T* dat, Link* nxt);
    }* head;
public:
    TStack();
    ~TStack();
    void push(T* dat);
    T* pop();
    T* peek() const;
    class iterator;
    friend class iterator;
    class iterator {
    public:
        iterator(const TStack<T>& tl);
        iterator(const iterator& tl);
        iterator();
        bool operator++();
        bool operator++(int);
        T* current() const;
        T* operator->() const;
        T* operator*() const;
        operator bool() const;
        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;
    private:
        TStack::Link* sp;
    };
    iterator begin() const;
    iterator end() const;
};

#endif
