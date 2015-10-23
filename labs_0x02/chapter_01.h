#ifndef CHAPTER_01_H
#define CHAPTER_01_H

int function_01_1();
void function_01_2();
void function_01_3(int sig);
void function_01_4();

class Class_01_1 {
public:
    class Class_1 {
    public:
        Class_1(const char* s) : str(s) {}
        const char* str;
    };
    void function_1() throw(Class_1);
};

#endif
