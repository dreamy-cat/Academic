#include "14_Inheritance_and_Composition.hpp"

using namespace std;

Vehicle_14::Vehicle_14(int ii) : i(ii) {
    cout << "Vehicle_14 constructor, int = " << i << endl;
}

Car_14::Car_14(int ii) : Vehicle_14(ii) {
    cout << "Car_14 constructor." << endl;
}

Class_14_2_1::Class_14_2_1() {
    cout << "Class_14_2_1 constructor." << endl;
}

Class_14_2_2::Class_14_2_2() {
    cout << "Class_14_2_2 constructor." << endl;
}

Class_14_3_1::Class_14_3_1() {
    cout << "Class_14_3_1 constructor." << endl;
}

Class_14_3_1::~Class_14_3_1() {
    cout << "Class_14_3_1 destructor." << endl;
}

Class_14_3_2::Class_14_3_2() {
    cout << "Class_14_3_2 constructor." << endl;
}

Class_14_3_2::~Class_14_3_2() {
    cout << "Class_14_3_2 destructor." << endl;
}

Class_14_3_3::Class_14_3_3() {
    cout << "Class_14_3_3 constructor." << endl;
}

Class_14_3_3::~Class_14_3_3() {
    cout << "Class_14_3_3 destructor." << endl;
}

Combined_A::Combined_A(int ii) : i(ii) { cout << "Combined_A constructor." << endl; }

Combined_A::~Combined_A() { cout << "Combined_A destructor." << endl; }

Combined_B::Combined_B(int ii) : i(ii) { cout << "Combined_B constructor." << endl; }

Combined_B::~Combined_B() { cout << "Combined_B destructor." << endl; }

Combined_C::Combined_C(int ii) : Combined_B(ii), a(ii) { cout << "Combined_C constructor." << endl; }

Combined_C::~Combined_C() { cout << "Combined_C destructor." << endl; }

void Combined_C::function_1() const {
    cout << "Combined_C, function_1." << endl;
    a.function_1();
    Combined_B::function_1();
}

Combined_D::Combined_D(int ii) : Combined_B(ii), a2(ii) { cout << "Combined_D constructor." << endl; }

Combined_D::~Combined_D() { cout << "Combined_D destructor." << endl; }

Base_6::Base_6(int ii) { cout << "Base_6 constructor." << endl; }

Base_6::~Base_6() { cout << "Base_6 destructor." << endl; }

Member_6_1::Member_6_1(int ii) { cout << "Member_6_1 constructor." << endl; }

Member_6_1::~Member_6_1() { cout << "Member_6_1 destructor." << endl; }

Member_6_2::Member_6_2(int ii) { cout << "Member_6_2 constructor." << endl; }

Member_6_2::~Member_6_2() { cout << "Member_6_2 destructor." << endl; }

Derived_6_1::Derived_6_1(int ii) : Base_6(ii), m1(ii) { cout << "Derived_6_1 constructor." << endl; }

Derived_6_1::~Derived_6_1() { cout << "Derived_6_1 destructor." << endl; }

Derived_6_2::Derived_6_2(int ii) : Derived_6_1(ii), m2(ii) { cout << "Derived_6_2 constructor." << endl; }

Derived_6_2::~Derived_6_2() { cout << "Derived_6_2 destructor." << endl; }

Derived_6_3::Derived_6_3(int ii) : Derived_6_2(ii), m1(ii), m2(ii) { cout << "Derived_6_3 constructor." << endl; }

Derived_6_3::~Derived_6_3() { cout << "Derived_6_3 destructor." << endl; }

int Base_7::f() const {
    cout << "Base_7::f()." << endl;
    return 1;
}

int Base_7::f(std::string) const { return 1; }

int Base_7::h(int) {
    cout << "int Base_7::h(int)." << endl;
    return 5;
}

int Derived_7_1::h(int) {
    cout << "int Derived_7_1::h(int)." << endl;
    return 6;
}

