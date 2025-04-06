#include "../include/isvesties_rezimai.h"

void isvestis_i_konsole (vector<Stud> &studentai){
    cout << std::left<<std::setw(25) <<"Vardas"<<std::setw(25)<<"Pavarde"<<std::setw(25)<<"Galutinis (Vid.)"<<std::setw(25)<<"/ Galutinis (Med.)"<<"\n"<<string(100, '-')<<"\n";
    for (auto &x:studentai){
        cout << std::left<<std::setw(25)<< x.getVardas() << std::setw(25)<< x.getPavarde() << std::setw(25)<< std::fixed << std::setprecision(2) <<x.getGalutinisVid() << std::setw(25)<<x.getGalutinisMed()<< "\n";
    }
}


void isvestis_i_faila (vector<Stud> &studentai, string failas){
    std::stringstream ss;
    std::ofstream fr(failas);
    ss << std::left<<std::setw(25) <<"Vardas"<<std::setw(25)<<"Pavarde"<<std::setw(25)<<"Galutinis (Vid.)"<<std::setw(25)<<"/ Galutinis (Med.)"<<"\n"<<string(100, '-')<<"\n";
    ss << std::fixed << std::setprecision(2);
    for (auto &x:studentai){
        ss << std::left<<std::setw(25)<< x.getVardas() << std::setw(25)<< x.getPavarde() << std::setw(25)<<x.getGalutinisVid() << std::setw(25)<<x.getGalutinisMed()<< "\n";
    }
    fr << ss.str();
    fr.close();
}