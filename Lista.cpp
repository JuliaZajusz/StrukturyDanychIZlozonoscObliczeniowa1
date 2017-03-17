//
// Created by julia on 16.03.2017.
//

#include "Lista.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

Lista::Lista(int rozmiar){
    ElemListy *pre;
    ElemListy *nex;


    for(int i=0;i<rozmiar;i++){
        ElemListy s;
        s.data=rand();
        if(i==0){
            head=&s;
            pre=head;
        }
        if(i==rozmiar-1){
            s.prev=pre;
            tail=&s;
            nex=tail;
        }
        else{
            s.prev=pre;

            for(int i=rozmiar-2;i==0;i--){
                pre->next=nex;
                nex=& s;
            }
        }

    }
}

void Lista::usun(int indeks) {

}
void Lista::dodaj(int indeks, int wartosc){

}
void Lista::wyswietl() {
    int rozmiar=2; //tymczasowo
    for(int i =0;i<rozmiar;i++){
        //ElemListy s=
        std::cout<<(*head).data;

    }

}
bool Lista::wyszukaj(int wartosc) {

}
void Lista::wczytaj(std::string nazwapliku){

}
