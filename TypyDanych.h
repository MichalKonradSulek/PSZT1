//
// Created by michalsulek on 07.12.2019.
//

#ifndef PSZT1_TYPYDANYCH_H
#define PSZT1_TYPYDANYCH_H

#include <vector>

/** \file TypyDanych.h
 * Plik zawierający aliasy dla wszystkich typów danych używanych w projekcie.
 * Aliasy zostały użyte w celu zwiększenia czytelności kodu.
 */

using WynikFunkcjiOceny = unsigned;
using Chromosom = unsigned;
using Genotyp = std::vector<Chromosom>; //jego wielkosc jest o 1 mniejszy od liczby miast, gdyż miasto zerowe nie wymaga opisu
using Fenotyp = std::vector<unsigned>; //numery kolejnych odwiedzanych miast
using NumerMiasta = unsigned;

/** \struct UstawieniaAlgorytmu
 * Struktura przechowująca wszystkie ustawienia algorytmu.
 * Została stworzona, aby w prosty sposób przekazywać do funkcji potomnych ustawienia symulacji.
 */
struct UstawieniaAlgoytmu {
    size_t iloscChromosomow;
    size_t wielkoscPopulacji;
    bool sortujPrzedKrzyzowaniem;
    size_t wielkoscPopulacjiDzieci;
    UstawieniaAlgoytmu() = default;
};

#endif //PSZT1_TYPYDANYCH_H
