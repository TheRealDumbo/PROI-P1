#ifndef HIST_H
#define HIST_H
#include <string>
#include <iostream>


class hist
{
public:
    std::string tekst;
    int ilosc[10];
    int iloscall;
    int ilosccyfry(std::string tekst, char cyfra);
    double frequency(std::string tekst, int ilosc);

protected:

private:
};

#endif
// Piotr Dabrowski, header klasy histogramu
