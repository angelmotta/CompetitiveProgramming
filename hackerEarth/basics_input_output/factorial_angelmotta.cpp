#include <cstdio>

int factorial(int num){
	if(num == 1){
		return num;
	}
	return num * factorial(num-1);
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",factorial(n));
	return 0;
}