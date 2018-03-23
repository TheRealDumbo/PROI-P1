#include "hist.h"
#include <string>

    int hist::ilosccyfry(std::string tekst, char cyfra)
    {
        int ilosc=0;
        int j=tekst.size();
        for (int i=0; i<j; i++)
        {
            if (tekst[i]==cyfra)
            {
                ilosc++;
            }
        }
        return ilosc;
    }
    double hist::frequency(std::string tekst, int ilosc)
    {
        int o=tekst.size();
        double frq=(double(o))/(double(ilosc));
        return frq;
    }
// Piotr Dabrowski, source klasy histogramu
