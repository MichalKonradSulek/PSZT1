//
// Created by michalsulek on 03.12.2019.
//

#ifndef PSZT1_POPULACJA_H
#define PSZT1_POPULACJA_H

#include <vector>
#include <utility>
#include "TypyDanych.h"
#include "ObslugaPlikow.h"

/** \class Osobnik
 * Genotyp tworzony jest na podstawie kolejności występowania następnych miast.
 * Zerowe miasto nie ma swojego genu. Miasto pierwsze może mieć gen 0 lub 1. Oznaczać to będzie,
 * że występuje ono przed, albo po mieście zerowym. Drugie miasto może mieć analogicznie gen 0, 1 lub 2 itd.
 */
class Osobnik {
public:
    explicit Osobnik(size_t iloscChromosomow); ///<Tworzy losowego osobnika o zadanej liczbie chromosomów
    explicit Osobnik(Genotyp genotyp); ///<Tworzy osobnika o zadanym genotypie
    Genotyp zwrocGenotyp() const;
    Fenotyp zwrocFenotyp() const;
private:
    Genotyp _genotyp;

    void stworzFenotyp(Fenotyp& fenotyp) const;
};

bool operator<(const Osobnik& osobnik1, const Osobnik& osobnik2); ///<Operator stworzony, aby zaspokoić funkcję, która sortuje pary w populacji
wynikFunkcjiOceny ocenOsobnika(const TablicaOdleglosci& tablicaOdleglosci, const Fenotyp& fenotyp); ///<Funkcja przystosowania. Oceną jest suma odległości między miastami. Im mniej, tym lepiej.

/** \class Populacja
 * Klasa przechowująca populację osobników.
 */
class Populacja {
public:
    explicit Populacja() = default;
    Populacja(size_t size, size_t iloscChromosomow);
    Osobnik osobnik(size_t number) const;
    size_t wielkosc() const;
    void ocenOsobnika(size_t numer, wynikFunkcjiOceny ocena);
    void sortuj(); ///< funkcja sortująca populację rosnąco względem wyniku funkcji oceny
private:
    std::vector<std::pair<wynikFunkcjiOceny, Osobnik>> _populacja;
};


#endif //PSZT1_POPULACJA_H
