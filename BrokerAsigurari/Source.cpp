//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class BrokerAsigurari {
//private:
//	bool* asigurariValide;
//	int nrAsigurari;
//	char* numeAsigurat;
//	int valAsigurare;
//	static int comision;
//	string tipAsigurare;
//public: 
//
//	BrokerAsigurari() {
//		this->numeAsigurat = new char[strlen("N/A") + 1];
//		strcpy_s(this->numeAsigurat, strlen("N/A") + 1, "N/A");
//		this->valAsigurare = 0;
//		this->tipAsigurare = "N/A";
//		this->nrAsigurari = 0;
//		this->asigurariValide = NULL;
//	}
//
//	BrokerAsigurari(const char* numeAsigurat, int valAsigurare, string tipAsigurare, int nrAsigurari, const bool* asigurariValide) {
//		this->numeAsigurat = new char[strlen(numeAsigurat) + 1];
//		strcpy_s(this->numeAsigurat, strlen(numeAsigurat) + 1, numeAsigurat);
//		this->valAsigurare = valAsigurare;
//		this->tipAsigurare = tipAsigurare;
//		this->nrAsigurari = nrAsigurari;
//		this->asigurariValide = new bool[nrAsigurari];
//		for (int i = 0; i < nrAsigurari; i++)
//		{
//			this->asigurariValide[i] = asigurariValide[i];
//		}
//	}
//
//	BrokerAsigurari(const BrokerAsigurari& b) {
//		this->numeAsigurat = new char[strlen(b.numeAsigurat) + 1];
//		strcpy_s(this->numeAsigurat, strlen(b.numeAsigurat) + 1, b.numeAsigurat);
//		this->valAsigurare = b.valAsigurare;
//		this->tipAsigurare = b.tipAsigurare;
//		this->nrAsigurari = b.nrAsigurari;
//		this->asigurariValide = new bool[b.nrAsigurari];
//		for (int i = 0; i < b.nrAsigurari; i++) 
//		{
//			this->asigurariValide[i] = b.asigurariValide[i];
//		}
//	}
//
//	~BrokerAsigurari() {
//		if (this->numeAsigurat != NULL) {
//			delete this->numeAsigurat;
//		}
//		if (this->asigurariValide != NULL)
//		{
//			delete[] this->asigurariValide;
//		}
//	}
//
//	string getTipAsigurare() {
//		return tipAsigurare;
//	}
//
//	BrokerAsigurari& operator=(const BrokerAsigurari& b) {
//		if (this != &b) {
//			if (this->numeAsigurat != NULL) {
//				delete this->numeAsigurat;
//			}
//			if (this->asigurariValide!=NULL)
//			{
//				delete[] this->asigurariValide;
//			}
//
//			this->numeAsigurat = new char[strlen(b.numeAsigurat) + 1];
//			strcpy_s(this->numeAsigurat, strlen(b.numeAsigurat) + 1, b.numeAsigurat);
//			this->valAsigurare = b.valAsigurare;
//			this->tipAsigurare = b.tipAsigurare;
//			this->nrAsigurari = b.nrAsigurari;
//			this->asigurariValide = new bool[b.nrAsigurari];
//			for (int i = 0; i < b.nrAsigurari; i++)
//			{
//				this->asigurariValide[i] = b.asigurariValide[i];
//			}
//		}
//		return *this;
//	}
//
//	friend ostream& operator<<(ostream& out, const BrokerAsigurari& b) {
//		out << "Nume asigurat: " << b.numeAsigurat << endl;
//		out << "Valoare asigurare: " << b.valAsigurare << endl;
//		out << "Comision: " << b.comision << endl;
//		out << "Tipul asigurarii: " << b.tipAsigurare << endl;
//		out << "Nr asigurari: " << b.nrAsigurari << endl;
//		out << "Asigurari valide: " << endl;
//		for (int i = 0; i < b.nrAsigurari; i++)
//		{
//			out << i + 1 << ". " << b.asigurariValide[i] << endl;
//		}
//		
//		return out;
//	}
//
//	friend istream& operator>>(istream& input, BrokerAsigurari& b) {
//		
//		cout << "Nume asigurat: ";
//		char buffer[50];
//		input >> ws;
//		input.getline(buffer, 49);
//		if (b.numeAsigurat != NULL) {
//			delete b.numeAsigurat;
//		}
//		b.numeAsigurat = new char[strlen(buffer) + 1];
//		strcpy_s(b.numeAsigurat, strlen(buffer) + 1, buffer);
//		cout << "Valoare asigurare: ";
//		input >> b.valAsigurare;
//		cout << "Tipul asigurarii: ";
//		input >> ws; // Clear leading whitespace
//		getline(input, b.tipAsigurare);
//
//		return input;
//	}
//
//	explicit operator double() {
//		return this->valAsigurare;
//	}
//
//	int operator()(int cursVal) {
//		int val = this->valAsigurare / cursVal;
//		return val;
//	}
//
//	BrokerAsigurari operator+(const BrokerAsigurari& b)const {
//		BrokerAsigurari temp = *this;
//		temp.valAsigurare += b.valAsigurare;
//		return temp;
//	}
//
//	BrokerAsigurari operator++() {
//		this->valAsigurare++;
//		return *this;
//	}
//
//	BrokerAsigurari operator++(int) {
//		BrokerAsigurari temp = *this;
//		this->valAsigurare++;
//		return temp;
//	}
//
//	BrokerAsigurari* operator->() {
//		this->tipAsigurare = "Auto";
//		return this;
//	}
//};
//
//int BrokerAsigurari::comision = 10;
//
//int main() {
//	BrokerAsigurari b1;
//
//	int nrAsigurari = 3;
//
//	bool* asigurariValide = new bool[nrAsigurari] {1, 0, 1};
//
//	BrokerAsigurari b2("Alex", 30, "Sanatate", nrAsigurari, asigurariValide);
//	cout << b2 << endl;
//	cin >> b2;
//	cout << b2;
////
////	BrokerAsigurari b3 = b2;
////
////	cout << b3 << endl;
////
////	b1 = b3;
////
////	cout << b1 <<endl;
////	double valoareAsigurare = (double)b2;
////	cout << valoareAsigurare << endl;
////
////	cout << b1(5)<<endl;
////	
////	b3 = b1 + b2;
////
////	cout << b3 << endl;
////	/*cout << b3.getObj() << endl;*/
////
////	//++b1;
////	b1++;
////	cout << b1 << endl;
////	cout << b2->getTipAsigurare() << endl;
////
//	delete[] asigurariValide;
//}