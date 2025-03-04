#include "../include/testavimo_funkcijos.h"
#include "../include/ivesties_tikrinimas.h"
#include "../include/skaiciavimo_funkcijos.h"
#include "../include/ivesties_rezimai.h"

void testinis_skaitymas_is_failo (Stud &laikinas, vector<Stud> &studentai, string failas){
    std::chrono::duration<double> laiku_suma{0};
    for (int i=0; i<5; i++){
        std::ifstream fd(failas);
        if (fd.fail()){
            throw "Failas nerastas.";
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
    string failai[] = {"kursiokai.txt", "studentai10000.txt", "studentai100000.txt", "studentai1000000.txt"};
    string tekstas="1 - kursiokai.txt\n2 - studentai10000.txt\n3 - studentai100000.txt\n4 - studentai1000000.txt\nPasirinkite faila testavimui: ";
    int pasirinkimas;
    ivesties_tikrinimas(pasirinkimas, tekstas);

    while (pasirinkimas<1 || pasirinkimas>4){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        ivesties_tikrinimas(pasirinkimas, tekstas);
    }
    try {
        testinis_skaitymas_is_failo(laikinas, studentai, failai[pasirinkimas-1]);
    }
    catch (const char* klaida){
        cout<<klaida<<endl;
        testavimas(laikinas, studentai);
    }
}

void failo_kurimo_ir_duomenu_apdorojimo_testavimas (){
    std::chrono::duration<double> laiku_suma{0};
    string tekstas="Iveskite, kiek studentu norite sugeneruoti: ";
    int n;
    ivesties_tikrinimas(n, tekstas);
    while (n<1){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        ivesties_tikrinimas(n, tekstas);
    }
    for (int i=0; i<5; i++){
        auto pradzia=std::chrono::high_resolution_clock::now();
        failu_generavimas(n);
        auto pabaiga=std::chrono::high_resolution_clock::now();
        laiku_suma+=pabaiga-pradzia;
    }
    cout<<"Failo kurimo laikas: "<<laiku_suma.count()/5<<" s\n";
}
