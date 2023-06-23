#include "chapter_02.h"

using namespace TestKit;
using namespace std;

Test::Test(ostream* osPtr) : os(osPtr), nPass(0), nFail(0) {}

Test::~Test() {}

long Test::getNumPassed() const { return nPass; }

long Test::getNumFailed() const { return nFail; }

const ostream* Test::getStream() const { return os; }

void Test::setStream(ostream* osPtr) { os = osPtr; }

void Test::succeed_() { ++nPass; }

long Test::report() const {
    if (os) *os << "Test: " << typeid(*this).name() << ", passed: " << nPass << ", failed: " << nFail << endl;
    return nFail;
}

void Test::reset() { nPass = nFail = 0; }

void Test::doTest(bool condition, const string& label, const char *fName, long line) {
    if (!condition) doFail(label, fName, line); else succeed_();
}

void Test::doFail(const string& label, const char *fName, long line) {
    ++nFail;
    if (os) *os << typeid(*this).name() << "failure: (" << label << ") . " << fName
                << " (line " << line << ")" << endl;
}

VectorTest::VectorTest() {}

void VectorTest::run() {
    v.push_back(1);
    doTest(!v.empty() && (*v.begin() == 1), "push_back()", "chapter_02.cpp", __LINE__);
    doTest(v.front() == 1, "front()", "chapter_02.cpp", __LINE__);
    doTest(v.back() == 1, "back()", "chapter_02.cpp", __LINE__);
    v.pop_back();
    doTest(v.empty(), "pop_back()", "chapter_02.cpp", __LINE__);
    v.push_back(1);
    doTest(v.at(0) == 1, "at(0)", "chapter_02.cpp", __LINE__);
    int element = v.at(1);      // Throw exception
}

RationalTest::RationalTest() : result(0,1), leftValue(1,2), rightValue(1,4) {}

void RationalTest::run() {
    result = leftValue + rightValue;
    doTest((result == Rational(3,4)), "operator+()", "chapter_02.cpp", __LINE__);
    result = leftValue - rightValue;
    doTest((result == Rational(1,4)), "operator-()", "chapter_02.cpp", __LINE__);
    result = leftValue * rightValue;
    doTest((result == Rational(1,8)), "operator*()", "chapter_02.cpp", __LINE__);
    result = leftValue / rightValue;
    doTest((result == Rational(2,1)), "operator/()", "chapter_02.cpp", __LINE__);
    result = Rational(1, 3);
    doTest((result < Rational(2,3)), "operator<()", "chapter_02.cpp", __LINE__);
    doTest((Rational(2,3) > result), "operator>()", "chapter_02.cpp", __LINE__);
    doTest((result <= Rational(1,3)), "operator<=()", "chapter_02.cpp", __LINE__);
    doTest((result >= Rational(1,3)), "operator>=()", "chapter_02.cpp", __LINE__);
    doTest((result != Rational(2,3)), "operator!=()", "chapter_02.cpp", __LINE__);
    doTest((result == Rational(1,3)), "operator==()", "chapter_02.cpp", __LINE__);
    result = Rational(0, 5);
    result += rightValue;
    doTest((result == Rational(1,4)), "operator+=()", "chapter_02.cpp", __LINE__);
    result *= rightValue;
    doTest((result == Rational(1,16)), "operator*=()", "chapter_02.cpp", __LINE__);
    result /= rightValue;
    doTest((result == Rational(1,4)), "operator/=()", "chapter_02.cpp", __LINE__);
    result -= rightValue;
    doTest((result == Rational(0,1)), "operator-=()", "chapter_02.cpp", __LINE__);
}

KitError::KitError(const std::string& s) : logic_error(s) {}

Kit::Kit(const string& name, ostream* osPtr) : name(name), os(osPtr) {}

string Kit::getName() const { return name; }

long Kit::getNumPassed() const {
    long totPass = 0;
    for (size_t i = 0; i < tests.size(); ++i) {
        assert(tests[i]);
        totPass += tests[i]->getNumPassed();
    }
    return totPass;
}

long Kit::getNumFailed() const {
    long totFail = 0;
    for (size_t i = 0; i < tests.size(); ++i) {
        assert(tests[i]);
        totFail += tests[i]->getNumFailed();
    }
    return totFail;
}

