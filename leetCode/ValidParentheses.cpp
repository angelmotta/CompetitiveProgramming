#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s){
	stack<char> mystack;
	string temp;
	for(int i = 0; i < s.length(); ++i){
		if(s[i] == '{' || s[i] == '(' || s[i] == '['){
			mystack.push(s[i]);
		}
		else{
			if(mystack.empty()) return false;
			temp = string(1,mystack.top()) + s[i];
			if(temp == "{}" || temp == "()" || temp == "[]"){
				mystack.pop();
			}
			else{
				return false;
			}
		}
	}
	if(!mystack.empty()) return false;
	return true;
}

int main(){
	string s = "]";
	cout << isValid(s) << '\n';
	return 0;
}