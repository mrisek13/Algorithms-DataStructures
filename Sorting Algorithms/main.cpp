#include "sortiranja.h"

int main()
{
	//definicija testova - broj elemenata
	const int testovi[] = { 500, 1000, 5000, 10000, 25000, 50000, 75000, 100000, 250000, 500000, 1000000 }; 
	const int broj_testova = 11;
	//datoteka sa rezultatima
	ofstream rezultati;
	rezultati.open("rezultati_heap.csv");
	rezultati << "n; random; a-z;z-a\n";
	//vremena koja se mjere
	clock_t pocetak_rand, pocetak_az, pocetak_za, kraj_rand, kraj_az, kraj_za;
	//testovi
	for (int i = 0; i < broj_testova; i++)
	{
		//int p[n]; //alociramo na stogu novo polje
		int* p = new int[testovi[i]]; //alociramo dinamicki novo polje
		cout << "Sortiram" << testovi[i] << " brojeva u random, a-z i z-a nizu..." << endl; //slucajni niz
		napuni_polje_rand(p, testovi[i]); //punimo polje slucajnim brojevima
		pocetak_rand = clock(); //zapamtimo pocetno vrijeme
		heap_sort(p, testovi[i]);
		kraj_rand = clock(); //zapamtimo vrijeme kraja
		//a-z niz vec imamo sortirani niz
		napuni_polje_az(p, testovi[i]); //punimo polje 1..n
		pocetak_az = clock();
		heap_sort(p, testovi[i]);
		kraj_az = clock();
		//z-a niz
		napuni_polje_za(p, testovi[i]); //punimo polje n..1
		pocetak_za = clock();
		heap_sort(p, testovi[i]);
		kraj_za = clock();
		//oslobodimo memoriju
		delete[]p;
		//zapisimo rezultate
		cout << "Sortiranje slucajnih brojeva obavljeno za \t" << diffclock(kraj_rand, pocetak_rand) << "ms" << endl; 
		cout << "Sortiranje 1..n brojeva obavljeno za \t\t" << diffclock(kraj_az, pocetak_az) << "ms" << endl; 
		cout << "Sortiranje n..1 brojeva obavljeno za \t\t" << diffclock(kraj_za, pocetak_za) << "ms" << endl; 
		rezultati << testovi[i] << ";" << diffclock(kraj_rand, pocetak_rand) << ";"
			<< diffclock(kraj_az, pocetak_az) << ";" << diffclock(kraj_za, pocetak_za) << "\n";
	}//eof testovi
	
	rezultati.close(); //zatvaranje output datoteke

	rezultati.open("rezultati_quick.csv");
	rezultati << "n; random; a-z;z-a\n";
	//testovi
	for (int i = 0; i < broj_testova; i++)
	{
		//int p[n]; //alociramo na stogu novo polje
		int* p = new int[testovi[i]]; //alociramo dinamicki novo polje
		cout << "Sortiram" << testovi[i] << " brojeva u random, a-z i z-a nizu..." << endl; //slucajni niz
		napuni_polje_rand(p, testovi[i]); //punimo polje slucajnim brojevima
		pocetak_rand = clock(); //zapamtimo pocetno vrijeme
		quick_sort(p, testovi[i]);
		kraj_rand = clock(); //zapamtimo vrijeme kraja
		//a-z niz vec imamo sortirani niz
		napuni_polje_az(p, testovi[i]); //punimo polje 1..n
		pocetak_az = clock();
		quick_sort(p, testovi[i]);
		kraj_az = clock();
		//z-a niz
		napuni_polje_za(p, testovi[i]); //punimo polje n..1
		pocetak_za = clock();
		quick_sort(p, testovi[i]);
		kraj_za = clock();
		//oslobodimo memoriju
		delete[]p;
		//zapisimo rezultate
		cout << "Sortiranje slucajnih brojeva obavljeno za \t" << diffclock(kraj_rand, pocetak_rand) << "ms" << endl;
		cout << "Sortiranje 1..n brojeva obavljeno za \t\t" << diffclock(kraj_az, pocetak_az) << "ms" << endl;
		cout << "Sortiranje n..1 brojeva obavljeno za \t\t" << diffclock(kraj_za, pocetak_za) << "ms" << endl;
		rezultati << testovi[i] << ";" << diffclock(kraj_rand, pocetak_rand) << ";"
			<< diffclock(kraj_az, pocetak_az) << ";" << diffclock(kraj_za, pocetak_za) << "\n";
	}//eof testovi

	rezultati.close(); //zatvaranje output datoteke
	system("pause");
	return 0;
}
