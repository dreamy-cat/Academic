#include "chapter_13.h"

using namespace std;

int Counted::count = 0;

Counted::Counted() : id(count++) {
    cout << "Class Counted constructor. Id = " << id << endl;
}

Counted::~Counted() {
    cout << "Class Counted destructor. Id = " << id << endl;
}

void Counted::function_1() {}
