#include "04_Data_Abstraction.hpp"

//

using namespace std;

void structure_4_1::function_1(structure_4_1 *strucPtr, int m) {
    strucPtr->n = m;
}

void structure_4_1::function_2(structure_4_1 *strucPtr) {
    cout << "Structure_4_2::Function_1 has called. N = " << strucPtr->n << endl;
}

// Task 6.

class_4_1::class_4_1() {
    s = "chapter_04";
    cout << "String from class_4_1 = " << this->s << endl;
}

// Task 7.

void Stash::initialize(int sz) {
    size = sz;
    quantity = 0;
    storage.clear();
    next = 0;
}

int Stash::add(const void *element) {
    if (next >= quantity) inflate (increment);
    int startOffs = next * size;
    unsigned char* e = (unsigned char*)element;
    for (int i = 0; i < size; i++) storage[startOffs+i] = e[i];
    next++;
}

void Stash::inflate(int increase) {
    //unsigned char* newStorage = new unsigned char[(quantity+increase)*size];
    storage.resize(quantity+increase*size);
/*
    for (int i = 0; i < quantity*size; i++) newStorage[i] = storage[i];
    delete []storage;
    storage = newStorage;
    */
    quantity += increase;
}

int Stash::count() {
    return next;
}

void* Stash::fetch(int index) {
    if (index >= next) return 0;
    //return (storage + index*size);
    return (void*)&storage[index*size];
}

void Stash::cleanup() {
//    if (storage != 0) {
    if (!storage.empty()) {
        cout << "Freeing memory.\n";
//        delete []storage;
        storage.clear();
    }
}

// Task 8.

void Stack::initialize() {
    head = 0;
}

void Stack::push(double *data) {
    Link* newLink = new Link;
    newLink->value = data;
    newLink->next = head;
    head = newLink;
}

double* Stack::pop() {
    if (head == 0) return 0;
    double* rVal = head->value;
    Link* oldHead = head;
    head = head->next;
    delete oldHead;
    return rVal;
}

// Task 13.

Class_4_13::Class_4_13(string newTitle) {
    title = newTitle;
    period = 0;
}

Class_4_13::~Class_4_13() {

}

void Class_4_13::give(string cust) {
    if (period != 0) return;
    period = 7;
    customer = cust;
}

void Class_4_13::get(string cust) {
    if (period == 0) return;
    customer.clear();
    period = 0;
}

void Class_4_13::print() {
    cout << "Title = " << title;
}

// Task 14.

Stack2::Stack2(int maxSize) : maxSz(maxSize) {
    mem = new Class_4_13*[maxSz];
    stackPointer = 0;
}

Stack2::~Stack2() {
    if (stackPointer > 0) {

    }
}

void Stack2::push(Class_4_13 &clPtr) {
    if (stackPointer >= maxSz) return;
    mem[stackPointer] = new Class_4_13(clPtr.title);
    *mem[stackPointer++] = clPtr;
}

Class_4_13 Stack2::pop() {
    if (stackPointer > 0)
        return *mem[--stackPointer];
}

// Task 18.

char* function_4_1 (const char *original) {
    int size = 0;
    while (*(original+size++) != '\0');
    char* copy = new char(size);
    for (int i = 0; i <= size; i++) copy[i] = original[i];
    return copy;
}

// Task 19.

void structure_4_2::printN() {
    cout << "Structure_4_2 N = " << n1 << endl;
}

void structure_4_2::structure_4_2_1::printN() {
    cout << "Structure_4_2_1 N = " << n2 << endl;
}

//Task 22.

void Stack3::init(int size) {
    maxSz = size;
    stackPointer = 0;
    mem = new Stash3*[maxSz];
}

void Stack3::push(Stash3 element) {
    if (stackPointer >= maxSz) return;
    Stash3* newStash = new Stash3;
    *newStash = element;
    mem[stackPointer++] = newStash;
}

Stash3 Stack3::pop() {
    if (stackPointer == 0) return Stash3();
    Stash3 val = *mem[--stackPointer];
    delete mem[stackPointer];
    return val;
}

void structure_4_6::wrapinit(int size) {
    stack.init(size);
}

void structure_4_6::wrapPush(Stash3 &element) {
    stack.push(element);
}

Stash3 structure_4_6::wrapPop() {
    return (stack.pop());
}

// Task 24.

void List::createList(List *start, int size) {
    for (int i = 0; i < size; i++) {
        start->n = i;
        if (i < size - 1) {
            start->next = new List;
            start = start->next;
        }
    }
    start->next = NULL;
}

