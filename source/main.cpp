#include "../include/headers_main.h"
#include "../include/ivesties_rezimai.h"
#include "../include/ivesties_tikrinimas.h"
#include "../include/isvesties_rezimai.h"
#include "../include/testavimo_funkcijos.h"
#include "../include/vartotojo_pasirinkimo_funkcijos.h"

int main(){
    cout<<"Sveiki!\n";
    int rezimas=0;
    Stud laikinas;
    cout<<"Pasirinkite konteineri. \n1 - Vector\n2 - List\n3 - Deque\n";
    int konteineris=0;
    string tekstas="Pasirinkite konteineri: ";
    while (konteineris!=1 && konteineris!=2 && konteineris!=3){
        ivesties_tikrinimas(konteineris, tekstas);
        if (konteineris!=1 && konteineris!=2 && konteineris!=3){
            cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
        }
    }
    if (konteineris==1){
        vector<Stud> studentai;
        rezimo_pasirinkimas(studentai);
    }
    else if (konteineris==2){
        list<Stud> studentai;
        rezimo_pasirinkimas(studentai);
    }
    else if (konteineris==3){
        deque<Stud> studentai;
        rezimo_pasirinkimas(studentai);
    }

    return 0;
}