#ifndef HIST_H
#define HIST_H
#include <string>
#include <iostream>
#include <ostream>
class hist
{
public:
    hist(); // konstruktor
    int filosc(std::string tekst, char cyfra); // zwraca ilosc konkretnej cyfry w tekscie
    double fczestotliwosc(std::string tekst, int ilosc); // zwraca x, gdzie konkretna liczba wystapila srednio 1 na x wyrazow
    void dopisanie(); // pozwala na dopisanie dalszej czesci tekstu
    friend hist operator+(hist a, hist b);
    friend std::ostream &    operator<<(std::ostream & a, hist &b);
    friend bool operator==(hist a, hist b); // zaprzyjaznione przeladowane operatory
protected:

private:
    std::string tekst; // tresc tekstu
    int ilosc[10]; // przechowuje ilosc poszczegolnych cyfr w tekscie
    double czestotliwosc[10]; // -,,- czestotliwosci w tekscie
    int iloscall; // przechowuje calkowita ilosc cyfr w tekscie
    double czestotliwoscall; // -,,- czestotliwosc cyfr w tekscie
};
#endif
// Piotr Dabrowski, header klasy histogramu i prze³adowan operatorow
