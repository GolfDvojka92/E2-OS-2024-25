/*
Uneti 5 celih brojeva sa standardnog ulaza.
Korišćenjem STL algoritma sortirati brojeve u rastućem redosledu.
*/

#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    list<int> v;
    string unos;
    cout << "Unos (<C-d> za kraj): ";
    while (getline(cin,unos)) {
        v.push_back(stoi(unos));
    }
    v.sort();
    cout << "["; 
    for (auto it = v.begin(); it != prev(v.end(), 1); it++) {
        cout << *it << ", ";
    }
    cout << *prev(v.end(), 1) << "]" << endl;
    return 0;
}
