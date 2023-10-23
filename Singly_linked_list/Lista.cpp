#include "lista.h"

//konstruktor
Lista::Lista(void)
{
	glava = NULL;
}

//destruktor
Lista::~Lista(void)
{
	ocisti();
}

void Lista::dodaj(string podatak)
{
	//novi cvor
	Cvor* novi = new Cvor;
	novi->podatak = podatak;
	novi->sljedeci = NULL;
	if (glava == NULL) //ako je lista prazna
		glava = novi;
	else //ako nije prazna lista
	{
		Cvor* c = glava; //trenutni cvor s kojim radimo
		//idemo na kraj liste
		while (c->sljedeci != NULL)
			c = c->sljedeci;
		//dodajemo novi cvor na kraj liste
		c->sljedeci = novi;
	}
}

void Lista::dodaj(string podatak, int indeks)
{
	Cvor* c = glava; //trenutni cvor
	//novi cvor
	Cvor* novi = new Cvor;
	novi->podatak = podatak;
	if (indeks == 0) //ako je indeks 0
	{
		if (c == NULL) //ako je lista prazna
			novi->sljedeci = NULL;
		else
			novi->sljedeci = c;
		glava = novi;
	}
	else //ako nije indeks nula
	{
		//idemo do n-tog clana liste
		for (int i = 1; i < indeks; i++)
		{
			c = c->sljedeci;
			if (c == NULL)
			{
				cout << "Krivi indeks!" << endl;
				return;
			}
		}
		//dodajemo novi
		novi->sljedeci = c->sljedeci;
		c->sljedeci = novi;
	}
}

void Lista::brisi(int indeks)
{
	Cvor* p = NULL; //prethodni cvor
	int i = 0; //brojac
	//prekidamo for ako dodjemo do trazenog indeksa ili do kraja liste
	for (Cvor* c = glava; c != NULL && i <= indeks; c = c->sljedeci)
	{
		if (i == indeks) //kada dodjemo do zeljenog elemeta
		{
			if (p == NULL) //ako brisemo 0 element
			{
				if (c != NULL) //ako postoji glava
					glava = c->sljedeci;
			}
			else //ako ne brisemo 0 element
				p->sljedeci = c->sljedeci;
			delete c;
		}
		p = c; //pamtimo prethodni
		i++;
	}
}

void Lista::ocisti()
{
	//brisemo glavu dok ne doðemo do kraja liste
	while (glava != NULL)
	{
		Cvor* c = glava->sljedeci;
		delete glava;
		glava = c;
	}
}

//definicija funkcije ucitaj_listu
void Lista::ucitaj_test()
{
	string buff;
	ifstream ulazna; //input file stream
	ulazna.open("rijeci.txt");
	if (ulazna.is_open())
	{
		while (!ulazna.eof())
		{
			ulazna >> buff;
			dodaj(buff);
		}
		ulazna.close();
	}
}

void Lista::ispisi() const
{
	//idemo do kraja liste
	for (Cvor* c = glava; c != NULL; c = c->sljedeci)
	{
		if (c != glava)
			cout << ", ";
		cout << c->podatak;
	}
	cout << endl;
}

// Implementacija metode vrati u datoteci lista.cpp

string Lista::vrati(int indeks) const
{
	int i = 0;			// int i: trenutni index
	Cvor* c = glava;	// Cvor* c: trenutni cvor

	while (c != nullptr) {
		if (i == indeks) {
			return c->podatak;
		}
		c = c->sljedeci;
		i++;
	}

	return "Indeks prazan!";
}

int Lista::velicina() const
{
	int n = 0;			// broj elemenata
	Cvor* c = glava;	// Cvor* c: trenutni cvor

	while (c != nullptr) {
		n++;
		c = c->sljedeci;
	}

	return n;
}