int Derived_7_2::f() const {
    cout << "Derived_7_2::f()." << endl;
    return 2;
}

void Derived_7_3::f() const { cout << "Derived_7_3::f()." << endl; }

int Derived_7_4::f(int) const {
    cout << "Derived_7_4::f()." << endl;
    return 4;
}

StringStack::StringStack() {
    storage.clear();
}

void StringStack::push_back(std::string* string) {
    storage.push_back(string);
}

const std::string* StringStack::operator[](int index) const {
    return storage[index];
}

Class_14_10::Class_14_10(long i) { l = long(i); }

Asteroid::Asteroid() {
    cout << "Asteroid constructor." << endl;
}

Asteroid::~Asteroid() {
    cout << "Asteroid destructor." << endl;
}

PStash_14::PStash_14() : quantity(0), next(0), storage(0) {}

int PStash_14::add(void *element) {
    const int inflateSize = 10;
    if (next >= quantity) inflate(inflateSize);
    storage[next++] = element;
    return (next - 1);
}

PStash_14::~PStash_14() {
    for (int i = 0; i < next; i++)
        if (storage[i] != 0) cout << "PStash_14 not empty." << endl;
    delete []storage;
}

void* PStash_14::operator[](int index) const {
    if (index < 0 || index >= quantity) {
        cout << "PStash_14, operator[] index out of range.";
        return NULL;
    }
    return storage[index];
}

void* PStash_14::remove(int index) {
    void* r = operator[](index);
    if (r != NULL) storage[index] = 0;
    return r;
}

void PStash_14::inflate(int increase) {
    void** newStorage = new void*[quantity + increase];
    memset((void*)newStorage, 0, (quantity + increase)*sizeof(void*));
    memcpy((void*)newStorage, storage, quantity*sizeof(void*));
    quantity += increase;
    delete []storage;
    storage = newStorage;
}

int PStash_14::count() const {
    return next;
}

PStash_14_1::PStash_14_1() { cout << "PStash_14_1 constructor." << endl; }

int PStash_14_1::add(Asteroid *element) {
    return PStash_14::add((void*)element);
}

PStash_14_1::~PStash_14_1() { cout << "PStash_14_1 destructor." << endl; }

Asteroid* PStash_14_1::operator[](int index) const {
    return (Asteroid*)PStash_14::operator [](index);
}

Asteroid* PStash_14_1::remove(int index) {
    return (Asteroid*)PStash_14::remove(index);
}

int PStash_14_1::count() const {
    return PStash_14::count();
}

PStash_14_2::PStash_14_2() { cout << "PStash_14_2 constructor." << endl; }

int PStash_14_2::add(Asteroid *element) {
    return p.add((void*)element);
}

PStash_14_2::~PStash_14_2() { cout << "PStash_14_2 destructor." << endl; }

Asteroid* PStash_14_2::operator[](int index) const {
    return (Asteroid*)p.operator [](index);
}

Asteroid* PStash_14_2::remove(int index) {
    return (Asteroid*)p.remove(index);
}

int PStash_14_2::count() const {
    return p.count();
}

PStash_14_3::PStash_14_3() { cout << "PStash_14_3 constructor." << endl; }

int PStash_14_3::add(Asteroid *element) {
    this->push_back((void*)element);
    return this->size();
}

PStash_14_3::~PStash_14_3() { cout << "PStash_14_3 destructor." << endl; }

Asteroid* PStash_14_3::operator[](int index) const {
    return (Asteroid*)this->operator[](index);
}

Asteroid* PStash_14_3::remove(int index) {
    vector<void*>::iterator it = this->begin();
    for (int i = 0; i < index; i++) it++;
    Asteroid* r = (Asteroid*)*it;
    this->erase(it);
    return r;
}

int PStash_14_3::count() const {
    return this->size();
}

PStash_14_4::PStash_14_4() { cout << "PStash_14_4 constructor." << endl; }

int PStash_14_4::add(Asteroid *element) {
    v.push_back((void*)element);
    return v.size();
}

