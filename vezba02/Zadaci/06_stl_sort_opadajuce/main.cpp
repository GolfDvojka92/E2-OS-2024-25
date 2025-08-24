/*
Uneti 5 celih brojela sa standardnog ulaza.
Korišćenjem STL algoritma sortirati brojele u opadajućem redosledu.
*/

#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    list<int> l;
    string unos;
    cout << "Unos (<C-d> za kraj): ";
    while (getline(cin,unos)) {
        l.push_back(stoi(unos));
    }
    l.sort();
    l.reverse();
    cout << "["; 
    for (auto it = l.begin(); it != prev(l.end(), 1); it++) {
        cout << *it << ", ";
    }
    cout << *prev(l.end(), 1) << "]" << endl;
    return 0;
}
