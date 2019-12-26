#include <iostream>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	string s;
	cin >> s;
	for(int i=0;i<s.length();++i){
		if(s[i] >= 97){	// if is lowerCase
			putchar(toupper(s[i]));
		}
		else{	// if is upperCase
			putchar(tolower(s[i]));			
		}
	}
	cout << '\n';
	return 0;
}