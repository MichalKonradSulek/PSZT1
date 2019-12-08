//
// Created by michalsulek on 07.12.2019.
//

#include <fstream>
#include "ObslugaPlikow.h"

TablicaOdleglosci::TablicaOdleglosci(size_t wielkosc):
    odleglosci(wielkosc, std::vector<WynikFunkcjiOceny>(wielkosc)),
    nazwyMiast(wielkosc) {

}

void TablicaOdleglosci::dodajMiasto(const std::string &nazwaMiasta) {
    odleglosci.emplace_back(std::vector<WynikFunkcjiOceny>(odleglosci.size()));
    for(auto& wiersz: odleglosci) {
        wiersz.emplace_back(WynikFunkcjiOceny());
    }
    nazwyMiast.push_back(nazwaMiasta);
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
}