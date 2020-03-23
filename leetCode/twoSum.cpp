#include<iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
	int idx2 = 1;
	vector<int> result;
	result.reserve(2);
	for(int i = 0; i < nums.size() - 1; i++){
		for(int j = i+1; j < nums.size(); j++){
			if(nums[i] + nums[j] == target){
				result.push_back(i);
				result.push_back(j);
				return result;
			}
		}
	}
	return result;
}

int main(){
	vector<int> nums = {3, 2, 4};
	int target = 6;
	vector<int> res;
	res.reserve(2);
	res = twoSum(nums, target);
	for(auto x : res) cout << x << " ";
	cout << '\n';
	return 0;
}