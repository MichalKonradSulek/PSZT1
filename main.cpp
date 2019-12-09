//Autorzy:
//Aleksandra Brela
//Michał Sułek

#include "WycieczkaObjazdowa.h"

int main() {
    WycieczkaObjazdowa wycieczkaObjazdowa;
    wycieczkaObjazdowa.wczytajDane("miastaPelne.txt", 37);
    wycieczkaObjazdowa.przeprowadzObliczenia();
    return 0;
}