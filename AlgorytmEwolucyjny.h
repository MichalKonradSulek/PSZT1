//
// Created by michalsulek on 07.12.2019.
//

#ifndef PSZT1_ALGORYTMEWOLUCYJNY_H
#define PSZT1_ALGORYTMEWOLUCYJNY_H

#include <iostream>
#include <random>
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
    std::default_random_engine _generator; ///<Generator liczb losowych
    UstawieniaAlgoytmu _ustawieniaAlgorytmu;
    TablicaOdleglosci _tablicaOdleglosci;
    Populacja _bierzacaPopulacja;
};

/** \class Reproduktor
 * Klasa odpowiedzialna za przeprowadzenie reprodukcji osobników populacji zgodnie z wprowadzonymi ustawieniami algorytmu.
 * Do krzyżowania wybrana jest metoda ruletki.
 */
class Reproduktor {
public:
    Reproduktor(const UstawieniaAlgoytmu& ustawieniaAlgoytmu, std::default_random_engine& generator);
    void reprodukuj(Populacja& populacja);
    Populacja zwrocPotomkow() const;
//private:
    std::default_random_engine& _generator;
    UstawieniaAlgoytmu _ustawieniaAlgorytmu;
    Populacja _nowaPopulacja;
    void wybierzOsobnikiDoReprodukcji(Populacja& populacja); ///<wybieranie osobników do populacji, korzystając z metody ruletkowej
    void krzyzujParami(); ///<jeśli nieparzysta liczba osobników, ostatni nie podlega krzyzowaniu
    void krzyzuj(Osobnik& osobnik1, Osobnik& osobnik2); ///<krzyżowanie osobników przy pomocy jednokrotnego cięcia genotypu
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
