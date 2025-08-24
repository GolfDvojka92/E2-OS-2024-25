/*
Korisnik treba da unese 5 celih brojeva koristeći tastaturu (standardni ulaz).
Korišćenjem STL algoritma, među tih 5 brojeva potrebno je pronaći najveći.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    string unos;
    cout << "Unos (<C-d> za kraj): ";
    while (getline(cin,unos)) {
        v.push_back(stoi(unos));
    }
    cout << "Najveci je: " << *max_element(v.begin(),v.end()) << endl;
    return 0;
}
