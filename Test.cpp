//
// Created by michalsulek on 07.12.2019.
//
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