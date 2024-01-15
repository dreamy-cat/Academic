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
    cout << "Class_12_13 integer = " << *i << ", address : " << (long long)i << endl;
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

// Task 23.

int Dog_12_2::constructorCount = 0;
int DogHouse_12_2::constructorCount = 0;

Dog_12_2::Dog_12_2(const string nm) : name(nm), refcount(1) {
    lastCounter = ++constructorCount;
    cout << "Creating Dog, objects[" << lastCounter << "]: " << *this << endl;
}

Dog_12_2* Dog_12_2::make(const string nm) {
    ++constructorCount;
    return new Dog_12_2(nm);
}

Dog_12_2::Dog_12_2(const Dog_12_2 &d) {
    lastCounter = ++constructorCount;
    name = d.name + " copy";
    refcount = 1;
    cout << "Dog copy constructor, objects[" << lastCounter << "]: " << *this << endl;
}

Dog_12_2::~Dog_12_2() {
    cout << "Deleting Dog[" << lastCounter << "]: " << *this << endl;
}

void Dog_12_2::attach() {
    ++refcount;
    cout << "Attached dog[" << lastCounter << "]: " << *this << endl;
}

void Dog_12_2::detach() {
    if (refcount == 0) {
        cout << "Refcount is null.";
        return;
    }
    cout << "Detaching Dog[" << lastCounter << "]: " << *this << endl;
    if (--refcount == 0) delete this;
}

Dog_12_2* Dog_12_2::unalias() {
    cout << "Unaliasing Dog[" << lastCounter << "]: " << *this << endl;
    if (refcount == 1) return this;
    --refcount;
    return new Dog_12_2(*this);
}

void Dog_12_2::rename(const string newName) {
    name = newName;
    cout << "Dog renamed to[" << lastCounter << "]: " << *this << endl;
}

ostream& operator<<(ostream& os, const Dog_12_2& value) {
    return os << "[" << value.name << ":" << value.refcount << "]";
}

DogHouse_12_2::DogHouse_12_2(Dog_12_2 *dog, const string house) {
    lastCounter = ++constructorCount;
    p = dog;
    name = house;
    cout << "Created DogHouse, objects[" << lastCounter << "]: " << *this << endl;
}

DogHouse_12_2::~DogHouse_12_2() {
    cout << "DogHouse destructor[" << lastCounter << "]: " << *this << endl;
    p->detach();
}

DogHouse_12_2::DogHouse_12_2(const DogHouse_12_2 &dh) {
    lastCounter = ++constructorCount;
    p = dh.p;
    name = "copy construced " + dh.name;
    p->attach();
    cout << "DogHouse copy-constructor, objects[" << lastCounter << "]: " << *this << endl;
}

DogHouse_12_2& DogHouse_12_2::operator=(const DogHouse_12_2& r) {
    if (&r != this) {
        name = r.name + " assigned.";
        p->detach();
        p = r.p;
        p->attach();
    }
    cout << "DogHouse operator=[" << lastCounter << "]: " << *this << endl;
    return *this;
}

void DogHouse_12_2::renameHouse(const string newName) {
    name = newName;
}

void DogHouse_12_2::renameDog(const string newName) {
    unalias();
    p->rename(newName);
}

void DogHouse_12_2::unalias() {
    p = p->unalias();
}

Dog_12_2* DogHouse_12_2::getDog() {
    unalias();
    return p;
}

ostream& operator<<(ostream& os, const DogHouse_12_2& value) {
    return os << "[" << value.name << "] contains " << *value.p;
}

Class_12_24_1::Class_12_24_1(std::string is) : s(is) {
    cout << "Class_12_24_1 constructor s = " << s << endl;
}

Class_12_24_2::Class_12_24_2(std::string is) : cl1(is) {
    cout << "Class_12_24_2 constructor, string = " << is << endl;
}

ostream& operator<<(ostream& os, const Class_12_24_2& value) {
    cout << "Class_12_24_2::Class_12_24_1 string = " << value.cl1.s << endl;
}

Integer_12::Integer_12(long il) : i(il) {
    cout << "Integer_12 constructor." << endl;
}

Integer_12* Integer_12::get() {
    cout << "Integer_12, get()." << endl;
    return this;
}

const Integer_12& operator+(const Integer_12& a) {
    cout << "Intger_12, unary 'operator+'." << endl;
    return a;
}

const Integer_12 operator-(const Integer_12& a) {
    cout << "Intger_12, unary 'operator-'." << endl;
    return Integer_12(-a.i);
}

const Integer_12 operator~(const Integer_12& a) {
    cout << "Intger_12, unary 'operator~'." << endl;
    return ~a.i;
}

