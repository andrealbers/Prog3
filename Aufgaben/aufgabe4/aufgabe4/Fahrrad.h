#pragma once
#include <string>
#include <map>
using namespace std;


class Fahrrad {
public:
	Fahrrad(string marke, string modell, int modellJahr, double preis);

	virtual ~Fahrrad() {};

	void nenneMarkeModell(void)const;

	Fahrrad* cloneFahrrad(Fahrrad* fp) { return fp->clone(); }
	virtual Fahrrad* clone() { return new Fahrrad(*this); }
	virtual void ausgeben() {};

	string  getMarke()const { return marke; }
	string  getModell()const { return modell; }
	int  getModellJahr()const { return modellJahr; }
	double  getPreis()const { return preis; }

	virtual map<string, string> getProperties() const;

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

	virtual void ausgeben();
	//virtual MTB* clone() { return new MTB(*this); }
protected:

private:

};

class E_Bike : public Fahrrad {
public:
	E_Bike(string marke, string modell, int modellJahr, double preis, int _kapazitat) : Fahrrad(marke, modell, modellJahr, preis), kapazitat(_kapazitat) {}
	~E_Bike() {};

	virtual E_Bike* clone() { return new E_Bike(*this); };
	virtual map<string, string> getProperties() const;

	virtual void ausgeben();
	int getKapazitat()const { return kapazitat; }

protected:

private:
	int kapazitat;
};