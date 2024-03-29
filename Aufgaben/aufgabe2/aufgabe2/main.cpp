/*
Aufgabe2
Datum: 14.11.19
Autor: Andr� Albers
Welche Art von Kontrollstruktur erlaubt es, die Men�f�hrung sp�ter m�glichst einfach erweitern zu k�nnen? Nennen Sie die Vor- und Nachteile gegen�ber anderen Abfragen:
	-switch-case. Vorteil: Leserlich, leicht erweiterbar; Nachteil: Nur exakter Wert kann verglichen werden. ((x > 10)&&(x < 20)) nicht m�glich.
Warum wird an dieser Stelle ein vector genutzt und kein herk�mmliches C-Array?:
	-Leicht erweiterbar, Eigenschaften des vectors leicht ermittelbar (size, ..), at() sicherer.., dynamisch
Was w�rde passieren, wenn Sie Ihre Methode void nenneMarkeModell(void) als private Methode der Klasse Fahrrad schreiben?:
	- Methode ist von au�en nicht sichtbar -> eigene Methode zur Ausgabe in FahrradLaden n�tig, viel aufwendiger
*/

#include <vector>
#include <iostream>
#include <iomanip>
#include "fahrrad.h"
#include "FahrradLaden.h"

using namespace std;

int main(void) {
	int eingabeMenu;
	string eingabeMarke;

	FahrradLaden Katalog;

	do {
		cout << setw(60) << setfill('*') << "";
		cout << "\n0 - Programm beenden\n1 - Kompletten Katalog ausgeben\n2 - Marke suchen" << endl;
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
		default:
			cout << "Fehler bei der Eingabe!" << endl;
		}
	} while (1);

	return 0;
}
