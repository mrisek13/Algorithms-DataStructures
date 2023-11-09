#pragma once
#include "Student.h"

// cvor DP liste
struct Cvor {
	Student podatak;
	Cvor* prethodni, * sljedeci;
};

//deklaracija DP liste
class dp_lista
{
	Cvor* glava, * rep; //pokazivaci na glavu i rep
public:
	// konstruktor i destruktor
	dp_lista(void);
	~dp_lista(void);
	// glavne funkcije
	bool prazna() const; // vraca true ako je lista prazna
	void dodaj_pocetak(Student _podatak); // dodaj na pocetak liste
	void dodaj_kraj(Student _podatak); // dodaj na kraj liste
	Student uzmi_pocetak(); // brise i vraca sa pocetka liste
	Student uzmi_kraj(); // brise i vraca sa kraja liste
	void ocisti(); // ocisti cijelu listu
	// ostale funkcije
	void ispisi() const; // ispisi listu studenata od glave do pete
	void ispisi_obrnuto() const; // ispisi od repa prema glavi

	void ispis_pretili() const; // ispis pretilih studenata
	void brisi_pretile(); // brisi pretile studente iz liste
	void pretili_studenti() const;
};

