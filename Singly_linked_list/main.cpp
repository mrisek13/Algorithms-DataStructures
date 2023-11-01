#include <iostream>
#include "lista.h"
int main()
{
	Lista l; //deklaracija liste na stogu
	Lista* l1 = new Lista; //dinamičko definiranje liste
	//alternative korištenja dinamički definirane klase
	(*l1).ocisti();
	l1->ocisti();
	//igrajmo se s listom, ispisimo praznu listu
	l.brisi(0); //brisemo praznu za test
	l.dodaj("Jura", 0); //dodajemo nulti član u praznu listu
	l.brisi(0); //brisemo nulti član
	l.ispisi();
	cout << "Broj elemenata u listi: " << l.velicina() << endl;
	l.ocisti(); //ocistimo
	l.ucitaj_test(); //ucitajmo ponovno iz datoteke
	//malo rucno punimo
	l.dodaj("Tomi");
	l.dodaj("Drazen", 0);
	l.dodaj("Luka", 2);
	l.dodaj("Kruno", 9);
	l.brisi(8);
	l.ispisi();
	cout << "Broj elemenata u listi: " << l.velicina() << endl;
	cout << "Element 0: " << l.vrati(0) << endl;
	cout << "Element 5: " << l.vrati(5) << endl;
	cout << "Element 999: " << l.vrati(999) << endl;
	//dodatni zadatak - kombinacija dvije funkcije liste vraca posljednji element liste
	l.ocisti();
	l.ucitaj_test();
	cout << "Posljednji element liste: " << l.vrati(l.velicina() - 1) << endl;

	Lista test;
	test.ucitaj_test();
	cout << "Velicina testne liste: " << test.velicina() << endl;
	cout << "Posljednji element liste: " << test.vrati(test.velicina() - 1) << endl;

	system("pause");
	return 0;
}
