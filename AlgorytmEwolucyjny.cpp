//
// Created by michalsulek on 07.12.2019.
//

#include "AlgorytmEwolucyjny.h"

AlgorytmEwolucyjny::AlgorytmEwolucyjny(TablicaOdleglosci tablicaOdleglosci,
                                       UstawieniaAlgoytmu ustawieniaAlgoytmu):
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
