//
// Created by julia on 02.04.2017.
//

#include <cstdlib>
#include "DrzewoRB.h"

DrzewoRB::DrzewoRB() {
    cr = cl = cp = "  ";
    cr[0] = 218; cr[1] = 196;
    cl[0] = 192; cl[1] = 196;
    cp[0] = 179;
    wezelStraznika.kolor = 'B';          // Inicjujemy strażnika
    wezelStraznika.rodzic = &wezelStraznika;
    wezelStraznika.lewySyn  = &wezelStraznika;
    wezelStraznika.prawySyn = &wezelStraznika;
    korzen = &wezelStraznika;           // Korzeń wskazuje strażnika
}

DrzewoRB::~DrzewoRB() {
    usunRekurencyjnie(korzen);
}

void DrzewoRB::usunRekurencyjnie(WezelDrzewaRB *wezel) {
    if(wezel != &wezelStraznika) {            //jeśli usuwany wezel nie jest ostatni
        usunRekurencyjnie(wezel->lewySyn);   // usuwamy lewe poddrzewo
        usunRekurencyjnie(wezel->prawySyn);  // usuwamy prawe poddrzewo
        delete wezel;                        // usuwamy sam węzeł
    }
}



void DrzewoRB::zapelnijLosowo(int roz) {
    srand (time(NULL));
    for(int i=0; i<roz;i++){
        this->dodaj(0,(rand() % 100));      //dodaj wezel o losowej wartosci
    }

}

void DrzewoRB::wczytaj(string nazwapliku) {
    string s;
    int i = 0;
    ifstream plik(nazwapliku);
    if (!plik)
        cout << "Nie mozna otworzyc pliku" << endl;
    else {
        getline(plik, s);
        int rozmiar = atoi(s.c_str());      //pierwsza wartość to rozmiar
        while (!plik.eof()) {               //do końca pliku
            if (i < rozmiar) {
                getline(plik, s);
                int wartosc = atoi(s.c_str());
                dodaj(0,wartosc);           //dodaj węzeł o wczytajnej wartości
                i++;
            } else break;
        }
        plik.close();
        for (i; i < rozmiar; i++) {         //jesli rozmiar większy niż liczba danych w pliku, pozostale wypelnij zerami
            dodaj(0,0);
        }
    }
}



void DrzewoRB::wyswietl() {
    printRBT("","",korzen);
}



void DrzewoRB::printRBT(string sp, string sn, WezelDrzewaRB *wezel) {                                   // Wypisuje drzewo
    string t;

    if(wezel != &wezelStraznika)                                                                    //jeśli wezel nie jest ostatnim
    {
        t = sp;
        if(sn == cr) t[t.length() - 2] = ' ';
        printRBT(t+cp,cr,wezel->prawySyn);

        t = t.substr(0,sp.length()-2);
        std::cout << t << sn << wezel->kolor << ":" << wezel->wartosc << endl;

        t = sp;
        if(sn == cl) t[t.length() - 2] = ' ';
        printRBT(t+cp,cl,wezel->lewySyn);
    }
}



WezelDrzewaRB *DrzewoRB::wyszukaj(int wartosc) {
    WezelDrzewaRB * wezel;
    wezel = korzen;                                                                                 //zaczynamy sprawdzac od korzenia
    while((wezel != &wezelStraznika) && (wezel->wartosc != wartosc))                                //dopoki sprawdzany wezel nie jest ostatnim i jego wartosc nie jest wartoscia szukana
        if(wartosc < wezel->wartosc) {                                                              //jesli szukana wartosc jest mniejsza niz wartosc wezla
            wezel = wezel->lewySyn;                                                                 //niech sprawdzany teraz będzie jego lewy syn
        }else{                                                                                      //jeśli mniejsza bądź równa
            wezel = wezel->prawySyn;                                                                //-||- prawy syn
        }
    if(wezel == &wezelStraznika) {                                                                  //jeśli dojdziesz do końca drzewa, wartość nie została znaleziona, zwróć null
        return NULL;
    }
    return wezel;
}

                                                                                    //       A              B
                                                                                    //      / \            / \
                                                                                    //     AL  B          A   BR
                                                                                    //        / \    ->  / \            .
                                                                                    //       BL  BR     AL BL
