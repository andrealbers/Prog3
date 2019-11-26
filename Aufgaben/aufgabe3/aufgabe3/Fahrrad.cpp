#include <iostream>
#include <string>
#include "Fahrrad.h"

Fahrrad::Fahrrad(string marke, string modell, int modellJahr, double preis) {
	this->marke = marke;
	this->modell = modell;
	this->modellJahr = modellJahr;
	this->preis = preis;
}

void Fahrrad::nenneMarkeModell(void)const {
	cout << "Marke: " << marke << "     \tModell: " << modell <<  endl;
}

map<string, string> Fahrrad::getProperties() const {
	map<string, string> map1;
	map1.insert(pair<string, string>("Marke", (this->marke)));
	map1.insert(pair<string, string>("Modell", (this->modell)));
	map1.insert(pair<string, string>("Modelljahr", to_string(this->modellJahr)));
	map1.insert(pair<string, string>("Preis", to_string(this->preis)));

	return map1;
}

map<string, string> E_Bike::getProperties() const {
	map<string, string> map1;

	map1.insert(pair<string, string>("Marke", (getMarke())));
	map1.insert(pair<string, string>("Modell", (getModell())));
	map1.insert(pair<string, string>("Modelljahr", to_string(getModellJahr())));
	map1.insert(pair<string, string>("Preis", to_string(getPreis())));
	map1.insert(pair<string, string>("Kapazitaet", to_string(this->kapazitat)));

	return map1;
}
