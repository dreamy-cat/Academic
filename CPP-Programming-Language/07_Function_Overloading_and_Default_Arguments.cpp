#include "07_Function_Overloading_and_Default_Arguments.hpp"

using namespace std;

Text::Text () {
    txt.clear();
}

Text::Text (string fileName) {
    txt.clear();
    fstream textFile;
    textFile.open(fileName.data());
    if (textFile.is_open()) std::getline(textFile, txt, '\0'); else
        cout << "Error open file: " << fileName << endl;
    textFile.close();
}

Message::Message(string init) {
    msg = init;
}

void Message::print() {
    cout << "Class message print function: " << msg << endl;
}

void Message::print(string pr) {
    cout << "Class message print(string) function : " << pr << msg << endl;
}

// Task's 4 changing.

void Class_7_4::f (int a, int b, int c, int d) {
    cout << "Class_7_4, function f with 4 arguments." << endl;
}

/*
void Class_7_4::f1(int a) {}

void Class_7_4::f2(int a, int b) {}

void Class_7_4::f3(int a, int b, int c) {}
*/

void function_7_5(int a, int) {
    cout << "Function_7_5 int a = " << a << endl;
}

Stash7::Stash7(int sz, int initQuantity) : increment(5) {
    if (initQuantity < 0) initQuantity = 0;
    size = sz;
    quantity = next = 0;
    storage = 0;
    inflate(initQuantity);
}

Stash7::~Stash7() {
    if (storage != 0) delete []storage;
}

int Stash7::add(void *element) {
    if (next >= quantity) inflate(increment);
    int startOffset = next * size;
    unsigned char* e = (unsigned char*)element;
    for (int i = 0; i < size; i++) storage[startOffset + i] = e[i];
    next++;
    return (next - 1);
}

void* Stash7::fectch(int index) {
    if (index < 0 && index > next) return 0;
    return &(storage[index * size]);
}

int Stash7::count() {
    return next;
}

void Stash7::inflate(int increase) {
    if (increase <= 0) return;
    unsigned char* b = new unsigned char[(quantity + increase) * size];
    for (int i = 0; i < quantity * size; i++) b[i] = storage[i];
    delete []storage;
    storage = b;
    quantity += increase;
}

Stack7::Stack7() {
    storage.clear();
}

Stack7::Stack7(string values[], int size) {
    storage.clear();
    for (int i = 0; i < size; i++) storage.push_back(values[i]);
}

void Stack7::push(string value) {
    storage.push_back(value);
}

string Stack7::pop() {
    if (!storage.empty()) {
        string value = storage.back();
        storage.pop_back();
        return value;
    }
}

#ifdef TASK_8

SuperVar::SuperVar(char ch) {
    c = ch;
}

SuperVar::SuperVar(int ii) {
    i = ii;
}

SuperVar::SuperVar(float ff) {
    f = ff;
}

void SuperVar::print(vartype t) {
    switch (t) {
    case character:
        cout << "character: " << c << endl;
        break;
    case integer:
        cout << "integer: " << i << endl;
        break;
    case floating:
        cout << "floating: " << f << endl;
        break;
    default:
        break;
    }
}

Mem::Mem(int sz) {
    mem = prevMem = 0;
    size = 0;
    ensureMinSize(sz);
}

Mem::~Mem() {
    delete []mem;
}

int Mem::msize() {
    return size;
}

void Mem::ensureMinSize(int minSize) {
    if (size < minSize) {
        unsigned char* newmem = new unsigned char[minSize];
        memset(newmem + size, 0, minSize - size);
        for (int i = 0; i < size; i++) newmem[i] = mem[i];
        delete []mem;
        mem = newmem;
        size = minSize;
    }
}

unsigned char* Mem::pointer(int minSize) {
    ensureMinSize(minSize);
    return mem;
}

bool Mem::moved() {
    if (pointer() != prevMem) {
        prevMem = pointer();
        return true;
    }
    return false;
}


#endif // TASK_8

String_9::String_9() : buf(0) { }

String_9::String_9(const char *str) {
    buf = new Mem(strlen(str) + 1);
    // cout << str << strlen(str) << buf->msize() << endl;
    strcpy((char*)buf->pointer(), str);
}

