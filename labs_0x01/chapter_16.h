#ifndef CHAPTER_16_H
#define CHAPTER_16_H

#include "memory.h"
#include <iostream>
#include <vector>
#include <set>
#include <stack>

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
        iterator(TSet<T>& set) : sp(0), base(&(set.elements)) {
            std::cout << "Addr = " << (long)base << std::endl;
        }

        iterator(const iterator& v) : sp(v.sp) {}

        iterator() : sp(0) {}

        bool operator++() {
            if (sp < (base->size()-1)) {
                sp++;
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

class AutoCounter {
public:
    static AutoCounter* create(bool quietly) {
        quiet = quietly;
        return new AutoCounter();
    }
    ~AutoCounter() {
        std::cout << "Destroying[" << className << ":" << id << "]" << std::endl;
        verifier.remove(this);
    }
    friend std::ostream& operator<<(std::ostream& os, const AutoCounter& value) { return os << "AutoCounter[" << value.id << "]"; }
    friend std::ostream& operator<<(std::ostream& os, const AutoCounter* value) { return os << "AutoCounter[" << value->id << "]"; }
private:
    static int count;
    int id;
    static bool quiet;
    std::string className;
    AutoCounter() : id(count++) {
        verifier.add(this);
        className = "AutoCounter";
        if (!quiet) std::cout << "AutoCounter constructor[" << className << ":" << id << "]" << std::endl;
    }
    AutoCounter(const AutoCounter&);
    void operator=(const AutoCounter&);
    class CleanupCheck {
    public:
        void add(AutoCounter* ap) { trace.insert(ap); }
        void remove(AutoCounter* ap) { trace.erase(ap); }
        ~CleanupCheck() { if (!quiet) std::cout << "CleanupCheck destructor, elements in set: " << trace.size() << std::endl; }
    private:
        std::set<AutoCounter*> trace;
    };
    static CleanupCheck verifier;
};

template<class T> class OStack {
private:
    std::vector<T*> elements;
    bool own;
public:
    OStack(bool owned = true) : own(owned) {}
    ~OStack() {
        if (!own) return;
        std::cout << "Cleanup OStack." << std::endl;
        while (!elements.empty()) delete pop();
    }
    void push (T* dat) { elements.push_back(dat); }
    T* pop() {
        if (elements.empty()) return 0;
        T* result = elements[elements.size()-1];
        elements.pop_back();
        return result;
    }
    T* peek() const { if (!elements.empty()) elements[0]; else return 0; }
    bool owns() const { return own; }
    void owns(bool newOwns) { own = newOwns; }
    operator bool() const { return elements.empty(); }
};

template<class T> class VStack {
public:
    VStack(int maxElements = 4) : maxSize(maxElements), sp(0) { stack.clear(); }
    ~VStack() {
        // delete []stack;
        stack.clear();
    }
    void push(T& element) {
        stack.push_back(element);
/*
        if (sp == maxSize) {
            T* newStack = new T[maxSize*2];
            for (int i = 0; i < maxSize; i++) newStack[i] = stack[i];
            maxSize *= 2;
            delete []stack;
            stack = newStack;
        }
        stack[sp++] = element;
        */
    }
    T pop() {
        T element = stack[stack.size()-1];
        stack.pop_back();
        return element;
    }
private:
    std::vector<T> stack;
    int maxSize, sp;
};

template<class T> class TStack_2 {
public:
    TStack_2() { storage.clear(); }
    ~TStack_2() { storage.clear(); }
    void push(T* element) { storage.push_back(element); }
    T* pop() {
        T* r = storage[storage.size()-1];
        storage.pop_back();
        return r;
    }
    class iterator;
    friend class iterator;
    class iterator {
    public:
        iterator(TStack_2<T>& baseRef) : base(&baseRef.storage), sp(0) {}
        iterator(const iterator& r) : base(r.base) {}
        bool operator++() {
            if (sp == base->size()) return true;
            sp++;
            return false;
        }
        bool operator++(int) { return operator++(); }
        T* current() const {
            if (sp < 0 || sp >= base->size()) return NULL;
            return base[sp];
        }
        T* operator->() {
            if (sp < 0 || sp >= base->size()) return NULL;
            return current();
        }
        T* operator*() const { return current(); }
    private:
        std::vector<T*>* base;
        int sp;
    };
private:
    std::vector<T*> storage;
};

template<class T> class TStack_3 {
public:
    TStack_3() { }
    ~TStack_3() { while (!storage.empty()) storage.pop(); }
    void push(T* element) { storage.push(element); }
    T* pop() {
        T* r = storage.top();
        storage.pop();
        return r;
    }
    class iterator;
    friend class iterator;
    class iterator {
    public:
        iterator(TStack_3<T>& baseRef) : base(&baseRef.storage), sp(0) {}
        iterator(const iterator& r) : base(r.base) {}
        bool operator++() {
            if (sp == base->size()) return true;
            sp++;
            return false;
        }
        bool operator++(int) { return operator++(); }
        T* current() const {
            if (sp < 0 || sp >= base->size()) return NULL;
            return base[sp];
        }
        T* operator->() {
            if (sp < 0 || sp >= base->size()) return NULL;
            return current();
        }
        T* operator*() const { return current(); }
    private:
        std::stack<T*>* base;
        int sp;
    };
private:
    std::stack<T*> storage;
};

template<class T, int increase = 2> class PStash_1 {
public:
    PStash_1() { storage.clear(); }
    ~PStash_1() { for (int i = 0; i < storage.size(); i++) delete storage[i]; }
    int add(T* element) { storage.push_back(element); }
    T* operator[](int index) const { return storage[index]; }
    T* remove(int index) {
        typename std::vector<T*>::iterator it = storage.begin();
        for (int i = 0; i < index; i++) it++;
        T* r = *it;
        storage.erase(it);
        return r;
    }
    int count() const { return storage.size(); }
    class iterator;
    friend class iterator;
    class iterator {
    public:
        iterator(PStash_1& stash) : pstash(stash), index(0) {}
        iterator(PStash_1& stash, bool) : pstash(stash), index(stash.storage.size()) {}
        iterator(const iterator& value) : pstash(value.pstash), index(value.index) {}
        iterator& operator=(const iterator& value) {
            pstash = value.pstash;
            index = value.index;
            return *this;
        }
        iterator& operator++() {
            if (index > pstash.storage.size()) return *this;
            index++;
            return *this;
        }
        iterator& operator++(int) { return operator++(); }
        iterator& operator--() {
            if (index == 0) return *this;
            index--;
            return *this;
        }
        iterator& operator--(int) { return operator--(); }
        iterator& operator+=(int amount) {
            if (index+amount >= pstash.storage.size() || index+amount < 0) return *this;
            index += amount;
            return *this;
        }
        iterator& operator-=(int amount) {
            if (index-amount >= pstash.storage.size() || index-amount < 0) return *this;
            index -= amount;
            return *this;
        }
        iterator operator+(int amount) const {
            iterator result(*this);
            result += amount;
            return result;
        }
        iterator operator-(int amount) const {
            iterator result(*this);
            result -= amount;
            return result;
        }
        T* current() const { return pstash.storage[index]; }
        T* operator*() const { return current(); }
        T* operator->() const { return current(); }
        T* remove() { pstash.remove(index); }
        bool operator==(const iterator& value) { return (index == value.index); }
        bool operator!=(const iterator& value) { return (index != value.index); }
    private:
        int index;
        PStash_1& pstash;
    };
    iterator begin() { return iterator(*this); }
    iterator end() { return iterator(*this, true); }
private:
    std::vector<T*> storage;
};

class Int {
public:
    Int(int ii);
    ~Int();
    friend std::ostream& operator<<(std::ostream& os, const Int& value);
    friend std::ostream& operator<<(std::ostream& os, const Int* value);
private:
    int i;
};

template<class T, int ssize = 5> class StackTemplate {
public:
    StackTemplate() : top(0) {}
    void push(const T& value) {
        if (top == ssize) {
            std::cout << "Too many elements in stack." << std::endl;
            return;
        }
        stack[top++] = value;
    }
    T pop() {
        if (top == 0) return T();
        return stack[--top];
    }
    class iterator;
    friend class iterator;
    class iterator {
    public:
        iterator(StackTemplate& st) : stackTempl(st), index(0) {}
        iterator(StackTemplate& st, bool) : stackTempl(st), index(st.top) {}
        T operator*() const { return stackTempl.stack[index]; }
        T operator++() {
            if (index >= stackTempl.top) return T();
            return stackTempl.stack[++index];
        }
        T operator++(int) {
            if (index >= stackTempl.top) return T();
            return stackTempl.stack[index++];
        }
        iterator& operator+=(int amount) {
            if (index + amount > stackTempl.top || index + amount < 0) return *this;
            index += amount;
            return *this;
        }
        bool operator==(const iterator& value) { return (index == value.index); }
        bool operator!=(const iterator& value) { return (index != value.index); }
        friend std::ostream& operator<<(std::ostream& os, const iterator& value) { return os << *value; }
    private:
        StackTemplate& stackTempl;
        int index;
    };
    iterator begin() { return iterator(*this); }
    iterator end() { return iterator(*this, true); }
private:
    T stack[ssize];
    int top;
};

class Shape_16 {
public:
    virtual void draw() = 0;
    virtual void erase() = 0;
    virtual ~Shape_16() {}
};

class Circle_16 : public Shape_16 {
public:
    Circle_16() {}
    ~Circle_16() { std::cout << "Circle_16 destructor." << std::endl; }
    void draw() { std::cout << "Circle_16::draw()." << std::endl; }
    void erase() { std::cout << "Circle_16::erase()." << std::endl; }
};

class Square_16 : public Shape_16 {
public:
    Square_16() {}
    ~Square_16() { std::cout << "Square_16 destructor." << std::endl; }
    void draw() { std::cout << "Square_16::draw()." << std::endl; }
    void erase() { std::cout << "Square_16::erase()." << std::endl; }
};

class Line_16 : public Shape_16 {
public:
    Line_16() {}
    ~Line_16() { std::cout << "Line_16 destructor." << std::endl; }
    void draw() { std::cout << "Line_16::draw()." << std::endl; }
    void erase() { std::cout << "Line_16::erase()." << std::endl; }
};

template<class T> void function_16_24(T* object) {
    std::cout << "Template function_16_24." << std::endl;
    object->erase();
}


template<class T> class Template_17 {
public:
    Template_17(T ii) : t(ii) {}
    ~Template_17() {}
    friend std::ostream& operator<<(std::ostream& os, const Template_17<T>& value) {
        return os << "Template_17: " << value.t << std::endl;
    }
    friend std::ostream& operator<<(std::ostream& os, const Template_17<T>* value) {
        return os << "Template_17: " << value->t << std::endl;
    }
private:
    T t;
};

template<class T, int aSize = 4> class TemplArray_16 {
public:
    TemplArray_16() { memset((void*)array, 0, aSize * sizeof(T)); }
    T& operator[](int x) {
        if (x < 0 || x >= aSize) return T();
        return array[x];
    }
    friend std::ostream& operator<<(std::ostream& os, const TemplArray_16& value) {
        os << "TemplArray_16: ";
        for (int i = 0; i < aSize; i++) os << value.array[i] << " ";
        return os;
    }
    friend std::istream& operator>>(std::istream& is, TemplArray_16& value) {
        std::cout << "Enter values TemplArray_16: ";
        for (int i = 0; i < aSize; i++) is >> value.array[i];
        return is;
    }
private:
    T array[aSize];
};

template<class T> class ObjContainer_16 {
public:
    void add(T* obj) { container.push_back(obj); }
    void f() const { std::cout << "ObjContainer_16::f()." << std::endl; }
    void g() const { std::cout << "ObjContainer_16::g()." << std::endl; }
    class SmartPointer;
    friend class SmartPointer;
    class SmartPointer {
    public:
        SmartPointer(ObjContainer_16& objC) : ocRef(objC), index(0) {}
        bool operator++() {
            if (index >= ocRef.container.size()) return false;
            index++;
            return true;
        }
        bool operator++(int) { return operator++(); }
        bool operator--() {
            if (index <= 0) return false;
            index--;
            return true;
        }
        bool operator--(int) { return operator--(); }
        T* operator->() const { return ocRef.container[index]; }
    private:
        int index;
        ObjContainer_16& ocRef;
    };
private:
    static int i, j;
    std::vector<T*> container;
};

class Object_16_20 {
public:
    virtual ~Object_16_20() {}
};

template<class T> class OStack_16_1 : public Object_16_20, public T {
private:
    struct Link {
        T* data;
        Link* next;
        Link(T* dat, Link* nxt) : data(dat), next(nxt) {}
    }* head;
public:
    OStack_16_1() : head(0) {}
    ~OStack_16_1() { while(head) delete pop(); }
    void push(T* element) {
        head = new Link(element, head);
    }
    T* peek() const {
        if (head) return head->data; else return NULL;
    }
    T* pop() {
        if (head == 0) return NULL;
        T* result = head->data;
        Link* oldHead = head;
        head = head->next;
        delete oldHead;
        return result;
    }
};

template<class T> class OStack_16_2 : public Object_16_20, public T {
private:
    std::vector<T*> storage;
public:
    OStack_16_2() { storage.clear(); }
    ~OStack_16_2() { while (!storage.empty()) delete pop(); }
    void push(T* element) {
        storage.push_back(element);
    }
    T* peek() const {
        if (!storage.empty()) return storage[storage.size()-1]; else return NULL;
    }
    T* pop() {
        if (storage.empty()) return NULL;
        T* result = storage[storage.size()-1];
        storage.pop_back();
        return result;
    }
};

class StringVector : public std::vector<void*> {
public:
    StringVector() { std::vector<void*>::clear(); }
    void push_back(const std::string* element) { std::vector<void*>::push_back((void*)element); }
    std::string* operator[](int index) {
        if (index < 0 || index >= std::vector<void*>::size()) return NULL;
        return (std::string*)std::vector<void*>::operator [](index);
    }
};

template<class T> class TemplVector : public std::vector<void*> {
public:
    TemplVector() { std::vector<void*>::clear(); }
    void push_back(const T* element) { std::vector<void*>::push_back((void*)element); }
    T* operator[](int index) {
        if (index < 0 || index >= std::vector<void*>::size()) return NULL;
        return (T*)std::vector<void*>::operator [](index);
    }
};

template<class T> class Stack_16 {
private:
    struct Link {
        T* data;
        Link* next;
        bool isOwn;
        Link(T* dat, Link* nxt, bool isOwned) : data(dat), next(nxt), isOwn(isOwned) {}
    }* head;
public:
    Stack_16() : head(0) {}
    ~Stack_16() {
        while (head)
            if (head->isOwn) delete pop();
    }
    void push(T* dat, bool isOwned) { head = new Link(dat, head, isOwned); }
    T* peek() const { if (head) return head->data; else return 0; }
    T* pop() {
        if (head == 0) return NULL;
        T* result = head->data;
        Link* oldHead = head;
        head = head->next;
        if (oldHead->isOwn) {
            delete oldHead;
            std::cout << " [object destroid] ";
        }
        return result;
    }
    class iterator;
    friend class iterator;
    class iterator {
    public:
        iterator(const Stack_16& st) : stackPtr(st.head) {}
        iterator(const iterator& it) : stackPtr(it.stackPtr) {}
        iterator() : stackPtr(0) {}
        bool operator++() {
            if (stackPtr->next) stackPtr = stackPtr->next; else stackPtr = 0;
            return bool(stackPtr);
        }
        bool operator++(int) { return operator++(); }
        T* current() const {
            if (!stackPtr) return NULL;
            return stackPtr->data;
        }
        T* operator->() const {
            if (!stackPtr) return NULL;
            return current();
        }
        T* operator*() const { return current(); }
        operator bool() const { return bool(stackPtr); }
        bool operator==(const iterator&) const { return (stackPtr == 0); }
        bool operator!=(const iterator&) const { return (stackPtr != 0); }
    private:
        Stack_16::Link* stackPtr;
    };
    iterator begin() const { return iterator(*this); }
    iterator end() const { return iterator(); }
};

template<typename T> class Cat {
public:
    T run() const {
        std::cout << "run\n";
        return T();
    }
    T eat(T i) const {
        std::cout << "eat\n";
        return i;
    }
    T sleep(T i, T j) const {
        std::cout << "sleep\n";
        return i;
    }
    typedef T (Cat<T>::*PointerMember_1)() const;
    typedef T (Cat<T>::*PointerMember_2)(T) const;
    typedef T (Cat<T>::*PointerMember_3)(T, T) const;
    class FunctionObject {
    public:
        FunctionObject (Cat* cPtr, PointerMember_1 pm) : ptr(cPtr), pmem_1(pm) {
            std::cout << "Function object constructor with PointerMember_1.\n";
        }
        FunctionObject (Cat* cPtr, PointerMember_2 pm) : ptr(cPtr), pmem_2(pm) {
            std::cout << "Function object constructor with PointerMember_2.\n";
        }
        FunctionObject (Cat* cPtr, PointerMember_3 pm) : ptr(cPtr), pmem_3(pm) {
            std::cout << "Function object constructor with PointerMember_3.\n";
        }
        T operator()() const {
            std::cout << "FunctionObject::operator()\n";
            return (ptr->*pmem_1)();
        }
        T operator()(T i) const {
            std::cout << "FunctionObject::operator()\n";
            return (ptr->*pmem_2)(i);
        }
        T operator()(T i, T j) const {
            std::cout << "FunctionObject::operator()\n";
            return (ptr->*pmem_3)(i, j);
        }
    private:
        Cat* ptr;
        PointerMember_1 pmem_1;
        PointerMember_2 pmem_2;
        PointerMember_3 pmem_3;
    };
    Cat<T>::FunctionObject operator->*(PointerMember_1 pm) {
        std::cout << "Cat::operator->*.\n";
        return FunctionObject(this, pm);
    }
    Cat<T>::FunctionObject operator->*(PointerMember_2 pm) {
        std::cout << "Cat::operator->*.\n";
        return FunctionObject(this, pm);
    }
    Cat<T>::FunctionObject operator->*(PointerMember_3 pm) {
        std::cout << "Cat::operator->*.\n";
        return FunctionObject(this, pm);
    }
};

#endif
