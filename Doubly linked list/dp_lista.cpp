#include "dp_lista.h"

dp_lista::dp_lista(void)
{
	glava = rep = NULL;
}

dp_lista::~dp_lista(void)
{
	ocisti();
}

bool dp_lista::prazna() const
{
	return (glava == NULL || rep == NULL);
}

void dp_lista::dodaj_pocetak(Student _podatak)
{
	Cvor* novi = new Cvor;
	novi->podatak = _podatak;
	novi->prethodni = NULL;
	novi->sljedeci = glava;
	glava = novi;
	if (prazna())
		rep = glava;
	else
		glava->sljedeci->prethodni = glava;
}

void dp_lista::dodaj_kraj(Student _podatak)
{
	Cvor* novi = new Cvor;
	novi->podatak = _podatak;
	novi->prethodni = rep;
	novi->sljedeci = NULL;
	rep = novi;
	if (prazna())
		glava = rep;
	else
		rep->prethodni->sljedeci = rep;
}

Student dp_lista::uzmi_kraj()
{
	if (prazna()) {
		cout << "Greška: Lista je prazna!" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		Cvor* c = rep; // zapamtimo pokazivac na rep
		Student s = rep->podatak; // zapamtimo podatak na repu
		rep = rep->prethodni; // postavimo novi rep
		if (rep != NULL)
			rep->sljedeci = NULL; // prekidamo vezu sa repom
		else
			glava = NULL; // ako smo uzeli zadnji element
			//onda korigiramo i glavu
		delete c; // brismo stari rep
		return s; // vracamo podatak
	}
}

Student dp_lista::uzmi_pocetak()
{
	if (prazna()) {
		cout << "Greška: Lista je prazna!" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		Cvor* c = glava; // zapamtimo pokazivac na glavu
		Student s = glava->podatak; // zapamtimo podatak na glavi
		glava = glava->sljedeci; // postavimo novu glavu
		if (glava != NULL)
			glava->prethodni = NULL; // prekidamo vezu sa starom glavom
		else
			rep = NULL; // ako smo uzeli zadnji element
			//onda korigiramo i rep
		delete c; // brismo staru glavu
		return s; // vracamo podatak
	}
}

void dp_lista::ocisti()
{
	while (glava != NULL)
		Student s = uzmi_kraj();
}

void dp_lista::ispisi() const
{
	cout << " ** Popis studenata ** " << endl;
	for (Cvor* c = glava; c != NULL; c = c->sljedeci)
		cout << c->podatak.opis() << endl;
}

void dp_lista::ispisi_obrnuto() const
{
	cout << " ** Popis studenata ** " << endl;
	for (Cvor* c = rep; c != NULL; c = c->prethodni)
		cout << c->podatak.opis() << endl;
}

void dp_lista::ispis_pretili() const
{
	cout << " ** Pretili studenti ** " << endl;
	for (Cvor* c = glava; c != NULL; c = c->sljedeci)
		if (c->podatak.isPretili())
			cout << c->podatak.opis() << endl;
}

void dp_lista::brisi_pretile()
{
	Cvor* c = glava;
	while (c != NULL) {
		if (c->podatak.isPretili()) {
			if (c->prethodni != NULL)
				c->prethodni->sljedeci = c->sljedeci;
			else
				glava = c->sljedeci;

			if (c->sljedeci != NULL)
				c->sljedeci->prethodni = c->prethodni;
			else
				rep = c->prethodni;

			Cvor* brisemo = c;
			c = c->sljedeci;
			delete brisemo;
		}
		else
		{
			c = c->sljedeci;
		}
	}
}

void dp_lista::pretili_studenti() const
{
	cout << "*** Pretili studenti ***" << endl;
	for (Cvor* c = glava; c != NULL; c = c->sljedeci) {
		if (c->podatak.isPretili())
			cout << c->podatak.opis() << endl;
	}
	cout << endl;
}
