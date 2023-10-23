#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//element liste
struct Cvor
{
	string podatak; //podatak elementa liste
	Cvor* sljedeci; //pokazivac na sljedeci element liste
};

//deklaracija liste
class Lista
{
private:
	Cvor* glava; //pocetak, glava liste
public:
	void dodaj(string podatak); //dodaj na kraj liste
	void dodaj(string podatak, int indeks); //dodaj na neko mjesto
	void brisi(int indeks); //brisi neki element
	string vrati(int indeks) const; //vrati neki element
	int velicina() const; //broj elementata u listi
	void ocisti(); //ocisti listu
	Lista(void); //konstruktor
	~Lista(void); //destruktor
	//pomocne funkcije, strogo gledajuci ne pripadaju klasi lista
	//implementacija klase ne bi trebala imati veze sa suceljem aplikacije
	void ucitaj_test(); //ucitati testne podatke iz ulazne datoteke
	void ispisi() const; //ispisati elemente liste na ekran	
};