void List::printList(List* start) {
    while (start != NULL) {
        cout << start->n << " ";
        start = start->next;
    }
}


void chapter_04() {
    cout << "Chapter's 4 tasks.\n";
    // Task 1. Not possible to use C flag. Try it later in separate project.
    // Task 2-6.
    structure_4_1 struc1;
    struc1.function_1(&struc1,1);
    struc1.function_2(&struc1);
    class_4_1 class1;
    // Task 7.
    Stash stashDouble;
    stashDouble.initialize(sizeof(double));
    for (int i = 0; i < 8; i++) {
        double d = i;
        stashDouble.add((void*)&d);
    }
    cout << "Fetch elements from storage: ";
    for (int i = 0; i < 8; i++) cout << *(double*)stashDouble.fetch(i) << " ";
    cout << endl;
    stashDouble.cleanup();
    // Task 8.
    double d8 = 1.0;
    Stack stackDouble;
    stackDouble.initialize();
    stackDouble.push(&d8);
    cout << "Pop double value from stack = " << *stackDouble.pop() << endl;
    // Task 9-10. Depends on compilers.
    // Task 11-12.
#ifdef TASK_11
    cout << "Define TASK_11." << endl;
#else
    cout << "Not define TASK_11." << endl;
    assert(0);
#endif
    // Task 13-14.
    Class_4_13 cl1("Test 1"), cl2("Test 2");
    cout << "Class_4_13 objects 1 & 2 = ";
    cl1.print();
    cout << " ";
    cl2.print();
    cout << endl;
    Stack2 stackClass_4_13(5);
    stackClass_4_13.push(cl1);
    cl2 = stackClass_4_13.pop();
    cout << "Stack test object 2 = object 1: ";
    cl2.print();
    cout << endl;
    // Task 15.
    cout << "Size of char = " << sizeof(char) << endl;
    cout << "Size of int = " << sizeof(int) << endl;
    cout << "Size of long = " << sizeof(long) << endl;
    cout << "Size of void* = " << sizeof(void*) << endl;
    cout << "Size of float = " << sizeof(float) << endl;
    cout << "Size of double = " << sizeof(double) << endl;
    // Task 16. Ready, old version remains commented.
    // Task 17.
    int *intPtr = new int (128);
    long *longPtr = new long (128);
    char *charPtr = new char (128);
    float *floatPtr = new float (128);
    cout << "Addresses of pointers to int, long, char, float : ";
    cout << (long)intPtr << " " << (long)longPtr << " " << (long)charPtr << " " << (long)floatPtr << endl;
    // Task 18.
    const char str1[] = "Task 18 test string";
    char* str2 = function_4_1(str1);
    cout << "Original string = " <<  str1 << ", address: " << (long)str1 << endl;
    cout << "Copy string = " << str2 << ", address: " << (long)str2 << endl;
    delete []str2;
    structure_4_2 struc2;
    struc2.n1 = 0;
    struc2.substructure.n2 = 1;
    struc2.printN();
    struc2.substructure.printN();
    // Task 20. Size > 0, becuase of addresses.
    cout << "Size of structure_4_3 = " << sizeof(structure_4_3) << endl;
    cout << "Size of structure_4_4 = " << sizeof(structure_4_4) << endl;
    cout << "Size of structure_4_5 = " << sizeof(structure_4_5) << endl;
    // Task 21. Compiles ok.
    enum_1 en1;
    union_4_1 un1;
    // Task 22-23.
    Stack3 stack_3;
    structure_4_6 struc;
    stack_3.init(8);
    struc.wrapinit(8);
    int actualRead = 0;
    fstream textFile;
    string textLine;
    textFile.open("labs_0x01/files/chapter-04.txt");
    if (textFile.is_open()) {
        cout << "File labs_0x01/files/chapter-04.txt:\n";
        while (getline(textFile, textLine, '\n')) {
            cout << "Line : " << textLine << endl;
            Stash3 line;
            line.text = textLine;
            //stack_3.push(line);
            struc.wrapPush(line);
            actualRead++;
        }
        cout << "Actual lines read " << actualRead << endl;
        cout << "Lines from stack : " << endl;
        for (int i = 0; i < actualRead; i++) {
            //Stash3 line = stack_3.pop();
            Stash3 line = struc.wrapPop();
            cout << line.text << endl;
        }
    } else cout << "Error open file /labs_0x01/files/chapte r-04.txt" << endl;
    // Task 24-25.
    List list1;
    list1.createList(&list1,4);
    cout << "List size 4 elements: ";
    list1.printList(&list1);
    cout << endl;
}
