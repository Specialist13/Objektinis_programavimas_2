#include "../include/ivesties_rezimai.h"
#include "../include/ivesties_tikrinimas.h"
#include "../include/skaiciavimo_funkcijos.h"
#include "../include/vartotojo_pasirinkimo_funkcijos.h"
#include "../include/isvesties_rezimai.h"
#include "../include/rikiavimo_funckija.h"

template <typename Container>
void ranka (Stud &laikinas, Container &studentai){
    string tekstas;
    cout<<"Veskite duomenis apie studentus. Kai noresite baigti, iveskite 'n' kaip studento varda.\n";
    while (laikinas.vardas!="n"){
        tekstas="Iveskite studento varda: ";
        ivesties_tikrinimas(laikinas.vardas, tekstas);

        if (laikinas.vardas=="n"){
            break;
        }

        tekstas="Iveskite studento pavarde: ";
        ivesties_tikrinimas(laikinas.pavarde, tekstas);

        cout<<"Veskite jo pazymius. Kai noresite baigti, iveskite '0'.\n";
        while (true){
            tekstas="Iveskite pazymi: ";
            int pazymys;
            ivesties_tikrinimas(pazymys, tekstas);

            if (pazymys==0){
                break;
            }
            else if (pazymys<0 || pazymys>10){
                cout<<"Neteisingas pazymys. Bandykite dar karta.\n";
                continue;
            }
            laikinas.pazymiai.push_back(pazymys);
        }

        tekstas="Iveskite studento egzamino pazymi: ";
        ivesties_tikrinimas(laikinas.egzaminas, tekstas);
        while (laikinas.egzaminas<0 || laikinas.egzaminas>10){
            cout<<"Neteisingas pazymys. Bandykite dar karta.\n";
            ivesties_tikrinimas(laikinas.egzaminas, tekstas);
        }

        laikinas.galutinis_vid=vidurkis(laikinas.pazymiai, laikinas.egzaminas);
        laikinas.galutinis_med=mediana(laikinas.pazymiai, laikinas.egzaminas);
        studentai.push_back(laikinas);
        laikinas.pazymiai.clear();
    }
    isvesties_pasirinkimas(studentai);
    studentai.clear();
    laikinas.vardas.clear();
}

template void ranka<vector<Stud>>(Stud&, vector<Stud>&);
template void ranka<list<Stud>>(Stud&, list<Stud>&);
template void ranka<deque<Stud>>(Stud&, deque<Stud>&);

template <typename Container>
void pazymiu_generavimas (Stud &laikinas, Container &studentai){
    srand(time(NULL));
    string tekstas;
    cout<<"Veskite duomenis apie studentus. Kai noresite baigti, iveskite 'n' kaip studento varda.\n";
    while (laikinas.vardas!="n"){
        tekstas="Iveskite studento varda: ";
        ivesties_tikrinimas(laikinas.vardas, tekstas);

        if (laikinas.vardas=="n"){
            break;
        }

        tekstas="Iveskite studento pavarde: ";
        ivesties_tikrinimas(laikinas.pavarde, tekstas);
        
        int n=rand()%10+1;
        for (int j=0; j<n; j++){
            int pazymys=rand()%10+1;
            laikinas.pazymiai.push_back(pazymys);
        }
        laikinas.egzaminas=rand()%10+1;
        laikinas.galutinis_vid=vidurkis(laikinas.pazymiai, laikinas.egzaminas);
        laikinas.galutinis_med=mediana(laikinas.pazymiai, laikinas.egzaminas);
        studentai.push_back(laikinas);
        laikinas.pazymiai.clear();
    }
    isvesties_pasirinkimas(studentai);
    studentai.clear();
    laikinas.vardas.clear();
}

template void pazymiu_generavimas<vector<Stud>>(Stud&, vector<Stud>&);
template void pazymiu_generavimas<list<Stud>>(Stud&, list<Stud>&);
template void pazymiu_generavimas<deque<Stud>>(Stud&, deque<Stud>&);

