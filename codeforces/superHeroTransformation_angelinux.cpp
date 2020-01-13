#include <iostream>

using namespace std;

bool isVowel(char& letter){
	if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') return true;
	return false;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	string s, t;
	cin >> s >> t;
	if(s.length() != t.length()){
		cout << "No\n";
		return 0;
	}

	for(int i=0; i<s.length(); ++i){
		if( !(isVowel(s[i]) == isVowel(t[i])) ){
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}