#include "../include/isvesties_rezimai.h"

template <typename Container>
void isvestis_i_konsole (Container &studentai){
    cout << std::left<<std::setw(25) <<"Vardas"<<std::setw(25)<<"Pavarde"<<std::setw(25)<<"Galutinis (Vid.)"<<std::setw(25)<<"/ Galutinis (Med.)"<<"\n"<<string(100, '-')<<"\n";
    for (auto &x:studentai){
        cout << std::left<<std::setw(25)<< x.vardas << std::setw(25)<< x.pavarde << std::setw(25)<< std::fixed << std::setprecision(2) <<x.galutinis_vid << std::setw(25)<<x.galutinis_med<< "\n";
    }
}

template void isvestis_i_konsole<vector<Stud>>(vector<Stud>&);
template void isvestis_i_konsole<list<Stud>>(list<Stud>&);
template void isvestis_i_konsole<deque<Stud>>(deque<Stud>&);


template <typename Container>
void isvestis_i_faila (Container &studentai, string failas){
    std::stringstream ss;
    std::ofstream fr(failas);
    ss << std::left<<std::setw(25) <<"Vardas"<<std::setw(25)<<"Pavarde"<<std::setw(25)<<"Galutinis (Vid.)"<<std::setw(25)<<"/ Galutinis (Med.)"<<"\n"<<string(100, '-')<<"\n";
    ss << std::fixed << std::setprecision(2);
    for (auto &x:studentai){
        ss << std::left<<std::setw(25)<< x.vardas << std::setw(25)<< x.pavarde << std::setw(25)<<x.galutinis_vid << std::setw(25)<<x.galutinis_med<< "\n";
    }
    fr << ss.str();
    fr.close();
}

template void isvestis_i_faila<vector<Stud>>(vector<Stud>&, string);
template void isvestis_i_faila<list<Stud>>(list<Stud>&, string);
template void isvestis_i_faila<deque<Stud>>(deque<Stud>&, string);