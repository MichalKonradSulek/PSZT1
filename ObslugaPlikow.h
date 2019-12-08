//
// Created by michalsulek on 07.12.2019.
//

#ifndef PSZT1_OBSLUGAPLIKOW_H
#define PSZT1_OBSLUGAPLIKOW_H

#include <iostream>
#include <vector>
#include "TypyDanych.h"

/** \file ObslugaPlikow.h
 * Plik zawierający wszystkie klasy i funkcje związane z wczytywaniem i zapisem danych.
 */

/** \struct TablicaOdleglosci
 * Tablica zawierająca wszystkie odległości między miastami. Odległości między miastem A oraz miastem A powinna wynosić 0;
 * W programi miasta identyfikowane są po numerach indeksów z tej tablicy.
 */
struct TablicaOdleglosci {
    explicit TablicaOdleglosci(size_t wielkosc = 0);
    std::vector<std::vector<wynikFunkcjiOceny>> odleglosci;
    std::vector<std::string> nazwyMiast;
    void dodajMiasto(const std::string& nazwaMiasta);
    size_t wielkosc() const;
};

void wczytajDane(TablicaOdleglosci& tablicaOdleglosci, const std::string &plik, int iloscRekordow); ///<Funkcja wczytująca dane z pliku do tablicy odległości.

#endif //PSZT1_OBSLUGAPLIKOW_H
