#ifndef ISVESTIES_REZIMAI_H
#define ISVESTIES_REZIMAI_H

#include "headers_vector.h"

void isvestis_i_konsole (vector<Stud> &studentai);
void isvestis_i_faila (vector<Stud> &studentai);
void visko_generavimas (Stud &laikinas, vector<Stud> &studentai);
void skaitymas_is_failo (Stud &laikinas, vector<Stud> &studentai, string failas);
void failu_generavimas();

#endif