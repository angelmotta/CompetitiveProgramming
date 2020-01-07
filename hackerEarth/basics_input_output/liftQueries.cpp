#include <iostream>
#include <cmath>

using namespace std;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int t, a=0, b=7, num_floor;
	cin >> t;
	while(t){
		cin >> num_floor;
		if(abs(a - num_floor) < abs(b - num_floor)){
			cout << "A\n";
			a = num_floor;
		}
		else if(abs(a - num_floor) > abs(b - num_floor)){
			cout << "B\n";
			b = num_floor;
		}
		else{
			cout << "A\n";
			a = num_floor;
		}
		t--;
	}
	return 0;
}