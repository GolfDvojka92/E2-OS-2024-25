/*
Napraviti funkciju:
	
vector<int> min_n(const vector<int>& v,	int n);

Ova funkcija vraća vektor koji sadrži n najmanjih elemenata iz vektora v.
Podrazumeva se: v.size()>=n
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> min_n(const vector<int>& v,	int n) {
    vector<int> r;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        r.push_back(v[i]);
    return r;
}

int main()
{
    vector<int> v = { 2, 14, 7, 10, 11, 4 };
    vector<int> m = min_n(v, 3);
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
