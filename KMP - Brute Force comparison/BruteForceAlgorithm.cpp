#include "BruteForceAlgorithm.h"

void BruteForceAlgorithm::bruteForceSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    cout << endl;

    for (int i = 0; i <= n - m; ++i) {
        int j;
        for (j = 0; j < m; ++j) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == m) {
            cout << "Ponavljanje je pronadeno na indeksu:  " << i << " koristeci brute force algoritam." << endl;
        }
    }
}
