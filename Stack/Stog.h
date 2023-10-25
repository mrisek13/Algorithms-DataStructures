#pragma once
#include <iostream>
using namespace std;

//tip podataka elemenata stoga
typedef int tip_elementaT;

//element stoga
struct cvor {
	tip_elementaT podatak; // podatak na stogu
	struct cvor* sljedeci; // pokazivac na perthodni cvor
};

class Stog
{
	int koliko; // broj elemenata na stogu
public:
	cvor* vrh; // pokazivac na vrh stoga
	//osnovne operacije
	int velicina() const; // vraca velicinu stoga
	bool prazan() const; // vraca true ako je stog prazan
	void push(tip_elementaT _podatak); // stavaljanje na stog
	tip_elementaT pop(); // uzimanje sa stoga
	//izvedene funkicje
	void ocisti(); //cisti stog
	//konstruktor i destrukotr
	Stog(void);
	~Stog(void);
};