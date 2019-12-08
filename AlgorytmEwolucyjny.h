//
// Created by michalsulek on 07.12.2019.
//

#ifndef PSZT1_ALGORYTMEWOLUCYJNY_H
#define PSZT1_ALGORYTMEWOLUCYJNY_H

#include <iostream>
#include "TypyDanych.h"
#include "ObslugaPlikow.h"
#include "Populacja.h"

/** \file AlgorytmEwolucjny.h
 * Plik zawierający główną klasy odpowiedzialne za podstawowe aspekty algorytmu ewolucynjego.
 */

class AlgorytmEwolucyjny {
public:
    AlgorytmEwolucyjny(TablicaOdleglosci tablicaOdleglosci, UstawieniaAlgoytmu ustawieniaAlgoytmu);
    void iteracja();
    void zwrocNajlepszegoOsobnika(Fenotyp) const;
private:
    UstawieniaAlgoytmu _ustawieniaAlgorytmu;
    TablicaOdleglosci _tablicaOdleglosci;
    Populacja _bierzacaPopulacja;
};

class Reproduktor {
public:
    void reprodukuj(Populacja& populacja, const UstawieniaAlgoytmu& ustawieniaAlgoytmu);
};

class Mutator {
public:
    void mutuj(Populacja& populacja, const UstawieniaAlgoytmu& ustawieniaAlgoytmu);
};


#endif //PSZT1_ALGORYTMEWOLUCYJNY_H
