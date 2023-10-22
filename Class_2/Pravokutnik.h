#pragma once
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Pravokutnik
{
	double visina;
	double sirina;
public:
	double getVisina() const;
	double getSirina() const;
	void setVisina(double _visina);
	void setSirina(double _sirina);
	double getPovrsina() const;
	double getOpseg() const;
	bool isKvadrat();
	string Opis() const;
	//konstruktori i destruktor
	Pravokutnik(void);
	Pravokutnik(double _visina, double _sirina);
	~Pravokutnik(void);
};