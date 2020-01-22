#include <iostream>
using namespace std;

int main(){
	int n;
	string y;
	cin >> n;
	while(n){
		cin >> y;
		// check mod3
		for(int i=0; i<y.length(); ++i){
			cout << y[i] << " ";
		}
		cout << '\n';
		//if(mod3())
		n--;
	}
	return 0;
}