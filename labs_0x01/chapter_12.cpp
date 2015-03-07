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

Class_12_9::Class_12_9(char ic) : c(ic) {}

const Class_12_9 Class_12_9::operator++(int a) {
    cout << "Fiction int in postfix operator++ = " << a << endl;
}

const Class_12_9 Class_12_9::operator--(int a) {
    cout << "Fiction int in postfix operator-- = " << a << endl;
}

std::ostream& operator<<(std::ostream& os, const Class_12_9& value) {
    os << "Class_12_2, char = " << value.c << endl;
    return os;
}

std::istream& operator>>(std::istream& is, Class_12_9& value) {
    cout << "Enter char : ";
    is >> value.c;
    return is;
}

Number_12::Number_12(double di) : d(di) {}

Number_12::Number_12(const Number_12& r) {
    d = r.d;
}

const Number_12 Number_12::operator+(const Number_12& right) const {
    return (Number_12(d + right.d));
}

const Number_12 Number_12::operator-(const Number_12& right) const {
    return (Number_12(d - right.d));
}

const Number_12 Number_12::operator*(const Number_12& right) const {
    return (Number_12(d * right.d));
}

const Number_12 Number_12::operator/(const Number_12& right) const {
    return (Number_12(d / right.d));
}

Number_12& Number_12::operator=(const Number_12& rv) {
    if (&rv != this) d = rv.d;
    return *this;
}

Number_12::operator double() const {
    cout << "Number_12::operator double() has called." << endl;
    return d;
}

std::ostream& operator<<(std::ostream& os, const Number_12& value) {
    return os << "Number_12, double value = " << value.d << endl;
}

void function_12_12(double d) {
    cout << "Function with argument double = " << d << endl;
}

Class_12_13::Class_12_13(int *ii) : i(ii) {}

void Class_12_13::print() {
    cout << "Class_12_13 integer = " << *i << ", address : " << (long)i << endl;
}

Class_12_13& Class_12_13::operator=(const Class_12_13& rv) {
    if (this != &rv) {
        i = new int;
        *i = *rv.i;
    }
    return *this;
}

int Bird_12::counter = 0;

Bird_12::Bird_12(int ii) { i = ii; name = "Class Bird_12-";  name += char('0' + counter++); }

Bird_12::Bird_12(Bird_12 &rv) {
    cout << "Copy constructor of Bird_12." << endl;
    name = rv.name;
    i = rv.i;
}

