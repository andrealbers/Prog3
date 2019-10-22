#include <vector>
#include "fahrrad.h"

using namespace std;

int main(void) {
	vector<Fahrrad> vecFahrrad;
	vecFahrrad.push_back(Fahrrad("Marke1", "Modell1", 2001, 1000.10)); //Fahrrad::Fahrrad(string marke, string modell, int modellJahr, double preis)
	vecFahrrad.push_back(Fahrrad("Marke2", "Modell2", 2002, 2000.20));
	vecFahrrad.push_back(Fahrrad("Marke3", "Modell3", 3003, 3000.30));
	
	//vecFahrrad.shrink_to_fit();
	for (int i = 0; i < vecFahrrad.size(); i++) {
		vecFahrrad.at(i).nenneMarkeModell();
	}

	return 0;
}
