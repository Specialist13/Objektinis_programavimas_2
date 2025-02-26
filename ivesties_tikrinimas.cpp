#include "ivesties_tikrinimas.h"

int skaiciu_ivesties_tikrinimas(string &tekstas) {
    int reiksme;
    while (true) {
        cout << tekstas;
        cin >> reiksme;
        if (cin.fail()) {
            cout << "Iveskite tinkama skaiciu!\n";
            cin.clear();
            cin.ignore();
        }
        else {
            cin.ignore();
            return reiksme;
        }
    }
}