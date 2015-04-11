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
