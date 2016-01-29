#include "chapter_06.h"

using namespace std;

clock_t function_6_1() { return clock(); }

char to_Upper(char c) {
    if (c >= 'a' && c <= 'z') c += 'A' - 'a';
    return c;
}

int Class_6_1::sum;

Class_6_1::Class_6_1(int init) { sum = 0; }

int Class_6_1::operator()(int n) { sum += n; return sum; }

void Class_6_2::function_1() { cout << "Class_6_2::function_1().\n"; }

void Class_6_2_1::function_1() { cout << "Class_6_2_1::function_1().\n"; }

Generator_1::Generator_1(int start, int skip) : i(start), sk(skip) {}

int Generator_1::operator()() {
    int r = i;
    i += sk;
    return r;
}

Generator_2::Generator_2(int lim) : limit(lim) {}

int Generator_2::operator()() {
    while (true) {
        int i = int(std::rand()) % limit;
        if (used.find(i) == used.end()) {
            used.insert(i);
            return i;
        }
    }
}

const char* Generator_3::source = "abcdefghijk";

const int Generator_3::len = strlen(source);

char Generator_3::operator()() {
    return source[std::rand()% len];
}

bool BRand::operator ()() { return rand() % 2 == 0; }

void multipliers(int n, std::vector<int>& m) {
    m.clear();
    for (int i = 0; i <= n; i++) m.push_back(i);
    for (int i = 2; i <= n; ) {
        for (int j = 2; j*i <= n; j++) m[j*i] = 0;
        while (++i <= n && !m[i]);
    }
    vector<int>::iterator end = remove(m.begin(), m.end(), 0);
    m.erase(end, m.end());
}

void textToWords(std::string text, std::vector<string>& words) {
    int word = 0, space = 0;
    while ((space = text.find_first_of(" .,!?\0", word)) != string::npos && word < text.size()) {
        words.push_back(string(text, word, space-word));
        word = ++space;
    }
}
