#ifndef PART_18
#define PART_18

#include <string>
#include <iostream>
#include <cassert>
#include <typeinfo>
#include <stdexcept>
#include <vector>
#include <cstdlib>

class Rational {
public:
    Rational (int numerator = 1, int denumerator = 1);
    Rational(const Rational& r);
    const Rational& operator=(const Rational& right);
    ~Rational();
    friend const Rational operator+(const Rational& left, const Rational& right);
    friend const Rational operator-(const Rational& left, const Rational& right);
    friend const Rational operator*(const Rational& left, const Rational& right);
    friend const Rational operator/(const Rational& left, const Rational& right);
    friend std::ostream& operator<<(std::ostream& os, const Rational& value);
    friend Rational& operator+=(Rational& left, const Rational& right);
    friend Rational& operator-=(Rational& left, const Rational& right);
    friend Rational& operator*=(Rational& left, const Rational& right);
    friend Rational& operator/=(Rational& left, const Rational& right);
    friend bool operator<(const Rational& left, const Rational& right);
    friend bool operator>(const Rational& left, const Rational& right);
    friend bool operator<=(const Rational& left, const Rational& right);
    friend bool operator>=(const Rational& left, const Rational& right);
    friend bool operator==(const Rational& left, const Rational& right);
    friend bool operator!=(const Rational& left, const Rational& right);
    static int lcm_gcd(int x, int y, int type);
private:
    int numerator, denumerator;
};

namespace TestKit {

class Test {
public:
    Test(std::ostream* osPtr = &std::cout);
    virtual ~Test();
    virtual void run() = 0;
    long getNumPassed() const;
    long getNumFailed() const;
    const std::ostream* getStream() const;
    void setStream(std::ostream* osPtr);
    void succeed_();
    long report() const;
    virtual void reset();
protected:
    void doTest(bool condition, const std::string& label, const char *fName, long line);
    void doFail(const std::string& label, const char *fName, long line);
private:
    std::ostream *os;
    long nPass, nFail;
    Test(const Test&);
    Test& operator=(const Test&);
};

class VectorTest : public Test {
public:
    VectorTest();
    void run();
private:
    std::vector<int> v;
};

class RationalTest : public Test {
public:
    RationalTest();
    void run();
private:
    Rational result, leftValue, rightValue;
};

class TestSearch : public Test {
public:
    TestSearch();
    int binSearch(int x);
    void run();
private:
    static const int size = 8;
    int v[size];
    int max, current;
    void setData();
};

class KitError : public std::logic_error {
public:
    KitError(const std::string& s = "");
};

class Kit {
public:
    Kit(const std::string& name, std::ostream* osPtr = &std::cout);
    std::string getName() const;
    long getNumPassed() const;
    long getNumFailed() const;
    const std::ostream* getStream() const;
    void setStream(std::ostream* osPtr);
    void addTest(Test* t) throw (KitError);
    void addKit(const Kit&k);
    void run();
    long report() const;
    void free();
private:
    std::string name;
    std::ostream* os;
    std::vector<Test*> tests;
    void reset();
    Kit(const Kit&);
    Kit& operator=(const Kit&);
};

}   // namespace TestKit

#endif
