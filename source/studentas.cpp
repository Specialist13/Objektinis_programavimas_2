#include "studentas.h"

Stud::Stud(std::istream& is) { 
    readStudent(is);  
}

std::istream& Stud::readStudent(std::istream& is) {
    is>>vardas>>pavarde;
    int n;
    is>>n;
    pazymiai.resize(n);
    for (int i = 0; i < n; i++) {
        is>>pazymiai[i];
    }
    is>>egzaminas;
    return is;
}