PStash_14_4::~PStash_14_4() { cout << "PStash_14_4 destructor." << endl; }

Asteroid* PStash_14_4::operator[](int index) const {
    return (Asteroid*)v.operator[](index);
}

Asteroid* PStash_14_4::remove(int index) {
    vector<void*>::iterator it = v.begin();
    for (int i = 0; i < index; i++) it++;
    Asteroid* r = (Asteroid*)*it;
    v.erase(it);
    return r;
}

int PStash_14_4::count() const {
    return v.size();
}

void Class_14_15_1::function_1() {
    cout << "Class_14_15_1, function 1." << endl;
}

void Class_14_15_1::function_2() {
    cout << "Class_14_15_1, function 2." << endl;
}

void Class_14_15_2::function_2() {
    cout << "Class_14_15_2, function 2." << endl;
}

GameBoard::GameBoard() { cout << "GameBoard constructor." << endl;}

GameBoard::GameBoard(const GameBoard&) { cout << "GameBoard copy constructor." << endl; }

GameBoard& GameBoard::operator=(const GameBoard&) {
    cout << "GameBoard, operator=" << endl;
    return *this;
}

GameBoard::~GameBoard() { cout << "GameBoard destructor." << endl; }

Game::Game() { cout << "Game constructor." << endl; }

Game::Game(const Game& g) { cout << "Game copy constructor." << endl; }

Game::Game(int) { cout << "Game constructor(int)." << endl; }

Game& Game::operator=(const Game& g) {
    gb = g.gb;
    cout << "Game operator=." << endl;
    return *this;
}

class Other {};

void function_14_13(Game::Other) {}

Game::operator Other() const {
    cout << "Game operator Other()." << endl;
    return Other();
}

Game::~Game() { cout << "Game destructor." << endl; }

Checkers::Checkers() { cout << "Checkers constructor." << endl; }

Checkers::Checkers(const Checkers& c) { cout << "Checkers copy constructor." << endl; }

Checkers& Checkers::operator=(const Checkers& c) {
    Game::operator =(c);
    cout << "Checkers operator=" << endl;
    return *this;
}

Chess::Chess() { cout << "Chess constructor." << endl; }

Chess::Chess(const Chess& c) {
    cout << "Chess copy constructod." << endl;
    Game::operator =(c);
}

Chess& Chess::operator=(const Chess& c) {
    cout << "Chess operator=." << endl;
    Game::operator =(c);
    return *this;
}

Traveler::Traveler(std::string s) : str(s) { cout << "Traveler costructor with s = " << s << endl; }

Pager::Pager(std::string s) : str(s) { cout << "Pager constructor with s = " << s << endl; }

Traveler::Traveler(const Traveler& r) {
    str = r.str;
    cout << "Traveler copy constructor with str=" << str << endl;
}

Traveler& Traveler::operator=(const Traveler& r) {
    str = r.str;
    cout << "Traveler operator= with str= " << str << endl;
    return *this;
}

Pager::Pager(const Pager& r) {
    str = r.str;
    cout << "Pager copy constructor with str=." << str << endl;
}

Pager& Pager::operator=(const Pager& r) {
    str = r.str;
    cout << "Pager operator= with str=" << str << endl;
    return *this;
}

BuisnessTraveler::BuisnessTraveler() : Traveler("buisness"), one("one pager") {
    cout << "Buisness traveler with default constructor." << endl;
}

BuisnessTraveler::BuisnessTraveler(std::string s) : Traveler(s), one(s) {
    cout << "Buisness traveler constructor with s=" << s << endl;
}

BuisnessTraveler::BuisnessTraveler(const BuisnessTraveler& r) : Traveler(r), one(r.one) {
    cout << "BuisnessTraveler copy constructor." << endl;
}

BuisnessTraveler& BuisnessTraveler::operator=(const BuisnessTraveler& r) {
    cout << "Buisness traveler operator=" << endl;
    ::Traveler::operator =(r);
    one.operator =(r.one);
}

