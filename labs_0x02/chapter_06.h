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
#include <functional>

clock_t function_6_1();

void multipliers(int n, std::vector<int>& m);

void textToWords(std::string text, std::vector<std::string>& words);

char to_Upper(char c);

char to_Lower(char c);

std::string to_string(int i);

int factorial();

double function_6_15(double x);

double *function_6_15_1();

bool function_6_20(const std::vector<std::string>& v1, const std::vector<std::string>& v2);

int function_6_23_1();

bool function_6_23_2(int value);

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

class Class_6_15 {
public:
    Class_6_15();
    double getRadian();
};

class Class_6_25 {
public:
    Class_6_25();
    int age, year;
    static bool isFirstPart(const Class_6_25& value);
    static bool isLess(const Class_6_25& left, const Class_6_25& right);
};



class Town {
public:
    enum weather { rainy, snowy, cloudy, clear };
    Town();
    friend std::ostream& operator<<(std::ostream& os, const Town& value);
    static Town& populationGrowth(Town& value);
    static bool isLess(const Town& left, const Town& right);
    static bool isEqual(const Town& value);
    static bool isNear(const Town& prev, const Town& elem);
    bool operator<(const Town& value) const;
private:
    static int counter;
    std::string name;
    static std::vector<std::string> weatherNames;
    int population;
    int height;
    weather wt;
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

class Class_6_13_1 {
private:
    char item;
    int quantity, value;
public:
    Class_6_13_1(char i, int q, int v);
    char getItem() const;
    int getQuantity() const;
    void setQuantity(int q);
    int getValue() const;
    void setValue(int v);
    friend std::ostream& operator<<(std::ostream& os, const Class_6_13_1& value);
};

Class_6_13_1 genValues();

class Class_6_13_2 {
private:
    int quantity, value;
public:
    Class_6_13_2();
    void operator()(const Class_6_13_1& cl);
    friend std::ostream& operator<<(std::ostream& os, const Class_6_13_2 value);
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

template<typename F1, typename F2>
class UnaryComp : public std::unary_function<typename F2::argument_type, typename F1::result_type> {
private:
    F1 f1;
    F2 f2;
public:
    UnaryComp(F1 fFirst, F2 fSecond) : f1(fFirst), f2(fSecond) {}
    typename F1::result_type operator()(typename F2::argument_type a) { return f1(f2(a)); }
};

template<typename F1, typename F2>
UnaryComp<F1,F2> compose (F1 fFirst, F2 fSecond) { return UnaryComp<F1,F2>(fFirst, fSecond); }

template<typename _InputIterator, typename _OutputIterator, typename _UnaryOperation, typename __ValueToReplace>
_OutputIterator transform_if(_InputIterator __first, _InputIterator __last, _OutputIterator __result, _UnaryOperation __unary_op, __ValueToReplace __value)
{
    // concept requirements
    __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)
            __glibcxx_function_requires(_OutputIteratorConcept<_OutputIterator,
                                        // "the type returned by a _UnaryOperation"
                                        __typeof__(__unary_op(*__first))>)
            __glibcxx_requires_valid_range(__first, __last);

    for (; __first != __last; ++__first, ++__result)
        if (__unary_op(*__first))
            *__result = __value;
        else
            *__result = __unary_op(*__first);
    return __result;
}

template<typename _InputIterator, typename _OutputIterator, typename _BinaryOperation>
_OutputIterator for_each_alt(_InputIterator __first_1, _InputIterator __last_1, _InputIterator __first_2, _OutputIterator __result, _BinaryOperation __f)
{
    // concept requirements
    __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)
            __glibcxx_requires_valid_range(__first, __last);
    for (; __first_1 != __last_1; ++__first_1, ++__first_2, ++__result)
        *__result = __f(*__first_1, *__first_2);
    return __result;
}

template<class T>
class Matrix {
public:
    explicit Matrix(const int rows, const int columns, int gen = 0) {
        data.resize(rows);
        for (int i = 0; i < data.size(); i++) {
            data[i].resize(columns);
            std::fill_n(data[i].begin(), columns, gen++);
        }

    }

    Matrix& operator=(const Matrix& rValue) {
        if (data.empty() || rValue.data.empty() || rValue.data.size() != data.size() || rValue.data[0].size() != data[0].size())
            return *this;
        for (int i = 0; i < data.size(); i++)
            for (int j = 0; j < data[i].size(); j++)
                data[i][j] = rValue.data[i][j];
        return *this;
    }

    const Matrix operator+(const Matrix& rValue) {
        if (data.empty() || rValue.data.empty() || rValue.data.size() != data.size() || rValue.data[0].size() != data[0].size())
            return *this;
        Matrix result(data.size(), data[0].size());
        for (int i = 0; i < data.size(); i++)
            for (int j = 0; j < rValue.data.size(); j++)
                result.data[i][j] = data[i][j] + rValue.data[i][j];
        return result;
    }

    const Matrix operator*(const Matrix& rValue) {
        if (data.empty() || rValue.data.empty() || rValue.data.size() != data[0].size()) {
            std::cout << "Matrix sizes mismatch.\n";
            return *this;
        }
        Matrix result(data.size(), rValue.data[0].size());
        for (int i = 0; i < data.size(); i++)
            for (int j = 0; j < rValue.data[0].size(); j++) {
                T element = 0;
                for (int k = 0; k < data[0].size(); k++)
                    element += data[i][k] * rValue.data[k][j];
                result.data[i][j] = element;
            }
        return result;
    }

    const Matrix operator*(const std::vector<T>& rValue) {
        if (data.empty() || rValue.empty() || rValue.size() != data[0].size())
            return *this;
        Matrix rOperand(data[0].size(), 1), result(data.size(), 1);
        for (int i = 0; i < data.size(); i++)
            rOperand.data[i][0] = rValue[i];
        result = (*this) * (rOperand);
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& value);
private:
    std::vector<std::vector<T> > data;
};



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
