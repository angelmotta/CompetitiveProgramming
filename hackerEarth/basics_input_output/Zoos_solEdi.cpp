#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 17;
string s;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s;
	cout << (count(s.begin(), s.end(), 'z') * 2 == count(s.begin(), s.end(), 'o') ? "Yes" : "No") << '\n';
}
