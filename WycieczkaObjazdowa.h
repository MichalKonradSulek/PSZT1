//
// Created by michalsulek on 07.12.2019.
//

#ifndef PSZT1_WYCIECZKAOBJAZDOWA_H
#define PSZT1_WYCIECZKAOBJAZDOWA_H

#include <iostream>
#include <memory>
#include "AlgorytmEwolucyjny.h"
#include "Test.h"

/** \file WycieczkaObjazdowa.h
 * Klasa przeprowadzająca obliczenia, wczytująca dane z pliku i zapisująca wyniki.
 */

class WycieczkaObjazdowa {
public:
    WycieczkaObjazdowa();
    void wczytajDane(const std::string& plik, int iloscRekordow); ///< funkcja wczytująca odległości z pliku do tablicy  odległości
    void przeprowadzObliczenia();
private:
    const size_t WIELKOSC_POPULACJI = 10;
    std::unique_ptr<AlgorytmEwolucyjny> _algorytmEwolucyjny;
    TablicaOdleglosci _tablicaOdleglosci;
};


#endif //PSZT1_WYCIECZKAOBJAZDOWA_H
