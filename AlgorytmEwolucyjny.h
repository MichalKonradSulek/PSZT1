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

/** \class AlgorytmEwolucyjny
 * Klasa która realizuje działanie algorytmu ewolucyjnego. Konstruktor generuje populację początkową.
 * Klasa umożliwia przeprowadzenie pojedynczej iteracji, dzięki czemu można oglądać stan algorytmu w czasie jego działania.
 */
class AlgorytmEwolucyjny {
public:
    AlgorytmEwolucyjny(TablicaOdleglosci tablicaOdleglosci, UstawieniaAlgoytmu ustawieniaAlgoytmu);
    void iteracja(); ///<Pojedyncza iteracja (wymiana jednego pokolenia)
    void zwrocNajlepszegoOsobnika(Fenotyp) const;
private:
    UstawieniaAlgoytmu _ustawieniaAlgorytmu;
    TablicaOdleglosci _tablicaOdleglosci;
    Populacja _bierzacaPopulacja;
};

/** \class Reproduktor
 * Klasa odpowiedzialna za przeprowadzenie reprodukcji osobników populacji zgodnie z wprowadzonymi ustawieniami algorytmu.
 * Z tej klasy wywołać można tylko funkcję "reprodukuj".
 */
class Reproduktor {
public:
    void reprodukuj(Populacja& populacja, const UstawieniaAlgoytmu& ustawieniaAlgoytmu);
private:
    Populacja _nowaPopulacja;
    void wybierzOsobnikiDoReprodukcji(Populacja& populacja);

};

/** \class Mutator
 * Klasa ospowiedzialna za przeprowadzenie mutacji zgodnie z ustawieniami algorytmu
 * Z tej klasy wywołać można tylko funkcję "mutuj".
 */
class Mutator {
public:
    void mutuj(Populacja& populacja, const UstawieniaAlgoytmu& ustawieniaAlgoytmu);
};


#endif //PSZT1_ALGORYTMEWOLUCYJNY_H