void DrzewoRB::obrotL(WezelDrzewaRB *A) {
    WezelDrzewaRB * B, * p;
    B = A->prawySyn;                                                     //B jest prawym synem A
    if(B != &wezelStraznika) {                                           //jeśli B nie jest strażnikiem (jeśli ma synów)
        p = A->rodzic;                                                   //p jest rodzicem A
        A->prawySyn = B->lewySyn;                                        //prawym synem A staje się lewy syn B
        if(A->prawySyn != &wezelStraznika) {                             //jeśli prawy syn A nie jest strażnikiem
            A->prawySyn->rodzic = A;                                     //to jego rodzicem zostaje A
        }

        B->lewySyn = A;                                                  //Lewym synem B zostaje A
        B->rodzic = p;                                                   //rodzicem B zostaje p(czyli były rodzic A)
        A->rodzic = B;                                                   //rodzicem A zostaje B

        if(p != &wezelStraznika) {                                       //jeżeli A miało rodzica (nieStrażnika) to
            if(p->lewySyn == A) {                                        //jeśli A jest lewym synem p
                p->lewySyn = B;                                          //to B staje się lewym synem p
            } else {
                p->prawySyn = B;                                         // w przeciwnym razie B staje się prawym synem p
            }
        }
        else korzen = B;                                                 //jeśli A było korzeniem to teraz korzeniem jest B
    }
}





                                                                        //       A              B
                                                                        //      / \            / \
                                                                        //     B   AR         BL  A
                                                                        //    / \       ->       / \      .
void DrzewoRB::obrotR(WezelDrzewaRB *A) {                               //   BL  BR             BR AR
    WezelDrzewaRB * B, * p;
    B = A->lewySyn;                                                     //B jest lewym synem A
    if(B != &wezelStraznika) {                                          //jeśli B nie jest strażnikiem (jeśli ma synów)
        p = A->rodzic;                                                  //p jest rodzicem A
        A->lewySyn = B->prawySyn;                                       //lewym synem A staje się prawy syn B
        if(A->lewySyn != &wezelStraznika) {                             //jeśli lewy syn A nie jest strażnikiem
            A->lewySyn->rodzic = A;                                     //to jego rodzicem zostaje A
        }

        B->prawySyn = A;                                                //Prawym synem B zostaje A
        B->rodzic = p;                                                  //rodzicem B zostaje p(czyli były rodzic A)
        A->rodzic = B;                                                  //rodzicem A zostaje B

        if(p != &wezelStraznika) {                                      //jeżeli A miało rodzica (nieStrażnika) to
            if(p->lewySyn == A) {                                       //jeśli A jest lewym synem p
                p->lewySyn = B;                                         //to B staje się lewym synem p
            } else {
                p->prawySyn = B;                                        // w przeciwnym razie B staje się prawym synem p
            }
        }
        else korzen = B;                                                //jeśli A było korzeniem to teraz korzeniem jest B
    }
}



