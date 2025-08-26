#ifndef NITI_HPP_INCLUDED
#define NITI_HPP_INCLUDED

#include <thread>
#include <vector>

#include "suma_vektora.hpp"

using namespace std;

// v - vektor A čije elemente treba sumirati
// v - vektor B čije elemente treba sumirati
// povratna vrednost - suma korespondentnih elemenata vektora A i B, izračunata pozivanjem dve niti
vector<double> sumiraj(vector<double> a, vector<double> b) {
    vector<double> suma(a.size());
    ci polovina_a = a.begin() + a.size() / 2;
    ci polovina_b = b.begin() + b.size() / 2;
    ci polovina_suma = suma.begin() + suma.size() / 2;
    thread t1(f, a.begin(), polovina_a, b.begin(), suma.begin());
    thread t2(f, polovina_a, a.end(), polovina_b, polovina_suma);
    t1.join();
    t2.join();
    return suma;
}

#endif // NITI_HPP_INCLUDED
