/*
Aufgabe3
Datum: 20.11.19
Autor: André Albers
...
FRAGE:
	-ANTWORT
*/

#include <vector>
#include <iostream>
#include <iomanip>
#include "fahrrad.h"
#include "FahrradLaden.h"

using namespace std;

int main(void) {
	int eingabeMenu;
	string eingabeMarke, eingabeTyp, eingabeFahrrad;

	FahrradLaden Katalog;

	do {
		cout << setw(60) << setfill('*') << "";
		cout << "\n0 - Programm beenden\n1 - Kompletten Katalog ausgeben\n2 - Marke suchen\n3 - nach Fahrrad-Typen suchen\n4 - Modell ausgeben\n5 - Modelljahre sortieren" << endl;
		cin >> eingabeMenu;

		switch (eingabeMenu) {
		case 0:
			return 0;
		case 1:
			Katalog.vectorAusgabe(ALLES);
			break;
		case 2:
			cout << "Welche Marke moechten Sie suchen? ";
			cin >> eingabeMarke;
			Katalog.sucheMarke(eingabeMarke);
			Katalog.vectorAusgabe(TEIL);
			break;
		case 3:
			cout << "MTB oder E_Bike ausgeben? ";
			cin >> eingabeTyp;
			Katalog.sucheTyp(eingabeTyp);
			break;
		case 4:
			cout << "Welches Modell ausgeben? ";
			cin >> eingabeFahrrad;
			Katalog.sucheModell(eingabeFahrrad);
			break;
		case 5:
			Katalog.sortModelljahr();
			break;
		default:
			cout << "Fehler bei der Eingabe!" << endl;
		}
	} while (1);
	

	return 0;
}