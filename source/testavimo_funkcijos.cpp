#include "../include/testavimo_funkcijos.h"
#include "../include/ivesties_tikrinimas.h"
#include "../include/skaiciavimo_funkcijos.h"
#include "../include/ivesties_rezimai.h"

template <typename Container>
void testinis_skaitymas_is_failo (Stud &laikinas, Container &studentai, string failas){
    std::chrono::duration<double> laiku_suma{0};
    for (int i=0; i<5; i++){
        std::ifstream fd(failas);
        if (fd.fail()){
            throw std::runtime_error("Failas nerastas.");
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
template void testinis_skaitymas_is_failo<vector<Stud>>(Stud &laikinas, vector<Stud> &studentai, string failas);
template void testinis_skaitymas_is_failo<list<Stud>>(Stud &laikinas, list<Stud> &studentai, string failas);
template void testinis_skaitymas_is_failo<deque<Stud>>(Stud &laikinas, deque<Stud> &studentai, string failas);

template <typename Container>
void testavimas(Stud &laikinas, Container &studentai){
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
    catch (std::runtime_error klaida){
        std::cerr<<klaida.what()<<endl;
        testavimas(laikinas, studentai);
    }
}
template void testavimas<vector<Stud>>(Stud &laikinas, vector<Stud> &studentai);
template void testavimas<list<Stud>>(Stud &laikinas, list<Stud> &studentai);
template void testavimas<deque<Stud>>(Stud &laikinas, deque<Stud> &studentai);

void failo_kurimo_testavimas (){
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

void duomenu_apdorojimo_testavimas (){
    std::chrono::duration<double> ivesties_suma{0}, rusiavimo_suma{0}, skirstymo_suma{0};
    /*string tekstas="Iveskite faila is kurio norite skirstyti: ";
    string failas;
    ivesties_tikrinimas(failas, tekstas);
    cout<<"Dabar rinkites vagsiuku rikiavimo buda:\n";
    */
    vector<string> failai = {"studentai1000.txt", "studentai10000.txt", "studentai100000.txt", "studentai1000000.txt", "studentai10000000.txt"};
    int strategija=0;
    string tekstas="Pasirinkite strategija (1, 2, 3): ";
    ivesties_tikrinimas(strategija, tekstas);
    while (strategija<1 || strategija>3){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        ivesties_tikrinimas(strategija, tekstas);
    }
    /*string tekstas="1 - Rikiuoti pagal varda\n2 - Rikiuoti pagal pavarde\n3 - Rikiuoti pagal galutini pazymi is vidurkio\n4 - Rikiuoti pagal galutini pazymi is medianos\n5 - Nerikiuoti\nPasirinkite rikiavimo buda: ";
    int pasirinkimas1;
    ivesties_tikrinimas(pasirinkimas1, tekstas);
    while (pasirinkimas1<1 || pasirinkimas1>5){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        ivesties_tikrinimas(pasirinkimas1, tekstas);
    }
    tekstas="1 - Rikiuoti didejancia tvarka\n2 - Rikiuoti mazejancia tvarka\nPasirinkite rikiavimo tvarka: ";
    int pasirinkimas2;
    ivesties_tikrinimas(pasirinkimas2, tekstas);
    while (pasirinkimas2<1 || pasirinkimas2>2){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        ivesties_tikrinimas(pasirinkimas2, tekstas);
    }
    cout<<"Dabar rinkites galvociu rikiavimo buda:\n";
    tekstas="1 - Rikiuoti pagal varda\n2 - Rikiuoti pagal pavarde\n3 - Rikiuoti pagal galutini pazymi is vidurkio\n4 - Rikiuoti pagal galutini pazymi is medianos\n5 - Nerikiuoti\nPasirinkite rikiavimo buda: ";
    int pasirinkimas3;
    ivesties_tikrinimas(pasirinkimas3, tekstas);
    while (pasirinkimas3<1 || pasirinkimas3>5){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        ivesties_tikrinimas(pasirinkimas3, tekstas);
    }
    tekstas="1 - Rikiuoti didejancia tvarka\n2 - Rikiuoti mazejancia tvarka\nPasirinkite rikiavimo tvarka: ";
    int pasirinkimas4;
    ivesties_tikrinimas(pasirinkimas4, tekstas);
    while (pasirinkimas4<1 || pasirinkimas4>2){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        ivesties_tikrinimas(pasirinkimas4, tekstas);
    }*/
    for (auto failas:failai){
        try {
            for (int i=0; i<5; i++){
                Stud laikinas;
                vector<Stud> studentai;
                studentu_skaitymas_ir_skirstymas_i_vargsiukus_ir_galvocius(laikinas, studentai, failas, ivesties_suma, rusiavimo_suma, skirstymo_suma, strategija/*, pasirinkimas1, pasirinkimas2, pasirinkimas3, pasirinkimas4*/);
            }
            cout<<"Failas: "<<failas<<endl;
            cout<<"Ivesties trukme: "<<ivesties_suma.count()/5<<" s\n";
            cout<<"Rusiavimo trukme: "<<rusiavimo_suma.count()/5<<" s\n";
            cout<<"Skirstymo trukme: "<<skirstymo_suma.count()/5<<" s\n";
            cout<<"Bendra trukme: "<<(ivesties_suma.count()+rusiavimo_suma.count()+skirstymo_suma.count())/5<<" s\n";
        }
        catch (std::runtime_error klaida){
            std::cerr<<klaida.what()<<endl;
            duomenu_apdorojimo_testavimas();
        }
    }
}


