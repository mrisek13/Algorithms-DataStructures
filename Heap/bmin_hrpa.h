#pragma once 
#include <iostream> 
#include <string> 

using namespace std;

#define MAX_CVOROVA 1000 //maksimalna velicina polja 

typedef string tip_podatkaT; //tip podatka u hrpi 

//binarna min hrpa 
class bmin_hrpa
{
	int elemenata; //broj elemenata u polju
	tip_podatkaT* podaci; //polje podataka za hrpu

	//privatne funkcije 
	int lijevo_dijete(int indeks) const { return 2 * indeks + 1; } //vraca indeks lijevog djeteta 
	int desno_dijete(int indeks) const { return 2 * indeks + 2; } //vraca indeks desnog djeteta 
	int tata(int indeks) const { return (indeks - 1) / 2; } //vraca indeks tate 
	void slozi_hrpu_gore(int _pozicija); // preslozi hrpu od lista 
	void slozi_hrpu_dolje(int _pozicija); // preslozi hrpu od korijena 

public:
	bmin_hrpa(void) { elemenata = 0; podaci = new tip_podatkaT[MAX_CVOROVA]; } //konstruktor 
	~bmin_hrpa(void) { delete[]podaci; } //destruktor 
	bool prazna() const { return elemenata == 0; } //vraca ako je hrpa prazna 
	bool puna() const { return elemenata == MAX_CVOROVA; } //vraca ako je hrpa puna 
	int velicina() const { return elemenata; } //vraca broj cvorova na hrpi 
	void dodaj(tip_podatkaT _podatak); //dodaje novi element u hrpu 
	tip_podatkaT brisi_min(); //brise korijen hrpe 
	//ispis standardni 
	void ispisi_po_indeksu() const;

	//dodatni zadaci - funkcije se pozivaju se sa indeksom 0 za ispis cijelog stable 
	void ispisi_preorder(int index) const;
	void ispisi_postorder(int index) const;
	void ispisi_inorder(int index) const;
};
