#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class KMPAlgorithm {
public:
    KMPAlgorithm() {}
    void computeLPSArray(const char pat[], int M, int lps[]); // Računa niz najduljih zajedničkih prefiksa i sufiksa (LPS) za zadani uzorak
    void KMPSearch(const char pat[], const char* txt); //Traži sve pojave uzorka u tekstu koristeći Knuth-Morris-Pratt algoritam
};
