#include <iostream>
#include <string>
#include "Fahrrad.h"
#include <iomanip>

Fahrrad::Fahrrad(string marke, string modell, int modellJahr, double preis) {
	this->marke = marke;
	this->modell = modell;
	this->modellJahr = modellJahr;
	this->preis = preis;
}

void Fahrrad::nenneMarkeModell(void)const {
	cout << "Marke: " << marke << "     \tModell: " << modell << endl;
}

map<string, string> Fahrrad::getProperties() const {
	string _preis;
	map<string, string> mFahrrad;

	mFahrrad["Marke"] = marke;
	mFahrrad["Modell"] = modell;
	mFahrrad["Modelljahr"] = to_string(modellJahr);

	_preis = to_string(preis);
	_preis.erase(_preis.end() - 4, _preis.end());
	_preis.append(" Euro");

	mFahrrad["Preis"] = _preis;

	return mFahrrad;
}

map<string, string> E_Bike::getProperties() const {
	map<string, string> mEBike = Fahrrad::getProperties();

	mEBike["Kapazitat"] = to_string(kapazitat).append(" Wh");

	return mEBike;
}

template <typename T> void ausgabeElement(T t, const int& breite) {
	cout << left << setw(breite) << setfill(' ') << t;
}

void MTB::ausgeben() {
	ausgabeElement("Fahrradtyp", 12);
	ausgabeElement("Marke", 11);
	ausgabeElement("Modell", 14);
	ausgabeElement("Modelljahr", 12);
	ausgabeElement("Preis [Euro]", 0);
	cout << endl;
	ausgabeElement("MTB", 12);
	ausgabeElement(getMarke(), 11);
	ausgabeElement(getModell(), 14);
	ausgabeElement(getModellJahr(), 12);
	ausgabeElement(getPreis(), 0);
	cout << endl;
}


void E_Bike::ausgeben() {
	ausgabeElement("Fahrradtyp", 12);
	ausgabeElement("Marke", 11);
	ausgabeElement("Modell", 14); 
 	ausgabeElement("Modelljahr", 12);
	ausgabeElement("Kapazitaet[Wh]", 16);
	ausgabeElement("Preis[Euro]", 0);
	cout << endl;
	ausgabeElement("MTB", 12);
	ausgabeElement(getMarke(), 11);
	ausgabeElement(getModell(), 14);
	ausgabeElement(getModellJahr(), 12);
	ausgabeElement(getKapazitat(), 16);
	ausgabeElement(getPreis(), 0);
	cout << endl;
}