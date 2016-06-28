#include <iostream>
#include <errno.h>
#include <signal.h>
#include <vector>
#include <map>
#include <valarray>
#include <queue>
#include <fstream>
#include <iomanip>
#include <exception>
#include <sstream>
#include <ctime>
#include <math.h>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include <cmath>

#include "labs_0x02.h"
#include "chapter_01.h"
#include "chapter_02.h"
#include "chapter_03.h"
#include "chapter_04.h"
#include "chapter_05.h"
#include "chapter_06.h"
#include "chapter_07.h"
#include "chapter_08.h"
#include "chapter_09.h"
#include "chapter_10.h"

#include "stdlib.h"

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

void Labs_0x02::chapter_04() {
    cout << "Chapter's 4 tasks.\n";
    // Task 1. Using std::cout instead of file.
    fstream file_1("labs_0x02/files/chapter-4-1.txt");
    string sourceFile, string_1;
    getline(file_1, sourceFile, '\0');
    string_1 = sourceFile;
    cout << "File chapter-4-1.txt:\n" << sourceFile << endl;
    for (int i = 0; i < string_1.size(); i++) string_1[i] = toupper(string_1[i]);
    cout << "Result text to upper case:\n" << string_1 << endl;
    file_1.close();
    // Task 2.
    string strings_1[] = { "alpha", "beta", "gamma" };
    cout << "Lines with words ";
    for (int i = 0; i < 3; i++) cout << "'" << strings_1[i] << "' ";
    cout << endl;
    file_1.close();
    file_1.open("labs_0x02/files/chapter-4-1.txt", ios::in);
    int line = 0;
    while (getline(file_1,string_1, '\n')) {
        bool isFounded = false;
        for (int i = 0; i < 3 && !isFounded; i++)
            if (string_1.find(strings_1[i], 0)) isFounded = true;
        if (isFounded) cout << line << ":" << string_1 << endl;
        line++;
    }
    cout << endl;
    // Task 3. See file chapter-4-2.txt
    fstream file_2("labs_0x02/files/chapter-4-2.txt", ios::out | ios::in);
    string string_2("String to insert.\n"), string_3;
    getline(file_2, string_3, '\0');
    if (string_3.find(string_2) == string::npos) string_3.insert(0, string_2);
    file_2.seekg(0);
    file_2 << string_3;
    file_2.close();
    // Task 4. See 'man'...
    // Task 5.
    cout << "FieldWidth class test: ";
    cout << FieldWidth("Long string.", 5) << FieldWidth("Short.", 5) << endl;
    // Task 6.
    fstream file_3("labs_0x02/files/chapter-4-2.txt", ios::in);
    string string_4;
    try {
        file_3.exceptions(ios::eofbit | ios::badbit | ios::failbit);
        cout << "Stream exception's flags(eofbit, badbit, failbit): " << file_3.exceptions() << endl;
        while (getline(file_3, string_4, '\n'));
    } catch (...) {
        cout << "Exception from stream, catched." << endl;
    }
    file_3.close();
    // Task 7. Result 3 seconds for atoi(), 8 seconds for operator >>, multiplier x10.
    int int_7;
    string string_5("1");
    istringstream iString(string_5);
    time_t time;
    time = std::time(NULL);
    tm local;
    local = *localtime(&time);
    cout << "Starting second with atoi() function: " << local.tm_sec << endl;
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 100000; j++)
            atoi(string_5.data());
    time = std::time(NULL);
    local = *localtime(&time);
    cout << "After atoi() function: " << local.tm_sec << endl;
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 100000; j++)
            iString >> int_7;
    time = std::time(NULL);
    local = *localtime(&time);
    cout << "After calling inline function: " << local.tm_sec << endl;
    // Task 8-10.
    DataBase_1 db_1("labs_0x02/files/db_1.txt");
    string backup;
    DataBase_1::Cat cat_1, cat_2;
    for (int i = 0; i < 3; i++) {
        cat_1.id = i;
        string name = "Cat_N";
        name[4] = '0'+i;
        cout << name << endl;
        strcpy(cat_1.name, name.data());
        db_1.add(cat_1);
    }
    cout << "Cats in DB_1: ";
    for (int i = 0; i < 3; i++) {
        cat_2 = db_1.retrieve(i);
        cout << cat_2 << " ";
        backup.append(toString(cat_2.id)+":"+string(cat_2.name)+"\n");
    }
    cout << "Backup stirngs for DataBase_1:\n" << backup;
    cout << "Backup restore:\n";
    db_1.fromString(backup);
    // Task 11. For one object. size of(size_t) = 8, size of string = 20;
    size_t num_11 = -1;
    cout << "Size_t = -1(" << num_11 << "), writing to file chapter-4-3.txt as text and to file chapter-4-4.txt as binary.\n";
    fstream file_4, file_5;
    file_4.open("labs_0x02/files/chapter-4-3.txt", ios::out | ios::trunc);
    file_5.open("labs_0x02/files/chapter-4-4.txt", ios::out | ios::trunc);
    for (int i = 0; i < 1; i++) {
        file_4 << num_11;
        file_5.write((char*)&num_11, sizeof(size_t));
    }
    file_4.close();
    file_5.close();
    // Task 12. It seems 53.
    cout << "SQRT(2.0) = " << setprecision(53) << sqrt(2.0) << " - (53 after point)." << endl;
    // Task 13.
    fstream file_6("labs_0x02/files/chapter-4-5.txt");
    string doubleStr;
    vector<double> array_1;
    cout << "All values from file 'chapter-4-5.txt: ";
    while (getline(file_6, doubleStr, '\n')) {
        array_1.push_back(atof(doubleStr.data()));
        cout << doubleStr << " ";
    }
    cout << "\nValues from vector: ";
    for (int i = 0; i < array_1.size(); i++) cout << setprecision(5) << array_1[i] << " ";
    cout << "\nSum, medium, min, max: ";
    double sum = 0, min, max;
    if (!array_1.empty()) {
        min = array_1[0];
        max = array_1[0];
    }
    for (int i = 0; i < array_1.size(); i++) {
        sum += array_1[i];
        if (array_1[i] < min) min = array_1[i];
        if (array_1[i] > max) max = array_1[i];
    }
    cout << sum << ", " << setprecision(2) << sum/(double)array_1.size() << ", " << min << ", " << max << endl;
    file_6.close();
    // Task 14. Pointers to stream, (get,put): (10,20), (10, 5).
    // Task 15.
    string parLine;
    fstream file_7("labs_0x02/files/chapter-4-6.txt");
    const int fields = 6;
    string fieldsName[] = { "Last name:", "First name:", "ID:", "Phone:", "Sales:", "Percent:" };
    const int fieldsW[] = { 12, 12, 6, 13, 12, 12 };
    while ( getline(file_7, parLine, '\n') ) {
        if (parLine.find(',',0) != string::npos) {
            int parBegin = 0, parEnd;
            string params[fields];
            for (int i = 0; i < fields; i++) {
                parEnd = parLine.find(',', parBegin);
                if (parEnd == string::npos) parEnd = parLine.size();
                params[i] = string(parLine, parBegin, parEnd-parBegin);
                parBegin = parEnd+1;
            }
            cout << setw(12) << left << params[2] << setw(12) << left << params[3];
            cout << setw(6) << left << fromHexString(params[0]);
            while (params[1].size() < 10) params[1].insert(0, "X");
            params[1].insert(3, "-");
            params[1].insert(7, "-");
            cout << setw(13) << left << params[1];
            cout << setprecision(2) << setw(12) << left << fixed << atof(params[4].data());
            cout << setprecision(2) << setw(12) << left << scientific << atof(params[5].data());
            cout << endl;
        } else {
            cout << endl << parLine << endl;
            for (int i = 0; i < fields; i++)
                cout << setw(fieldsW[i]) << left << fieldsName[i];
            cout << "\n--------\n";
        }
    }
    file_7.close();
    file_1.close();
}

