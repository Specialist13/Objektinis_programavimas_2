#include "studentas.h"
#include "ivesties_tikrinimas.h"
#include "skaiciavimo_funkcijos.h"

Stud::Stud(std::istream& is, string rezimas) { 
    readStudent(is, rezimas);  
}

std::istream& Stud::readStudent(std::istream& is, string rezimas) {
    string tekstas;
    if (rezimas=="ranka" || rezimas=="pazymiu_generavimas") {    
        tekstas = "Iveskite studento varda: ";
        ivesties_tikrinimas(vardas, tekstas);
        if (vardas == "n") {
            return is;
        }
        
        tekstas = "Iveskite studento pavarde: ";
        ivesties_tikrinimas(pavarde, tekstas);
    }
    if (rezimas=="ranka") {
        cout << "Veskite jo pazymius. Kai noresite baigti, iveskite '0'.\n";
        while (true) {
            tekstas = "Iveskite pazymi: ";
            int pazymys;
            ivesties_tikrinimas(pazymys, tekstas);
            
            if (pazymys == 0) {
                break;
            }
            else if (pazymys < 0 || pazymys > 10) {
                cout << "Neteisingas pazymys. Bandykite dar karta.\n";
                continue;
            }
            pazymiai.push_back(pazymys);
        }
        
        tekstas = "Iveskite studento egzamino pazymi: ";
        ivesties_tikrinimas(egzaminas, tekstas);
        while (egzaminas < 0 || egzaminas > 10) {
            cout << "Neteisingas pazymys. Bandykite dar karta.\n";
            ivesties_tikrinimas(egzaminas, tekstas);
        }
        
        skaiciuotiGalutini();
    }    

    if (rezimas=="visko_generavimas") {
        srand(time(NULL));
        int n = rand() % 10 + 1;
        for (int j = 0; j < n; j++) {
            int pazymys = rand() % 10 + 1;
            pazymiai.push_back(pazymys);
        }
        egzaminas = rand() % 10 + 1;
        skaiciuotiGalutini();
    }

    if (rezimas=="pazymiu_generavimas" || rezimas=="visko_generavimas") {
        srand(time(NULL));
        int n = rand() % 10 + 1;
        for (int j = 0; j < n; j++) {
            int pazymys = rand() % 10 + 1;
            pazymiai.push_back(pazymys);
        }
        egzaminas = rand() % 10 + 1;
        skaiciuotiGalutini();
    }

    
    return is;
}

void Stud::skaiciuotiGalutini() {
    galutinis_vid = vidurkis(pazymiai, egzaminas);
    galutinis_med = mediana(pazymiai, egzaminas);
}