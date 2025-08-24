/*
Napraviti program koji prihvata proizvoljan broj linija sa standardnog ulaza i zatim ih ispisuje u obrnutom redosledu 
(poslednja prihvaćena linija se ispisuje prva).
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> v;
    string unos;
    cout << "Unos (<C-d> za kraj):";
    while (getline(cin,unos)) {
        v.push_back(unos);
    }
    cout << "Uneseni stringovi obrnuto: " << endl;
    for (auto it = v.rbegin(); it != v.rend(); it++) {
        cout << *it << endl;
    }
    return 0;
}
