#include <iostream>

using namespace std;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int n, a, breaks=0, i=1, limit;
	cin >> n;
	limit = n - 1;
	while(n){
		cin >> a;
		if(a != i){
			if(breaks < limit){
				breaks++;
			}
			else{
				cout << -1 << '\n';
				return 0;
			}
		}
		else{
			i++;
		}
		n--;
	}
	cout << breaks << '\n';
	return 0;
}