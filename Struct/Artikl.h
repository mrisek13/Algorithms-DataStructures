#include <cstring>
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
struct Artikl
{
    char naziv[20];
    char dobavljac[20];
    char mj[5];
    int kolicina;
    char proizvodjac[30]; // proizvođač
    double cijena;
};

void upis(vector<Artikl>* vec);            // upis artikla
void ispis(vector<Artikl>* vec);           // ispis svih artikla sa skladišta
void brisanjeArtikli(vector<Artikl>* vec); // brisanje svih artikala skladišta
void brisiArtikl(vector<Artikl>* vec);
void provjeraKol(vector<Artikl>* vec);
void skladiste(vector<Artikl>* vec);