void Labs_0x02::chapter_05() {
    cout << "Chapter's 5 tasks.\n";
    // Task 1.
    const char c_1 = 'a';
    function_5_1<const char>(c_1);
    function_5_1<int>(2);
    function_5_1(3);
    // Task 2.
    Stack_5<int> st_5;
    st_5.push(1);
    cout << "Value from Stack_5: " << st_5.pop() << endl;
    // Task 3.
    Stack_5_1<int, Stack_5 > st_2;
    st_2.push(1);
    cout << "Value from Stack_5_1: " << st_2.pop() << endl;
    // Task 4. No match for 'operator==', may be not as planned.
    // Task 5. Try char.
    char string_5[4] = { 1, 2, 3, 4 };
    cout << "Sum of char (1, 2, 3, 4) = " << (int)function_5_5<char>(string_5, 0, 3, 0) << endl;
    // Task 6.
    int array_1[] = { 1, 2, 3, 4};
    double array_2[] = { 1.0, 2.0, 3.0, 4.0 };
    cout << "Sum of int (1, 2, 3, 4) in overloaded function: " << function_5_5(array_1, 0, 3, int(0)) << endl;
    cout << "Sum of double (1, 2, 3, 4) in overloaded function: " << function_5_5(array_2, 0, 3, double(0)) << endl;
    // Task 7.
    Class_5_2<int> cl_1;
    Class_5_2<Friendly> cl_2, cl_3;
    // 'int Class_5_2<Friendly>::i' is private.
    // cl_1.play(cl_3);
    cl_2.play(cl_3);
    p_ag(1, 2, 3);
    p_ag(1.0, 2.0, 3.0);
    // no matching for call to 'p_ag(int, double, double)'
    // p_ag(1, 2.0, 3.0);
    cout << "Result of function 'p_ag': " << p_ag<double>(1, 2.0, 3.0) << endl;
    // Task 8. See in .h file.
    // Task 9.
    Class_5_5<int, char> cl_4;
    Class_5_5<char, int> cl_5;
    Class_5_5<char, char> cl_6;
    cl_4.function_1();
    cl_5.function_1();
    cl_6.function_1();
    // Task 10. Strange, works but seems not usable in practice.
    Class_5_6<char> cl_7;
    Class_5_6<int> cl_8;
    cl_7.functionCalls();
    cl_8.functionCalls();
}

