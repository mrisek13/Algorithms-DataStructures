#include "rle.h"

int main()
{
	//komprimiramo različite datoteke
	cout << "Komprimiramo razlicite datoteke..." << endl << endl;
	komprimiraj("test.txt", "test_rle.txt");
	komprimiraj("u2.txt", "u2_rle.txt");
	komprimiraj("kennedy.txt", "kennedy_rle.txt");
	komprimiraj("che.txt", "che_rle.txt");

	//dekomprimiramo razlicite datoteke
	cout << "Dekomprimiramo natrag datoteke..." << endl << endl;
	dekomprimiraj("test_rle.txt", "test2.txt");
	dekomprimiraj("u2_rle.txt", "u2.txt");
	dekomprimiraj("kennedy_rle.txt", "kennedy2.txt");
	dekomprimiraj("che_rle.txt", "che2.txt");

	//ispisujemo testnu datoteku prije i nakon komprimiranja te nakom dekomprimiranja
	cout << "Primjer testne datoteke redom ORIGINAL, KOMPRIMIRANA, DEKOMPRIMIRANA..." << endl << endl;
	ispisi_datoteku("test.txt");
	system("pause");
	ispisi_datoteku("test_rle.txt");
	system("pause");
	ispisi_datoteku("test2.txt");
	system("pause");

	//analiza rezultata
	cout << "***ANALIZA (velicine u bytes) ***" << endl;
	cout << "Datoteka\tOriginal\tKomprimirano\tDekomprimirano\tkompresija" << endl;
	cout << "test.txt\t" << velicina_datoteke("test.txt") << "\t\t" << velicina_datoteke("test_rle.txt") << "\t\t";
	cout << velicina_datoteke("test2.txt") << "\t\t" << (float)velicina_datoteke("test_rle.txt") / (float)velicina_datoteke("test.txt") << endl;
	cout << "u2.txt\t\t" << velicina_datoteke("u2.txt") << "\t\t" << velicina_datoteke("u2_rle.txt") << "\t\t";
	cout << velicina_datoteke("u2.txt") << "\t\t" << (float)velicina_datoteke("u2_rle.txt") / (float)velicina_datoteke("u2.txt") << endl;
	cout << "kennedy.txt\t" << velicina_datoteke("kennedy.txt") << "\t\t" << velicina_datoteke("kennedy_rle.txt") << "\t\t";
	cout << velicina_datoteke("kennedy2.txt") << "\t\t" << (float)velicina_datoteke("kennedy_rle.txt") / (float)velicina_datoteke("kennedy.txt") << endl;
	cout << "che.txt\t\t" << velicina_datoteke("che.txt") << "\t\t" << velicina_datoteke("che_rle.txt") << "\t\t";
	cout << velicina_datoteke("che2.txt") << "\t\t" << (float)velicina_datoteke("che_rle.txt") / (float)velicina_datoteke("che.txt") << endl;
	cout << endl;

	system("pause");
	return 0;
}
