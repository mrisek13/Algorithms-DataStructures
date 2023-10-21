#include "Mobitel.h";

string Mobitel::getNaziv() const {
    return naziv;
}

void Mobitel::setNaziv(string naziv) {
    this->naziv = naziv;
}

double Mobitel::getCijena() const {
    return cijena;
}

void Mobitel::setCijena(double cijena) {
    this->cijena = cijena;
}

int Mobitel::getMemorija() const {
    return memorija;
}

void Mobitel::setMemorija(int memorija) {
    this->memorija = memorija;
}

Mobitel::Mobitel() {
    naziv = "";
    cijena = 0;
    memorija = 0;
}

Mobitel::Mobitel(string naziv, double cijena, int memorija) {
    this->naziv = naziv;
    this->cijena = cijena;
    this->memorija = memorija;
}

Mobitel::~Mobitel() {

}

string Mobitel::Opis() const{
    stringstream ss;
    ss << "Mobitel - naziv: " << getNaziv()
        << ", Cijena: " << getCijena() << "EUR"
        << ", Memorija: " << getMemorija() << "GB" << endl;

    return ss.str();
}