#include "chapter_10.h"

using namespace std;

Singleton Singleton::single(0);

int Singleton::i;

Singleton& Singleton::instance() { return single; }

int Singleton::getValue() { return i; }

void Singleton::setValue(int x) { i = x; }

Singleton::Singleton(int x) {
    i = x;
    cout << "Singleton::Singleton(" << i << ")" << endl;
}

string Class_10_2::file;

Class_10_2 Class_10_2::reader;

string Class_10_2::readFile() {
    fstream textFile;
    textFile.open(file.data(), ios::in);
    string result;
    getline(textFile, result, '\0');
    textFile.close();
    return result;
}

Class_10_2::Class_10_2() { file = "labs_0x02/files/chapter-10.txt"; }

vector<Class_10_3*> Class_10_3::objects;

int Class_10_3::counter;

int Class_10_3::limit;

void Class_10_3::init(int lim) {
    counter = 0;
    limit = lim;
}

bool Class_10_3::create(Class_10_3 *newObject) {
    if (counter < limit) {
        cout << "Counter of Class_10_3, less than limit. Creating object..." << endl;
        counter++;
        objects.push_back(new Class_10_3);
        newObject = objects[objects.size()-1];
        return true;
    } else {
        cout << "Counter of Class_10_3, is reached it's limit, returninig..." << endl;
        return false;
    }
}

Class_10_3::Class_10_3() {
    cout << "Class_10_3::Class_10_3(), counter = " << counter << endl;
}

void StateRotation::Object::responce() { cout << "StateRotation::Object::responce()" << endl; }

void StateRotation::Tool::responce() { cout << "StateRotation::Tool::responce()" << endl; }

void StateRotation::Material::responce() { cout << "StateRotation::Material::responce()" << endl; }

StateRotation::StateRotation() : iteration(0), limit(3) {
    cout << "StateRotation::StateRotation()" << endl;
    state = new Object;
}

// StateRotation::~StateRotation() { cout << "StateRotation::~StateRotation()" << endl; }

void StateRotation::function() {
    state->responce();
}

void StateRotation::action() {
    delete state;
    if (++iteration >= limit) iteration = 0;
    switch (iteration) {
    case 0:
        state = new Object;
        break;
    case 1:
        state = new Tool;
        break;
    case 2:
        state = new Material;
        break;
    default:
        break;
    }
}
