#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int t, pos;
	string s, s1, s2;
	cin >> t;
	cin.ignore();
	while(t){
		getline(cin,s);
		pos = s.find(" ");
		s1 = s.substr(0,pos);
		s2 = s.substr(pos+1);
		//cout << "s1: " << s1 << " s2: " << s2 << '\n';
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		//cout << "s1: " << s1 << " s2: " << s2 << '\n';
		if(s1 == s2){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
		t--;
	}
	
	return 0;
}