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

void Shape::altDraw() {
    string className = typeid(*this).name();
    if ( className.find("Circle") != string::npos ) (dynamic_cast<Circle*>(this))->draw(); else
        if ( className.find("Triangle") != string::npos ) (dynamic_cast<Triangle*>(this))->draw(); else
            if ( className.find("Square") != string::npos ) (dynamic_cast<Square*>(this))->draw(); else
                cout << "Something goes wrong with type " << className << endl;
}

Circle::Circle() { radius = rand() % 10; }

void Circle::draw() { cout << "Circle::draw(), radius " << radius << endl; }

Circle::~Circle() { cout << "Circle::~Circle()" << endl; }

Triangle::Triangle() { line = rand() % 10; }

void Triangle::draw() { cout << "Triangle::draw(), line length " << line << endl; }

Triangle::~Triangle() { cout << "Triangle::~Triangle()" << endl; }

Square::Square() { perimeter = rand() % 10; }

void Square::draw() { cout << "Square::draw(), perimeter " << perimeter << endl; }

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

Class_7_11::Class_7_11() {
    priority = rand() % 10;
}

bool operator<(const Class_7_11& lv, const Class_7_11& rv) {
    return (lv.priority < rv.priority);
}

ostream& operator<<(ostream& os, const Class_7_11& value) {
    return os << "Class_7_11::priority = " << value.priority << endl;
}

Class_7_15::Class_7_15(const char l) : letter(l), isExist(false) {}

bool Class_7_15::exist(char c) { return (isExist = (toupper(c) == toupper(letter))); }

char Class_7_15::getLetter() { return letter; }
