#include <iostream>

using namespace std;

class reteleSociale {
private:
	string email;
	int nrPrieteni;
	const int id;
protected:
	string* numePrieteni;
public:
	static int nrRetele;

	reteleSociale():id(++nrRetele) {
		this->email = "N/A";
		this->nrPrieteni = 0;
		this->numePrieteni = nullptr;
	}

	reteleSociale(const string* numePrieteni, string email, int nrPrieteni):id(++nrRetele) {
		this->email = email;
		this->nrPrieteni = nrPrieteni;
		this->numePrieteni = new string[nrPrieteni];
		for (int i = 0; i < nrPrieteni; i++)
		{
			this->numePrieteni[i] = numePrieteni[i];
		}
	}

	~reteleSociale() {
		if (this->numePrieteni != nullptr) {
			delete[] this->numePrieteni;
		}
	}

	string getEmail() {
		return email;
	}

	void setEmail(string newEmail) {
		if (email.size() > 8) {
			this->email = newEmail;
		}
	}

	string& operator[](string numePrieten){
		for (int i = 0; i < nrPrieteni; i++)
		{
			if (this->numePrieteni[i] == numePrieten) {
				return this->numePrieteni[i];
			}
		}
			throw "Nu se afla nicio valoare in indexul selectat";
	}
};

int reteleSociale::nrRetele = 0;

int main() {
	int nrPrieteni = 4;
	string* numePrieteni = new string[nrPrieteni]{ "Andrei", "Alexandru", "Ion"};

	reteleSociale rs2(numePrieteni, "yasin@mail", nrPrieteni);

	rs2["Ion"] = "Alexandr";
	cout << rs2["Alexandr"]<< endl;



	delete[] numePrieteni;

}