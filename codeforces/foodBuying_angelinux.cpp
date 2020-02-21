#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t, s, spend, num;
	cin >> t;
	for(int i=0; i<t; ++i){
		cin >> s;
		spend = 0;
		while(s){
			if(s < 10){
				spend += s;
				s -= s;
				break;
			}
			num = s / 10;
			spend += (num * 10);
			s -= (num*10);
			s += num*1;
		}
		cout << spend << '\n';
	}
	return 0;
}