void function_14_14(BuisnessTraveler v) {
    cout << "Function_14_14 has called." << endl;
}

FName::FName(const string fname) : std::fstream(), fileName(fname) {
    named = true;
}

std::string FName::name() const {
    return fileName;
}

void FName::name(std::string newName) {

}

void function_14_17(Class_14_17& c) {
    cout << "Integer from base Class_14_17 = " << c.i << endl;
}

Base_18::Base_18(int ii) : i(ii) {}

int Base_18::value(int m) const { return (i * m); }

int Base_18::read() const { return i; }

void Base_18::set(int ii) {}

Derived_18::Derived_18(int jj) : j(jj) {}

void Derived_18::change(int x) { set(x); }

int Derived_18::readvalue() const { return read(); }

void SpaceShip::fly() { cout << "SpaceShip::fly()." << endl; }

void Shuttle::land() { cout << "Shuttle::land()." << endl; }

void Instrument_14::play(int) const { cout << "Instrument_14, play." << endl; }

void Instrument_14::prepare() { cout << "Instrument_14, prepare." << endl; }

void function_14_21(Instrument_14& r) {
    r.prepare();
    r.play(1);
}

void Wind_14::play(int) const { cout << "Wind_14, play." << endl; }

Parent_14::Parent_14() { cout << "Parent_14 default constructor." << endl; }

Parent_14::Parent_14(int ii) : i(ii) { cout << "Parent_14 constructor i = " << i << "." << endl; }

Parent_14::Parent_14(Parent_14& p) : i (p.i) { cout << "Parent_14 copy constructor i = " << i << "." << endl; }

ostream& operator<<(ostream& os, const Parent_14& v) { return (os << "Parent_14::i = " << v.i << "." << endl); }

Member_14::Member_14(int ii) : i(ii) { cout << "Member_14 constructor i = " << i << "." << endl; }

Member_14::Member_14(const Member_14& p) : i(p.i) { cout << "Member_14 copy constructor. i = " << i << "." << endl; }

ostream& operator<<(std::ostream& os, const Member_14& v) { return (os << "Member_14::i = " << v.i << "," << endl); }

Child_14::Child_14(int ii) : i(ii), Parent_14(ii), m(ii) { cout << "Child_14 constructor i = " << i << "." << endl; }

Child_14::Child_14(const Child_14& c) : m(c.m) {
    i = c.i;
    cout << "Child_14 copy constructor i = " << i << "." << endl;
}

std::ostream& operator<<(std::ostream& os, const Child_14& v) { return (os << "Child_14::i = " << v.i << "." << endl); }

Toy_14::Toy_14(int ii) : i(ii), m(ii), Child_14(ii) { cout << "Toy_14 constructor i = " << i << "." << endl; }

Toy_14::Toy_14(const Toy_14& t) : Child_14(t.i), m(t.m) {
    i = t.i;
    cout << "Toy_14 copy constructor i = " << i << "." << endl;
}

Toy_14& Toy_14::operator=(const Toy_14& t) {
    i = t.i;
    cout << "Toy_14 operator = , i = " << i << "." << endl;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Toy_14& v) { cout << "Toy_14::i = " << v.i << "." << endl; }

void StringStack_14::push(std::string* str) {
    storage.push_back(str);
}

std::string* StringStack_14::pop() {
    if (storage.empty()) return NULL;
    string* r = storage[storage.size()-1];
    storage.pop_back();
    return r;
}

std::string* StringStack_14::peek(int index) {
    if (index >= storage.size() || index < 0) return NULL;
    return storage[index];
}

Rock::Rock() { cout << "Rock constructor." << endl; }

Rock::Rock(const Rock& r) { cout << "Rock copy constructor." << endl; }

Rock& Rock::operator=(const Rock& r) { cout << "Rock operator=." << endl; }

Rock::~Rock() { cout << "Rock destructor." << endl; }

void Subject::f() { cout << "Subject::f()." << endl; }

