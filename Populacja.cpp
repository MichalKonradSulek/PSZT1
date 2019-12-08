//
// Created by michalsulek on 03.12.2019.
//

#include <random>
#include <chrono>
#include "Populacja.h"

/** \class Osobnik
 * Genotyp tworzony jest na podstawie kolejności występowania następnych miast.
 * Zerowe miasto nie ma swojego genu. Miasto pierwsze może mieć gen 0 lub 1. Oznaczać to będzie,
 * że występuje ono przed, albo po mieście zerowym. Drugie miasto może mieć analogicznie gen 0, 1 lub 2 itd.
 * @param size
 */
Osobnik::Osobnik(size_t size) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    for(int i = 0; i < size; ++i) {
        std::uniform_int_distribution<Gen> distribution(0, i + 1);
        _genotyp.push_back(distribution(generator));
    }
}

Osobnik::Osobnik(Genotyp genotyp): _genotyp(std::move(genotyp)){}

Genotyp Osobnik::zwrocGenotyp() const {
    return _genotyp;
}

Fenotyp Osobnik::zwrocFenotyp() const {
    Fenotyp wynik;
    if(_genotyp.empty()) return wynik;
    wynik.push_back(0); //zerowe miasto
    for(int i = 0; i < _genotyp.size(); ++i) {
        wynik.insert((wynik.begin() + _genotyp.at(i)), i + 1); //i+1, gdyż gen o indexie 0 opisuje miasto 1
    }
    return wynik;
}

Populacja::Populacja(size_t size, size_t iloscChromosomow): _populacja(size, std::pair<WynikFunkcjiOceny, Osobnik>(0, Osobnik(iloscChromosomow))) {}

Osobnik Populacja::osobnik(size_t number) const {
    if(number >= _populacja.size()) throw "Populacja::getSpecimen - wrong number";
    return _populacja[number].second;
}

size_t Populacja::rozmiar() const {
    return _populacja.size();
}
