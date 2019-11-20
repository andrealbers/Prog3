#include "FahrradLaden.h"
#include <iostream>
#include <fstream>

FahrradLaden::FahrradLaden() {
	string leszeile, pfad = "fahrradliste.txt";
	ifstream textdat(pfad);
	string marke, modell;
	int modellJahr, anzWorterLesen = 4;
	double preis;

	if (textdat.is_open()) {
		std::cout << "Datei " << pfad << " wurde geoeffnet!" << endl;

		while (!textdat.eof()) {
			int posnow = 0, posvorher = 0, welchesWort = 0;
			getline(textdat, leszeile);

			if (leszeile == "\0") {
				welchesWort = anzWorterLesen;
			}
			else {
				while (welchesWort < anzWorterLesen) {
					while (leszeile[posnow] != ' ') {
						posnow++;
					}
					string wort = leszeile.substr(posvorher, posnow - posvorher);

					switch (welchesWort) {
					case 0:
						marke = wort;
						break;
					case 1:
						modell = wort;
						break;
					case 2:
						modellJahr = stoi(wort);
						break;
					case 3:
						preis = stod(wort);
						break;
					default:
						std::cout << "Fehler Anzahl Worter!" << endl;
					}

					welchesWort++;
					posnow++;
					posvorher = posnow;
				}
				vecFahrradKatalog.push_back(Fahrrad(marke, modell, modellJahr, preis));
			}
		}
		std::cout << "Anzahl eingelesender Elemente: " << vecFahrradKatalog.size() << endl;
	}
	else { std::cout << "Fehler beim Oeffnen der Datei!\n"; }
}

void printListe(const vector<Fahrrad>& liste) {
	for (unsigned int i = 0; i < liste.size(); i++) {
		liste.at(i).nenneMarkeModell();
	}
}

void FahrradLaden::vectorAusgabe(Auswahl listentyp) {
	switch (listentyp) {
		case ALLES:
			printListe(vecFahrradKatalog);
			break;
		case TEIL:
			printListe(vecSuchergebnisse);
	}
}

void FahrradLaden::sucheMarke(string _marke) {
	int i = 0;
	string marke;
	vecSuchergebnisse.clear();

	for (int i = 0; i < _marke.size(); i++) {
		_marke.at(i) = tolower(_marke.at(i));
	}

	for (int i = 0; i < vecFahrradKatalog.size(); i++) {
		marke = vecFahrradKatalog.at(i).getMarke();
		for (int i = 0; i < marke.size(); i++) {
			marke.at(i) = tolower(marke.at(i));
		}
		if (marke == _marke) {
			vecSuchergebnisse.push_back(vecFahrradKatalog.at(i));
		}
	}
	if (vecSuchergebnisse.size() == 0) cout << "Marke nicht im Katalog!\n";
}