#include "rle.h"

//RLE komprimiranje datoteke
void komprimiraj(const char* ulazna_naziv, const char* izlazna_naziv)
{
	int koliko = 1; //broj ponavljanja karaktera
	char c = NULL, p; //promatrani i prethodni karakter, c postavljamo na NULL za prvu iteraciju
	ifstream ulazna(ulazna_naziv); //otvaranje ulazne datoteke
	ofstream izlazna(izlazna_naziv); //otvaranje izlazne datoteke

	if (ulazna.is_open()) //ako je uspjesno otvorena ulazna datoteka
	{
		while (!ulazna.eof()) //citamo do kraja datoteke karakter po karakter
		{
			p = c; //prethodni postaje sadasnji
			c = ulazna.get(); //uzimamo karakter iz ulazne datoteke, kad procitamo posljednji ulazna.eof() je true
			if (p == c && !ulazna.eof() && koliko < 9)
				koliko++;
			else if (p != NULL) //prvi put je p NULL pa nista ne radimo
			{
				//% je escape karakter po uvijek kodiramo zapis bez obzira na broj ponavljanja
				if (koliko >= 3 || p == ESCAPE)
					izlazna << ESCAPE << p << koliko;
				else //ako je broj ponavljanja <3 osim za escape ponavljamo ispis umjesto kodiranja
					for (int i = 0; i < koliko; i++)
						izlazna << p;
				koliko = 1; //nakon ispisa resetiramo brojac
			}
		}
		ulazna.close(); //zatvaramo ulznu datoteku
	}
	else
		cout << "Greška kod citanja datoteke: " << ulazna_naziv << endl;
	izlazna.close(); //zatvaramo izlaznu daoteku
}

void dekomprimiraj(const char* ulazna_naziv, const char* izlazna_naziv)
{
	char c, next_char;
	int broj_ponavljanja;

	ifstream ulazna(ulazna_naziv);
	ofstream izlazna(izlazna_naziv);

	if (ulazna.is_open() && izlazna.is_open())
	{
		while (!ulazna.eof())
		{
			c = ulazna.get();

			if (!ulazna.eof())
			{
				if (c != ESCAPE)
				{
					izlazna << c;
				}
				else
				{
					next_char = ulazna.get();
					broj_ponavljanja = ulazna.get() - '0';

					if (broj_ponavljanja >= 1 && broj_ponavljanja <= 9)
					{
						for (int i = 0; i < broj_ponavljanja; i++)
						{
							izlazna << next_char;
						}
					}
					else if (broj_ponavljanja >= 1 && broj_ponavljanja <= 78)
					{
						for (int i = 0; i < broj_ponavljanja; i++)
						{
							izlazna << (char)(i + '1');
						}
					}
				}
			}
		}

		ulazna.close();
		izlazna.close();
	}
	else
	{
		cout << "Greška kod otvaranja datoteka." << endl;
	}
}

// Vraca velicinu datoteke
int velicina_datoteke(const char* naziv)
{
	FILE* pFile = NULL;
	if (fopen_s(&pFile, naziv, "rb") == 0 && pFile != NULL)
	{
		fseek(pFile, 0, SEEK_END);
		int size = ftell(pFile);
		fclose(pFile);
		return size;
	}
	else
	{
		return -1;
	}
}

//ispis datoteke na konzolu
void ispisi_datoteku(const char* naziv)
{
	cout << "*** " << naziv << " ***" << endl;
	ifstream datoteka;
	datoteka.open(naziv);
	char c; //trenutni karakter
	while (!datoteka.eof())
	{
		c = datoteka.get();
		cout << c;
	}
	cout << endl;
}

