#include "Artikl.h"

void upis(std::vector<Artikl>* vec)
{
    Artikl A;
    string dataS;
    system("cls"); // brisanje ekrana

    cout << "Upisi naziv artikla: ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ocisti ulazni buffer
    cin.getline(A.naziv, sizeof(A.naziv));

    cout << "Upisi kolicinu artikla: ";
    cin >> A.kolicina;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ocisti ulazni buffer

    cout << "Upisi mjernu jedinicu artikla: ";
    cin.getline(A.mj, sizeof(A.mj));

    cout << "Upisi naziv proizvodaca: ";
    cin.getline(A.proizvodjac, sizeof(A.proizvodjac));

    cout << "Cijena: ";
    cin >> A.cijena;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ocisti ulazni buffer
    
    cout << "Upisi naziv dobavljaca: ";    
    cin.getline(A.dobavljac, sizeof(A.dobavljac));

    vec->push_back(A);
}


void ispis(vector<Artikl>* vec)
{
    system("cls"); // brisanje ekrana
    int br = 1;
    for (int x = 0; x < vec->size(); x++)
    {
        Artikl A = vec->at(x);
        cout << br << ". Artikl: " << A.naziv << " " << A.kolicina << " " << A.mj << " Cijena: " << A.cijena << endl;
        cout << "Naziv dobavljaca: " << A.dobavljac << endl
                  << endl;
        br++;
    }
    system("PAUSE");
}

void brisanjeArtikli(vector<Artikl>* vec)
{
    system("cls"); // brisanje ekrana
    char odgovor;
    cout << "Zelite li obrisati sve artikle u skladistu (D / N) ?";
    cin >> odgovor;
    if (toupper(odgovor) == 'N')
        return;
    vec->clear();
    cout << endl
         << "Svi artikli u skladistu su obrisani!" << endl;
    system("PAUSE");
}

void brisiArtikl(vector<Artikl>* vec)
{
    system("cls"); // brisanje ekrana
    char naziv[20];
    cout << "Upisi naziv artikla kojeg zelis obrisati: ";
    cin >> naziv;
    bool OK = false; // nije obrisano
    for (int x = 0; x < vec->size(); x++)
    {
        Artikl A = (Artikl)vec->at(x);
        if (strcmp(A.naziv, naziv) == 0)
        {
            vec->erase(vec->begin() + x);
            cout << "Artikl je obrisani!" << endl
                 << endl;
            OK = true;
            break;
        }
    }
    if (!OK)
        cout << "Artikl nije pronaden." << endl
             << endl;
    system("PAUSE");
}

void provjeraKol(vector<Artikl>* vec)
{
    system("cls");
    int br = 1;
    for (int x = 0; x < vec->size(); x++)
    {
        Artikl A = (Artikl)vec->at(x);
        if (A.kolicina <= 10)
        {
            cout << br << ". Artikl: " << A.naziv << " " << A.kolicina << " " << A.mj << "Cijena: " << A.cijena << endl;
            cout << "Naziv dobavljaca: " << A.dobavljac << endl
                 << endl;
            br++;
        }
        else
            cout << "Nema." << endl;
    }
    system("PAUSE");
}

void skladiste(vector<Artikl>* vec)
{
    double vsklad = 0;
    Artikl X;
    for (int x = 0; x < vec->size(); x++)
    {
        Artikl X = (Artikl)vec->at(x);
        vsklad += X.cijena * (double)X.kolicina;
    }
    cout << "Vrijednost skladista: " << vsklad << endl;
}