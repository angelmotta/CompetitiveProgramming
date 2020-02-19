#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, v, c, res=0;
	cin >> n;
	vector<int> v_arr, c_arr;
	for(int i=0; i<n; ++i){
		cin >> v;
		v_arr.push_back(v);
	}
	for(int i=0; i<n; ++i){
		cin >> c;
		c_arr.push_back(c);
	}
	// Find the maximum result
	for(int i=0; i<n; ++i){
		if((v_arr[i] - c_arr[i]) > 0){
			res += (v_arr[i] - c_arr[i]);
		}
	}
	cout << res << '\n';
	return 0;
}