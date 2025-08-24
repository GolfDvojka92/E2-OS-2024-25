/*
    Napraviti funkciju koja sortira dati vektor int-ova koristeći
    za određivanje da li je neki element manji ili veći od drugog
    prosleđenu funkciju. Demonstrirati ovo kroz lambda izraz.

    Bonus zadaci:
    1. Implementirati ovo da radi sa bilo kojim tipom kroz
    šablone.
    2. Implementirati ovo kroz quicksort algoritam.
*/

#include <functional>
#include <iostream>
#include <vector>

using namespace std;

void zameni(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortiraj(vector<int> &v, function<bool(int, int)> f) {
    vector<int> temp;
    int najmanji;
    for (int i = 0; i < v.size() - 1; i++) {
        najmanji = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (f(v[j], v[i]))
                najmanji = j;
        }
        zameni(v[i], v[najmanji]);
    }
}

int main() {
    vector<int> v = { 2, 17, 10, 8, 4, 24 };
    sortiraj(v, [](int a, int b) -> bool { return a < b; });
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
