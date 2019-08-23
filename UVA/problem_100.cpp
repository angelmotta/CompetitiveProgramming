#include <iostream>

int cycle_length;

long long int algo(long long int n){
	if(n == 1){
		return cycle_length;
	}
	else{
		if(n%2 != 0){
			cycle_length++;
			return algo(3 * n + 1);
		}
		else{
			cycle_length++;
			return algo(n/2);
		}
	}
}

int main() {
	int i, j, temp;
	while(std::cin >> i >> j){
		int max = 0, result = 0, reverse=0;
		//std::cout << algo(n) << std::endl;
		if(i > j){
			temp = i;
			i = j;	// i = 10;
			j = temp;	// j = 20;
			reverse = 1;

		}
		for(int n = i; n <= j; n++){
			cycle_length = 1;
			//std::cout << algo(n) << std::endl;
			result = algo(n);
			if(result > max){
				max = result;
			}
		}
		if(reverse){
			temp = j;
			j = i;
			i = temp;
		}
		std::cout << i << " " << j << " " << max << std::endl;
	}
    return 0;
}