//
// Created by julia on 20.03.2017.
//

#ifndef PROJEKT1_KOPIEC_H
#define PROJEKT1_KOPIEC_H
#include <iostream>
#include <fstream>
#include <cstdlib>


class Kopiec {
private:
    int *kop;
    int rozmiar;
    int lpoziomow=0;
public:
    Kopiec();
    Kopiec(int roz);
    ~Kopiec();
    void uporzadkowanie();
    void dodaj(int a, int wartosc);
    void usun(int a);
    void poziomy();
    void wczytaj(std::string nazwapliku);
    bool wyszukaj(int wartosc);
    void wyswietl(std::string sp, std::string sn, int v);
};


#endif //PROJEKT1_KOPIEC_H
