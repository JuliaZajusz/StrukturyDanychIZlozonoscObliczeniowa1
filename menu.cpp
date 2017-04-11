// menu.cpp : Defines the entry point for the console application.
//


#include<conio.h>
#include<string>
#include<iostream>
#include <afxres.h>
#include <iomanip>
#include "Tablica.h"
//#include "List.h"
#include "Lista.h"
#include "Kopiec.h"
#include "DrzewoRB.h"
#include "Testy.h"
#include <windows.h>
#include <iomanip>


using namespace std;



//Tablica* a;
//List* b;
Lista *b;
Kopiec* c;
DrzewoRB *d;

string nazwapliku;
int index;
int wartosc;


void displayMenu(string info)
{
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun" << endl;
	cout << "3.Dodaj" << endl;
	cout << "4.Znajdz" << endl;
	cout << "5.Utworz losowo" << endl;
	cout << "6.Wyswietl" << endl;
	cout << "7.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}



void menu_table()
{
	char opt;
	do{
		displayMenu("--- TABLICA ---");
		opt = getche();
		cout << endl;
		switch (opt){
		case '1': //tutaj wczytytwanie tablicy z pliku
			cout<<"Podaj nazwe pliku, z ktorego maja zostac wczytane dane: ";
			cin >>nazwapliku;
            a = new Tablica(1);
			a->wczytaj(nazwapliku);
            a->wyswietl();
			break;
		case '2': //tutaj usuwanie elemenu z tablicy
            cout<<"Podaj pozycje elementu, ktory chcesz usunac: ";
                cin>>index;
                a->usun(index);
                a->wyswietl();
			break;
		case '3': //tutaj dodawanie elemetu do tablicy
            cout<<"Podaj pozycje nowego elementu i jego wartosc: ";
            cin>>index;
            cin>>wartosc;
            a->dodaj(index, wartosc);
                a->wyswietl();
			break;
		case '4': //tutaj znajdowanie elemetu w tablicy
            cout<<"Podaj wartosc, ktora chcesz wyszukac: ";
            cin>>wartosc;
            if(a->wyszukaj(wartosc)){
                cout<<"Znaleziono wartosc";
            }else{
                cout<<"Nie znaleziono wartosci";
            }
			break;
		case '5':  //tutaj generowanie  tablicy
            cout << "Podaj rozmiar tablicy: ";
            int roz;
            cin>> roz;
            a = new Tablica(roz);
            a->wyswietl();
			break;
		case '6':  //tutaj wyswietlanie tablicy
            a->wyswietl();
			break;
		case '7': //tutaj nasza funkcja do eksperymentow (pomiary czasów i generowanie danych) - nie bedzie testowana przez prowadzacego
	        //statTworzenia<Tablica>(a, "statTab.txt");
            //statDodawania<Tablica>( "statTab.txt");
            //statWyszukiwania<Tablica>("statTab.txt");
            break;
		}

	} while (opt != '0');
}



void menu_list()
{
    char opt;
    do{
        displayMenu("--- LISTA ---");
        opt = getche();
        cout << endl;
        switch (opt){
            case '1': //tutaj wczytytwanie listy z pliku
                cout<<"Podaj nazwe pliku, z ktorego maja zostac wczytane dane: ";
                cin >>nazwapliku;
                b= new Lista();
                b->wczytaj(nazwapliku);
                b->wyswietl();
                break;
            case '2': //tutaj usuwanie elemenu z listy
                cout<<"Podaj wartosc elementu, ktory chcesz usunac: ";
                cin>>wartosc;
                b->usun(wartosc);
                b->wyswietl();
                break;
            case '3': //tutaj dodawanie elemetu do listy
                cout<<"1.Dodaj na poczatek\n";
                cout<<"2.Dodaj za wskazana wartoscia\n";
                cout<<"3.Dodaj na koniec\n";
                int wybor;
                cin>>wybor;
                switch(wybor){
                    case 1:
                        cout<<"Podaj wartosc nowego elementu: ";
                        cin>>wartosc;
                        b->dodajNaPoczatek(wartosc);
                        break;
                    case 2:
                        cout<<"Podaj wartosc, po ktorej ma zostac wstawiona nowa wartosc: ";
                        int wartoscPoprzedzajaca;
                        cin>>wartoscPoprzedzajaca;
                        cout<<"Podaj wartosc,ktora chcesz wstawic: ";
                        cin>>wartosc;
                        b->dodajZaElementemOWartosci(wartoscPoprzedzajaca, wartosc);
                        break;
                    case 3:
                        cout<<"Podaj wartosc nowego elementu: ";
                        cin>>wartosc;
                        b->dodajNaKoniec(wartosc);
                        break;
                }
                b->wyswietl();
                break;
            case '4': //tutaj znajdowanie elemetu w listy
                cout<<"Podaj wartosc, ktora chcesz wyszukac: ";
                cin>>wartosc;
                if(b->wyszukaj(wartosc)){
                    cout<<"Znaleziono wartosc";
                }else{
                    cout<<"Nie znaleziono wartosci";
                }
                break;
            case '5':  //tutaj generowanie  listy
                cout << "Podaj rozmiar listy: ";
                int roz;
                cin>> roz;
                b = new Lista();
                b->zapelnijLosowo(roz);
                b->wyswietl();
                break;
            case '6':  //tutaj wyswietlanie listy
                b->wyswietl();
                break;
            case '7': //tutaj nasza funkcja do eksperymentow (pomiary czasów i generowanie danych) - nie bedzie testowana przez prowadzacego
                //statTworzenia<Lista>(b, "statLista.txt");
                //statDodawania<Lista>("statLista.txt");
                //statWyszukiwania<Lista>("statLista.txt");
                break;
        }

    } while (opt != '0');
}

void menu_heap()
{
    char opt;
    do{
        displayMenu("--- KOPIEC ---");
        opt = getche();
        cout << endl;
        switch (opt){
            case '1': //tutaj wczytytwanie kopca z pliku
                cout<<"Podaj nazwe pliku, z ktorego maja zostac wczytane dane: ";
                cin >>nazwapliku;
                c=new Kopiec(0);
                c->wczytaj(nazwapliku);
                c->wyswietl("","",0);
                break;
            case '2': //tutaj usuwanie elementu z kopca
                c->usun(0);
                c->wyswietl("","",0);
                break;
            case '3': //tutaj dodawanie elemetu do kopca
                cout<<"Podaj wartosc nowego elementu: ";
                cin>>wartosc;
                c->dodaj(0,wartosc);
                c->wyswietl("","",0);
                break;
            case '4': //tutaj znajdowanie elemetu w kopca
                cout<<"Podaj wartosc, ktora chcesz wyszukac: ";
                cin>>wartosc;
                if(c->wyszukaj(wartosc)){
                    cout<<"Znaleziono wartosc";
                }else{
                    cout<<"Nie znaleziono wartosci";
                }
                break;
            case '5':  //tutaj generowanie  kopca
                cout << "Podaj rozmiar kopca: ";
                int roz;
                cin>> roz;
                c = new Kopiec(roz);
                c->wyswietl("","",0);
                break;
            case '6':  //tutaj wyswietlanie kopca
                c->wyswietl("","",0);
                break;
            case '7': //tutaj nasza funkcja do eksperymentow (pomiary czasów i generowanie danych) - nie bedzie testowana przez prowadzacego
                //statTworzenia<Kopiec>(c, "statKop.txt");
                //statDodawania<Kopiec>("statKop.txt");
                statWyszukiwania<Kopiec>("statKop.txt");
                break;
        }

    } while (opt != '0');
}

void menu_tree()
{
    char opt;
    do{
        displayMenu("--- DRZEWO CZERWONO-CZARNE ---");
        opt = getche();
        cout << endl;
        switch (opt){
            case '1': //tutaj wczytytwanie drzewa z pliku
                cout<<"Podaj nazwe pliku, z ktorego maja zostac wczytane dane: ";
                cin >>nazwapliku;
                d=new DrzewoRB();
                d->wczytaj(nazwapliku);
                d->wyswietl();
                break;
            case '2': //tutaj usuwanie elementu z drzewa
                cout<<"Podaj wartosc elementu, ktory chcesz usunac: ";
                cin>>wartosc;
                WezelDrzewaRB *tmp;
                tmp=d->wyszukaj(wartosc);
                if(tmp!=NULL){
                    d->usun(tmp);
                }
                d->wyswietl();
                break;
            case '3': //tutaj dodawanie elemetu do drzewa
                cout<<"Podaj wartosc nowego elementu: ";
                cin>>wartosc;
                d->dodaj(0,wartosc);
                d->wyswietl();
                break;
            case '4': //tutaj znajdowanie elemetu w drzewie
                cout<<"Podaj wartosc, ktora chcesz wyszukac: ";
                cin>>wartosc;
                if(d->wyszukaj(wartosc)){
                    cout<<"Znaleziono wartosc";
                }else{
                    cout<<"Nie znaleziono wartosci";
                }
                break;
            case '5':  //tutaj generowanie  drzewa
                cout << "Podaj rozmiar drzewa: ";
                int roz;
                cin>> roz;
                d = new DrzewoRB();
                d->zapelnijLosowo(roz);
                d->wyswietl();
                break;
            case '6':  //tutaj wyswietlanie drzewa
                d->wyswietl();
                break;
            case '7': //tutaj nasza funkcja do eksperymentow (pomiary czasów i generowanie danych) - nie bedzie testowana przez prowadzacego
                //statTworzenia<DrzewoRB>(d, "statDrze.txt");
               // statDodawania<DrzewoRB>( "statDrze.txt");
                //WezelDrzewaRB * w=statWyszukiwania<DrzewoRB>( "statDrze.txt");
                break;
        }

    } while (opt != '0');
}


int main(int argc, char* argv[])
{
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

	char option;
	do{
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.Tablica" << endl;
		cout << "2.Lista" << endl;
		cout << "3.Kopiec" << endl;
        cout << "4.Drzewo czerwono-czarne" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje:";		
		option = getche();
		cout << endl;

		switch (option){
		case '1':
			menu_table();
			break;

		case '2':
			menu_list();
			break;

		case '3':
			menu_heap();
			break;

        case '4':
            menu_tree();
        break;
        }

	} while (option != '0');
	

	return 0;
}

