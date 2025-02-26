#include "vartotojo_pasirinkimo_funkcijos.h"
#include "isvesties_rezimai.h"
#include "ivesties_rezimai.h"
#include "ivesties_tikrinimas.h"
#include "rikiavimo_funckija.h"


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
    string failas;
    string tekstas="1 - kursiokai.txt\n2 - studentai10000.txt\n3 - studentai100000.txt\n4 - studentai1000000.txt\nPasirinkite faila: ";
    int pasirinkimas=skaiciu_ivesties_tikrinimas(tekstas);
    while (pasirinkimas<1 || pasirinkimas>4){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        pasirinkimas=skaiciu_ivesties_tikrinimas(tekstas);
    }
    switch(pasirinkimas){
        case 1:
            failas="kursiokai.txt";
            skaitymas_is_failo(laikinas, studentai, failas);
            break;
        case 2:
            failas="studentai10000.txt";
            skaitymas_is_failo(laikinas, studentai, failas);
            break;
        case 3:
            failas="studentai100000.txt";
            skaitymas_is_failo(laikinas, studentai, failas);
            break;
        case 4:
            failas="studentai1000000.txt";
            skaitymas_is_failo(laikinas, studentai, failas);
            break;
        default:
            cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
            return;
    }
}