Widget_14::Widget_14() { cout << "Widget_14 constructor." << endl; }

Widget_14::~Widget_14() { cout << "Widget_14 destructor." << endl; }

void* Widget_14::operator new(size_t sz) {
    cout << "Widget_14 operator new, sz = " << sz << endl;
    return ::new char[sz];
}

void Widget_14::operator delete(void* p) {
    cout << "Widget_14 operator delete, p = " << (long)p << endl;
    ::delete [](char*)p;
}

void *Widget_14::operator new[](size_t sz) {
    cout << "Widget_14 operator new[], sz = " << sz << endl;
    return ::new char[sz];
}

void Widget_14::operator delete[](void* p) {
    cout << "Widget_14 operator delete[], p = " << (long)p << endl;
    ::delete [](char*)p;
}

Class_14_28::Class_14_28() { cout << "Class_14_28 constructor." << endl; }

Class_14_28::~Class_14_28() { cout << "Class_14_28 destructor." << endl; }

void* Class_14_28::operator new(size_t sz) {
    cout << "Class_14_28 operator new, sz = " << sz << endl;
    return (::Widget_14::operator new(sizeof(Class_14_28)));
}

void Class_14_28::operator delete(void* p) {
    cout << "Class_14_28 operator delete, p = " << (long)p << endl;
    ::delete((Class_14_28*)p);
}

void* Class_14_28::operator new[](size_t sz) {
    cout << "Class_14_28 operator new[], sz = " << sz << endl;
    return (::Widget_14::operator new(sz));
}

void Class_14_28::operator delete[](void* p) {
    cout << "Class_14_28 operator delete[], p = " << (long)p << endl;
    ::delete[]((Class_14_28*)p);
}

unsigned char Framis_14::pool[Framis_14::maxSz * sizeof(Framis_14)];

bool Framis_14::alloc_map[Framis_14::maxSz];

Framis_14::Framis_14() {
    cout << "Framis_14 constructor." << endl;
}

Framis_14::~Framis_14() {
    cout << "Framis_14 destructor." << endl;
}

void* Framis_14::operator new(size_t) {
    for (int i = 0; i < maxSz; i++)
        if (!alloc_map[i]) {
            cout << "Using block " << i << " from pool." << endl;
            alloc_map[i] = true;
            return pool + (i * sizeof(Framis_14));
        }
    cout << "Memory pool full." << endl;
    return NULL;
}

void Framis_14::operator delete(void* p) {
    if (!p) return;
    unsigned long block = (unsigned long)p - (unsigned long)pool;
    block /= sizeof(Framis_14);
    alloc_map[block] = false;
}

void* Class_14_29::operator new (size_t sz) {
    cout << "Class_14_29 operator new, sz = " << sz << endl;
    return new char[sz];
}

void Class_14_29::operator delete (void* p) {
    cout << "Class_14_29 operator delete. p = " << (unsigned long)p << endl;
    ::delete (Class_14_29*)p;
}


