//Autorzy:
//Aleksandra Brela
//Michał Sułek

#include <fstream>
#include "ObslugaPlikow.h"

TablicaOdleglosci::TablicaOdleglosci(size_t wielkosc):
    odleglosci(wielkosc, std::vector<WynikFunkcjiOceny>(wielkosc)),
    nazwyMiast(wielkosc) {

}

size_t TablicaOdleglosci::wielkosc() const {
    return nazwyMiast.size();
}

void wczytajDane(TablicaOdleglosci& tablicaOdleglosci, const std::string &plik, int iloscRekordow) {
    std::ifstream daneWejsciowe;
    daneWejsciowe.open(plik);
    if(!daneWejsciowe.good()) throw "Nie mozna otworzyc pliku";
    for(int i = 0; i < iloscRekordow; ++i) {
        std::string slowo;
        daneWejsciowe >> slowo;
        tablicaOdleglosci.nazwyMiast.at(i) = slowo;
        for(int j = 0; j < tablicaOdleglosci.wielkosc(); ++j) {
            daneWejsciowe >> tablicaOdleglosci.odleglosci.at(i).at(j);
        }
    }
    daneWejsciowe.close();
}