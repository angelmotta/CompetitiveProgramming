#include <iostream>

using namespace std;


bool isPalindrome(int x) {
	if(x < 0) return false;
	int xCopy = x;
	long long int revNum = 0;
	while(x > 0){
		revNum = revNum * 10 + x % 10;
		x /= 10;
	}
	return revNum == xCopy;
}

int main(){
	int num;
	cin >> num;
	cout << isPalindrome(num) << '\n';
	return 0;
}