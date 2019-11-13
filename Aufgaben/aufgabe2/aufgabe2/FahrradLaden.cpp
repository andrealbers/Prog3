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
		textdat.close();
		std::cout << "Anzahl eingelesender Elemente: " << vecFahrradKatalog.size() << endl;
	}
	else { std::cout << "Fehler beim Oeffnen der Datei!\n"; }
}

void FahrradLaden::vectorAusgabe(int listentyp) {
	
	switch(listentyp) {
		case 1:
			for (unsigned int i = 0; i < vecFahrradKatalog.size(); i++) {
				vecFahrradKatalog.at(i).nenneMarkeModell();
			}
			break;
		case 2:
			for (unsigned int i = 0; i < vecSuchergebnisse.size(); i++) {
				vecSuchergebnisse.at(i).nenneMarkeModell();
			}
			break;
		default:
			cout << "Fehler bei der Uebergabe von listentyp an vectorAusgabe!" << endl;
	}			
}

void FahrradLaden::sucheMarke(string _marke) {
	int i = 0;
	
	for (int i = 0; i < _marke.size(); i++) {
		_marke.at(i) = tolower(_marke.at(i));
	}
	_marke.at(0) = toupper(_marke.at(0));

	for (int i = 0; i < vecFahrradKatalog.size(); i++) {
		if (vecFahrradKatalog.at(i).getMarke() == _marke) {
			vecSuchergebnisse.push_back(vecFahrradKatalog.at(i));
		}
	}	
}