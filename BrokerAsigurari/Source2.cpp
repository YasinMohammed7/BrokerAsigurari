//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// relatia unu la multi
//
//class Participant {
//private:
//	int varsta;
//public:
//	Participant() :varsta(10){}
//
//	friend class VideoConferinta;
//
//	int getVarsta() {
//
//		return varsta;
//	}
//};
//
//class VideoConferinta {
//	int nrParticipanti;
//	Participant* participanti;
//public:
//	VideoConferinta() {
//		this->nrParticipanti = 10;
//		this->participanti = new Participant[this->nrParticipanti];
//		for (int i = 0; i < nrParticipanti; i++)
//		{
//			this->participanti[i].varsta = i + 10;
//		}
//	}
//
//	~VideoConferinta() {
//		if (this->participanti != nullptr) {
//			delete[] this->participanti;
//		}
//	}
//
//	friend ostream& operator<<(ostream& out, VideoConferinta& v) {
//		out << "Numar participanti: " << v.nrParticipanti << endl;
//		for (int i = 0; i < v.nrParticipanti; i++)
//		{
//			out << i + 1 << ". " << v.participanti[i].getVarsta() << endl;
//		}
//
//		return out;
//	}
//};
//
//int main() {
//	VideoConferinta v1;
//
//	cout << v1;
//}