String_9::~String_9() {
    delete buf;
}

void String_9::concat(char *str) {
    if (!buf) {
        buf = new Mem;
    }
    strcat((char*)buf->pointer(buf->msize() + strlen(str) + 1), str);
}

void String_9::print(ostream &os) {
    if (!buf) return;
    os << buf->pointer() << endl;
}

StashMem::StashMem(int sz, int initQuantity) : increment(5) {
    if (initQuantity < 0) initQuantity = 0;
    storage = new Mem(initQuantity);
    size = sz;
    quantity = next = 0;
}

StashMem::~StashMem() {
    if (storage != 0) delete storage;
}

int StashMem::add(void *element) {
    // if (next >= quantity) storage->pointer(next * size);
    int startOffset = next * size;
    unsigned char* e = (unsigned char*)element;
    for (int i = 0; i < size; i++) storage->pointer((next+1) * size)[startOffset + i] = e[i];
    next++;
    return (next - 1);
}

void* StashMem::fectch(int index) {
    if (index < 0 && index > next) return 0;
    return (void*)(storage->pointer() + index * size);
}

int StashMem::count() {
    return next;
}

void chapter_07() {
    cout << "Chapter's 7 tasks.\n";
    // Task 1.
    Text class1("labs_0x01/files/chapter-07.txt");
    cout << "File chapter-07.txt : " << "\n" << class1.txt;
    // Task 2.
    Message class2("Initial string.");
    class2.print();
    class2.print("With string. ");
    // Task 3. Intresting...
    // Task 4. May be not right
    Class_7_4 class4;
    class4.f();
    class4.f(1);
    class4.f(1,2);
    class4.f(1,2,3);
    // Task 5.
    function_7_5(1, 2);
    // Task 6.
    Stash7 stashOfInt(sizeof(int));
    Stash7 stashOfChar(sizeof(char), 8);
    for (int i = 0; i < 16; i++) {
        stashOfInt.add((void*)&i);
        char c = 'a' + i;
        stashOfChar.add((void*)&c);
    }
    cout << "Stash of int : ";
    for (int i = 0; i < stashOfInt.count(); i++) cout << *((int*)stashOfInt.fectch(i)) << " ";
    cout << "\nStash of char : ";
    for (int i = 0; i < stashOfChar.count(); i++) cout << *((char*)stashOfChar.fectch(i)) << " ";
    cout << endl;
    // Task 7.
    string strings_1[] = {"one", "two", "three"};
    Stack7 r(strings_1, 3);
    cout << "Pop strings values : ";
    for (int i = 0; i < 3; i++) cout << r.pop() << " ";
    cout << endl;
    // Task 8.
    SuperVar sv[3] = { SuperVar(char('a')), SuperVar(int(1)), SuperVar(float(3.0)) };
    for (int i = 0; i < 3; i++) sv[i].print((SuperVar::vartype)i);
    // Task 9.
    string s1 = "First test string.", s2 = "Add string.", s3 = "Using default constructor.";
    String_9 s_91(s1.data());
    s_91.print(cout);
    s_91.concat(const_cast<char*>(s2.data()));
    s_91.print(cout);
    String_9 s_92;
    s_92.print(cout);
    s_92.concat(const_cast<char*>(s3.data()));
    s_92.print(cout);
    // Task 10.
    StashMem stashMemOfInt(sizeof(int));
    StashMem stashMemOfChar(sizeof(char), 8);
    for (int i = 0; i < 16; i++) {
        stashMemOfInt.add((void*)&i);
        char c = 'a' + i;
        stashMemOfChar.add((void*)&c);
    }
    cout << "StashMem class. Integers : ";
    for (int i = 0; i < stashMemOfInt.count(); i++) cout << *((int*)stashMemOfInt.fectch(i)) << " ";
    cout << "\nStashMem class. Chars : ";
    for (int i = 0; i < stashMemOfChar.count(); i++) cout << *((char*)stashMemOfChar.fectch(i)) << " ";
    cout << endl;
    // Task 11.
    Mem mem1(5);
    cout << "Mem class pointer moved : " << mem1.moved() << ". ";
    cout << "And after second call : " << mem1.moved() << endl;
}
