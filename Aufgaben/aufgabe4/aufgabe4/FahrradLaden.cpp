#include "FahrradLaden.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <algorithm>

int getauscht = 0, verglichen = 0;

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

void printListe(const vector<Fahrrad*>& liste) {
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

	for (unsigned int i = 0; i < vecFahrradKatalog.size(); i++) {
		marke = vecFahrradKatalog.at(i)->getMarke();
		for (unsigned int i = 0; i < marke.size(); i++) {
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

	for (unsigned int i = 0; i < vecFahrradKatalog.size(); i++) {
		typ = typeid(*(vecFahrradKatalog.at(i))).name();
		typ = typ.substr(6, typ.size());

		for (unsigned int i = 0; i < typ.size(); i++) {
			typ.at(i) = tolower(typ.at(i));
		}

		if (typ == _typ) {
			map<string, string>mTyp = vecFahrradKatalog.at(i)->getProperties();

			for (map<string, string>::const_iterator it = mTyp.begin(), end = mTyp.end(); it != end; ++it) {
				cout << it->first << ": " << it->second << "    \t";
			}
			cout << endl;
		}
	}
}

void FahrradLaden::sucheModell(string _modell) {
	string modell;
	headerzeichnen();

	for (unsigned int i = 0; i < vecFahrradKatalog.size(); i++) vecFahrradKatalog.at(i)->ausgeben();

	/*
	for (unsigned int i = 0; i < _modell.size(); i++) {
		_modell.at(i) = tolower(_modell.at(i));
	}

	for (unsigned int i = 0; i < vecFahrradKatalog.size(); i++) {
		modell = vecFahrradKatalog.at(i)->getModell();
		for (unsigned int i = 0; i < modell.size(); i++) {
			modell.at(i) = tolower(modell.at(i));
		}
		if (modell == _modell) {
			headerzeichnen();
			vecFahrradKatalog.at(i)->ausgeben();
		}
	}   */
	cout << "\n\n";
}

bool vergleicheModelljahre(Fahrrad* a, Fahrrad* b) {
	if (a->getModellJahr() < b->getModellJahr()) getauscht++;
	verglichen++;
	return (a->getModellJahr() < b->getModellJahr());
}

void FahrradLaden::sortModelljahr() {
	getauscht = 0, verglichen = 0;
	sort(vecFahrradKatalog.begin(), vecFahrradKatalog.end(), vergleicheModelljahre);

	/*sort(vecFahrradKatalog.begin(), vecFahrradKatalog.end(), [](Fahrrad* erstes, Fahrrad* zweites) {
		return (erstes->getModellJahr() < zweites->getModellJahr());
		});*/

	cout << "Getauscht: " << getauscht << "  Verglichen: " << verglichen << endl;
}

void FahrradLaden::setPreis() {
	if (vecSuchergebnisse.size() == 0) return;

	cout << "\nGesuchte Marke rabattieren? Ja/Nein ";
	string eingabeRabattMarke;
	cin >> eingabeRabattMarke;

	for (unsigned int i = 0; (i < 1) && (i < eingabeRabattMarke.size()); i++) {
		eingabeRabattMarke.at(i) = tolower(eingabeRabattMarke.at(i));
	}

	if (eingabeRabattMarke != "ja") return;

	headerzeichnen();
	for (int i = 0; i < vecSuchergebnisse.size(); i++) vecSuchergebnisse.at(i)->ausgeben();

	cout << "\n\nUm wie viel Prozent rabattieren? ";
	double rabatt;
	cin >> rabatt;

	if ((rabatt < 100) && (rabatt > 0)) {
		string marke = vecSuchergebnisse.at(0)->getMarke();
		vecSuchergebnisse.clear();

		for (unsigned int i = 0; i < vecFahrradKatalog.size(); i++) {
			if (marke == vecFahrradKatalog.at(i)->getMarke()) {
				vecFahrradKatalog.at(i)->setPreisFahrrad(rabatt);
				vecSuchergebnisse.push_back(vecFahrradKatalog.at(i));
			}
		}

		headerzeichnen();
		for (int i = 0; i < vecSuchergebnisse.size(); i++) vecSuchergebnisse.at(i)->ausgeben();

		cout << "\n\n";
	}
	else cout << "Wert muss zwischen 0-100 liegen!" << endl;
}