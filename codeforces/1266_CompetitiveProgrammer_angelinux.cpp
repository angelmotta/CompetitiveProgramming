#include <iostream>
using namespace std;

int main(){
	int n, x, mod_5_2, mod4, mod3, sum_digits;
	string y;
	cin >> n;
	while(n){
		cin >> y;
		mod_5_2 = 0;
		mod3 = 0;
		mod4 = 0;
		sum_digits = 0;
		// check mod3
		for(int i=0; i<y.length(); ++i){
			x = y[i] - '0';		//cast
			sum_digits += x;
			if(x == 0){
				mod_5_2++;
				continue;
			}
			if(x == 2 || x == 4 || x == 6 || x == 8){
				mod4 = 1;
			}
		}
		if(sum_digits%3 == 0) mod3=1;
		if(mod_5_2 >= 2) mod4 = 1;
		if(mod_5_2 && mod4 && mod3){
			cout << "red\n";
		}
		else{
			cout << "cyan\n";
		}
		n--;
	}
	return 0;
}