#ifndef L_02_CHAPTER_06_H
#define L_02_CHAPTER_06_H

#include <ctime>
#include <list>
#include <vector>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <iterator>
#include <algorithm>

clock_t function_6_1();

void multipliers(int n, std::vector<int>& m);

void textToWords(std::string text, std::vector<std::string>& words);

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

struct BRand {
    bool operator()();
};

template<typename Contain, typename UnaryFunc>
void testUnary(Contain& source, Contain& destination, UnaryFunc f) {
    transform(source.begin(), source.end(), destination.begin(), f);
}

template<typename Contain_1, typename Contain_2, typename BinaryFunc>
void testBinary(Contain_1& source_1, Contain_2& source_2, Contain_2& destination, BinaryFunc f) {
    transform(source_1.begin(), source_1.end(), source_2.begin(), destination.begin(), f);
}

template<typename T>
void function_6_2() {
    const int sizeV = 5, max = 10;
    std::vector<T> vector_1(sizeV), vector_2(sizeV), vector_3(sizeV);
    Generator_2 gen_2(max);
    srand(0);
    std::generate_n(vector_1.begin(), sizeV, gen_2);
    std::generate_n(vector_2.begin(), sizeV, gen_2);
    std::transform(vector_2.begin(), vector_2.end(), vector_2.begin(), std::bind2nd(std::plus<T>(), 1));
    vector_1[0] = vector_2[0];
    printInterval(vector_1.begin(), vector_1.end(), "Vector_1", " ");
    printInterval(vector_2.begin(), vector_2.end(), "Vector_2", " ");
    testBinary(vector_1, vector_2, vector_3, std::plus<T>());
    printInterval(vector_3.begin(), vector_3.end(), "Vector_3 result of 'plus'", " ");
    testBinary(vector_1, vector_2, vector_3, std::minus<T>());
    printInterval(vector_3.begin(), vector_3.end(), "Vector_3 result of 'minus'", " ");
    testBinary(vector_1, vector_2, vector_3, std::multiplies<T>());
    printInterval(vector_3.begin(), vector_3.end(), "Vector_3 result of 'multiplies'", " ");
    testBinary(vector_1, vector_2, vector_3, std::divides<T>());
    printInterval(vector_3.begin(), vector_3.end(), "Vector_3 result of 'divides'", " ");
    /*
    testBinary(vector_1, vector_2, vector_3, std::modulus<T>());
    printInterval(vector_3.begin(), vector_3.end(), "Vector_3 result of 'modulus'", " ");
    */
    testBinary(vector_1, vector_2, vector_3, std::equal_to<T>());
    printInterval(vector_3.begin(), vector_3.end(), "Vector_3 result of 'equal_to'", " ");
    testBinary(vector_1, vector_2, vector_3, std::not_equal_to<T>());
    printInterval(vector_3.begin(), vector_3.end(), "Vector_3 result of 'not_equal_to'", " ");
    testBinary(vector_1, vector_2, vector_3, std::greater<T>());
    printInterval(vector_3.begin(), vector_3.end(), "Vector_3 result of 'greater'", " ");
    testBinary(vector_1, vector_2, vector_3, std::less<T>());
    printInterval(vector_3.begin(), vector_3.end(), "Vector_3 result of 'less'", " ");
    testBinary(vector_1, vector_2, vector_3, std::greater_equal<T>());
    printInterval(vector_3.begin(), vector_3.end(), "Vector_3 result of 'greater_equal'", " ");
    testBinary(vector_1, vector_2, vector_3, std::less_equal<T>());
    printInterval(vector_3.begin(), vector_3.end(), "Vector_3 result of 'less_equal'", " ");
    testBinary(vector_1, vector_2, vector_3, std::not2(std::greater_equal<T>()));
    printInterval(vector_3.begin(), vector_3.end(), "Vector_3 result of 'greater'", " ");
    testBinary(vector_1, vector_2, vector_3, std::not2(std::less_equal<T>()));
    printInterval(vector_3.begin(), vector_3.end(), "Vector_3 result of 'less'", " ");
    std::vector<bool> vector_4(sizeV), vector_5(sizeV), vector_6(sizeV);
    std::generate_n(vector_4.begin(), sizeV, BRand());
    std::generate_n(vector_5.begin(), sizeV, BRand());
    printInterval(vector_4.begin(), vector_4.end(), "Vector_4", " ");
    printInterval(vector_5.begin(), vector_5.end(), "Vector_5", " ");
    testBinary(vector_4, vector_5, vector_6, std::logical_and<T>());
    printInterval(vector_6.begin(), vector_6.end(), "Vector 6, result of 'logical_and'", " ");
    testBinary(vector_4, vector_5, vector_6, std::logical_or<T>());
    printInterval(vector_6.begin(), vector_6.end(), "Vector 6, result of 'logical_or'", " ");
    testUnary(vector_4, vector_6, std::logical_not<T>());
    printInterval(vector_6.begin(), vector_6.end(), "Vector 6, result of 'logical_not'", " ");
    testUnary(vector_4, vector_6, std::not1(std::logical_not<T>()));
    printInterval(vector_6.begin(), vector_6.end(), "Vector 6, result of 'not1(logical_not)'", " ");
}

#endif
