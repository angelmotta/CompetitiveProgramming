#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, q, num, qnum, num_case = 1;
	while(scanf("%d %d",&n,&q)){
		vector<int> numbers;
		if(n == 0 && q == 0) break;
		for(int i=0; i<n; ++i){
			scanf("%d",&num);
			numbers.push_back(num);
		}
		sort(numbers.begin(), numbers.end());
		printf("CASE# %d:\n",num_case);
		for(int i=0; i<q; ++i){
			scanf("%d",&qnum);
			auto it = find(numbers.begin(), numbers.end(), qnum);
			if(it != numbers.end()){
				int index = distance(numbers.begin(), it);
				printf("%d found at %d\n",qnum,index+1);
			}
			else printf("%d not found\n",qnum);
		}
		num_case++;
	}
	return 0;
}