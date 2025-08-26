/*
Napraviti konkurentni program koji pronalazi element najbliži broju 0 u zadatom vektoru brojeva.

Pretragu podeliti u 3 programske niti. Ulazni vektor brojeva treba da sadrži 900.000 slučajno generisanih brojeva.

Za svaku nit, evidentirati trenutke kada je izvršavanje počelo i kada se završilo. Na kraju programa, ispisati koliko je trajalo izvršavanje svake niti u milisekundama.
*/

#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <vector>
#include <random>

using namespace std;
using namespace chrono;

typedef vector<double>::const_iterator cit;
typedef std::chrono::high_resolution_clock hrc_t;

struct vreme {
    system_clock::time_point pocetak;
    system_clock::time_point kraj;
};

double compareAbs(double a, double b) {
    if (abs(a) < abs(b))
        return a;
    return b;
}

void f(cit pocetak, cit kraj, double & min, struct vreme * v) {
    v->pocetak = hrc_t().now();
    min = *pocetak;
    for (; pocetak + 1 != kraj; pocetak++) {
        min = compareAbs(*pocetak, min);
    }
    v->kraj = hrc_t().now();
}

const int BROJ_NITI = 3;
const int DUZINA = 900000;

int main() {
    int SEGMENT = DUZINA / BROJ_NITI;
    default_random_engine gen;

    gen.seed(duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count());// Inicijalizacija generatora slučajnih brojeva da pri svakom pokretanju daje različite brojeve
    uniform_real_distribution<double> real_dist(-1e5, 1e5);

    vector<double> v(DUZINA);
    // Puni se vektor pseudo-slučajnim brojevima
    for (int i = 0; i < DUZINA; i++)
       v[i] = real_dist(gen);

    double minimumi[BROJ_NITI];  // Niz elemenata najbližih nuli - svaka programska nit će dati svoj međurezltat
    struct vreme vremena[BROJ_NITI]; // Niz struktura u koji će biti upisani podaci o trajanju izvršavanja svake niti

    thread niti[BROJ_NITI];
    cit pomeraj = v.begin();

    for (int i = 0; i < BROJ_NITI; i++) {
        niti[i] = thread(f, pomeraj, pomeraj + SEGMENT, minimumi + i, vremena + i);
        pomeraj += SEGMENT;
    }

    for (int i = 0; i < BROJ_NITI; i++) {
        niti[i].join();
    }

    double rez = minimumi[0];
    for (int i = 1; i < BROJ_NITI; i++) {
        rez = compareAbs(minimumi[i], rez);
    }

    for (int i = 0; i < BROJ_NITI; i++) {
        duration<double, milli> d = vremena[i].kraj - vremena[i].pocetak;
        cout << "Nit broj " << i + 1 << " je trajala: " << d.count() << "." << endl;
    }

    return 0;
}

