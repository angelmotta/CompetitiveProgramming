#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
	int n, type, num;
	while(cin >> n){	// for each data structure
		queue<int> q;
		stack<int> s;
		priority_queue<int> pq;
		bool isQueue = true, isStack = true, isPq = true;
		int ds = -1;
		for(int i=0; i<n; ++i){
			cin >> type >> num;
			if(type == 1){
				if(isQueue){
					q.push(num);
				}
				if(isStack){
					s.push(num);
				}
				if(isPq){
					pq.push(num);
				}
			}
			else if(type == 2){
				if(isQueue){
					if(q.empty() || q.front() != num){
						isQueue = false;
					}
					else{
						q.pop();		// if actually is Queue keep true and pop the element from the DS
					}
				}
				if(isStack){
					if(s.empty() || s.top() != num){
						isStack = false;
					}
					else{
						s.pop();		// if actually is Stack, keep in true and pop the element from the DS
					}
				}
				if(isPq){
					if(pq.empty() || pq.top() != num){
						isPq = false;
					}
					else{
						pq.pop();
					}
				}
			}
		}
		// Determine which DS we have
		if( (isQueue && isPq) || (isStack && isPq) || (isQueue && isStack) ){
			cout << "not sure\n";
		}
		else if(!isQueue && !isStack &&!isPq){
			cout << "impossible\n";
		}
		else if(isQueue){
			cout << "queue\n";
		}
		else if(isStack){
			cout << "stack\n";
		}
		else if(isPq){
			cout << "priority queue\n";
		}
	}
	return 0;
}

