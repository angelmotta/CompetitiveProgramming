#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int n, k, score, k_score, num_adv=0;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> score;
		if(i<=k && score > 0){
			num_adv++;
			if(i == k){
				k_score = score;
			}
			continue;
		}
		if(score >= k_score && score > 0) num_adv++;
	}
	cout << num_adv << '\n';
	return 0;
}