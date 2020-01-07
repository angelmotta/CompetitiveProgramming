#include <cstdio>

int main(){
	int n, i=1, res=0, tmp=0;
	scanf("%d",&n);
	while(true){
		//printf("pat: %d, ", i);
		res += i;
		//printf("res: %d, ",res);
		if(res >= n){
			printf("Patlu\n");
			break;
		}
		//printf("mot: %d, ", i*2);
		res += i*2;
		//printf("res: %d \n",res);
		if(res >= n){
			printf("Motu\n");
			break;
		}
		i++;
	}
	return 0;
}