const ostream* Kit::getStream() const { return os; }

void Kit::setStream(ostream* osPtr) { os = osPtr; }

void Kit::addTest(Test* t) throw (KitError) {
    if (t == NULL) throw KitError("Test has a NULL pointer."); else
        if (os && !getStream()) t->setStream(os);
    tests.push_back(t);
    t->reset();
}

void Kit::addKit(const Kit& k) {
    for (size_t i = 0; i < k.tests.size(); ++i) {
        assert(tests[i]);
        addTest(k.tests[i]);
    }
}

void Kit::run() {
    reset();
    for (size_t i = 0; i < tests.size(); ++i) {
        assert(tests[i]);
        tests[i]->run();
    }
}

long Kit::report() const {
    if (os) {
        long totalFail = 0;
        *os << "Kit '" << name << "':";
        size_t i;
        *os << endl;
        for (i = 0; i < tests.size(); ++i) {
            assert(tests[i]);
            totalFail += tests[i]->report();
        }
        return totalFail;
    } else return getNumFailed();
}

void Kit::free() {
    for (size_t i = 0; i < tests.size(); ++i) {
        delete (tests[i]);
        tests[i] = 0;
    }
}

void Kit::reset() {
    for (size_t i = 0; i < tests.size(); ++i) {
        assert(tests[i]);
        tests[i]->reset();
    }
}

Rational::Rational (int numerator, int denumerator) {
    if (denumerator == 0) throw invalid_argument("Division by zero.");
    this->numerator = numerator;
    if (numerator == 0) this->denumerator = 1; else
        this->denumerator = denumerator;
    if (denumerator < 0) {
        this->numerator *= -1;
        this->denumerator *= -1;
    }
}

const Rational& Rational::operator=(const Rational& right) {
    numerator = right.numerator;
    denumerator = right.denumerator;
    return *this;
}

Rational::~Rational() {}

Rational::Rational(const Rational& r) {
    numerator = r.numerator;
    denumerator = r.denumerator;
}

Rational const operator+(const Rational& left, const Rational& right) {
    int rNum = 1, rDen = 1;
    int lcm = Rational::lcm_gcd(left.denumerator, right.denumerator, 0);
    int leftNum = left.numerator * (lcm / left.denumerator);
    int rightNum = right.numerator * (lcm / right.denumerator);
    rNum = leftNum + rightNum;
    rDen = lcm;
    int gcd = Rational::lcm_gcd(rNum, rDen, 1);
    rNum /= gcd;
    rDen /= gcd;
    return Rational(rNum, rDen);
}

const Rational operator-(const Rational& left, const Rational& right) {
    Rational tmp = right;
    tmp.numerator *= -1;
    return (left + tmp);
}

const Rational operator*(const Rational& left, const Rational& right) {
    int rNum = left.numerator * right.numerator, rDen = left.denumerator * right.denumerator;
    int gcd = Rational::lcm_gcd(rNum, rDen, 1);
    rNum /= gcd;
    rDen /= gcd;
    return Rational(rNum, rDen);
}

const Rational operator/(const Rational& left, const Rational& right) {
    Rational temp(right.denumerator, right.numerator);
    return (left * temp);
}

Rational& operator+=(Rational& left, const Rational& right) {
    left = left + right;
    return left;
}

Rational& operator-=(Rational& left, const Rational& right) {
    left = left - right;
    return left;
}

Rational& operator*=(Rational& left, const Rational& right) {
    left = left * right;
    return left;
}

Rational& operator/=(Rational& left, const Rational& right) {
    left = left / right;
    return left;
}

std::ostream& operator<<(std::ostream& os, const Rational& value) {
    os << value.numerator << "/" << value.denumerator;
}

bool operator<(const Rational& left, const Rational& right) {
    int lcm = Rational::lcm_gcd(left.denumerator, right.denumerator, 0);
    int leftNum = left.numerator * (lcm / left.denumerator);
    int rightNum = right.numerator * (lcm / right.denumerator);
    return bool(leftNum < rightNum);
}

bool operator>(const Rational& left, const Rational& right) {
    int lcm = Rational::lcm_gcd(left.denumerator, right.denumerator, 0);
    int leftNum = left.numerator * (lcm / left.denumerator);
    int rightNum = right.numerator * (lcm / right.denumerator);
    return bool(leftNum > rightNum);
}

