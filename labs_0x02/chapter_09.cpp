#include "chapter_09.h"

using namespace std;

Animal::~Animal() { cout << "Animal::~Animal()" << endl; }

#ifndef DANGER_CODE

HuntingCat::HuntingCat(int i) : Hero(i), s(i) { cout << "HuntingCat::HuntingCat(" << i << ")" << endl; }

HuntingCat::~HuntingCat() { cout << "HuntingCat::~HuntingCat(" << s << ")" << endl; }

void HuntingCat::work() { cout << "HuntingCat::work(" << s << ")" << endl; }

void HuntingCat::save() {}

void HuntingCat::move() {}

Hero::Hero(int s) : str(s) { cout << "Hero::Hero(" << s << ")" << endl; }

Hero::~Hero() { cout << "Hero::~Hero()" << endl; }

void Hero::workout() { cout << "Hero::workout()" << endl; }

void Hero::work() { cout << "Hero::work(" << str << ")" << endl; }

Bat::Bat(int i) : Hero (i) { cout << "Bat::Bat(" << i << ")" << endl; }

void Bat::save() { cout << "Bat::save()" << endl; }

void Bat::move() { cout << "Bat::move()" << endl; }

void Bat::eat(int v) { cout << "Bat::eat(" << v << ")" << endl; }

void Bat::workout() { cout << "Bat::workout()" << endl; }

Tarantool::Tarantool(int i) : Hero(i) { cout << "Tarantool::Tarantoll()" << endl; }

void Tarantool::noise() { cout << "Tarantool::noise()" << endl; }

void Tarantool::save() { cout << "Tarantool::save()" << endl; }

void Tarantool::move() { cout << "Tarantool::move()" << endl; }

FatCat::FatCat(int i) : Hero(i), Bat(i) { cout << "FatCat::FatCat(" << i << ")" << endl; }

void FatCat::noise() { cout << "FatCat::noise()" << endl; }

void FatCat::save() { cout << "FatCat::save()" << endl; }

void FatCat::move() { cout << "FatCat::move()" << endl; }

void FatCat::eat(char c) { cout << "FatCat::eat(" << c << ")"; }

SuperCat::SuperCat(int i) : h(10), fc(20) { cout << "SuperCat::SuperCat(" << i << ")" << endl; }

FunnyFatCat::FunnyFatCat(int i) : FatCat(i), Bat(i), Hero(i) { cout << "FunnyFatCat::FunnyFatCat(" << i << ")" << endl; }

FunnyFatCat& FunnyFatCat::operator=(const FunnyFatCat& rv) {
    cout << "FunnyFatCat::operator=()" << endl;
    this->FatCat::Bat::str = rv.FatCat::Bat::str;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const FunnyFatCat& rv) {
    return os << "FunnyFatCat, id " << rv.FatCat::Bat::str << endl;
}

#endif // DANGER_CODE

void Train::stopTrain() { cout << "Train::stopTrain()" << endl; }

void Car::rideCar() { cout << "Car::rideCar()" << endl; }

int Counter::globalCount = 0;

std::fstream Counter::log;

Counter::Counter(string name) {
    log.open("labs_0x02/files/chapter-9.txt", ios::trunc | ios::out);
    count = 0;
    log << "Class '" << name << "', counter = " << count << ", global counter = " << globalCount << endl;
}

Counter::~Counter() {
    cout << "Counter::~Counter()" << endl;
    log.close();
}

int Counter::attach(std::string name) {
    ++count;
    log << "Counter::attach(), count = " << count << endl;
    return count;
}

int Counter::detach() {
    log << "Counter::detach(), counter = " << --count << endl;
    if (count == 0) log << "No more objects in counter." << endl; else
        log << "Some objects remains attached." << endl;
    return count;
}

Class_15::Class_15() : Counter("Class_15") {
    cout << "Class_15::Class_15()" << endl;
}

Class_15::~Class_15() {
    cout << "Class_15::~Class_15()" << endl;
    detach();
}

void Class_15::create() {
    attach("Class_15");
}

Class_16::~Class_16() { cout << "Class_16::~Class_16()" << endl; }

void Class_16_1::function() { cout << "Class_16_1::function()" << endl; }

void Class_16_2::function() { cout << "Class_16_2::function()" << endl; }

