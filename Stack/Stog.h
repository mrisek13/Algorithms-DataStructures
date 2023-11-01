#pragma once
#include <iostream>
using namespace std;

//tip podataka elemenata stoga
typedef int tip_elementaT;

//element stoga
struct Cvor {
	tip_elementaT podatak; // podatak na stogu
	struct Cvor* sljedeci; // pokazivac na prethodni cvor
};

class Stog
{
	int koliko; // broj elemenata na stogu
public:
	Cvor* vrh; // pokazivac na vrh stoga
	//osnovne operacije
	int velicina() const; // vraca velicinu stoga
	bool prazan() const; // vraca true ako je stog prazan
	void push(tip_elementaT _podatak); // stavljanje na stog
	tip_elementaT pop(); // uzimanje sa stoga
	//izvedene funkcije
	void ocisti(); //cisti stog
	//konstruktor i destrukotr
	Stog(void);
	~Stog(void);
};