bool operator<=(const Rational& left, const Rational& right) {
    int lcm = Rational::lcm_gcd(left.denumerator, right.denumerator, 0);
    int leftNum = left.numerator * (lcm / left.denumerator);
    int rightNum = right.numerator * (lcm / right.denumerator);
    return bool(leftNum <= rightNum);
}

bool operator>=(const Rational& left, const Rational& right) {
    int lcm = Rational::lcm_gcd(left.denumerator, right.denumerator, 0);
    int leftNum = left.numerator * (lcm / left.denumerator);
    int rightNum = right.numerator * (lcm / right.denumerator);
    return bool(leftNum >= rightNum);
}

bool operator==(const Rational& left, const Rational& right) {
    int lcm = Rational::lcm_gcd(left.denumerator, right.denumerator, 0);
    int leftNum = left.numerator * (lcm / left.denumerator);
    int rightNum = right.numerator * (lcm / right.denumerator);
    return bool(leftNum == rightNum);
}

bool operator!=(const Rational& left, const Rational& right) {
    int lcm = Rational::lcm_gcd(left.denumerator, right.denumerator, 0);
    int leftNum = left.numerator * (lcm / left.denumerator);
    int rightNum = right.numerator * (lcm / right.denumerator);
    return bool(leftNum != rightNum);
}

int Rational::lcm_gcd(int x, int y, int type) {
    if (type == 0) {
        if (x == 1 || x == -1) return y;
        if (y == 1 || y == -1) return x;
    } else
        if (x == 1 || y == 1 || x == -1 || y == -1) return 1;
    vector<int> xDecomp, yDecomp, multipliers;
    int maxMultiplier, multiplier, multiplierIndex = 0;
    if (x > y) maxMultiplier = x; else maxMultiplier = y;
    for (int i = 2; i <= maxMultiplier; i++)
        multipliers.push_back(i);
    while (multiplierIndex < multipliers.size()) {
        multiplier = multipliers[multiplierIndex];
        for (int i = 1; multiplierIndex+multiplier * i < multipliers.size(); i++)
            multipliers[multiplierIndex+multiplier*i] = 0;
        while (multiplierIndex < multipliers.size() && multiplier >= multipliers[multiplierIndex])
            multiplierIndex++;
    }
    for (vector<int>::iterator it = multipliers.begin(); it != multipliers.end(); it++)
        if (*it == 0) multipliers.erase(it--);
    xDecomp.resize(multipliers.size(), 0);
    yDecomp.resize(multipliers.size(), 0);
    int i, j;
    while (x > 1) {
        for (i = 0; x % multipliers[i] != 0; i++);
        xDecomp[i]++;
        x = x / multipliers[i];
    }
    while (y > 1) {
        for (j = 0; y % multipliers[j] != 0; j++);
        yDecomp[j]++;
        y = y / multipliers[j];
    }
    int result = 1, power, factor;
    for (i = 0; i < multipliers.size(); i++) {
        if (type == 0)
            if (xDecomp[i] >= yDecomp[i]) power = xDecomp[i]; else power = yDecomp[i];
        else
            if (xDecomp[i] <= yDecomp[i]) power = xDecomp[i]; else power = yDecomp[i];
        factor = 1;
        for (j = 0; j < power; j++) factor *= multipliers[i];
        result *= factor;
    }
    return result;
}

TestSearch::TestSearch() : max(0), current(0) { srand(0); }

int TestSearch::binSearch(int x) {
    int low = 0, high = size, mid = (low + high)/2;
    while (low <= high && v[mid] != x) {
        if (x < v[mid]) high = mid - 1; else low = mid + 1;
        mid = (low + high)/2;
    }
    if (low <= high) return mid; else return -1;
}

void TestSearch::setData() {
    if (max) throw out_of_range("Max value non zero.");
    for (int i = 0; i < size; i++) {
        v[i] = max;
        if (rand() % 2 == 0) max += 1; else max += 2;
    }
}

void TestSearch::run() {
    setData();
    cout << "Vector: ";
    int founded = 0, notFounded = 0;
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
        if (binSearch(i) != -1) founded++; else notFounded++;
    }
    cout << "\nFounded: " << founded << ", not founded: " << notFounded << endl;
}
