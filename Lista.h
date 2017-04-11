//
// Created by julia on 02.04.2017.
//

#ifndef PROJEKT1_LISTA_H
#define PROJEKT1_LISTA_H
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

class ElemListy {
public:
    ElemListy *nast, *pop;
    int wartosc;
};

class Lista {
private:
    ElemListy *glowa, *ogon;
public:
    int rozmiar;
public:
    Lista();
    ~Lista();
    void zapelnijLosowo(int rozmiar);
    bool wyszukaj(int liczbaDoZnalezienia);
    void wczytaj(string nazwa);
    void dodajZaElementemOWartosci(int wartoscPoprzedzajacego, int wartosc);
    void dodajNaPoczatek(int nowyKlucz);
    void dodajNaKoniec(int wartosc);
    void usun(int wartoscDoUsuniecia);
    void wyswietl();
};




#endif //PROJEKT1_LISTA_H
