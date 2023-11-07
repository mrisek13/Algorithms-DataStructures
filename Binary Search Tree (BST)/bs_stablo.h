#pragma once
#include <iostream>
using namespace std;

// cvor BST
struct cvor {
	int kljuc;
	cvor* lijevi, * desni;
	//konstruktor cvora
	cvor(int _kljuc) {
		kljuc = _kljuc;
		lijevi = desni = NULL;
	}
};

// binarno sortirano stablo
class bs_stablo
{
	cvor* korijen; // korijen stabla
	// privatne rekurzivne funkcije
	void obrisi(cvor* c); // ocisti podstablo
	void upisi(int _kljuc, cvor*& c); // upisi novi kljuc u podstablo
	bool sadrzi(int _kljuc, cvor* c) const; // da li podstablo sadržava kljuc
	int najveca_dubina(cvor* c) const; //vraca najvecu dubinu podstabla
	int broj_cvorova(cvor* c) const; //broj cvoroca podstabla
	void ispisi(int tip_ispisa, cvor* c) const; // 1-preorder, 2-postorder, 3- inorder
public:
	//konstruktor i destruktor
	bs_stablo();
	~bs_stablo();
	//operacije
	bool prazno() const; // vraca true ako je stablo prazno
	void upisi(int _kljuc); //upisuje novi kljuc u stablo
	bool sadrzi(int _kljuc) const; //vraca true kljuc postoji u stablu
	int najveca_dubina() const; // vraca najvecu dubinu stabla
	int broj_cvorova() const; // vraca broj cvorova stabla
	int najveci_kljuc() const; //vraca najveci kljuc (pomocu petlje)
	//razni ispisi stabla
	void ispisi_preorder() const;
	void ispisi_postorder() const;
	void ispisi_inorder() const;
};
