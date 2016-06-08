#include "chapter_08.h"

using namespace std;

Base::Base() { cout << "Base::Base()" << endl; }

Base::~Base() { cout << "Base::~Base()" << endl; }

Derived::Derived::Derived() { cout << "Derived::Derived()" << endl; }

Derived::~Derived() { cout << "Derived::~Derived()" << endl; }

template<class T> int AutoCounter<T>::count = 0;

template<class T> std::map<std::string,int> AutoCounter<T>::cleanupCheck;

Class_2::Class_2() { cout << "Class_2::Class_2()" << endl; }

Class_2::~Class_2() { cout << "Class_2::~Class_2()" << endl; }

Class_3::Class_3() { cout << "Class_3::Class_3()" << endl; }

Class_3::~Class_3() { cout << "Class_3::~Class_3()" << endl; }

void Instrument::prepare() {
    string className = typeid(*this).name();
    if ( className.find("Wind") != string::npos ) ((Wind*)this)->clearValve(); else
        cout << "Instrument or Stringed class, method 'clear'." << endl;
}

void Wind::clearValve() { cout << "Wind::clearValve()" << endl; }

Pet::Pet() { cout << "Pet::Pet()" << endl; }

Pet::~Pet() { cout << "Pet::~Pet()" << endl; }

void Pet::eat(Food& v) { cout << "Pet::eat()" << endl; }

Dog::Dog() { cout << "Dog::Dog()" << endl; }

Dog::~Dog() { cout << "Dog::~Dog()" << endl; }

void Dog::eat(Beef& v) { cout << "Dog::eat()" << endl; }

Cat::Cat() { cout << "Cat::Cat()" << endl; }

Cat::~Cat() { cout << "Cat::~Cat()" << endl; }

void Cat::eat(Fish& v) { cout << "Cat::eat()" << endl; }

Horse::Horse() { cout << "Horse::Horse()" << endl; }

Horse::~Horse() { cout << "Horse::~Horse()" << endl; }

void Horse::eat(Oats& v) { cout << "Horse::eat()" << endl; }

void drawQuad(Shape* v) {
    string className = typeid(*v).name();
    if ( className.find("Square") != string::npos || className.find("Rectangle") != string::npos ) v->draw(); else
        cout << "Shape object not a Square or Rectangle." << endl;
}

bool lessShapeType(const Shape* lv, const Shape* rv) {
    return ( typeid(*lv).before(typeid(*rv)) );
}
