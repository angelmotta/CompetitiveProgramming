#include <iostream>
#include <cmath>

using namespace std;

bool isKaprekar(int& n){
	if(n == 1) return true;
	int n_sq = n*n;
	int num_digits = 0;
	while(n_sq){
		n_sq = n_sq / 10;
		num_digits++;
	}
	n_sq = n*n;		// set n_sq to the original square value
	for(int i=1; i<num_digits; ++i){
		int divisor = pow(10,i);
		if(divisor == n) continue;		// not consider numbers 10, 100, 1000...etc..
		if(n == (n_sq%divisor + n_sq/divisor)){
			return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int n, inf, sup;
	bool isFound;
	cin >> n;
	for(int i=1; i<= n; ++i){
		cin >> inf >> sup;
		isFound = false;
		cout << "case #" << i << '\n';
		for(int j=inf; j<=sup; ++j){
			int num = j;
			if(isKaprekar(num)){
				isFound = true;
				cout << j << '\n'; 	
			}
		}
		if(!isFound) cout << "no kaprekar numbers\n";
		if(i != n) cout << '\n';
	}
	return 0;
}