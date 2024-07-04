#include "24_Runtime_Type_Identification.hpp"

using namespace std;

Base::Base() { cout << "Base::Base()" << endl; }

Base::~Base() { cout << "Base::~Base()" << endl; }

Derived::Derived::Derived() { cout << "Derived::Derived()" << endl; }

Derived::~Derived() { cout << "Derived::~Derived()" << endl; }

template<class T> int AutoCounterA<T>::count = 0;

template<class T> std::map<std::string,int> AutoCounterA<T>::cleanupCheck;

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

#ifndef DANGER_CODE

Pet_A::Pet_A() { cout << "Pet_A::Pet_A()" << endl; }

Pet_A::~Pet_A() { cout << "Pet_A::~Pet_A()" << endl; }

void Pet_A::eat(Food& v) { cout << "Pet_A::eat()" << endl; }

Dog_A::Dog_A() { cout << "Dog_A::Dog_A()" << endl; }

Dog_A::~Dog_A() { cout << "Dog_A::~Dog_A()" << endl; }

void Dog_A::eat(Beef& v) { cout << "Dog_A::eat()" << endl; }

Cat_A::Cat_A() { cout << "Cat_A::Cat_A()" << endl; }

Cat_A::~Cat_A() { cout << "Cat_A::~Cat_A()" << endl; }

void Cat_A::eat(Fish& v) { cout << "Cat_A::eat()" << endl; }

Horse::Horse() { cout << "Horse::Horse()" << endl; }

Horse::~Horse() { cout << "Horse::~Horse()" << endl; }

void Horse::eat(Oats& v) { cout << "Horse::eat()" << endl; }

#endif  // DANGER_CODE

void drawQuad(Shape_2* v) {
    string className = typeid(*v).name();
    if ( className.find("Square") != string::npos || className.find("Rectangle") != string::npos ) v->draw(); else
        cout << "Shape object not a Square or Rectangle." << endl;
}

bool lessShapeType(const Shape_2* lv, const Shape_2* rv) {
    return ( typeid(*lv).before(typeid(*rv)) );
}

void chapter_24() {
    cout << "Chapter's 8 tasks.\n";
    // Task 1. Testing both variants...
    vector<Base*> vector_1;
    vector<Derived*> vector_2;
    for (int i = 0; i < 5; i++)
        if ( i % 2 ) vector_1.push_back(new Base); else vector_1.push_back(new Derived);
    cout << "All types in vector_1:\n";
    for (int i = 0; i < vector_1.size(); i++) {
        string typeN(typeid(*vector_1[i]).name());
        cout << i << ": " << typeN << endl;
        if ( typeN.find("Derived") != string::npos) {
            Derived* dPtr = dynamic_cast<Derived*>(vector_1[i]);
            vector_2.push_back(dPtr);
        }
    }
    cout << "All types in vector_2:\n";
    for (int i = 0; i < vector_2.size(); i++) cout << typeid(*vector_2[i]).name() << endl;
    // Tasks 2-3. Just works fine.
    vector<Class_2*> vector_3;
    vector<Class_3*> vector_4;
    for (int i = 0; i < 3; i++) {
        vector_3.push_back(new Class_2());
        vector_4.push_back(new Class_3());
    }
    vector_3[0]->debug.trace();
    vector_4[1]->debug.trace();
    vector_3[0]->debug.verify();
    vector_4[1]->debug.verify();
    for (int i = 0; i < vector_3.size(); i++) {
        delete(vector_3[i]);
        delete(vector_4[i]);
    }
    // Tasks 4-5.
    vector<Instrument*> vector_5;
    vector_5.push_back(new Wind);
    vector_5.push_back(new Stringed);
    vector_5.push_back(new Instrument);
    for (int i = 0; i < vector_5.size(); i++) vector_5[i]->prepare();
    // Task 6-7. Virtual calls more convinient here.
    vector<Shape_2*> vector_6, vector_7;
    for (int i = 0; i < 10; i++)
        switch (rand() % 3) {
        case 0:
            vector_6.push_back(new Circle_2);
            break;
        case 1:
            vector_6.push_back(new Triangle_2);
            break;
        case 2:
            vector_6.push_back(new Square_2);
            break;
        default:
            break;
        }
    cout << "Sorting vector with Circles.\n";
    vector<Circle_2*> vector_8;
    vector<Square_2*> vector_9;
    for (int i = 0; i < vector_6.size(); i++) {
        string className = typeid(*vector_6[i]).name();
        if ( className.find("Circle") !=  string::npos ) vector_8.push_back(dynamic_cast<Circle_2*>(vector_6[i])); else
            if ( className.find("Square") != string::npos ) vector_9.push_back(dynamic_cast<Square_2*>(vector_6[i]));
    }
    sort(vector_8.begin(), vector_8.end(), greaterRadius);
    sort(vector_9.begin(), vector_9.end(), greaterPerimeter);
    for (int i = 0; i < vector_8.size(); i++) vector_8[i]->altDraw();
    cout << "Sorting vector with Squares.\n";
    for (int i = 0; i < vector_9.size(); i++) vector_9[i]->altDraw();
    vector_7 = vector_6;
    for (int i = 0; i < vector_7.size(); i++)
        vector_7[vector_7.size() - 1]->altDraw();
#ifndef DANGER_CODE
    // Task 8. Not so intresting...
    cout << "Stack of calls in vector with 'Pets*'.\n";
    vector<Pet_A*> vector_10;
    for (int i = 0; i < 10; i++)
        switch (rand() % 3) {
        case 0:
            vector_10.push_back(new Dog_A);
            break;
        case 1:
            vector_10.push_back(new Cat_A);
            break;
        case 2:
            vector_10.push_back(new Horse);
            break;
        default:
            break;
        }
    cout << "Calling all virtual functions 'eat' for the classes Dog_A, Cat and Horse.\n";

    Beef food_1;
    Fish food_2;
    Oats food_3;
    for (int i = 0; i < vector_10.size(); i++) {
        string className = typeid(*vector_10[i]).name();
        if ( className.find("Dog_A") != string::npos ) dynamic_cast<Dog_A*>(vector_10[i])->eat(food_1); else
            if ( className.find("Cat_A") != string::npos ) dynamic_cast<Cat_A*>(vector_10[i])->eat(food_2); else
                if ( className.find("Horse") != string::npos ) dynamic_cast<Horse*>(vector_10[i])->eat(food_3);
    }
#endif  // DANGER_CODE
    // Task 9-10.
    vector<Shape_2*> vector_11;
    for (int i = 0; i < 12; i++) {
        switch (rand() % 4) {
        case 0:
            vector_11.push_back(new Circle_2);
            break;
        case 1:
            vector_11.push_back(new Triangle_2);
            break;
        case 2:
            vector_11.push_back(new Square_2);
            break;
        case 3:
            vector_11.push_back(new Rectangle_2);
            break;
        default:
            break;
        }
    }
    for_each(vector_11.begin(), vector_11.end(), drawQuad);
    cout << "After sorting vector<Shape*> with type_info::before().\n";
    sort(vector_11.begin(), vector_11.end(), lessShapeType);
    for_each(vector_11.begin(), vector_11.end(), drawQuad);
}
