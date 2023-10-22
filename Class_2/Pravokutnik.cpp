#include "Pravokutnik.h"

Pravokutnik::Pravokutnik(void)//konstruktor koji kreira objekt, nije definirana velicina Pravokutnika
{
	visina = 0;
	sirina = 0;
}

Pravokutnik::Pravokutnik(double _visina, double _sirina)//e tu je velicina Pravokutnika definirana
{
	visina = _visina;
	sirina = _sirina;
}

Pravokutnik::~Pravokutnik(void)//destruktor ima tildu
{
}

double Pravokutnik::getPovrsina() const
{
	return visina * sirina;
}

double Pravokutnik::getOpseg() const
{
	return 2 * visina * sirina;
}

double Pravokutnik::getVisina() const
{
	return visina;//funkcija vraca vrijednost varijable
}

void Pravokutnik::setVisina(double _visina)
{
	visina = _visina;//postavlja vrijednost varijable
}

double Pravokutnik::getSirina() const
{
	return sirina;//funkcija vraca vrijednost varijable
}

void Pravokutnik::setSirina(double _sirina)
{
	sirina = _sirina;//postavlja vrijednost varijable
}

string Pravokutnik::Opis() const
{
	stringstream ss;
	ss << "Pravokutnik - Visina = " << getVisina() <<
		", Sirina = " << getSirina() <<
		", Opseg = " << getOpseg() <<
		", Povrsina = " << getPovrsina() << endl;
	return ss.str();
}

bool Pravokutnik::isKvadrat()
{
	if (visina == sirina)
	{
		return true;
	}
	else {
		return false;
	}
}