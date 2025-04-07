#include "../include/vartotojo_pasirinkimo_funkcijos.h"
#include "../include/isvesties_rezimai.h"
#include "../include/ivesties_rezimai.h"
#include "../include/ivesties_tikrinimas.h"
#include "../include/rikiavimo_funckija.h"
#include "../include/testavimo_funkcijos.h"

void rezimo_pasirinkimas (vector<Stud> &studentai){
    int rezimas=0;
    Stud laikinas;
    string tekstas;
    while (rezimas!=8){
        tekstas="Pasirinkite programos rezima.\n1 - Duomenu ivedimas ranka\n2 - Pazymiu generavimas\n3 - Pazymiu ir vardu generavimas\n4 - Skaityti duomenis is failo\n5 - Testuoti ivesties laika\n6 - Kurti faila ir testuoti jo sukurimo laika\n7 - Skirstyti studentus is failo i vargsiukus ir galvocius\n8 - Baigti darba\nIveskite pasirinkima: ";
        ivesties_tikrinimas(rezimas, tekstas);
        switch(rezimas){
            case 1:
                ranka(studentai);
                break;
            case 2:
                pazymiu_generavimas(studentai);
                break;
            case 3:
                visko_generavimas(studentai);
                break;
            case 4:
                failo_pasirinkimas(studentai);
                break;
            case 5:
                testavimas(studentai);
                break;
            case 6:
                failo_kurimo_testavimas();
                break;
            case 7:
                duomenu_apdorojimo_testavimas();
                break;
            case 8:
                cout<<"Viso gero!\n";
                break;
            default:
                cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
                break;
        }      
    }
}

void isvesties_pasirinkimas(vector<Stud> &studentai){
    rikiavimas(studentai);
    string tekstas="1 - Isvesti rezultatus i konsole\n2 - Isvesti rezultatus i faila\nPasirinkite isvedimo buda: ";
    int pasirinkimas;
    ivesties_tikrinimas(pasirinkimas, tekstas);
    while (pasirinkimas<1 || pasirinkimas>2){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        ivesties_tikrinimas(pasirinkimas, tekstas);
    }
    std::ofstream fr;
    switch(pasirinkimas){
        case 1:
            isvestis(cout, studentai);
            break;
        case 2:
            fr.open("rezultatai.txt");
            isvestis(fr, studentai);
            fr.close();
            break;
        default:
            cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
            return;
    }
}

void failo_pasirinkimas(vector<Stud> &studentai){
    string failai[] = {"kursiokai.txt", "studentai10000.txt", "studentai100000.txt", "studentai1000000.txt"};
    string tekstas="1 - kursiokai.txt\n2 - studentai10000.txt\n3 - studentai100000.txt\n4 - studentai1000000.txt\nPasirinkite faila: ";
    int pasirinkimas;
    ivesties_tikrinimas(pasirinkimas, tekstas);
    while (pasirinkimas<1 || pasirinkimas>4){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        ivesties_tikrinimas(pasirinkimas, tekstas);
    }
    try {
        skaitymas_is_failo(studentai, failai[pasirinkimas-1], false);
    }
    catch (std::runtime_error klaida){
        std::cerr<<klaida.what()<<endl;
        failo_pasirinkimas(studentai);
    }
}
