#include "Stog.h"

//konstruktor
Stog::Stog(void) {
	koliko = 0;
	vrh = NULL;
}

//destruktor
Stog::~Stog(void) {
	ocisti();
}

//vraca velicinu stoga
int Stog::velicina() const
{
	return koliko;
}

//vraca true ako je stog prazan
bool Stog::prazan() const
{
	return koliko == 0;
}

//stavljanje na stog
void Stog::push(tip_elementaT _podatak)
{
	Cvor* novi = new Cvor; // kreiramo novi cvor
	novi->podatak = _podatak; // dodajemo podatak u cvor
	novi->sljedeci = vrh; // novi gleda na prethodni
	vrh = novi; // novi cvor postaje novi vrh stoga
	koliko++; // povecamo brojac elemenata na stogu
}

tip_elementaT Stog::pop()
{
	if (!prazan()) {
		tip_elementaT _podatak = vrh->podatak; // zapamtimo podatak
		Cvor* c = vrh->sljedeci; // zapamtimo novi vrh
		delete vrh; //obrisemo stari vrh
		vrh = c; //postavljamo novi vrh
		koliko--; // smanjimo brojac elemenata na stogu
		return _podatak; // vratimo podatak sa stoga
	}
	else {
		cout << "GREŠKA: Stog je prazan!" << endl;
		return NULL;
	}
}

//cisti stog
void Stog::ocisti()
{
	while (vrh != NULL)
		tip_elementaT _podatak = pop(); //uzimamo sa stoga dok ima
}

