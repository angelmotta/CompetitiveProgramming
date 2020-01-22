#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int t,n,num;
	cin >> t;
	while(t){
		cin >> n;
		int total_sum = 0, max_so_far = 0, max_ending_here = 0, idx_start=0;
		for(int i=0; i<n; ++i){
			cin >> num;
			total_sum += num;
			max_ending_here = max_ending_here + num;
			if(max_ending_here > max_so_far){
				if(i == 0) idx_start=1;
				if(i == (n-1) && idx_start) break;
				max_so_far = max_ending_here;
			}
			if(max_ending_here < 0){
				max_ending_here = 0;
				idx_start = 0;
			}
		}
		cout << "Total Sum: " << total_sum << '\n';
		cout << "Max sum of subarray: " << max_so_far << '\n';
		if(total_sum > max_so_far){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";	
		}
		t--;
	}
	return 0;
}