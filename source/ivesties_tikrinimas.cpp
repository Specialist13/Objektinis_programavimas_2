#include "../include/ivesties_tikrinimas.h"

template <typename T>
void ivesties_tikrinimas(T &reiksme, string &tekstas) {
    while (true) {
        try {
            cout << tekstas;
            cin >> reiksme;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                throw "Iveskite tinkama reiksme!\n";
            }
        }
        catch (const char* klaida) {
            cout << klaida;
            cin.ignore();
        }
    }
}