Integer_12* operator&(Integer_12& a) {
    cout << "Intger_12, unary 'operator&'." << endl;
    return a.get();
}

const int operator!(const Integer_12& a) {
    cout << "Intger_12, unary 'operator!'." << endl;
    return !a.i;
}

const Integer_12 operator++(Integer_12& a) {
    cout << "Intger_12, unary 'prefix operator++'." << endl;
    a.i++;
    return a.i;
}

const Integer_12 operator++(Integer_12& a, int) {
    cout << "Intger_12, unary 'postfix operator++'." << endl;
    Integer_12 r = a.i;
    a.i++;
    return r;
}

const Integer_12 operator--(Integer_12& a) {
    cout << "Intger_12, unary 'prefix operator--'." << endl;
    a.i--;
    return a.i;
}

const Integer_12 operator--(Integer_12& a, int) {
    cout << "Intger_12, unary 'postfix operator--'." << endl;
    Integer_12 r = a.i;
    a.i--;
    return r;
}

const Integer_12 operator+(Integer_12& left, Integer_12& right) {
    cout << "Intger_12, binary 'operator+'." << endl;
    return Integer_12(left.i + right.i);
}

const Integer_12 operator-(Integer_12& left, Integer_12& right) {
    cout << "Intger_12, binary 'operator-'." << endl;
    return Integer_12(left.i - right.i);
}

const Integer_12 operator*(Integer_12& left, Integer_12& right) {
    cout << "Intger_12, binary 'operator*'." << endl;
    return Integer_12(left.i * right.i);
}

const Integer_12 operator/(Integer_12& left, Integer_12& right) {
    cout << "Intger_12, binary 'operator/'." << endl;
    if (right.i == 0) return Integer_12(0);
    return Integer_12(left.i / right.i);
}

const Integer_12 operator%(Integer_12& left, Integer_12& right) {
    cout << "Intger_12, binary 'operator%'." << endl;
    if (right.i == 0) return Integer_12(0);
    return Integer_12(left.i % right.i);
}

const Integer_12 operator^(Integer_12& left, Integer_12& right) {
    cout << "Intger_12, binary 'operator^'." << endl;
    return Integer_12(left.i ^ right.i);
}

const Integer_12 operator&(Integer_12& left, Integer_12& right) {
    cout << "Intger_12, binary 'operator&'." << endl;
    return Integer_12(left.i & right.i);
}

const Integer_12 operator|(Integer_12& left, Integer_12& right) {
    cout << "Intger_12, binary 'operator|'." << endl;
    return Integer_12(left.i | right.i);
}

const Integer_12 operator<<(Integer_12& left, Integer_12& right) {
    cout << "Intger_12, binary 'operator<<'." << endl;
    return Integer_12(left.i << right.i);
}

const Integer_12 operator>>(Integer_12& left, Integer_12& right) {
    cout << "Intger_12, binary 'operator>>'." << endl;
    return Integer_12(left.i >> right.i);
}

Integer_12& operator+=(Integer_12& left, Integer_12& right) {
    cout << "Integer_12, binary 'operator+='." << endl;
    left.i += right.i;
    return left;
}

Integer_12& operator-=(Integer_12& left, Integer_12& right) {
    cout << "Integer_12, binary 'operator-='." << endl;
    left.i -= right.i;
    return left;
}

Integer_12& operator*=(Integer_12& left, Integer_12& right) {
    cout << "Integer_12, binary 'operator*='." << endl;
    left.i *= right.i;
    return left;
}

Integer_12& operator/=(Integer_12& left, Integer_12& right) {
    cout << "Integer_12, binary 'operator/='." << endl;
    if (right.i == 0) return left;
    left.i /= right.i;
    return left;
}

Integer_12& operator%=(Integer_12& left, Integer_12& right) {
    cout << "Integer_12, binary 'operator%='." << endl;
    if (right.i == 0) return left;
    left.i %= right.i;
    return left;
}

Integer_12& operator^=(Integer_12& left, Integer_12& right) {
    cout << "Integer_12, binary 'operator^='." << endl;
    left.i ^= right.i;
    return left;
}

Integer_12& operator&=(Integer_12& left, Integer_12& right) {
    cout << "Integer_12, binary 'operator&='." << endl;
    left.i &= right.i;
    return left;
}

Integer_12& operator|=(Integer_12& left, Integer_12& right) {
    cout << "Integer_12, binary 'operator|='." << endl;
    left.i |= right.i;
    return left;
}

Integer_12& operator>>=(Integer_12& left, Integer_12& right) {
    cout << "Integer_12, binary 'operator>>='." << endl;
    left.i >>= right.i;
    return left;
}