void Labs_0x02::chapter_06() {
    cout << "Chapter's 6 tasks.\n";
    // Task 1.
    list<clock_t> list_1;
    cout << "Generated list of clock_t: ";
    generate_n(back_inserter(list_1), 5, function_6_1);
    copy(list_1.begin(), list_1.end(), ostream_iterator<int>(cout, " "));
    list_1.unique();
    cout << "\nList of clock_t, after unique(): ";
    copy(list_1.begin(), list_1.end(), ostream_iterator<int>(cout, " "));
    // Task 2
    string string_1 = "string_1";
    cout << "\nTransform 'string_1' to upper case: ";
    transform(string_1.begin(), string_1.end(), string_1.begin(), to_Upper);
    cout << string_1 << endl;
    // Task 3.
    vector<int> vector_1;
    vector_1.push_back(1);
    vector_1.push_back(2);
    Class_6_1 cl_1(0);
    for_each(vector_1.begin(), vector_1.end(), cl_1);
    cout << "Vector<int>, function object with static sum, 1 + 2 = " << cl_1.sum << endl;
    // Task 4-5.
    string string_2 = "abc";
    cout << "Permutations of 'abc' string: ";
    while (next_permutation(string_2.begin(), string_2.end())) cout << string_2 << " ";
    string string_3 = "Short sentance permutations.";
    vector<string> sentance;
    textToWords(string_3, sentance);
    sort(sentance.begin(), sentance.end());
    cout << "\nPermutations with sentance:\n";
    while (next_permutation(sentance.begin(), sentance.end())) {
        copy(sentance.begin(), sentance.end(), ostream_iterator<string>(cout, " "));
        cout << endl;
    }
    // Task 6.
    cout << "Function adapter, a little old, but works:\n";
    vector<Class_6_2*> vector_2;
    vector_2.push_back(new Class_6_2);
    vector_2.push_back(new Class_6_2_1);
    for_each(vector_2.begin(), vector_2.end(), mem_fun(&Class_6_2::function_1));
    // Tasks 7-8.
    function_6_2<float>();
    // Task 9, partly was in chapter 2.cpp
    vector<int> vector_3;
    multipliers(100, vector_3);
    cout << "Multipliers of '100', size = " << vector_3.size() << ": ";
    copy(vector_3.begin(), vector_3.end(), ostream_iterator<int>(cout, " "));
    // Tasks 10-11.
    vector<ifstream*> files;
    files.push_back(new ifstream);
    files.push_back(new ifstream);
    vector<string> words[3];
    string word;
    files[0]->open("labs_0x02/files/chapter-6-1.txt");
    files[1]->open("labs_0x02/files/chapter-6-2.txt");
    for (int i = 0; i < files.size(); i++) {
        cout << "\nFile 'chapter-6-" << char(i+'1') << ".txt', words: ";
        int j = 0;
        while ( (*files[i] >> word) ) {
            cout << word << " ";
            words[i].push_back(word);
        }
        files[i]->close();
    }
    cout << endl;
    for (int i = 0; i < words[0].size(); i++)
        for_each(words[0][i].begin(), words[0][i].end(), to_Lower);
    sort(words[0].begin(), words[0].end());
    cout << "Delete duplicats and sort, result words[0]: ";
    vector<string>::iterator end = unique(words[0].begin(), words[0].end());
    copy(words[0].begin(), end, ostream_iterator<string>(cout, " "));
    words[0].resize(end - words[0].begin());
    sort(words[1].begin(), words[1].end());
    if (words[0].size() > words[1].size()) words[2].resize(words[0].size()); else words[2].resize(words[1].size());
    set_intersection(words[0].begin(), words[0].end(), words[1].begin(), words[1].end(), words[2].begin());
    cout << "\nResult of set_intersection of words[0] and words[1]: ";
    copy(words[2].begin(), words[2].end(), ostream_iterator<string>(cout, " "));
    for (int i = 0; i < 2; i++) {
        cout << "\nWords[" << i << "]: ";
        copy(words[i].begin(), words[i].end(), ostream_iterator<string>(cout, " "));
    }
    cout << "\nResult of set_symmetric difference of words[0] and words[1]: ";
    end = set_symmetric_difference(words[0].begin(), words[0].end(), words[1].begin(), words[1].end(), words[2].begin());
    words[2].resize(end - words[2].begin());
    copy(words[2].begin(), words[2].end(), ostream_iterator<string>(cout, " "));
    // Task 12.
    int fMax = 5;
    vector<int> factorials(fMax), sums(fMax);
    generate_n(factorials.begin(), fMax, factorial);
    cout << "\nFactorials, n = " << fMax << ": ";
    copy(factorials.begin(), factorials.end(), ostream_iterator<int>(cout, " "));
    partial_sum(factorials.begin(), factorials.end(), sums.begin());
    cout << "\nResult of partial_sum function: ";
    copy(sums.begin(), sums.end(), ostream_iterator<int>(cout, " "));
    // Task 13.
    vector<Class_6_13_1> cl_13, cl_15;
    srand(0);
    generate_n(back_inserter(cl_13), 5, genValues);
    cout << "\nClass_6_13_1 vector:\n";
    copy(cl_13.begin(), cl_13.end(), ostream_iterator<Class_6_13_1>(cout, ""));
    Class_6_13_2 cl_14 = for_each(cl_13.begin(), cl_13.end(), Class_6_13_2());
    cout << cl_14;
    int min = 150;
    // For copy_if() operator, need std=c++11...
    for (int i = 0; i < cl_13.size(); i++)
        if (cl_13[i].getValue() < min) cl_15.push_back(cl_13[i]);
    cout << "Without operator copy_if, vector of Class_6_13_1(less than " << min << "):\n";
    copy(cl_15.begin(), cl_15.end(), ostream_iterator<Class_6_13_1>(cout, ""));
    // Task 14.
    const int vecSize = 10;
    vector<int> vector_4(vecSize), vector_5(vecSize), vector_6(vecSize);
    Generator_2 gen_2(100);
    generate_n(vector_4.begin(), vecSize, gen_2);
    cout << "Source vector_4: ";
    copy(vector_4.begin(), vector_4.end(), ostream_iterator<int>(cout, " "));
    transform(vector_4.begin(), vector_4.end(), vector_5.begin(), bind2nd(modulus<int>(), 3));
    cout << "\nDestination vector_5(modulus 3): ";
    copy(vector_5.begin(), vector_5.end(), ostream_iterator<int>(cout, " "));
    transform(vector_5.begin(), vector_5.end(), vector_6.begin(), bind2nd(divides<int>(), 2));
    cout << "\nDestination vector divided by 2: ";
    copy(vector_6.begin(), vector_6.end(), ostream_iterator<int>(cout, " "));
    // Task 15.
    vector<double> vector_7(vecSize);
    cout << "\nVector_7, sin(radians): ";
    vector<Class_6_15> vector_8;
    for (int i = 0; i < 10; i++) vector_8.push_back(Class_6_15());
    transform(vector_8.begin(), vector_8.end(), vector_7.begin(), compose(pointer_to_unary_function<double,double>(sin), mem_fun_ref(&Class_6_15::getRadian)));
    copy(vector_7.begin(), vector_7.end(), ostream_iterator<double>(cout, " "));
    // Task 16. Very fast...
    cout << "\nPerfomnace of 'equal' for pair of vectors..." << endl;
    srand(time(0));
    vector<int> vector_9, vector_10;
    generate_n(back_inserter(vector_9), 1048576, rand );
    srand(time(0));
    generate_n(back_inserter(vector_10), 1048576, rand );
    equal(vector_9.begin(), vector_9.end(), vector_10.begin(), equal_to<int>());
    cout << "Operation complete." << endl;
    // Task 17.
    vector<int> vector_11;
    for (int i = 0; i < 5; i++) vector_11.push_back(5);
    cout << "Original values from vector_11: ";
    copy(vector_11.begin(), vector_11.end(), ostream_iterator<int>(cout, " "));
    transform_if(vector_11.begin(), vector_11.end(), vector_11.begin(), bind2nd(equal_to<int>(),5), 0);
    cout << "\nValues of vector_11 after transform_if algorithm: " ;
    copy(vector_11.begin(), vector_11.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    // Task 18.
    vector<int> vector_12, vector_13, vector_14;
    for (int i = 0; i < 5; i++) {
        vector_12.push_back(i);
        vector_13.push_back(i);
        vector_14.push_back(0);
    }
    cout << "Vector_12: ";
    copy(vector_12.begin(), vector_12.end(), ostream_iterator<int>(cout, " "));
    cout << "\nVector_13: ";
    copy(vector_13.begin(), vector_13.end(), ostream_iterator<int>(cout, " "));
    for_each_alt(vector_12.begin(), vector_12.end(), vector_13.begin(), vector_14.begin(), std::plus<int>());
    cout << "\nResult vector_14: ";
    copy(vector_14.begin(), vector_14.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    // Task 19.
    Matrix<int> matrix_1(3, 3), matrix_2(3, 3, 3), matrix_3(3, 3, 0);
    Matrix<int> matrix_4(3, 4, 0), matrix_5(4, 5, 1), matrix_6(3, 5, 0), matrix_7(3, 1, 0);
    vector<int> vector_15;
    for (int i = 0; i < 4; i++) vector_15.push_back(i);
    cout << "Source matrix_1:\n" << matrix_1;
    cout << "Source matrix_2:\n" << matrix_2;
    matrix_3 = matrix_1 + matrix_2;
    cout << "Result of matrix_1 + matrix_2:\n" << matrix_3;
    cout << "Source matrix_4:\n" << matrix_4;
    cout << "Source matrix_5:\n" << matrix_5;
    matrix_6 = matrix_4 * matrix_5;
    cout << "Result of matrix_4 * matrix_5:\n" << matrix_6;
    cout << "Source vector_15: ";
    copy(vector_15.begin(), vector_15.end(), ostream_iterator<int>(cout, " "));
    matrix_7 = matrix_4 * vector_15;
    cout << "\nResult of matrix_4 * vector_15:\n" << matrix_7;
    // Task 20. After crypt, using one space. Lex_cmp not useful in that case.
    fstream fileMap;
    fileMap.open("labs_0x02/files/chapter-6-3.txt", ios::in | ios::out);
    cout << "Source file 'chapter-6-3.txt':\n";
    string string_4;
    getline(fileMap, string_4, '\0');
    cout << string_4;
    map<string, string> map_1;
    vector<string> vector_16, vector_17;
    int pos = 1, next = 1;
    while ( (next = string_4.find('"', pos)) != string::npos) {
        string key(string_4, pos, next-pos);
        cout << "key = " << key;
        pos = next + 2;
        next = string_4.find('\n', pos);
        string value(string_4, pos, next-pos);
        cout << ", value = " << value << endl;
        pos = next + 2;
        map_1[key] = value;
        if (vector_16.size() < 2) vector_16.push_back(value); else vector_17.push_back(value);
    }
    vector< vector<string> > lexVector;
    lexVector.push_back(vector_16);
    lexVector.push_back(vector_17);
    sort(lexVector.begin(), lexVector.end(), function_6_20);
    cout << "Sorted vector_16: ";
    copy(vector_16.begin(), vector_16.end(), ostream_iterator<string>(cout, " "));
    cout << "\nSorted vector_17: ";
    copy(vector_17.begin(), vector_17.end(), ostream_iterator<string>(cout, " "));
    for (map<string, string>::iterator it = map_1.begin(); it != map_1.end(); it++) {
        int pos = 0;
        while ( (pos = string_4.find(it->second)) != string::npos) {
            string_4.replace(pos, it->second.size(), it->first);
            pos++;
        }
    }
    cout << "\nResult of the first replacement:\n" << string_4;
    for (map<string, string>::iterator it = map_1.begin(); it != map_1.end(); it++) {
        int pos = 0;
        while ( (pos = string_4.find(it->first, pos)) != string::npos) {
            if (pos > 0 && string_4[pos-1] != '"')
                string_4.replace(pos, it->second.size()-1, it->second);
            else
                pos++;
        }
    }
    cout << "Result of the second replacement:\n" << string_4;
    fileMap.close();
    // Tasks 21-22.
    vector<string> vector_18, vector_19;
    vector< vector<string> > vector_20;
    vector_18.push_back("Mike");
    vector_18.push_back("John");
    vector_18.push_back("Ralph");
    vector_19.push_back("Sharon");
    vector_19.push_back("Jane");
    vector_19.push_back("Kate");
    sort(vector_18.begin(), vector_18.end());
    sort(vector_19.begin(), vector_19.end());
    cout << "All possible combinations:\n";
    for (int i = 0; i < vector_18.size(); i++) {
        vector<string> setNames;
        for (int j = 0; j < vector_18.size(); j++) {
            setNames.push_back(vector_18[j] + " " + vector_19[j]);
            cout << i << ": " << vector_18[j] + " " + vector_19[j] << endl;
        }
        vector_20.push_back(setNames);
        rotate(vector_19.begin(), vector_19.begin() + 1, vector_19.end());
    }
    cout << "All combinatiosn with John and Jane:\n";
    for (int i = 0; i < vector_20.size(); i++)
        if ( find(vector_20[i].begin(), vector_20[i].end(), "John Jane") != vector_20[i].end() )
            for (int j = 0; j < vector_20[i].size(); j++) cout << i << ": " << vector_20[i][j] << endl;
    // Task 23.
    vector<int> vector_21(20);
    generate_n(vector_21.begin(), 20, function_6_23_1);
    cout << "Source vector_21: ";
    copy(vector_21.begin(), vector_21.end(), ostream_iterator<int>(cout, " "));
    remove_if(vector_21.begin(), vector_21.end(), function_6_23_2);
    cout << "\nSource vector_21, after removing elements which less than 10 and more than 20: ";
    copy(vector_21.begin(), vector_21.end(), ostream_iterator<int>(cout, " "));
    int sum = 0;
    for (int i = 0; i < vector_21.size(); i++)
        sum += vector_21[i];
    cout << "\nMedian of vector_21: " << sum / vector_21.size() << endl;
    // Task 24. Too fast...
    vector<int> vector_22;
    for (int i = 0; i < 0x10; i++) vector_22.push_back(i);
    sort(vector_22.begin(), vector_22.end());
    cout << "Source vector_22: ";
    copy(vector_22.begin(), vector_22.end(), ostream_iterator<int>(cout, " "));
    cout << "\nSearching with 'find'..." << endl;
    vector<int>::iterator founded = find(vector_22.begin(), vector_22.end(), 5);
    cout << "Verification: " << *founded << endl;
    cout << "Searching with 'binary_search'..." << endl;
    bool isFounded = binary_search(vector_22.begin(), vector_22.end(), 5);
    cout << "Verification: " << isFounded << endl;
    // Task 25.
    vector<Class_6_25> vector_23;
    cout << "Full list of vector_23<Class_6_25>:\n";
    for (int i = 0; i < 10; i++) {
        vector_23.push_back(Class_6_25());
        cout << vector_23[vector_23.size()-1].age << " " << vector_23[vector_23.size()-1].year << endl;
    }
    vector<Class_6_25>::iterator lastPartElem = partition(vector_23.begin(), vector_23.end(), Class_6_25::isFirstPart);
    cout << "After partition vector_23<Class_6_25>:\n";
    for (int i = 0; i < 10; i++)
        cout << vector_23[i].age << " " << vector_23[i].year << endl;
    cout << "After sort vector_23<Class_6_25>:\n";
    sort(vector_23.begin(), lastPartElem, Class_6_25::isLess);
    sort(lastPartElem, vector_23.end(), Class_6_25::isLess);
    for (int i = 0; i < 10; i++)
        cout << vector_23[i].age << " " << vector_23[i].year << endl;
    // Task 26-30.
    vector<Town> vector_24, vector_25, vector_26;
    cout << "Full vector_24<Town>:\n";
    fstream file_1;
    file_1.open("labs_0x02/files/chapter-6-4.txt", ios::out | ios::in | ios::trunc);
    for (int i = 0; i < 10; i++) {
        vector_24.push_back(Town());
        cout << vector_24[i];
        file_1 << vector_24[i];
    }
    transform(vector_24.begin(), vector_24.end(), vector_24.begin(), Town::populationGrowth);
    cout << "After first transform vector_24<Town>:\n";
    file_1 << "After first transform vector_24<Town>:\n";
    copy (vector_24.begin(), vector_24.end(), ostream_iterator<Town>(cout));
    copy (vector_24.begin(), vector_24.end(), ostream_iterator<Town>(file_1));
    vector<Town>::iterator minTown = min_element(vector_24.begin(), vector_24.end(), Town::isLess);
    vector<Town>::iterator maxTown = max_element(vector_24.begin(), vector_24.end(), Town::isLess);
    cout << "Minimum town: " << *minTown;
    cout << "Maximum town: " << *maxTown;
    vector_25.resize(vector_24.size());
    vector<Town>::iterator endIt = remove_copy_if(vector_24.begin(), vector_24.end(), vector_25.begin(), Town::isEqual);
    vector_25.resize(endIt-vector_25.begin());
    cout << "All towns with height in [25,75]:\n";
    copy(vector_25.begin(), vector_25.end(), ostream_iterator<Town>(cout));
    cout << "Delete towns within height of 25:\n";
    vector_25 = vector_24;
    endIt = unique(vector_25.begin(), vector_25.end(), Town::isNear);
    vector_25.resize(endIt - vector_25.begin());
    copy (vector_25.begin(), vector_25.end(), ostream_iterator<Town>(cout));
    cout << "Sorting of previous vector_25, default:\n";
    vector_26 = vector_25;
    sort(vector_26.begin(), vector_26.end());
    copy (vector_26.begin(), vector_26.end(), ostream_iterator<Town>(cout));
    cout << "Sorting of previous vector_25, with Town::isLess():\n";
    sort(vector_26.begin(), vector_26.end(), Town::isLess);
    copy (vector_26.begin(), vector_26.end(), ostream_iterator<Town>(cout));
    file_1.close();
    // Task 31.
    vector<int> vector_27;
    cout << "Source vector_27<int>: ";
    for (int i = 0; i < 10; i++) {
        vector_27.push_back(rand() % 10);
        cout << vector_27[vector_27.size()-1] << " ";
    }
    vector<int>::iterator tail = vector_27.end(), maxE;
    while (tail != vector_27.begin()) {
        maxE = max_element(vector_27.begin(), tail);
        swap_ranges(maxE, maxE + 1, --tail);
    }
    cout << "\nAfter simple sorting: ";
    copy(vector_27.begin(), vector_27.end(), ostream_iterator<int>(cout, " "));
    // Task 32-33.
    file_1.open("labs_0x02/files/chapter-6-5.txt", ios::in | ios::out);
    string text;
    vector<string> names, phones;
    map<string, string> map_2;
    getline(file_1, text, '\0');
    cout << "\nFile 'chapter-6-5.txt:\n" << text;
    file_1.close();
    cout << "Create lists of names and numbers vector<string>:\n";
    pos = 0;
    while ( (next = text.find('\t', pos)) != string::npos) {
        int endL = text.find('\n', pos);
        names.push_back( string(text, pos, next-pos) );
        phones.push_back( string(text, next, endL-next) );
        pos = text.find('\n', pos) + 1;
    }
    for ( int i = 0; i < names.size(); i++)
        cout << names[i] << phones[i] << endl;
    cout << "After replace text:\n";
    pos = 0, next = 0;
    string newS = "755";
    while ( (pos = text.find("333", pos)) != string::npos) {
        text.replace(pos, newS.size(), newS);
        pos++;
    }
    cout << text;
    cout << "First string with name 'John', using lower_bound: " << *lower_bound(names.begin(), names.end(), "John") << endl;
    cout << "First string with name 'Jane', using upper_bound: " << *upper_bound(names.begin(), names.end(), "Jane") << endl;
    pair< vector<string>::iterator, vector<string>::iterator> range;
    cout << "First string with name 'John', using equal_range: ";
    range = equal_range(names.begin(), names.end(), "John");
    cout << distance(names.begin(), range.first) + 1 << " up to " << distance(names.begin(), range.second) + 1 << endl;
    // Task 34.
    fstream file_2;
    file_2.open("labs_0x02/files/chapter-6-6.txt", ios::in | ios::out);
    text.clear();
    getline(file_2, text, '\0');
    file_2.seekg(0, ios::end);
    cout << "Source of file 'chater-6-6.txt':\n" << text;
    pos = 0, next = 0;
    while ( (next = text.find('\n', pos)) != string::npos ) {
        if (next - pos <= 2) {
            string w(text, pos, next-pos);
            file_2 << w << endl;
        }
        pos = next + 1;
    }
    file_2.close();
    // Task 35.
    vector<Employee*> vector_28;
    for (int i = 0; i < 5; i++) vector_28.push_back(new Employee());
    sum = 0;
    for (int i = 0; i < vector_28.size(); i++) sum += vector_28[i]->salary();
    cout << "Sum of salaries of vector_28<*Employee>: " << sum << endl;
    // Task 36. Just testing...
    vector<int> vector_29;
    for (int i = 0; i < 10; i++) vector_29.push_back(rand() % 10);
    sort(vector_29.begin(), vector_29.end());
    partial_sort(vector_29.begin(), vector_29.begin() + 3, vector_29.end());
    nth_element(vector_29.begin(), vector_29.begin() + 5, vector_29.end());
    cout << "Vector<int> sorted: ";
    copy(vector_29.begin(), vector_29.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void Labs_0x02::chapter_07() {
    cout << "Chapter's 7 tasks.\n";
    // Task 1. All ok...
    fstream file;
    file.open("labs_0x02/files/chapter-7-1.txt", ios::in);
    string text;
    set<char> set_1;
    getline(file, text, '\0');
    cout << "Source file 'chapter-7-1.txt:\n" << text;
    for (int i = 0; i < text.size(); i++) set_1.insert(text[i]);
    cout << "All characters in set_1<char>: ";
    copy(set_1.begin(), set_1.end(), ostream_iterator<char>(cout, " "));
    file.close();
    // Task 2. Without testing perfomance.
    vector<Noisy> vector_1;
    list<Noisy> list_1;
    deque<Noisy> deque_1;
    cout << endl;
    for (int i = 0; i < 3; i++) {
        vector_1.push_back(Noisy());
        deque_1.push_back(Noisy());
        list_1.push_back(Noisy());
    }
    function_7_2<vector <Noisy> > (vector_1);
    function_7_2<deque <Noisy> > (deque_1);
    function_7_2(list_1);
    Noisy::report();
    // Task 3. Too fast for testing perfomance. std::sort not actual...
    list<int> list_2, list_3;
    for (int i = 4; i >= 0; i--) {
        list_2.push_back(i);
        list_3.push_back(i);
    }
    list_2.sort();
    // sort(list_3.begin(), list_3.end());
    cout << "Source of list_2<int>: ";
    copy(list_2.begin(), list_2.end(), ostream_iterator<int>(cout, " "));
    cout << "\nSource of list_3<int>: ";
    copy(list_2.begin(), list_2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    // Task 4.
    multiset<int> multiset_1;
    cout << "Multiset<int> elements: ";
    for (int i = 0; i < 10; i++) multiset_1.insert(rand() % 10);
    for (multiset<int>::iterator it_1 = multiset_1.begin(); it_1 != multiset_1.end(); it_1++)
        cout << *it_1 << "[" << multiset_1.count(*it_1) << "] ";
    cout << endl;
    // Task 5.
    deque<Shape*> deque_2;
    deque_2.push_back(new Circle);
    deque_2.push_back(new Square);
    deque_2.push_back(new Triangle);
    deque<Shape*>::iterator it_2;
    for ( it_2 = deque_2.begin(); it_2 != deque_2.end(); it_2++) (*it_2)->draw();
    for ( it_2 = deque_2.begin(); it_2 != deque_2.end(); it_2++) delete (*it_2);
    // Task 6.
    file.open("labs_0x02/files/chapter-7-1.txt", ios::in);
    list<string> list_4;
    deque<string> deque_3;
    while ( (getline(file, text, '\n')) ) {
        list_4.push_back(text);
        deque_3.push_back(text);
    }
    cout << "All lines from file 'chapter-7-1.txt' in reverse, using list<string>:\n";
    for ( list<string>::reverse_iterator it_3 = list_4.rbegin(); it_3 != list_4.rend(); it_3++) cout << *it_3 << endl;
    cout << "All lines from file 'chapter-7-1.txt' in reverse, using deque<string>:\n";
    for ( deque<string>::reverse_iterator it_4 = deque_3.rbegin(); it_4 != deque_3.rend(); it_4++) cout << *it_4 << endl;
    file.close();
    // Task 7.
    const int fibMax = 10;
    stack<int> stack_1;
    cout << "Fiboncci numbers: ";
    for (int i = 0; i < fibMax; i++)
        if (i < 2)
            stack_1.push(1);
        else {
            int prev_1 = stack_1.top();
            stack_1.pop();
            int prev_2 = stack_1.top();
            stack_1.push(prev_1);
            stack_1.push(prev_1 + prev_2);
        }
    for (int i = 0; i < fibMax; i++) {
        cout << stack_1.top() << " ";
        stack_1.pop();
    }
    // Task 8. Not clear...
    stack<int> source, sorted, less;
    for (int i = 0; i < 10; i++) source.push(rand() % 10);
    printStack(source, "source");
    while ( !source.empty() ) {
        sortStack(source, sorted, less);
        sortStack(less, sorted, source);
    }
    cout << "After sort.\n";
    printStack(source, "source");
    printStack(sorted, "sorted");
    printStack(less, "less");
    // Task 9-10.
    file.open("labs_0x02/files/chapter-7-1.txt", ios::in);
    getline(file, text, '\0');
    file.close();
    multiset<string> multiset_2;
    map<string, int> wordMap;
    int pos = 0, next = 0;
    while ( (next = text.find_first_of(" \n\0", pos)) != string::npos ) {
        string word(text, pos, next-pos);
        multiset_2.insert(word);
        if ( wordMap.find(word) == wordMap.end() ) wordMap.insert(pair<string, int>(word, 1)); else
            (*wordMap.find(word)).second++;
        pos = next + 1;
    }
    cout << "Words and counters in multiset<string>: ";
    for (multiset<string>::iterator it_3 = multiset_2.begin(); it_3 != multiset_2.end(); it_3++)
        cout << *it_3 << "[" << multiset_2.count(*it_3) << "] ";
    cout << "\nWords and counters in map<string, int>: ";
    for (map<string, int>::iterator it_4 = wordMap.begin(); it_4 != wordMap.end(); it_4++)
        cout << (*it_4).first << "[" << (*it_4).second << "] ";
    cout << endl;
    // Task 11.
    priority_queue<Class_7_11> pQueue;
    cout << "Priority queue:\n";
    for (int i = 0; i < 5; i++) pQueue.push(Class_7_11());
    for (int i = 0; i < 5; i++) {
        cout << pQueue.top();
        pQueue.pop();
    }
    // Task 12-13.
    Ring< std::string, std::deque > ring_1;
    ring_1.push_back("one");
    ring_1.push_back("two");
    Ring< std::string, std::deque >::iterator it_5 = ring_1.begin();
    it_5.insert("three");
    it_5 = ring_1.begin();
    cout << "All strings in Ring<string>: ";
    for (int i = 0; i < 10; i++) cout << *it_5++ << " ";
    cout << endl;
    // Task 14. Very strange.
    BitBucket<Noisy> bucket;
    bucket.fill(vector_1);
    // Task 15. Without keyboard input.
    cout << "Words in map<string, int>: ";
    srand(4);
    int wordIdx = rand() % wordMap.size(), idx = 0;
    string word;
    for (map<string, int>::iterator it_4 = wordMap.begin(); it_4 != wordMap.end(); it_4++, idx++) {
        if (idx == wordIdx) word = (*it_4).first;
        cout << (*it_4).first << " ";
    }
    cout << "\nChosen word is: " << word;
    vector<Class_7_15> vector_2;
    for (int i = 0; i < word.size(); i++) vector_2.push_back(Class_7_15(word[i]));
    vector<int> vector_3;
    vector_3.resize(vector_2.size());
    fill(vector_3.begin(), vector_3.end(), 0);
    for (int i = 0; i < 30; i++) {
        char fC = rand() % 26 + 'A';
        for (int i = 0; i < word.size(); i++)
            if ( vector_2[i].exist(fC) )
                vector_3[i] = 1;
    }
    cout << "\nAfter 30 iterations, the existing letters is: ";
    for (int i = 0; i < vector_3.size(); i++)
        if ( vector_3[i] ) cout << vector_2[i].getLetter(); else cout << "_";
    cout << endl;
    // Task 16.
    cout << "Words from file 'chapter-7-1.txt': ";
    stringstream strStream(text);
    list<string> list_5;
    Delim delims(" \t\n~;()\"<>:{}[]+-=&*#.,/\\");
    ostream_iterator<string> console(cout, " ");
    istreambuf_iterator<char> isBegin(strStream), isEnd;
    TokenIt<istreambuf_iterator<char>, Delim> wordIt(isBegin, isEnd, delims), end;
    copy(wordIt, end, back_inserter(list_5));
    copy(list_5.begin(), list_5.end(), console);
    // Task 17. Too fast, just trying.
    stack<int, vector<int> > stack_2;
    stack<int, deque<int> > stack_3;
    stack<int, list<int> > stack_4;
    for (int i = 0; i < 5; i++) {
        stack_2.push(i);
        stack_3.push(i * 2);
        stack_4.push(i * 3);
    }
    cout << "\nStacks variants (vector, deque, list), all elements: ";
    for (int i = 0; i < 5; i++) {
        cout << stack_2.top() << " ";
        stack_2.pop();
        cout << stack_3.top() << " ";
        stack_3.pop();
        cout << stack_4.top() << " ";
        stack_4.pop();
    }
    // Task 18.
    cout << endl;
    FList<int> flist;
    cout << "Is forwarded list empty: " << flist.empty() << endl;
    for (int i = 0; i < 5; i++) flist.push(i);
    cout << "Is forwarded list empty after pushing: " << flist.empty() << endl;
    flist.print();
    for (int i = 0; i < 2; i++) flist.pop();
    flist.print();
    FList<int>::iterator it_1 = flist.begin();
    it_1++;
    cout << "Inserting element 7...\n";
    flist.insertAfter(it_1, 7);
    flist.print();
    cout << "Erasing element 7...\n";
    flist.eraseAfter(it_1);
    flist.print();
    // Task 19. A little strange with median.
    const int vecSize = 10;
    int vector_4[vecSize];
    cout << "Elements of 'vector_4': ";
    for (int i = 0; i < vecSize; i++) cout << (vector_4[i] = rand() % vecSize) << " ";
    valarray<int> valarray_1(vector_4, vecSize);
    cout << "\nSize of valarray<int> " << valarray_1.size() << ", elements: ";
    for (int i = 0; i < valarray_1.size(); i++) cout << valarray_1[i] << " ";
    cout << "\nMinimum " << valarray_1.min() << ", maximum " << valarray_1.max() << ", sum " << valarray_1.sum();
    cout << "\nMedian " << valarray_1[vecSize/2] << ", arithmetical mean " << valarray_1.sum() / vecSize << endl;
    // Task 20.
    valarray<int> valarray_2;
    valarray<int> valarray_3;
    valarray<int> valarray_4;
    valarray_2.resize(12);
    valarray_3.resize(20);
    for (int i = 0; i < 12; i++) valarray_2[i] = rand() % 5;
    for (int i = 0; i < 20; i++) valarray_3[i] = rand() % 5;
    printMatrix(valarray_2, 12, 3);
    printMatrix(valarray_3, 20, 4);
    valarray_4.resize(5 * 5);
    valarray_4 = multiplyMatrix(valarray_2, 4, 3, valarray_3, 5, 4);
    printMatrix(valarray_4, 16, 4);
}

void Labs_0x02::chapter_08() {
    cout << "Chapter's 8 tasks.\n";
    // Task 1. Testing both variants...
    vector<Base*> vector_1;
    vector<Derived*> vector_2;
    for (int i = 0; i < 5; i++)
        if ( i % 2 ) vector_1.push_back(new Base); else vector_1.push_back(new Derived);
    cout << "All types in vector_1:\n";
    for (int i = 0; i < vector_1.size(); i++) {
        string typeN(typeid(*vector_1[i]).name());
        cout << i << ": " << typeN << endl;
        if ( typeN.find("Derived") != string::npos) {
            Derived* dPtr = dynamic_cast<Derived*>(vector_1[i]);
            vector_2.push_back(dPtr);
        }
    }
    cout << "All types in vector_2:\n";
    for (int i = 0; i < vector_2.size(); i++) cout << typeid(*vector_2[i]).name() << endl;
    // Tasks 2-3. Just works fine.
    vector<Class_2*> vector_3;
    vector<Class_3*> vector_4;
    for (int i = 0; i < 3; i++) {
        vector_3.push_back(new Class_2());
        vector_4.push_back(new Class_3());
    }
    vector_3[0]->debug.trace();
    vector_4[1]->debug.trace();
    vector_3[0]->debug.verify();
    vector_4[1]->debug.verify();
    for (int i = 0; i < vector_3.size(); i++) {
        delete(vector_3[i]);
        delete(vector_4[i]);
    }
    // Tasks 4-5.
    vector<Instrument*> vector_5;
    vector_5.push_back(new Wind);
    vector_5.push_back(new Stringed);
    vector_5.push_back(new Instrument);
    for (int i = 0; i < vector_5.size(); i++) vector_5[i]->prepare();
    // Task 6-7. Virtual calls more convinient here.
    vector<Shape*> vector_6, vector_7;
    for (int i = 0; i < 10; i++)
        switch (rand() % 3) {
        case 0:
            vector_6.push_back(new Circle);
            break;
        case 1:
            vector_6.push_back(new Triangle);
            break;
        case 2:
            vector_6.push_back(new Square);
            break;
        default:
            break;
        }
    cout << "Sorting vector with Circles.\n";
    vector<Circle*> vector_8;
    vector<Square*> vector_9;
    for (int i = 0; i < vector_6.size(); i++) {
        string className = typeid(*vector_6[i]).name();
        if ( className.find("Circle") !=  string::npos ) vector_8.push_back(dynamic_cast<Circle*>(vector_6[i])); else
            if ( className.find("Square") != string::npos ) vector_9.push_back(dynamic_cast<Square*>(vector_6[i]));
    }
    sort(vector_8.begin(), vector_8.end(), greaterRadius);
    sort(vector_9.begin(), vector_9.end(), greaterPerimeter);
    for (int i = 0; i < vector_8.size(); i++) vector_8[i]->altDraw();
    cout << "Sorting vector with Squares.\n";
    for (int i = 0; i < vector_9.size(); i++) vector_9[i]->altDraw();
    vector_7 = vector_6;
    for (int i = 0; i < vector_7.size(); i++)
        vector_7[vector_7.size() - 1]->altDraw();
    // Task 8. Not so intresting...
    cout << "Stack of calls in vector with 'Pets*'.\n";
    vector<Pet*> vector_10;
    for (int i = 0; i < 10; i++)
        switch (rand() % 3) {
        case 0:
            vector_10.push_back(new Dog);
            break;
        case 1:
            vector_10.push_back(new Cat);
            break;
        case 2:
            vector_10.push_back(new Horse);
            break;
        default:
            break;
        }
    cout << "Calling all virtual functions 'eat' for the classes Dog, Cat and Horse.\n";
    Beef food_1;
    Fish food_2;
    Oats food_3;
    for (int i = 0; i < vector_10.size(); i++) {
        string className = typeid(*vector_10[i]).name();
        if ( className.find("Dog") != string::npos ) dynamic_cast<Dog*>(vector_10[i])->eat(food_1); else
            if ( className.find("Cat") != string::npos ) dynamic_cast<Cat*>(vector_10[i])->eat(food_2); else
                if ( className.find("Horse") != string::npos ) dynamic_cast<Horse*>(vector_10[i])->eat(food_3);
    }
    // Task 9-10.
    vector<Shape*> vector_11;
    for (int i = 0; i < 12; i++) {
        switch (rand() % 4) {
        case 0:
            vector_11.push_back(new Circle);
            break;
        case 1:
            vector_11.push_back(new Triangle);
            break;
        case 2:
            vector_11.push_back(new Square);
            break;
        case 3:
            vector_11.push_back(new Rectangle);
            break;
        default:
            break;
        }
    }
    for_each(vector_11.begin(), vector_11.end(), drawQuad);
    cout << "After sorting vector<Shape*> with type_info::before().\n";
    sort(vector_11.begin(), vector_11.end(), lessShapeType);
    for_each(vector_11.begin(), vector_11.end(), drawQuad);
}

void Labs_0x02::chapter_09() {
    cout << "Chapter's 9 tasks.\n";
    // Tasks 1-2. Works only in .cpp, specified namespace.
    Class_A cl_1;
    cl_1.Class_Y::function();
    Class_A* ptr_1 = &cl_1;
    // Task 3. May be with the old version of compiler, it was possible to trace, but now it's error 'ambigous'.
    ptr_1->Class_Y::function();
    // Task 4-7.
    Bat cl_2(1);
    Tarantool cl_3(2);
    FatCat cl_4(3);
    noisy(&cl_3);
    noisy(&cl_4);
    move(&cl_3, &cl_4);
    save(&cl_2, new Train, new Car);
    // Task 8-9. Work fine with current hierarchy of classes.
    save(&cl_4, new Train, new Car);
    // Task 10. Both variants works fine.
    FunnyFatCat cl_5(4), cl_6(5);
    cl_5.Bat::eat(5);
    cl_5.eat('a');
    // Task 11-12.
    cl_6 = cl_5;
    cout << cl_6;
    cl_4.workout();
    // Task 13. Works fine, except calling virtual method.
    SuperCat* cl_7_ptr = new SuperCat(6);
    FatCat* ptr_2 = (FatCat*)(cl_7_ptr);
    cout << "Using dangerous convertion from SuperCat class to FatCat.\n";
    ptr_2->move();
    ptr_2->noise();
    ptr_2->eat('a');
    // Task 14. Not working as described, maybe too old, simply add another layer of absctraction.
    cout << "\nUsing class HuntingCat.\n";
    HuntingCat cl_8(7);
    cl_8.work();
    // Task 15. Works, but very strange scheme of task.
    Class_15 cl_9;
    for (int i = 0; i < 3; i++) cl_9.create();
    // Task 16. Ok, 'using' works correctly.
    Class_16_3 cl_10;
    cl_10.function();
    Class_16_4 cl_11;
    cl_11.function();
}

void Labs_0x02::chapter_10() {
    cout << "Chapter's 10 tasks.\n";
    // Task 1. No, method instance() not required.
    Singleton::setValue(5);
    cout << "Singleton::getValue() = " << Singleton::getValue() << endl;
    // Task 2. Simplify...
    cout << "Result of Class_10_2::reader():\n" << Class_10_2::readFile();
    // Task 3.
    cout << "Creating 3 objects of Class_10_3, limit 3.\n";
    Class_10_3::init(3);
    Class_10_3* lastObj;
    for (int i = 0; i < 5; i++) Class_10_3::create(lastObj);
    // Task 4. Think about namespaces for classes. Undefined behaviour, but works.
    StateRotation rotate;
    for (int i = 0; i < 5; i++) {
        rotate.function();
        rotate.action();
    }
    // Task 5. Iterator delete elements from the stack.
    Stack_10<std::string> stack;
    stack.push(new string("first"));
    cout << "Stack<string> elements: " << *stack.peek() << " ";
    stack.push(new string("second"));
    cout << *stack.peek() << " ";
    stack.push(new string("third"));
    cout << *stack.peek() << endl;
    StackAdapter<string> stackA(stack);
    StackAdapter<string>::iterator it_1(stackA);
    cout << "All iterators in StackAdapter:\n";
    while ( it_1 != stackA.end() ) cout << it_1++;
    stack.push(new string("first"));
    stack.push(new string("second"));
    stack.push(new string("third"));
    cout << "All elements and algorithm 'for_each':\n";
    for_each(stackA.begin(), stackA.end(), function_10_5);
    // Tasks 6-7. Ok, uncomment later for not mess with files.
    string files("labs_0x02/files/chapter-10-1.txt");
    vector<string> fileNames;
    cout << "Source text files:\n";
    for (int i = 1; i <= 3; i++) {
        files[files.find("-", 0) + 4] = char('0' + i);
        fileNames.push_back(files);
        cout << fileNames[fileNames.size()-1] << endl;
    }
    Class_10_6_1 cl_1(fileNames);
    Class_10_6_2 cl_2(fileNames);
    // class_1.toUpperCase();
    // cl_2.searchWords();
    Class_10_7 cl_3(cl_1), cl_4(cl_2);
    // cl_3.toUpperCase();
    // cl_4.searchWords();
    // Tasks 8-9.
    vector<Class_10_8*> vector_1;
    vector_1.push_back(new Class_10_8_1);
    vector_1.push_back(new Class_10_8_2);
    vector_1.push_back(new Class_10_8_3);
    Class_10_8_4 cl_5(vector_1);
    for (int i = 0; i < 5; i++) cl_5.function();
    // Tasks 10-11.
    vector<ShapeF1*> vector_2;
    const char* classNames[] = { "Circle", "Square", "Square", "Triangle", "Circle" };
    try {
        for (int i = 0; i < sizeof(classNames) / sizeof (char*); i++)
            vector_2.push_back( ShapeF1::factory(classNames[i]) );
    } catch (ShapeF1::Error err) {
        cout << err.what() << endl;
    }
    for (int i = 0; i < vector_2.size(); i++) {
        vector_2[i]->draw();
        vector_2[i]->erase();
        delete ( vector_2[i] );
    }
    vector<ShapeF2*> vector_3;
    cout << "Polymorphic factory:\n";
    try {
        for (int i = 0; i < sizeof(classNames) / sizeof(char*); i++)
            vector_3.push_back(FactoryShapeF2::factory(classNames[i]));
    } catch ( FactoryShapeF2::Error e ) {
        cout << e.what() << endl;
    }
    for (int i = 0; i < vector_3.size(); i++) {
        vector_3[i]->draw();
        vector_3[i]->erase();
        delete vector_3[i];
    }
    // Task 12.
}

void labs_0x02() {
    chapter_10();
}
