//
// Created by julia on 24.03.2017.
//

#ifndef PROJEKT1_TESTY_H
#define PROJEKT1_TESTY_H

#include<conio.h>
#include<string>
#include<iostream>
#include <afxres.h>
#include <iomanip>
#include <fstream>
#include "Tablica.h"
//#include "Lista.h"
#include "Kopiec.h"
#include "Tablica.h"
#include "DrzewoRB.h"


extern long long int frequency, start, elapsed;
//extern float times;
//extern float timems;
extern float timeus;
extern Tablica *a;

extern void zachowajCzas();
//extern void statTworzenieTabeli();
extern long long int read_QPC();
extern void zapiszStatystykeDoPliku(std::string nazwapliku, float timeus);
extern void zapiszDoPliku(std::string nazwapliku, std::string tresc);

//void zapiszDoPliku(std::string basic_string, std::string basicString);

template<class Typ>
void statTworzenia(Typ *struktura, std::string nazwaPliku) {


    Typ * tmpStruct;                                        //test dla 1000 elementów
    float tmp=0;
    for(int i=0;i<100;i++){
        start = read_QPC();
        tmpStruct = new Typ();
        tmpStruct->zapelnijLosowo(1000);
        elapsed = read_QPC() - start;
        zachowajCzas();
        tmp+=timeus;
    }
    tmp=tmp/100;
    zapiszStatystykeDoPliku(nazwaPliku,tmp);

    tmp=0;                                            //test dla 2000 elementów
    for(int i=0;i<100;i++){
        start = read_QPC();
        tmpStruct = new Typ();
        tmpStruct->zapelnijLosowo(2000);
        elapsed = read_QPC() - start;
        zachowajCzas();
        tmp+=timeus;
    }
    tmp=tmp/100;
    zapiszStatystykeDoPliku(nazwaPliku,tmp);

    tmp=0;                                            //test dla 5000 elementów
    for(int i=0;i<100;i++){
        start = read_QPC();
        tmpStruct = new Typ();
        tmpStruct->zapelnijLosowo(5000);
        elapsed = read_QPC() - start;
        zachowajCzas();
        tmp+=timeus;
    }
    tmp=tmp/100;
    zapiszStatystykeDoPliku(nazwaPliku,tmp);

    tmp=0;                                            //test dla 10000 elementów
    for(int i=0;i<100;i++){
        start = read_QPC();
        tmpStruct = new Typ();
        tmpStruct->zapelnijLosowo(10000);
        elapsed = read_QPC() - start;
        zachowajCzas();
        tmp+=timeus;
    }
    tmp=tmp/100;
    zapiszStatystykeDoPliku(nazwaPliku,tmp);

    tmp=0;                                            //test dla 20000 elementów
    for(int i=0;i<100;i++){
        start = read_QPC();
        tmpStruct = new Typ();
        tmpStruct->zapelnijLosowo(20000);
        elapsed = read_QPC() - start;
        zachowajCzas();
        tmp+=timeus;
    }
    tmp=tmp/100;
    zapiszStatystykeDoPliku(nazwaPliku,tmp);
    zapiszDoPliku(nazwaPliku, "\n");


}


