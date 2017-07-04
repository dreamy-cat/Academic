#include "chapter_01.hpp"

using namespace std;

StringInsens::StringInsens(const char *str) : text(str)
{
    cout << "Insensitive string constructor, data '" << str << "'.\n";
}

char* StringInsens::data()
{
    return text;
}

