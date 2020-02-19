#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,a, max=0, second_max=0;
	vector<int> arr;
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> a;
		arr.push_back(a);
		if(a >= max){
			if(i == 0){
				max = a;
			}
			else{
				second_max = max;
				max = a;
			}
		}
		else{
			if(a > second_max){
				second_max = a;
			}
		}
	}
	// Print result
	//cout << "max: " << max << " second_max: " << second_max << '\n';
	for(int i=0; i<n; ++i){
		if(arr[i] == max){
			cout << second_max << '\n';
		}
		else{
			cout << max << '\n';
		}
	}
	return 0;
}