#include <iostream>
#include <errno.h>
#include <signal.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <exception>
#include <sstream>
#include <ctime>
#include <math.h>
#include <algorithm>
#include <iterator>

#include "labs_0x02.h"
#include "chapter_01.h"
#include "chapter_02.h"
#include "chapter_03.h"
#include "chapter_04.h"
#include "chapter_05.h"
#include "chapter_06.h"

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
    int word = 0, space = 0;
    while ((space = string_3.find_first_of(" .,!?\0", word)) != string::npos && word < string_3.size()) {
        sentance.push_back(string(string_3, word, space-word));
        word = ++space;
    }
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
}

void labs_0x02() {
    chapter_06();
}
