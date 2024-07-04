#include "26_Patterns.hpp"

using namespace std;

Singleton Singleton::single(0, true);

int Singleton::i;

map<string, FactoryShapeF2*> FactoryShapeF2::factories ;

std::map<std::string, ShapeV*> ShapeV::shapesV;

// Change true to false, if output is needed.
FactoryShapeF2Init FactoryShapeF2Init::factoryInit(true);

Singleton& Singleton::instance() { return single; }

int Singleton::getValue() { return i; }

void Singleton::setValue(int x) { i = x; }

Singleton::Singleton(int x, bool quietly) {
    i = x;
    if (!quietly) cout << "Singleton::Singleton(" << i << ")" << endl;
}

string Class_10_B::file;

Class_10_B Class_10_B::reader;

string Class_10_B::readFile() {
    fstream textFile;
    textFile.open(file.data(), ios::in);
    string result;
    getline(textFile, result, '\0');
    textFile.close();
    return result;
}
// check file.
Class_10_B::Class_10_B() { file = "files/chapter-10-1.txt"; }

vector<Class_10_C*> Class_10_C::objects;

int Class_10_C::counter;

int Class_10_C::limit;

void Class_10_C::init(int lim) {
    counter = 0;
    limit = lim;
}

bool Class_10_C::create(Class_10_C *newObject) {
    if (counter < limit) {
        cout << "Counter of Class_10_C, less than limit. Creating object..." << endl;
        counter++;
        objects.push_back(new Class_10_C);
        newObject = objects[objects.size()-1];
        return true;
    } else {
        cout << "Counter of Class_10_C, is reached it's limit, returninig..." << endl;
        return false;
    }
}

Class_10_C::Class_10_C() {
    cout << "Class_10_C::Class_10_C(), counter = " << counter << endl;
}

void StateRotation::Object::responce() { cout << "StateRotation::Object::responce()" << endl; }

void StateRotation::Tool::responce() { cout << "StateRotation::Tool::responce()" << endl; }

void StateRotation::Material::responce() { cout << "StateRotation::Material::responce()" << endl; }

StateRotation::StateRotation() : iteration(0), limit(3) {
    cout << "StateRotation::StateRotation()" << endl;
    // fix
    // state = new Object_A;
}

void StateRotation::function() {
    state->responce();
}

void StateRotation::action() {
    delete state;
    if (++iteration >= limit) iteration = 0;
    switch (iteration) {
    case 0:
        // fix
        // state = new Object_A;
        break;
    case 1:
        state = new Tool;
        break;
    case 2:
        state = new Material;
        break;
    default:
        break;
    }
}

void function_10_5(std::string value) { cout << "StackAdapter::operator*() = " << value << endl; }

Class_10_6::Class_10_6(std::vector<std::string>& fileNames) {
    cout << "Class_10_6::Class_10_6()" << endl;
    for (int i = 0; i < fileNames.size(); i++) {
        fstream* file = new fstream;
        if ( i < fileNames.size() - 1) file->open(fileNames[i].data(), ios::in); else file->open(fileNames[i].data(), ios::out | ios::app);
        files.push_back(file);
    }
}

Class_10_6::~Class_10_6() {
    cout << "Class_10_6::~Class_10_6()" << endl;
    for (int i = 0; i < files.size(); i++) {
        files[i]->close();
        delete files[i];
    }
}

void Class_10_6::toUpperCase() {}

void Class_10_6::searchWords() {}

Class_10_6_1::Class_10_6_1(std::vector<string> &fileNames) : Class_10_6(fileNames) {
    cout << "Class_10_6_1::Class_10_6_1()" << endl;
}

Class_10_6_1::~Class_10_6_1() {
    cout << "Class_10_6_1::~Class_10_6_1()" << endl;
}

void Class_10_6_1::toUpperCase() {
    for (int i = 0; i < files.size() - 1; i++) {
        string text;
        getline(*files[i], text, '\0');
        for (int j = 0; j < text.size(); j++) text[j] = toupper(text[j]);
        *files[files.size()-1] << text;
    }
}

Class_10_6_2::Class_10_6_2(std::vector<string> &fileNames) : Class_10_6(fileNames) {
    cout << "Class_10_6_2::Class_10_6_2()" << endl;
}

Class_10_6_2::~Class_10_6_2() {
    cout << "Class_10_6_2::~Class_10_6_2()" << endl;
}

