#include "15_Polymorphism_and_Virtual_Functions.hpp"

using namespace std;

Shape_1::Shape_1() {
    cout << "Shape_1::Shape_1()." << endl;
// undefined reference to 'Shape_1::draw()'
// pure virtual 'virtual void Shape_1::Shape_1
// draw();
}

Shape_1::~Shape_1() {
    cout << "Shape_1 destructor" << endl;
}

Circle_1::~Circle_1() {
    cout << "Circle_1 destructor" << endl;
}

Square_1::~Square_1() {
    cout << "Square_1 destructor" << endl;
}

Triangle_1::~Triangle_1() {
    cout << "Triangle_1 destructor" << endl;
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

std::string Pet_15_24::speak() const { return "Pet_15_24::speak()."; }

std::string Dog_15_24::speak() const { return "Dog_15_24::speak()."; }

Base_15_25& Base_15_25::clone() {
    cout << "Base_15_25::clone()" << endl;
    Base_15_25* copy = new Base_15_25;
    return *copy;
}

Derived_15_25_1& Derived_15_25_1::clone() {
    cout << "Derived_15_25_1::clone()" << endl;
    // Works fine.
    // Base_15_25* copy = new Base_15_25;
    Derived_15_25_1* copy = new Derived_15_25_1;
    return *copy;
}

Derived_15_25_2& Derived_15_25_2::clone() {
    cout << "Derived_15_25_2::clone()" << endl;
    Derived_15_25_2* copy = new Derived_15_25_2;
    return *copy;
}

void Base_15_25::print() const { cout << "Base_15_25::print()" << endl; }

void Derived_15_25_1::print() const { cout << "Derived_15_25_1::print()." << endl; }

void Derived_15_25_2::print() const { cout << "Derived_15_25_2::print()." << endl; }

Object_15::~Object_15() { cout << "Object_15::~Object_15()" << endl; }

Stack_15::Link::Link(Object_15* dat, Link* nxt) : data(dat), next(nxt) {}

Stack_15::Stack_15() : head(0) {}

Stack_15::~Stack_15() {
    while (head) delete pop();
}

void Stack_15::push(Object_15* dat) {
    head = new Link(dat, head);
}

Object_15* Stack_15::peek() const {
    if (head) return head->data; else return 0;
}

Object_15* Stack_15::pop() {
    if (head == 0) return 0;
    Object_15* result = head->data;
    Link* oldHead = head;
    head = head->next;
    delete oldHead;
    return result;
}

Class_15_26_1::Class_15_26_1(int ii) : Class_15_26(ii) {}

Class_15_26_1::~Class_15_26_1() {}

Math::~Math() {}

Math& Matrix::operator*(Math& rv) { return rv.multiply(this); }

Math& Matrix::multiply(Matrix*) {
    cout << "Matrix * Matrix" << endl;
    return *this;
}

Math& Matrix::multiply(Scalar*) {
    cout << "Scalar * Matrix" << endl;
    return *this;
}

Math& Matrix::multiply(Vector*) {
    cout << "Vector * Matrix" << endl;
    return *this;
}

Math& Matrix::multiply(Tensor*) {
    cout << "Tensor * Matrix" << endl;
    return *this;
}

Math& Scalar::operator*(Math& rv) { return rv.multiply(this); }

Math& Scalar::multiply(Matrix*) {
    cout << "Matrix * Scalar" << endl;
    return *this;
}

Math& Scalar::multiply(Scalar*) {
    cout << "Scalar * Scalar" << endl;
    return *this;
}

Math& Scalar::multiply(Vector*) {
    cout << "Vector * Scalar" << endl;
    return *this;
}

Math& Scalar::multiply(Tensor*) {
    cout << "Tensor * Scalar" << endl;
    return *this;
}

Math& Vector::operator*(Math& rv) { return rv.multiply(this); }

Math& Vector::multiply(Matrix*) {
    cout << "Matrix * Vector" << endl;
    return *this;
}

Math& Vector::multiply(Scalar*) {
    cout << "Scalar * Vector" << endl;
    return *this;
}

Math& Vector::multiply(Vector*) {
    cout << "Vector * Vector" << endl;
    return *this;
}

Math& Vector::multiply(Tensor*) {
    cout << "Tensor * Vector" << endl;
    return *this;
}

Math& Tensor::operator*(Math& rv) { return rv.multiply(this); }

Math& Tensor::multiply(Matrix*) {
    cout << "Matrix * Tensor" << endl;
    return *this;
}

Math& Tensor::multiply(Scalar*) {
    cout << "Scalar * Tensor" << endl;
    return *this;
}

Math& Tensor::multiply(Vector*) {
    cout << "Vector * Tensor" << endl;
    return *this;
}

Math& Tensor::multiply(Tensor*) {
    cout << "Tensor * Tensor" << endl;
    return *this;
}

Class_15_28::Class_15_28() {
    function();
}
void Class_15_28::function() { cout << "Class_15_28::function()." << endl; }

Class_15_28_1::Class_15_28_1() {}

void Class_15_28_1::function() { cout << "Class_15_28_1::function()." << endl; }

void Class_15_30::function() { cout << "Class_15_30::function()." << endl; }

void Class_15_30_1::function() { cout << "Class_15_30_1::function()." << endl; }

void function_15_30(Class_15_30 cl) {
    cout << "function_15_30()" << endl;
    cl.function();
}

void Instrument_34::play(int note) const { cout << "Instrument_34::play()" << endl; }

string Instrument_34::what() const { return "Instrument_34"; }

void Instrument_34::adjust(int) {}

void Wind_34::play(int note) const { cout << "Wind_34::play()" << endl; }

string Wind_34::what() const { return "Wind_34"; }

void Wind_34::adjust(int) {}

void Percussion_34::play(int note) const { cout << "Percussion_34::play()" << endl; }

string Percussion_34::what() const { return "Percussion_34"; }

void Percussion_34::adjust(int) {}

void Stringed_34::play(int note) const { cout << "Stringed_34::play()" << endl; }

string Stringed_34::what() const { return "Stringed_34"; }

void Stringed_34::adjust(int) {}

void Brass_34::play(int note) const { cout << "Brass_34::play()" << endl; }

string Brass_34::what() const { return "Brass_34"; }

void Woodwind_34::play(int note) const { cout << "Woodwind_34::play()" << endl; }

string Woodwind_34::what() const { return "Woodwind_34"; }

int Shape_15::whatAmI() { return Shape; }

int Circle_15::whatAmI() { return Circle; }

int Square_15::whatAmI() { return Square; }

int Dog_15_36::run(int i) const { cout << "Dog_15_36::run()" << endl; }

int Dog_15_36::eat(int i) const { cout << "Dog_15_36::eat()" << endl; }

int Dog_15_36::sleep(int i) const { cout << "Dog_15_36::sleep()" << endl; }

Dog_15_36::FunctionObject_15::FunctionObject_15(Dog_15_36* wp, Pointer pmf) : ptr(wp), pmem(pmf) {
    cout << "FunctionObject_15 constructor" << endl;
}

int Dog_15_36::FunctionObject_15::operator()(int i) const {
    cout << "FunctionObject_15::operator()" << endl;
    return (ptr->*pmem)(i);
}

Dog_15_36::FunctionObject_15 Dog_15_36::operator->*(Pointer pmf) {
    cout << "FunctionObject_15::operator->*" << endl;
    return FunctionObject_15(this, pmf);
}

int Dog_15_36_1::run(int i) const { cout << "Dog_15_36_1::run()" << endl;}

int Dog_15_36_1::eat(int i) const { cout << "Dog_15_36_1::eat()" << endl; }

int Dog_15_36_1::sleep(int i) const { cout << "Dog_15_36_1::sleep()" << endl; }

Dog_15_36_1::FunctionObject_15::FunctionObject_15(Dog_15_36_1* wp, Pointer pmf) : ptr(wp), pmem(pmf) {
    cout << "FunctionObject_15 constructor" << endl;
}

int Dog_15_36_1::FunctionObject_15::operator()(int i) const {
    cout << "FunctionObject_15::operator()" << endl;
    return (ptr->*pmem)(i);
}

Dog_15_36_1::FunctionObject_15 Dog_15_36_1::operator->*(Pointer pmf) {
    cout << "FunctionObject_15::operator->*" << endl;
    return FunctionObject_15(this, pmf);
}

void chapter_15() {
    cout << "Chapter's 15 tasks.\n";
    // Task 1-3. With reference works fine.
    Shape_1* ar1[] = { new Circle_1, new Square_1, new Triangle_1 };
    for (int i = 0; i < 3; i++) ar1[i]->draw();
    // cannot declare variable 'cl1' to be of abstract type 'Shape_1'
    // Shape_1 cl1;
    function_15_1(*ar1[0]);
    // Task 4.
    Class_15_B* ptr4 = new Class_15_C(4);
    ptr4->f();
    // Task 5.
    Instrument_5* ptr5 = new Wind_5;
    function_15_5(*ptr5);
    // Task 6-10.
    Rodent* ar6[] = { new Mouse, new Gerbil, new Hamster };
    vector<Rodent*> vec6;
    vec6.push_back(new Mouse);
    vec6.push_back(new Gerbil);
    vec6.push_back(new Hamster);
    for (int i = 0; i < vec6.size(); i++) {
        ar6[i]->run();
        vec6[i]->eat();
        delete vec6[i];
    }
    Rodent* ptr6 = new BlueHamster;
    ptr6->run();
    ptr6->eat();
    // Task 11.
    Tower cl11(3);
    cl11.open();
    cl11.close();
    // Task 12.
    vector<Plant*> greenhouse;
    for (int i = 0; i < 2; i++) {
        greenhouse.push_back(new Cactus);
        greenhouse.push_back(new Flower);
        greenhouse[i*2]->seat();
        greenhouse[i*2+1]->fertilize();
    }
    // Task 13-14.
    Pet* ptr13 = new Dog("Ralph");
    cout << ptr13->speak() << endl;
    cout << ptr13->name() << endl;
    // Task 15.
    Class_15_14_1* ptr15 = new Class_15_14_1;
    ptr15->function_2();
    // Task 16-17.
    Base_15* ptr16 = new Derived_15_2;
    delete ptr16;
    // Task 18.
    Derived_15_18 cl16;
    cout << "Sizeof Derived_18 = " << sizeof(cl16) << ". ";
    function_15_18(cl16);
    // Task 19. see in .cpp file.
    // Task 20. With x100 multiplier, virtual calls - 43 seconds, usual - 35.
    Class_15_20* ptr20 = new Class_15_20_1;
    time_t time;
    tm local;
    time = std::time(NULL);
    local = *std::localtime(&time);
    int startTimer = local.tm_sec;
    cout << "Starting second of call's virtual function_1(): " << startTimer;
    for (int i = 0; i < 10000; i++) for (int j = 0; j < 10000; j++) ptr20->function_1();
    time = std::time(NULL);
    local = *std::localtime(&time);
    int finishTimer = local.tm_sec;
    cout << ", after calling virtual function_1() : " << finishTimer << endl;
    cout << "Seconds after calling function_2(): ";
    for (int i = 0; i < 10000; i++) for (int j = 0; j < 10000; j++) ptr20->function_2();
    time = std::time(NULL);
    local = *std::localtime(&time);
    finishTimer = local.tm_sec;
    cout << finishTimer << endl;
    // Task 21.
    Base_15_21* ptrs21[] = { new Derived_15_21_1, new Derived_15_21_2 };
    for (int i = 0; i < 2; i++) {
        ptrs21[i]->function();
        delete ptrs21[i];
    }
    // Task 22. Yes, with Class::. If remove method, then calling only methods from the base class.
    Class_15_22_1* ptr22 = new Class_15_22_1;
    char c22 = 'a';
    int i22 = 3;
    float f22 = 1.0;
    ptr22->function(c22);
    ptr22->function(i22);
    ptr22->function(f22);
    Class_15_22* ptr22_1 = (Class_15_22*)ptr22;
    ptr22_1->function(c22);
    ptr22_1->function(f22);
    ptr22_1->function(i22);
    // Task 23. May be another path. Not clear.
    Bird_15 bird;
    Cat_15 cat;
    Pet_15* ptr23[] = { &bird, &cat };
    for (int i = 0; i < 2; i++) {
        cout << ptr23[i]->type() << " eats "
             << ptr23[i]->eats(true).foodType() << endl;
    }
    Cat_15::CatFood_15& ptr23_1 = cat.eats(true);
    Bird_15::BirdFood_15& ptr23_2 = dynamic_cast<Bird_15::BirdFood_15&>(bird.eats(true));
    // Task 24. Hard to find in assembly output.
    Dog_15_24 cl24;
    Pet_15_24* ptr24_1 = &cl24;
    Pet_15_24& ptr24_2 = cl24;
    Pet_15_24 cl24_1;
    cout << "Pointer 1: " << ptr24_1->speak() << endl;
    cout << "Pointer 2: " << ptr24_2.speak() << endl;
    cout << "Object 3: " << cl24_1.speak() << endl;
    // Task 25. Strange task, but works fine in both cases.
    Base_15_25* ptrs25[] = { new Derived_15_25_1, new Derived_15_25_2 };
    Base_15_25& ref25_1 = ptrs25[0]->clone();
    Base_15_25& ref25_2 = ptrs25[1]->clone();
    ref25_1.print();
    ref25_2.print();
    // Task 26.
    Stack_15 st26;
    for (int i = 0; i < 3; i++) st26.push(new Class_15_26_1(i));
    for (int i = 0; i < 3; i++) {
        Class_15_26_1* element = (Class_15_26_1*)st26.pop();
        cout << "Pop Class_15_26_1 with index from base class = "
             << element->i << endl;
        delete element;
    }
    // Task 27.
    Math* maths[] = { new Matrix, new Vector, new Scalar, new Tensor };
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            Math& m1 = *maths[i];
            Math& m2 = *maths[j];
            m1 * m2;
        }
    // Task 28-29. Because of default constructor, find assembly code too hard.
    Class_15_28_1 cl28;
    // Task 30.
    Class_15_30_1 cl31;
    function_15_30(cl31);
    // Task 31. See task 20 above.
    // Task 32.
    Class_15_32_3 cl32;
    Class_15_32_1 cl32_1;
    Class_15_32_2 cl32_2;
    cout << "Sizeof empty Class_15_32_3 = " << sizeof(cl32) << endl;
    cout << "Sizeof empty Class_15_32_1 = " << sizeof(cl32_1) << endl;
    cout << "Sizeof empty Class_15_32_2 = " << sizeof(cl32_2) << endl;
    // Task 33.
    Class_15_33 cl33;
    unsigned char* ptr33 = (unsigned char*)&cl33;
    cout << "Memory map for Class_15_33: ";
    for (int i = 0; i < sizeof(cl33); i++)
        cout << (int)*(ptr33+i) << " ";
    cout << endl;
    // Task 34. Works fine.
    Instrument_34* ptrs34[] = { new Wind_34, new Percussion_34, new Stringed_34, new Brass_34, new Woodwind_34 };
    dynamic_cast<Wind_34*>(ptrs34[0])->play(0);
    dynamic_cast<Percussion_34*>(ptrs34[1])->play(0);
    dynamic_cast<Stringed_34*>(ptrs34[2])->play(0);
    dynamic_cast<Brass_34*>(ptrs34[3])->play(0);
    dynamic_cast<Woodwind_34*>(ptrs34[4])->play(0);
    // Task 35.
    Circle_15 circle1;
    Square_15 square1;
    Shape_15* ptr35_1 = &square1;
    Circle_15* cptr = 0;
    Square_15* sptr = 0;
    if (ptr35_1->whatAmI() == Shape_15::Circle) cptr = static_cast<Circle_15*>(ptr35_1);
    if (ptr35_1->whatAmI() == Shape_15::Square) sptr = static_cast<Square_15*>(ptr35_1);
    if (cptr != 0) cout << "Circle_15 found." << endl;
    if (sptr != 0) cout << "Square_15 found." << endl;
    // invalid static_cast from type 'Shape_15*' to type 'Other_15*'
    // Other_15* optr = static_cast<Other_15*>(ptr35_1);
    // Task 36. Works, but think later.
    Dog_15_36* cl36 = new Dog_15_36_1;
    Dog_15_36::Pointer ptrs36[] = { &Dog_15_36::run, &Dog_15_36::eat, &Dog_15_36::sleep };
    for (int i = 0; i < 3; i++) cout << (cl36->*ptrs36[i])(i) << endl;
}
