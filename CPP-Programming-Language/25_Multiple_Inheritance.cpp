#include "25_Multiple_Inheritance.hpp"

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

void chapter_25() {
    cout << "Chapter's 9 tasks.\n";
    // Tasks 1-2. Works only in .cpp, specified namespace.
    Class_A cl_1;
    cl_1.Class_Y::function();
    Class_A* ptr_1 = &cl_1;
    // Task 3. May be with the old version of compiler, it was possible to trace, but now it's error 'ambigous'.
    ptr_1->Class_Y::function();
    // Task 4-7.
#ifndef DANGER_CODE
    Bat cl_2(1);
    Tarantool cl_3(2);
    FatCat cl_4(3);
    noisy(&cl_3);
    noisy(&cl_4);
    move(&cl_3, &cl_4);
    save(&cl_2, new Train, new Car);
    // Task 8-9. Work fine with current hierarchy of classes.
    save(&cl_4, new Train, new Car);
    // Task 10. Both variants works fine.
    FunnyFatCat cl_5(4), cl_6(5);
    cl_5.Bat::eat(5);
    cl_5.eat('a');
    // Task 11-12.
    cl_6 = cl_5;
    cout << cl_6;
    cl_4.workout();
    // Task 13. Works fine, except calling virtual method.
    SuperCat* cl_7_ptr = new SuperCat(6);
    FatCat* ptr_2 = (FatCat*)(cl_7_ptr);
    cout << "Using dangerous convertion from SuperCat class to FatCat.\n";
    ptr_2->move();
    ptr_2->noise();
    ptr_2->eat('a');
    // Task 14. Not working as described, maybe too old, simply add another layer of absctraction.
    cout << "\nUsing class HuntingCat.\n";
    HuntingCat cl_8(7);
    cl_8.work();
#endif  // DANGER_CODE
    // Task 15. Works, but very strange scheme of task.
    Class_15 cl_9;
    for (int i = 0; i < 3; i++) cl_9.create();
    // Task 16. Ok, 'using' works correctly.
    Class_16_3 cl_10;
    cl_10.function();
    Class_16_4 cl_11;
    cl_11.function();
}
