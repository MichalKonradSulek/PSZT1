//Autorzy:
//Aleksandra Brela
//Michał Sułek

#include <iostream>
#include <chrono>
#include <fstream>
#include "WycieczkaObjazdowa.h"
#include "ObslugaPlikow.h"

WycieczkaObjazdowa::WycieczkaObjazdowa(): _tablicaOdleglosci() {

};

void WycieczkaObjazdowa::wczytajDane(const std::string &plik, int iloscRekordow) {
    _tablicaOdleglosci = TablicaOdleglosci(iloscRekordow);
    ::wczytajDane(_tablicaOdleglosci, plik, iloscRekordow);
}

void WycieczkaObjazdowa::przeprowadzObliczenia() {
    if (_tablicaOdleglosci.wielkosc() == 0) return;

    UstawieniaAlgorytmu ustawieniaAlgorytmu1;
        ustawieniaAlgorytmu1.iloscChromosomow = _tablicaOdleglosci.wielkosc() - 1;
        ustawieniaAlgorytmu1.wielkoscPopulacji = 1000;
        ustawieniaAlgorytmu1.sortujPrzedKrzyzowaniem = false;
        ustawieniaAlgorytmu1.wielkoscPopulacjiDzieci = ustawieniaAlgorytmu1.wielkoscPopulacji;
        ustawieniaAlgorytmu1.prawdopodobienstwoMutacji = 100;
    AlgorytmEwolucyjny algorytm1(_tablicaOdleglosci, ustawieniaAlgorytmu1);

    for(int i = 0; i < 3000; ++i) {
        algorytm1.iteracja();
        std::cout << "Iteracja:" << i << " Ocena najlepszego:" << algorytm1.zwrocOceneNajlepszegoOsobnika() << " Najlepszy: ";
        wypiszWektorU(algorytm1.zwrocNajlepszegoOsobnika().zwrocFenotyp());
    }
    std::cout << "Najlepsza wycieczka:" << std::endl;
    for(const auto& i: algorytm1.zwrocNajlepszegoOsobnika().zwrocFenotyp()){
        std::cout << _tablicaOdleglosci.nazwyMiast.at(i) << " ";
    }
    std::cout << std::endl;
}