Integer_12& operator<<=(Integer_12& left, Integer_12& right) {
    cout << "Integer_12, binary 'operator<<='." << endl;
    left.i <<= right.i;
    return left;
}

int operator==(const Integer_12& left, const Integer_12& right) {
    cout << "Integer_12, binary 'operator=='." << endl;
    return (left.i == right.i);
}

int operator!=(const Integer_12& left, const Integer_12& right) {
    cout << "Integer_12, binary 'operator!='." << endl;
    return (left.i != right.i);
}

int operator<(const Integer_12& left, const Integer_12& right) {
    cout << "Integer_12, binary 'operator<'." << endl;
    return (left.i < right.i);
}

int operator>(const Integer_12& left, const Integer_12& right) {
    cout << "Integer_12, binary 'operator>'." << endl;
    return (left.i < right.i);
}

int operator<=(const Integer_12& left, const Integer_12& right) {
    cout << "Integer_12, binary 'operator<='." << endl;
    return (left.i <= right.i);
}

int operator>=(const Integer_12& left, const Integer_12& right) {
    cout << "Integer_12, binary 'operator>='." << endl;
    return (left.i >= right.i);
}

int operator&&(const Integer_12& left, const Integer_12& right) {
    cout << "Integer_12, binary 'operator&&'." << endl;
    return (left.i && right.i);
}

int operator||(const Integer_12& left, const Integer_12& right) {
    cout << "Integer_12, binary 'operator||'." << endl;
    return (left.i || right.i);
}

int Dog_26::run(int i) const {
    cout << "Class_26, function 'run()'." << endl;
    return 1;
}

int Dog_26::eat(int i) const {
    cout << "Class_26, function 'eat()'." << endl;
    return 2;
}

int Dog_26::sleep(int i) const {
    cout << "Class_26, function 'sleep()'." << endl;
    return 3;
}

void Dog_26::function_1() const {
    cout << "Class_26, 'function_1'." << endl;
}

void Dog_26::function_2() const {
    cout << "Class_26, 'function_2'." << endl;
}

Dog_26::FunctionObject_26::FunctionObject_26(Dog_26 *wp, pmf p) : ptr(wp), pmem(p) {
    cout << "FunctionObject_26 constructor." << endl;
}

Dog_26::FunctionObject_26::FunctionObject_26(Dog_26* wp, pvt pv) : ptr(wp), pvoid(pv) {
    cout << "FunctionObject_26 constructor for addition functions." << endl;
}

int Dog_26::FunctionObject_26::operator ()(int i) const {
    cout << "FunctionObject_26, operator()." << endl;
    return (ptr->*pmem)(i);
}

Dog_26::FunctionObject_26 Dog_26::operator ->*(pmf ptr) {
    cout << "FunctionObject_26, operator->*." << endl;
    return Dog_26::FunctionObject_26(this, ptr);
}

void Dog_26::FunctionObject_26::operator ()() const {
    cout << "FunctionObject_26, operator() for addition functions." << endl;
    return (ptr->*pvoid)();
}

Dog_26::FunctionObject_26 Dog_26::operator ->*(void (Dog_26::*pvt)() const) {
    cout << "Function_26, operator->* for addition functions." << endl;
    return Dog_26::FunctionObject_26(this, pvt);
}

Obj_27::Obj_27(int id, fPtr p) : objectID(id), ptr(p) {
    cout << "Obj_27 constructor id = " << id << endl;
}

void Obj_27::function_1() {
    cout << "Class Obj_27, function_1, id = " << objectID << endl;
}

void Obj_27::function_2() {
    cout << "Class Obj_27, function_2, id = " << objectID << endl;
}

void Obj_27::operator()() {
    cout << "Class Obj-27, operator(), id = " << objectID << endl;
    return (this->*ptr)();
}

ObjContainer_27::ObjContainer_27() : index(0) {
    cout << "Class ObjContainer_27 constructor." << endl;
}

void ObjContainer_27::add(Obj_27* obj) {
    a.push_back(obj);
}

void ObjContainer_27::next() { if (index < a.size()-1) index++; }

void ObjContainer_27::previous() { if (index > 0) index--; }

Obj_27 ObjContainer_27::operator->*(void (Obj_27::*fP)() ) {
    cout << "Class Obj_27, operator->*." << endl;
    a[index]->ptr = fP;
    return *(a[index]);
    // return (Obj_27(0, fP));
}

Apple_12::Apple_12(Orange_12) {
    cout << "Consturctor class Apple_12." << endl;
}