void Class_10_6_2::searchWords() {
   vector<string> words;
   string delim = " ,.;-\"'!?:\n\0";
   int idx1 = 0, idx2, last = files.size() - 1;
   string text;
   for (int i = 0; i < last - 1; i++) files[i]->seekg(0, ios::beg);
   getline(*files[0], text, '\0');
   *files[last] << "All words in the first file: ";
   while ( (idx2 = text.find_first_of(delim, idx1)) != string::npos ) {
       words.push_back(string(text, idx1, idx2-idx1));
       idx1 = text.find_first_not_of(delim, idx2);
       *files[last] << words[words.size()-1] << " ";
   }
   *files[last] << "\nWords founded in all files except first one: ";
   for (int i = 1; i < files.size() - 1; i++) {
       text.clear();
       getline(*files[i], text, '\0');
       for (int j = 0; j < words.size(); j++) {
           idx1 = 0;
           while ( (idx2 = text.find(words[j], idx1)) != string::npos ) {
               if ( idx2 != string::npos ) {
                   *files[last] << words[j] << " ";
                   idx1 = ++idx2;
               }
           }
       }
   }
   *files[last] << endl;
}

Class_10_7::Class_10_7(Class_10_6 &iBase) : base(iBase) { cout << "Class_10_7::Class_10_7()" << endl; }

void Class_10_7::toUpperCase() { base.toUpperCase(); }

void Class_10_7::searchWords()  { base.searchWords(); }

bool Class_10_8_A::function() {
    cout << "Class_10_8_1::function()" << endl;
    return false;
}

bool Class_10_8_B::function() {
    cout << "Class_10_8_2::function()" << endl;
    return false;
}

bool Class_10_8_C::function() {
    cout << "Class_10_8_3::function()" << endl;
    return true;
}

Class_10_8_D::Class_10_8_D(vector<Class_10_8_0*> iBase) {
    base = iBase;
    state = 0;
}

void Class_10_8_D::function() {
    cout << "Class_10_8_4::function(), state: " << state << endl;
    base[state++]->function();
    if (state == base.size()) state = 0;
    cout << "Class_10_8_4::function(), call all functions until success:" << endl;
    while ( (base[state++]->function()) )
        if (state == base.size()) state = 0;
}

ShapeF1::~ShapeF1() { cout << "ShapeF1::~ShapeF1()" << endl; }

ShapeF1::Error::Error(std::string type) : logic_error("Error create " + type) {}

ShapeF1* ShapeF1::factory(const std::string type) throw (Error) {
    if (type == "Circle") return new CircleF1;
    if (type == "Square") return new SquareF1;
    if (type == "Triangle") return new TriangleF1;
    throw Error(type);
}

CircleF1::CircleF1() { cout << "CircleF1::CircleF1()" << endl; }

void CircleF1::draw() { cout << "CircleF1::draw()" << endl; }

void CircleF1::erase() { cout << "CircleF1::erase()" << endl; }

CircleF1::~CircleF1() { cout << "CircleF1::~CircleF1()" << endl; }

SquareF1::SquareF1() { cout << "SquareF1::SquareF1()" << endl; }

void SquareF1::draw() { cout << "SquareF1::draw()" << endl; }

void SquareF1::erase() { cout << "SquareF1::erase()" << endl; }

SquareF1::~SquareF1() { cout << "SquareF1::~SquareF1()" << endl; }

TriangleF1::TriangleF1() { cout << "TriangleF1::TriangleF1()" << endl; }

void TriangleF1::draw() { cout << "TriangleF1::draw()" << endl; }

void TriangleF1::erase() { cout << "TriangleF1::erase()" << endl; }

TriangleF1::~TriangleF1() { cout << "TriangleF1::~TriangleF1()" << endl; }

ShapeF2::~ShapeF2() { cout << "ShapeF2::~ShapeF2()" << endl; }



FactoryShapeF2::FactoryShapeF2(bool quietly) : quiet(quietly) {
    if (!quiet) cout << "FactoryShapeF2::FactoryShapeF2()" << endl;
}

FactoryShapeF2::~FactoryShapeF2() {
    if (!quiet) cout << "FactoryShapeF2::~FactoryShapeF2()" << endl;
}

FactoryShapeF2::Error::Error(string type) : logic_error("Error creating " + type) {}

ShapeF2* FactoryShapeF2::factory(const std::string& id, bool isBold) throw (Error) {
    if (factories.find(id) != factories.end()) {
        if ( isBold ) return factories[id]->createBold(); else return factories[id]->createThin();
    } else throw Error(id);
}

