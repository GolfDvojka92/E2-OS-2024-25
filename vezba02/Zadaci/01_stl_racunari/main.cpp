/* 
Napisati program koji omogućava evidentiranje fakultetskih učionica.

Za svaku učionicu potrebno je evidentirati naziv učionice, kvadraturu i sve računare koji se nalaze u učionici. 
Za svaki računar evidentiraju se podaci o hard disku i procesoru.

U okviru main funkcije, definisati jednu učionicu koja sadrži dva računara.
Zatim je potrebno na konzolu ispisati hard disk i procesor svakog računara u učionici.
*/

#include <iostream>
#include <list>
#include <string>
using namespace std;

class Racunar {
    private:
    string HDD, CPU;
    public:
    Racunar() { HDD = ""; CPU = ""; }
    Racunar(const char* HDD, const char* CPU) { this->HDD = HDD; this->CPU = CPU; }
    string getHDD() { return HDD; }
    string getCPU() { return CPU; }
    friend ostream& operator<<(ostream& os, const Racunar& r) {
        os << "HDD:" << r.HDD << endl;
        os << "CPU:" << r.CPU << endl;
        return os;
    }
};

class Ucionica {
    private:
    string naziv;
    double kvadratura;
    list<Racunar> racunari;
    public:
    Ucionica() : racunari() { naziv = ""; kvadratura = 0; }
    Ucionica(string naziv, double kvadratura) : racunari() { this->naziv = naziv; this->kvadratura = kvadratura; }
    string getNaziv() { return naziv; }
    double getKvadratura() { return kvadratura; }
    list<Racunar> getRacunari() { return racunari; }
    void dodajRacunar(Racunar r) { racunari.push_back(r); }
};

int main()
{
    Ucionica u = Ucionica("MIA-2", 115);
    u.dodajRacunar(Racunar("WD Purple 1TB","Pentium Gold"));
    u.dodajRacunar(Racunar("WD Purple 2TB","i5 10600K"));
    u.dodajRacunar(Racunar("Seagate Barracuda 500GB", "Ryzen 5 2600X"));
    for (const Racunar& r : u.getRacunari()) {
        cout << r;
    }
    return 0;
}
