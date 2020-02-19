#include <iostream>

using namespace std;

int main(){
	int n;
	double res=0;
	cin >> n;
	while(n){
		res += 1.0/n;
		n--;
	}
	cout << res << '\n';
	return 0;
}