//
// Created by michalsulek on 07.12.2019.
//

#include <iostream>
#include <chrono>
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
    /*Populacja populacja(10, 4);
    for(int i = 0; i < populacja.wielkosc(); ++i) {
        std::cout << "Osobnik " << i << ": " << ocenOsobnika(_tablicaOdleglosci, populacja.osobnik(i).zwrocFenotyp()) << std::endl;;
        wypiszWektorU(populacja.osobnik(i).zwrocFenotyp());
    }*/
    Osobnik osobnik1(Genotyp{1,2,3,4,5,6,7,8,9,10});
    Osobnik osobnik2(Genotyp{11,12,13,14,15,16,17,18,19,20});
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count()); //inicjalizacja generatora liczb losowych
            std::cout << "genotyp1: ";
    wypiszWektorU(osobnik1.zwrocGenotyp());
    std::cout << "genotyp2: ";
    wypiszWektorU(osobnik2.zwrocGenotyp());
    for(int i = 0; i < 10; ++i) {
        std::cout << "krzyzowanie" << std::endl;
        Reproduktor(UstawieniaAlgoytmu{10, 1, false}, generator).krzyzuj(osobnik1, osobnik2);
        std::cout << "genotyp1: ";
        wypiszWektorU(osobnik1.zwrocGenotyp());
        std::cout << "genotyp2: ";
        wypiszWektorU(osobnik2.zwrocGenotyp());
    }
}
