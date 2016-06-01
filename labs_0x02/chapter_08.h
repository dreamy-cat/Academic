#ifndef L_02_CHAPTER_08_H
#define L_02_CHAPTER_08_H

#include <iostream>
#include <set>

class Base {
public:
    Base();
    virtual ~Base();
};

class Derived : public Base {
public:
    Derived();
    ~Derived();
};

class AutoCounter {
public:
    static AutoCounter* create() { return new AutoCounter(); }
    ~AutoCounter() {
        std::cout << "Destroying[" << className << ":" << id << "]" << std::endl;
        verifier.remove(this);
    }
    friend std::ostream& operator<<(std::ostream& os, const AutoCounter& value) { return os << "AutoCounter[" << value.id << "]"; }
    friend std::ostream& operator<<(std::ostream& os, const AutoCounter* value) { return os << "AutoCounter[" << value->id << "]"; }
private:
    static int count;
    int id;
    std::string className;
    AutoCounter() : id(count++) {
        verifier.add(this);
        className = "AutoCounter";
        std::cout << "AutoCounter constructor[" << className << ":" << id << "]" << std::endl;
    }
    AutoCounter(const AutoCounter&);
    void operator=(const AutoCounter&);
    class CleanupCheck {
    public:
        void add(AutoCounter* ap) { trace.insert(ap); }
        void remove(AutoCounter* ap) { trace.erase(ap); }
        ~CleanupCheck() { std::cout << "CleanupCheck destructor, elements in set: " << trace.size() << std::endl; }
    private:
        std::set<AutoCounter*> trace;
    };
    static CleanupCheck verifier;
};

class Class_2 {
public:
    Class_2();
    ~Class_2();
private:
    // AutoCounter debug;
};

#endif
