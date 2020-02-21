#include <iostream>
#include <set>

using namespace std;

int main(){
	int t, n, s, k, a;
	cin >> t;
	while(t--){
		cin >> n >> s >> k;
		// Set closed restaurants
		set<int> closed;
		for(int i = 0; i < k; ++i){
			cin >> a;
			closed.insert(a);
		}	
		// Find the minimum staircases
		int i=0;
		while(true){	// you will have at least 1 restaurant so go until you find it
			if(s + i <= n){
				if(!closed.count(s+i)){
					cout << i << '\n';
					break;
				}
			}
			if(s - i > 0){
				if(!closed.count(s-i)){
					cout << i << '\n';
					break;
				}
			}
			i++;
		}
	}
	return 0;
}