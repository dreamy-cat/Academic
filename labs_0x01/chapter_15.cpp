#include "chapter_15.h"

using namespace std;

Shape_1::Shape_1() {
    cout << "Shape_1::Shape_1()." << endl;
// undefined reference to 'Shape_1::draw()'
// pure virtual 'virtual void Shape_1::Shape_1
// draw();
}

void Shape_1::draw() { cout << "Shape_1::draw()." << endl; }

void Circle_1::draw() { cout << "Circle_1::draw()." << endl; }

void Square_1::draw() { cout << "Square_1::draw()." << endl; }

void Triangle_1::draw() { cout << "Triangle_1::draw()." << endl; }

void function_15_1 (Shape_1 &shp)  {
    shp.draw();
}

void Class_15_B::f() const {
    cout << "virtual void Class_15_B::f()." << endl;
}

void Class_15_C::f() const {
    a.f();
    Class_15_B::f();
}

void Instrument_5::play(int note) const { cout << "Instrument_5::play(), note = " << note << endl; }

void Instrument_5::prepare() const { cout << "Instrument_5::prepare()." << endl; }

void Wind_5::play(int note) const { cout << "Wind::play(), note = " << note << endl; }

void function_15_5(Instrument_5 &i) {
    i.prepare();
    i.play(5);
}

// Pure virtual.
Rodent::~Rodent() { cout << "Rodent::~Rodent()." << endl; }

Mouse::~Mouse() { cout << "Mouse::~Mouse()." << endl; }

void Mouse::run() { cout << "Mouse::run()." << endl; }

void Mouse::eat() { cout << "Mouse::eat()." << endl; }

Gerbil::~Gerbil() { cout << "Gerbil::~Gerbil()." << endl; }

void Gerbil::run() { cout << "Gerbil::run()." << endl; }

void Gerbil::eat() { cout << "Gerbil::eat()." << endl; }

Hamster::~Hamster() { cout << "Hamster::~Hamster()." << endl; }

void Hamster::run() { cout << "Hamster::run()." << endl; }

void Hamster::eat() { cout << "Hamster::eat()." << endl; }

void BlueHamster::run() { cout << "BlueHamster::run()." << endl; }

void BlueHamster::eat() { cout << "BlueHamster::eat()." << endl; }

void Aircraft_A::takeoff() { cout << "Aircraft_A::takeoff()." << endl; }

void Aircraft_A::toland() { cout << "Aircraft_A::toland()." << endl; }

void Aircraft_B::takeoff() { cout << "Aircraft_B::takeoff()." << endl; }

void Aircraft_B::toland() { cout << "Aircraft_B::toland()." << endl; }

Tower::Tower(int units) {
    cout << "Tower::Tower(" << units << ")" << endl;
    for (int i = 0; i < units; i++) {
        storage.push_back(new Aircraft_A);
        storage.push_back(new Aircraft_B);
    }
}

Tower::~Tower() {
    cout << "Tower::~Tower()."  << endl;
    while (!storage.empty()) {
        delete storage[storage.size()-1];
        storage.pop_back();
    }
}

void Tower::open() {
    cout << "Tower::open()." << endl;
    for (int i = 0; i < storage.size(); i++) storage[i]->takeoff();
}

void Tower::close() {
    cout << "Tower::close()." << endl;
    for (int i = 0; i < storage.size(); i++) storage[i]->toland();
}

void Cactus::seat() { cout << "Cactus::seat()." << endl; }

void Cactus::fertilize() { cout << "Cactus::fertilize()." << endl; }

void Flower::seat() { cout << "Flower::seat()." << endl; }

void Flower::fertilize() { cout << "Flower::fertilize()." << endl; }

Pet::Pet(const string& name) : pname(name) {}

string Pet::name() const { return pname; }

Dog::Dog(string name) : Pet(name) {}

string Dog::speak() const { return string("Dog::speak()."); }

string Dog::name() const { return Pet::name(); }

void Class_15_14::function_1() { cout << "Class_15_14::function_1()." << endl; }

Class_15_14::Class_15_14() {
    cout << "Class_15_14::Class_15_14()." << endl;
    function_1();
}

