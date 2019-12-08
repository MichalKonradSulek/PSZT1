//
// Created by michalsulek on 07.12.2019.
//

#include <iostream>
#include "WycieczkaObjazdowa.h"
#include "ObslugaPlikow.h"

WycieczkaObjazdowa::WycieczkaObjazdowa(): _tablicaOdleglosci(5) {

};

void WycieczkaObjazdowa::wczytajDane(const std::string &plik, int iloscRekordow) {
    ::wczytajDane(_tablicaOdleglosci, plik, iloscRekordow);
    if(iloscRekordow == 0) {
        std::cerr << "Tablica odleglosci pusta" << std::endl;
        return;
    }
    UstawieniaAlgoytmu ustawieniaAlgoytmu{_tablicaOdleglosci.wielkosc() - 1, WIELKOSC_POPULACJI};
    _algorytmEwolucyjny = std::make_unique<AlgorytmEwolucyjny>(_tablicaOdleglosci, ustawieniaAlgoytmu);
}

void WycieczkaObjazdowa::przeprowadzObliczenia() {
    wypiszTablice(_tablicaOdleglosci);
    Osobnik osobnik(4);
    wypiszWektorU(osobnik.zwrocGenotyp());
    wypiszWektorU(osobnik.zwrocFenotyp());
    std::cout << ocenOsobnika(_tablicaOdleglosci, osobnik.zwrocFenotyp()) << std::endl;
}
