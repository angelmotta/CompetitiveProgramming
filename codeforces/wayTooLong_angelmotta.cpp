#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	string w;
	int n;
	cin >> n;
	while(n){
		cin >> w;
		if(w.length() >= 11){
			cout << w[0] << w.length() -2 << w[w.length()-1] << '\n';
		}
		else{
			cout << w << '\n';
		}
		n--;
	}
	return 0;
}