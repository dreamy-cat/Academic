#include "chapter_01.hpp"

using namespace std;

StringInsens::StringInsens(const char *str) : text(str)
{
    cout << "Insensitive string constructor, data '" << str << "'.\n";
}

int operator==(const StringInsens& lv, const char* rv)
{
    string right(rv), left(lv.getData());
    if (right.size() != left.size())
        return false;
    cout << "Right string " << right << endl;
    for (int i = 0; i < left.size(); ++i)
        if (toupper(left[i]) != toupper(right[i]))
            return false;
    return true;
}

const char *StringInsens::getData() const
{
    return text;
}

string& function_1_6(list<string>& source, string &value)
{
    static string notFound("Value not founded in the list.");
    cout << "Function_1_6, finding value in the list.\n";
    list<string>::iterator end(source.end());
    for (list<string>::iterator it = source.begin(); it != end; ++it)
        if (*it == value) return value;
    return notFound;
}

string function_1_7(const list<string> &source, const string &value)
{
    cout << "Function_1_7, finding value in the list.";
    list<string>::const_iterator it(find(source.begin(), source.end(), value));
    if (it != source.end()) return value;
    return string("Value not founded in the list.");
}

bool greaterSeven(int i) { return i > 7; }

bool isGreater_1(std::vector<int>& source)
{
    return (find_if(source.begin(), source.end(), greaterSeven) != source.end());
}

bool Greater_1::operator()(int i) const { return i > 7; }

bool isGreater_2(vector<int>& source)
{
    return (find_if(source.begin(), source.end(), Greater_1()) != source.end());
}

Greater_2::Greater_2(int rv) : value(rv) {}

bool Greater_2::operator()(int i) const { return i > value; }

bool isGreater_3(std::vector<int>& source)
{
    return (find_if(source.begin(), source.end(), Greater_2(7)) != source.end());
}

bool isGreater_4(std::vector<int>& source)
{
    return (find_if(source.begin(), source.end(), Greater_3<int>(7)) != source.end());
}

Greater_4_1::Greater_4_1(size_t n) : i(0), m(n) {}

void Class_2::testing() const { cout << "Class_2::testing().\n"; }

Class_14a::Class_14a() { cout << "Class_14a, constructor.\n"; }

Class_14a* Class_14a::verify() { cout << "Class_14a::verify().\n"; }

void function_1(Class_16) { cout << "Function_1a(Class_16).\n"; }

int findKey(const int key, int* vecKeys, size_t maxElements)
{
    int i = 0;
    while (key != vecKeys[i] && i < maxElements) i++;
    if (i != maxElements) return i; else return -1;
}

Class_17::Class_17() : n(0) {}

const Class_17 operator++(Class_17& rv, int)
{
    cout << "Postfix operator++ for Class_17.\n";
    rv.n++;
}

int function_2(Class_17 value)
{
    cout << "Function_2(Class_17).\n";
    return value.n;
}