template<class Typ>
void statDodawania( std::string nazwaPliku) {
    Typ *struktura;
    Typ *tmpStrukt;
    int index;
    for(int i=0;i<1;i++) {
        /*if (i == 0) {
            zapiszDoPliku(nazwaPliku, "dodawanie/usuwanie elementu na poczatku\n");
            index = 0;
        } else if (i == 1) {
            zapiszDoPliku(nazwaPliku, "dodawanie/usuwanie w srodku\n");
            //index = 500;
            index = 3;
        }*/

        float tmp = 0;
        Typ *tmpStrukt = new Typ();
        tmpStrukt->zapelnijLosowo(1000);
        for (int i = 0; i < 100; i++) {    //test dla 1000 elementów
            struktura = tmpStrukt;
            struktura->dodaj(0,65000);
            WezelDrzewaRB* tmpn;
            tmpn=struktura->wyszukaj(65000);
            start = read_QPC();
            //struktura->dodajNaPoczatek(500);
            struktura->usun(tmpn);
            elapsed = read_QPC() - start;
            zachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 100;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);

        tmp = 0;



        tmpStrukt=new Typ();
        tmpStrukt->zapelnijLosowo(2000);                                  //test dla 2000 elementów
             for (int i = 0; i < 100; i++) {
                 struktura = tmpStrukt;
                 struktura->dodaj(0,65000);
                 WezelDrzewaRB* tmpn;
                 tmpn=struktura->wyszukaj(65000);
                 start = read_QPC();
                 //struktura->dodajNaPoczatek(500);
                 struktura->usun(tmpn);
                 elapsed = read_QPC() - start;
                 zachowajCzas();
                 tmp += timeus;
             }
             tmp = tmp / 100;
             zapiszStatystykeDoPliku(nazwaPliku, tmp);

             tmp = 0;
        tmpStrukt=new Typ();
        tmpStrukt->zapelnijLosowo(5000);                                    //test dla 5000 elementów
             for (int i = 0; i < 100; i++) {
                 struktura = tmpStrukt;
                 struktura->dodaj(0,65000);
                 WezelDrzewaRB* tmpn;
                 tmpn=struktura->wyszukaj(65000);
                 start = read_QPC();
                 //struktura->dodajNaPoczatek(500);
                 struktura->usun(tmpn);
                 elapsed = read_QPC() - start;
                 zachowajCzas();
                 tmp += timeus;
             }
             tmp = tmp / 100;
             zapiszStatystykeDoPliku(nazwaPliku, tmp);

             tmp = 0;
        tmpStrukt=new Typ();
        tmpStrukt->zapelnijLosowo(10000);                                        //test dla 10000 elementów
             for (int i = 0; i < 100; i++) {
                 struktura = tmpStrukt;
                 struktura->dodaj(0,65000);
                 WezelDrzewaRB* tmpn;
                 tmpn=struktura->wyszukaj(65000);
                 start = read_QPC();
                 //struktura->dodajNaPoczatek(500);
                 struktura->usun(tmpn);
                 elapsed = read_QPC() - start;
                 zachowajCzas();
                 tmp += timeus;
             }
             tmp = tmp / 100;
             zapiszStatystykeDoPliku(nazwaPliku, tmp);

             tmp = 0;
        tmpStrukt=new Typ();
        tmpStrukt->zapelnijLosowo(20000);                                    //test dla 20000 elementów
             for (int i = 0; i < 100; i++) {
                 struktura = tmpStrukt;
                 struktura->dodaj(0,65000);
                 WezelDrzewaRB* tmpn;
                 tmpn=struktura->wyszukaj(65000);
                 start = read_QPC();
                 //struktura->dodajNaPoczatek(500);
                 struktura->usun(tmpn);
                 elapsed = read_QPC() - start;
                 zachowajCzas();
                 tmp += timeus;
             }
             tmp = tmp / 100;
             zapiszStatystykeDoPliku(nazwaPliku, tmp);


             zapiszDoPliku(nazwaPliku, "\n");


         }
/*
    float tmp = 0;
    zapiszDoPliku(nazwaPliku, "dodawanie/usuwanie elementu w srodku\n");

    tmpStrukt=new Typ();
    tmpStrukt->zapelnijLosowo(500);
    for (int i = 0; i < 100; i++) {    //test dla 1000 elementów
        struktura = tmpStrukt;
        int j=1;
        while(j<500){
            struktura->dodajNaPoczatek(j);
            j++;
        }
        start = read_QPC();
        struktura->dodajZaElementemOWartosci(1,999);
        elapsed = read_QPC() - start;
        zachowajCzas();
        tmp += timeus;
    }
    tmp = tmp / 100;
    zapiszStatystykeDoPliku(nazwaPliku, tmp);

    tmp = 0;

    tmpStrukt=new Typ();
    tmpStrukt->zapelnijLosowo(1000);
    for (int i = 0; i < 100; i++) {    //test dla 2000 elementów
        struktura = tmpStrukt;
        int j=1;
        while(j<1000){
            struktura->dodajNaPoczatek(j);
            j++;
        }
        start = read_QPC();
        struktura->dodajZaElementemOWartosci(1,999);
        elapsed = read_QPC() - start;
        zachowajCzas();
        tmp += timeus;
    }
    tmp = tmp / 100;
    zapiszStatystykeDoPliku(nazwaPliku, tmp);

    tmp = 0;


    tmpStrukt=new Typ();
    tmpStrukt->zapelnijLosowo(2500);
    for (int i = 0; i < 100; i++) {    //test dla 5000 elementów
        struktura = tmpStrukt;
        int j=1;
        while(j<2500){
            struktura->dodajNaPoczatek(j);
            j++;
        }
        start = read_QPC();
        struktura->dodajZaElementemOWartosci(1,999);
        elapsed = read_QPC() - start;
        zachowajCzas();
        tmp += timeus;
    }
    tmp = tmp / 100;
    zapiszStatystykeDoPliku(nazwaPliku, tmp);

    tmp = 0;

    tmpStrukt=new Typ();
    tmpStrukt->zapelnijLosowo(5000);
    for (int i = 0; i < 100; i++) {    //test dla 10000 elementów
        struktura = tmpStrukt;
        int j=1;
        while(j<5000){
            struktura->dodajNaPoczatek(j);
            j++;
        }
        start = read_QPC();
        struktura->dodajZaElementemOWartosci(1,999);
        elapsed = read_QPC() - start;
        zachowajCzas();
        tmp += timeus;
    }
    tmp = tmp / 100;
    zapiszStatystykeDoPliku(nazwaPliku, tmp);

    tmp = 0;

    tmpStrukt=new Typ();
    tmpStrukt->zapelnijLosowo(10000);
    for (int i = 0; i < 100; i++) {    //test dla 20000 elementów
        struktura = tmpStrukt;
        int j=1;
        while(j<10000){
            struktura->dodajNaPoczatek(j);
            j++;
        }
        start = read_QPC();
        struktura->dodajZaElementemOWartosci(1,999);
        elapsed = read_QPC() - start;
        zachowajCzas();
        tmp += timeus;
    }
    tmp = tmp / 100;
    zapiszStatystykeDoPliku(nazwaPliku, tmp);

    tmp = 0;


    zapiszDoPliku(nazwaPliku, "\n");



    zapiszDoPliku(nazwaPliku, "dodawanie/usuwanie elementu na koncu\n");



                 tmpStrukt=new Typ();
                 tmpStrukt->zapelnijLosowo(1000);                       //test dla 1000 elementów
                for (int i = 0; i < 100; i++) {
                     struktura = tmpStrukt;
                     start = read_QPC();
                    struktura->dodajNaKoniec(500);
                    //struktura->usun(1000-1);
                     elapsed = read_QPC() - start;
                     zachowajCzas();
                     tmp += timeus;
                 }
                 tmp = tmp / 100;
                 zapiszStatystykeDoPliku(nazwaPliku, tmp);

                 tmp = 0;
                 tmpStrukt=new Typ();
                tmpStrukt->zapelnijLosowo(2000);                            //test dla 2000 elementów
                 for (int i = 0; i < 100; i++) {
                     struktura = tmpStrukt;
                     start = read_QPC();
                     struktura->dodajNaKoniec(500);
                     //struktura->usun(2000-1);
                     elapsed = read_QPC() - start;
                     zachowajCzas();
                     tmp += timeus;
                 }
                 tmp = tmp / 100;
                 zapiszStatystykeDoPliku(nazwaPliku, tmp);

                 tmp = 0;
    tmpStrukt=new Typ();
    tmpStrukt->zapelnijLosowo(5000);;                            //test dla 5000 elementów
                 for (int i = 0; i < 100; i++) {
                     struktura = tmpStrukt;
                     start = read_QPC();
                     struktura->dodajNaKoniec(500);
                     //struktura->usun(5000-1);
                     elapsed = read_QPC() - start;
                     zachowajCzas();
                     tmp += timeus;
                 }
                 tmp = tmp / 100;
                 zapiszStatystykeDoPliku(nazwaPliku, tmp);

                 tmp = 0;                            //test dla 10000 elementów
    tmpStrukt=new Typ();
    tmpStrukt->zapelnijLosowo(10000);
                 for (int i = 0; i < 100; i++) {
                     struktura = tmpStrukt;
                     start = read_QPC();
                     struktura->dodajNaKoniec(500);
                     //struktura->usun(10000-1);
                     elapsed = read_QPC() - start;
                     zachowajCzas();
                     tmp += timeus;
                 }
                 tmp = tmp / 100;
                 zapiszStatystykeDoPliku(nazwaPliku, tmp);

                 tmp = 0;                            //test dla 20000 elementów
    tmpStrukt=new Typ();
    tmpStrukt->zapelnijLosowo(20000);
                 for (int i = 0; i < 100; i++) {
                     struktura = tmpStrukt;
                     start = read_QPC();
                     struktura->dodajNaKoniec(500);
                     //struktura->usun(20000-1);
                     elapsed = read_QPC() - start;
                     zachowajCzas();
                     tmp += timeus;
                 }
                 tmp = tmp / 100;
                 zapiszStatystykeDoPliku(nazwaPliku, tmp);


                 zapiszDoPliku(nazwaPliku, "\n");
*/


}





