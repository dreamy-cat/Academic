#include "chapter_03.h"

using namespace std;

std::string reverseString(const std::string& s) {
    string r = s;
    for (int i = 0, j = 0; i < r.size()/2; i++) {
        char c = r[i];
        r[i] = r[r.size()-1-i];
        r[r.size()-1-i] = c;
    }
    return r;
}

char toLower(const char c) {
    if (c >= 'A' && c <= 'Z') return char(c+('a'-'A'));
    return c;
}

std::string toLower(const std::string& s) {
    string r = s;
    for (int i = 0; i < r.size(); i++) r[i] = toLower(r[i]);
    return r;
}

bool isEqual(const std::string& s_1, const std::string& s_2) {
    int i, j;
    for (i = 0, j = 0; i < s_1.size() && j < s_2.size(); i++, j++) {
        while (s_1[i] == ' ' || s_1[i] == ',') i++;
        while (s_2[j] == ' ' || s_2[j] == ',') j++;
        if (tolower(s_1[i]) != tolower(s_2[j])) return false;
    }
    return true;
}

bool isDelim(const char c, const std::string delimS) {
    for (int i = 0; i < delimS.size(); i++)
        if (c == delimS[i]) return true;
    return false;
}
