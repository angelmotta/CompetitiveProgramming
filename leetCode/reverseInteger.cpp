#include <iostream>

using namespace std;

int reverse(long long int x){
	long long int revNum = 0;
	bool positive;
	if(x > 0){
		positive = true;
	}
	else{
		positive = false;
		x = x * -1;
	}
	while(x > 0){
		revNum = revNum * 10 + x % 10;
		if(positive){
			if(revNum > 2147483647){
				//cout << "overflow positive" << '\n';
				return 0;
			}
		}
		else{
			if(revNum > 2147483648){
				//cout << "overflow negative" << '\n';
				return 0;
			}
		}
		x /= 10;
	}
	if(!positive){
		return revNum * -1;
	}
	return revNum;
}

int main(){
	int num;
	cin >> num;
	int res = reverse(num);
	cout << res << '\n';
	return 0;
}