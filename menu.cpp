#include <iostream>
#include <ostream>
#include <string>
#include <cstdio>
#include "hist.h"
#include "menu.h"
// wszystkie metody i przeladowane operatory uzywane w funkcji menu sa opisane w plikach hist.h oraz hist.cpp
using namespace std;

int menu(hist a, hist b)
{
    char cd; // zmienna uzywana do nawigacji po menu
og: // punkt: opcje ogolne
    cout<<"Aby porownac histogramy, wczytaj 'p'"<<endl<<"Aby polaczyc histogramy, wczytaj 'm'"<<endl<<"Aby przejsc do opcji zwiazanych z poszczegolnymi tekstami, wczytaj odpowiednio '1', lub '2'"<<endl<<"Aby zakonczyc prace programu, wczytaj 'e'"<<endl;
    while(1)
    {
        cin>>cd;
        getchar();
        if(cd=='p')
        {
            if(a==b)
            {
                cout<<"Histogramy sa jednakowe."<<endl;
            }
            else
            {
                cout<<"Histogramy sie roznia."<<endl;
            }
        }
        if(cd=='m')
        {
            a=a+b;
            goto polaczone;
        }
        if(cd=='1')
        {
            goto t1;
        }
        if(cd=='2')
        {
            goto t2;
        }
        if(cd=='e')
        {
            return 0;
        }
    }
t1: // punkt tekst 1.
    cout<<"Jestes w tekscie nr 1."<<endl<<"Aby sprawdzic histogram, wczytaj 'h'"<<endl<<"Aby kontynuowac wpisywanie tekstu, wczytaj 'k'"<<endl<<"Aby przejsc do tekstu 2., wczytaj '2'"<<endl<<"Aby przejsc do opcji ogolnych, wczytaj 'o'"<<endl;
    while(1)
    {
        cin>>cd;
        getchar();
        if(cd=='h')
        {
            cout<<a;
        }
        if(cd=='k')
        {
            a.dopisanie();
        }
        if(cd=='2')
        {
            goto t2;
        }
        if(cd=='o')
        {
            goto og;
        }
    }
t2: // punkt: tekst 2.
    cout<<"Jestes w tekscie nr 2."<<endl<<"Aby sprawdzic histogram, wczytaj 'h'"<<endl<<"Aby kontynuowac wpisywanie tekstu, wczytaj 'k'"<<endl<<"Aby przejsc do tekstu 1., wczytaj '1'"<<endl<<"Aby przejsc do opcji ogolnych, wczytaj 'o'"<<endl;
    while(1)
    {
        cin>>cd;
        getchar();
        if(cd=='h')
        {
            cout<<b;
        }
        if(cd=='k')
        {
            b.dopisanie();
        }
        if(cd=='1')
        {
            goto t1;
        }
        if(cd=='o')
        {
            goto og;
        }
    }
polaczone: //punkt: teksty po zlaczeniu
    cout<<"Jestes w polaczonym tekscie."<<endl<<"Aby sprawdzic histogram, wczytaj 'h'"<<endl<<"Aby kontynuowac wpisywanie tekstu, wczytaj 'k'"<<endl<<"Aby zakonczyc prace programu, wczytaj 'e'"<<endl;
    while(1)
    {
        cin>>cd;
        getchar();
        if(cd=='h')
        {
            cout<<a;
        }
        if(cd=='k')
        {
            a.dopisanie();
        }
        if(cd=='e')
        {
            return 0;
        }
    }
    return 0;
}
