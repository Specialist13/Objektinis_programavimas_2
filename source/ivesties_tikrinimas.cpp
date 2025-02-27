#include "../include/ivesties_tikrinimas.h"

int ivesties_tikrinimas(string &tekstas) {
    int reiksme;
    while (true) {
        cout << tekstas;
        cin >> reiksme;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            throw "Iveskite tinkama reiksme!\n";
        }
        else {
            cin.ignore();
            return reiksme;
        }
    }
}