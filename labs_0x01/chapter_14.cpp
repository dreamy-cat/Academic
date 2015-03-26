#include "chapter_14.h"

using namespace std;

Vehicle_14::Vehicle_14(int ii) : i(ii) {
    cout << "Vehicle_14 constructor, int = " << i << endl;
}

Car_14::Car_14(int ii) : Vehicle_14(ii) {
    cout << "Car_14 constructor." << endl;
}
