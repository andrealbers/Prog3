#pragma once

using namespace std;

class klasse
{
public:
	klasse();
	klasse(int preis, float modell);
	~klasse() {};
	void ausgabe();

	const int getPreis();
	const float getModell();

private:
	int preis;
	float modell;
};

