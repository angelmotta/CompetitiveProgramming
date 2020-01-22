#include <iostream>

using namespace std;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int n,p,i=1,swap_num=0;
	cin >> n;
	while(n){
		cin >> p;
		if(i != p) swap_num++;
		if(swap_num > 2){
			cout << "NO\n";
			return 0;
		}
		i++;
		n--;
	}
	cout << "YES\n";
	return 0;
}