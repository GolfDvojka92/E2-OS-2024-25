#ifndef NITI_HPP_INCLUDED
#define NITI_HPP_INCLUDED

#include <thread>
#include <vector>

#include "suma_vektora.hpp"

using namespace std;

// v - vektor čije elemente treba sumirati
// povratna vrednost - suma svih elemenata vektora, izračunata pokretanjem 2 niti (svaka treba da obradi jednu polovinu elemenata)
double sumiraj(vector<double> v) {
    double zbir1 = 0, zbir2 = 0;
    ci poloina = v.begin() + v.size() / 2;
    thread t1(f, v.begin(), poloina, zbir1);
    thread t2(f, poloina, v.end(), zbir2);
    t1.join();
    t2.join();
    return zbir1 + zbir2;
}

#endif // NITI_HPP_INCLUDED
