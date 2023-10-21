#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Mobitel {
    string naziv;
    double cijena;
    int memorija;

public:
    string getNaziv() const;
    double getCijena() const;
    int getMemorija() const;
    void setNaziv(string naziv);
    void setCijena(double cijena);
    void setMemorija(int memorija);
    // Konstruktori i destruktor
    Mobitel();
    Mobitel(string naziv, double cijena, int memorija);
    ~Mobitel();

    string Opis() const;
};