#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool isAllToB(string s, int& n){
	vector<int> arr;
	for(int i=0; i<n-1; ++i){
		if(s[i] == 'W'){
			s[i] = 'B';
			arr.push_back(i+1);
			// change the next character
			if(s[i+1] == 'W'){
				s[i+1] = 'B';
			}
			else{
				s[i+1] = 'W';
			}
		}
	}
	//Check the last char
	if(s[n-1] == 'B'){
		//cout << "Good\n";
		if(arr.size() == 0){
			cout << 0 << '\n';
		}
		else{
			cout << arr.size() << '\n';
			for(auto i : arr) cout << i << " ";
			cout << '\n';
		}
		return true;
	}
	else{
		//cout << "Impossible change all to B\n";
		return false;
	}
}

bool isAlltoW(string s, int& n){
	vector<int> arr;
	for(int i=0; i<n-1; ++i){
		if(s[i] == 'B'){
			s[i] = 'W';
			arr.push_back(i+1);
			// change the next character
			if(s[i+1] == 'W'){
				s[i+1] = 'B';
			}
			else{
				s[i+1] = 'W';
			}
		}
	}
	//Check the last char
	if(s[n-1] == 'W'){
		//cout << "Goooood\n";
		if(arr.size() == 0){
			cout << 0 << '\n';
		}
		else{
			cout << arr.size() << '\n';
			for(auto i : arr) cout << i << " ";
			cout << '\n';	
		}
		return true;
	}
	else{
		//cout << "Impossible change all to W\n";
		return false;
	}
}

bool isTheSameColor(string& s, int& n){
	for(int i=0; i<n-1; ++i){
		if(s[i] != s[i+1]){
			return false;
		}
	}
	return true;
}

int main(){
	string s;
	int n;
	cin >> n;
	cin >> s;
	// check if It is already all the same color
	if(isTheSameColor(s, n)){
		cout << 0 << '\n';
		return 0;
	}
	// try changing everything to B
	if(!isAllToB(s, n)){
		//cout << "Execute isAlltoW\n";
		if(!isAlltoW(s, n)){
			cout << -1 << '\n';
		}
	}
	return 0;
}

