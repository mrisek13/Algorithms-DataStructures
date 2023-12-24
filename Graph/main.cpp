#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include <string>

using namespace std;

class GrafRacunalo {
public:
    string nazivRacunala;
    int velicinaMemorije;

    GrafRacunalo(const string& naziv, int velicina) : nazivRacunala(naziv), velicinaMemorije(velicina) {}
};

class Graf {
private:
    vector<GrafRacunalo> racunala;
    vector<list<int>> listaSusjedstva;

public:
    // Dodavanje racunala u graf
    void dodajRacunalo(const GrafRacunalo& racunalo) {
        racunala.push_back(racunalo);
        listaSusjedstva.emplace_back(); // Dodaj praznu listu susjedstva za novo racunalo
    }

    // Dodavanje veze između računala (brid)
    void dodajBrid(int indeksRacunala1, int indeksRacunala2) {
        listaSusjedstva[indeksRacunala1].push_back(indeksRacunala2);
        listaSusjedstva[indeksRacunala2].push_back(indeksRacunala1);
    }

    // Pronalaženje računala s najvećom memorijom
    GrafRacunalo najveceRacunalo() const {
        if (racunala.empty()) {
            return GrafRacunalo("", 0); // Vrati prazan objekt ako nema računala
        }

        // Pronađi računalo s najvećom memorijom
        GrafRacunalo najvece = racunala[0];
        for (size_t i = 1; i < racunala.size(); ++i) {
            if (racunala[i].velicinaMemorije > najvece.velicinaMemorije) {
                najvece = racunala[i];
            }
        }

        return najvece;
    }
};

int main() {
    // Primjer korištenja
    Graf graf;

    // Dodaj 10 računala u graf
    for (int i = 1; i <= 10; ++i) {
        GrafRacunalo racunalo("Racunalo" + to_string(i), i * 2); // Naziv i veličina memorije se mijenjaju
        graf.dodajRacunalo(racunalo);
    }

    // Dodaj veze između računala (bridove)
    graf.dodajBrid(0, 1);
    graf.dodajBrid(1, 2);
    graf.dodajBrid(2, 3);
    graf.dodajBrid(3, 4);
    graf.dodajBrid(4, 5);
    graf.dodajBrid(5, 6);
    graf.dodajBrid(6, 7);
    graf.dodajBrid(7, 8);
    graf.dodajBrid(8, 9);

    // Pronađi računalo s najvećom memorijom
    GrafRacunalo najvece = graf.najveceRacunalo();

    // Ispiši podatke o najvećem računalu
    cout << "Najvece racunalo:\n";
    cout << "Naziv: " << najvece.nazivRacunala << "\n";
    cout << "Velicina memorije: " << najvece.velicinaMemorije << " GB\n";

    return 0;
}
