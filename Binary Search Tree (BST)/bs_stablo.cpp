#include "bs_stablo.h"

// konstruktor
bs_stablo::bs_stablo()
{
	korijen = NULL;
}
//destruktor
bs_stablo::~bs_stablo()
{
	obrisi(korijen);
}

bool bs_stablo::prazno() const
{
	return korijen == NULL;
}

//private, rekurzivna obirisi
//predaje joj se pokazivac na podstablo koje brise
void bs_stablo::obrisi(cvor* c)
{
	if (c != NULL) // ako postoji cvor (kocnica za rekurziju)
	{
		obrisi(c->lijevi); // ocisti lijevo podstablo
		obrisi(c->desni); // ocisti desno podstablo
		delete c; // obrisi cvor
	}
}

//rekuzivna funkcija za upis novog kljuca u stablo
//posto pokazivac na cvor preuzimamo kao referencu
// mijenjanjem reference mijenjamo i originalni pokazivac
// koji je predat funkciji
void bs_stablo::upisi(int _kljuc, cvor*& c)
{
	if (c == NULL) // ako je cvor prazan kreiraj noci cvor
		c = new cvor(_kljuc);
	else // ili ako je novi kljuc manji od trenutnog
	{
		if (_kljuc < c->kljuc) // upisi lijevo
			upisi(_kljuc, c->lijevi);
		else // inace desno
			upisi(_kljuc, c->desni);
	}

}

//rekurzivno trazi kljuc u stablu
bool bs_stablo::sadrzi(int _kljuc, cvor* c) const
{
	if (c == NULL) // ako smo dosli do kraja stabla i nismo nista nasli
		return false;
	else {
		if (_kljuc == c->kljuc) //ako smo nasli kljuc
			return true;
		else
		{
			if (_kljuc < c->kljuc) // kreni lijevo
				return sadrzi(_kljuc, c->lijevi); //ispitaj lijevo podstablo
			else
				return sadrzi(_kljuc, c->desni); // ispitaj desno podstablo
		}
	}
}

//vraca najvecu dubinu cvora
int bs_stablo::najveca_dubina(cvor* c) const
{
	if (c == NULL)
		return 0;
	else
	{
		int lijeva_dubina = najveca_dubina(c->lijevi);
		int desna_dubina = najveca_dubina(c->desni);
		if (lijeva_dubina > desna_dubina)
			return lijeva_dubina + 1;
		else
			return desna_dubina + 1;
	}
}

//univerzalna funkcija za ispis stabla
//tip: 1- preorder, 2- postorder, 3- inorder
void bs_stablo::ispisi(int tip_ispisa, cvor* c) const
{
	if (c != NULL) // ako postoji cvor (kocnice za rekurziju)
	{
		if (tip_ispisa == 1) // preorder
			cout << c->kljuc << " ";
		ispisi(tip_ispisa, c->lijevi); // ispisi lijevo podstablo
		if (tip_ispisa == 3) // inorder
			cout << c->kljuc << " ";
		ispisi(tip_ispisa, c->desni); // ispisi lijevo podstablo
		if (tip_ispisa == 2) // postorder
			cout << c->kljuc << " ";
	}
}

//public upisi_kljuc, zove rekurzivnu upisi_kljuc i predaje joj korijen stabla
void bs_stablo::upisi(int _kljuc)
{
	upisi(_kljuc, korijen);
}
//public funkcija za trazenje kljuca, zove rekurziju
bool bs_stablo::sadrzi(int _kljuc) const
{
	return sadrzi(_kljuc, korijen);
}
//public - vraca najvecu dubinu stabla
int bs_stablo::najveca_dubina() const
{
	return najveca_dubina(korijen);
}

void bs_stablo::ispisi_preorder() const
{
	ispisi(1, korijen);
	cout << endl;
}
void bs_stablo::ispisi_postorder() const
{
	ispisi(2, korijen);
	cout << endl;
}
void bs_stablo::ispisi_inorder() const
{
	ispisi(3, korijen);
	cout << endl;
}

/// <summary>
/// Rekurzivna funkcija koja broji elemente u podstablu
/// </summary>
/// <param name="c">Početni čvor od kojeg se počinje brojati</param>
/// <returns>Broj čvorova u podstablu počevši od čvora 'c'</returns>
int bs_stablo::broj_cvorova(cvor* c) const {
	if (c == NULL) {
		return 0; // Ako je čvor prazan (null), nema čvorova u podstablu.
	}

	// Rekurzivno brojimo čvorove u lijevom i desnom podstablu te ih zbrojimo s glavnim čvorom.
	return 1 + broj_cvorova(c->lijevi) + broj_cvorova(c->desni);
}

/// <summary>
/// Public funkcija koja vraća broj elemenata u stablu
/// </summary>
/// <returns>Broj čvorova u cijelom stablu.</returns>
int bs_stablo::broj_cvorova() const {
	return broj_cvorova(korijen); // Pozivamo rekurzivnu funkciju s korijenom stabla kao početnom točkom.
}

/// <summary>
/// Funkcija koja vraća broj najveći ključ u stablu implementirana pomoću petlje(nije rekurzivna)
/// </summary>
/// <returns>Najveći ključ u stablu. Ako stablo nije sadržavalo nijedan čvor, vraća -1</returns>
int bs_stablo::najveci_kljuc() const {
	cvor* c = korijen;

	while (c && c->desni != NULL) {
		c = c->desni; // Pomaknite se udesno dok ne dođete do najdesnijeg čvora.
	}

	if (c != NULL) {
		return c->kljuc; // Vraćamo ključ najdesnijeg čvora koji predstavlja najveći ključ u stablu.
	}
	else {
		// Ako stablo nije sadržavalo nijedan čvor, možete vratiti neku zadanu vrijednost ili generirati iznimku ovisno o zahtjevima.
		// Ovdje ćemo vratiti -1 kao oznaku za neuspjeh.
		return -1;
	}
}
