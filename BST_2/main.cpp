#include <iostream>
#include <ctime>
#include "BsStablo.h"

using namespace std;

// funkcija koja generira long int slucajni broj
long int lrand() {
	return rand()*(RAND_MAX+1) + rand();
}

// razlika između dva vremena u ms
double diffclock(clock_t clock1, clock_t clock2) {
	double diffticks = clock1 - clock2;
	double diffms = (diffticks * 1000) / CLOCKS_PER_SEC;
	return diffms;
}

// funkcija koja stablo puni slucajnim long int brojevima u n iteracija
// u svakoj iteraciji se provjerava da li broj vec postoji u stablu
// dodaje se u spablo ako ne postoji
double generiraj_stablo(BsStablo* _s, long int _n) {
	clock_t begin = clock();
	for (long int i = 0; i < _n; i++) {
		long int r = lrand();
		if (!_s->sadrzi(r))
			_s->upisi(r);
	}
	clock_t end = clock();
	return diffclock(end, begin);
}

int main(int argc, char** argv) {
	BsStablo s;
	cout << "Upisimo nekoliko kljuceva u novu listu..." << endl;
	s.upisi(10);
	s.upisi(15);
	s.upisi(4);
	s.upisi(7);
	s.upisi(0);
	s.upisi(99);
	s.upisi(105);

	cout << "Ispisujemo listu preorder, postorder i inorder..." << endl << endl;
	s.ispisi_preorder();
	s.ispisi_postorder();
	s.ispisi_inorder();
	cout << endl;
	cout << "Najveca dubina je: " << s.najveca_dubina() << endl;
	cout << "Stablo sadrzi 7: " << s.sadrzi(7) << endl;
	cout << "Stablo sadrzi 20: " << s.sadrzi(20) << endl;
	cout << "Stablo je prazno: " << s.prazno() << endl << endl;

	cout << "Dodatni zadatak: " << endl;
	cout << "Broj cvorova: " << s.broj_cvorova() << endl;
	cout << "Najveci kljuc: " << s.najveci_kljuc() << endl << endl;
	
	cout << "Dodatak - analiza performansi" << endl;
	BsStablo s2;
	// upis 7 long int vrijednosti u stablo
	for (int i = 0; i < 7; i++) {
		s2.upisi(lrand());
	}
	cout << "Ispisujemo listu preorder, postorder i inorder..." << endl << endl;
	s2.ispisi_preorder();
	s2.ispisi_postorder();
	s2.ispisi_inorder();
	cout << endl;
	cout << "Najveca dubina je: " << s2.najveca_dubina() << endl;
	cout << "Stablo sadrzi 7: " << s2.sadrzi(7) << endl;
	cout << "Stablo sadrzi 20: " << s2.sadrzi(20) << endl;
	cout << "Stablo je prazno: " << s2.prazno() << endl << endl;
	
	cout << "Broj cvorova: " << s2.broj_cvorova() << endl;
	cout << "Najveci kljuc: " << s2.najveci_kljuc() << endl << endl;
	
	cout << "Dodatak - nastavak" << endl << endl;
		
	BsStablo* s3 = new BsStablo();
	long int n = 1000000; // Broj čvorova
	
	double elapsed_time = generiraj_stablo(s3, n);

	cout << "Broj cvorova: " << s3->broj_cvorova() << endl;
	cout << "Najveci kljuc: " << s3->najveci_kljuc() << endl;
	cout << "Najveca dubina je: " << s3->najveca_dubina() << endl;
	cout << "Vrijeme generiranja [ms]: " << elapsed_time << " ms" << endl;
}
