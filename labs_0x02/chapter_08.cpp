#include "chapter_08.h"

using namespace std;

Base::Base() { cout << "Base::Base()" << endl; }

Base::~Base() { cout << "Base::~Base()" << endl; }

Derived::Derived::Derived() { cout << "Derived::Derived()" << endl; }

Derived::~Derived() { cout << "Derived::~Derived()" << endl; }

Class_2::Class_2() { cout << "Class_2::Class_2()" << endl; }

Class_2::~Class_2() { cout << "Class_2::~Class_2()" << endl; }
