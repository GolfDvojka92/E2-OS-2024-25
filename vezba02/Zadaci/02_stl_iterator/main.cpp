/*
Napraviti program koji prihvata proizvoljan broj linija sa standardnog ulaza i zatim ih ispisuje u redosledu kojim su uneti.
*/

#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<string> l;
    string unos;
    cout << "Unos (<C-d> za kraj): ";
    while (getline(cin,unos)) {
        l.push_back(unos);
    }
    cout << "Uneseni stringovi su: " << endl;
    /*for (const string &s : l) {
        cout << s << endl;
    }*/
    for (auto it = l.begin(); it != l.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
