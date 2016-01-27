#ifndef L_02_CHAPTER_06_H
#define L_02_CHAPTER_06_H

#include <ctime>
#include <list>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <iterator>
#include <algorithm>

clock_t function_6_1();

char to_Upper(char c);

class Class_6_1 {
public:
    Class_6_1(int init);
    int operator()(int n);
    static int sum;
};

class Class_6_2 {
public:
    virtual void function_1();
};

class Class_6_2_1 : public Class_6_2 {
public:
    void function_1();
};

class Generator_1 {
private:
    int i, sk;
public:
    Generator_1(int start = 0, int skip = 1);
    int operator()();
};

class Generator_2 {
private:
    std::set<int> used;
    int limit;
public:
    Generator_2(int lim);
    int operator()();
};

class Generator_3 {
private:
    static const char* source;
    static const int len;
public:
    char operator()();
};

template<typename Iter>
void printInterval(Iter first, Iter last, const char* msg, const char* separator, std::ostream& os = std::cout) {
    if (msg != 0 && *msg != '\0') os << msg << ": " << separator;
    typedef typename std::iterator_traits<Iter>::value_type T;
    std::copy(first, last, std::ostream_iterator<T>(std::cout, separator));
    os << std::endl;
}

// Test more...

template<typename Contain, typename UnaryFunc>
void testUnary(Contain& source, Contain& destination, UnaryFunc f) {
    transform(source.begin(), source.end(), destination.begin(), f);
}

template<typename Contain_1, typename Contain_2, typename BinaryFunc>
void testBinary(Contain_1& source_1, Contain_2& source_2, Contain_2& destination, BinaryFunc f) {
    transform(source_1.begin(), source_1.end(), source_2.begin(), destination.begin(), f);
}

#endif
