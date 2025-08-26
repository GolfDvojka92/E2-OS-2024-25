#ifndef NITI_HPP_INCLUDED
#define NITI_HPP_INCLUDED

#include <thread>
#include <vector>

#include "suma_vektora.hpp"

using namespace std;

// v - vektor čije elemente treba sumirati
// n - koliko niti treba pokrenuti
// povratna vrednost - suma svih elemenata vektora, izračunata pokretanjem n niti (svaka nit treba da obradi jedan deo elemenata)
double sumiraj(vector<double> v, int n) {
    int duzinaNiti = v.size() / n;
    thread niti[n];
    double ret, zbir[n];
    ci it = v.begin();
    for (int i = 0; i < n - 1; i++) {
        niti[i] = thread(f, it, it + v.size() / n, zbir+i);
        it += v.size() / n;
    }
    niti[n - 1] = thread(f, it, v.end(), zbir+n-1);
    for (int i = 0; i < n; i++) {
        niti[i].join();
    }
    for (int i = 0; i < n; i++) {
        ret += zbir[i];
    }
    return ret;
}

#endif // NITI_HPP_INCLUDED
