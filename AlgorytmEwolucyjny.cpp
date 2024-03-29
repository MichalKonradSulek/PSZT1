//Autorzy:
//Aleksandra Brela
//Michał Sułek

#include <chrono>
#include <random>
#include <algorithm>
#include "AlgorytmEwolucyjny.h"

AlgorytmEwolucyjny::AlgorytmEwolucyjny(TablicaOdleglosci tablicaOdleglosci,
                                       UstawieniaAlgorytmu ustawieniaAlgoytmu):
                                       _generator(std::chrono::system_clock::now().time_since_epoch().count()), //inicjalizacja generatora liczb losowych
                                       _ustawieniaAlgorytmu(ustawieniaAlgoytmu),
                                       _tablicaOdleglosci(std::move(tablicaOdleglosci)),
                                       _bierzacaPopulacja(ustawieniaAlgoytmu.wielkoscPopulacji, ustawieniaAlgoytmu.iloscChromosomow){
    for(int i = 0; i < _bierzacaPopulacja.wielkosc(); ++i) { //Wstępna ocena wszystkich osobników.
        _bierzacaPopulacja.ocenOsobnika(i, ocenOsobnika(_tablicaOdleglosci, _bierzacaPopulacja.osobnik(i).zwrocFenotyp()));
    }
    _bierzacaPopulacja.sortuj();
}

void AlgorytmEwolucyjny::iteracja() {
    Reproduktor reproduktor(_ustawieniaAlgorytmu, _generator);
    reproduktor.reprodukuj(_bierzacaPopulacja);
    Populacja potomkowie = reproduktor.zwrocPotomkow();
    Mutator mutator(_ustawieniaAlgorytmu, _generator);
    mutator.mutuj(potomkowie);
    for(int i = 0; i < potomkowie.wielkosc(); ++i) { //ocena wszystkich osobników nowej populacji
        potomkowie.ocenOsobnika(i, ocenOsobnika(_tablicaOdleglosci, potomkowie.osobnik(i).zwrocFenotyp()));
    }
    potomkowie.sortuj();
    _bierzacaPopulacja = potomkowie; //to przypisanie jest rozsądne tylko, gdy populacja potomków ma taką samą liczebność
}

Populacja AlgorytmEwolucyjny::zwrocBierzacaPopulacje() const {
    return _bierzacaPopulacja;
}

Osobnik AlgorytmEwolucyjny::zwrocNajlepszegoOsobnika() const {
    if(_bierzacaPopulacja.wielkosc() == 0) throw "AlgorytmEwolucyjny::zwrocNajlepszegoOsobnika - populacja pusta";
    return _bierzacaPopulacja.osobnik(0);
}

WynikFunkcjiOceny AlgorytmEwolucyjny::zwrocOceneNajlepszegoOsobnika() const {
    if(_bierzacaPopulacja.wielkosc() == 0) throw "AlgorytmEwolucyjny::zwrocOceneNajlepszegoOsobnika - populacja pusta";
    return _bierzacaPopulacja.ocenaOsobnika(0);
}

Reproduktor::Reproduktor(const UstawieniaAlgorytmu& ustawieniaAlgoytmu, std::default_random_engine& generator):
    _generator(generator),
    _ustawieniaAlgorytmu(ustawieniaAlgoytmu)
    {}

void Reproduktor::reprodukuj(const Populacja &populacja) {
    wybierzOsobnikiDoReprodukcji(populacja);
    if(_ustawieniaAlgorytmu.sortujPrzedKrzyzowaniem) _nowaPopulacja.sortuj();
    krzyzujParami();
}

Populacja Reproduktor::zwrocPotomkow() const{
    return _nowaPopulacja;
}

