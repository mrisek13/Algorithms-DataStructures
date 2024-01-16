#include <fstream>
#include <iterator>
#include <chrono>
#include "KMPAlgorithm.h"
#include "BruteForceAlgorithm.h"

using namespace std;
using namespace chrono;

int main() {
    KMPAlgorithm kmp;
    BruteForceAlgorithm bfa;

    cout << "Usporedba algoritama pretrazivanje teksta:" << endl;

    // Učitavanje teksta iz datoteke
    ifstream file("tekst.txt");
    if (file.is_open()) {
        string txt((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
        file.close();

        char pat[100];
        cout << "Unesite uzorak za pretragu: ";
        cin >> pat;

        // Vrijeme izvršenja za KMP algoritam
        auto startKMP = high_resolution_clock::now();
        kmp.KMPSearch(pat, txt.c_str());
        auto stopKMP = high_resolution_clock::now();
        auto durationKMP = duration_cast<microseconds>(stopKMP - startKMP);
        cout << "Vrijeme izvrsenja za KMP algoritam: " << durationKMP.count() << " mikrosekundi." << endl;

        // Vrijeme izvršenja za Brute Force algoritam
        auto startBruteForce = high_resolution_clock::now();
        bfa.bruteForceSearch(txt, pat);
        auto stopBruteForce = high_resolution_clock::now();
        auto durationBruteForce = duration_cast<microseconds>(stopBruteForce - startBruteForce);
        cout << "Vrijeme izvrsenja za Brute Force algoritam: " << durationBruteForce.count() << " mikrosekundi." << endl;
    }
    else {
        cerr << "Nije moguce otvoriti datoteku." << endl;
    }

    return 0;
}
