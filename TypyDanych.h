//Autorzy:
//Aleksandra Brela
//Michał Sułek

#ifndef PSZT1_TYPYDANYCH_H
#define PSZT1_TYPYDANYCH_H

#include <vector>

/** \file TypyDanych.h
 * Plik zawierający aliasy dla wszystkich typów danych używanych w projekcie.
 * Aliasy zostały użyte w celu zwiększenia czytelności kodu.
 */
using WynikFunkcjiOceny = unsigned;
using Chromosom = unsigned;
using Genotyp = std::vector<Chromosom>; //jego wielkosc jest o 1 mniejsza od liczby miast, gdyż miasto zerowe nie wymaga opisu
using Fenotyp = std::vector<unsigned>; //numery kolejnych odwiedzanych miast

/** \struct UstawieniaAlgorytmu
 * Struktura przechowująca wszystkie ustawienia algorytmu.
 * Została stworzona, aby w prosty sposób przekazywać do funkcji potomnych ustawienia symulacji.
 */
struct UstawieniaAlgorytmu {
    size_t liczbaMiast;
    size_t iloscChromosomow;
    size_t wielkoscPopulacji;
    bool sortujPrzedKrzyzowaniem;
    size_t wielkoscPopulacjiDzieci;
    unsigned prawdopodobienstwoMutacji; ///<w promilach
};

#endif //PSZT1_TYPYDANYCH_H
