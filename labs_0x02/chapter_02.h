#ifndef L_02_CHAPTER_02_H
#define L_02_CHAPTER_02_H

#include <string>
#include <iostream>
#include <cassert>
#include <typeinfo>
#include <stdexcept>
#include <vector>

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

class Rational {
public:
    Rational (int numerator, int denumerator);
    ~Rational();
    friend const Rational operator+(const Rational& left, const Rational& right);
    friend const Rational operator-(const Rational& left, const Rational& right);
    friend const Rational operator*(const Rational& left, const Rational& right);
    friend const Rational operator/(const Rational& left, const Rational& right);
    friend std::ostream& operator<<(std::ostream& os, const Rational& value);
    Rational& operator+=(const Rational& value);
    Rational& operator-=(const Rational& value);
    Rational& operator*=(const Rational& value);
    Rational& operator/=(const Rational& value);
    friend bool operator<(const Rational& left, const Rational& right);
    friend bool operator>(const Rational& left, const Rational& right);
    friend bool operator<=(const Rational& left, const Rational& right);
    friend bool operator>=(const Rational& left, const Rational& right);
    friend bool operator==(const Rational& left, const Rational& right);
    friend bool operator!=(const Rational& left, const Rational& right);
    int lcm_gcd(int x, int y, int type);
    Rational(const Rational& r);
    int numerator, denumerator;

private:

};

Rational f_1(Rational r);

#endif
