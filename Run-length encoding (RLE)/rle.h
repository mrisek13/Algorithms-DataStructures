#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

#define ESCAPE '%' //escape karakter za RLE kompresiju

//RLE kompesija i dekompresija
void komprimiraj(const char* ulazna_naziv, const char* izlazna_naziv);
void dekomprimiraj(const char* ulazna_naziv, const char* izlazna_naziv);

//pomocne funkcije
int velicina_datoteke(const char* naziv);
void ispisi_datoteku(const char* naziv);