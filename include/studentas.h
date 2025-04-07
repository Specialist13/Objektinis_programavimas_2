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
    Stud(std::istream& is, string rezimas);
    inline string getVardas() const { return vardas; }
    inline std::string getPavarde() const { return pavarde; }
    inline double getGalutinisVid() const { return galutinis_vid; }
    inline double getGalutinisMed() const { return galutinis_med; }
    std::istream& readStudent(std::istream&, string rezimas); 
    void Stud::skaiciuotiGalutini();
};

#endif