CircleF2::CircleF2(bool isBold) { cout << "CircleF2::CircleF2(" << isBold << ")" << endl; }

CircleF2::~CircleF2() { cout << "CircleF2::~CircleF2()" << endl; }

CircleF2::Factory::Factory(bool quietly) : FactoryShapeF2(quietly) {}

ShapeF2* CircleF2::Factory::createThin() { return new CircleF2(false); }

ShapeF2* CircleF2::Factory::createBold() { return new CircleF2(true); }

void CircleF2::draw() { cout << "CircleF2::draw()" << endl; }

void CircleF2::erase() { cout << "CircleF2::erase()" << endl; }

SquareF2::Factory::Factory(bool quietly) : FactoryShapeF2(quietly) {}

SquareF2::SquareF2(bool isBold) { cout << "SquareF2::SquareF2(" << isBold << ")" << endl; }

ShapeF2* SquareF2::Factory::createThin() { return new SquareF2(false); }

ShapeF2* SquareF2::Factory::createBold() { return new SquareF2(true); }

void SquareF2::draw() { cout << "SquareF2::draw()" << endl; }

void SquareF2::erase() { cout << "SquareF2::erase()" << endl; }

SquareF2::~SquareF2() { cout << "SquareF2::~SquareF2()" << endl; }

TriangleF2::Factory::Factory(bool quietly) : FactoryShapeF2(quietly) {}

TriangleF2::TriangleF2(bool isBold) { cout << "TriangleF2::TriangleF2(" << isBold << ")" << endl; }

ShapeF2* TriangleF2::Factory::createThin() { return new TriangleF2(false); }

ShapeF2* TriangleF2::Factory::createBold() { return new TriangleF2(true); }

void TriangleF2::draw() { cout << "TriangleF2::draw()" << endl; }

void TriangleF2::erase() { cout << "TriangleF2::erase()" << endl; }

TriangleF2::~TriangleF2() { cout << "TriangleF2::~TriangleF2()" << endl; }

FactoryShapeF2Init::FactoryShapeF2Init(bool quietly) {
    FactoryShapeF2::factories["Thin circle"] = new CircleF2::Factory(quietly);
    FactoryShapeF2::factories["Thin square"] = new SquareF2::Factory(quietly);
    FactoryShapeF2::factories["Thin triangle"] = new TriangleF2::Factory(quietly);
    FactoryShapeF2::factories["Bold circle"] = new CircleF2::Factory(quietly);
    FactoryShapeF2::factories["Bold square"] = new SquareF2::Factory(quietly);
    FactoryShapeF2::factories["Bold triangle"] = new TriangleF2::Factory(quietly);
}

FactoryShapeF2Init::~FactoryShapeF2Init() {
    map<string, FactoryShapeF2*>::iterator it = FactoryShapeF2::factories.begin();
    while ( it != FactoryShapeF2::factories.end() ) delete it++->second;
}

void Worker_1::interactWith(Material* obj) {
    cout << "Worker_1 has work with ";
    obj->action();
}

void Worker_2::interactWith(Material* obj) {
    cout << "Worker_2 has work with ";
    obj->action();
}

void Worker_3::interactWith(Material* obj) {
    cout << "Worker_3 has work with ";
    obj->action();
}

void Brick::action() { cout << "brick" << endl; }

void Wood::action() { cout << "wood" << endl; }

void Steel::action() { cout << "Steel" << endl; }

Worker* Worker_1_Wood::makeWorker() { return new Worker_1; }

Material* Worker_1_Wood::makeMaterial() { return new Wood; }

Worker* Worker_2_Brick::makeWorker() { return new Worker_2; }

Material* Worker_2_Brick::makeMaterial() { return new Brick; }

Worker* Worker_3_Steel::makeWorker() { return new Worker_3; }

Material* Worker_3_Steel::makeMaterial() { return new Steel; }

WorkSet::WorkSet(WorkFactory* fcy) : factory(fcy), worker(factory->makeWorker()), obj(factory->makeMaterial()) {
    cout << "WorkSet::WorkSet()" << endl;
}

void WorkSet::play() {
    worker->interactWith(obj);
}

WorkSet::~WorkSet() {
    delete worker;
    delete obj;
    delete factory;
}

ShapeV::ShapeV() { shape = NULL; }

void ShapeV::draw() { shape->draw(); } // cout << "ShapeV::draw()" << endl; }

void ShapeV::erase() { shape->erase(); } // cout << "ShapeV::erase()" << endl; }

void ShapeV::test() { shape->test(); } // cout << "ShapeV::test()"

