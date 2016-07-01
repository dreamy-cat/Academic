#include "chapter_10.h"

using namespace std;

Singleton Singleton::single(0);

int Singleton::i;

map<string, FactoryShapeF2*> FactoryShapeF2::factories ;

std::map<std::string, ShapeV*> ShapeV::shapesV;

FactoryShapeF2Init FactoryShapeF2Init::factoryInit;

Singleton& Singleton::instance() { return single; }

int Singleton::getValue() { return i; }

void Singleton::setValue(int x) { i = x; }

Singleton::Singleton(int x) {
    i = x;
    cout << "Singleton::Singleton(" << i << ")" << endl;
}

string Class_10_2::file;

Class_10_2 Class_10_2::reader;

string Class_10_2::readFile() {
    fstream textFile;
    textFile.open(file.data(), ios::in);
    string result;
    getline(textFile, result, '\0');
    textFile.close();
    return result;
}

Class_10_2::Class_10_2() { file = "labs_0x02/files/chapter-10-1.txt"; }

vector<Class_10_3*> Class_10_3::objects;

int Class_10_3::counter;

int Class_10_3::limit;

void Class_10_3::init(int lim) {
    counter = 0;
    limit = lim;
}

bool Class_10_3::create(Class_10_3 *newObject) {
    if (counter < limit) {
        cout << "Counter of Class_10_3, less than limit. Creating object..." << endl;
        counter++;
        objects.push_back(new Class_10_3);
        newObject = objects[objects.size()-1];
        return true;
    } else {
        cout << "Counter of Class_10_3, is reached it's limit, returninig..." << endl;
        return false;
    }
}

Class_10_3::Class_10_3() {
    cout << "Class_10_3::Class_10_3(), counter = " << counter << endl;
}

void StateRotation::Object::responce() { cout << "StateRotation::Object::responce()" << endl; }

void StateRotation::Tool::responce() { cout << "StateRotation::Tool::responce()" << endl; }

void StateRotation::Material::responce() { cout << "StateRotation::Material::responce()" << endl; }

StateRotation::StateRotation() : iteration(0), limit(3) {
    cout << "StateRotation::StateRotation()" << endl;
    state = new Object;
}

void StateRotation::function() {
    state->responce();
}

void StateRotation::action() {
    delete state;
    if (++iteration >= limit) iteration = 0;
    switch (iteration) {
    case 0:
        state = new Object;
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

bool Class_10_8_1::function() {
    cout << "Class_10_8_1::function()" << endl;
    return false;
}

bool Class_10_8_2::function() {
    cout << "Class_10_8_2::function()" << endl;
    return false;
}

bool Class_10_8_3::function() {
    cout << "Class_10_8_3::function()" << endl;
    return true;
}

Class_10_8_4::Class_10_8_4(vector<Class_10_8*> iBase) {
    base = iBase;
    state = 0;
}

void Class_10_8_4::function() {
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

FactoryShapeF2::FactoryShapeF2() { cout << "FactoryShapeF2::FactoryShapeF2()" << endl; }

FactoryShapeF2::~FactoryShapeF2() { cout << "FactoryShapeF2::~FactoryShapeF2()" << endl; }

FactoryShapeF2::Error::Error(string type) : logic_error("Error creating " + type) {}

ShapeF2* FactoryShapeF2::factory(const std::string& id, bool isBold) throw (Error) {
    if (factories.find(id) != factories.end()) {
        if ( isBold ) return factories[id]->createBold(); else return factories[id]->createThin();
    } else throw Error(id);
}

CircleF2::CircleF2(bool isBold) { cout << "CircleF2::CircleF2(" << isBold << ")" << endl; }

CircleF2::~CircleF2() { cout << "CircleF2::~CircleF2()" << endl; }

ShapeF2* CircleF2::Factory::createThin() { return new CircleF2(false); }

ShapeF2* CircleF2::Factory::createBold() { return new CircleF2(true); }

void CircleF2::draw() { cout << "CircleF2::draw()" << endl; }

void CircleF2::erase() { cout << "CircleF2::erase()" << endl; }

SquareF2::SquareF2(bool isBold) { cout << "SquareF2::SquareF2(" << isBold << ")" << endl; }

ShapeF2* SquareF2::Factory::createThin() { return new SquareF2(false); }

ShapeF2* SquareF2::Factory::createBold() { return new SquareF2(true); }

void SquareF2::draw() { cout << "SquareF2::draw()" << endl; }

void SquareF2::erase() { cout << "SquareF2::erase()" << endl; }

SquareF2::~SquareF2() { cout << "SquareF2::~SquareF2()" << endl; }

TriangleF2::TriangleF2(bool isBold) { cout << "TriangleF2::TriangleF2(" << isBold << ")" << endl; }

ShapeF2* TriangleF2::Factory::createThin() { return new TriangleF2(false); }

ShapeF2* TriangleF2::Factory::createBold() { return new TriangleF2(true); }

void TriangleF2::draw() { cout << "TriangleF2::draw()" << endl; }

void TriangleF2::erase() { cout << "TriangleF2::erase()" << endl; }

TriangleF2::~TriangleF2() { cout << "TriangleF2::~TriangleF2()" << endl; }

FactoryShapeF2Init::FactoryShapeF2Init() {
    FactoryShapeF2::factories["Thin circle"] = new CircleF2::Factory;
    FactoryShapeF2::factories["Thin square"] = new SquareF2::Factory;
    FactoryShapeF2::factories["Thin triangle"] = new TriangleF2::Factory;
    FactoryShapeF2::factories["Bold circle"] = new CircleF2::Factory;
    FactoryShapeF2::factories["Bold square"] = new SquareF2::Factory;
    FactoryShapeF2::factories["Bold triangle"] = new TriangleF2::Factory;
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
