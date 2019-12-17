#include <iostream>
#include <list>
using namespace std;


void printDS(const int& ds){
	switch(ds){
		case 0: cout << "queue\n"; break;
		case 1: cout << "stack\n"; break;
		case 2: cout << "priority queue\n"; break;
		case 3: cout << "impossible\n"; break;
		case 4: cout << "not sure\n"; break;
	}
}

void printList(list<int>& list_num){
	for(auto it = list_num.begin(); it != list_num.end(); ++it) cout << *it << " ";
	cout << "\n";
}

void isPriorityQueue(list<int>& list_num, int& num, int& pq, int& ds){
	int max = -1;
	list<int>::iterator itr_max;
	for(auto it = list_num.begin(); it != list_num.end(); ++it){
		if(*it > max){
			max = *it;
			itr_max = it;
		}
	}
	if( ((max == num) && pq) || ((max == num) && (pq == -1)) ){		//if num is max
		//cout << "...priority Queue\n";
		pq = 1;
		if(ds != 0 && ds != 1){
			list_num.erase(itr_max);	// delete max element (last) from the list
			//cout << "Only priority Queue\n";
			ds = 2;						// only Priority Queue
		}
		//printList(list_num);
	}
	else{
		//cout << "No es Priority Queue\n";
		//printList(list_num);
		if(ds == -1 || ds == 2){
			//cout << "Set impossible\n";
			ds = 3;	// impossible
		}
		pq = 0;
	}
}

void identifyDS(list<int>& list_num, int& num, int& ds, int& pq){
	if(list_num.size() == 0) return;
	if(list_num.size() == 1){	// Edge case: list with 1 element
		if(list_num.front() == num){
			//cout << "size: 1 - Not yet sure...pq=1\n";
			pq = 1;
			list_num.pop_front();
		}
		else{
			ds = 3;					// impossible
		}
		return;
	}
	// Identify Data Structure
	if(list_num.front() == num){	// queue
		//cout << "...queue\n";
		ds = 0;
		isPriorityQueue(list_num, num, pq, ds);
		list_num.pop_front();
	}
	else if(list_num.back() == num){	// stack
		//cout << "...stack\n";
		ds = 1;
		isPriorityQueue(list_num, num, pq, ds);
		list_num.pop_back();
	}
	else{		// if we have at least 2 elements
		//cout << "...check is priority queue?? \n";
		isPriorityQueue(list_num, num, pq, ds);
	}
}

void confirmDS(list<int>& list_num, int& num, int& ds, int& pq){
	if(ds == 0){	// queue
		if(list_num.front() == num){
			//cout << "ConfirmDS queue..\n";
			isPriorityQueue(list_num, num, pq, ds);
			list_num.pop_front();
			return;
		}
		else if(pq){
			//cout << "No es queue..\n";
			ds = 2;
			isPriorityQueue(list_num, num, pq, ds);
		}
		else{
			//cout << "---Set impossible\n";
			ds = 3;	// set status to impossible
		}
	}
	else if(ds == 1){		
		if(list_num.back() == num){
			//cout << "ConfirmDS stack..\n";
			isPriorityQueue(list_num, num, pq, ds);
			list_num.pop_back();
			return;
		}
		else{
			//cout << "No es stack..\n";
			if(!pq){
				ds = 3;	// set status to impossible
			}
			else{
				ds = 2;
				isPriorityQueue(list_num, num, pq, ds);
				//cout << "Is only pq ds:2\n";
				//if(pq) ds = 2;
			}
		}
	}
	else if(ds == 2 || pq == 1){	// only Priority Queue
		//cout << "Check only if is Priority Queue\n";
		isPriorityQueue(list_num, num, pq, ds);
	}
}

int main(){
	int n, type, num;
	while(cin >> n){	// for each data structure
		list<int> list_num;
		int ds=-1, pq=-1;
		for(int i=0; i<n; ++i){
			cin >> type >> num;
			if(type == 1){
				list_num.push_back(num);
			}
			else if(type == 2){
				if(ds == -1){
					//cout << "Identify DS\n";
					identifyDS(list_num, num, ds, pq);	
				}
				else{
					if(ds != 3) confirmDS(list_num, num, ds, pq);
				}
			}
		}
		if((ds == 0 && pq) || (ds == 1 && pq)){
			ds = 4;			// not sure
		}
		else if(pq == 1 && ds == 2){
			ds = 2;
		}
		else if(ds == -1){
			ds = 4;
		}
		printDS(ds);
	}
	return 0;
}