template <typename Container>
void visko_generavimas (Stud &laikinas, Container &studentai){
    srand(time(NULL));

    vector<string> vyriskiVardai = {
        "Jonas", "Petras", "Marius", "Tadas", "Rokas", "Darius", "Arnas", "Justas", "Edvinas", "Tomas",
        "Paulius", "Simas", "Lukas", "Andrius", "Rytis", "Ernestas", "Giedrius", "Mantas", "Deividas", "Vilius",
        "Mindaugas", "Martynas", "Saulius", "Vytautas", "Tautvydas", "Sigitas", "Algirdas", "Gintaras", "Julius", "Remigijus",
        "Kestas", "Vaidotas", "Audrius", "Augustas", "Nerijus", "Gediminas", "Raimundas", "Juozas", "Dainius", "Arvydas",
        "Evaldas", "Zygimantas", "Vytenis", "Laurynas", "Arminas", "Rolandas", "Alvydas", "Laimonas", "Dominykas", "Tautvilas"
    };
    
    vector<string> moteriskiVardai = {
        "Ona", "Ieva", "Lina", "Egle", "Asta", "Rima", "Greta", "Aiste", "Monika", "Laura",
        "Jurgita", "Dovile", "Karolina", "Viktorija", "Gabija", "Sandra", "Vaida", "Aurelija", "Kristina", "Evelina",
        "Ruta", "Egle", "Aiste", "Indre", "Diana", "Viktorija", "Marija", "Aldona", "Gintare", "Alina",
        "Birute", "Rita", "Raimonda", "Virginija", "Irena", "Jolanta", "Solveiga", "Vilma", "Lijana", "Agnė",
        "Saulė", "Nida", "Grazina", "Danutė", "Liuda", "Daiva", "Jadvyga", "Sigita", "Jonė", "Vaida"
    };
    
    vector<string> vyriskosPavardes = {
        "Kazlauskas", "Petrauskas", "Jankauskas", "Paulauskas", "Butkus", "Navickas", "Sabonis", "Rimkus", "Grigas", "Urbonas",
        "Brazinskas", "Šimkus", "Pocius", "Žukauskas", "Daukantas", "Blaževičius", "Stankūnas", "Grybauskas", "Vaičiulis", "Vaitkus",
        "Rutkauskas", "Tamulis", "Kudirka", "Bagdonas", "Pavardenis", "Morkūnas", "Noreika", "Dapkus", "Žilinskas", "Venckus",
        "Kairys", "Janušaitis", "Andriuškevičius", "Šimaitis", "Mockus", "Vaitkevičius", "Matulionis", "Aleknavičius", "Valančius", "Račkauskas",
        "Giedraitis", "Petkevičius", "Radzevičius", "Žiogas", "Kalvaitis", "Baranauskas", "Masiulis", "Gervė", "Balčiūnas", "Mačiulis"
    };
    
    vector<string> moteriskosPavardes = {
        "Kazlauskaitė", "Petrauskaitė", "Jankauskaitė", "Paulauskaitė", "Butkutė", "Navickaitė", "Sabonytė", "Rimkutė", "Grigaitė", "Urbonaitė",
        "Brazinskaitė", "Šimkutė", "Pociūtė", "Žukauskaitė", "Daukantaitė", "Blaževičiūtė", "Stankūnaitė", "Grybauskaitė", "Vaičiulienė", "Vaitkienė",
        "Rutkauskaitė", "Tamulytė", "Kudirkaitė", "Bagdonaitė", "Morkūnaitė", "Noreikaitė", "Dapkutė", "Žilinskaitė", "Venckutė", "Kairytė",
        "Janušaitė", "Andriuškevičiūtė", "Šimaitė", "Mockutė", "Vaitkevičiūtė", "Matulionytė", "Aleknavičiūtė", "Valančiūtė", "Račkauskaitė", "Giedraitė",
        "Petkevičiūtė", "Radzevičiūtė", "Žiogaitė", "Kalvaitė", "Baranauskaitė", "Masiulytė", "Balčiūnaitė", "Mačiulytė", "Gervaitė", "Daukšytė"
    };

    int k=rand()%10+1;
    for (int i=0; i<k; i++){
        int lytis=rand()%2, v=rand()%50, p=rand()%50;
        if (lytis==0){
            laikinas.vardas=vyriskiVardai[v];
            laikinas.pavarde=vyriskosPavardes[p];
        }
        else {
            laikinas.vardas=moteriskiVardai[v];
            laikinas.pavarde=moteriskosPavardes[p];
        }
        int n=rand()%10+1;
        for (int j=0; j<n; j++){
            int pazymys=rand()%10+1;
            laikinas.pazymiai.push_back(pazymys);
        }
        laikinas.egzaminas=rand()%10+1;
        laikinas.galutinis_vid=vidurkis(laikinas.pazymiai, laikinas.egzaminas);
        laikinas.galutinis_med=mediana(laikinas.pazymiai, laikinas.egzaminas);
        studentai.push_back(laikinas);
        laikinas.pazymiai.clear();
    }
    isvesties_pasirinkimas(studentai);
    studentai.clear();
    laikinas.vardas.clear();
}
template void visko_generavimas<vector<Stud>>(Stud&, vector<Stud>&);
template void visko_generavimas<list<Stud>>(Stud&, list<Stud>&);
template void visko_generavimas<deque<Stud>>(Stud&, deque<Stud>&);

