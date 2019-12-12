#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int getIndex(int& num, vector<int>& vec_nums){
	int index;
	auto it = find(vec_nums.begin(), vec_nums.end(), num);
	if(it != vec_nums.end()){
		index = distance(vec_nums.begin(), it);
		return index;
	}
	else return -1;
}

void checkIndexPattern(int& idx, int& prev_idx, int& ds, const vector<int>& vec_nums, int& pq_state){
	int current_ds = -1;
	if(idx == prev_idx-1){		// stack: if indexes are decreasing
		if(vec_nums[idx] < vec_nums[prev_idx] && pq_state){
			pq_state = 1;				// priority queue
		}
		else pq_state = 0;
		current_ds = 0;
	}
	else if(idx-1 == prev_idx){		// queue: if indexes are increasing
		if(vec_nums[idx] < vec_nums[prev_idx] && pq_state){
			pq_state = 1;				// priority queue
		}
		else pq_state = 0;
		current_ds = 1;
	}
	else{						// maybe priority queue
		//cout << "could be priority queue...not yet confirmed\n";
		if(vec_nums[idx] < vec_nums[prev_idx]){
			current_ds = 2;				// priority queue
		}
	}
	// Check there is not change of DS Status
	if(ds == -1){	// first check
		ds = current_ds;
	}
	else{	// at least second check 
		if(current_ds == ds){
			return;
		}
		else{
			ds = 3;		// impossible, it can't be stack, queue or priority queue
		}
	}
}

void printDS(const int& ds){
	switch(ds){
		case 0: cout << "stack\n"; break;
		case 1: cout << "queue\n"; break;
		case 2: cout << "priority queue\n"; break;
		case 3: cout << "impossible\n"; break;
		case 4: cout << "not sure\n"; break;
	}
}

int main(){
	int n, type, num;
	while(cin >> n){	// for each data structure
		vector<int> vec_num;
		int idx, num_op=0, prev_idx, ds=-1, pq_state=1;
		for(int i=0; i<n; ++i){
			cin >> type >> num;
			if(type == 1){
				vec_num.push_back(num);
			}
			else if(type == 2){
				num_op++;
				if(num_op >= 2){
					prev_idx = idx;
				}
				idx = getIndex(num, vec_num);
				if(idx == -1) ds = 3;			// ds = 3 "impossible"
				if(num_op >= 2 && ds != 3){
					checkIndexPattern(idx, prev_idx, ds, vec_num, pq_state);
				}
			}
		}
		if(ds == 0 && pq_state) ds = 4;
		if(ds == 1 && pq_state) ds = 4;
		printDS(ds);
	}
	return 0;
}

