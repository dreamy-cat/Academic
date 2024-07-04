#include "20_Input_and_Output_Streams.hpp"

using namespace std;

std::ostream& newMan(std::ostream& os) {
    os << "TEST" << endl;
}

FieldWidth::FieldWidth(string message, int n) : maxWidth(n), msg(message) {}

ostream& operator<<(ostream& os, const FieldWidth& fw) {
    FieldWidth tmp = fw;
    if (tmp.msg.size() > tmp.maxWidth) tmp.msg.resize(tmp.maxWidth);
    os << tmp.msg;
    return os;
}

DataBase_1::DataBase_1(std::string dbName) : fileName(dbName) {
    file.open(fileName.data(), ios::out | ios::in | ios::trunc);
}

DataBase_1::~DataBase_1() {
    file.close();
}

size_t DataBase_1::query(size_t n) {
    file.seekg(n*sizeof(Cat));
}

DataBase_1::Cat DataBase_1::retrieve(size_t n) {
    query(n);
    Cat value;
    file.read((char*)&value, sizeof(Cat));
    return value;
}

void DataBase_1::add(const Cat& value) {
    file.write((char*)&value, sizeof(Cat));
}

ostream& operator<<(ostream& os, const DataBase_1::Cat& value) {
    os << "(" << value.id << "," << value.name << ")";
}

int DataBase_1::fromString(const std::string backup) {
    int recordBegin = 0, recordEnd = 0;
    while ((recordEnd = backup.find('\n', recordBegin)) != string::npos) {
        string line(backup, recordBegin, recordEnd-recordBegin);
        int idPos, nextPos;
        if ((idPos = line.find(':', 0)) != string::npos) {
            cout << "Id:" << atoi(string(line, 0, idPos).data());
            cout << ", Name: " << string(line, ++idPos, line.size()-idPos);
        } else cout << "Error in line, no ':' founded." << endl;
        recordBegin = recordEnd+1;
        cout << endl;
    }
}

string toString(int i, int base) {
    string result;
    int sign;
    if (i < 0) sign = -1; else sign = 1;
    do {
        result.insert(result.begin(), char('0' + i % base));
        i /= base;
    } while (i);
    if (sign == -1) result.insert(result.begin(), '-');
    return result;
}

int fromHexString(const std::string source) {
    int value = 0, pos = 0;
    const char hexTab[] = "0123456789ABCDEF";
    for (int i = source.size()-1; i >= 0; --i) {
        char c = toupper(source[i]);
        int index = 0;
        while (index < 16 && c != hexTab[index]) index++;
        if (index != 16) value += index << pos;
        pos += 4;
    }
    return value;
}


