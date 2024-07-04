#include "22_Generic_Algorithms.hpp"

using namespace std;

clock_t function_6_1() { return clock(); }

char to_Upper(char c) {
    if (c >= 'a' && c <= 'z') c += 'A' - 'a';
    return c;
}

char to_Lower(char c) {
    if (c >= 'A' && c <= 'Z') c -= 'A' - 'a';
    return c;
}

string toString(int i) {
    string r;
    do {
        r.insert(0, 1, char(i % 10 + '0'));
    } while ( (i = i / 10) );
    return r;
}

int factorial() {
    static int factor = 1;
    static int value = 1;
    return (value *= (factor++));
}

double function_6_15(double x) {
    return 1.0;
}

double r = 1.0;

double* function_6_15_1() {
    return &r;
}

bool function_6_20(const std::vector<string>& v1, const std::vector<string>& v2) {
    return lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
}

int function_6_23_1() {
    if (rand() % 10 == 0)
        return rand() % 100;
    return rand() % 10 + 10;
}

bool function_6_23_2(int value) {
    if (value > 20 || value < 10) return true; else return false;
}

int Class_6_1::sum;

Class_6_1::Class_6_1(int init) { sum = 0; }

int Class_6_1::operator()(int n) { sum += n; return sum; }

void Class_6_2::function_1() { cout << "Class_6_2::function_1().\n"; }

void Class_6_2_1::function_1() { cout << "Class_6_2_1::function_1().\n"; }

Class_6_15::Class_6_15() {}

double Class_6_15::getRadian() {
    /*
    const double* r = new double;
    *r =
    * */

    return r = double(rand() % 314) / double(100);
}

Class_6_25::Class_6_25() {
    age = rand() % 10 + 20;
    year = rand() % 5 + 1995;
}

bool Class_6_25::isFirstPart(const Class_6_25 &value) {
    if (value.year == 1997) return true; else return false;
}

bool Class_6_25::isLess(const Class_6_25& left, const Class_6_25& right) {
    if (left.age < right.age) return true; else return false;
}

int Town::counter = 0;

vector<string> Town::weatherNames;

Town::Town() {
    if (weatherNames.empty()) {
        weatherNames.push_back("rainy");
        weatherNames.push_back("snowy");
        weatherNames.push_back("cloudy");
        weatherNames.push_back("clear");
    }
    name = "Town_" + toString(counter++);
    population = rand() % 900 + 100;
    height = rand() % 90 + 10;
    wt = Town::weather(rand() % 4);
}

ostream& operator<<(std::ostream& os, const Town& value) {
    return os << value.name << "\t" << value.population << "\t" << value.height << "\t" << value.weatherNames[value.wt] << endl;
}

Town& Town::populationGrowth(Town& value) {
    value.population *= 1.1;
    return value;
}

bool Town::isLess(const Town& left, const Town& right) {
    if (left.population < right.population) return true; else return false;
}

bool Town::isEqual(const Town& value) {
    if (value.height < 25 || value.height > 75) return true; return false;
}

bool Town::isNear(const Town& prev, const Town& elem) {
    if (abs(prev.height - elem.height) <= 25) return true; else return false;
}

bool Town::operator<(const Town& value) const {
    if (value.population < population) return true; else return false;
}

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

Class_6_13_1::Class_6_13_1(char i, int q, int v) : item(i), quantity(q), value(v) {}

char Class_6_13_1::getItem() const { return item; }

int Class_6_13_1::getQuantity() const { return quantity; }

void Class_6_13_1::setQuantity(int q) { quantity = q; }

int Class_6_13_1::getValue() const { return value; }

void Class_6_13_1::setValue(int v) { value = v; }

std::ostream& operator<<(std::ostream& os, const Class_6_13_1& value) {
    return os <<  "Item [quantity, value]: " << value.getItem() << "[" << value.getQuantity() << "," << value.getValue() << "]" << endl;
}

Class_6_13_1 genValues() {
    static char c = 'a';
    int q = rand() % 100;
    int v = rand() % 300;
    return Class_6_13_1(c++, q, v);
}

Class_6_13_2::Class_6_13_2() : quantity(0), value(0) {}

void Class_6_13_2::operator()(const Class_6_13_1& cl) {
    quantity += cl.getQuantity();
    value += cl.getQuantity() * cl.getValue();
}

std::ostream& operator<<(std::ostream& os, const Class_6_13_2 value) {
    return os << "Total [quantity, value]: [" << value.quantity << "," << value.value << "]" << endl;
}

Employee::Employee() {
    hours = rand() % 10;
    hourlyPay = rand() % 5 + 1;
}

int Employee::salary() {
    return (hours * hourlyPay);
}

void chapter_22() {
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
    Matrix_A<int> Matrix_A_1(3, 3), Matrix_A_2(3, 3, 3), Matrix_A_3(3, 3, 0);
    Matrix_A<int> Matrix_A_4(3, 4, 0), Matrix_A_5(4, 5, 1), Matrix_A_6(3, 5, 0), Matrix_A_7(3, 1, 0);
    vector<int> vector_15;
    for (int i = 0; i < 4; i++) vector_15.push_back(i);
    cout << "Source Matrix_A_1:\n" << Matrix_A_1;
    cout << "Source Matrix_A_2:\n" << Matrix_A_2;
    Matrix_A_3 = Matrix_A_1 + Matrix_A_2;
    cout << "Result of Matrix_A_1 + Matrix_A_2:\n" << Matrix_A_3;
    cout << "Source Matrix_A_4:\n" << Matrix_A_4;
    cout << "Source Matrix_A_5:\n" << Matrix_A_5;
    Matrix_A_6 = Matrix_A_4 * Matrix_A_5;
    cout << "Result of Matrix_A_4 * Matrix_A_5:\n" << Matrix_A_6;
    cout << "Source vector_15: ";
    copy(vector_15.begin(), vector_15.end(), ostream_iterator<int>(cout, " "));
    Matrix_A_7 = Matrix_A_4 * vector_15;
    cout << "\nResult of Matrix_A_4 * vector_15:\n" << Matrix_A_7;
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
