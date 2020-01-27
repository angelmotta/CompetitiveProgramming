#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int sumDigits(int& num, int& num_digits ){
	int sum_digits=0;
	for(int i=1; i<=num_digits; ++i){
		sum_digits += num%10;
		num = num / 10;
	}
	return sum_digits;
}

int countDigits(int& x_num){
	int num_digits = 0;
	while(x_num){
		x_num = x_num / 10;
		num_digits++;
	}
	return num_digits;
}

int main(){
	int n, num_digits=0, sum_digits;
	vector<int> x_vec;
	cin >> n;
	// Guess the number x
	int x = 1, x_num;
	if(n >= 100000){
		x = n - 81;
	}
	while(x <= n){
		x_num = x;
		num_digits = countDigits(x_num);
		x_num = x;
		sum_digits = sumDigits(x_num, num_digits);
		if((x+sum_digits) == n){
			x_vec.push_back(x);
		}
		x++;
	}
	//Print results
	cout << x_vec.size() << '\n';
	for(auto x : x_vec) cout << x << '\n';
	
	return 0;
}