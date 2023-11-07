#include <iostream>
#include "bs_stablo.h"

int main()
{
	bs_stablo s;
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
	cout << "Stablo je prazno: " << s.prazno() << endl;

	cout << "Dodatni zadatak: " << endl;
	cout << "Broj cvorova: " << s.broj_cvorova() << endl;
	cout << "Najveci kljuc: " << s.najveci_kljuc() << endl;
}
