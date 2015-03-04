#include "chapter_12.h"

using namespace std;

const Class_12_1& Class_12_1::operator++() {
    cout << "Class_12_1, prefix operator++." << endl;
}

const Class_12_1& Class_12_1::operator++(int) {
    cout << "Class_12_1, postfix operator++." << endl;
}

Class_12_2::Class_12_2(int ii) : i(ii) {}

const Class_12_2 operator +(const Class_12_2 &left, const Class_12_2& right) {
    return (Class_12_2(left.i + right.i));
}

const Class_12_2 operator -(const Class_12_2& left, const Class_12_2& right) {
    return (Class_12_2(left.i - right.i));
}

const Class_12_2 Class_12_2::operator -() {
    i = i * (-1);
    return *this;
}

Class_12_2& Class_12_2::operator++() {
    i++;
    return *this;
}

const Class_12_2 Class_12_2::operator++(int) {
    Class_12_2 value(i);
    i++;
    return value;
}

std::ostream& operator<<(std::ostream& os, Class_12_2& value) {
    return os << "Class_12_2, integer = " << value.i << endl;
}

