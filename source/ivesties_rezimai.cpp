#include "../include/ivesties_rezimai.h"
#include "../include/ivesties_tikrinimas.h"
#include "../include/skaiciavimo_funkcijos.h"
#include "../include/vartotojo_pasirinkimo_funkcijos.h"
#include "../include/isvesties_rezimai.h"
#include "../include/rikiavimo_funckija.h"

void strategija_1(vector<Stud> &studentai, vector<Stud> &vargsiukai, vector<Stud> &galvociai){
    for (Stud &studentas : studentai){
        if (studentas.getGalutinisVid()<5){
            vargsiukai.push_back(studentas);
        }
        else {
            galvociai.push_back(studentas);
        }
    }
    
    vargsiukai.shrink_to_fit();
    galvociai.shrink_to_fit();
}

void ranka(vector<Stud> &studentai) {
    cout << "Veskite duomenis apie studentus. Kai noresite baigti, iveskite 'n' kaip studento varda.\n";
    
    while (true) {
        Stud laikinas(std::cin, "ranka");
        
        if (laikinas.getVardas() == "n") {
            break;
        }
        
        studentai.push_back(laikinas);
    }
    
    isvesties_pasirinkimas(studentai);
    studentai.clear();
}

void pazymiu_generavimas (vector<Stud> &studentai){
    cout<<"Veskite duomenis apie studentus. Kai noresite baigti, iveskite 'n' kaip studento varda.\n";
    while (true){
        Stud laikinas(std::cin, "pazymiu_generavimas");
        if (laikinas.getVardas() == "n"){
            break;
        }
        studentai.push_back(laikinas);
    }
    isvesties_pasirinkimas(studentai);
    studentai.clear();
}

void visko_generavimas (vector<Stud> &studentai){
    srand(time(NULL));
    int k=rand()%10+1;
    for (int i=0; i<k; i++){
        Stud laikinas(std::cin, "visko_generavimas");
        studentai.push_back(laikinas);
    }
    isvesties_pasirinkimas(studentai);
    studentai.clear();
}

void skaitymas_is_failo (Stud &laikinas, vector<Stud> &studentai, string failas, bool testavimas){
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

void studentu_skaitymas_ir_skirstymas_i_vargsiukus_ir_galvocius (Stud &laikinas, vector<Stud> &studentai, string failas, std::chrono::duration<double>  &ivesties_suma, std::chrono::duration<double>  &rusiavimo_suma, std::chrono::duration<double>  &skirstymo_suma, int strategija/*, int pasirinkimas1, int pasirinkimas2, int pasirinkimas3, int pasirinkimas4*/){
    auto ivesties_pradzia=std::chrono::high_resolution_clock::now();
    skaitymas_is_failo(laikinas, studentai, failas, true);
    auto ivesties_pabaiga=std::chrono::high_resolution_clock::now();
    ivesties_suma+=ivesties_pabaiga-ivesties_pradzia;
    auto rusiavimo_pradzia=std::chrono::high_resolution_clock::now();
    
    std::sort(studentai.begin(), studentai.end(), raktas_gv);
    
    auto rusiavimo_pabaiga=std::chrono::high_resolution_clock::now();
    rusiavimo_suma+=rusiavimo_pabaiga-rusiavimo_pradzia;
    auto skirstymo_pradzia=std::chrono::high_resolution_clock::now();
    vector<Stud> vargsiukai, galvociai;
    if (strategija==1){
        strategija_1(studentai, vargsiukai, galvociai);
    }
    else if (strategija==2){
        strategija_2(studentai, galvociai);
    }
    else if (strategija==3){
        strategija_3(studentai, vargsiukai, galvociai);
    }
    
    
    auto skirstymo_pabaiga=std::chrono::high_resolution_clock::now();
    if (strategija==1 || strategija==3){
        isvestis_i_faila(vargsiukai, "vargsiukai.txt");
        isvestis_i_faila(galvociai, "galvociai.txt");
    }
    else if (strategija==2){
        isvestis_i_faila(galvociai, "galvociai.txt");
        isvestis_i_faila(studentai, "vargsiukai.txt");
    }
    skirstymo_suma+=skirstymo_pabaiga-skirstymo_pradzia;
    vargsiukai.clear();
    galvociai.clear();
    studentai.clear();
}