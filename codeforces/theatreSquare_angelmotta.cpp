#include <cstdio>

int main(){
	int n,m,a;
	long long int res,x,y;
	scanf("%d %d %d",&n,&m,&a);
	x = (n+a-1)/a;	// Ceil(n/a)
	y = (m+a-1)/a;
	res = x*y;
	printf("%lld\n",res);
	return 0;
}