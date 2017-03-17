//
// Created by julia on 16.03.2017.
//

#ifndef PROJEKT1_LISTA_H
#define PROJEKT1_LISTA_H


#include <string>

struct ElemListy{
    int data=NULL;
    ElemListy * next=NULL;
    ElemListy * prev=NULL;
};

class Lista {
private:
    ElemListy *head=NULL;
    ElemListy *tail=NULL;
public:
    Lista(int rozmiar);
    void wczytaj(std::string nazwapliku);
    void wyswietl();
    void dodaj(int indeks,int wartosc);
    void usun(int indeks);
    bool wyszukaj(int wartosc);


};




#endif //PROJEKT1_LISTA_H
