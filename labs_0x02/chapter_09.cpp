#include "chapter_09.h"

using namespace std;

Animal::~Animal() { cout << "Animal::~Animal()" << endl; }

Hero::~Hero() { cout << "Hero::~Hero()" << endl; }

Bat::Bat() { cout << "Bat::Bat()" << endl; }

void Bat::save() { cout << "Bat::save()" << endl; }

void Bat::move() { cout << "Bat::move()" << endl; }

Tarantool::Tarantool() { cout << "Tarantool::Tarantoll()" << endl; }

void Tarantool::noise() { cout << "Tarantool::noise()" << endl; }

void Tarantool::save() { cout << "Tarantool::save()" << endl; }

void Tarantool::move() { cout << "Tarantool::move()" << endl; }

FatCat::FatCat() { cout << "FatCat::FatCat()" << endl; }

void FatCat::noise() { cout << "FatCat::noise()" << endl; }

void FatCat::save() { cout << "FatCat::save()" << endl; }

void FatCat::move() { cout << "FatCat::move()" << endl; }

void noisy(Animal* ptr) {
    ptr->move();
    ptr->noise();
}

void saves(Hero* ptr) {
    ptr->move();
    ptr->save();
}