void DrzewoRB::dodaj(int a,int wartosc) {
    WezelDrzewaRB * X, * Y;
    X = new WezelDrzewaRB;                                               // Tworzymy nowy węzeł
    X->lewySyn  = &wezelStraznika;                                       // Inicjujemy pola
    X->prawySyn = &wezelStraznika;
    X->rodzic    = korzen;
    X->wartosc   = wartosc;
    if(X->rodzic == &wezelStraznika) korzen = X;                         //jeśli nie ma korzenia X staje się korzeniem
    else
        while(true) {                                                    // Szukamy liścia do zastąpienia przez X
            if(wartosc < X->rodzic->wartosc) {                           //jeśli wartość X jest mniejsza niż warość jego rodzica
                if(X->rodzic->lewySyn == &wezelStraznika) {              //jeśli lewy syn jest Strażnikiem
                    X->rodzic->lewySyn = X;                              // X zastępuje lewy liść
                    break;
                }
                X->rodzic = X->rodzic->lewySyn;                          //rodzicem X staje się lewy syn
            } else {                                                     //jeśli wartość X jest większa lub równa wartosci jego rodzica
                if(X->rodzic->prawySyn == &wezelStraznika) {             //jeśli prawy syn jest Strażnikiem
                    X->rodzic->prawySyn = X;                             // X zastępuje prawy liść
                    break;
                }
                X->rodzic = X->rodzic->prawySyn;                        //rodzicem staje się prawy syn
            }
        }
    X->kolor = 'R';                                                      // Węzeł kolorujemy na czerwono
    while((X != korzen) && (X->rodzic->kolor == 'R')) {                  //dopóki X nie jest korzeniem i jego rodzic jest czerwony
        if(X->rodzic == X->rodzic->rodzic->lewySyn) {                    //jeśli rodzic X jest lewym synem (swojego ojca)
            Y = X->rodzic->rodzic->prawySyn;                             // Y -> wujek X

            if(Y->kolor == 'R'){                                             // Przypadek 1
                X->rodzic->kolor = 'B';                                      //Ojca i wujka kolorujemy na czarno a dziadka na czerwono
                Y->kolor = 'B';
                X->rodzic->rodzic->kolor = 'R';
                X = X->rodzic->rodzic;
                continue;
            }

            if(X == X->rodzic->prawySyn)   {                                 // Przypadek 2
                X = X->rodzic;                                               //jeżeli X jest prawym synem to obrót w lewo, żeby był lewym synem i przechodzimy do przypadku 3
                obrotL(X);
            }

            X->rodzic->kolor = 'B';                                         // Przypadek 3
            X->rodzic->rodzic->kolor = 'R';                                 //jeżeli X jest lewym synem to obrót w prawo względem dziadka
            obrotR(X->rodzic->rodzic);
            break;
        }
        else {                                                              // Przypadki lustrzane
            Y = X->rodzic->rodzic->lewySyn;

            if(Y->kolor == 'R')                                             // Przypadek 1
            {
                X->rodzic->kolor = 'B';
                Y->kolor = 'B';
                X->rodzic->rodzic->kolor = 'R';
                X = X->rodzic->rodzic;
                continue;
            }

            if(X == X->rodzic->lewySyn)                                      // Przypadek 2
            {
                X = X->rodzic;
                obrotR(X);
            }

            X->rodzic->kolor = 'B';                                         // Przypadek 3
            X->rodzic->rodzic->kolor = 'R';
            obrotL(X->rodzic->rodzic);
            break;
        }
    }
    korzen->kolor = 'B';
}





