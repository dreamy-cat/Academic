#include <iostream>
#include <errno.h>
#include <signal.h>
#include <vector>
#include <fstream>

#include "labs_0x02.h"
#include "chapter_01.h"
#include "chapter_02.h"
#include "chapter_03.h"

using namespace Labs_0x02;
using namespace std;

void Labs_0x02::chapter_01() {
    cout << "Chapter's 1. Tasks.\n";
    // Task 1.
    cout << "Function 01 returns " << function_01_1() << ".\n";
    function_01_2();
    std::cout << "Function 02, errno = " << errno << ".\n";
    signal(SIGINT, function_01_3);
    raise(SIGINT);
    try {
        function_01_4();
    } catch (int) {
        cout << "Catch exception from function 04.\n";
    }
    // Task 2.
    Class_01_1 class_1;
    try {
        class_1.function_1();
    } catch (Class_01_1::Class_1 cl) {
        cout << "Catch exception from function_1, Class_01_1. String = " << cl.str << "\n";
    }
    // Task 3-4.
    PStash_1 stash;
    const char string_1[] = "ABC";
    try {
        cout << "All objects in stash: ";
        for (int i = 0; i < 3; i++) {
            stash.add((void*)&string_1[i]);
            cout << *((char*)stash[i]) << " ";
        }
        cout << endl;
        for (int i = 0; i < 3; i++) stash.remove(i);
        cout << *((char*)stash[5]) << " ";
    } catch(out_of_range m) {
        cout << "Exception from PStash_1: " << m.what() << endl;
    } catch(invalid_argument m) {
        cout << "Exception from PStash_1: " << m.what() << endl;
    }
    // Task 5.
    Class_1_5* ptrs_1[] = { NULL, NULL, NULL, NULL, NULL };
    int i, j = 0;
    for (i = 0; i < 3; i++) ptrs_1[i] = new Class_1_5;
    for ( ; i < 5; ) {
        try {
            ptrs_1[i] = new Class_1_5;
            i++;
        } catch (bad_alloc e) {
            cout << "Exception from Class_1_5::operator new: " << e.what() << ", trying to free some space." << endl;
            delete (ptrs_1[j++]);
        }
    }
    // Task 6-8. Terminate called after throwing an instance of 'int'.
    Class_1_6* class_2 = new Class_1_6, class_3;
    try {
        class_3.function_1();       // Auto object.
        class_2->function_1();      // Heap object.
        // delete class_2;
    } catch (int n) {
        cout << "Exception from Class_1_6:: " << n << endl;
    }
    // Task 11. First, because of terminate.
    try {
        Garage class_3;
    } catch (int i) {
        cout << "Exception in Garage constructor, int = " << i << endl;
    }
    // Task 9-10. May be not as planning.
    set_unexpected(unexpectedHandler);
    for (int i = 0; i < 5; i++) {
        try {
            function_01_9(i);
        } catch (char c) {
            cout << "Catch exception with char = " << c << endl;
        } catch (int i) {
            cout << "Catch exception with int = " << i << endl;
        } catch (bool b) {
            cout << "Catch exception with bool = " << b << endl;
        } catch (Class_1_9 cl) {
            cout << "Catch exception with Class_1_9, what(): " << cl.what() << endl;
        }
    }
}

void Labs_0x02::chapter_02() {
    cout << "Chapter's 2 tasks.\n";
    // Task 1.
    vector<int> vector_1;
    for (int i = 0; i < 3; i++) vector_1.push_back(i);
    TestKit::Kit kit("Vector");
    kit.addTest(new TestKit::VectorTest);
    try {
        kit.run();
    } catch (out_of_range) {
        cout << "Exception, vector out of range." << endl;
    }
    kit.report();
    // Task 2-4.
    TestKit::Kit kit_2("Rational");
    try {
        kit_2.addTest(new TestKit::RationalTest);
        kit_2.run();
        kit_2.report();
    } catch (invalid_argument s) {
        cout << "Exception: " << s.what() << endl;
    }
    // Task 5.
    TestKit::Kit kit_3("BinSearch");
    try {
        kit_3.addTest(new TestKit::TestSearch);
        kit_3.run();
        kit_3.report();
    } catch (out_of_range m) {
        cout << "Exception: " << m.what() << endl;
    }
}

void Labs_0x02::chapter_03() {
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
    file_2.close();
    file_1.close();
}

void labs_0x02() {
    chapter_03();
}
