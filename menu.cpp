// menu.cpp : Defines the entry point for the console application.
//


#include<conio.h>
#include<string>
#include<iostream>
#include "Tablica.h"
#include "Lista.h"

using namespace std;

Tablica* a;
Lista* b;
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
			break;
		case '6':  //tutaj wyswietlanie tablicy
            a->wyswietl();
			break;
		case '7': //tutaj nasza funkcja do eksperymentow (pomiary czasów i generowanie danych) - nie bedzie testowana przez prowadzacego
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
                b = new Lista(2);
                //b->wczytaj(nazwapliku);
                break;
            case '2': //tutaj usuwanie elemenu z listy
                cout<<"Podaj pozycje elementu, ktory chcesz usunac: ";
                cin>>index;
                b->usun(index);
                b->wyswietl();
                break;
            case '3': //tutaj dodawanie elemetu do listy
                cout<<"Podaj pozycje nowego elementu i jego wartosc: ";
                cin>>index;
                cin>>wartosc;
                b->dodaj(index, wartosc);
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
                cout << "Podaj rozmiar tablicy: ";
                int roz;
                cin>> roz;
                b = new Lista(roz);
                break;
            case '6':  //tutaj wyswietlanie listy
                b->wyswietl();
                break;
            case '7': //tutaj nasza funkcja do eksperymentow (pomiary czasów i generowanie danych) - nie bedzie testowana przez prowadzacego
                break;
        }

    } while (opt != '0');
}

void menu_heap()
{
	//analogicznie jak menu_table()
}

int main(int argc, char* argv[])
{

	char option;
	do{
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.Tablica" << endl;
		cout << "2.Lista" << endl;
		cout << "3.Kopiec" << endl;
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
		}

	} while (option != '0');
	

	return 0;
}

