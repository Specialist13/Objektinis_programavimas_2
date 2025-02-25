#include "headers_vector.h"

double vidurkis(vector<int> &pazymiai, int &egzaminas){
    if (pazymiai.size() == 0) {
        return egzaminas*0.6;
    }
    double vid = 0;
    for (int i=0; i<pazymiai.size(); i++){
        vid += pazymiai[i];
    }
    vid = vid/pazymiai.size()*0.4 + egzaminas*0.6;
    return vid;
}

double mediana(vector<int> &pazymiai, int &egzaminas){
    if (pazymiai.size() == 0) {
        return egzaminas*0.6;
    }
    double med = 0;
    std::sort(pazymiai.begin(), pazymiai.end());
    if (pazymiai.size() % 2 == 0) {
        med = double((pazymiai[pazymiai.size()/2 - 1] + pazymiai[pazymiai.size()/2])) / 2.0;
    } else {
        med = pazymiai[pazymiai.size()/2];
    }
    
    med = med*0.4 + egzaminas*0.6;
    return med;
}

void isvestis_i_konsole (vector<Stud> &studentai){
    cout << std::left<<std::setw(25) <<"Vardas"<<std::setw(25)<<"Pavarde"<<std::setw(25)<<"Galutinis (Vid.)"<<std::setw(25)<<"/ Galutinis (Med.)"<<"\n"<<string(100, '-')<<"\n";
    for (auto &x:studentai){
        cout << std::left<<std::setw(25)<< x.vardas << std::setw(25)<< x.pavarde << std::setw(25)<< std::fixed << std::setprecision(2) <<x.galutinis_vid << std::setw(25)<<x.galutinis_med<< "\n";
    }
}

void isvestis_i_faila (vector<Stud> &studentai){
    std::stringstream ss;
    std::ofstream fr("rezultatai.txt");
    ss << std::left<<std::setw(25) <<"Vardas"<<std::setw(25)<<"Pavarde"<<std::setw(25)<<"Galutinis (Vid.)"<<std::setw(25)<<"/ Galutinis (Med.)"<<"\n"<<string(100, '-')<<"\n";
    ss << std::fixed << std::setprecision(2);
    for (auto &x:studentai){
        ss << std::left<<std::setw(25)<< x.vardas << std::setw(25)<< x.pavarde << std::setw(25)<<x.galutinis_vid << std::setw(25)<<x.galutinis_med<< "\n";
    }
    fr << ss.str();
    fr.close();
}

int skaiciu_ivesties_tikrinimas(string &tekstas) {
    int reiksme;
    while (true) {
        cout << tekstas;
        cin >> reiksme;
        if (cin.fail()) {
            cout << "Įveskite tinkamą skaičių!\n";
            cin.clear();
            cin.ignore();
        }
        else {
            cin.ignore();
            return reiksme;
        }
    }
}

void isvesties_pasirinkimas(vector<Stud> &studentai){
    string tekstas="1 - Išvesti rezultatus į konsolę\n2 - Išvesti rezultatus į failą\nPasirinkite išvedimo būdą: ";
    int pasirinkimas=skaiciu_ivesties_tikrinimas(tekstas);
    while (pasirinkimas<1 || pasirinkimas>2){
        cout<<"Neteisingas pasirinkimas. Bandykite dar kartą.\n";
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
            cout<<"Neteisingas pasirinkimas. Bandykite dar kartą.\n";
            return;
    }
}

void ranka (Stud &laikinas, vector<Stud> &studentai){
    string tekstas;
    cout<<"Veskite duomenis apie studentus. Kai norėsite baigti, įveskite 'n' kaip studento vardą.\n";
    while (laikinas.vardas!="n"){
        cout << "Įveskite studento vardą: ";
        cin >> laikinas.vardas;
        if (laikinas.vardas=="n"){
            break;
        }
        cout << "Įveskite studento pavardę: ";
        cin >> laikinas.pavarde;
        cout<<"Veskite jo pažymius. Kai norėsite baigti, įveskite '0'.\n";
        while (true){
            tekstas="Įveskite pažymį: ";
            int pazymys=skaiciu_ivesties_tikrinimas(tekstas);
            if (pazymys==0){
                break;
            }
            else if (pazymys<0 || pazymys>10){
                cout<<"Neteisingas pažymys. Bandykite dar kartą.\n";
                continue;
            }
            laikinas.pazymiai.push_back(pazymys);
        }
        tekstas="Įveskite studento egzamino pažymį: ";
        laikinas.egzaminas=skaiciu_ivesties_tikrinimas(tekstas);
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

    cout<<"Veskite duomenis apie studentus. Kai norėsite baigti, įveskite 'n' kaip studento vardą.\n";
    while (laikinas.vardas!="n"){
        cout << "Įveskite studento vardą: ";
        cin >> laikinas.vardas;
        if (laikinas.vardas=="n"){
            break;
        }
        cout << "Įveskite studento pavardę: ";
        cin >> laikinas.pavarde;
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
        cout<<"Failas nerastas.\n";
        return;
    }
    std::stringstream ss;
    ss << fd.rdbuf();
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
    fd.close();
    isvesties_pasirinkimas(studentai);
    studentai.clear();
    laikinas.vardas.clear();
}

void failo_pasirinkimas(Stud &laikinas, vector<Stud> &studentai){
    string failas;
    string tekstas="1 - kursiokai.txt\n2 - studentai10000.txt\n3 - studentai100000.txt\n4 - studentai1000000.txt\nPasirinkite failą: ";
    int pasirinkimas=skaiciu_ivesties_tikrinimas(tekstas);
    while (pasirinkimas<1 || pasirinkimas>4){
        cout<<"Neteisingas pasirinkimas. Bandykite dar kartą.\n";
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
            cout<<"Neteisingas pasirinkimas. Bandykite dar kartą.\n";
            return;
    }
}

int main(){
    Stud laikinas;
    vector<Stud> studentai;
    int rezimas=0;
    cout<<"Sveiki!\n";
    while (rezimas!=5){
        string tekstas="Pasirinkite programos režimą.\n1 - Duomenų įvedimas ranka\n2 - Pažymių generavimas\n3 - Pažymių ir vardų generavimas\n4 - Skaityti duomenis iš failo\n5 - Baigti darbą\nIveskite pasirinkimą: ";
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
                cout<<"Viso gero!\n";
                break;
            default:
                cout<<"Neteisingas pasirinkimas. Bandykite dar kartą.\n";
                break;
        }      
    }
    return 0;
}