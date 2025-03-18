#ifndef IVESTIES_REZIMAI_H
#define IVESTIES_REZIMAI_H

#include "headers_main.h"

template <typename Container>
void ranka (Stud &laikinas, Container &studentai);
template <typename Container>
void pazymiu_generavimas (Stud &laikinas, Container &studentai);
template <typename Container>
void visko_generavimas (Stud &laikinas, Container &studentai);
template <typename Container>
void skaitymas_is_failo (Stud &laikinas, Container &studentai, string failas, bool testavimas);
void failu_generavimas(int n);
template <typename Container>
void studentu_skaitymas_ir_skirstymas_i_vargsiukus_ir_galvocius (Stud &laikinas, Container &studentai, string failas, std::chrono::duration<double>  &ivesties_suma, std::chrono::duration<double>  &rusiavimo_suma, std::chrono::duration<double> &isvedimo_suma, int pasirinkimas1, int pasirinkimas2, int pasirinkimas3, int pasirinkimas4);

#endif