template<class Typ>
void statWyszukiwania( std::string nazwaPliku) {
    int tmp=0;
    Typ*struktura=new Typ(1000);
    //struktura->dodaj(0, 400);
    start = read_QPC();
    struktura->wyszukaj(400);
    elapsed = read_QPC() - start;
    zachowajCzas();
    tmp += timeus;

    zapiszStatystykeDoPliku(nazwaPliku, tmp);
    tmp=0;

    struktura=new Typ(2000);
    //struktura->dodaj(0, 400);
    start = read_QPC();
    struktura->wyszukaj(400);
    elapsed = read_QPC() - start;
    zachowajCzas();
    tmp += timeus;

    zapiszStatystykeDoPliku(nazwaPliku, tmp);
    tmp=0;

    struktura=new Typ(5000);
    //struktura->dodaj(0, 400);
    start = read_QPC();
    struktura->wyszukaj(400);
    elapsed = read_QPC() - start;
    zachowajCzas();
    tmp += timeus;

    zapiszStatystykeDoPliku(nazwaPliku, tmp);
    tmp=0;

    struktura=new Typ(10000);
    //struktura->dodaj(0, 400);
    start = read_QPC();
    struktura->wyszukaj(400);
    elapsed = read_QPC() - start;
    zachowajCzas();
    tmp += timeus;

    zapiszStatystykeDoPliku(nazwaPliku, tmp);
    tmp=0;

    struktura=new Typ(20000);
    //struktura->dodaj(0, 400);
    start = read_QPC();
    struktura->wyszukaj(400);
    elapsed = read_QPC() - start;
    zachowajCzas();
    tmp += timeus;

    zapiszStatystykeDoPliku(nazwaPliku, tmp);
    tmp=0;




 /*   if(struktura->wyszukaj(400)==true){
        zapiszDoPliku(nazwaPliku, "znaleziono");
    }*/
   // tmp=0;

 /*   int tmp=0;
    int tru=0;
    Typ*struktura=new Typ(1000);
    struktura->dodaj(500, 99);
    for (int i = 0; i < 100; i++) {
        start = read_QPC();
        struktura->wyszukaj(99);
        elapsed = read_QPC() - start;
        zachowajCzas();
        tmp += timeus;
        if(struktura->wyszukaj(99)==true){
            tru++;
        }
    }
    tmp = tmp / 100;
    zapiszStatystykeDoPliku(nazwaPliku, tmp);
    zapiszStatystykeDoPliku(nazwaPliku, tru);
    tmp=0;
    tru=0;*/
/*
    struktura=new Typ(2000);
    struktura->dodaj(500, 99);
    for (int i = 0; i < 100; i++) {
        start = read_QPC();
        struktura->wyszukaj(99);
        elapsed = read_QPC() - start;
        zachowajCzas();
        tmp += timeus;
    }
    tmp = tmp / 100;
    zapiszStatystykeDoPliku(nazwaPliku, tmp);
    tmp=0;

    struktura=new Typ(5000);
    struktura->dodaj(500, 99);
    for (int i = 0; i < 100; i++) {
        start = read_QPC();
        struktura->wyszukaj(99);
        elapsed = read_QPC() - start;
        zachowajCzas();
        tmp += timeus;
    }
    tmp = tmp / 100;
    zapiszStatystykeDoPliku(nazwaPliku, tmp);
    tmp=0;

    struktura=new Typ(10000);
    struktura->dodaj(500, 99);
    for (int i = 0; i < 100; i++) {
        start = read_QPC();
        struktura->wyszukaj(99);
        elapsed = read_QPC() - start;
        zachowajCzas();
        tmp += timeus;
    }
    tmp = tmp / 100;
    zapiszStatystykeDoPliku(nazwaPliku, tmp);
    tmp=0;

    struktura=new Typ(20000);
    struktura->dodaj(500, 99);
    for (int i = 0; i < 100; i++) {
        start = read_QPC();
        struktura->wyszukaj(99);
        elapsed = read_QPC() - start;
        zachowajCzas();
        tmp += timeus;
    }
    tmp = tmp / 100;
    zapiszStatystykeDoPliku(nazwaPliku, tmp);
    tmp=0;*/
    zapiszDoPliku(nazwaPliku, "\n");


}



#endif //PROJEKT1_TESTY_H
