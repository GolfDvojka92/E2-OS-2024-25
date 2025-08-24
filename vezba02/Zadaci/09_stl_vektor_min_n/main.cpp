/*
Napraviti funkciju:
	
vector<int> min_n(const vector<int>& v,	int n);

Ova funkcija vraća vektor koji sadrži n najmanjih elemenata iz vektora v.
Podrazumeva se: v.size()>=n
*/

#include <iostream>
#include <vector>
#include <list>
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
    return 0;
}
