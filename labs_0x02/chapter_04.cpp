#include "chapter_04.h"

using namespace std;

std::ostream& newMan(std::ostream& os) {
    os << "TEST" << endl;
}

FieldWidth::FieldWidth(string message, int n) : maxWidth(n), msg(message) {}

ostream& operator<<(ostream& os, const FieldWidth& fw) {
    FieldWidth tmp = fw;
    if (tmp.msg.size() > tmp.maxWidth) tmp.msg.resize(tmp.maxWidth);
    os << tmp.msg;
    return os;
}
