#ifndef TESTAVIMO_FUNKCIJOS_H
#define TESTAVIMO_FUNKCIJOS_H

#include "headers_main.h"

template <typename Container>
void testinis_skaitymas_is_failo (Stud &laikinas, Container &studentai, string failas);
template <typename Container>
void testavimas(Stud &laikinas, Container &studentai);
void failo_kurimo_testavimas ();
void duomenu_apdorojimo_testavimas();

#endif