void Reproduktor::wybierzOsobnikiDoReprodukcji(const Populacja &populacja) {
    std::vector<double> wagiOsobnikowDoMetodyRuletkowej(populacja.wielkosc());
    double sumaWagMetodyRuletkowej = 0;
    for(int i = 0; i < populacja.wielkosc(); ++i) {
        if(populacja.ocenaOsobnika(i) == 0) throw "Reproduktor::wybierzOsobnikiDoReprodukcji - ocena = 0";
        wagiOsobnikowDoMetodyRuletkowej.at(i) = 1.0 / populacja.ocenaOsobnika(i);
        sumaWagMetodyRuletkowej += wagiOsobnikowDoMetodyRuletkowej.at(i);
    }
    std::uniform_real_distribution<double> distribution(0, sumaWagMetodyRuletkowej); //określanie zakresu generowanych liczb losowych
    for(int i = 0; i < _ustawieniaAlgorytmu.wielkoscPopulacjiDzieci; ++i) { //generowanie określonej liczby dzieci
        double wylosowanaLiczba = distribution(_generator);
        for(int j = 0; j < populacja.wielkosc(); ++j) { //sprawdzanie do której "przegródki" wpadła wylosowana liczba
            if(wylosowanaLiczba <= wagiOsobnikowDoMetodyRuletkowej.at(j)){
                _nowaPopulacja.dodajOsobnika(populacja.osobnik(j));
                break;
            }
            wylosowanaLiczba -= wagiOsobnikowDoMetodyRuletkowej.at(j);
        }
    }
    if(_nowaPopulacja.wielkosc() != _ustawieniaAlgorytmu.wielkoscPopulacjiDzieci) throw "Reproduktor::wybierzOsobnikiDoReprodukcji - zła liczba populacji dzieci";
}

void Reproduktor::krzyzujParami() {
    for(int i = 0; i < _nowaPopulacja.wielkosc() - 1; i+=2){ //-1 bo inaczej dla ostatniego elementu w populacji nieparzystej nie zadziała
        krzyzuj(_nowaPopulacja.osobnik(i), _nowaPopulacja.osobnik(i + 1));
    }
}

void Reproduktor::krzyzuj(Osobnik& osobnik1, Osobnik& osobnik2) {
    if(_ustawieniaAlgorytmu.iloscChromosomow < 2) return;
    std::uniform_int_distribution<size_t> distribution(1, _ustawieniaAlgorytmu.iloscChromosomow - 1); //określanie zakresu generowanych liczb losowych (cięcie musi być między chromosomami)
    size_t miejsceCiecia = distribution(_generator);
    Genotyp& genotypOsobnika1 = osobnik1.genotyp();
    Genotyp& genotypOsobnika2 = osobnik2.genotyp();
    std::swap_ranges(genotypOsobnika1.begin() + miejsceCiecia, genotypOsobnika1.end(), genotypOsobnika2.begin() + miejsceCiecia);
}

Mutator::Mutator(const UstawieniaAlgorytmu &ustawieniaAlgorytmu, std::default_random_engine &generator):
    _generator(generator),
    _ustawieniaAlgorytmu(ustawieniaAlgorytmu)
    {}

void Mutator::mutuj(Populacja &populacja) {
    std::uniform_int_distribution<unsigned> distribution(1, 1000); //określanie zakresu generowanych liczb losowych (1000, bo promile)
    for(int i = 0; i < populacja.wielkosc(); ++i) {
        if(distribution(_generator) <= _ustawieniaAlgorytmu.prawdopodobienstwoMutacji)
            mutujOsobnika(populacja.osobnik(i));
    }
}

void Mutator::mutujOsobnika(Osobnik &osobnik) {
    if(_ustawieniaAlgorytmu.iloscChromosomow < 1) throw "Mutator::mutujOsobnika - liczba chromosomow = 0";
    std::uniform_int_distribution<size_t> distribution(0, _ustawieniaAlgorytmu.iloscChromosomow - 1); //określanie zakresu generowanych liczb losowych
    size_t indeksMutowanegoChromosomu = distribution(_generator);
    std::uniform_int_distribution<Chromosom> dopuszczalneWartosciDanegoChromosomu(0, indeksMutowanegoChromosomu); //powinno być indeksMutowanegoChromosomu + 1, ale nie chcemy wylosować jeszcze raz takiej samej wartości
    Genotyp genotypOsobnika = osobnik.zwrocGenotyp();
    Chromosom nowaWartosc = dopuszczalneWartosciDanegoChromosomu(_generator);
    if(nowaWartosc >= genotypOsobnika.at(indeksMutowanegoChromosomu)) ++nowaWartosc; //zakres losowanych liczb był o 1 za mały; teraz, jeśli wylosowana liczba jest >= starej, dodajemy 1 by nie wylosować starej, ale też móc wylosować wartość maksymalną
    genotypOsobnika.at(indeksMutowanegoChromosomu) = nowaWartosc;
    osobnik = Osobnik(genotypOsobnika);
}
