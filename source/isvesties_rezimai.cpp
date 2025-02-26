#include "../include/isvesties_rezimai.h"

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
