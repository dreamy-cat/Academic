#include "19_Strings.hpp"

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

void chapter_19() {
    cout << "Chapter's 3 tasks.\n";
    // Tasks 1-4.
    string string_1 = "string_1", string_2;
    cout << "Reverse string '" << string_1;
    string_2 = reverseString(string_1);
    cout << "' = " << string_2 << endl;
    string string_3 = "w o,W ";
    cout << "Is string '" << string_3 << "' = '" << reverseString(string_3) << "': ";
    cout << isEqual(string_3, reverseString(string_3)) << endl;
    cout << "Is string '" << string_1 << "' = '" << reverseString(string_1) << "': ";
    cout << isEqual(string_1, reverseString(string_1)) << endl;
    // Task 5.
    string strings_1[] = { "one", "two", "three" };
    cout << "Strings in vector: ";
    for (int i = 0; i < sizeof(strings_1)/sizeof(string*); i++) cout << strings_1[i] << " ";
    cout << endl;
    // Task 6-7.
    string source_1, from = "word_1", to = "word_2", source_2;
    fstream file_1("labs_0x02/files/chapter-3.txt");
    getline(file_1, source_1, '\0');
    source_2 = toLower(source_1);
    cout << "Original file chapter-3.txt:\n" << source_1;
    int pos;
    string lowFrom = toLower(from), lowTo = toLower(to), lowSource = toLower(source_1);
    while ((pos = lowSource.find(lowFrom, 0)) != string::npos) {
        source_1.replace(pos, from.size(), to);
        lowSource.replace(pos, from.size(), to);
    }
    cout << "\nText after replace:\n" << source_1 << endl;
    // Task 8.
    string delim(" ,.;\t\n\0");
    int wordBegin = source_2.find_first_not_of(delim);
    int wordEnd = source_2.find_first_of(delim, wordBegin);
    cout << "All words from file(already in vector, case insensetive):\n";
    vector<string> words;
    vector<int> counters;
    while (wordBegin != string::npos) {
        string word(string(source_2, wordBegin, (wordEnd - wordBegin)));
        int i = 0;
        while (i < words.size() && toLower(words[i]) != toLower(word)) i++;
        if (i == words.size()) {
            words.push_back(word);
            counters.push_back(1);
            cout << words.back() << " ";
        } else {
            cout << "(" << words[i] << ") ";
            counters[i]++;
        }
        wordBegin = source_2.find_first_not_of(delim, wordEnd+1);
        wordEnd = source_2.find_first_of(delim, wordBegin);
    }
    cout << "\nFounded symmetric words:\n";
    for (int i = 0; i < words.size(); i++) {
        if (toLower(words[i]) == reverseString(toLower(words[i])))
            cout << words[i] << " ";
    }
    cout << endl;
    // Task 9.
    string tag = "comment", source_3 = source_2;
    int tagBegin, tagEnd;
    while ((tagBegin = source_3.find("<"+tag+">")) != string::npos)
        if ((tagEnd = source_3.find("</"+tag+">", tagBegin)) != string::npos)
            source_3.erase(tagBegin, tagEnd-tagBegin+tag.size()+3);
        else cout << "Error, tag '" << tag << "' founded, but not closed." << endl;
    // else cout << "Error, tag '" << tag << "' not found." << endl;
    cout << "Result text without comments:\n" << source_3 << endl;
    // Task 10.
    string word_5 = "contain_1", word_6 = "contain_2";
    int lineBegin = 0, lineEnd = 0;
    while ((lineEnd = source_2.find("\n", lineBegin)) != string::npos) {
        string line(source_2, lineBegin, lineEnd-lineBegin);
        if (line.find(word_5) != string::npos && line.find(word_6) != string::npos)
            cout << "Text line contains both searched words:\n" << line << endl;
        else if (line.find(word_5) != string::npos || line.find(word_6) != string::npos)
            cout << "Text line contains one searched word:\n"  << line << endl;
        else cout << "Text line contains no searched words:\n" << line << endl;
        lineBegin = lineEnd+1;
    }
    // Task 11.
    cout << "Words in file and counters:\n";
    for (int i = 0; i < words.size(); i++) cout << words[i] << " : " << counters[i] << "\n";
    // Task 12.
    fstream file_2("labs_0x02/labs_0x02.cpp");
    string source_4;
    vector<int> symCounters;
    symCounters.resize(256);
    getline(file_2, source_4, '\0');
    for (int i = 0; i < source_4.size(); i++) symCounters[source_4[i]]++;
    cout << "Symbols frequences in source file labs_0x02.cpp:\n";
    for (int i = 32; i < 127; i++) cout << char(i) << "[" << symCounters[i] << "] ";
    cout << endl;
    // Task 13. May be not as planning...
    string string_4 = "chapter's 3 text file.";
    cout << "First word after first'" << string_4 << "': ";
    int fp, lp;
    if ((fp = source_2.find(string_4, 0)) == 0)
        cout << string(source_2, string_4.size()+1, source_2.find_first_of(delim, string_4.size()+1)-string_4.size())
             << ", index = " << fp << endl;
    else cout << "Error, string not found." << endl;
    cout << "First word before last '" << string_4 << "': ";
    if ((lp = source_2.rfind(string_4)) != string::npos) {
        int i = lp-2;
        while (i >= 0 && !isDelim(source_2[i], delim)) i--;
        cout << string(source_2, i+1, lp-i-2) << ", index = " << lp << endl;
    } else cout << "Error, string nod found." << endl;
    // Task 14.
    file_1.seekg(0);
    source_2.clear();
    getline(file_1, source_2, '\0');
    string nonAlpha = "!@#$%^&*()_/:;<=>?[]\\`,";
    while ((pos = source_2.find_first_of(nonAlpha)) != string::npos)
        source_2.replace(pos, 1, "");
    for (int i = 0; i < source_2.size(); i++)
        if (source_2[i] == '.') {
            while (!((source_2[i] >= 'a' && source_2[i] <= 'z') ||
                     (source_2[i] >= 'A' && source_2[i] <= 'Z'))) i++;
            if (source_2[i] >= 'a' && source_2[i] <= 'z')
                source_2[i] -= 'a'-'A';
        }
    cout << "Result text without special symbols:\n" << source_2 << endl;
    // Task 15.
    source_2.clear();
    file_1.seekg(0);
    getline(file_1, source_2, '\0');
    string numbers("0123456789");
    fp = lp = 0;
    cout << "All doubles in file: ";
    while ((fp = source_2.find_first_of(numbers, fp)) != string::npos) {
        int lp = fp;
        while (source_2[lp] >= '0' && source_2[lp] <= '9' || source_2[lp] == '.') lp++;
        string num(source_2, fp, (lp-fp));
        cout << atof(num.data()) << " ";
        fp = lp + 1;
    }
    cout << endl;
    // Task 16.
    int pairsToChange = 3;
    cout << "Words with changed symbols in pairs: ";
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        for (int j = 0; j < pairsToChange && j*2+1 < word.size(); j++) {
            char c = word[j*2];
            word[j*2] = word[j*2+1];
            word[j*2+1] = c;
        }
        cout << word << " ";
    }
    cout << endl;
    // Task 17.
    lp = fp = 0;
    int totalSenten = 0;
    while ((lp = source_2.find('.', fp)) != string::npos) {
        string sentence(source_2, fp, lp-fp);
        totalSenten++;
        fp = lp + 1;
    }
    cout << "Total file size: " << source_2.size() << ", sentences: " << totalSenten
         << ", medium sentence size: " << source_2.size()/totalSenten << endl;
    // Task 18.
    try {
        words.at(words.size()+1);
    } catch (out_of_range e) {
        cout << "Exception: " << e.what() << endl;
    }
    file_2.close();
    file_1.close();
}
