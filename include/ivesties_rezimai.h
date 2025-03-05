#ifndef IVESTIES_REZIMAI_H
#define IVESTIES_REZIMAI_H

#include "headers_vector.h"

void ranka (Stud &laikinas, vector<Stud> &studentai);
void pazymiu_generavimas (Stud &laikinas, vector<Stud> &studentai);
void visko_generavimas (Stud &laikinas, vector<Stud> &studentai);
void skaitymas_is_failo (Stud &laikinas, vector<Stud> &studentai, string failas, bool testavimas);
void failu_generavimas(int n);
void studentu_skaitymas_ir_skirstymas_i_vargsiukus_ir_galvocius (Stud &laikinas, vector<Stud> &studentai, string failas);

#endif