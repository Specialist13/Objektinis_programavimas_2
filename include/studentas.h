#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "headers_main.h"
#include "skaiciavimo_funkcijos.h"

class Stud {
    private:
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double galutinis_vid;
    double galutinis_med;
public:
    Stud() : egzaminas(0) {}
    Stud(std::istream& is);
    inline string getVardas() const { return vardas; }
    inline std::string pavarde() const { return pavarde; }
    double galBalas(std::function<double(std::vector<int>&, int&)> func = mediana) const; 
    std::istream& readStudent(std::istream&); 
};

#endif