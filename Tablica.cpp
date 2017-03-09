//
// Created by julia on 09.03.2017.
//
#include <iostream>
#include "Tablica.h"
#include <cstdlib>
#include <ctime>
#include <fstream>

Tablica::Tablica(int rozmiar) {
    //
    srand (time(NULL));
    Tablica::tab = new int[rozmiar];
    this->rozmiar = rozmiar;
    for(int i =0;i<rozmiar;i++){
        tab[i] = rand();
    }
}

void Tablica::wyswietl() {
    for(int i =0;i<rozmiar;i++){
        std::cout << tab[i] << " ";
    }
}


void Tablica::dodaj(int indeks, int wartosc) {
    rozmiar++;
    int * tmptab = new int[rozmiar];
    std::cout<<"gwiazdka";
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

void Tablica::zapiszStatystykeDoPliku() {
    std::ofstream plik;
    plik.open("danelosowe.txt");
    /*
    for(int i =0;i<rozmiar;i++){
        plik << tab[i] << " ";
    }*/
    plik.close();
}

void Tablica::wczytaj(std::string nazwapliku) {
    std::cout<<"tutaj";
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



