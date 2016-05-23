#include "chapter_07.h"

using namespace std;

int Noisy::create = 0;

int Noisy::assign = 0;

int Noisy::copyCons = 0;

int Noisy::destroy = 0;

Noisy::Noisy() : id(create++) { cout << "Noisy::Noisy(), id = " << id << endl; }

Noisy::~Noisy() { cout << "Noisy::~Noisy(), id = " << id << ", counter " << ++destroy << endl; }

Noisy::Noisy(const Noisy& rv) : id(rv.id) {
    cout << "Noisy::Noisy(const Noisy&), id " << id << ", counter " << ++copyCons << endl;
}

Noisy& Noisy::operator=(const Noisy& rv) {
    id = rv.id;
    cout << "Noisy::operator=(), id " << id << ", counter " << ++assign << endl;
    return *this;
}

void Noisy::report() {
    cout << "Noisy::report(), counters: create " << create
         << ", assing " << assign
         << ", copy constructors " << copyCons
         << ", destructors " << destroy << endl;
}

bool operator<(const Noisy& lv, const Noisy& rv) {
    cout << "Noisy::operator<(), lv.id " << lv.id << ", rv.id " << rv.id << endl;
    return (lv.id < rv.id);
}

bool operator==(const Noisy& lv, const Noisy& rv) {
    cout << "Noisy::operator==(), lv.id " << lv.id << ", rv.id " << rv.id << endl;
    return (lv.id == rv.id);
}

ostream& operator<<(ostream& os, const Noisy& value) {
    return os << "Noisy::id " << value.id << endl;
}

void function_7_2(std::list<Noisy> v) {
    cout << "Sorting list<Noisy>, container size " << v.size() << endl;
    v.sort();
}

Shape::~Shape() {}

void Circle::draw() { cout << "Circle::draw()" << endl; }

Circle::~Circle() { cout << "Circle::~Circle()" << endl; }

void Triangle::draw() { cout << "Triangle::draw()" << endl; }

Triangle::~Triangle() { cout << "Triangle::~Triangle()" << endl; }

void Square::draw() { cout << "Square::draw()" << endl; }

Square::~Square() { cout << "Square::~Square()" << endl; }

void printStack(stack<int>& s, string name) {
    cout << "Stack '"  << name << "': ";
    stack<int> tmp = s;
    while ( !tmp.empty() ) {
        cout << tmp.top() << " ";
        tmp.pop();
    }
    cout << endl;
}

void sortStack(std::stack<int>& source, std::stack<int>& sorted, std::stack<int>& tail) {
    while ( !source.empty() ) {
        sorted.push(source.top());
        source.pop();
        if (source.empty()) break;
        if ( source.top() > sorted.top() ) {
            if (sorted.empty()) cout << "sorted empty" << endl;
            tail.push(sorted.top());
            sorted.pop();
        }
        if ( source.top() <= sorted.top() ) {
            if (source.empty()) cout << "source empty" << endl;
            tail.push(source.top());
            source.pop();
        }
    }
}

