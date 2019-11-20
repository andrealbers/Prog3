#include <iostream>
#include <string>
#include "fahrrad.h"

Fahrrad::Fahrrad(string marke, string modell, int modellJahr, double preis) {
	this->marke = marke;
	this->modell = modell;
	this->modellJahr = modellJahr;
	this->preis = preis;
}

void Fahrrad::nenneMarkeModell(void)const {
	cout << "Marke: " << marke << "     \tModell: " << modell << endl;
}
