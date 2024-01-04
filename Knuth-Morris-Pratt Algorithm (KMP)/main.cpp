#include "KMPAlgorithm.h"

using namespace std;


int main() {
    KMPAlgorithm kmp;

    cout << "Odaberite nacin unosa teksta:" << endl;
    cout << "1. Unos teksta putem konzole" << endl;
    cout << "2. Ucitavanje teksta iz datoteke" << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
        // Unos teksta putem konzole
        cout << "Unesite tekst: ";
        string txt;
        cin.ignore();  // Ignoriraj preostale nove redove
        getline(cin, txt);

        char pat[100];
        cout << "Unesite uzorak za pretragu: ";
        cin >> pat;

        kmp.KMPSearch(pat, txt.c_str());
    }
    else if (choice == 2) {
        // Učitavanje teksta iz datoteke
        ifstream file("tekst.txt");
        if (file.is_open()) {
            string txt((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

            char pat[100];
            cout << "Unesite uzorak za pretragu: ";
            cin >> pat;

            kmp.KMPSearch(pat, txt.c_str());
            file.close();
        }
        else {
            cerr << "Nije moguce otvoriti datoteku." << endl;
        }
    }
    else {
        cerr << "Nevazeci odabir." << endl;
        return 1;
    }

    return 0;
}
