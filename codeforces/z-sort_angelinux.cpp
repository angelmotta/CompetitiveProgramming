#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n, a;
	vector<int> arr;
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> a;
		arr.push_back(a);
	}
	// base case arr.size() == 1
	if(n == 1){
		cout << arr[0] << '\n';
		return 0;
	}
	// my Z-sort algorithm
	sort(arr.begin(), arr.end());
	int start=0, end=n-1;
	while(end >= start){
		if(end == start){	// last processing
			cout << arr[start];
			break;
		}
		cout << arr[start] << " " << arr[end] <<  " ";
		start++;
		end--;
	}
	cout << '\n';
	return 0;
}