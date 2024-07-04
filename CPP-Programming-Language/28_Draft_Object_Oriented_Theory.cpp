#include <iostream>

using namespace std;

// Черновик для темы объектов, после расширить или наоборот разделить и структурировать.

// Вопросы к экзамену по ГО, программирование на ЯВУ(3-ий семестр), с примерами на С++. :)

class Color
{   // Абстрактный класс.
public:
    virtual void paint() const = 0;
};

class Bright final
{   // Класс для композиции, оттенок основного цвета.
public:
    Bright(int init) : diff(init) {
        cout << "Bright constructor with value " << init << ".\n";
    }
    Bright(Bright& rv) = delete;
    Bright(Bright&& rv) = delete;
    ~Bright() {
        cout << "Bright destructor with value " << diff << ".\n";
        diff = 0;
    }
    Bright& operator=(Bright& rv) = delete;
    void* operator new(size_t) {
        void* addr = malloc(sizeof(Bright));
        cout << "Bright operator 'new' allocated at (" << addr << ").\n";
        ((Bright*)addr)->diff = 0;
        return addr;
    }
    void operator delete(void* addr) {
        ((Bright*)addr)->diff = 0;
        cout << "Bright operator 'delete' free memory at (" << addr << ").\n";
        free(addr);
    }
    void set(int value) {
        diff = value;
        cout << "Set bright protected difference value " << diff << ".\n";
    }
    int get() const {
        cout << "Get bright protected value " << diff << ".\n";
        return diff;
    }
private:
    int diff;
};

class Red : public Color
{   // Красный цвет, производный класс от базового цвета. Дополнительные конструкторы и операторы упущены.
public:
    Red(int init) : value(init) {
        cout << "Red constructor, value " << init << ", address (" << this << ").\n";
    }
    ~Red() {
        cout << "Red destructor, value " << value << " address for object (" << this << ").\n";
        value = 0;
    }
    void paint() const {
        cout << "Paint Red with value " << value << ", address is (" << this << "), size is "
             << sizeof(Red) << " bytes.\n";
    }
    virtual int get() const {
        cout << "Virtual get from Red, value " << value << ".\n";
        return value;
    }
private:
    int value;
};

class Green : public Color
{   // Зеленый цвет, производный класс от базового класса. Дополнительные конструкторы и операторы упущены.
public:
    Green(int init) : value(init) {
        cout << "Green constructor with value " << value << " at (" << this << ").\n";
    }
    ~Green() {
        cout << "Green destructor with value " << value << " at (" << this << ").\n";
        value = 0;
    }
    void paint() const {
        cout << "Paint Green, value " << value << ".\n";
    }
    // virtual void greenValue();   // if vptr is empty.
    virtual int get() const {
        cout << "Virtual get from Green, value " << value << ".\n";
        return value;
    }
private:
    int value;
};

/*
class LightGreen : public Green   // private
{   // Светло зеленый цвет с композицей. Дополнительные конструкторы и операторы упущены.
public:
    LightGreen(int init, int bright) : Green(init) {
        mix = new Bright(sizeof(Bright));
        cout << "Light green constructor with Bright object composition green " << init << " and " << bright
             << ", address at (" << this << ").\n";
        // mix->diff = init;    // protected
        mix->set(init);
    }
    ~LightGreen() {
        cout << "Light green destructor with Bright object at (" << this << ").\n";
        delete mix;
    }
    void paint() const {
        cout << "Paint light green, trying to get green value...\n";
        int value = this->get();
        cout << "Value of base class Green is " << value << ".\n";
        value = mix->get();
        cout << "Size of LightGreen is " << sizeof(LightGreen) << " bytes.\n";
        cout << "VPTR from LightGreen class:\n"
             << "Green::get\t\t" << (void*)(&(this->Green::get)) << ";\n";
        cout << "Green::paint\t\t" << (void*)(&(this->Green::paint)) << ";\n";
        cout << "LightGreen::paint\t" << (void*)(&(this->paint)) << ";\n";
    }
    int get() const {

    }
private:
    Bright* mix;
};

class Yellow : public Red, public Green // public Color,
{   // Желтый с наследованием и перекрытием имен. Дополнительные конструкторы и операторы упущены.
public:
    Yellow(int red, int green) : Red(red), Green(green) {
        cout << "Yellow constructor, calling all bases constructors, size of class " << sizeof(Yellow) << " bytes.\n";
    }
    ~Yellow() {
        cout << "Yellow destructor, calling all bases classes.\n";
    }
    void paint() const {
        cout << "Paint Yellow, with abstract class Color and privates Red and Green. "
             << "size is " << sizeof(Yellow) << "bytes.\n";
        cout << "VPTR from Yellow class:\n"
             << "Green::get\t\t" << (void*)(&(this->Green::get)) << ";\n";
        cout << "Green::paint\t\t" << (void*)(&(this->Green::paint)) << ";\n";
        cout << "Yellow::paint\t\t" << (void*)(&(this->paint)) << ";\n";
        // int value = get();  // multiple classes base
        int value = Green::get();
    }
protected:
    // Red r, Green g;
};

*/

void chapter_28()
{
    cout << "Object Oriented Theory, set part and update rep.\n\n";
    // Динамические объекты и перегрузка операторов new(), delete(), создание объекта.
    /*
    cout << "Create object of class Bright, using overloading operator 'new'.\n";
    Bright* obj = new Bright(5);
    obj->set(3);
    delete obj;
    // Инкапсуляция, наследование и композиция.
    cout << "\nIncapsulation, inheritance and composition.\n\n";
    cout << "Interface or abstract class 'Color' size is " << sizeof(Color) << " bytes.\n";
    // Color abstractObject; // is an abstract class.
    Red red(1);
    red.paint();
    LightGreen lGreen(3, 7);    // Порядок.
    // lGreen.get();   // get is private.
    lGreen.paint();
    cout << "\nPolymorphic calls and class ierarchy.\n\n";
    // Полиморфизм и таблица виртуальных вызовов.
    // Color* basePtr = new Yellow(2, 4);  // ambiguous.
    Yellow yellow(2, 4);
    yellow.paint();
    Color* basePtr = &lGreen;
    basePtr->paint();
    Green* ptr = &yellow;
    */
}
