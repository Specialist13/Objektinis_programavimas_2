#include "../include/vartotojo_pasirinkimo_funkcijos.h"
#include "../include/isvesties_rezimai.h"
#include "../include/ivesties_rezimai.h"
#include "../include/ivesties_tikrinimas.h"
#include "../include/rikiavimo_funckija.h"


void isvesties_pasirinkimas(vector<Stud> &studentai){
    rikiavimas(studentai);
    string tekstas="1 - Isvesti rezultatus i konsole\n2 - Isvesti rezultatus i faila\nPasirinkite isvedimo buda: ";
    int pasirinkimas=skaiciu_ivesties_tikrinimas(tekstas);
    while (pasirinkimas<1 || pasirinkimas>2){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        pasirinkimas=skaiciu_ivesties_tikrinimas(tekstas);
    }
    switch(pasirinkimas){
        case 1:
            isvestis_i_konsole(studentai);
            break;
        case 2:
            isvestis_i_faila(studentai);
            break;
        default:
            cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
            return;
    }
}

void failo_pasirinkimas(Stud &laikinas, vector<Stud> &studentai){
    string failai[] = {"kursiokai.txt", "studentai10000.txt", "studentai100000.txt", "studentai1000000.txt"};
    string tekstas="1 - kursiokai.txt\n2 - studentai10000.txt\n3 - studentai100000.txt\n4 - studentai1000000.txt\nPasirinkite faila: ";
    int pasirinkimas=skaiciu_ivesties_tikrinimas(tekstas);
    while (pasirinkimas<1 || pasirinkimas>4){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        pasirinkimas=skaiciu_ivesties_tikrinimas(tekstas);
    }
    try {
        skaitymas_is_failo(laikinas, studentai, failai[pasirinkimas-1]);
    }
    catch (const char* klaida){
        cout<<klaida<<endl;
        failo_pasirinkimas(laikinas, studentai);
    }
}
