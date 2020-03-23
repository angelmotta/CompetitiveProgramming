#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
	// Result
	vector<int> result;
	result.reserve(2);
	// Create map(complement, idx) to store complement = target - num;
	map<int, int> mymap;
	// Read the vector
	for(int i = 0; i < nums.size(); ++i){
		auto it = mymap.find(nums[i]);
		if(it != mymap.end()){
			result.push_back(it->second);
			result.push_back(i);
			break;
		}
		else{
			int complement = target - nums[i];
			mymap.insert({complement, i});
		}

	}
	return result;
}

int main(){
	vector<int> nums = {3, 3};
	int target = 6;
	vector<int> res;
	res.reserve(2);
	res = twoSum(nums, target);
	for(auto x : res) cout << x << " ";
	cout << '\n';
	return 0;
}