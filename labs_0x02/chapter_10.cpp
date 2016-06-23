#include "chapter_10.h"

using namespace std;

Singleton Singleton::single(0);

int Singleton::i;

map<string, FactoryShapeF2*> FactoryShapeF2::factories ;

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
