#pragma once
#include <vector>
#include "fahrrad.h"

enum Auswahl {ALLES, TEIL};

class FahrradLaden
{
public:
	FahrradLaden();
	~FahrradLaden() {};

	void sortModelljahr();
	
	void vectorAusgabe(Auswahl listentyp);
	void sucheMarke(string _marke);
	void sucheTyp(string _typ);
	void sucheModell(string _modell);

protected:

private:
	vector<Fahrrad*> vecFahrradKatalog;
	vector<Fahrrad*> vecSuchergebnisse;
};

