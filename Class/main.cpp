/*
Definirati klasu mobitel koja će imati sljedeće atribute:
- Naziv mobitela
- Cijena
- Memorija
- Potrebno definirati :
- konstruktor
- Destruktor
- Funkcije za upis podataka atributa i čitanje atributa
- Funkcija za ispis podataka o mobitelu
*/
#include "Mobitel.h";
#include <iostream>

int main()
{
    Mobitel m1 = Mobitel();
    m1.setCijena(199.99);
    m1.setMemorija(20);
    m1.setNaziv("Samsung Galaxy 21A");

    cout << m1.Opis();

    return 0;
}
