#include <cstdio>

int main(){
	int n, num;
	scanf("%d",&n);
	while(n){
		scanf("%d",&num);
		n == 1 ? printf("%d\n",num) : printf("%d ",num);
		n--;
	}
	return 0;
}