/* 
Napraviti funkciju:
	
vector<int> min(const vector<int>& a, const vector<int>& b);

Ova funkcija vraća vektor koji sadrži minimume korespodentnih elemenata vektora a i b.
Npr: r[0]=min(a[0],b[0]), r[1]=...
Podrazumeva se: a.size()==b.size()
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> min(const vector<int>& a, const vector<int>& b) {
    vector<int> r;
    for (int i = 0;i < a.size(); i++) {
        r.push_back(min(a[i], b[i]));
    }
    return r;
}

int main()
{
    vector<int> a = { 7, 13, 3, 6, 30, 4 }, b = { 5, 8, 10, 5, 32, 7 };
    vector<int> r = min(a, b);
    for (auto it = r.begin(); it != r.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
