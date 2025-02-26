#include "headers_vector.h"
#include "ivesties_rezimai.h"
#include "ivesties_tikrinimas.h"
#include "isvesties_rezimai.h"
#include "testavimo_funkcijos.h"
#include "vartotojo_pasirinkimo_funkcijos.h"

int main(){
    Stud laikinas;
    vector<Stud> studentai;
    int rezimas=0;
    cout<<"Sveiki!\n";
    while (rezimas!=6){
        string tekstas="Pasirinkite programos rezima.\n1 - Duomenu ivedimas ranka\n2 - Pazymiu generavimas\n3 - Pazymiu ir vardu generavimas\n4 - Skaityti duomenis is failo\n5 - Testuoti ivesties laika\n6 - Baigti darba\nIveskite pasirinkima: ";
        rezimas=skaiciu_ivesties_tikrinimas(tekstas);
        switch(rezimas){
            case 1:
                ranka(laikinas, studentai);
                break;
            case 2:
                pazymiu_generavimas(laikinas, studentai);
                break;
            case 3:
                visko_generavimas(laikinas, studentai);
                break;
            case 4:
                failo_pasirinkimas(laikinas, studentai);
                break;
            case 5:
                testavimas(laikinas, studentai);
                break;
            case 6:
                cout<<"Viso gero!\n";
                break;
            default:
                cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
                break;
        }      
    }
    return 0;
}