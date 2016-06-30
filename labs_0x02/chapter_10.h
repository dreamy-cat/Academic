#ifndef L_02_CHAPTER_10_H
#define L_02_CHAPTER_10_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <map>
#include <typeinfo>

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
protected:
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

class Class_10_7 {
private:
    Class_10_6& base;
public:
    Class_10_7(Class_10_6& iBase);
    void toUpperCase();
    void searchWords();
};

class Class_10_8 {
public:
    virtual bool function() = 0;
};

class Class_10_8_1 : public Class_10_8 {
public:
    bool function();
};

class Class_10_8_2 : public Class_10_8 {
public:
    bool function();
};

class Class_10_8_3 : public Class_10_8 {
public:
    bool function();
};

class Class_10_8_4 {
private:
    int state;
    std::vector<Class_10_8*> base;
public:
    Class_10_8_4(std::vector<Class_10_8*> iBase);
    void function();
};

class ShapeF1 {
public:
    virtual void draw() = 0;
    virtual void erase() = 0;
    virtual ~ShapeF1();
    class Error : public std::logic_error {
    public:
        Error(std::string type);
    };
    static ShapeF1* factory(const std::string type) throw (Error);
};

class CircleF1 : public ShapeF1 {
public:
    void draw();
    void erase();
    ~CircleF1();
private:
    CircleF1();
    friend class ShapeF1;
};

class SquareF1 : public ShapeF1 {
public:
    void draw();
    void erase();
    ~SquareF1();
private:
    SquareF1();
    friend class ShapeF1;
};

class TriangleF1 : public ShapeF1 {
public:
    void draw();
    void erase();
    ~TriangleF1();
private:
    TriangleF1();
    friend class ShapeF1;
};

class ShapeF2 {
public:
    virtual void draw() = 0;
    virtual void erase() = 0;
    virtual ~ShapeF2();
};

class FactoryShapeF2 {
protected:
    static std::map<std::string, FactoryShapeF2*> factories;
public:
    FactoryShapeF2();
    virtual ShapeF2* createThin() = 0;
    virtual ShapeF2* createBold() = 0;
    virtual ~FactoryShapeF2();
    friend class FactoryShapeF2Init;
    class Error : public std::logic_error {
    public:
        Error(std::string type);
    };
    static ShapeF2* factory(const std::string& id, bool isBold) throw (Error);
};

class CircleF2 : public ShapeF2 {
private:
    CircleF2(bool isBold);
    friend class FactoryShapeF2Init;
    class Factory;
    class Factory : public FactoryShapeF2 {
    public:
        ShapeF2* createThin();
        ShapeF2* createBold();
        friend class FactoryShapeF2Init;
    };
public:
    void draw();
    void erase();
    ~CircleF2();
};

class SquareF2 : public ShapeF2 {
private:
    SquareF2(bool isBold);
    friend class FactoryShapeF2Init;
    class Factory;
    class Factory : public FactoryShapeF2 {
    public:
        ShapeF2* createThin();
        ShapeF2* createBold();
        friend class FactoryShapeF2;
    };
public:
    void draw();
    void erase();
    ~SquareF2();
};

class TriangleF2 : public ShapeF2 {
private:
    TriangleF2(bool isBold);
    friend class FactoryShapeF2Init;
    class Factory;
    class Factory : public FactoryShapeF2 {
    public:
        ShapeF2* createThin();
        ShapeF2* createBold();
        friend class FactoryShapeF2;
    };
public:
    void draw();
    void erase();
    ~TriangleF2();
};

class FactoryShapeF2Init {
private:
    static FactoryShapeF2Init factoryInit;
    FactoryShapeF2Init();
    ~FactoryShapeF2Init();
};

class Material {
public:
    virtual void action() = 0;
};

class Worker {
public:
    virtual void interactWith(Material*) = 0;
};

class Worker_1 : public Worker {
    virtual void interactWith(Material* obj);
};

class Worker_2 : public Worker {
    virtual void interactWith(Material* obj);
};

class Worker_3 : public Worker {
    virtual void interactWith(Material* obj);
};

class Brick : public Material {
public:
    void action();
};

class Wood : public Material {
public:
    void action();
};

class Steel : public Material {
public:
    void action();
};

class WorkFactory {
public:
    virtual Worker* makeWorker() = 0;
    virtual Material* makeMaterial() = 0;
};

class Worker_1_Wood : public WorkFactory {
public:
    virtual Worker* makeWorker();
    virtual Material* makeMaterial();
};

class Worker_2_Brick : public WorkFactory {
public:
    virtual Worker* makeWorker();
    virtual Material* makeMaterial();
};

class Worker_3_Steel : public WorkFactory {
public:
    virtual Worker* makeWorker();
    virtual Material* makeMaterial();
};

class WorkSet {
private:
    WorkFactory* factory;
    Worker* worker;
    Material* obj;
public:
    WorkSet(WorkFactory* fcy);
    void play();
    ~WorkSet();
};

class ShapeV {
private:
    ShapeV* shape;
    static std::map<std::string, ShapeV*> shapesV;
    ShapeV(ShapeV&);
    ShapeV operator=(ShapeV&);
protected:
    ShapeV();
public:
    virtual void draw();
    virtual void erase();
    virtual void test();
    virtual ~ShapeV();
    class Error : public std::logic_error {
    public:
        Error(std::string type);
    };
    ShapeV(std::string type) throw(Error);
};

class CircleV : public ShapeV {
private:
    CircleV();
    CircleV(CircleV&);
    CircleV operator=(CircleV&);
    friend class ShapeV;
public:
    void draw();
    void erase();
    void test();
    ~CircleV();
};

class SquareV : public ShapeV {
private:
    SquareV();
    SquareV(SquareV&);
    SquareV operator=(SquareV&);
    friend class ShapeV;
public:
    void draw();
    void erase();
    void test();
    ~SquareV();
};


#endif
