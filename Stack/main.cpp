// vjezba 4.cpp : Defines the entry point for the console application.
//Zadatak dodati funkciju inkrement koja uvecava sve elemente stoga za 1 INCREMENT ()
// i ispisati sve PARNI () elemente

/*
Napisati funkciju za invertiranje stoga ne mijenjajuci klasu
stog. Funkcija treba vratiti pokazivač na stog sa elementima
ulaznog stoga ali popunjenih obrnutim redoslijedom. Funkcija
ima sljededi potpis
stog* invertiraj_stog(stog*);
tj. funkciji se predaje pokazivač na postojedi stog i funkcija
vrada pokazivač na novi invertirani stog.
Primjer invertiranja stoga s:
s = *invertiraj_stog(&s);
*/

#include "Stog.h"
using namespace std;

void pisi_Stog(Stog* _s, tip_elementaT _t); //push
void prikazi_Stog(Stog* _s); //prikazi sadrzaj stoga
void citaj_Stog(Stog* _s); //pop
void parni(Stog* _s);
void inkrement(Stog* _s);
Stog* invertiraj_stog(Stog* _s);

int main()
{
	cout << "Kreiramo STOG" << endl;
	Stog s;
	prikazi_Stog(&s); //& referenca, da se ne prosljeđuju svi ?objekti?
	//punimo i praznimo stog
	pisi_Stog(&s, 10);
	pisi_Stog(&s, 15);
	pisi_Stog(&s, 77);
	pisi_Stog(&s, 3);
	pisi_Stog(&s, 4);
	pisi_Stog(&s, 7);
	pisi_Stog(&s, 6);
	/*s.ocisti();*/
	prikazi_Stog(&s);
	parni(&s);
	inkrement(&s);
	Stog* invertiraniS = invertiraj_stog(&s);
	prikazi_Stog(invertiraniS);
	system("PAUSE");
	return 0;
}

//prikaz stoga na ekran - mimo standardnih operacija
//trebamo posebna prava....
void prikazi_Stog(Stog* _s)
{
	cout << "\t\t\t\t";
	if (_s->vrh != NULL)
	{
		Cvor* c = _s->vrh;
		while (c != NULL)
		{
			cout << c->podatak << " ";
			c = c->sljedeci;
		}
	}
	else
		cout << "prazan stog";
	cout << "(" << _s->velicina() << ")" << endl; //velicina stoga
}

// pomocna funkcija za vracanje sa stoga i ispis na ekran
void citaj_Stog(Stog* _s)
{
	tip_elementaT temp; // privremena varijabla
	temp = _s->pop(); //uzmemo sa stoga
	cout << "Vracamo sa stoga " << temp << endl;
	prikazi_Stog(_s);
}

//pomocna funkcija za stavljanje na stog i ispis na ekran
void pisi_Stog(Stog* _s, tip_elementaT _t)
{
	_s->push(_t); // stavljamo na stog
	cout << "Stavljamo na stog: " << _t << endl;
	prikazi_Stog(_s);
}

void parni(Stog* _s)
{
	if (_s->vrh != NULL)
	{
		cout << "\nParni: ";
		Cvor* c = _s->vrh;
		while (c != NULL)
		{

			if (c->podatak % 2 == 0)
				cout << c->podatak << " ";

			c = c->sljedeci;
		}
	}
}

void inkrement(Stog* _s)
{
	if (_s->vrh != NULL)
	{
		Cvor* c = _s->vrh;
		cout << "\nInkrementirano: ";
		while (c != NULL)
		{
			c->podatak = c->podatak + 1;

			cout << c->podatak << " ";

			c = c->sljedeci;
		}
	}
}

Stog* invertiraj_stog(Stog* _s) {
	Stog* invertiraniStog = new Stog(); // Stvaramo novi stog za invertirane elemente

	// Iteriramo kroz originalni stog i premještamo elemente na invertirani stog
	while (!_s->prazan()) {
		tip_elementaT podatak = _s->pop(); // Uzimanje elementa s originalnog stoga
		invertiraniStog->push(podatak); // Stavljanje elementa na invertirani stog
	}

	return invertiraniStog; // Vraćamo pokazivač na invertirani stog
}
