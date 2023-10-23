#include "Artikl.h"
#include <iostream>

int main(int argc, char** argv)
{
    meni();
    system("PAUSE");	
	
	return 0;
}

void meni()
{
	vector<Artikl> artikli;
    int izbor = 0;
    do
    {
        system("cls"); // brisanje ekrana
        cout << "M E N I" << endl;
        cout << "1. Unos artikala u skladiste" << endl;
        cout << "2. Brisanje artikla sa skladista" << endl;
        cout << "3. Ispis svih artikala skladista" << endl;
        cout << "4. Provjera kolicine manje od 10" << endl;
        cout << "5. Brisanje svih artikala skladista" << endl;
        cout << "6. Skladiste" << endl
             << endl;
        cout << "7. Izlaz" << endl;
        cout << "Odaberi opciju menija:";
        cin >> izbor;
        switch (izbor)
        {
        case 1:
            upis(&artikli);
            break;
        case 2:
            brisiArtikl(&artikli);
            break;
        case 3:
            ispis(&artikli);
            break;
        case 4:
            provjeraKol(&artikli);
            break;
        case 5:
            brisanjeArtikli(&artikli);
            break;
        case 6:
            skladiste(&artikli);
            break;
        case 7:
            cout << "Kraj programa!" << endl;
            break;
        } // switch
    } while (izbor != 7);
}
