#include <windows.h> //zmiana tytu�u
#include"BMI.h"
#include"BMR.h"
#include"Zdrowomierz-master/funkcje.h"
#include<limits>
#include <stdlib.h>//kolorki tekstu
#include<iomanip>//srodkowanie

#include <fstream>
#include <string>//getline

void menu()
{
	int opcja;

	HANDLE hOut;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\n********************************************MENU GLOWNE********************************************";
	cout << "\n\nWitaj w aplikacji 'ZdrowioMierz'! Skoro tu jestes to znaczy, ze zaczynasz dbac o siebie i swoj organizm!";
	cout << "\nPierwszy krok w strone lepszej jakosci zycia wykonany - teraz powolutku do przodu ;)\n";
	SetConsoleTextAttribute(hOut, 7);
	cout << "\n\nWybierz opcje:";
	cout << "\n1. Obliczanie BMI";
	cout << "\n2. Obliczanie BMR";
	cout << "\n3. Wpis posilku do dziennika";
	cout << "\n4. Odczyt zapiskow z dziennika";
	cout << "\n5. Wyjscie";
	cout << "\n######################################";
	cout << "\n\nNumer opcji:";
	
}

int main()
{
	SetConsoleTitleA("ZdrowioMierz");
	int opcja;
	
			//while (true)
			//{
	while (true)
	{

		menu();
		cin >> opcja;

		while (cin.fail() || opcja<1 || opcja>5)
		{
			cout << "Nie oszukuj! Nie ma takiej opcji!" << endl;
			cout << "\nNumer opcji:";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> opcja;
		}

		switch (opcja)
		{


		case 1:
		{

			system("cls");
			BMI mojeBMI;

			mojeBMI.oblicz();

			break;
		}

		//cout << "Wroc do menu(dowolny przycisk)";

		case 2:
		{
			system("CLS");
			BMR mojeBMR;

			mojeBMR.wylicz();
			break;
		}
		case 3:
		{
			system("CLS");
			string posilek;
			double kcal;
			double il{};
			
			getline(cin, posilek);

			posilek = wczytajposilek();
			kcal = wczytajkalorie(il);

			wpiszdopliku(posilek, kcal);
			break;
		}
		case 4:
		{
			system("CLS");
			dziennik();
			break;
		}
		case 5:
			return 0;


			
		}
		char temp;
		cout << "Nacisnij przycisk 'q', a nastepie 'enter' by przejsc do poczatku menu: ";
		cin >> temp;
		system("cls");
	}

		
	
}