void chapter_20() {
    cout << "Chapter's 4 tasks.\n";
    // Task 1. Using std::cout instead of file.
    fstream file_1("labs_0x02/files/chapter-4-1.txt");
    string sourceFile, string_1;
    getline(file_1, sourceFile, '\0');
    string_1 = sourceFile;
    cout << "File chapter-4-1.txt:\n" << sourceFile << endl;
    for (int i = 0; i < string_1.size(); i++) string_1[i] = toupper(string_1[i]);
    cout << "Result text to upper case:\n" << string_1 << endl;
    file_1.close();
    // Task 2.
    string strings_1[] = { "alpha", "beta", "gamma" };
    cout << "Lines with words ";
    for (int i = 0; i < 3; i++) cout << "'" << strings_1[i] << "' ";
    cout << endl;
    file_1.close();
    file_1.open("labs_0x02/files/chapter-4-1.txt", ios::in);
    int line = 0;
    while (getline(file_1,string_1, '\n')) {
        bool isFounded = false;
        for (int i = 0; i < 3 && !isFounded; i++)
            if (string_1.find(strings_1[i], 0)) isFounded = true;
        if (isFounded) cout << line << ":" << string_1 << endl;
        line++;
    }
    cout << endl;
    // Task 3. See file chapter-4-2.txt
    fstream file_2("labs_0x02/files/chapter-4-2.txt", ios::out | ios::in);
    string string_2("String to insert.\n"), string_3;
    getline(file_2, string_3, '\0');
    if (string_3.find(string_2) == string::npos) string_3.insert(0, string_2);
    file_2.seekg(0);
    file_2 << string_3;
    file_2.close();
    // Task 4. See 'man'...
    // Task 5.
    cout << "FieldWidth class test: ";
    cout << FieldWidth("Long string.", 5) << FieldWidth("Short.", 5) << endl;
    // Task 6.
    fstream file_3("labs_0x02/files/chapter-4-2.txt", ios::in);
    string string_4;
    try {
        file_3.exceptions(ios::eofbit | ios::badbit | ios::failbit);
        cout << "Stream exception's flags(eofbit, badbit, failbit): " << file_3.exceptions() << endl;
        while (getline(file_3, string_4, '\n'));
    } catch (...) {
        cout << "Exception from stream, catched." << endl;
    }
    file_3.close();
    // Task 7. Result 3 seconds for atoi(), 8 seconds for operator >>, multiplier x10.
    int int_7;
    string string_5("1");
    istringstream iString(string_5);
    time_t time;
    time = std::time(NULL);
    tm local;
    local = *localtime(&time);
    cout << "Starting second with atoi() function: " << local.tm_sec << endl;
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 100000; j++)
            atoi(string_5.data());
    time = std::time(NULL);
    local = *localtime(&time);
    cout << "After atoi() function: " << local.tm_sec << endl;
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 100000; j++)
            iString >> int_7;
    time = std::time(NULL);
    local = *localtime(&time);
    cout << "After calling inline function: " << local.tm_sec << endl;
    // Task 8-10.
    DataBase_1 db_1("labs_0x02/files/db_1.txt");
    string backup;
    DataBase_1::Cat cat_1, cat_2;
    for (int i = 0; i < 3; i++) {
        cat_1.id = i;
        string name = "Cat_N";
        name[4] = '0'+i;
        cout << name << endl;
        strcpy(cat_1.name, name.data());
        db_1.add(cat_1);
    }
    cout << "Cats in DB_1: ";
    for (int i = 0; i < 3; i++) {
        cat_2 = db_1.retrieve(i);
        cout << cat_2 << " ";
        backup.append(toString(cat_2.id)+":"+string(cat_2.name)+"\n");
    }
    cout << "Backup stirngs for DataBase_1:\n" << backup;
    cout << "Backup restore:\n";
    db_1.fromString(backup);
    // Task 11. For one object. size of(size_t) = 8, size of string = 20;
    size_t num_11 = -1;
    cout << "Size_t = -1(" << num_11 << "), writing to file chapter-4-3.txt as text and to file chapter-4-4.txt as binary.\n";
    fstream file_4, file_5;
    file_4.open("labs_0x02/files/chapter-4-3.txt", ios::out | ios::trunc);
    file_5.open("labs_0x02/files/chapter-4-4.txt", ios::out | ios::trunc);
    for (int i = 0; i < 1; i++) {
        file_4 << num_11;
        file_5.write((char*)&num_11, sizeof(size_t));
    }
    file_4.close();
    file_5.close();
    // Task 12. It seems 53.
    cout << "SQRT(2.0) = " << setprecision(53) << sqrt(2.0) << " - (53 after point)." << endl;
    // Task 13.
    fstream file_6("labs_0x02/files/chapter-4-5.txt");
    string doubleStr;
    vector<double> array_1;
    cout << "All values from file 'chapter-4-5.txt: ";
    while (getline(file_6, doubleStr, '\n')) {
        array_1.push_back(atof(doubleStr.data()));
        cout << doubleStr << " ";
    }
    cout << "\nValues from vector: ";
    for (int i = 0; i < array_1.size(); i++) cout << setprecision(5) << array_1[i] << " ";
    cout << "\nSum, medium, min, max: ";
    double sum = 0, min, max;
    if (!array_1.empty()) {
        min = array_1[0];
        max = array_1[0];
    }
    for (int i = 0; i < array_1.size(); i++) {
        sum += array_1[i];
        if (array_1[i] < min) min = array_1[i];
        if (array_1[i] > max) max = array_1[i];
    }
    cout << sum << ", " << setprecision(2) << sum/(double)array_1.size() << ", " << min << ", " << max << endl;
    file_6.close();
    // Task 14. Pointers to stream, (get,put): (10,20), (10, 5).
    // Task 15.
    string parLine;
    fstream file_7("labs_0x02/files/chapter-4-6.txt");
    const int fields = 6;
    string fieldsName[] = { "Last name:", "First name:", "ID:", "Phone:", "Sales:", "Percent:" };
    const int fieldsW[] = { 12, 12, 6, 13, 12, 12 };
    while ( getline(file_7, parLine, '\n') ) {
        if (parLine.find(',',0) != string::npos) {
            int parBegin = 0, parEnd;
            string params[fields];
            for (int i = 0; i < fields; i++) {
                parEnd = parLine.find(',', parBegin);
                if (parEnd == string::npos) parEnd = parLine.size();
                params[i] = string(parLine, parBegin, parEnd-parBegin);
                parBegin = parEnd+1;
            }
            cout << setw(12) << left << params[2] << setw(12) << left << params[3];
            cout << setw(6) << left << fromHexString(params[0]);
            while (params[1].size() < 10) params[1].insert(0, "X");
            params[1].insert(3, "-");
            params[1].insert(7, "-");
            cout << setw(13) << left << params[1];
            cout << setprecision(2) << setw(12) << left << fixed << atof(params[4].data());
            cout << setprecision(2) << setw(12) << left << scientific << atof(params[5].data());
            cout << endl;
        } else {
            cout << endl << parLine << endl;
            for (int i = 0; i < fields; i++)
                cout << setw(fieldsW[i]) << left << fieldsName[i];
            cout << "\n--------\n";
        }
    }
    file_7.close();
    file_1.close();
}
