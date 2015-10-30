#include "chapter_02.h"

using namespace TestKit;
using namespace std;

Test::Test(std::ostream* osPtr) : os(osPtr), nPass(0), nFail(0) {}

Test::~Test() {}

void Test::run() {}

long Test::getNumPassed() const { return nPass; }

long Test::getNumFailed() const { return nFail; }

const std::ostream* Test::getStream() const { return os; }

void Test::setStream(std::ostream* osPtr) { os = osPtr; }

void Test::succeed_() { ++nPass; }

long Test::report() const {
    if (os) *os << " Test : " << typeid(*this).name() << ", passed: " << nPass << ", failed: " << nFail << endl;
    return nFail;
}

void Test::reset() { nPass = nFail = 0; }

void Test::doTest(bool condition, const std::string& label, const char *fName, long line) {
    if (!condition) doFail(label, fName, line); else succeed_();
}

void Test::doFail(const std::string& label, const char *fName, long line) {
    ++nFail;
    if (os) *os << typeid(*this).name() << "failure: (" << label << ") . " << fName
                << " (line " << line << ")" << endl;
}


