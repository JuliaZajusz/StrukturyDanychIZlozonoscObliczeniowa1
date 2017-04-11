//
// Created by julia on 09.03.2017.
//
#include <iostream>
#include "Tablica.h"
#include <cstdlib>
#include <ctime>
#include <fstream>

Tablica::Tablica(int rozmiar) {
    if(rozmiar==0){
        Tablica::tab=new int[0];
        this->rozmiar=0;
    }
    //
    else {
        srand(time(NULL));
        Tablica::tab = new int[rozmiar];
        this->rozmiar = rozmiar;
        for (int i = 0; i < rozmiar; i++) {
            tab[i] = rand();
        }
    }
}

void Tablica::wyswietl() {
    for(int i =0;i<rozmiar;i++){
        std::cout <<i<<". "<< tab[i] << "\n";
    }
}


void Tablica::dodaj(int indeks, int wartosc) {
    rozmiar++;
    int * tmptab = new int[rozmiar];
    for(int i=0;i<indeks;i++){
        tmptab[i]=tab[i];
    }
    tmptab[indeks]=wartosc;
    for(int i=indeks+1;i<rozmiar;i++){
        tmptab[i]=tab[i-1];
    }
    tab=tmptab;
    tmptab = NULL;
}



void Tablica::wczytaj(std::string nazwapliku) {
    std::ifstream plik;
    std::string dana;
    plik.open(nazwapliku);

    plik>>dana;
    rozmiar=atoi(dana.c_str());
    int * tmptab = new int[rozmiar];
    for(int i=0; i<rozmiar;i++){
        plik>>dana;
        tmptab[i]=atoi(dana.c_str());
    }
    plik.close();
    tab=tmptab;
    tmptab = NULL;
}

void Tablica::usun(int indeks) {
    int * tmptab = new int[rozmiar];
    for(int i=0;i<indeks;i++){
        tmptab[i]=tab[i];
    }
    for(int i=indeks;i<rozmiar;i++){
        tmptab[i]=tab[i+1];
    }
    tab=tmptab;
    tmptab = NULL;
    rozmiar--;
}

bool Tablica::wyszukaj(int wartosc) {
    for(int i=0;i<rozmiar;i++){
        int a=tab[i];
        if(a==wartosc){
            return true;
        }
    }
    return false;
}

Tablica::~Tablica() {
    delete[] tab;
    rozmiar=0;
}



