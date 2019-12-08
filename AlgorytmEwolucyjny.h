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
    AlgorytmEwolucyjny(TablicaOdleglosci tablicaOdleglosci, UstawieniaAlgorytmu ustawieniaAlgoytmu);
    void iteracja(); ///<Pojedyncza iteracja (wymiana jednego pokolenia)
    Populacja zwrocBierzacaPopulacje() const;
    Osobnik zwrocNajlepszegoOsobnika() const;
    WynikFunkcjiOceny zwrocOceneNajlepszegoOsobnika() const;
private:
    std::default_random_engine _generator; ///<Generator liczb losowych
    UstawieniaAlgorytmu _ustawieniaAlgorytmu;
    TablicaOdleglosci _tablicaOdleglosci;
    Populacja _bierzacaPopulacja;
};

/** \class Reproduktor
 * Klasa odpowiedzialna za przeprowadzenie reprodukcji osobników populacji zgodnie z wprowadzonymi ustawieniami algorytmu.
 * Do krzyżowania wybrana jest metoda ruletki.
 */
class Reproduktor {
public:
    Reproduktor(const UstawieniaAlgorytmu& ustawieniaAlgoytmu, std::default_random_engine& generator);
    void reprodukuj(const Populacja& populacja);
    Populacja zwrocPotomkow() const;
private:
    std::default_random_engine& _generator;
    UstawieniaAlgorytmu _ustawieniaAlgorytmu;
    Populacja _nowaPopulacja;
    void wybierzOsobnikiDoReprodukcji(const Populacja& populacja); ///<wybieranie osobników do populacji, korzystając z metody ruletkowej
    void krzyzujParami(); ///<jeśli nieparzysta liczba osobników, ostatni nie podlega krzyzowaniu
    void krzyzuj(Osobnik& osobnik1, Osobnik& osobnik2); ///<krzyżowanie osobników przy pomocy jednokrotnego cięcia genotypu
};

/** \class Mutator
 * Klasa ospowiedzialna za przeprowadzenie mutacji. Osobnik mutowany jest z prawdopodobieństwem określonym
 * w ustawieniach algorytmu. Mutacja osobnika polega na zmianie jednego z jego chromosomów. Zmiana ta wykonywana
 * jest poprzez wylosowanie nowej wartości z puli wartości dostępnych dla tego chromosomu. Nie jest możliwe
 * wylosowanie tej samej wartości. Zmutowany chromosom zawsze jest różny.
 */
class Mutator {
public:
    Mutator(const UstawieniaAlgorytmu& ustawieniaAlgoytmu, std::default_random_engine& generator);
    void mutuj(Populacja& populacja); ///<przeprowadza mutację wszystkich osobników, każdy przechodzi mutację z określonym prawdopodobieństwem
private:
    std::default_random_engine& _generator;
    UstawieniaAlgorytmu _ustawieniaAlgorytmu;

    void mutujOsobnika(Osobnik& osobnik);
};


#endif //PSZT1_ALGORYTMEWOLUCYJNY_H
