#pragma once
#include <string>
using namespace std;




class Fahrrad {
public:
	Fahrrad(string marke, string modell, int modellJahr, double preis);

	Fahrrad* cloneFahrrad(Fahrrad* fp) { return fp->clone(); }  //UBERPRUFEN

	~Fahrrad() {};

	void nenneMarkeModell(void)const;
	Fahrrad* clone() { nenneMarkeModell; }

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

class MTB : public Fahrrad {
public:
	MTB(string marke, string modell, int modellJahr, double preis) : Fahrrad(marke, modell, modellJahr, preis) {}
	~MTB() {};

protected:

private:

};

class E_Bike : public Fahrrad {
public:
	E_Bike(string marke, string modell, int modellJahr, double preis, int _kapazitat) : Fahrrad(marke, modell, modellJahr, preis), kapazitat(_kapazitat) {}
	~E_Bike() {};

	int getKapazitat()const { return kapazitat; }
protected:

private:
	int kapazitat;
};