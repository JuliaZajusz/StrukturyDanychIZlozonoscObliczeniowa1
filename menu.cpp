// menu.cpp : Defines the entry point for the console application.
//


#include<conio.h>
#include<string>
#include<iostream>
#include "Tablica.h"
using namespace std;

Tablica* a;
string nazwapliku;

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
			break;
		case '3': //tutaj dodawanie elemetu do tablicy
            cout<<"Podaj pozycje nowego elementu i jego wartosc: ";
            int indeks;
            cin>>indeks;
            int wartosc;
            cin>>wartosc;
            a->dodaj(indeks, wartosc);
			break;
		case '4': //tutaj znajdowanie elemetu w tablicy
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
	 //analogicznie jak menu_table()
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

