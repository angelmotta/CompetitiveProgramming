#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n, slen;
	long long int res = 0, count=1;
	string s;
	cin >> n;
	vector<string> arr;
	bool ana;
	for(int i=0; i<n; ++i){
		cin >> s;
		sort(s.begin(), s.end());
		arr.push_back(s);
	}
	sort(arr.begin(), arr.end());
	//
	for(int i=0; i<arr.size()-1; ++i){
		if(arr[i] == arr[i+1]){
			count += 1;
			ana = true;
		}
		else {
			if(count > 1){
				//cout << "Apply inner sumatoria de: " << count << '\n';
				res = res + ((count-1)*(count)/2);
				ana = false;
				count = 1;
			}
		}
	}
	if(ana){
		//cout << "Apply sumatoria de: " << count << '\n';
		res = res + ((count-1)*(count)/2);
	}
	cout << res << '\n';
	return 0;
}