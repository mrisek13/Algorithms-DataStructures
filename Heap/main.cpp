#include "bmin_hrpa.h"

int main()
{
	bmin_hrpa h;
	h.dodaj("Saturn");
	h.ispisi_po_indeksu();
	h.dodaj("Jupiter");
	h.ispisi_po_indeksu();
	h.dodaj("Zemlja");
	h.ispisi_po_indeksu();
	h.dodaj("Venera");
	h.ispisi_po_indeksu();
	h.dodaj("Neptun");
	h.ispisi_po_indeksu();
	h.dodaj("Merkur");
	h.ispisi_po_indeksu();
	h.dodaj("Uran");
	h.ispisi_po_indeksu();
	h.dodaj("Mars");
	h.ispisi_po_indeksu();

	//broj elemenata 
	cout << endl << "Na hrpi je " << h.velicina() << " elemenata" << endl << endl;

	//ispisi 
	cout << "PREORDER: ";
	h.ispisi_preorder(0);
	cout << endl << "POSTORDER: ";
	h.ispisi_postorder(0);
	cout << endl << "INORDER: ";
	h.ispisi_inorder(0);
	cout << endl << endl;
	cout << "Uzimamo korijen stabla dok postoji (sort A,Z)...";
	cout << endl << endl; //uzimamo i ispisujemo korijen 
	while (!h.prazna())
	{
		cout << h.brisi_min() << " ";
	}
	cout << endl << endl;
	//system("pause"); 

	return 0;
}
