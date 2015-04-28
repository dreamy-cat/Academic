#include "chapter_16.h"

using namespace std;

int AutoCounter::count = 0;

AutoCounter::CleanupCheck AutoCounter::verifier;

Int::Int(int ii) : i(ii) { cout << "Int constructor: " << i << endl; }

Int::~Int() { cout << "Int destructor: " << i << endl; }

std::ostream& operator<<(std::ostream& os, const Int& value) { return os << "Int.i = " << value.i; }

std::ostream& operator<<(std::ostream& os, const Int* value) { return os << "Int.i = " << value->i; }

template<class T> int ObjContainer_16<T>::i = 0;

template<class T> int ObjContainer_16<T>::j = 0;

