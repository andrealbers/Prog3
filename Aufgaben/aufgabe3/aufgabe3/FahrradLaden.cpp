#include "FahrradLaden.h"
#include <iostream>
#include <fstream>
#include <typeinfo>

FahrradLaden::FahrradLaden() {
	string leszeile, pfad = "fahrradliste.txt";
	ifstream textdat(pfad);
	string marke, modell, fahrradtyp;
	int modellJahr, kapazitat;  
	double preis;

	if (textdat.is_open()) {
		std::cout << "Datei " << pfad << " wurde geoeffnet!" << endl;

		while (!textdat.eof()) {
			int posnow = 0, posvorher = 0, welchesWort = 0, anzWorterLesen = 5;
			getline(textdat, leszeile);
			
			if (leszeile == "\0") {
				welchesWort = anzWorterLesen;
			}
			else {
				while (welchesWort < anzWorterLesen) {
					while ((leszeile[posnow] != ' ') && (leszeile[posnow] != NULL)) {
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
					case 4:
						fahrradtyp = wort;
						if (fahrradtyp == "E-Bike") anzWorterLesen = 6;
						break;
					case 5:
						kapazitat = stoi(wort);
						break;
					default:
						std::cout << "Fehler Anzahl Worter!" << endl;
					}
					welchesWort++;
					posnow++;
					posvorher = posnow;
				}
				if (fahrradtyp == "E-Bike") vecFahrradKatalog.push_back(new E_Bike(marke, modell, modellJahr, preis, kapazitat));
				else vecFahrradKatalog.push_back(new MTB(marke, modell, modellJahr, preis)); 				
			}
		}
		std::cout << "Anzahl eingelesender Elemente: " << vecFahrradKatalog.size() << endl;
	}
	else { std::cout << "Fehler beim Oeffnen der Datei!\n"; }
}

void printListe(const vector<Fahrrad*>&liste) {
	for (unsigned int i = 0; i < liste.size(); i++) {
		liste.at(i)->nenneMarkeModell();
	}
}

void FahrradLaden::vectorAusgabe(Auswahl listentyp) {
	switch (listentyp) {
		case ALLES:
			printListe(vecFahrradKatalog);
			break;
		case TEIL:
			printListe(vecSuchergebnisse);
			break;
	}
}

void FahrradLaden::sucheMarke(string _marke) {
	int i = 0;
	string marke;
	vecSuchergebnisse.clear();

	for (unsigned int i = 0; i < _marke.size(); i++) {
		_marke.at(i) = tolower(_marke.at(i));
	}

	for (int i = 0; i < vecFahrradKatalog.size(); i++) {
		marke = vecFahrradKatalog.at(i)->getMarke();
		for (int i = 0; i < marke.size(); i++) {
			marke.at(i) = tolower(marke.at(i));
		}
		if (marke == _marke) {
			vecSuchergebnisse.push_back(vecFahrradKatalog.at(i)->cloneFahrrad(vecFahrradKatalog.at(i)));
		}
	}
	if (vecSuchergebnisse.size() == 0) cout << "Marke nicht im Katalog!\n";
}

void FahrradLaden::sucheTyp(string _typ) {
	string typ;

	for (unsigned int i = 0; i < _typ.size(); i++) {
		_typ.at(i) = tolower(_typ.at(i));
	}

	for (int i = 0; i < vecFahrradKatalog.size(); i++) {
		typ = typeid(*(vecFahrradKatalog.at(i))).name();
		typ = typ.substr(6, typ.size());
		for (int i = 0; i < typ.size(); i++) {
			typ.at(i) = tolower(typ.at(i));
		}
		if (typ == _typ) {
			map<string, string>mTyp = vecFahrradKatalog.at(i)->cloneFahrrad(vecFahrradKatalog.at(i))->getProperties();
			
			//vector <pair<string, string>> vTyp(mTyp.begin(), mTyp.end());
			//for (int i = 0; i < vTyp.size(); i++) {
			//	
			//}
			
			for (map<string, string>::const_iterator it = mTyp.begin(), end = mTyp.end(); it != end; ++it) {
				cout << it->first << ": " << it->second << "    \t";
			}
			cout << endl;
		}
	}
}