void DrzewoRB::usun(WezelDrzewaRB *X) {
    WezelDrzewaRB * W, * Y, * Z;

    if((X->lewySyn == &wezelStraznika) || (X->prawySyn == &wezelStraznika)) {               //jeżeli X nie ma któregoś z synów
        Y = X;
    }
    else{
        Y = znajdzNastepnik(X);
    }

    if(Y->lewySyn != &wezelStraznika) {                                                      //jeżeli lewy syn Y istnieje
        Z = Y->lewySyn;
    }
    else{
        Z = Y->prawySyn;
    }

    Z->rodzic = Y->rodzic;

    if(Y->rodzic == &wezelStraznika) {                                                       //jeśli Y jest korzeniem
        korzen = Z;
    }
    else if(Y == Y->rodzic->lewySyn) {                                                      //jeśli Y jest lewym synem
        Y->rodzic->lewySyn  = Z;
    }
    else{                                                                                   //jeśli jest prawym synem
        Y->rodzic->prawySyn = Z;
    }

    if(Y != X) {
        X->wartosc = Y->wartosc;
    }

    if(Y->kolor == 'B')                                                         // Naprawa struktury drzewa czerwono-czarnego
        while((Z != korzen) && (Z->kolor == 'B'))                               //jeżeli Y jest czarne // dopóki Z nie jest korzeniem i jest czarne
            if(Z == Z->rodzic->lewySyn){                                        //jeżeli Z jest lewym synem
                W = Z->rodzic->prawySyn;                                        //W to brat Z (prawy)

                if(W->kolor == 'R')                                             //jeśli W jest czerwony
                {                                                                // Przypadek 1
                    W->kolor = 'B';
                    Z->rodzic->kolor = 'R';
                    obrotL(Z->rodzic);
                    W = Z->rodzic->prawySyn;
                }

                if((W->lewySyn->kolor == 'B') && (W->prawySyn->kolor == 'B'))     //jeśli obydwaj synowie W są czarni
                {                                                                 // Przypadek 2
                    W->kolor = 'R';
                    Z = Z->rodzic;
                    continue;
                }

                if(W->prawySyn->kolor == 'B')                                      //jeżeli prawy syn W jest czarny
                {                                                                  // Przypadek 3
                    W->lewySyn->kolor = 'B';
                    W->kolor = 'R';
                    obrotR(W);
                    W = Z->rodzic->prawySyn;
                }

                W->kolor = Z->rodzic->kolor;                                     // Przypadek 4
                Z->rodzic->kolor = 'B';
                W->prawySyn->kolor = 'B';
                obrotL(Z->rodzic);
                Z = korzen;                                                        // To spowoduje zakończenie pętli
            }
            else                                                                    //jeżeli Z jest prawym synem
            {                                                                      // Przypadki lustrzane
                W = Z->rodzic->lewySyn;

                if(W->kolor == 'R')
                {                                                                // Przypadek 1
                    W->kolor = 'B';
                    Z->rodzic->kolor = 'R';
                    obrotR(Z->rodzic);
                    W = Z->rodzic->lewySyn;
                }

                if((W->lewySyn->kolor == 'B') && (W->prawySyn->kolor == 'B'))
                {                                                                  // Przypadek 2
                    W->kolor = 'R';
                    Z = Z->rodzic;
                    continue;
                }

                if(W->lewySyn->kolor == 'B')
                {                                                                 // Przypadek 3
                    W->prawySyn->kolor = 'B';
                    W->kolor = 'R';
                    obrotL(W);
                    W = Z->rodzic->lewySyn;
                }

                W->kolor = Z->rodzic->kolor;                                      // Przypadek 4
                Z->rodzic->kolor = 'B';
                W->lewySyn->kolor = 'B';
                obrotR(Z->rodzic);
                Z = korzen;                                                      // To spowoduje zakończenie pętli
            }

    Z->kolor = 'B';

    delete Y;
}


WezelDrzewaRB *DrzewoRB::wyszukajMin(WezelDrzewaRB *wezel) {
    if(wezel != &wezelStraznika)
        while(wezel->lewySyn != &wezelStraznika) wezel = wezel->lewySyn;    //znajdź ostatnieego lewego syna
    return wezel;
}



WezelDrzewaRB *DrzewoRB::znajdzNastepnik(WezelDrzewaRB *wezel) {
    WezelDrzewaRB * r;
    if(wezel != &wezelStraznika)
    {
        if(wezel->prawySyn != &wezelStraznika) {
            return wyszukajMin(wezel->prawySyn);
        }
        else {
            r = wezel->rodzic;
            while((r != &wezelStraznika) && (wezel == r->prawySyn)) {
                wezel = r;
                r = r->rodzic;
            }
            return r;
        }
    }
    return &wezelStraznika;
}





