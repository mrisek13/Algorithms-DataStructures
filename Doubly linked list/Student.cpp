#include "Student.h"

Student::Student(string _ime, int _visina_cm, int _tezina_kg) {
	ime = _ime;
	visina_cm = _visina_cm;
	tezina_kg = _tezina_kg;
}
//indeks tjelesne mase - body mass index - BMI
float Student::BMI() const {
	return tezina_kg / pow((visina_cm / 100.0), 2);
}
//vraca true ako je student pretili
bool Student::isPretili() const {
	return BMI() >= 30;
}
//vraca opis studenta sa svim atributima
string Student::opis() const {
	string opis_pretili;
	if (isPretili())
		opis_pretili = "Pretili";
	else
		opis_pretili = "Nije pretili";
	stringstream ss;
	ss << ime << "\t" << visina_cm << "cm\t" << tezina_kg
		<< "kg\tBMI: " << BMI() << "\t" << opis_pretili << endl;
	return ss.str();
}