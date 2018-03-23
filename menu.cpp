#include "menu.h"
#include "hist.h"
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int menu(hist st, hist temp)
{
    cout<<"Witam. Prosze wpisac dowolny tekst z klawiatury."<<endl;
    getline(cin, st.tekst);
    char ic;
    st.iloscall=0;
    for(int i=0; i<10; i++)
    {
        ic=i+48; //zamiana cyfry w znak
        st.ilosc[i]=st.ilosccyfry(st.tekst, ic);
        st.iloscall+=st.ilosc[i];
    }
    char cd;
    merg:
    cout<<endl<<"Aby wpisac nowy tekst, wczytaj 'n'"<<endl<<"Aby sprawdzic statystki konkretnej cyfry, wczytaj wspomniana cyfre"<<endl<<"Aby sprawdzic statystyki wszystkich cyfr w tekscie, wczytaj 'a'"<<endl<<"Aby wyswietlic obecna tresc tekstu, wczytaj 'd'"<<endl<<"Aby zakonczyc prace z programem, wczytaj 'e'"<<endl;
    while(1)
    {
        cin>>cd;
        getchar();
        if((cd>47)&&(cd<58))
        {
            int ci=cd-48;
            cout<<"Cyfra "<<ci<<" wystapila w tekscie "<<st.ilosc[ci]<<" raz(y), z czestotliwoscia srednio 1 na "<<st.frequency(st.tekst, st.ilosc[ci])<<" znak(i/ow)."<<endl;
        }
        if(cd=='a')
        {
            cout<<"Wszystkie cyfry wystapily w tekscie, lacznie "<<st.iloscall<<" raz(y), z czestotliwoscia srednio 1 na "<<st.frequency(st.tekst, st.iloscall)<<" znak(i/ow)."<<endl;
        }
        if(cd=='n')
        {
            cout<<"Wpisz tekst."<<endl;
            getline(cin, temp.tekst);
            break;
        }
        if(cd=='d')
        {
            cout<<endl<<st.tekst<<endl<<endl;
        }
        if(cd=='e')
        {
            return 0;
        }
    }
    temp.iloscall=0;
    for(int i=0; i<10; i++)
    {
        ic=i+48; //zamiana cyfry w znak
        temp.ilosc[i]=temp.ilosccyfry(temp.tekst, ic);
        temp.iloscall+=temp.ilosc[i];
    }
    int git=0; //pomocnicza do porownania histogramow
    cout<<endl<<"Aby sprawdzic podobienstwo histogramow, wczytaj 'c'"<<endl<<"Aby polaczyc tekst w jeden, wczytaj 'm'"<<endl<<"Mozesz takze swobodnie sprawdzic histogram nowego tekstu, za pomoca wczesniej podanych komend, wyswietlic nowy tekst lub zakonczyc prace programu."<<endl;
    while(1)
    {
    cin>>cd;
    getchar();
        if((cd>47)&&(cd<58))
        {
            int ci=cd-48;
            cout<<"Cyfra "<<ci<<" wystapila w tekscie "<<temp.ilosc[ci]<<" raz(y), z czestotliwoscia srednio 1 na "<<temp.frequency(temp.tekst, temp.ilosc[ci])<<" znak(i/ow)."<<endl;
        }
        if(cd=='a')
        {
            cout<<"Wszystkie cyfry wystapily w tekscie, lacznie "<<temp.iloscall<<" raz(y), z czestotliwoscia srednio 1 na "<<temp.frequency(temp.tekst, temp.iloscall)<<" znak(i/ow)."<<endl;
        }
        if(cd=='c')
        {
            for(int i=0; i<10; i++)
            {
                if(st.ilosc[i]==temp.ilosc[i])
                {
                    git++;
                }
                else
                {
                    cout<<"Histogramy sie roznia."<<endl;
                    break;
                }
            }
            if(git==10)
            {
                cout<<"Histogramy sa identyczne"<<endl;
            }
        }
        if(cd=='m')
        {
            st.tekst+=temp.tekst;
            for(int i=0; i<10; i++)
            {
                st.ilosc[i]+=temp.ilosc[i];
            }
            st.iloscall+=temp.iloscall;
            cout<<"Polaczenie tesktow zakonczone pomyslnie."<<endl;
            goto merg;
        }
        if(cd=='d')
        {
            cout<<endl<<temp.tekst<<endl<<endl;
        }
        if(cd=='e')
        {
            return 0;
        }
    }
}
// Piotr Dabrowski, source funkcji interaktywnego menu
