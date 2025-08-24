/*
Napraviti jednostavan program za prevođenje reči sa engleskog na srpski jezik.
Nakon unosa reči sa standardnog ulaza, ispisuje se prevod (ukoliko unesena reč postoji u rečniku). 

Uneti 3 engleske reči i njihove prevode na srpski.
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string,string> m;
    m["Monkey"] = "Majmun";
    m["Headphones"] = "Slusalice";
    m["Cellphone"] = "Mobilni";
    cout << "Unesite rec: ";
    string unos;
    cin >> unos;
    cout << "Prevod: " << m[unos] << endl;
    return 0;
}
