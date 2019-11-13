#pragma once
#include <vector>
#include "fahrrad.h"

using namespace std;

class FahrradLaden
{
public:
	FahrradLaden();
	~FahrradLaden() {};

	void vectorAusgabe(int listentyp);
	void sucheMarke(string _marke);
protected:

private:
	vector<Fahrrad> vecFahrradKatalog;
	vector<Fahrrad> vecSuchergebnisse;
};

