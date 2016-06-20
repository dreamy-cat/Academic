#ifndef L_02_CHAPTER_10_H
#define L_02_CHAPTER_10_H

#include <iostream>
#include <fstream>
#include <string>
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
};

template<class T> class Stack_10 {
private:
    struct Link {
        T* data;
        Link* next;
        Link(T* newData, Link* nextLink) : data(newData), next(nextLink) {}
    }* head;
public:
    Stack_10() : head(0) {}
    ~Stack_10() {
        while (head)
            delete pop();
    }
    void push(T* value) {
        head = new Link(value, head);
    }
    T* peek() const {
        if (head) return head->data; else return 0;
    }
    T* pop() {
        if (head == 0) return 0;
        T* result = head->data;
        Link* oldHead = head;
        head = head->next;
        delete oldHead;
        return result;
    }
};

template<class T> class StackAdapter {
public:
    StackAdapter(Stack_10<T>& iStack) : stack(iStack) {}
    class iterator;
    friend class iterator;
    class iterator : public std::iterator<std::input_iterator_tag, StackAdapter<T>, std::ptrdiff_t> {
    private:
        StackAdapter<T>& adapter;
    public:
        T* element;
        iterator(StackAdapter& as) : adapter(as) {
            element = adapter.stack.peek();
        }
        bool operator==(const iterator& rv) {
            return ( element == rv.element );
        }
        bool operator!=(const iterator& rv) {
            return ( element != rv.element );
        }
        T operator*() const {
            return *element;
        }
        iterator& operator++() {
            element = adapter.stack.pop();
            return *this;
        }
        iterator operator++(int) {
            element = adapter.stack.pop();
            return *this;
        }
        friend std::ostream& operator<<(std::ostream& os, iterator value) {
            if ( value.element ) return os << "StackAdapter::iterator = " << *(value.element) << std::endl; else
                return os << "StackAdapter::iterator = NULL" << std::endl;
        }
    };
public:
    iterator begin() {
        iterator beg(*this);
        beg.element = stack.pop();
        return beg;
    }
    iterator end() {
        iterator term(*this);
        term.element = 0;
        return term;
    }
private:
    Stack_10<T>& stack;
};

void function_10_5(std::string value);

class Class_10_6 {
public:
    Class_10_6(std::vector<std::string>& fileNames);
    virtual ~Class_10_6();
    virtual void toUpperCase();
    virtual void searchWords();
private:
    std::vector<std::fstream*> files;
};

class Class_10_6_1 : public Class_10_6 {
public:
    Class_10_6_1(std::vector<std::string>& fileNames);
    ~Class_10_6_1();
    void toUpperCase();
};

class Class_10_6_2 : public Class_10_6 {
public:
    Class_10_6_2(std::vector<std::string>& fileNames);
    ~Class_10_6_2();
    void searchWords();
};

#endif
