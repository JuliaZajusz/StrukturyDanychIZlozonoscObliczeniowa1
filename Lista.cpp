//
// Created by julia on 02.04.2017.
//

#include "Lista.h"

Lista::Lista(){

    ogon = glowa = NULL;
    rozmiar = 0;
}

Lista::~Lista(){
    ElemListy * element;
    while (glowa) {
        element = glowa->nast;
        delete glowa;
        glowa = element;
    }
    rozmiar = 0;
}

void Lista::zapelnijLosowo(int ile){
    srand (time(NULL));
    for (int i = 1; i <= ile; i++)
        dodajNaPoczatek(rand());
}


void Lista::wczytaj(string nazwaPliku){
    string s;
    int i = 0;
    ifstream plik(nazwaPliku);
    if (!plik)
        cout << "Nie mozna otworzyc pliku" << endl;
    else {
        getline(plik, s);
        int rozmiar = atoi(s.c_str());
        while (!plik.eof()) {
            if (i < rozmiar) {
                getline(plik, s);
                int wartosc = atoi(s.c_str());
                dodajNaKoniec(wartosc);
                i++;
            } else break;
        }
        plik.close();
        for (i; i < rozmiar; i++) {
            dodajNaKoniec(0);
        }
    }
}


void Lista::dodajZaElementemOWartosci(int wartoscPoprzedzajacego, int wartosc) {
    ElemListy *element;
    ElemListy * nowyElement = new ElemListy();
    if (!(wyszukaj(wartoscPoprzedzajacego))) {                                                          //jeżeli nie znajdzie elementu za który ma wstawić
        dodajNaKoniec(wartosc);
        cout << "Na liscie nie ma elementu o podanej wartosci - wstawiono na koniec listy" << endl;
    } else {                                                                                            //jeśli znajdzie
        element = glowa;
        for (unsigned i = 1; i <= rozmiar; i++) {
            if (element->wartosc == wartoscPoprzedzajacego) {
                nowyElement->nast = element->nast;
                nowyElement->pop = element;
                element->nast = nowyElement;
                if (nowyElement->nast) {
                    nowyElement->nast->pop = nowyElement;
                }
                else {
                    ogon = nowyElement;
                }
                nowyElement->wartosc = wartosc;
                rozmiar++;
                break;
            } else {
                element = element->nast;
            }
        }
    }
}


void Lista::dodajNaPoczatek(int wartosc){
    ElemListy * nowyElement = new ElemListy();
    nowyElement->nast = glowa;
    nowyElement->pop = NULL;
    if (glowa) {                                //jeśli głowa istanieje
        glowa->pop = nowyElement;
    }
    glowa = nowyElement;                        //jeśli głowa nie istnieje to nowy element staje się głową
    if (!ogon) {                                //jeśli nie ma ogona
        ogon = glowa;
    }
    nowyElement->wartosc = wartosc;
    rozmiar++;
}


void Lista::dodajNaKoniec(int wartosc){
    ElemListy * nowyElement = new ElemListy();
    nowyElement->pop = ogon;
    nowyElement->nast = NULL;
    if (ogon) {
        ogon->nast = nowyElement;
    }
    ogon = nowyElement;
    if (!glowa) {
        glowa = ogon;
    }
    nowyElement->wartosc = wartosc;
    rozmiar++;
}


void Lista::usun(int wartoscDoUsuniecia){
    ElemListy *element;
    element = glowa;
    if (rozmiar == 0) cout << "Lista jest pusta, nie mozna nic usunac" << endl;
    else {
        while ((element->nast != NULL) && (element->wartosc != wartoscDoUsuniecia)) {                               //dopóki jest następny element i wartość nie jest szukaną wartością do usunięcia
            element = element->nast;                                                                                //przechodź do następnego elementu
        }
        if (element->wartosc == wartoscDoUsuniecia) {                                                               //jeśli znajdziesz wartość
            if (element->nast) {                                                                                    //i istnieje następny element
                element->nast->pop = element->pop;
            }
            else {                                                                                                  //jeśli nie ma następnego
                ogon = element->pop;
            }
            if (element->pop) {                                                                                     //jeśli istnieje poprzedni element
                element->pop->nast = element->nast;
            }
            else glowa = element->nast;                                                                             //jeśli nie istnieje poprzedni element
            rozmiar--;
        }
        else cout << "Na liscie nie ma elementu o podanej wartosci" << endl;
    }
}

bool Lista::wyszukaj(int liczbaDoZnalezienia){
    bool znaleziono = false;
    ElemListy *element;
    element = glowa;                                                                                                //zaczyna szukać od głowy
    for (int i = 1; i <= rozmiar; i++) {
        if (element->wartosc == liczbaDoZnalezienia) {
            znaleziono = true;
            break;
        }
        else {
            element = element->nast;
        }
    }
    return znaleziono;
}


void Lista::wyswietl(){
    ElemListy * element = new ElemListy();
    int i = 0;
    if (!glowa) cout << "Lista jest pusta." << endl;
    else {
        element = glowa;
        while (element) {
            cout << i << ". " << element->wartosc << endl;
            element = element->nast;
            i++;
        }
        cout << endl;
    }
    delete element;
}
