#include "../include/isvesties_rezimai.h"

void isvestis (std::ostream &out, vector<Stud> &studentai){
    out << std::left<<std::setw(25) <<"Vardas"<<std::setw(25)<<"Pavarde"<<std::setw(25)<<"Galutinis (Vid.)"<<std::setw(25)<<"/ Galutinis (Med.)"<<"\n"<<string(100, '-')<<"\n";
    for (auto &x:studentai){
        out << std::left<<std::setw(25)<< x.getVardas() << std::setw(25)<< x.getPavarde() << std::setw(25)<< std::fixed << std::setprecision(2) <<x.getGalutinisVid() << std::setw(25)<<x.getGalutinisMed()<< "\n";
    }
}