#include <iostream>
#include "klasse.h"

klasse::klasse() {
	preis = 0;
	modell = 0.0;
	cout << "Standard Konstruktor" << endl;
}

klasse::klasse(int preis, float modell) {
	this->preis = preis;
	this->modell = modell;

	cout << "Motorrad wurde angelegt" << endl;
}

const int klasse::getPreis() {
	return preis;
}

const float klasse::getModell() {
	return modell;
}

void klasse::ausgabe() {
	cout << "Modell: " << modell << "\tPreis: " << preis << endl;
}