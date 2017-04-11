//
// Created by julia on 02.04.2017.
//

#ifndef PROJEKT1_DRZEWORB_H
#define PROJEKT1_DRZEWORB_H
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

struct WezelDrzewaRB
{
    WezelDrzewaRB * rodzic;
    WezelDrzewaRB * lewySyn;
    WezelDrzewaRB * prawySyn;
    int wartosc;
    char kolor;
};

class DrzewoRB {
private:
    WezelDrzewaRB wezelStraznika;
    WezelDrzewaRB * korzen;
    string cr,cl,cp;                                                                  // Łańcuchy do znaków ramek

    void printRBT(string sp, string sn, WezelDrzewaRB * wezel);                                // Wypisuje drzewo

public:
    DrzewoRB();
    ~DrzewoRB();
    void zapelnijLosowo(int roz);
    void wczytaj(string nazwapliku);
    void usunRekurencyjnie(WezelDrzewaRB *wezel);                                         // Usuwa rekurencyjnie drzewo
    void wyswietl();                                                                      // Wyswietla drzewo
    WezelDrzewaRB * wyszukaj(int wartosc);                                              // Wyszukuje węzeł o danej wartosci
    WezelDrzewaRB * wyszukajMin(WezelDrzewaRB *wezel);                                   // Wyszukuje najmniejszy węzeł w p
    WezelDrzewaRB * znajdzNastepnik(WezelDrzewaRB *wezel);                                     // Wyszukuje następnik danego wezla
    void obrotL(WezelDrzewaRB *A);                                                             // Rotacja w lewo względem A
    void obrotR(WezelDrzewaRB *A);                                                              // Rotacja w prawo względem A
    void dodaj(int a,int wartosc);                                                              // Wstawia węzeł o danej wartosci
    void usun(WezelDrzewaRB *X);                                                                 // Usuwa węzeł X
};


#endif //PROJEKT1_DRZEWORB_H
