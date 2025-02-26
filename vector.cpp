#include "headers_vector.h"
#include "ivesties_rezimai.h"
#include "ivesties_tikrinimas.h"
#include "isvesties_rezimai.h"
#include "testavimo_funkcijos.h"
#include "vartotojo_pasirinkimo_funkcijos.h"

bool raktas_v(Stud a, Stud b){
    return a.vardas<b.vardas;
}
bool raktas_p(Stud a, Stud b){
    return a.pavarde<b.pavarde;
}
bool raktas_gv(Stud a, Stud b){
    return a.galutinis_vid<b.galutinis_vid;
}
bool raktas_gm(Stud a, Stud b){
    return a.galutinis_med<b.galutinis_med;
}
void rikiavimas (vector<Stud> &studentai){
    string tekstas="1 - Rikiuoti pagal varda\n2 - Rikiuoti pagal pavarde\n3 - Rikiuoti pagal galutini pazymi is vidurkio\n4 - Rikiuoti pagal galutini pazymi is medianos\n5 - Nerikiuoti\nPasirinkite rikiavimo buda: ";
    int pasirinkimas=skaiciu_ivesties_tikrinimas(tekstas);
    while (pasirinkimas<1 || pasirinkimas>5){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        pasirinkimas=skaiciu_ivesties_tikrinimas(tekstas);
    }
    switch (pasirinkimas){
        case 1:
            std::sort(studentai.begin(), studentai.end(), raktas_v);
            break;
        case 2:
            std::sort(studentai.begin(), studentai.end(), raktas_p);
            break;
        case 3:
            std::sort(studentai.begin(), studentai.end(), raktas_gv);
            break;
        case 4:
            std::sort(studentai.begin(), studentai.end(), raktas_gm);
            break;
        case 5:
            break;
        default:
            cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
            return;
    }
    if (pasirinkimas==5){
        return;
    }
    tekstas="1 - Rikiuoti didejancia tvarka\n2 - Rikiuoti mazejancia tvarka\nPasirinkite rikiavimo tvarka: ";
    pasirinkimas=skaiciu_ivesties_tikrinimas(tekstas);
    while (pasirinkimas<1 || pasirinkimas>2){
        cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        pasirinkimas=skaiciu_ivesties_tikrinimas(tekstas);
    }
    if (pasirinkimas==2){
        std::reverse(studentai.begin(), studentai.end());
    }
}


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