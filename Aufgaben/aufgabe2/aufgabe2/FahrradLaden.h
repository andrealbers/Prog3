#pragma once
#include <vector>
#include "fahrrad.h"

enum Auswahl {ALLES, TEIL};

class FahrradLaden
{
public:
	FahrradLaden();
	~FahrradLaden() {};

	void vectorAusgabe(Auswahl listentyp);
	void sucheMarke(string _marke);
protected:

private:
	vector<Fahrrad> vecFahrradKatalog;
	vector<Fahrrad> vecSuchergebnisse;
};