Bird_12& Bird_12::operator=(const Bird_12& rv) {
    if (this != &rv) {
        i = rv.i;
        name = rv.name;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Bird_12& value) {
    cout << value.name << " integer = " << value.i << endl;
}

const Bird_12 Bird_12::operator +(const Bird_12& right) const {
    Bird_12 t(i + right.i);
    return t;
}

const Bird_12 Bird_12::operator -(const Bird_12& right) const {
    Bird_12 t(i - right.i);
    return t;
}

const Bird_12 Bird_12::operator *(const Bird_12& right) const {
    Bird_12 t(i * right.i);
    return t;
}

const Bird_12 Bird_12::operator/(const Bird_12& right) const {
    Bird_12 t(i / right.i);
    return t;
}

void function_12_14(Bird_12& cl) {
    cout << "Function_12_14." << endl;
}

BirdHouse_12::BirdHouse_12(Bird_12& cl1, Bird_12& cl2, Bird_12& cl3, int ii) : bird_3(cl3), i(ii)  {
    bird_1 = cl1;
    bird_2 = new Bird_12();
    *bird_2 = cl2;
}

std::ostream& operator<<(std::ostream& os, const BirdHouse_12& value) {
    cout << "Birds in class BirdsHouse_12 : int(" << value.i << ")\n" << value.bird_1 << *value.bird_2 << value.bird_3;
}

BirdHouse_12::BirdHouse_12(const BirdHouse_12&r) : bird_3(r.bird_3) {
    i = r.i;
    bird_1 = r.bird_1;
    bird_2 = r.bird_2;
}

BirdHouse_12& BirdHouse_12::operator=(const BirdHouse_12& r) {
    bird_1 = r.bird_1;
    bird_2 = r.bird_2;
    bird_3 = r.bird_3;
    return *this;
}

const BirdHouse_12 operator+(const BirdHouse_12& left, const BirdHouse_12& right) {
    Bird_12* p1 = new Bird_12();
    Bird_12* p2 = new Bird_12();
    Bird_12* p3 = new Bird_12();
    *p1 = left.bird_1 + right.bird_1;
    *p2 = *left.bird_2 + *right.bird_2;
    *p3 = left.bird_3 + right.bird_3;
    return BirdHouse_12(*p1, *p2, *p3, 10);
}

const BirdHouse_12 operator-(const BirdHouse_12& left, const BirdHouse_12& right) {
    Bird_12* p1 = new Bird_12();
    Bird_12* p2 = new Bird_12();
    Bird_12* p3 = new Bird_12();
    *p1 = left.bird_1 - right.bird_1;
    *p2 = *left.bird_2 - *right.bird_2;
    *p3 = left.bird_3 - right.bird_3;
    return BirdHouse_12(*p1, *p2, *p3, 15);
}

const BirdHouse_12 operator*(const BirdHouse_12& left, const BirdHouse_12& right) {
    Bird_12* p1 = new Bird_12();
    Bird_12* p2 = new Bird_12();
    Bird_12* p3 = new Bird_12();
    *p1 = left.bird_1 * right.bird_1;
    *p2 = *left.bird_2 * (*right.bird_2);
    *p3 = left.bird_3 * right.bird_3;
    return BirdHouse_12(*p1, *p2, *p3, 20);
}

const BirdHouse_12 operator/(const BirdHouse_12& left, const BirdHouse_12& right) {
    Bird_12* p1 = new Bird_12();
    Bird_12* p2 = new Bird_12();
    Bird_12* p3 = new Bird_12();
    *p1 = left.bird_1 / right.bird_1;
    *p2 = *left.bird_2 / *right.bird_2;
    *p3 = left.bird_3 / right.bird_3;
    return BirdHouse_12(*p1, *p2, *p3, 25);
}

int Obj_18::i = 3;
int Obj_18::j = 7;

void Obj_18::f() const { cout << "Obj_18_1, i = " << i++ << endl; }

void Obj_18::g() const { cout << "Obj_18_1, j = " << j++ << endl; }

void ObjContainer_18_1::add(Obj_18 *obj) { a.push_back(obj); }

SmartPointer_18_1::SmartPointer_18_1(ObjContainer_18_1 &objC) : oc(objC) {
    index = 0;
}

bool SmartPointer_18_1::operator ++() {
    if (index >= oc.a.size()) return false;
    if (oc.a[++index] == 0) return false;
    return true;
}

bool SmartPointer_18_1::operator --() {
    if (index == 0) return false;
    if (oc.a[--index] == 0) return false;
    return true;
}

bool SmartPointer_18_1::operator --(int) {
    return operator--();
}

bool SmartPointer_18_1::operator ++(int) {
    return operator++();
}

Obj_18* SmartPointer_18_1::operator ->() const {
    if (oc.a.empty())  return NULL;
    return oc.a[index];
}

void ObjContainer_18_2::add(Obj_18 *obj) {
    a.push_back(obj);
}

ObjContainer_18_2::SmartPointer_18_2::SmartPointer_18_2(ObjContainer_18_2 &objC) : oc(objC){
    index = 0;
}

bool ObjContainer_18_2::SmartPointer_18_2::operator++() {
    if (index >= oc.a.size()) return false;
    if (oc.a[++index] == 0) return false;
    return true;
}

bool ObjContainer_18_2::SmartPointer_18_2::operator++(int) {
    return operator++();
}

bool ObjContainer_18_2::SmartPointer_18_2::operator--() {
    if (index <= 0) return false;
    if (oc.a[--index] == 0) return false;
    return true;
}

bool ObjContainer_18_2::SmartPointer_18_2::operator--(int) {
    return operator--();
}

Obj_18* ObjContainer_18_2::SmartPointer_18_2::operator->() const {
    if (oc.a.empty()) return NULL;
    return oc.a[index];
}

ObjContainer_18_2::SmartPointer_18_2 ObjContainer_18_2::begin() {
    return ObjContainer_18_2::SmartPointer_18_2(*this);
}

Class_12_19_1::Class_12_19_1() {
    cout << "Class_12_19_1 constructor." << endl;
}

Class_12_19_2::Class_12_19_2() {
    cout << "Class_12_19_2 constructor." << endl;
}

Class_12_19_2::Class_12_19_2(const Class_12_19_1 &) {
    cout << "Class_12_19_2 copy constructor from Class_12_19_1." << endl;
}


// Task 20. 'Class_12_19_2& operator=(Class_12_19_2& r)' must be a nonstatic member function
// Class_12_19_2& operator=(const Class_12_19_2& r) {}

Class_12_21::Class_12_21(string is) : s(is) {}

Class_12_21& Class_12_21::operator =(Class_12_21& r) {
    s = r.s;
    return *this;
}

Dog_12_1::Dog_12_1(const string &nm) : name(nm) {
    cout << "Dog_12_1 constructor, name = " << *this << endl;
}

Dog_12_1::Dog_12_1(const Dog_12_1 *dp, const string &msg) : name(dp->name + msg) {
    cout << "Dog_12_1 object copied : " << *this << " from " << *dp << endl;
}

Dog_12_1::~Dog_12_1() {
    cout << "Dog_12_1 destructor : " << *this << endl;
}

void Dog_12_1::rename(string newName) {
    name = newName;
    cout << "Dog_12_1 renamed: " << *this << endl;
}

ostream& operator<<(ostream& os, const Dog_12_1& value) {
    return os << "[" << value.name << "]";
}

DogHouse_12_1::DogHouse_12_1(Dog_12_1 *dog, const string nm) : p(dog), name(nm) {}

DogHouse_12_1::~DogHouse_12_1() { delete p; }

DogHouse_12_1::DogHouse_12_1(const DogHouse_12_1& r) {
    p = new Dog_12_1(r.p, " copy constructed.");
    name = r.name + " copy constructed.";
}

DogHouse_12_1& DogHouse_12_1::operator =(const DogHouse_12_1& r) {
    if (&r != this) {
        p = new Dog_12_1(r.p, " assigned.");
        name = r.name + " assigned.";
    }
    return *this;
}

void DogHouse_12_1::rename(const string &newName) { name = newName; }

Dog_12_1* DogHouse_12_1::getDog() const { return p; }

ostream& operator<<(ostream& os, const DogHouse_12_1& value) {
    return os << "[" << value.name << "] contains " << *value.p;
}
