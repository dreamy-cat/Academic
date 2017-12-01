#ifndef LABS_0x05_CHAPTER_05_H
#define LABS_0x05_CHAPTER_05_H

#include <iostream>
#include <numeric>

namespace NameSpace_A {

struct Struct_1 {
    char c;
};

struct Struct_2 {
    char c;
};

void function_1(int);

void function_2(Struct_1);

}

namespace NameSpace_B {

void function_1(int i);

void function_2(NameSpace_A::Struct_1 st);

void function_3(NameSpace_A::Struct_2 st);

}

namespace NameSpace_C {

class Class_5_1 {
public:
    Class_5_1(const char* name, const char* mode);
    ~Class_5_1();
    int seek(long offset, int origin);
    long tell();
    virtual std::ostream& print(std::ostream&) const;
private:
    void function_1() const;
    void function_5_1(const NameSpace_C::Class_5_1 &value);
};

}

void function_5_1(const NameSpace_C::Class_5_1& value);

std::ostream& operator<<(std::ostream&, NameSpace_C::Class_5_1& value);

namespace NameSpace_D {

void function_5_1(NameSpace_C::Class_5_1& value);

void function_5_2(NameSpace_C::Class_5_1& value);

}

namespace NameSpace_E {

class Class_5_2 {
public:
    Class_5_2();
    int a;
};

int operator+(int i, NameSpace_E::Class_5_2);

}

struct Struct_5A {
    int function_1(int);
    int function_1(double);
    int function_2(int);
};

struct Struct_5B : public Struct_5A {
    using Struct_5A::function_2;
private:
    int function_2(std::string, bool);
};

#endif