void chapter_14() {
    cout << "Chapter's 14 tasks.\n";
    // Task 1.
    Car_14 cl1(1);
    // Task 2.
    Class_14_2_3 cl2;
    // Task 3.
    Class_14_3_3 cl3;
    // Task 4-5.
    Combined_D cl4(3);
    // Task 6.
    Derived_6_3 cl6(1);
    // Task 7-8.
    string s7 = "Task7";
    Derived_7_1 cl7_1;
    int i7 = cl7_1.f();
    Derived_7_2 cl7_2;
    // no matching for call to 'Derived_7_2::f(std::string&'
    // cl7_2.f(s7);
    Derived_7_3 cl7_3;
    // note: candidate expects 0 arguments, 1 provided
    // i7 = cl7_3.f();
    Derived_7_4 cl7_4;
    i7 = cl7_4.f(1);
    cl7_1.h(1);
    // Task 9. invalid conversation. Task not clear.
    StringStack cl9;
    void* ptr = (void*)&s7;
    cl9.push_back(&s7);
    // cl9.push_back(ptr);
    // Task 10 see in .h, .cpp file.
    // Task 11.
    PStash_14_1 cl11;
    PStash_14_2 cl11_2;
    cout << "Testing task 11.\n";
    for (int i = 0; i < 3; i++) {
        cl11.add(new Asteroid);
        cl11_2.add(new Asteroid);
    }
    for (int i = 0; i < 3; i++) {
        cl11.remove(i);
        cl11_2.remove(i);
    }
    // Task 12.
    cout << "Testing task 12 with vector.\n";
    PStash_14_3 cl12_1;
    PStash_14_4 cl12_2;
    for (int i = 0; i < 3; i++) {
        cl12_1.add(new Asteroid);
        cl12_2.add(new Asteroid);
    }
    // Task 13.
    cout << "Task 13.\n";
    Chess cl13_1;
    Chess cl13_2(cl13_1);
//    Chess cl13_3(1);
    cl13_1 = cl13_2;
    function_14_13(cl13_1);
    Game::Other cl13_sub;
//    cl13_1 = cl13_sub;
    Checkers cl13_4, cl13_5(cl13_4);
    cl13_4 = cl13_5;
    // Task 14.
    BuisnessTraveler cl14_1("one"), cl14_2("two");
    cl14_1 = cl14_2;
    function_14_14(cl14_1);
    // Task 15.
    cout << "Static functions.\n";
    Class_14_15_2::function_1();
    Class_14_15_2::function_2();
    // Task 16.
    FName cl16("labs_0x01/files/chapter-14.txt");
    cl16.open(cl16.name().c_str());
    cout << "Task 16, file name : " << cl16.name() << endl;
    string str16;
    getline(cl16, str16, '\0');
    cout << "String from file: " << str16 << endl;
    cl16.close();
    // Task 17
    Class_14_17_1 cl17_1(1);
    Class_14_17_2 cl17_2(2);
    // 'Class_14_17' is an inaccessible base of 'Class_14_17_1'
    // function_14_17(cl17_1);
    // function_14_17(cl17_2);
    // Task 18-19.
    Derived_18 cl18(1);
    cout << "Derived_18, readvalue = " << cl18.readvalue() << endl;
    // 'int Base_18::value(int) const' is inaccessible
    // cl18.value(3);
    // Task 20. 'class SpaceShip' has no member named 'land'
    Shuttle cl20;
    SpaceShip* ptrS = &cl20;
    // ptrS->land();
    // Task 21-22.
    Wind_14 cl21_1;
    function_14_21(cl21_1);
    // Task 23-24.
    Child_14 cl23_1(3);
    cout << "Operator << test : " << cl23_1;
    Child_14 cl23_2 = cl23_1;
    Toy_14 cl23_3(1);
    Toy_14 cl23_4 = cl23_3;
    cl23_4 = cl23_3;
    // Task 25.
    StringStack_14 cl25;
    string str25_1 = "string 1";
    string str25_2 = "string 2";
    cl25.push(&str25_1);
    cl25.push(&str25_2);
    cout << "StringStack contains : " << *cl25.peek(0) << " " << *cl25.pop() << endl;
    // Task 26. Not possible for reference.
    vector<Rock*> vec_26;
    Rock cl26_1, cl26_2;
    vec_26.reserve(2);
    vec_26.push_back(&cl26_1);
    vec_26.push_back(&cl26_2);
    // Task 27. Rethink...
    Subject cl27_1;
    Proxy cl27_2(&cl27_1);
    cl27_2.f();
    // Task 28. Not clear... Maybe fixed size in original example was wrong.
    Widget_14* ptr28_1 = new Widget_14;
    Widget_14* ptr28_2 = new Widget_14[2];
    delete ptr28_1;
    delete []ptr28_2;
    Class_14_28* cl28_1 = new Class_14_28;
    delete cl28_1;
    // Task 29.
    Class_14_29* cl29 = new Class_14_29;
    delete cl29;
}
