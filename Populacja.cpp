//
// Created by michalsulek on 03.12.2019.
//

#include <random>
#include <chrono>
#include <algorithm>
#include "Populacja.h"
#include "ObslugaPlikow.h"


Osobnik::Osobnik(size_t iloscChromosomow) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //inicjator generatora liczb losowych
    std::default_random_engine generator(seed); //tworzenie generatora liczb losowych
    for(int i = 0; i < iloscChromosomow; ++i) {
        std::uniform_int_distribution<Chromosom> distribution(0, i + 1); //określanie zakresu generowanych liczb losowych
        _genotyp.push_back(distribution(generator));
    }
}

Osobnik::Osobnik(Genotyp genotyp): _genotyp(std::move(genotyp)){}

Genotyp Osobnik::zwrocGenotyp() const {
    return _genotyp;
}

Genotyp &Osobnik::genotyp() {
    return _genotyp;
}

Fenotyp Osobnik::zwrocFenotyp() const {
    Fenotyp fenotyp;
    stworzFenotyp(fenotyp);
    return fenotyp;
}

void Osobnik::stworzFenotyp(Fenotyp &fenotyp) const{
    fenotyp.clear();
    if(_genotyp.empty()) return;
    fenotyp.push_back(0); //zerowe miasto, które nie ma swojego chromosomu w genotypie
    for(int i = 0; i < _genotyp.size(); ++i) { //bierzemy kolejne chromosomy i odpowiadające im miasta umieszczamy na odpowiednich miejscach w fenotypie
        fenotyp.insert((fenotyp.begin() + _genotyp.at(i)), i + 1); //i+1, gdyż gen o indexie 0 opisuje miasto 1
    }
}

bool operator<(const Osobnik& osobnik1, const Osobnik& osobnik2){
    if(osobnik1.zwrocGenotyp().empty() || osobnik2.zwrocGenotyp().empty()) return true; //jeśli genotypy są puste, nie ma czego porównywać
    return osobnik1.zwrocGenotyp().at(0) < osobnik2.zwrocGenotyp().at(0);
}

WynikFunkcjiOceny ocenOsobnika(const TablicaOdleglosci& tablicaOdleglosci, const Fenotyp& fenotyp){
    if(fenotyp.size() <= 1) return 0;
    WynikFunkcjiOceny wynik = 0;
    for(int i = 0; i < fenotyp.size() - 1; ++i){ //-1, gdyż dla ostatniego miasta nie możemy sięgnąć po miasto i+1'sze
        wynik+=tablicaOdleglosci.odleglosci.at(fenotyp.at(i)).at(fenotyp.at(i + 1));
    }
    wynik+=tablicaOdleglosci.odleglosci.at(fenotyp.back()).at(fenotyp.front()); //brakujące połączenie - ostatnie miasto z zerowym
    return wynik;
}

Populacja::Populacja(size_t size, size_t iloscChromosomow): _populacja() {
    for(int i = 0; i < size; ++i){
        _populacja.emplace_back(std::pair<WynikFunkcjiOceny, Osobnik>(0, Osobnik(iloscChromosomow))); //generowanie losowych osobników
    }
}

Osobnik Populacja::osobnik(size_t numer) const {
    if(numer >= _populacja.size()) throw "Populacja::osobnik - zly numer";
    return _populacja[numer].second;
}

Osobnik& Populacja::osobnik(size_t numer) {
    if(numer >= _populacja.size()) throw "Populacja::osobnik - zly numer";
    return _populacja[numer].second;
}

WynikFunkcjiOceny Populacja::ocenaOsobnika(size_t numer) const{
    if(numer >= _populacja.size()) throw "Populacja::ocenaOsobnika - zly numer";
    return _populacja.at(numer).first;
}

size_t Populacja::wielkosc() const {
    return _populacja.size();
}

void Populacja::ocenOsobnika(size_t numer, WynikFunkcjiOceny ocena) {
    _populacja.at(numer).first = ocena;
}

void Populacja::sortuj() {
    std::sort(_populacja.begin(), _populacja.end());
}

void Populacja::dodajOsobnika(const Osobnik &osobnik, WynikFunkcjiOceny ocena) {
    _populacja.emplace_back(std::pair<WynikFunkcjiOceny, Osobnik>(ocena, osobnik));
}

void Populacja::doklejInnaPopulacje(const Populacja &innaPopulacja) {
    for(const auto& i: innaPopulacja._populacja) {
        _populacja.emplace_back(i);
    }
}

void Populacja::przytnijPopulacjeDoRozmiaru(size_t rozmiar) {
    while(_populacja.size() > rozmiar) {
        _populacja.pop_back();
    }
}



