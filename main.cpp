#include <iostream>
#include "WycieczkaObjazdowa.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    WycieczkaObjazdowa wycieczkaObjazdowa;
    wycieczkaObjazdowa.wczytajDane("miasta.txt", 5);
    wycieczkaObjazdowa.przeprowadzObliczenia();
    return 0;
}