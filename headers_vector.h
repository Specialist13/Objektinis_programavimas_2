#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Stud {
    string vardas, pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double galutinis_vid;
    double galutinis_med;
};