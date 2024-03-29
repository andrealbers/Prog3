#pragma once
#include <string>

using namespace std;

class Fahrrad {
public:
	Fahrrad(string marke, string modell, int modellJahr, double preis);
	~Fahrrad() {};
	
	void nenneMarkeModell(void)const;
	
	string  getMarke()const { return marke; }
	string  getModell()const { return modell; }
	int  getModellJahr()const { return modellJahr; }
	double  getPreis()const { return preis; }

protected:

private:
	string marke, modell;
	int modellJahr;
	double preis;
};