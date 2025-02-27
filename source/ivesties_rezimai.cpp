#include "../include/ivesties_rezimai.h"
#include "../include/ivesties_tikrinimas.h"
#include "../include/skaiciavimo_funkcijos.h"
#include "../include/vartotojo_pasirinkimo_funkcijos.h"

void ranka (Stud &laikinas, vector<Stud> &studentai){
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

void pazymiu_generavimas (Stud &laikinas, vector<Stud> &studentai){
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

void visko_generavimas (Stud &laikinas, vector<Stud> &studentai){
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

void skaitymas_is_failo (Stud &laikinas, vector<Stud> &studentai, string failas){
    std::ifstream fd(failas);
    if (fd.fail()){
        throw "Failas nerastas.";
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
    
    isvesties_pasirinkimas(studentai);
    studentai.clear();
    laikinas.vardas.clear();
}