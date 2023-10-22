#include "Krug.h"
#include "Pravokutnik.h"
#include "Mobitel.h"
#include <iostream>

int main()
{
    Krug k1 = Krug(10);
    Krug k2, k3, k4;
    cout << k1.Opis() << endl;
    k2.setPovrsina(100);
    cout << k2.Opis() << endl;
    k3.setOpseg(50);
    cout << k3.Opis() << endl;
    k4.setRadius(10);
    cout << k4.Opis() << endl;

    Pravokutnik p1 = Pravokutnik();
    cout << p1.Opis();
    p1.setSirina(45.78);
    p1.setVisina(15.89);
    cout << p1.Opis();
    if (p1.isKvadrat() == 1) {
        cout << "Pravokutnik je ujedno i kvadrat." << endl;
    }
    else {
        cout << "Pravokutnik nije kvadrat." << endl;
    }
    p1.setVisina(45.78);
    if (p1.isKvadrat() == 1) {
        cout << "Pravokutnik je ujedno i kvadrat." << endl;
    }
    else {
        cout << "Pravokutnik nije kvadrat." << endl;
    }

    Pravokutnik p2 = Pravokutnik(12.87, 32.47);
    cout << p2.Opis();

    Pravokutnik p3 = Pravokutnik(5.78, 2.36);
    cout << p3.Opis();

    Mobitel m1 = Mobitel();
    m1.setCijena(199.99);
    m1.setMemorija(20);
    m1.setNaziv("Samsung Galaxy 21A");
    cout << m1.Opis();

    system("PAUSE");
    return 0;
}
