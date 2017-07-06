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


