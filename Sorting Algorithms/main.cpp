#include "sortiranja.h"
#include <iostream>

int main()
{
	const int n = 100; //broj elemenata u polju
	clock_t pocetak_rand, pocetak_az, pocetak_za, kraj_rand, kraj_az, kraj_za; //vremena
	//int p[n]; //alociramo na stogu novo polje
	int* p = new int[n]; //alociramo dinamicki novo polje
	cout << "Sortiram " << n << " brojeva u random, a-z i z-a nizu..." << endl << endl;
	//slucajni niz
	napuni_polje_rand(p, n); //punimo polje slucajnim brojevima
	pocetak_rand = clock(); //zapamtimo pocetno vrijeme
	selection_sort(p, n);
	kraj_rand = clock(); //zapamtimo vrijeme kraja
	ispisi_polje(p, n); //ispis
	//a-z niz - vec imamo sortirani niz
	napuni_polje_az(p, n); //punimo polje 1..n
	pocetak_az = clock();
	selection_sort(p, n);
	kraj_az = clock();
	ispisi_polje(p, n); //ispis
	//z-a niz
	napuni_polje_za(p, n); //punimo polje n..1
	pocetak_za = clock();
	selection_sort(p, n);
	kraj_za = clock();
	ispisi_polje(p, n); //ispis
	cout << "Sortiranje slucajnih brojeva obavljeno za \t" << diffclock(kraj_rand, pocetak_rand) << "ms" << endl;
	cout << "Sortiranje 1..n brojeva obavljeno za \t\t" << diffclock(kraj_az, pocetak_az) << "ms" << endl;
	cout << "Sortiranje n..1 brojeva obavljeno za \t\t" << diffclock(kraj_za, pocetak_za) << "ms" << endl;
	system("pause");
	return 0;
}
