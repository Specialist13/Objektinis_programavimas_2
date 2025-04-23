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
    void skaiciuotiGalutini();
    ~Stud() {
        vardas.clear();
        pavarde.clear();
        pazymiai.clear();
    }
    Stud(const Stud &s) {
        vardas = s.vardas;
        pavarde = s.pavarde;
        pazymiai = s.pazymiai;
        egzaminas = s.egzaminas;
        galutinis_vid = s.galutinis_vid;
        galutinis_med = s.galutinis_med;
    }
    Stud& operator=(const Stud &s) {
        if (this != &s) {
            vardas = s.vardas;
            pavarde = s.pavarde;
            pazymiai = s.pazymiai;
            egzaminas = s.egzaminas;
            galutinis_vid = s.galutinis_vid;
            galutinis_med = s.galutinis_med;
        }
        return *this;
    }
    Stud(Stud &&s) noexcept {
        vardas = std::move(s.vardas);
        pavarde = std::move(s.pavarde);
        pazymiai = std::move(s.pazymiai);
        egzaminas = s.egzaminas;
        galutinis_vid = s.galutinis_vid;
        galutinis_med = s.galutinis_med;
    }
    Stud& operator=(Stud &&s) noexcept {
        if (this != &s) {
            vardas = std::move(s.vardas);
            pavarde = std::move(s.pavarde);
            pazymiai = std::move(s.pazymiai);
            egzaminas = s.egzaminas;
            galutinis_vid = s.galutinis_vid;
            galutinis_med = s.galutinis_med;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Stud& s) {
        os << std::left<<std::setw(25)<< s.vardas <<std::setw(25)<< s.pavarde <<std::setw(25)<< std::fixed << std::setprecision(2) << s.galutinis_vid << std::setw(25)<< s.galutinis_med;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Stud& s) {
        string vardas;
        is >> vardas;
        if (vardas == "n") {
            return is;
        }
        s.vardas=vardas;
        is >> s.pavarde;
        int pazymys;
        while (is >> pazymys && pazymys != -1) {
            s.pazymiai.push_back(pazymys);
        }
        is >> s.egzaminas;
        return is;
    }

};

#endif