#include "headers_vector.h"
#include "ivesties_rezimai.cpp"
#include "ivesties_tikrinimas.cpp"
#include "isvesties_rezimai.cpp"

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