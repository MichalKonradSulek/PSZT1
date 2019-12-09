//Autorzy:
//Aleksandra Brela
//Michał Sułek

#ifndef PSZT1_WYCIECZKAOBJAZDOWA_H
#define PSZT1_WYCIECZKAOBJAZDOWA_H

#include <iostream>
#include <memory>
#include "AlgorytmEwolucyjny.h"
#include "Test.h"

/** \file WycieczkaObjazdowa.h
 * Klasa wywołująca algorytm ewolucyjny, umożliwiająca automatyzaję obliczeń.
 * Wczytuje dane z pliku i prezentuje wyniki.
 * To właśnie ta klasa przeprowadza testy algorytmu.
 */

class WycieczkaObjazdowa {
public:
    WycieczkaObjazdowa();
    void wczytajDane(const std::string& plik, int iloscRekordow); ///< funkcja wczytująca odległości z pliku do tablicy  odległości
    void przeprowadzObliczenia();
private:
    TablicaOdleglosci _tablicaOdleglosci;
};


#endif //PSZT1_WYCIECZKAOBJAZDOWA_H
