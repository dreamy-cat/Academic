#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <assert.h>

#include "labs_0x01.h"
#include "chapter_03.h"
#include "chapter_04.h"
#include "chapter_05.h"
#include "chapter_06.h"
#include "chapter_07.h"

using namespace std;

void chapter_02 () {
    cout << "Chapter's 2 tasks.\n";
    // Tasks 1,2.
    cout << "Radius:  ";
    double radius = 0;
    double pi = 3.1415;
    cin >> radius;
    cout << "Area of circle with radius " << radius << " = " << pi*radius*radius << endl;
    // Tasks 3,4,5.
    fstream textFile;
    string text, searchWord, currentWord, textLine;
    vector<string> textLines;
    textFile.open("labs_0x01/files/chapter-02.txt");
    if (textFile.is_open()) {
        std::getline(textFile,text,'\0');
        cout << "Textfile: \n" << text << endl;
        textFile.seekg(0);
        while (std::getline(textFile, textLine, '\n')) textLines.push_back(textLine);
        cout << "Enter word to find: ";
        cin >> searchWord;
        int words = 0, foundedWords = 0;
        bool inWord = false;
        for (int i = 0; i < text.size(); i++) {
            if ( (text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z') ) {
                if (!inWord) {
                    inWord = true;
                    words++;
                }
                currentWord.push_back(text[i]);
            } else {
                if (currentWord == searchWord) foundedWords++;
                currentWord.clear();
                inWord = false;
            }
        }
        cout << "Words in text " << words << endl;
        cout << "Word '" << searchWord << "' was founded: " << foundedWords << endl;
        if (!textLines.empty()) {
            cout << "Text file from vector lines in reverse: \n";
            for (int i = textLines.size()-1; i > 0; i--) cout << textLines[i] << endl;
        } else cout << "File is empty.\n";
    } else cout << "Error open file: ./labs_0x01/files/chapther-02.txt" << endl;
    textFile.close();
    // Tasks 8,9,10.
    vector<float> first, second, third;
    for (int i = 0; i < 25; i++) {
        first.push_back(i);
        second.push_back(i%5);
        third.push_back(first[i]+second[i]);
    }
    cout << "First vector of floats: \n";
    for (int i = 0; i < 25; i++) cout << first[i] << " ";
    cout << "\nSecond vector of floats: \n";
    for (int i = 0; i < 25; i++) cout << second[i] << " ";
    cout << "\nThird vector of floats: \n";
    for (int i = 0; i < 25; i++) cout << third[i] << " ";
    cout << "\nSquares of elements in third vector: \n";
    for (int i = 0; i < 25; i++) {
        third[i] = third[i] * third[i];
        cout << third[i] << " ";
    }
    cout << endl;
}

void chapter_03 () {
    cout << "Chapter's 3 tasks.\n";
    // Task 1.
    function_3_1();
    char c = 'a';
    c =  function_3_2(c);
    cout << "Return value = '" << c << "'\n";
    int ix = 0;
    ix = function_3_3(ix);
    cout << "Return value = " << ix << "\n";
    float f = 2;
    f = function_3_4(f);
    cout << "Return value = " << f << "\n";
    // Task 2.
    cout << "Primary numbers: ";
    for (int i = 2; i < 100; i++)
        for (int j = 2; (i % j != 0 || i == j) && j <= i; j++)
            if (j == i) cout << i << " ";
    cout << endl;
    // Task 3. Better skip it.
    fstream textFile;
    string text, word1 = "port", word2 = "factory", word3 = "corporate";
    textFile.open("labs_0x01/files/chapter-03.txt");
    if (textFile.is_open()) {
        cout << "File labs_0x01/files/chapter-03.txt:\n";
        while (true) {
            text.clear();
            getline(textFile, text, '\n');
            cout << "Line : " << text << " ";
            int d = 3;
            if (text.find(word1) != string::npos) d = 0;
            if (text.find(word2) != string::npos) d = 1;
            if (text.find(word3) != string::npos) d = 2;
            switch (d) {
            case 0:
                cout << "Find word '" << word1 << "' at position " << text.find(word1) << endl;
                break;
            case 1:
                cout << "Find word '" << word2 << "' at position " << text.find(word2) << endl;
                break;
            case 2:
                cout << "Find word '" << word3 << "' at position " << text.find(word3) << ", exit from while." << endl;
                break;
            default:
                cout << "Words not found." << endl;
            }
            if (d == 2) break;
        }
    } else cout << "Error open file: ./labs_0x01/files/chapter-03.txt" << endl;
    // Task 4. Short.
    cout << "Menu: 1,2,3."  << endl;
    while (true) {
        char c;
        cin >> c;
        switch (c) {
        case '1':
            cout << "First item.\n";
            break;
        case '2':
            cout << "Second item.\n";
            break;
        case '3':
            cout << "Third. Exit.\n";
            break;
        default:
            cout << "Enter 1,2 of 3 for exit.\n";
        }
        if (c == '3') break;
    }
    // Task 5.
    int a, x = 1, y = 2, z = 2;
    a = x + y - 2/2 + z;
    cout << "a = x + y - 2/2 + z = " << a << endl;
    a = x + (y - 2)/(z + 2);
    cout << "a = x + (y - 2)/(z + 2) = " << a << endl;
    // Task 6.
    char cat;
    int dog;
    float fish;
    double bird;
    cout << "Types and memory.\n";
    cout << "Char 'cat'. Size =  " << sizeof(cat) << " bytes. Address: " << (long)&cat << endl;
    cout << "Int 'dog'. Size = " << sizeof(dog) << " bytes. Address: " << (long)&dog << endl;
    cout << "Float 'fish'. Size = " << sizeof(fish) << " bytes. Address: " << (long)&fish << endl;
    cout << "Double 'bird'. Size = " << sizeof(bird) << " bytes. Address: " << (long)&bird << endl;
    cout << "Function chapter_03 address: " << (long)&chapter_03 << endl;
    // Task 7.
    string str = "Calls: ";
    string* str1 = &str;
    string& str2 = str;
    function_3_5(str1);
    str += " ";
    function_3_6(str2);
    cout << str1 << endl << str2 << endl;
    // Task 8. Skip, because gcc doesn't support trigraph.
    // Task 9.
    for (int i = 0; i < 3; i++) function_3_7();
    // Task 10. Undefined reference, if 'fs' loacate in other file.
    extern int fs;
    cout << "Static int = " << fs << endl;
    // Tasks 11-13.
    double p1, p2;
    cout << "Double arguments 1 & 2:\n";
    cin >> p1;
    cin >> p2;
    cout << "p1 > p2 is " << (p1 > p2) << endl;
    cout << "p1 < p2 is " << (p1 < p2) << endl;
    cout << "p1 >= p2 is " << (p1 >= p2) << endl;
    cout << "p1 <= p2 is " << (p1 <= p2) << endl;
    cout << "p1 == p2 is " << (p1 == p2) << endl;
    cout << "p1 != p2 is " << (p1 != p2) << endl;
    cout << "p1 && p2 is " << (p1 && p2) << endl;
    cout << "p1 || p2 is " << (p1 || p2) << endl;
    cout << "Binary p1 | p2 = " << ((int)p1 | (int)p2) << endl;
    cout << "Binary p1 & p2 = " << ((int)p1 & (int)p2) << endl;
    unsigned char b1 , b2;
    int n1, n2;
    cout << "Byte arguments 1 & 2:\n";
    cin >> n1; cin >> n2;
    b1 = n1; b2 = n2;
    cout << "Binary arguments b1 & b2:" << toBinary(b1) << " " << toBinary(b2) << endl;
    cout << "b1 | b2 = " << toBinary(b1 | b2) << endl;
    cout << "b1 & b2 = " << toBinary(b1 & b2) << endl;
    cout << "b1 ^ b2 = " << toBinary(b1 ^ b2) << endl;
    cout << "~b1 = " << toBinary(~b1) << endl;
    cout << "~b2 = " << toBinary(~b2) << endl;
    unsigned char mask = 0x5a;
    cout << "Binary mask 0x5a = " << toBinary(mask) << endl;
    cout << "b1 | mask = " << toBinary(b1 | mask) << endl;
    b2 &= mask;
    cout << "b2 & mask = " << toBinary(b2) << endl;
    cout << "b2 ^ b1 = " << toBinary(b2 ^ b1) << endl;
    for (int i = 0; i < 4; i++) {
        rolByte(b1);
        rorByte(b2);
        cout << "Rotate left b1: " << toBinary(b1) << " , rotate right b2: " << toBinary(b2) << endl;
    }
    // Task 14.
    (b2 > 0) ? cout << "b2 > 0, using operator '?'\n" : cout << "b2 <= 0, using operator '?'\n";
    // Task 15.
    struct_3_1 st1;
    struct_3_1* st1Ptr;
    st1.s1 = "String 1";
    st1.s2 = "String 2";
    st1.n = 3;
    st1Ptr = &st1;
    cout << "String 1 from struct_3_1 = " << st1Ptr->s1 << ", string 2 from struct_3_1 = " << st1Ptr->s2 << endl;
    cout << "Int from struct_3_1 = " << st1Ptr->n << endl;
    // Task 16.
    for (int i = red; i <= blue; i++) cout << "Color number " << i << " ";
    cout << endl;
    // Task 17. Deleting element 'double' decrease size.
    union_3_1 union1;
    union1.i = 17;
    cout << "Union_3_1 int = " << union1.i << ", char = " << union1.c << ", double = " << union1.d << endl;
    // Task 18. May be worked, in old compilers. Offset = 3.
    int m1[2] = {0, 1};
    int m2[2] = {2, 3};
    int* ptrInt = &m1[1];
    ptrInt += 3;
    cout << "Pointer out of range, int = " << *ptrInt << endl;
    // Task 19.
    int im[3];
    char cm[3];
    float fm[3];
    long lm[3];
    cout << "Addresses of arrays int, char, float, long: " << endl;
    for (int i = 0; i < 3; i++)
        cout << "int:" << (long)&im[i] << " char:" << (long)&cm[i] << " float:" << (long)&fm[i] << " long:" << (long)&lm[i] << endl;
    // Task 20.
    point_3_20 pts[3];
    cout << "Size of array = " << sizeof(pts) << ", size of point_3_20 = " << sizeof(point_3_20) << endl;
    cout << "Addresses of elements structure_3_20: " << (long)&pts[0].i << " : " << (long)&pts[0].j << " : " << (long)&pts[0].k << endl;
    // Task 21.
    string ms[3];
    cout << "String array: ";
    for (int i = 0; i < 3; i++) {
        ms[i] = "string ";
        ms[i].push_back('0'+i);
        cout << ms[i] + " ";
    }
    cout << endl;
    // Task 22.
    const char param1[] = "1024";
    const char param2[] = "3.3";
    cout << "Long argument from string = " << atol(param1) << ", float argument from string =  " << atof(param2) << endl;
    // Task 23.
    primitiv_3_23 union2[3];
    primitiv_3_23* prim_3_23 = union2;
    cout << "Size of union 'prim' = " << sizeof(union2) << ", address = " << (long)union2 << ", pointer = " << (long)prim_3_23 << endl;
    prim_3_23++;
    cout << "Next pointer = " << (long)prim_3_23 << endl;
    // Task 24.
    long lArray[10];
    for (int i = 0; i < 10; i++) lArray[i] = i;
    long* lPtr = lArray;
    cout << "*lPtr = " << *lPtr << ", *++lPtr = " << *++lPtr << ", *(lPtr+5) = " << *(lPtr+5) << endl;
    long* lPtr2 = lPtr + 5;
    cout << "*lPtr2 = " << *lPtr2 << ", *(lPtr2-4) = " << *(lPtr2-4) << ", *--lPtr2 = " << *--lPtr2 << endl;
    cout << "lPtr2 - lPtr = " << lPtr2-lPtr << endl;
    // Task 25.
    float f2 = 1;
    unsigned char* f2Ptr = (unsigned char*)&f2;
    cout << "Float " << f2 << " in memory:\n";
    for (int i = 0; i < sizeof(float); i++) {
        string offS = "Offset ";
        offS.push_back('0'+i);
        cout << offS << ": " << toBinary(*f2Ptr++) << endl;
    }
    // Task 26.
    int iArr[5];
    void* arrPtr = static_cast<void*>(&iArr);
    setInt(arrPtr,5,3);
    cout << "Set all elements in array int[5] = ";
    for (int i = 0; i < 5; i++) cout << iArr[i] << " ";
    cout << endl;
    // Task 27.
    const double mcd[3] = {1, 2, 3};
    volatile double mvd[3];
    cout << "Const and volatile arrays of doulbe: ";
    for (int i = 0; i < 3; i++) {
        *(const_cast<double*>(&mcd[i])) = i;
        *(const_cast<double*>(&mvd[i])) = i + 1;
        cout << mcd[i] << "," << mvd[i] << " ";
    }
    cout << endl;
    // Task 28. Extra task.
    double dm[3];
    for (int i = 0; i < 3; i++) dm[i] = 0;
    outDoubleArray(dm,3);
    unsigned char* dArrayPtr = reinterpret_cast<unsigned char*>(dm);
    for (int i = 0; i < sizeof(dm); i++) *dArrayPtr++ = 1;
    outDoubleArray(dm,3);
    // Task 29.
    double td = -1;
    outDoubleBinary(td);
    // Task 30 & 35. Think about it later.
    // Task 31.
#ifdef DEBUG
    cout << "Testing define flag." << endl;
#endif
    // Task 32.
    int (*fPtr)(double d) = function_3_8;
    (*fPtr)(1.0);
    // Task 33. Bonus.
    float (*(*fPtr2)(int))(char) = function_3_9;
    float (*fPtr3)(char) = (*fPtr2)(1);
    (*fPtr3)('S');
    // Task 34.
    string (*funcTable[])() = {function_3_11, function_3_12, function_3_13};
    for (int i = 0; i < 3; i++) cout << ((*funcTable[i])()) << endl;
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

void chapter_05 () {
    cout << "Chapter's 5 tasks.\n";
    // Task 1. Only public members compiles.
    Class_5_1 class1;
    class1.a = 0;
    class1.f1();
    /*
    class1.b = 0;
    class1.f2();
    class1.c = 0;
    class1.f3();
    */
    // Task 2.
    Structure_5_1 x;
    x.a = "Structure_5_1.a";
    x.b = "Structure_5_1.b";
    x.c = "Structure_5_1.c";
    x.s[0] = x.a;
    x.s[1] = x.b;
    x.s[2] = x.c;
    Class_5_1_2 class2;
    class2.setString("String 1",0);
    class2.setString("String 2",1);
    class2.setString("String 3",2);
    cout << "Strings from Class_5_1_2: ";
    for (int i = 0; i < 3; i++) cout << class2.getString(i) << " ";
    cout << endl;
    // Task 3.
    Class_5_3 class3;
    function_5_3(&class3);
    // Task 4.
    Class_5_4_1 class41;
    Class_5_4_2 class42;
    class41.f(&class42);
    class42.f(&class41);
    // Task 5.
    Class_5_5_1 class51;
    Class_5_5_2 class52;
    Class_5_5_3 class53;
    class52.printA(&class51);
    class53.f(&class51);
    // Task 6-7.
    Class_5_6_1 class61;
    Class_5_6_1::Class_5_6_2 class62;
    Class_5_6_1::Class_5_6_2::Class_5_6_3 class63;
    class61.display();
    class62.display();
    class63.display();
    // Task 8.
    Class_5_8 class5;
    class5.showMap();
    // Task 9. See chapter 4.
    // Task 10.
    cout << "Store 4 objects of Class_5_6_1 in Stash.\n";
    Stash stash;
    stash.initialize(sizeof(Class_5_6_1));
    for (int i = 0; i < 4; i++) {
        Class_5_6_1* clPtr = new Class_5_6_1;
        clPtr->c = '0'+i;
        stash.add(clPtr);
    }
    cout << "Fetch 4 objects of Class_5_6_1 from Stash.\n";
    for (int i = 0; i < 4; i++) {
        Class_5_6_1* clPtr = (Class_5_6_1*)stash.fetch(i);
        clPtr->print();
    }
    // Task 11. See chapter 4.
    // Task 12.
    cout << "Push 4 objects of Class_5_6_1 in Stack_5.\n";
    Stack_5 stack(5);
    for (int i = 0; i < 4; i++) {
        Class_5_6_1* clPtr = new Class_5_6_1;
        clPtr->c = '0'+i;
        stack.push((void*)clPtr);
    }
    cout << "Pop 4 objects of Class_5_6_1 from Stack_5.\n";
    for (int i = 0; i < 4; i++) {
        Class_5_6_1* clPtr = (Class_5_6_1*)stack.pop();
        clPtr->print();
    }
    // Task 13-14. Not compile, if changes in _05_1.cpp.
    StackOfInt st;
    st.stack1 = new StackImp_1(3);
    st.stack2 = new StackImp_2(3);
    cout << "Push 3 values to StackImp_1 & StackImp_2 objects.\n";
    for (int i = 0; i < 3; i++) {
        st.stack1->push(i);
        st.stack2->push(i);
    }
    cout << "Pop 3 values from StackImp_1 & StackImp_2 objects : ";
    for (int i = 0; i < 3; i++) cout << st.stack1->pop() << " " << st.stack2->pop() << " ";
    cout << endl;
}

void chapter_06() {
    cout << "Chapter's 6 tasks.\n";
    // Tasks 1-4.
    Simple class1(0), class2(1);
    for (int i = 0; i < 2; i++) {
        Simple class3(2);
        goto jump;
    }
jump: ;
    // Task 5. May be in old standard, but works fine now.
    int i = 0;
    cout << "Counters in 'for' i,j : ";
    for (; i < 3; i++) for (int i = 0; i < 3; i++) cout << i << " " << i << " ";
    cout << endl;
    // Task 6.
    Class_6_6 class66;
    cout << "Class_6_6 int = " << class66.read();
    class66.change(1);
    cout << " after change int = " << class66.read() << endl;
    // Task 7.
    double dm[3] = { 1.0, 2.0 };
    cout << "Vector of double : ";
    for (int i = 0; i < sizeof(dm)/sizeof(double); i++) cout << dm[i] << " ";
    double dm2[] = { 1.0, 2.0, 3.0 };
    cout << endl << "Second vector of double : ";
    for (int i = 0; i < sizeof(dm2)/sizeof(double); i++) cout << dm2[i] << " ";
    cout << endl;
    // Task 8.
    string sm[3] = { "one", "two", "three" };
    Stack6 class68;
    cout << "Push strings to stack : ";
    for (int i = 0; i < 3; i++) {
        cout << sm[i] << " ";
        class68.push(sm[i]);
    }
    cout << "\nPop strings from stack : ";
    for (int i = 0; i < 3; i++) cout << class68.pop() << " ";
    cout << endl;
    // Task 9.
    Simple class9[] = { Simple(1), Simple(2), Simple(3) };
    cout << "Class Simple vector, print a : ";
    for (int i = 0; i < sizeof(class9)/sizeof(Simple); i++) class9[i].printA();
    cout << endl;
    // Task 10. Just for constructor test.
    Class_6_10 class10(0);
    class10.function();
    cout << endl;
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
}

void Labs_0x01() {
    chapter_07();
}
