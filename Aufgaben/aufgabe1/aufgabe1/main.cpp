#include <iostream>
#include <vector>

using namespace std;

void aufgabe1(void) {
	/*
	Welche Indizes sind erlaubt?
		Zugriff nur auf initialisierte Felder erlaubt | Bei Initialisierung: i > 0 | Sonst: i >=0
	Was passiert, wenn Sie beim Zugriff auf das Array einen zu gro�en oder zu kleinen Index verwenden (z.B. -1 oder 21)?
		Programm versucht auf einen nicht allozierten Speicherbereich zuzugreifen. Es wird irgendein Wert ausgegeben.
	Gibt es M�glichkeiten, zur Laufzeit die Gr��e des Arrays zu ver�ndern?
		int neugroesse;
		cin >> neugroesse;
		int *zahlen = malloc(neugroesse*sizeof(int));  //Abfangen bei neugroesse
	*/
	int zahlen[10];

	for (int i = 0; i < 10; i++) {									
		zahlen[i] = i + 1;
		cout << "zahlen[" << i << "] Wert: " << zahlen[i] << endl;
	}

	return;
}

void aufgabe2(void) {
	/*
	Welche Vorteile bieten new/delete gegen�ber malloc()/free() und was sind die Unterschiede?

	*/
	double* ptrZahlen = new double[10];
	cout << "Pointer auf Pointer Adresse: " << &ptrZahlen << endl;

	for (int i = 0; i < 10; i++) {
		ptrZahlen[i] = i * 1.1;
		cout << "ptrZahlen[" << i << "]" << " Adresse: " << &ptrZahlen[i] << ". Wert: " << ptrZahlen[i] << endl;
	}

	delete[] ptrZahlen;

	return;
}

void aufgabe3(void) {
	/*
	Erkl�ren Sie, was die folgenden Methoden bewirken: size(), at(), push_back().
		size(): Gibt Anzahl der beinhalteten Elemente an | at(): vector.at(3) -> R�ckgabe vom Wert von vector[3] | push_back(): Element wird am Ende des Vectors eingef�gt
	Welche Vorteile besitzt die Methode at() gegen�ber dem Zugriffoperator []?
		Bei �berschreitung des Wertebereichs des Vectors->Fehlermeldung. Nur Zugriff auf existierende Elemente des Vectors m�glich.
	Ist es bei einem vector m�glich, die Gr��e w�hrend der Laufzeit zu ver�ndern? Wenn ja, wie?
		vector.resize(5); oder vector.shrink_to_fit();
	*/
	vector<double> vectorzahlen(0);
	cout << "vectorzahlen Groesse vor Zuweisung: " << vectorzahlen.size() << endl;
	
	for (int i = 0; i < 10; i++) {
		vectorzahlen.push_back(i);
		cout << "vectorzahlen[" << i << "] Wert: " << vectorzahlen[i] << endl;
	}
	
	cout << "vectorzahlen Groesse nach Zuweisung: " << vectorzahlen.size() << endl;

	return;
}

int main(void) {
	cout << "**************************************************\nAufgabe 1:" << endl;
	aufgabe1();
	cout << "**************************************************\nAufgabe 2:" << endl;
	aufgabe2();
	cout << "**************************************************\nAufgabe 3:" << endl;
	aufgabe3();

	return 0;
}