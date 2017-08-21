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

TerminalHacked::TerminalHacked(int wordS, int attempts) : wordSize(wordS), attemptsLimit(attempts), attempt(0) {}

void TerminalHacked::play()
{
    srand(time(0));
    cout << "Game 'Terminal Hacked'.\n";
    word.resize(wordSize);
    for (auto& literal : word)
        literal = 'A' + char(trunc((double)rand() / (double)RAND_MAX * (double)('Z' - 'A')));
    cout << "Word to find: " << word << endl;
    const int variantFactor = 2;
    vector<string> wordVariants(variantFactor * attemptsLimit);
    int originalPos = 4; // trunc((float)rand() / (float)RAND_MAX * (float)(wordSize));
    cout << "Position of original word: " << originalPos << endl;
    cout << "All variants of the word: ";
    for (int j = 0; j < variantFactor * attemptsLimit; j++) {
        wordVariants[j] = word;
        for (int i = 0; j != originalPos && i < wordSize; i++) {
            int pos1 = trunc((float)rand() / (float)RAND_MAX * (float)(wordSize));
            int pos2 = trunc((float)rand() / (float)RAND_MAX * (float)(wordSize));
            char literal = wordVariants[j][pos1];
            wordVariants[j][pos1] = wordVariants[j][pos2];
            wordVariants[j][pos2] = literal;
        }
        cout << wordVariants[j] << " ";
    }
    cout << endl;
    cout << "Trying to find word.\n";
    int likeness = 0, bestPosition = 0;
    vector<int> previousLikeness(attemptsLimit);
    for (int i = 0, guess = 0; /*wordVariants[guess] != word && */ i < attemptsLimit; i++) {
        // string guess = wordVariants[i];
        cout << "Try " << guess << ": " << wordVariants[guess] << endl;
        for (int k = 0; k < i; k++) {
            likeness = 0;
            cout << "\tCompare with " << wordVariants[k] << " guess, ";
            for (int j = 0; j < wordSize; j++)
                if (wordVariants[guess][j] == wordVariants[k][j])
                    likeness++;
            cout << "likeness is " << likeness;
            if (previousLikeness[k] == 0 && likeness > 0)
                cout << ", original likeness was zero, so skipped this variant.";
            if (previousLikeness[k] == likeness)
                cout << ", this is equal of previous guess.";
            if (previousLikeness[bestPosition] < likeness) {
                cout << ", is greater than one of previous.";
                bestPosition = k;
            }
            cout << endl;
        }
        // if (likeness >= previousLikeness[bestPosition]) {
            likeness = 0;
            for (int j = 0; j < wordVariants[guess].size(); j++)
                if ( wordVariants[guess][j] == word[j] ) likeness++;
            cout << "\tLikeness with original " << likeness;
            if (likeness == wordSize) cout << ", founded.";
            previousLikeness[i] = likeness;
            // bestPosition = guess;
        // } else cout << "\tSkip attempt because of low likeness.";
        cout << endl;
        guess++;
    }
}

TerminalHacked::~TerminalHacked()
{

}