Orange_12::Orange_12() {
    cout << "Consturctor class Orange_12." << endl;
}

Orange_12::operator Apple_12() const {
    cout << "Class Orange_12, operator Apple_12()" << endl;
}

void function_12_28(Apple_12 o) {
    cout << "Function_12_28." << endl;
}

Number_12_1::Number_12_1(int ii) : i(ii) {
    cout << "Class Number_12_1, constructor." << endl;
}

const Number_12_1 Number_12_1::operator +(const Number_12_1& right) const {
    return Number_12_1(i + right.i);
}

const Number_12_1 operator-(const Number_12_1& left, const Number_12_1& right) {
    return Number_12_1(left.i - right.i);
}

const Number_12_1 operator*(const Number_12_1& left, const Number_12_1& right) {
    return Number_12_1(left.i * right.i);
}

Class_12_30_1::Class_12_30_1(int ii) : i(ii) {
    cout << "Class_12_30_1 constructor." << endl;
}

Class_12_30_1::operator Class_12_30_2() const {
    cout << "Class_12_30_1, operator (Class_12_30_2)." << endl;
    return Class_12_30_1(i);
}

const Class_12_30_1 operator+(const Class_12_30_1& left, const Class_12_30_1& right) {
    return Class_12_30_1(left.i + right.i);
}

Class_12_30_2::Class_12_30_2(int ii) : i(ii) {
    cout << "Class_12_30_2 constructor." << endl;
}

Class_12_30_2::operator Class_12_30_1() const {
    cout << "Class_12_30_2, operator (Class_12_30_1)." << endl;
}
/*
const Class_12_30_2 Class_12_30_2::operator+(Class_12_30_2& right) {
    return Class_12_30_2(i + right.i);
}
*/

void func_30(Class_12_30_2 cl) {

}

void function_32() {
    double d1 = 8, d2 = 2, d3 = 0;
    d3 = d1 + d2;
    d3 = d1 - d2;
    d3 = d1 * d2;
    d3 = d1 / d2;
}

/* Code...

 8900              		.globl	_Z11function_32v
 8901              		.type	_Z11function_32v, @function
 8902              	_Z11function_32v:
 8903              	.LFB1491:
 8904              		.cfi_startproc
 8905 3d39 55       		pushq	%rbp
 8906              		.cfi_def_cfa_offset 16
 8907              		.cfi_offset 6, -16
 8908 3d3a 4889E5   		movq	%rsp, %rbp
 8909              		.cfi_def_cfa_register 6
 8910 3d3d 48B80000 		movabsq	$4620693217682128896, %rax
 8910      00000000
 8910      2040
 8911 3d47 488945E8 		movq	%rax, -24(%rbp)
 8912 3d4b 48B80000 		movabsq	$4611686018427387904, %rax
 8912      00000000
 8912      0040
 8913 3d55 488945F0 		movq	%rax, -16(%rbp)
 8914 3d59 B8000000 		movl	$0, %eax
 8914      00
 8915 3d5e 488945F8 		movq	%rax, -8(%rbp)
 8916 3d62 F20F1045 		movsd	-24(%rbp), %xmm0
 8916      E8
 8917 3d67 F20F5845 		addsd	-16(%rbp), %xmm0
 8917      F0
 8918 3d6c F20F1145 		movsd	%xmm0, -8(%rbp)
 8918      F8
 8919 3d71 F20F1045 		movsd	-24(%rbp), %xmm0
 8919      E8
 8920 3d76 F20F5C45 		subsd	-16(%rbp), %xmm0
 8920      F0
 8921 3d7b F20F1145 		movsd	%xmm0, -8(%rbp)
 8921      F8
 8922 3d80 F20F1045 		movsd	-24(%rbp), %xmm0
 8922      E8
 8923 3d85 F20F5945 		mulsd	-16(%rbp), %xmm0
 8923      F0
 8924 3d8a F20F1145 		movsd	%xmm0, -8(%rbp)
 8924      F8
 8925 3d8f F20F1045 		movsd	-24(%rbp), %xmm0
 8925      E8
 8926 3d94 F20F5E45 		divsd	-16(%rbp), %xmm0
 8926      F0
 8927 3d99 F20F1145 		movsd	%xmm0, -8(%rbp)
 8927      F8
 8928 3d9e 5D       		popq	%rbp
 8929              		.cfi_def_cfa 7, 8
GAS LISTING /tmp/ccOp3L1h.s 			page 184


 8930 3d9f C3       		ret
 8931              		.cfi_endproc
 8932              	.LFE1491:
 8933              		.size	_Z11function_32v, .-_Z11function_32v


*/
