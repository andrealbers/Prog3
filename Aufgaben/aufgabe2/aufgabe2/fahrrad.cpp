#include <iostream>
#include <string>
#include <vector>
#include "fahrrad.h"

Fahrrad::Fahrrad(string marke, string modell, int modellJahr, double preis) {
	this->marke = marke;
	this->modell = modell;
	this->modellJahr = modellJahr;
	this->preis = preis;
}

void Fahrrad::nenneMarkeModell(void) {
	cout << "Marke: " << marke << "\t\tModell: " << modell << endl;
}