#include "09_Inline_Functions.hpp"

using namespace std;

void function_9_4_1() {
    int a = 1, b = 2, c = 3;
    a = b * c;
    b = c + a;
    c = b - a;
}

void chapter_09() {
    cout << "Chapter's 9 tasks.\n";
    // Task 1.
    // 'x' was not declared in this scope
// #define F (x) (x+1)
#define F(x) (x+1)
    int i1 = F(1);
    cout << "F(1) = " << i1 << endl;
    // Task 2.
#define FLOOR1(x,b) x<=b?1:0
    cout << "Macros FLOOR first version result : ";
    if (FLOOR1(5,3)) cout << "true" << endl; else cout << "false" << endl;
    cout << "Macors FLOOR incorrect result : ";
    int a = 0x0F;
    if (FLOOR1(a&0x0F,a&0x07)) cout << "true" << endl; else cout << "false" << endl;
    // Task 3.
#define BAND(x) (((x)>5 && (x)<10) ? (x) : 0)
    cout << "Testing macro BAND.\n";
    for (int i = 4; i < 11; i++) {
        int a = i;
        cout << "a = " << a << " " << "BAND(a+1) = " << BAND((a+1));
        cout << ", a = " << a << endl;
    }
    // Task 4-5. Strange, recheck.
    time_t time;
    tm local;
    local = *std::localtime(&time);
    cout << "Starting second : " << local.tm_sec;
    for (int i = 0; i < 1000; i++)
        for(int j = 0; j < 100000; j++) function_9_4_1();
    local = *std::localtime(&time);
    cout << " after calling standart function : " << local.tm_sec;
    for (int i = 0; i < 1000; i++)
        for(int j = 0; j < 100000; j++) function_9_4_2();
    local = *std::localtime(&time);
    cout << ", after calling inline function : " << local.tm_sec << endl;
    // Task 6. in .h, .cpp
    Class_9_6 class6;
    cout << "Address of class6 : " << (long)&class6 << ", address of 'this' in class function t() : ";
    class6.t();
    cout << endl;
    // Task 7.
    Class_9_7 class7('a');
    cout << "Result of memset char text[] : ";
    class7.print();
    // Task 8.
    Structure_9_8 struc90;
    Structure_9_8::Structure_9_8_1 struc91(&struc90);
    cout << "Values from Structure_9_8_1 : ";
    for (int i = 0; i < 3; i++) { struc91.set(i); struc91.next(); }
    for (int i = 0; i < 3; i++) { struc91.previous(); cout << struc91.read() << " "; }
    cout << endl;
    // Task 9.
    string strings1[] = { "one", "two", "three" };
    StringStack9 stack9;
    cout << "Strings of class StringStacks9 : ";
    for (int i = 0; i < 3; i++) stack9.push(&strings1[i]);
    for (int i = 0; i < 3; i++) cout << *stack9.pop() << " ";
    cout << endl;
    // Task 10-11.
    Color9 class10(Color9::blue);
    class10.color(Color9::blue);
    cout << "Color from Color9 class : " << class10.color() << endl;
    // Task 12. See task 4-5. Later.
    // Task 13.
    Class_9_13 class13;
    class13.function_1();
    // Task 14.
    Class_9_14_2 class14;
    // Task 15. Not convinient without suppress console output.
    const int maxObjs = 4;
    Class_9_14_2* objects[maxObjs];
    for (int i = 0; i < maxObjs; i++) {
        objects[i] = new Class_9_14_2;
    }
    // Task 16.
#define DEBUG16(x) cout << "Debug macros : " #x " " << x << endl;
    string str16 = "Task 16";
    while (!str16.empty()) {
        DEBUG16(str16[str16.size() - 1]);
        str16.resize(str16.size()-1);
    }
    // Task 17.
#define TRACE16(s) cout << "Trace marcos : " << #s << endl , s;
    TRACE16(cout << "Trace paramter.\n");
    // Task 18-19. Very strange, may be not correct.
    char txt18[] = "Task 18.";
    // fix
    /*
    // Record9 class18 (txt18);

    cout << "Class Record9, select method : " << class18.select(1) << endl;
    cout << "Class Record9, one_get method : " << class18.one_get() << endl;
    */
    // Task 20. Need arguments, not possible.
    // Task 21.
#define IFOPEN(var,name) \
    ifstream var; \
    var.open(name); \
    if (var.is_open()) cout << "File " << name << " open. Ok.\n"; else cout << "Error open " << name << " file.\n"; \
    var.close();
    // fix
    // IFOPEN(textFile,"labs_0x01/files/chapter-02.txt");
    // Task 22. Bonus.
}
