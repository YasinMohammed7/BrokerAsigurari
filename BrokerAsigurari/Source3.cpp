#include <iostream>
#include <string>

using namespace std;

class Marker {
	char* denumire;
	string culoare;
	int dimensiune;
public:
	Marker() {
		this->culoare = "N/A";
		this->denumire = new char[strlen("N/A") + 1];
		strcpy_s(this->denumire, strlen("N/A") + 1, "N/A");
		this->dimensiune = 0;
	}
	Marker(string culoare, const char* denumire, int dimensiune) {
		this->culoare = culoare;
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		this->dimensiune = dimensiune;
	}

	Marker(const Marker& m) {
		this->culoare = m.culoare;
		this->denumire = new char[strlen(m.denumire) + 1];
		strcpy_s(this->denumire, strlen(m.denumire) + 1, m.denumire);
		this->dimensiune = m.dimensiune;
	}

	friend ostream& operator<<(ostream& out, const Marker& m) {
		out << m.culoare << endl;
		out << m.denumire << endl;
		out << m.dimensiune << endl;

		return out;
	}

	int getDimensiune() {
		return dimensiune;
	}
};

class EMarker:public Marker {
	int capacitateBaterie;
public:
	EMarker(string culoare, const char* denumire, int dimensiune, int capacitateBaterie):Marker(culoare, denumire, dimensiune) {
		this->capacitateBaterie = capacitateBaterie;
	}

	friend ostream& operator<<(ostream& out, const EMarker& em) {
		out << (Marker)em;
		out << em.capacitateBaterie << endl;

		return out;
	}
};

int main() {
	EMarker em("Albastru", "miria", 3, 20);
	cout << em;

}