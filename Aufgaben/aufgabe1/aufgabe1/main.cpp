/*
Aufgabe1
Autor: André Albers
Unterschied private und public: 
	-private: Datenelemente sind innerhalb der Klasse verfügbar
	-public: Dazu noch außerhalb zugreifbar
Wie von außen zugriff auf private Datenelemente?
	-durch get-Methoden, methode gibt als return das private Datenelemente zurück
Gemeinsamkeiten/Unterschiede Funktionen und Methoden:
	- Methoden sind Funktionen aber eine Funktion muss keine Methode sein
*/



#include <vector>
#include "fahrrad.h"

using namespace std;

int main(void) {
	vector<Fahrrad> vecFahrrad;
	vecFahrrad.push_back(Fahrrad("Marke1", "Modell1", 2001, 1000.10)); //Fahrrad::Fahrrad(string marke, string modell, int modellJahr, double preis)
	vecFahrrad.push_back(Fahrrad("Marke2", "Modell2", 2002, 2000.20));
	vecFahrrad.push_back(Fahrrad("Marke3", "Modell3", 3003, 3000.30));
	
	//vecFahrrad.shrink_to_fit();
	for (int i = 0; i < vecFahrrad.size(); i++) {
		vecFahrrad.at(i).nenneMarkeModell();
	}

	return 0;
}
