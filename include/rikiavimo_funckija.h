#ifndef RIKIAVIMO_FUNKCIJA_H
#define RIKIAVIMO_FUNKCIJA_H

#include "headers_main.h"

bool raktas_v(Stud a, Stud b);
bool raktas_p(Stud a, Stud b);
bool raktas_gv(Stud a, Stud b);
bool raktas_gm(Stud a, Stud b);

template <typename Container>
void rikiavimas (Container &studentai);

#endif