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
    
    return 0;
}
