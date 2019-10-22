#ifndef __FAHRRAD__
#define __FAHRRAD__

#include <string>

using namespace std;

class Fahrrad {
public:
	Fahrrad();
	Fahrrad(string marke, string modell, int modellJahr, double preis);
	void nenneMarkeModell();
	~Fahrrad();

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

#endif 