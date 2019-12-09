//Autorzy:
//Aleksandra Brela
//Michał Sułek

#include "Test.h"

void wypiszTablice(const TablicaOdleglosci& tablicaOdleglosci) {
    for(const auto& wiersz: tablicaOdleglosci.odleglosci) {
        for(const auto& komorka: wiersz) {
            std::cout << komorka << " ";
        }
        std::cout << std::endl;
    }
    for(int i = 0; i < tablicaOdleglosci.nazwyMiast.size(); ++i) {
        std::cout << i << " " << tablicaOdleglosci.nazwyMiast.at(i) << std::endl;
    }
}

void wypiszWektorU(const std::vector<unsigned>& wektor) {
    for(const auto& i: wektor) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void wypiszPopulacje(const Populacja& populacja) {
    for(int i = 0; i < populacja.wielkosc(); ++i) {
        std::cout << i << " ocena:" << populacja.ocenaOsobnika(i) << " genotyp: ";
        wypiszWektorU(populacja.osobnik(i).zwrocGenotyp());
    }
}