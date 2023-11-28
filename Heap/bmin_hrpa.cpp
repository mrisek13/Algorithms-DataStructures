#include "bmin_hrpa.h"

//dodaje novi element u hrpu 
void bmin_hrpa::dodaj(tip_podatkaT _podatak) {
	if (!puna()) {
		podaci[elemenata] = _podatak;
		slozi_hrpu_gore(elemenata);
		elemenata++;
	}
	else
		cout << "Greska: Hrpa je puna!" << endl;
}

//preslozi hrpu prema gore 
void bmin_hrpa::slozi_hrpu_gore(int indeks) {
	//tako dugo dok je dijete manje od tate mijenjaj sa tatom
	while ((indeks != 0) && (podaci[indeks] < podaci[tata(indeks)]))
	{
		swap(podaci[indeks], podaci[tata(indeks)]); //zamijeni tatu i dijete
		indeks = tata(indeks); //azuriraj trenutnu poziciju
	}
}

//brise korijen hrpe 
tip_podatkaT bmin_hrpa::brisi_min()
{
	if (!prazna())
	{
		elemenata--; //brisemo posljednji 
		if (elemenata != 0) // ako nismo obrisali korijen
		{
			swap(podaci[0], podaci[elemenata]); //stavimo korijen na kraj polja a kraj u korijen 
			slozi_hrpu_dolje(0); //promatramo dalje korijen i stavimo ga gdje treba 
		}
		return podaci[elemenata]; //vracamo korijen 
	}
	else
		return NULL;
}

//preslozi hrpu prema dolje 
void bmin_hrpa::slozi_hrpu_dolje(int indeks)
{
	int dijete = lijevo_dijete(indeks); //dijete je lijevo dijete 
	if (dijete > elemenata - 1) //ako dijete ne postoji izlazimo 
		return;
	if (desno_dijete(indeks) <= elemenata - 1) //ako postoji desno dijete 
		if (podaci[desno_dijete(indeks)] < podaci[dijete]) //i manje je od lijevog 
			dijete = desno_dijete(indeks); //onda je dijete desno dijete 
	if (podaci[indeks] <= podaci[dijete]) //ako je tata manji od djeteta onda izlazimo 
		return; swap(podaci[indeks], podaci[dijete]); //inace mijenjamo tatu i manje dijete 
	slozi_hrpu_dolje(dijete); // nastaljavamo dalje dok su zadovoljeni uvjeti 
}

void bmin_hrpa::ispisi_po_indeksu() const {
	cout << "HRPA: ";
	for (int i = 0; i < elemenata; i++)
		cout << podaci[i] << " ";
	cout << endl;
}

void bmin_hrpa::ispisi_preorder(int indeks) const
{
	if (indeks < elemenata)
	{
		cout << podaci[indeks] << " ";
		ispisi_preorder(lijevo_dijete(indeks));
		ispisi_preorder(desno_dijete(indeks));
	}
}

void bmin_hrpa::ispisi_postorder(int indeks) const
{
	if (indeks < elemenata)
	{
		ispisi_postorder(lijevo_dijete(indeks));
		ispisi_postorder(desno_dijete(indeks));
		cout << podaci[indeks] << " ";
	}
}

void bmin_hrpa::ispisi_inorder(int indeks) const
{
	if (indeks < elemenata)
	{
		ispisi_inorder(lijevo_dijete(indeks));
		cout << podaci[indeks] << " ";
		ispisi_inorder(desno_dijete(indeks));
	}
}
