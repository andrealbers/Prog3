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

void headerzeichnen() {
	ausgabeElement("Fahrradtyp", 15);
	ausgabeElement("Marke", 15);
	ausgabeElement("Modell", 15);
	ausgabeElement("Modelljahr", 15);
	ausgabeElement("Preis [Euro]", 15);
	ausgabeElement("Kapazitaet[Wh]", 0);
	cout << endl << left << setw(89) << setfill('-') << "";
	}

void MTB::ausgeben() {
	//headerzeichnen();
	cout << endl;
	ausgabeElement("MTB", 15);
	ausgabeElement(getMarke(), 15);
	ausgabeElement(getModell(), 15);
	ausgabeElement(getModellJahr(), 15);
	ausgabeElement(getPreis(), 15);
	ausgabeElement('-', 0);
}

void E_Bike::ausgeben() {
	//headerzeichnen();
	cout << left << setw(75) << setfill(' ');
	//ausgabeElement("Kapazitaet[Wh]", 0);
	cout << endl;

	ausgabeElement("MTB", 15);
	ausgabeElement(getMarke(), 15);
	ausgabeElement(getModell(), 15);
	ausgabeElement(getModellJahr(), 15);
	ausgabeElement(getPreis(), 15);
	ausgabeElement(getKapazitat(), 0);
}

void Fahrrad::setPreisFahrrad(double& rabatt) {

	preis = preis * (1-(rabatt/100)); 
}