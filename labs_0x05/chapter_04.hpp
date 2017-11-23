#ifndef LAB_05_CHAPTER_04_H
#define LAB_05_CHAPTER_04_H

#include <iostream>
#include <list>

// Task 4.1-4.3. Complete types are 1,2,4. Others only needs declaration.

class Base_4_1 {};
class Base_4_2 {};
class Base_4_3;
class Base_4_4 {};
class Base_4_5;

class Derived_4_1 : public Base_4_1, private Base_4_2 {
public:
    Derived_4_1(const Base_4_3&);
    Base_4_2 function_1 (int, char);
    Base_4_3 function_1 (int, Base_4_3);
    Base_4_3& function_2 (Base_4_2);
    Base_4_5 function_3 (Base_4_5);
    virtual std::ostream& print(std::ostream& ) const;
private:
    struct DerivedImpl {
        std::list<Base_4_3> lst;
        Base_4_4 obj;
    };
    DerivedImpl* ptr;

};

inline std::ostream& operator<<(std::ostream& os, const Derived_4_1& value) { return value.print(os); }

// Task 4.5.

class Base_4_3 {
public:
    Base_4_3();
    ~Base_4_3();
    Base_4_5* objPtr;
};

class Base_4_5 {};

class Class_4_5A {
public:
    Class_4_5A();
    ~Class_4_5A();
};

class Class_4_5B {
public:
    Class_4_5B();
    ~Class_4_5B();
    static const size_t sx = 1;
    char obj[sx];
};

#endif
