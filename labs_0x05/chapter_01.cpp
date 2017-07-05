#include "chapter_01.hpp"

using namespace std;

StringInsens::StringInsens(const char *str) : text(str)
{
    cout << "Insensitive string constructor, data '" << str << "'.\n";
}

const char *StringInsens::getData() const
{
    return text;
}

int operator==(const StringInsens& lv, const char* rv)
{
    string right(rv), left(lv.getData());
    if (right.size() != left.size())
        return false;
    cout << "Right string " << right << endl;
    for (int i = 0; i < left.size(); ++i) {
        if (left[i] >= 'a' && left[i] <= 'z')
            left[i] -= ' ';
        if (right[i] >= 'a' && right[i] <= 'z')
            right[i] -= ' ';
        if (left[i] != right[i])
            return false;
    }
    return true;
}

