#include <iostream>
#include <string>
#include <vector>
#include "fahrrad.h"

using namespace std;
//Fahrrad::Fahrrad(string marke, string modell, int modellJahr, double preis)
int main(void) {
	vector<Fahrrad> vecFahrrad(0);
	vecFahrrad.push_back(Fahrrad("Marke1", "Modell1", 2003, 1000.1));

	vecFahrrad.at(0).nenneMarkeModell();
	return 0;
}