ShapeV::~ShapeV() {
    cout << "ShapeV::~ShapeV()" << endl;
    if (shape) {
        cout << "Making virtual call: ";
        shape->erase();
    }
    cout << "Delete shape: ";
    delete shape;
}

ShapeV::Error::Error(std::string type) : logic_error("Cannot create type " + type) {}

ShapeV::ShapeV(std::string type) throw(Error) {
    // if (shapesV.find(type) == shapesV.end()) throw(Error(type));
    if (type == "Circle") shapesV[type] = new CircleV; else
        if (type == "Square") shapesV[type] = new SquareV;
}

CircleV::CircleV() { cout << "CircleV::CircleV()" << endl;}

void CircleV::draw() { cout << "CircleV::draw()" << endl; }

void CircleV::erase() { cout << "CircleV::erase()" << endl; }

void CircleV::test() { cout << "CircleV::test()" << endl; }

CircleV::~CircleV() { cout << "CircleV::~CircleV()" << endl; }

SquareV::SquareV() { cout << "SquareV::SquareV()" << endl; }

void SquareV::draw() { cout << "SquareV::draw()" << endl; }

void SquareV::erase() { cout << "SquareV::erase()" << endl; }

void SquareV::test() { cout << "SquareV::test()" << endl; }

SquareV::~SquareV() { cout << "SquareV::~SquareV()" << endl; }

WordsAnalyzer::WordsAnalyzer(const std::string& fileName) {
    fstream sourceFile;
    sourceFile.open(fileName.data(), ios::in);
    string delim = " ,.;-\"'!?:\n\0";
    int idx1 = 0, idx2;
    string text;
    getline(sourceFile, text, '\0');
    // *files[last] << "All words in the first file: ";
    while ( (idx2 = text.find_first_of(delim, idx1)) != string::npos ) {
        source.push_back(string(text, idx1, idx2-idx1));
        idx1 = text.find_first_not_of(delim, idx2);
    }
    sourceFile.close();
}

int WordsAnalyzer::analyze() {
    cout << "WordsAnalyzer::analyze()" << endl;
}

