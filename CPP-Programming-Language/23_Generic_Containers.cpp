#include "23_Generic_Containers.hpp"

using namespace std;

int Noisy::create = 0;

int Noisy::assign = 0;

int Noisy::copyCons = 0;

int Noisy::destroy = 0;

Noisy::Noisy() : id(create++) { cout << "Noisy::Noisy(), id = " << id << endl; }

Noisy::~Noisy() { cout << "Noisy::~Noisy(), id = " << id << ", counter " << ++destroy << endl; }

Noisy::Noisy(const Noisy& rv) : id(rv.id) {
    cout << "Noisy::Noisy(const Noisy&), id " << id << ", counter " << ++copyCons << endl;
}

Noisy& Noisy::operator=(const Noisy& rv) {
    id = rv.id;
    cout << "Noisy::operator=(), id " << id << ", counter " << ++assign << endl;
    return *this;
}

void Noisy::report() {
    cout << "Noisy::report(), counters: create " << create
         << ", assing " << assign
         << ", copy constructors " << copyCons
         << ", destructors " << destroy << endl;
}

bool operator<(const Noisy& lv, const Noisy& rv) {
    cout << "Noisy::operator<(), lv.id " << lv.id << ", rv.id " << rv.id << endl;
    return (lv.id < rv.id);
}

bool operator==(const Noisy& lv, const Noisy& rv) {
    cout << "Noisy::operator==(), lv.id " << lv.id << ", rv.id " << rv.id << endl;
    return (lv.id == rv.id);
}

ostream& operator<<(ostream& os, const Noisy& value) {
    return os << "Noisy::id " << value.id << endl;
}

void function_7_2(std::list<Noisy> v) {
    cout << "Sorting list<Noisy>, container size " << v.size() << endl;
    v.sort();
}

Shape_2::~Shape_2() {}

void Shape_2::altDraw() {
    string className = typeid(*this).name();
    if ( className.find("Circle_2") != string::npos ) (dynamic_cast<Circle_2*>(this))->draw(); else
        if ( className.find("Triangle_2") != string::npos ) (dynamic_cast<Triangle_2*>(this))->draw(); else
            if ( className.find("Square_2") != string::npos ) (dynamic_cast<Square_2*>(this))->draw(); else
                cout << "Something goes wrong with type " << className << endl;
}

Circle_2::Circle_2() { radius = rand() % 10; }

void Circle_2::draw() { cout << "Circle_2::draw(), radius " << radius << endl; }

Circle_2::~Circle_2() { cout << "Circle_2::~Circle_2()" << endl; }

Triangle_2::Triangle_2() { line = rand() % 10; }

void Triangle_2::draw() { cout << "Triangle_2::draw(), line length " << line << endl; }

Triangle_2::~Triangle_2() { cout << "Triangle_2::~Triangle_2()" << endl; }

Square_2::Square_2() { perimeter = rand() % 10; }

void Square_2::draw() { cout << "Square_2::draw(), perimeter " << perimeter << endl; }

Square_2::~Square_2() { cout << "Square_2::~Square_2()" << endl; }

Rectangle_2::Rectangle_2() { cout << "Rectangle_2::Rectangle_2()" << endl; }

void Rectangle_2::draw() { cout << "Rectangle_2::draw()" << endl; }

Rectangle_2::~Rectangle_2() { cout << "Rectangle_2::~Rectangle_2()" << endl; }


bool greaterRadius(const Circle_2 *lv, const Circle_2 *rv) {
    return ( lv->radius > rv->radius );
}

bool greaterPerimeter(const Square_2 *lv, const Square_2 *rv) {
    return ( lv->perimeter > rv->perimeter );
}


void printStack(stack<int>& s, string name) {
    cout << "Stack '"  << name << "': ";
    stack<int> tmp = s;
    while ( !tmp.empty() ) {
        cout << tmp.top() << " ";
        tmp.pop();
    }
    cout << endl;
}

void sortStack(std::stack<int>& source, std::stack<int>& sorted, std::stack<int>& tail) {
    sorted.push(source.top());
    source.pop();
    while ( !source.empty() ) {
        if ( source.top() > sorted.top() ) {
            if (sorted.empty()) cout << "sorted empty" << endl;
            tail.push(sorted.top());
            sorted.pop();
            sorted.push(source.top());
            source.pop();
        } else {
            if (source.empty()) cout << "source empty" << endl;
            tail.push(source.top());
            source.pop();
        }
    }
}

Class_7_11::Class_7_11() {
    priority = rand() % 10;
}

bool operator<(const Class_7_11& lv, const Class_7_11& rv) {
    return (lv.priority < rv.priority);
}

ostream& operator<<(ostream& os, const Class_7_11& value) {
    return os << "Class_7_11::priority = " << value.priority << endl;
}

Class_7_15::Class_7_15(const char l) : letter(l), isExist(false) {}

bool Class_7_15::exist(char c) { return (isExist = (toupper(c) == toupper(letter))); }

char Class_7_15::getLetter() { return letter; }

void chapter_23() {
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
    deque<Shape_2*> deque_2;
    deque_2.push_back(new Circle_2);
    deque_2.push_back(new Square_2);
    deque_2.push_back(new Triangle_2);
    deque<Shape_2*>::iterator it_2;
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
    cout << endl;
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


