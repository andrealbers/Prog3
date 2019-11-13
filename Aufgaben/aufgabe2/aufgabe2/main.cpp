/*
Aufgabe2
Datum: 14.11.19
Autor: André Albers
Welche Art von Kontrollstruktur erlaubt es, die Menüführung später möglichst einfach erweitern zu können? Nennen Sie die Vor- und Nachteile gegenüber anderen Abfragen:
	-switch-case. Vorteil: Leserlich, leicht erweiterbar; Nachteil: Nur exakter Wert kann verglichen werden. ((x > 10)&&(x < 20)) nicht möglich.
Warum wird an dieser Stelle ein vector genutzt und kein herkömmliches C-Array?:
	-Leicht erweiterbar, Eigenschaften des vectors leicht ermittelbar (size, ..), at() sicherer.., dynamisch
Was würde passieren, wenn Sie Ihre Methode void nenneMarkeModell(void) als private Methode der Klasse Fahrrad schreiben?:
	- Methode ist von außen nicht sichtbar -> eigene Methode zur Ausgabe in FahrradLaden nötig, viel aufwendiger
*/


#include <vector>
#include <iostream>
#include "fahrrad.h"
#include "FahrradLaden.h"

using namespace std;

int main(void) {
	string eingabeMarke;
	int eingabeMenu;

	FahrradLaden Katalog;
	cout << "\n\n0 - Programm beenden\n1 - Kompletten Katalog ausgeben\n2 - Marke suchen" << endl;
	cin >> eingabeMenu;
	switch (eingabeMenu) {
	case 0:
		return 0;
	case 1:
		Katalog.vectorAusgabe(1);
		break;
	case 2:
		cout << "Welche Marke moechten Sie suchen?" << endl;
		cin >> eingabeMarke;
		Katalog.sucheMarke(eingabeMarke);
		Katalog.vectorAusgabe(2);
		break;
	default:
		cout << "Fehler bei der Eingabe!" << endl;
	}


	return 0;
}
