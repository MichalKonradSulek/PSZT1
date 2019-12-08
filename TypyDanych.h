//
// Created by michalsulek on 07.12.2019.
//

#ifndef PSZT1_TYPYDANYCH_H
#define PSZT1_TYPYDANYCH_H

#include <vector>

/** \file TypyDanych.h
 * Plik zawierający aliasy dla wszystkich typów danych używanych w projekcie.
 */

using WynikFunkcjiOceny = unsigned;
using Gen = unsigned;
using Genotyp = std::vector<Gen>;
using Fenotyp = std::vector<unsigned>;
using NumerMiasta = unsigned;

struct UstawieniaAlgoytmu {
    size_t iloscChromosomow;
    size_t wielkoscPopulacji;
};

#endif //PSZT1_TYPYDANYCH_H
