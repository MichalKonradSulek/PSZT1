//
// Created by michalsulek on 03.12.2019.
//

#ifndef PSZT1_POPULACJA_H
#define PSZT1_POPULACJA_H

#include <vector>
#include <utility>
#include "TypyDanych.h"

class Osobnik {
public:
    explicit Osobnik(size_t size);
    explicit Osobnik(Genotyp genotyp);
    Genotyp zwrocGenotyp() const;
    Fenotyp zwrocFenotyp() const;
private:
    Genotyp _genotyp;


};

class GeneratorPopulacji;

class Populacja {
public:
    Populacja(size_t size, size_t iloscChromosomow);
    Osobnik osobnik(size_t number) const;
    size_t rozmiar() const;
private:
    std::vector<std::pair<WynikFunkcjiOceny, Osobnik>> _populacja;
};

class GeneratorPopulacji {
public:

};

#endif //PSZT1_POPULACJA_H