void WordsAnalyzer::getWords() {
    cout << "All words in source file: ";
    copy(source.begin(), source.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
}

WordsToSet::WordsToSet(const std::string& fileName) : WordsAnalyzer(fileName) {
    cout << "WordsToSet::WordsToSet()" << endl;
}

int WordsToSet::analyze() {
    for (int i = 0; i < source.size(); i++)
        words.insert(source[i]);
    return words.size();
}

void WordsToSet::getWords() {
    cout << "All words in set<string>: ";
    for (set<string>::iterator it = words.begin(); it != words.end(); it++)
        cout << *it << " ";
    cout << endl;
}

WordsToMap::WordsToMap(const std::string& fileName) : WordsAnalyzer(fileName) {
    cout << "WordsToMap::WordsToMap()" << endl;
}

int WordsToMap::analyze() {
    for (int i = 0; i < source.size(); i++)
        if (words.find(source[i]) == words.end())
            words[source[i]] = 1;
        else
            words[source[i]]++;
    return words.size();
}

void WordsToMap::getWords() {
    cout << "All words in map<string>: ";
    for (map<string, int>::iterator it = words.begin(); it != words.end(); it++)
        cout << it->first << "(" << it->second << ") ";
    cout << endl;
}

Observer::~Observer() { cout << "Observer::~Observer()" << endl; }

void Object_A::setState(bool change) { changed = change; }

void Object_A::addObserver(Observer& obs) { observers.insert(&obs); }

void Object_A::deleteObserver(Observer& obs) { observers.erase(&obs); }

void Object_A::clearObservers() { observers.clear(); }

int Object_A::count() { return observers.size(); }

bool Object_A::hasChanged() { return changed; }

void Object_A::notify() {
    if ( !changed ) return;
    setState(false);
    std::set<Observer*>::iterator it;
    for (it = observers.begin(); it != observers.end(); it++)
        (*it)->update(this);
}

void Observer::update(Object_A* obj) { cout << "Observer::update()" << endl; }

Object_A::~Object_A() {}

void Class_17::function_1() { cout << "Class_17::function_1()" << endl; }

void Class_17::function_2() { cout << "Class_17::function_2()" << endl; }

std::map<std::string, std::map<std::string, gameResult> > Item::resultMap;

Item::~Item() { cout << "Item::~Item()" << endl; }

ostream& operator<<(ostream& os, const Item* value) { return value->print(os); }

gameResult Paper::compete(const Item* item) {
    return resultMap[string(typeid(*item).name())][string(typeid(*this).name())];
}

void Item::createMap() {
    resultMap["5Paper"]["5Paper"] = draw;
    resultMap["5Paper"]["7Scissor"] = win;
    resultMap["5Paper"]["6Rock_1"] = lose;
    resultMap["7Scissor"]["7Scissor"] = draw;
    resultMap["7Scissor"]["6Rock_1"] = win;
    resultMap["7Scissor"]["5Paper"] = lose;
    resultMap["6Rock_1"]["6Rock_1"] = draw;
    resultMap["6Rock_1"]["7Scissor"] = lose;
    resultMap["6Rock_1"]["7Scissor"] = win;
}

ostream& Paper::print(ostream &os) const { return os << "paper"; }

gameResult Scissor::compete(const Item* item) {
    return resultMap[string(typeid(*item).name())][string(typeid(*this).name())];
}

std::ostream& Scissor::print(std::ostream &os) const { return os << "scissor"; }

gameResult Rock_1::compete(const Item* item) {
    return resultMap[string(typeid(*item).name())][string(typeid(*this).name())];
}

std::ostream& Rock_1::print(std::ostream &os) const { return os << "rock"; }

Character::~Character() {}

std::map<std::pair<int, int>, int> Character::tResult;

void Character::createMap() {
    tResult.clear();
    tResult[std::make_pair(0, 0)] = draw;
}

void Troll::interact(Character* chr) {
    this->print();
    cout << " - ";
    chr->print();
    cout << endl;
}

void Dwarf::interact(Character* chr) {
    this->print();
    cout << " - ";
    chr->print();
    cout << endl;
}

void Elf::interact(Character* chr) {
    this->print();
    cout << " - ";
    chr->print();
    cout << endl;
}

Troll::Troll() { action = rand() % 3; }

Dwarf::Dwarf() { action = rand() % 3; }

Elf::Elf() { action = rand() % 3; }

void Troll::print() { cout << "Troll(" << action << ", " << item << ")"; }

void Dwarf::print() { cout << "Dwarf(" << action << ", " << item << ")"; }

void Elf::print() { cout << "Elf(" << action << ", " << item << ")"; }

void Character::setItem(int it) { item = it; }

Visit::~Visit() {}

Place_0::~Place_0() {}

void Place_1::accept(Visit &v) { v.visit(this); }

void Place_2::accept(Visit &v) { v.visit(this); }

void Place_3::accept(Visit &v) { v.visit(this); }

void Place_4::accept(Visit &v) { v.visit(this); }

VisitString::operator const std::string &() { return s; }

void VisitString::visit(Place_1 *pl) { s = "place_1"; }

void VisitString::visit(Place_2 *pl) { s = "place_2"; }

void VisitString::visit(Place_3 *pl) { s = "place_3"; }

void VisitString::visit(Place_4 *pl) { s = "place_4"; }

void VisitCat::visit(Place_1 *pl) { cout << "Cat at place_1" << endl; }

void VisitCat::visit(Place_2 *pl) { cout << "Cat at place_2" << endl; }

void VisitCat::visit(Place_3 *pl) { cout << "Cat at place_3" << endl; }

void VisitCat::visit(Place_4 *pl) { cout << "Cat at place_4" << endl; }

void VisitDog::visit(Place_1 *pl) { cout << "Dog at place_1" << endl; }

void VisitDog::visit(Place_2 *pl) { cout << "Dog at place_2" << endl; }

void VisitDog::visit(Place_3 *pl) { cout << "Dog at place_3" << endl; }

void VisitDog::visit(Place_4 *pl) { cout << "Dog at place_4" << endl; }

void chapter_26() {
    /*
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
    const char* classNames[] = { "Thin circle", "Bold square", "Thin square", "Bold triangle", "Bold circle" };
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
        for (int i = 0; i < sizeof(classNames) / sizeof(char*); i++) {
            if ( i % 2 ) vector_3.push_back(FactoryShapeF2::factory(classNames[i], false)); else
                vector_3.push_back(FactoryShapeF2::factory(classNames[i], true));
        }
    } catch ( FactoryShapeF2::Error e ) {
        cout << e.what() << endl;
    }
    for (int i = 0; i < vector_3.size(); i++) {
        vector_3[i]->draw();
        vector_3[i]->erase();
        delete vector_3[i];
    }
    // Task 12. Undefined behaviour, becuase of abscense of destructor in base class;
    cout << "Abstract factory with WorkSet class:\n";
    WorkSet set_1(new Worker_1_Wood), set_2(new Worker_2_Brick), set_3(new Worker_3_Steel);
    set_1.play();
    set_2.play();
    set_3.play();
    // Task 13. Strange and dangerous architecture, but works...
    // Task 14. Think later, because of old method is still using.
    vector<ShapeV*> vector_4;
    const char* shapeNames[] = { "Circle", "Square", "Square" };
    cout << "Virtual construction in ShapeV:\n";
    try {
        for (int i = 0; i < sizeof(shapeNames) / sizeof(char*); i++) {
            if ( i % 2 ) vector_4.push_back(new ShapeV(shapeNames[i])); else
                vector_4.push_back(new ShapeV(shapeNames[i]));
        }
    } catch ( ShapeV::Error e ) {
        cout << e.what() << endl;
    }
    for (int i = 0; i < vector_4.size(); i++) delete vector_4[i];
    // Task 15.
    WordsToSet wordsSet("labs_0x02/files/chapter-10-2.txt");
    WordsToMap wordsMap("labs_0x02/files/chapter-10-2.txt");
    cout << "Result of WordsToSet::analyze(): " << wordsSet.analyze() << endl;
    cout << "Result of WordsToMap::analyze(): " << wordsMap.analyze() << endl;
    wordsSet.getWords();
    wordsMap.getWords();
    // Task 16.
    Object object;
    vector<Observer*> vector_5;
    for (int i = 0; i < 5; i++) {
        vector_5.push_back(new Observer);
        // if ( i % 2 ) vector_5[vector_5.size()-1]->setState(true);
        object.addObserver(*vector_5[vector_5.size()-1]);
    }
    cout << "Object has " << object.count() << " observers. Notify all observers:\n";
    object.setState(true);
    object.notify();
    // Task 17. Not found original source code.
    Class_17 cl;
    cl.function_1();
    cl.function_2();
    // Task 18.
    vector<Item*> vector_6(10), vector_7(10);
    Item::createMap();
    cout << "Generating two vectors of Item, sizes =  " << vector_6.size() << " and " << vector_7.size() << ", generating...\n";
    generate(vector_6.begin(), vector_6.end(), ItemGen());
    generate(vector_7.begin(), vector_7.end(), ItemGen());
    for (int i = 0; i < 10; i++) {
        cout << vector_6.at(i) << " ";
        cout << vector_7.at(i) << " ";
        cout << typeid(vector_6[i]).name() << endl;
    }
    cout << "Result of compteting with this object:\n";
    transform(vector_6.begin(), vector_6.end(), vector_7.begin(), ostream_iterator<gameResult>(cout, "\n"), Compete());
    // Task 19-20. Too many lines, just a few...
    vector<Character*> vector_8, vector_9;
    cout << "All characters in both vectors<Character*>: ";
    srand(0);
    for (int i = 0; i < 10; i++) {
        Character* chr;
        switch ( rand() % 3 ) {
        case 0:
            chr = new Troll;
            break;
        case 1:
            chr = new Dwarf;
            break;
        case 2:
            chr = new Elf;
            break;
        default:
            cout << "Something goes wrong..." << endl;
            break;
        }
        chr->setItem(rand() % 2);
        chr->print();
        if ( i % 2 ) vector_8.push_back(chr); else vector_9.push_back(chr);
        cout << " ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++) vector_8[i]->interact(vector_9[i]);
    // Tasks 21-23. Last task, too many.
    vector<Place_0*> vector_10;
    for (int i = 0; i < 10; i++)
        switch ( rand() % 4 ) {
        case 0:
            vector_10.push_back(new Place_1);
            break;
        case 1:
            vector_10.push_back(new Place_2);
            break;
        case 2:
            vector_10.push_back(new Place_3);
            break;
        case 3:
            vector_10.push_back(new Place_4);
            break;
        default:
            cout << "Something goes wrong..." << endl;
        }
    VisitString stringV;
    vector<Place_0*>::iterator it_2;
    for (it_2 = vector_10.begin(); it_2 != vector_10.end(); it_2++) {
        (*it_2)->accept(stringV);
        cout << string(stringV) << endl;
    }
    VisitCat visitor_1;
    VisitDog visitor_2;
    for (it_2 = vector_10.begin(); it_2 != vector_10.end(); it_2++) {
        (*it_2)->accept(visitor_1);
        (*it_2)->accept(visitor_2);
    }
    */
}
