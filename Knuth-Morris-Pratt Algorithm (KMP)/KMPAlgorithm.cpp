#include "KMPAlgorithm.h"

/**
    * Računa niz najduljih zajedničkih prefiksa i sufiksa (LPS) za zadani uzorak.
    *
    * LPS niz je korisna preprocesirana informacija koja pokazuje duljinu najduljeg ispravnog prefiksa
    * koji je istovremeno i sufiks za svaki znak u uzorku.
    *
    * @param pat Uzorak za koji se računa LPS niz.
    * @param M   Duljina uzorka.
    * @param lps Niz za pohranu izračunatih vrijednosti LPS-a.
    */
void KMPAlgorithm::computeLPSArray(const char pat[], int M, int lps[]) {
    // Inicijalizacija varijabli
    int len = 0;  // Duljina prethodnog najduljeg ispravnog prefiksa sufiksa
    int i = 1;    // Trenutni indeks koji se obrađuje u uzorku

    lps[0] = 0;   // Vrijednost LPS-a za prvi znak uvijek je 0

    // Iteracija kroz uzorak za izračunavanje vrijednosti LPS-a
    while (i < M) {
        // Ako se znakovi na trenutnim pozicijama podudaraju, proširi prefiks
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            // Ako postoji nespodudavanje i duljina nije nula,
            // ažuriraj duljinu na temelju LPS-a prethodnog znaka
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                // Ako je duljina nula, postavi vrijednost LPS-a za trenutni znak na 0
                lps[i] = 0;
                i++;
            }
        }
    }
}


/**
    * Traži sve pojave uzorka u tekstu koristeći Knuth-Morris-Pratt algoritam.
    *
    * Knuth-Morris-Pratt (KMP) algoritam efikasno pronalazi sve pojave uzorka u tekstu.
    * Ova funkcija koristi prethodno izračunati niz najduljih zajedničkih prefiksa i sufiksa (LPS)
    * za optimizaciju pretrage.
    *
    * @param pat Uzorak koji se traži u tekstu.
    * @param txt Tekst u kojem se vrši pretraga.
    */
void KMPAlgorithm::KMPSearch(const char pat[], const char* txt) {
    int M = strlen(pat);  // Duljina uzorka
    int N = strlen(txt);  // Duljina teksta

    // Izračun niza LPS
    vector<int> lps(M);
    computeLPSArray(pat, M, lps.data());

    int i = 0; // Indeks za txt[]
    int j = 0; // Indeks za pat[]

    // Iteracija kroz tekst dok ne pronađemo sve pojave uzorka
    while (i < N) {
        // Ako se znakovi podudaraju, povećaj indekse
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        // Ako smo pronašli kompletnu pojavu uzorka, ispiši indeks
        if (j == M) {
            cout << "Uzorak pronadjen na indeksu " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i]) {
            // Ako se znakovi ne podudaraju, ažuriraj indeks prema LPS vrijednosti
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                // Ako je indeks j već nula, povećaj indeks i
                i = i + 1;
            }
        }
    }
}
