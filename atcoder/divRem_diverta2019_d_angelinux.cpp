#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	ll n;
	cin >> n;
	vector<ll> divisors;
	//Left's find all divisors of N in O(sqrt(n))
	for(ll div = 1; div * div <= n; ++div){
		if(n % div == 0){
			if(div != 1) divisors.push_back(div);
			if(div != (n/div)) divisors.push_back(n/div);
		}
	}
	// Find all favorite numbers and print the sum of those
	ll sum = 0;
	for(auto div : divisors){
		//cout << "check: " << div << '\n';
		ll m = div - 1;
		if(n / m == n % m){
			sum += m;
		}
	}
	cout << sum << '\n';
	return 0;
}