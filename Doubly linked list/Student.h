#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// klasa student (tip podatka elementa liste)
// ovo je jednostavna klasa te je deklaracija klase ujedno i definicija
// funkcijski članovi definirani su unutar deklaracije klase
// uvijek su umetnuti bez eksplicitnog korisštenja ključne riječi
// inline

class Student
{
	string ime;
	int visina_cm;
	int tezina_kg;
public:
	// konstruktori - treba nam i inicijalni konstruktor bez parametara
	// on se poziva kod kreiranja novog cvora, prilikom pozivanja
	// podrazumjevanog konstruktora cvora, kojemu je student jedan od clanova
	Student(void) {}
	Student(string _ime, int _visina_cm, int _tezina_kg);
	~Student(void) {}
	float BMI() const;
	bool isPretili() const;
	string opis() const;
};

