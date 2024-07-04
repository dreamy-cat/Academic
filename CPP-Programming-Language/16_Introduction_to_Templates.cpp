#include "16_Introduction_to_Templates.hpp"

using namespace std;

int AutoCounter::count = 0;

bool AutoCounter::quiet = true;

AutoCounter::CleanupCheck AutoCounter::verifier;

Int::Int(int ii) : i(ii) { cout << "Int constructor: " << i << endl; }

Int::~Int() { cout << "Int destructor: " << i << endl; }

std::ostream& operator<<(std::ostream& os, const Int& value) { return os << "Int.i = " << value.i; }

std::ostream& operator<<(std::ostream& os, const Int* value) { return os << "Int.i = " << value->i; }

template<class T> int ObjContainer_16<T>::i = 0;

template<class T> int ObjContainer_16<T>::j = 0;

void Part_16_Introduction_to_Templates(void) {
    cout << "Chapter's 16 tasks." << endl;
    // Task 1. See in .h file.
    // Task 2.
    // FIX, was Shape_1
    TStack<OShape> tstack2;
    tstack2.push(new OCircle);
    tstack2.push(new OTriangle);
    tstack2.push(new OSquare);
    // Task 3-4. Merge tasks.
    TPStash_1<int> t_pstash3;
    for (int i = 0; i < 8; i++) t_pstash3.add(new int(i));
    // Task 5.
    cout << "Fibonacci int: ";
    for (unsigned char i = 1; i < 10; i++) {
        cout << fibonacci<int>(i) << " ";
    }
    cout << endl << "Fibonacci float : ";
    for (unsigned char i = 1; i < 10; i++) {
        cout << fibonacci<float>(i) << " ";
    }
    cout << endl;
    // Task 6.
    cout << "Numbers in set: ";
    TSet<int> tset_6;
    set<int> tset_61;
    for (int i = 0; i < 3; i++) {
        tset_6.add(new int(i+5));
        tset_61.insert(int(i));
    }
    TSet<int>::iterator it(tset_6);
    set<int>::iterator it1 = tset_61.begin();
    for (int i = 0; i < 3; i++) {
        cout << **it << "(" << *it1 << ") ";
        it++;
        it1++;
    }
    cout << endl;
    for (int i = 0; i < 3; i++) tset_6.remove(&i);
    // Task 7.
    vector<AutoCounter*> vec7;
    for (int i = 0; i < 3; i++) vec7.push_back(AutoCounter::create(true));
    for (int i = 0; i < 3; i++) delete vec7[i];
    // Task 8.
    OStack<int> ostack8(true);
    cout << "Elements in OStack<int> : ";
    for (int i = 0; i < 3; i++) ostack8.push(new int(i));
    for (int i = 0; i < 2; i++) cout << *ostack8.pop() << " ";
    cout << endl;
    // Task 9-11.
    cout << "VStack values : ";
    VStack<int> vstack_9;
    for (int i = 0; i < 16; i++) vstack_9.push(i);
    for (int i = 0; i < 16; i++) cout << vstack_9.pop() << " ";
    cout << endl;
    vector<int> stack9_1;
    cout << "Stack 'vector' values : ";
    for (int i = 0; i < 16; i++) stack9_1.push_back(i);
    for (int i = 0; i < 16; i++) {
        cout << stack9_1[stack9_1.size()-1] << " ";
        stack9_1.pop_back();
    }
    cout << endl;
    // Task 12.
    TStack_2<int> stack_12;
    TStack_2<int>::iterator it12(stack_12);
    for (int i = 0; i < 5; i++) stack_12.push(new int(i));
    cout << "Elements in STack_2 : ";
    for (int i = 0; i < 5; i++) cout << *stack_12.pop() << " ";
    cout << endl;
    // Task 13.
    TStack_3<int> stack_13;
    TStack_3<int>::iterator it13(stack_13);
    for (int i = 0; i < 5; i++) stack_13.push(new int(i));
    cout << "Elements in STack_3 : ";
    for (int i = 0; i < 5; i++) cout << *stack_13.pop() << " ";
    cout << endl;
    // Task 14, 23
    cout << "PStash_1 class test, PStash_1<Int> contains: \n";
    PStash_1<Int> ints;
    for (int i = 0; i < 5; i++) ints.add(new Int(i));
    for (PStash_1<Int>::iterator it = ints.begin(); it != ints.end(); it++) cout << *it << " ";
    cout << endl;
    PStash_1<Int>::iterator it14_1 = ints.begin();
    it14_1 += 1;
    PStash_1<Int>::iterator it14_2 = it14_1 + 3;
    it14_2 = it14_2 - 1;
    while (it14_1 != it14_2) {
        delete it14_1.remove();
        it14_1++;
    }
    cout << "After remove PStash_1<Int> contains: ";
    for (PStash_1<Int>::iterator it = ints.begin(); it != ints.end(); it++) cout << *it << " ";
    cout << endl;
    // Task 15.
    StackTemplate<int> stack15;
    for (int i = 0; i < 5; i++) stack15.push(i);
    cout << "StackTemplate class, elements: ";
    StackTemplate<int>::iterator it15 = stack15.begin();
    while (it15 != stack15.end()) cout << it15++ << " ";
    cout << endl;
    StackTemplate<int>::iterator it15_1 = stack15.begin(), it15_2 = stack15.begin();
    it15_1 += 1;
    it15_2 += 3;
    cout << "StackTemplate iterator_1 : " << it15_1 << endl;
    cout << "StackTemplate iterator_2 : " << it15_2 << endl;
    cout << "StackTemplate after iterator_1 : ";
    while (it15_1 != stack15.end()) cout << it15_1++ << " ";
    cout << endl;
    // Task 16.
    StackTemplate<Shape_16*> stack16;
    stack16.push(new Circle_16);
    stack16.push(new Square_16);
    stack16.push(new Line_16);
    cout << "Virtual methods from StackTemplate:\n";
    for (StackTemplate<Shape_16*>::iterator it16 = stack16.begin(); it16 != stack16.end(); it16++) {
        (*it16)->draw();
        (*it16)->erase();
    }
    PStash_1<Shape_16> stash16;
    stash16.add(new Circle_16);
    stash16.add(new Square_16);
    stash16.add(new Line_16);
    cout << "Virtual methods from PStash_1<Shape_16>, size: " << stash16.count() << endl;
    for (PStash_1<Shape_16>::iterator it16 = stash16.begin(); it16 != stash16.end(); it16++) {
        (*it16)->draw();
        (*it16)->erase();
    }
    // Task 17.
    Template_17<char> cl17('A');
    cout << cl17;
    // Task 18.
    TemplArray_16<char, 3> cl18;
    cin >> cl18;
    cout << cl18 << endl;
    // Task 19.
    ObjContainer_16<char> cl16_1;
    ObjContainer_16<int> cl16_2;
    for (int i = 0; i < 3; i++) cl16_1.add(new char('a'+i));
    ObjContainer_16<char>::SmartPointer it16_1(cl16_1);
    cout << "ObjContainer_16<char> elements: ";
    for (int i = 0; i < 3; i++) {
        cout << *it16_1.operator->() << " ";
        it16_1++;
    }
    cout << endl;
    ObjContainer_16<int>::SmartPointer it16_2(cl16_2);
    for (int i = 0; i < 3; i++) cl16_2.add(new int(i));
    cout << "ObjContainer_16<int> elements: ";
    for (int i = 0; i < 3; i++) {
        cout << *it16_2.operator->() << " ";
        it16_2++;
    }
    cout << endl;
    // Task 20-21.
    OStack_16_1<Circle_16> stack16_1;
    stack16_1.push(new Circle_16);
    cout << "OStack_16_1<Circle_16> : ";
    stack16_1.pop()->draw();
    OStack_16_2<Circle_16> stack16_2;
    stack16_2.push(new Circle_16);
    cout << "OStack_16_2<Circle_16> : ";
    stack16_2.pop()->draw();
    // Task 22.
    TemplVector<char> cl22;
    cl22.push_back(new char('a'));
    cout << "TemplVector<char> : " << *cl22[0] << endl;
    // Task 24.
    Line_16 cl24;
    function_16_24<Line_16>(&cl24);
    // Task 25.
    Stack_16<int> stack25;
    int* ar25[5];
    for (int i = 0; i < 5; i++) {
        ar25[i] = new int(i);
        stack25.push(ar25[i], i < 3 ? true : false);
    }
    cout << "Stack_16<int> elements: ";
    Stack_16<int>::iterator it25;
    for (it25 = stack25.begin(); it25 != stack25.end(); it25++) cout << *stack25.pop() << " ";
    cout << endl;
    // Task 26.
    Cat<char> cat26;
    Cat<char>::PointerMember_1 ptrMember1 = &Cat<char>::run;
    Cat<char>::PointerMember_2 ptrMember2 = &Cat<char>::eat;
    Cat<char>::PointerMember_3 ptrMember3 = &Cat<char>::sleep;
    cout << (cat26->*ptrMember1)() << endl;
    cout << (cat26->*ptrMember2)('a') << endl;
    cout << (cat26->*ptrMember3)('a', 'b') << endl;
}
