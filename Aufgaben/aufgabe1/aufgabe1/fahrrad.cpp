#include <iostream>
#include <string>
#include <vector>
#include "fahrrad.h"

Fahrrad::Fahrrad() {
	
}


Fahrrad::Fahrrad(string _marke, string _modell, int _modellJahr, double _preis) {
	marke = _marke;
	modell = _modell;
	modellJahr = _modellJahr;
	preis = _preis;

}

void Fahrrad::nenneMarkeModell(void) {
	cout << "Marke: " << marke << "\tModell: " << modell << endl;
}

Fahrrad::~Fahrrad() {
	
}