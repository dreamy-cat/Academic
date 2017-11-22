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

void TerminalHacked(int wordSize, int variants)
{
    srand(3);
    cout << "Game 'Terminal Hacked!'.\n";
    string word;
    word.resize(wordSize);
    const int alphabetSize = 'z' - 'a' + 1;
    for (auto& literal : word) literal = 'a' + rand() % alphabetSize;
    cout << "Word to find is '" << word << "', variants " << variants << ".\n";
    cout << "Generate mask and word's variants.\n";
    cout << "Variant:\tLikeness:\tNext:\tMask:\tRandom mask:\tWord:\n";
    vector<string> words(variants + 1);
    vector<int> mask(wordSize);
    int likeness = 0;
    for (int i = 0, next = variants / wordSize + (variants % wordSize > 0); i <= variants; i++) {
        if (i == next)
            if (wordSize > variants)
                likeness += (wordSize / variants) + (next++ <= wordSize % variants);
            else
                next += (variants / wordSize) + (++likeness < variants % wordSize);
        cout <<  i << "\t\t" << likeness << "\t\t" << next << "\t";
        for (int j = 0; j < wordSize; j++) {
            if (j < likeness) mask[j] = 1; else mask[j] = 0;
            cout << mask[j];
        }
        cout << "\t";
        for (int j = 0; j < variants * variants; j++) {
            int left = rand() % wordSize, right = rand() % wordSize;
            int element = mask[left];
            mask[left] = mask[right];
            mask[right] = element;
        }
        words[i].resize(wordSize);
        for (int j = 0; j < wordSize; j++) {
            cout << mask[j];
            if (mask[j] == 1) words[i][j] = word[j]; else
                while ((words[i][j] = ('a' + rand() % alphabetSize)) == word[j]);
        }
        cout << "\t\t" << words[i] << endl;
    }
    cout << "Resort all variants, source:\n";
    for (int i = 0; i < variants * variants; i++) {
        int left = rand() % (variants + 1);
        int right = rand() % (variants + 1);
        string element = words[left];
        words[left] = words[right];
        words[right] = element;
    }
    const int terminalWidth = 40;
    for (int column = 0, i = 0; i < words.size(); i++) {
        cout << words[i] << "\t";
        if ((column += wordSize) > terminalWidth) {
            column = 0;
            cout << endl;
        }
    }
    cout << "\nTrying to find the word.\n";
    cout << "Try and guess:\tAttempt:\tLikeness:\tPrevious:\tComment:\n";
    map<string, int> attempts;
    likeness = 0;
    for (int i = 0, j = 0, satisfy = 0; likeness < word.size() && i < words.size(); i = j) {
        string attempt = words[i];
        likeness = 0;
        for (int j = 0; j < attempt.size(); j++)
            if (attempt[j] == word[j]) likeness++;
        cout << i << " : 0\t\t" << attempt << "\t\t" << likeness << "\t\t-\t\t";
        attempts[attempt] = likeness;
        if (likeness < word.size()) {
            cout << "Word not correct, trying to guess next variant.\n";
            for (j = i + 1; satisfy != attempts.size() && j < words.size(); ) {
                satisfy = 0;
                attempt = words[j];
                for (map<string, int>::const_iterator aPtr = attempts.begin(); aPtr != attempts.end(); aPtr++) {
                    int prevLikeness = 0;
                    for (int l = 0; l < attempt.size(); l++)
                        if (attempt[l] == (*aPtr).first[l]) prevLikeness++;
                    cout << i << " : " << j - i << "\t\t";
                    cout << attempt << "\t\t" << prevLikeness << "\t\t" << (*aPtr).first << "\t\t";
                     if ((*aPtr).second == prevLikeness) {
                        satisfy++;
                        cout << "Guess likeness is good as previous attempt.\n";
                     } else cout << "Guess likeness not satisfy previous attempt.\n";
                }
                for (int k = 0; k < 8; k++) cout << "\t";
                if (satisfy == attempts.size())
                    cout << "The guess satisfies all previous attempts.\n";
                else {
                    cout << "The guess not satisfies all previous attempts.\n";
                    j++;
                }
            }
            if (satisfy != attempts.size()) cout << "Something goes wrong, next word not found.\n";
        } else cout << "Word founded, OK!\n";
    }
}
