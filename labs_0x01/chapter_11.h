#ifndef CHAPTER_11_H
#define ChAPTER_11_H

int& function_11_4(int& i);

class Class_11_5 {
public:
    Class_11_5();
    void function_1 ();
    void function_2 () const;
};

void function_11_5(Class_11_5& clPtr);

void function_11_6(int*& iRef);

void function_11_7(int**& iRef);

void function_11_8(char& cRef);

class Class_11_9 {
public:
    Class_11_9();
    void function_1();
    void function_2() const;
};

void function_11_9_1(Class_11_9 cl);

void function_11_9_2(Class_11_9& cl);

void function_11_9_3(const Class_11_9& cl);

int function_11_10(int i);

void function_11_11(char c, int i, float f, double d);

double function_11_12(double d);

struct Structure_13 {
    char buf[32];
    int i;
    long l;
};

Structure_13 function_11_13(Structure_13 st);

#endif