Class_15_14_1::Class_15_14_1() { cout << "Class_15_14_1::Class_15_14_1()." << endl; }

void Class_15_14_1::function_1() { cout << "Class_15_14_1::function_1()." << endl; }

void Class_15_14_1::function_2() {
    cout << "Class_15_14_1::function_2()." << endl;
    function_1();
}

Base_15::~Base_15() {
    cout << "Base_15::~Base_15()." << endl;
    function();
}

void Base_15::function() { cout << "Base_15::function()." << endl; }


Derived_15_1::~Derived_15_1() {
    cout << "Derived_15_1::~Derived_15_1()." << endl;
    function();
}

void Derived_15_1::function() { cout << "Derived_15_1::function()." << endl; }


Derived_15_2::~Derived_15_2() {
    cout << "Derived_15_2::~Derived_15_2()." << endl;
    function();
}

void Derived_15_2::function() { cout << "Derived_15_2::function()." << endl; }

void function_15_18(Base_18_1 obj) { cout << "Sizeof(Base_18) = " << sizeof(obj) << endl; }


// Task 19.
/*

387 0215 488B45F8 		movq	-8(%rbp), %rax
388 0219 488B00   		movq	(%rax), %rax
389 021c 488B00   		movq	(%rax), %rax
390 021f 488B55F8 		movq	-8(%rbp), %rdx
391 0223 BE050000 		movl	$5, %esi
391      00
392 0228 4889D7   		movq	%rdx, %rdi
393 022b FFD0     		call	*%rax

*/

void Class_15_20_1::function_1() {
    // Perfomance test.
    int a = 0, b = 0;
    int c = a + b;
    c *= 1;
}

void Class_15_20::function_2() {
    // Perfomance test.
    int a = 0, b = 0;
    int c = a + b;
    c *= 1;
}

Base_15_21::Base_15_21() { cout << "Base_15_21::Base_15_21()." << endl; }

Base_15_21::~Base_15_21() { cout << "Base_15_21::~Base_15_21()." << endl; }

Member_15_21_1::Member_15_21_1() { cout << "Member_15_21_1::Member_15_21_1()." << endl; }

Member_15_21_1::~Member_15_21_1() { cout << "Member_15_21_1::~Member_15_21_1()." << endl; }

Member_15_21_2::Member_15_21_2() { cout << "Member_15_21_2::Member_15_21_2()." << endl; }

Member_15_21_2::~Member_15_21_2() { cout << "Member_15_21_2::~Member_15_21_2()." << endl; }

Derived_15_21_1::Derived_15_21_1() { cout << "Derived_15_21_1::Derived_15_21_1(int id)." << endl; }

Derived_15_21_1::~Derived_15_21_1() { cout << "Derived_15_21_1::~Derived_15_21_1(int id)." << endl; }

Derived_15_21_2::Derived_15_21_2() { cout << "Derived_15_21_2::Derived_15_21_2(int id)." << endl; }

Derived_15_21_2::~Derived_15_21_2() { cout << "Derived_15_21_2::~Derived_15_21_2(int id)." << endl; }

void Derived_15_21_1::function() { cout << "Derived_15_21_1::function()." << endl; }

void Derived_15_21_2::function() { cout << "Derived_15_21_2::function()." << endl; }

void Class_15_22::function(int i) { cout << "Class_15_22::function(int)." << endl; }

void Class_15_22::function(char c) { cout << "Class_15_22::function(char)." << endl; }

void Class_15_22::function(float f) { cout << "Class_15_22::function(float)." << endl; }

void Class_15_22_1::function(char) { cout << "Class_15_22_1::function(char)." << endl; }

std::string Bird_15::type() const { return "Bird"; }

std::string Bird_15::BirdFood_15::foodType() const { return "Bird food"; }

PetFood_15* Bird_15::eats() { return &bf; }

PetFood_15& Bird_15::eats(bool f) { return bf; }

std::string Cat_15::type() const { return "Cat"; }

std::string Cat_15::CatFood_15::foodType() const { return "Cat food"; }

Cat_15::CatFood_15* Cat_15::eats() { return &cf; }

Cat_15::CatFood_15& Cat_15::eats(bool f) { return cf; }
