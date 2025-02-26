#include "testavimo_funkcijos.h"
#include "ivesties_tikrinimas.h"
#include "skaiciavimo_funkcijos.h"

void testinis_skaitymas_is_failo (Stud &laikinas, vector<Stud> &studentai, string failas){
    std::chrono::duration<double> laiku_suma{0};
    for (int i=0; i<5; i++){
        std::ifstream fd(failas);
        if (fd.fail()){
            cout<<"Failas nerastas.\n";
            return;
        }
        auto pradzia=std::chrono::high_resolution_clock::now();
        std::stringstream ss;
        ss << fd.rdbuf();
        fd.close();
        string linija;
        std::getline(ss, linija);
        while (std::getline(ss, linija)){
            std::istringstream iss(linija);
            iss >> laikinas.vardas >> laikinas.pavarde;
            int pazymys;
            while (iss >> pazymys){
                laikinas.pazymiai.push_back(pazymys);
            }
            laikinas.egzaminas=laikinas.pazymiai.back();
            laikinas.pazymiai.pop_back();
            laikinas.galutinis_vid=vidurkis(laikinas.pazymiai, laikinas.egzaminas);
            laikinas.galutinis_med=mediana(laikinas.pazymiai, laikinas.egzaminas);
            studentai.push_back(laikinas);
            laikinas.pazymiai.clear();
        }
        auto pabaiga=std::chrono::high_resolution_clock::now();
        laiku_suma+=pabaiga-pradzia;
        studentai.clear();
        laikinas.vardas.clear();
    }
    cout<<"Skaitymo is failo laikas: "<<laiku_suma.count()/5<<" s\n";
}

void testavimas(Stud &laikinas, vector<Stud> &studentai){
    string failas;
    string tekstas="1 - kursiokai.txt\n2 - studentai10000.txt\n3 - studentai100000.txt\n4 - studentai1000000.txt\nPasirinkite faila testavimui: ";
    int pasirinkimas=skaiciu_ivesties_tikrinimas(tekstas);
    while (pasirinkimas<1 || pasirinkimas>4){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        pasirinkimas=skaiciu_ivesties_tikrinimas(tekstas);
    }
    switch(pasirinkimas){
        case 1:
            failas="kursiokai.txt";
            testinis_skaitymas_is_failo(laikinas, studentai, failas);
            break;
        case 2:
            failas="studentai10000.txt";
            testinis_skaitymas_is_failo(laikinas, studentai, failas);
            break;
        case 3:
            failas="studentai100000.txt";
            testinis_skaitymas_is_failo(laikinas, studentai, failas);
            break;
        case 4:
            failas="studentai1000000.txt";
            testinis_skaitymas_is_failo(laikinas, studentai, failas);
            break;
        default:
            cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
            return;
    }
}
