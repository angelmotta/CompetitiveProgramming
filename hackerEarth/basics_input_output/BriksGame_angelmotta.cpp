#include <cstdio>

int main(){
	int n, i=1, res=0;
	scanf("%d",&n);
	while(true){
		res += i;
		printf("%d ",res);
		if(res >= n){
			printf("Patlu\n");
			break;
		}
		res += i*2;
		printf("%d \n",res);
		if(res >= n){
			printf("Patlu\n");
			break;
		}
		i++;
	}
	return 0;
}