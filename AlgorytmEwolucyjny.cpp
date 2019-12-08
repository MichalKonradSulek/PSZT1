//
// Created by michalsulek on 07.12.2019.
//

#include <chrono>
#include <random>
#include <algorithm>
#include "AlgorytmEwolucyjny.h"

AlgorytmEwolucyjny::AlgorytmEwolucyjny(TablicaOdleglosci tablicaOdleglosci,
                                       UstawieniaAlgoytmu ustawieniaAlgoytmu):
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
//    Reproduktor reproduktor(_bierzacaPopulacja, _ustawieniaAlgorytmu);
//    Mutator mutator(_bierzacaPopulacja, _ustawieniaAlgorytmu);
}

Reproduktor::Reproduktor(const UstawieniaAlgoytmu& ustawieniaAlgoytmu, std::default_random_engine& generator):
    _generator(generator),
    _ustawieniaAlgorytmu(ustawieniaAlgoytmu)
    {}

void Reproduktor::reprodukuj(Populacja &populacja) {
    wybierzOsobnikiDoReprodukcji(populacja);
    if(_ustawieniaAlgorytmu.sortujPrzedKrzyzowaniem) _nowaPopulacja.sortuj();
    krzyzujParami();
}

void Reproduktor::wybierzOsobnikiDoReprodukcji(Populacja &populacja) {

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
    std::cout << "miejsce ciecia: " << miejsceCiecia << std::endl;
    Genotyp& genotypOsobnika1 = osobnik1.genotyp();
    Genotyp& genotypOsobnika2 = osobnik2.genotyp();
    std::swap_ranges(genotypOsobnika1.begin() + miejsceCiecia, genotypOsobnika1.end(), genotypOsobnika2.begin() + miejsceCiecia);
}

void Reproduktor::scalPotomkowZRodzicami() {

}
