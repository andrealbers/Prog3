#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>

void sortieren(vector<T>& vSortieren) {
	bool getauscht = true;
	int groeﬂe = vSortieren.size();

	if (groeﬂe == 0) return;
	else {
		while (getauscht == true) {
			getauscht = false;
				for (int i = 0; i < groeﬂe-1; i++) {
					if (vSortieren.at(i) > vSortieren.at(i + 1)) {
						swap(vSortieren.at(i), vSortieren.at(i + 1));
						getauscht = true;
					}
				}
		}
	}
}


template <typename T>

void printVector(T& vAusgabe) {
	for (int i = 0; i < vAusgabe.size(); i++) {
		cout << vAusgabe.at(i) << " ";
	}
	cout << "\n\n";
}

int main() {
	vector<int> vIZahlen;
	vector<double>vDZahlen;

	int intWerte;
	double doubleWerte, min = 1.0, max = 20.0;

	for (int i = 0; i < 20; i++) {
		intWerte = rand();
		doubleWerte = min + (static_cast<double>(rand()) / RAND_MAX)* max;
		vIZahlen.push_back(intWerte);
		vDZahlen.push_back(doubleWerte);
	}
	//vDZahlen = { 3.1, 1.7, 2.3, 4.4, 5.5 };

	cout << "Int-Vector vor der Sortierung" << endl;
	printVector(vIZahlen);
	//sort(vIZahlen.begin(), vIZahlen.end());
	sortieren(vIZahlen);
	cout << "Int-Vector nach der Sortierung" << endl;
	printVector(vIZahlen);


	cout << "\nDouble-Vector vor der Sortierung" << endl;
	printVector(vDZahlen);
	sortieren(vDZahlen);
	cout << "Double-Vector nach der Sortierung" << endl;
	printVector(vDZahlen);

	cout << "\n\n\n";
}