template <typename Container>
void skaitymas_is_failo (Stud &laikinas, Container &studentai, string failas, bool testavimas){
    std::ifstream fd(failas);
    if (fd.fail()){
        throw std::runtime_error("Failas nerastas.");
    }
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
    if (!testavimas){
        isvesties_pasirinkimas(studentai);
        studentai.clear();
        laikinas.vardas.clear();
    }    
}
template void skaitymas_is_failo<vector<Stud>>(Stud&, vector<Stud>&, string, bool);
template void skaitymas_is_failo<list<Stud>>(Stud&, list<Stud>&, string, bool);
template void skaitymas_is_failo<deque<Stud>>(Stud&, deque<Stud>&, string, bool);

void failu_generavimas(int n){
    string filename = "studentai" + std::to_string(n) + ".txt";
    std::ofstream fd(filename);

    if (!fd) {
        cout << "Nepavyko sukurti failo.\n";
        return;
    }

    fd<<std::left<< std::setw(15) <<"Vardas"<< std::setw(15) <<"Pavarde"<< std::setw(15) <<"ND1"<<std::setw(15) <<"ND2"<<std::setw(15) <<"ND3"<<std::setw(15) <<"ND4"<< std::setw(15) <<std::setw(15) <<"ND5"<<std::setw(15) <<"Egzaminas\n";

    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        Stud laikinas;
        laikinas.vardas = "Vardas" + std::to_string(i + 1);
        laikinas.pavarde = "Pavarde" + std::to_string(i + 1);
        int pazymiu_kiekis = 5;
        for (int j = 0; j < pazymiu_kiekis; ++j) {
            laikinas.pazymiai.push_back(rand() % 10 + 1);
        }
        laikinas.egzaminas = rand() % 10 + 1;
        laikinas.galutinis_vid = vidurkis(laikinas.pazymiai, laikinas.egzaminas);
        laikinas.galutinis_med = mediana(laikinas.pazymiai, laikinas.egzaminas);

        fd <<std::left<< std::setw(15) << laikinas.vardas << std::setw(15)  << laikinas.pavarde;
        for (int pazymys : laikinas.pazymiai) {
            fd <<std::left<< std::setw(15) << pazymys << " ";
        }
        fd <<std::left<< std::setw(15) << laikinas.egzaminas << "\n";
    }

    fd.close();
    cout << "Failas sukurtas: " << filename << "\n";
}

