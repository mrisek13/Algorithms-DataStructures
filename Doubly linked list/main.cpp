#include "dp_lista.h"
int main()
{
	dp_lista l;
	Student s("Marko", 176, 95);
	//testiranje funkcija
	l.dodaj_pocetak(s);
	s = l.uzmi_kraj();
	l.dodaj_kraj(s);
	s = l.uzmi_pocetak();
	l.ispisi(); //treba biti prazna
	//napunimo listu
	l.dodaj_kraj(s);
	l.dodaj_kraj(Student("Jura", 181, 75));
	l.dodaj_kraj(Student("Igor", 196, 119));
	l.dodaj_pocetak(Student("Ida", 82, 14));
	l.ispisi();
	l.ispisi_obrnuto();
	l.pretili_studenti();
	//brisimo pretile
	cout << "Brisemo pretile iz liste..." << endl << endl;
	l.brisi_pretile();
	l.ispisi();
	//ocistimo listu
	cout << "Ocistimo listu..." << endl << endl;
	l.ocisti();
	l.ispisi();
	system("pause");
	return 0;
}
