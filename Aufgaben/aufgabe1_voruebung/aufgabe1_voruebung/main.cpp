#include <iostream>
#include <vector>

using namespace std;

void aufgabe1(void) {
	/*
	Welche Indizes sind erlaubt?
		Zugriff nur auf initialisierte Felder erlaubt | Bei Initialisierung: i > 0 | Sonst: i >=0
	Was passiert, wenn Sie beim Zugriff auf das Array einen zu großen oder zu kleinen Index verwenden (z.B. -1 oder 21)?
		Programm versucht auf einen nicht allozierten Speicherbereich zuzugreifen. Es wird irgendein Wert ausgegeben.
	Gibt es Möglichkeiten, zur Laufzeit die Größe des Arrays zu verändern?
		int neugroesse;
		cin >> neugroesse;
		int *zahlen = malloc(neugroesse*sizeof(int));  //Abfangen bei neugroesse==NULL
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
	Welche Vorteile bieten new/delete gegenüber malloc()/free() und was sind die Unterschiede?

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
	Erklären Sie, was die folgenden Methoden bewirken: size(), at(), push_back().
		size(): Gibt Anzahl der beinhalteten Elemente an | at(): vector.at(3) -> Rückgabe vom Wert von vector[3] | push_back(): Element wird am Ende des Vectors eingefügt
	Welche Vorteile besitzt die Methode at() gegenüber dem Zugriffoperator []?
		Bei Überschreitung des Wertebereichs des Vectors->Fehlermeldung. Nur Zugriff auf existierende Elemente des Vectors möglich.
	Ist es bei einem vector möglich, die Größe während der Laufzeit zu verändern? Wenn ja, wie?
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