template <typename Container>
void studentu_skaitymas_ir_skirstymas_i_vargsiukus_ir_galvocius (Stud &laikinas, Container &studentai, string failas, std::chrono::duration<double>  &ivesties_suma, std::chrono::duration<double>  &rusiavimo_suma, std::chrono::duration<double>  &skirstymo_suma/*, int pasirinkimas1, int pasirinkimas2, int pasirinkimas3, int pasirinkimas4*/){
    auto ivesties_pradzia=std::chrono::high_resolution_clock::now();
    skaitymas_is_failo(laikinas, studentai, failas, true);
    auto ivesties_pabaiga=std::chrono::high_resolution_clock::now();
    ivesties_suma+=ivesties_pabaiga-ivesties_pradzia;
    auto rusiavimo_pradzia=std::chrono::high_resolution_clock::now();
    
    if constexpr (std::is_same_v<Container, std::list<Stud>>){
        studentai.sort(raktas_gv);
    }
    else {
        std::sort(studentai.begin(), studentai.end(), raktas_gv);
    }
    
    /*if (pasirinkimas1==5){
        return;
    }

    if constexpr (std::is_same_v<Container, std::list<Stud>>){
        switch (pasirinkimas1){
            case 1:
                vargsiukai.sort(raktas_v);
                break;
            case 2:
                vargsiukai.sort(raktas_p);
                break;
            case 3:
                vargsiukai.sort(raktas_gv);
                break;
            case 4:
                vargsiukai.sort(raktas_gm);
                break;
            case 5:
                break;
            default:
                cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
                return;
        }
    }
    else {
        switch (pasirinkimas1){
            case 1:
                std::sort(vargsiukai.begin(), vargsiukai.end(), raktas_v);
                break;
            case 2:
                std::sort(vargsiukai.begin(), vargsiukai.end(), raktas_p);
                break;
            case 3:
                std::sort(vargsiukai.begin(), vargsiukai.end(), raktas_gv);
                break;
            case 4:
                std::sort(vargsiukai.begin(), vargsiukai.end(), raktas_gm);
                break;
            case 5:
                break;
            default:
                cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
                return;
        }
    }
    
    if (pasirinkimas2==2){
        if constexpr (std::is_same_v<Container, std::list<Stud>>){
            studentai.reverse();
        }
        else {
            std::reverse(vargsiukai.begin(), vargsiukai.end());
        }
    }


    if (pasirinkimas3==5){
        return;
    }


    if constexpr (std::is_same_v<Container, std::list<Stud>>){
        switch (pasirinkimas3){
            case 1:
                galvociai.sort(raktas_v);
                break;
            case 2:
                galvociai.sort(raktas_p);
                break;
            case 3:
                galvociai.sort(raktas_gv);
                break;
            case 4:
                galvociai.sort(raktas_gm);
                break;
            case 5:
                break;
            default:
                cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
                return;
        }
    }
    else {
        switch (pasirinkimas3){
            case 1:
                std::sort(galvociai.begin(), galvociai.end(), raktas_v);
                break;
            case 2:
                std::sort(galvociai.begin(), galvociai.end(), raktas_p);
                break;
            case 3:
                std::sort(galvociai.begin(), galvociai.end(), raktas_gv);
                break;
            case 4:
                std::sort(galvociai.begin(), galvociai.end(), raktas_gm);
                break;
            case 5:
                break;
            default:
                cout<<"Neteisingas pasirinkimas. Bandykite dar karta.\n";
                return;
        }
    }
    
    if (pasirinkimas4==2){
        if constexpr (std::is_same_v<Container, std::list<Stud>>){
            galvociai.reverse();
        }
        else {
            std::reverse(galvociai.begin(), galvociai.end());
        }
    }*/

    auto rusiavimo_pabaiga=std::chrono::high_resolution_clock::now();
    rusiavimo_suma+=rusiavimo_pabaiga-rusiavimo_pradzia;
    auto skirstymo_pradzia=std::chrono::high_resolution_clock::now();
    Container vargsiukai, galvociai;
    for (Stud &studentas : studentai){
        if (studentas.galutinis_vid<5){
            vargsiukai.push_back(studentas);
        }
        else {
            galvociai.push_back(studentas);
        }
    }
    
    
    if constexpr (std::is_same_v<Container, std::vector<Stud>>){
        vargsiukai.shrink_to_fit();
        galvociai.shrink_to_fit();
    }
    
    
    auto skirstymo_pabaiga=std::chrono::high_resolution_clock::now();
    isvestis_i_faila(vargsiukai, "vargsiukai.txt");
    isvestis_i_faila(galvociai, "galvociai.txt");
    skirstymo_suma+=skirstymo_pabaiga-skirstymo_pradzia;
    vargsiukai.clear();
    galvociai.clear();
    studentai.clear();
}
template void studentu_skaitymas_ir_skirstymas_i_vargsiukus_ir_galvocius<vector<Stud>>(Stud&, vector<Stud>&, string, std::chrono::duration<double>&, std::chrono::duration<double>&, std::chrono::duration<double>&/*, int, int, int, int*/);
template void studentu_skaitymas_ir_skirstymas_i_vargsiukus_ir_galvocius<list<Stud>>(Stud&, list<Stud>&, string, std::chrono::duration<double>&, std::chrono::duration<double>&, std::chrono::duration<double>&/*, int, int, int, int*/);
template void studentu_skaitymas_ir_skirstymas_i_vargsiukus_ir_galvocius<deque<Stud>>(Stud&, deque<Stud>&, string, std::chrono::duration<double>&, std::chrono::duration<double>&, std::chrono::duration<double>&/*, int, int, int, int*/);