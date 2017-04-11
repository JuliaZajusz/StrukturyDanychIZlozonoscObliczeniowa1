//
// Created by julia on 20.03.2017.
//

#include "Kopiec.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <math.h>

Kopiec::Kopiec(int roz){
    srand (time(NULL));
    rozmiar=roz;
    kop=new int[rozmiar];

    while(roz>0){
        roz-=pow(2,lpoziomow);
        lpoziomow++;
    }

    for(int i=0; i<rozmiar; i++) {                   //wypelnienie tablicy liczbami
        int element = rand() % 100;
        kop[i]=element;
    }
    uporzadkowanie();
}


void Kopiec::uporzadkowanie(){
    for(int i=0; i<rozmiar; i++) {                    //uporzadkowanie tablicy
        int element=kop[i];
        for(int c=0; c<(lpoziomow-1);c++) {
            int j = ceil((i-1)/2);
            while (i>0 && kop[j]<element) {
                kop[i] = kop[j];
                kop[j] = element;
                i = j;
                j = ceil((i-1)/2);
            }
            kop[i]=element;
        }
    }
}

void Kopiec::wyswietl(std::string sp, std::string sn, int v) {
    std::string cr,cl,cp;
    std::string s;
    cr = cl = cp = "  ";      //                     _
    cr[0] = 218; cr[1] = 196; //196 -           218 |          192 |_      179 |
    cl[0] = 192; cl[1] = 196;
    cp[0] = 179;

    if(v < rozmiar) {
        s = sp;
        if(sn == cr) {
            s[s.length() - 2] = ' ';
        }
        wyswietl(s + cp, cr, 2 * v + 2);
        s = s.substr(0,sp.length()-2);
        std::cout << s << sn << kop[v] << std::endl;

        s = sp;
        if(sn == cl) {
            s[s.length() - 2] = ' ';
        }
        wyswietl(s + cp, cl, 2 * v + 1);
    }
}

Kopiec::~Kopiec() {
    delete[] kop;
}

void Kopiec::dodaj(int a, int wartosc) {
    rozmiar++;
    int *tmpkop=new int[rozmiar];

    for(int i=0;i<rozmiar-1;i++){
        tmpkop[i]=kop[i];
    }
    tmpkop[rozmiar-1]=wartosc;
    delete[] kop;
    kop=new int[rozmiar];

    for(int i=0;i<rozmiar;i++){
        kop[i]=tmpkop[i];
    }
    poziomy();
    uporzadkowanie();
    delete[] tmpkop;
}

void Kopiec::usun(int a) {
    if(rozmiar!=0) {
        rozmiar--;
        int *tmpkop = new int[rozmiar];

        for (int i = 0; i < rozmiar; i++) {
            tmpkop[i] = kop[i+1];
        }
        delete[] kop;
        kop=new int[rozmiar];

        for(int i=0;i<rozmiar;i++){
            kop[i]=tmpkop[i];
        }
        poziomy();
        uporzadkowanie();
        delete[] tmpkop;
    }else return;
}

void Kopiec::poziomy() {
    lpoziomow = 0;
    int roz=rozmiar;
    while (roz > 0) {
        roz -= pow(2, lpoziomow);
        lpoziomow++;
    }
}

void Kopiec::wczytaj(std::string nazwapliku) {
    std::ifstream plik;
    std::string dana;
    plik.open(nazwapliku);
    plik>>dana;
    rozmiar=atoi(dana.c_str());
    kop = new int[rozmiar];

    for(int i=0; i<rozmiar;i++){
        plik>>dana;
        kop[i]=atoi(dana.c_str());
    }
    plik.close();
    poziomy();
    uporzadkowanie();
}

Kopiec::Kopiec() {
    rozmiar=0;
    kop=new int[rozmiar];
}

/*bool Kopiec::wyszukaj(int wartosc) {
    for(int i=0;i<rozmiar;i++){
        int a=kop[i];
        if(a==wartosc){
            return true;
        }
    }
    return false;
}*/

bool Kopiec::wyszukaj(int wartosc) {
    if(kop[0]==wartosc){
        return true;
    }
    for(int i=0;i<rozmiar;i++){ //dla kazdego elementu
        if((2*i+1)<rozmiar){          //jeśli lewy syn istnieje
            if(kop[2*i+1]==wartosc){//jesli lewy syn jest szukana wartoscia
                return true;
            }else if((2*i+2)<rozmiar){    //jesli prawy syn istnieje
                if(kop[2*i+2]==wartosc){// jesli prawy syn jest szukana wartoscia
                    return true;
                }
            }
        }
    }
    return false;
}
