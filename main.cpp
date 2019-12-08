#include <iostream>
#include "WycieczkaObjazdowa.h"

int main() {
    WycieczkaObjazdowa wycieczkaObjazdowa;
    wycieczkaObjazdowa.wczytajDane("miasta.txt", 5);
    wycieczkaObjazdowa.przeprowadzObliczenia();
    return 0;
}