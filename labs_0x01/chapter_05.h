#ifndef CHAPTER_05_H
#define CHAPTER_05_H

#include <string>

class Class_5_1 {
public:
    int a;
    void f1();
protected:
    int b;
    void f2();
private:
    int c;
    void f3();
};

struct Structure_5_1 {
    std::string a, b, c;
    std::string s[3];
};

class Class_5_1_2 {
public:
    void setString(std::string str, int index);
    std::string getString (int index);
private:
    std::string s[3];
};

class Class_5_3 {
    friend void function_5_3(Class_5_3* clPtr);
private:
    int a;
};

class Class_5_4_2;

class Class_5_4_1 {
public:
    void f(Class_5_4_2* ptr);
};

class Class_5_4_2 {
public:
    void f(Class_5_4_1* ptr);
};

class Class_5_5_1;

class Class_5_5_3 {
public:
    void f(Class_5_5_1 *ptr);
};

class Class_5_5_1 {
    friend class Class_5_5_2;
    friend void Class_5_5_3::f(Class_5_5_1 *ptr);
private:
    int a;
};

class Class_5_5_2 {
public:
    void printA(Class_5_5_1 *ptr);
};

class Class_5_6_1;
class Class_5_6_2;
class Class_5_6_3;

class Class_5_6_1 {
public:
    void display();
    class Class_5_6_2 {
        friend class Class_5_6_1;
    public:
        void display();
        class Class_5_6_3 {
            friend class Class_5_6_2;
        public:
            void display();
        private:
            static const char b = 'b';
        } cl;
    private:
        static const char a = 'a';
    } cl;
};

class Class_5_8 {
public:
    void showMap();
    int a;
protected:
    int b;
private:
    int c;
};

#endif
