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
    this->numerator = numerator;
    this->denumerator = denumerator;
}

const Rational operator+(const Rational& left, const Rational& right) {}

const Rational operator-(const Rational& left, const Rational& right) {}

const Rational operator*(const Rational& left, const Rational& right) {}

const Rational operator/(const Rational& left, const Rational& right) {}

std::ostream& operator<<(std::ostream& os, const Rational& value) {}

bool operator<(const Rational& left, const Rational& right) {}

bool operator>(const Rational& left, const Rational& right) {}

bool operator<=(const Rational& left, const Rational& right) {}

bool operator>=(const Rational& left, const Rational& right) {}

bool operator==(const Rational& left, const Rational& right) {}

bool operator!=(const Rational& left, const Rational& right) {}

int Rational::lcm(int x, int y) {
    vector<int, int> xDecomp, yDecomp;
}


