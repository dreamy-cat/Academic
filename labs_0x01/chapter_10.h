#ifndef CHAPTER_10_H
#define CHAPTER_10_H

#include <iostream>

int function_10_1 (int init[] = 0);
int numberFibbonaci(bool reset = false);

class Class_10_3 {
public:
    Class_10_3(int iVar) : var(iVar) {
        for (int i = 0; i < size; i++) array[i] = i;
    }
    static void printVar2() { std::cout << "Var2 = " << var2; }
    void print() {
        std::cout << "Class_10_3, array : ";
        for (int i = 0; i < size; i++) std::cout << array[i] << " ";
        printVar2();
        std::cout << std::endl;
    }
private:
    static const int size = 5;
    int array[size];
    const int var;
    static int var2;
};

class Class_10_4 {
public:
    Class_10_4 ();
    void count ();
    void print ();
    void decrement();
private:
    static int counter;
};

void function_10_4 ();

class Class_10_5 {
public:
    Class_10_5(Class_10_4* ptr);
    ~Class_10_5();
private:
    Class_10_4* clPtr;
};

void function_10_5 (Class_10_4* ptr);

class Class_10_8 {
public:
    Class_10_8(char cc);
    ~Class_10_8();
private:
    char c;
};

void function_10_8_2();

void function_10_8_1();

class Class_10_11 {
public:
    Class_10_11 (int ii);
    void print ();
private:
    int i;
};

void function_10_13 ();

// Task 13. Undefined reference.
// static void function_10_13 ();

class Class_10_14 {
public:
    Class_10_14();
    // void isr() volatile;
    static void isr();
    char read (int index) const;
private:
    static const unsigned char byte;
    static unsigned char flag;
    enum { bufsize = 100 };
    static unsigned char buf[bufsize];
    static int index;
};

namespace NameSpace_16_1 {
    void function_16_1 ();
    void function_16_2 ();
}

namespace NameSpace_16_2 {
    using namespace NameSpace_16_1;
    void function_16_3();
    void function_16_4();
}

namespace {
    void function_10_17() {
        std::cout << "Function_10_17. Anonymous namespace." << std::endl;
    }
}

void function_10_18 ();

namespace NameSpace_10_19 {
    class Class_10_19 {
    public:
        friend void function_10_19();
    };
}

void function_10_19();

namespace NameSpace_10_20_1 {
    enum sign { positive, negative };
    class Integer {
        int i;
        sign s;
    public:
        Integer(int ii) : i(ii), s(i >= 0 ? positive : negative) {}
        sign getSign() const { return s; }
        void setSign(sign sgn) { s = sgn; }
    };
}

void arithmetic();

namespace NameSpace_10_22_1 {
    class Class_10_22 {
    public:
        Class_10_22() { std::cout << "First namespace. Class_10_22 constructor." << std::endl; }
    };
}

namespace NameSpace_10_22_2 {
class Class_10_22 {
public:
    Class_10_22() { std::cout << "Second namespace. Class_10_22 constructor." << std::endl; }
};
}

namespace NameSpace_10_24_1 {
    class Class_10_24_1 {

    };
    class Class_10_24_2 {

    };
}

namespace NameSpace_10_24_2 {
    class Class_10_24_3 {

    };
    class Class_10_24_4 {

    };
    class Class_10_24_5 {

    };
    class Class_10_24_6 {
    public:
        Class_10_24_3 c3[3];
        Class_10_24_4 c4[4];
        Class_10_24_5 c5[5];
        int integer_24_1, integer_24_2, integer_24_3;
    };
}

namespace NameSpace_10_24_3 {
    using namespace NameSpace_10_24_1;
    using namespace NameSpace_10_24_2;
}

class Class_10_25 {
public:
    Class_10_25(std::string iStr) : str(iStr) {}
    void print() { std::cout << "String parameter, Class_10_25 = " << str << std::endl; }
private:
    std::string str;
};

class Class_10_26 {
public:
    Class_10_26();
    void print();
private:
    static long longP;
    static double doubleP;
};

class Class_10_27_1 {
public:
    Class_10_27_1(int ii) : i(ii) {}
    void print () { std::cout << "Class_10_27_1, integer = " << i; }
private:
    int i;
};

class Class_10_27_2 {
public:
    Class_10_27_2();
    static void function_1();
private:
    static Class_10_27_1 cl;
};

class Class_10_28 {
public:
    Class_10_28(const int* aPtr);
    static void function_1();
private:
    int ar1[3];
    const int* ar2;
};

class Class_10_29_1 {
public:
    Class_10_29_1 (std::string init);
    void print() const;
private:
    std::string str;
};

class Class_10_29_2 {
public:
    Class_10_29_2();
    static void printArray();
private:
    static Class_10_29_1 ar1[3];
    static const Class_10_29_1 ar2[3];
};

class Class_10_31 {
public:
    Class_10_31(int ii) : i(ii) {}
    static Class_10_31* instance() { return &inst; }
    int value() { return i; }
private:
    Class_10_31(const Class_10_31&);
    static Class_10_31 inst;
    int i;
};

#endif // CHAPTER_10_H
