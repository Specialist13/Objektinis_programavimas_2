#include "../include/headers_vector.h"
#include "../include/ivesties_rezimai.h"
#include "../include/ivesties_tikrinimas.h"
#include "../include/isvesties_rezimai.h"
#include "../include/testavimo_funkcijos.h"
#include "../include/vartotojo_pasirinkimo_funkcijos.h"

int main(){
    Stud laikinas;
    vector<Stud> studentai;
    int rezimas=0;
    cout<<"Sveiki!\n";
    while (rezimas!=7){
        string tekstas="Pasirinkite programos rezima.\n1 - Duomenu ivedimas ranka\n2 - Pazymiu generavimas\n3 - Pazymiu ir vardu generavimas\n4 - Skaityti duomenis is failo\n5 - Testuoti ivesties laika\n6 - Kurti faila ir testuoti jo sukurimo laika\n7 - Baigti darba\nIveskite pasirinkima: ";
        ivesties_tikrinimas(rezimas, tekstas);
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
                failo_kurimo_ir_duomenu_apdorojimo_testavimas();
            case 7:
                cout<<"Viso gero!\n";
                break;
            default:
                cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
                break;
        }      
    }
    return 0;
}