//
// Created by michalsulek on 03.12.2019.
//

#ifndef PSZT1_POPULACJA_H
#define PSZT1_POPULACJA_H

#include <vector>
#include <utility>
#include <random>
#include "TypyDanych.h"
#include "ObslugaPlikow.h"

/** \class Osobnik
 * Genotyp tworzony jest na podstawie kolejności występowania następnych miast.
 * Zerowe miasto nie ma swojego genu. Miasto pierwsze może mieć gen 0 lub 1. Oznaczać to będzie,
 * że występuje ono przed, albo po mieście zerowym. Drugie miasto może mieć analogicznie gen 0, 1 lub 2 itd.
 */
class Osobnik {
public:
    explicit Osobnik(size_t iloscChromosomow, std::default_random_engine& generator); ///<Tworzy losowego osobnika o zadanej liczbie chromosomów
    explicit Osobnik(Genotyp genotyp); ///<Tworzy osobnika o zadanym genotypie
    Genotyp zwrocGenotyp() const;
    Genotyp& genotyp();
    Fenotyp zwrocFenotyp() const;
private:
    Genotyp _genotyp;

    void stworzFenotyp(Fenotyp& fenotyp) const;
};

bool operator<(const Osobnik& osobnik1, const Osobnik& osobnik2); ///<Operator stworzony, aby zaspokoić funkcję, która sortuje pary w populacji
WynikFunkcjiOceny ocenOsobnika(const TablicaOdleglosci& tablicaOdleglosci, const Fenotyp& fenotyp); ///<Funkcja przystosowania. Oceną jest suma odległości między miastami. Im mniej, tym lepiej.

/** \class Populacja
 * Klasa przechowująca populację osobników.
 */
class Populacja {
public:
    explicit Populacja() = default; ///<generacja pustej populacji
    Populacja(size_t size, size_t iloscChromosomow); ///<generacja populacji losowych osobników
    Osobnik osobnik(size_t numer) const;
    Osobnik& osobnik(size_t numer);
    WynikFunkcjiOceny ocenaOsobnika(size_t numer) const;
    size_t wielkosc() const;
    void ocenOsobnika(size_t numer, WynikFunkcjiOceny ocena);
    void sortuj(); ///< funkcja sortująca populację rosnąco względem wyniku funkcji oceny
    void dodajOsobnika(const Osobnik& osobnik, WynikFunkcjiOceny ocena = 0); ///<dodaje osobnika na końcu populacji
    void doklejInnaPopulacje(const Populacja& innaPopulacja); ///<dokleja inną populację na końcu obecnej
    void przytnijPopulacjeDoRozmiaru(size_t rozmiar); ///<usuwa z końca populacji tak długo, aż populacja będzie miała żądany rozmiar
private:
    std::vector<std::pair<WynikFunkcjiOceny, Osobnik>> _populacja;
};


#endif //PSZT1_POPULACJA_H
