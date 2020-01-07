#include <cstdio>

int main(){
	int l, n, w, h;
	scanf("%d%d",&l, &n);
	//printf("Ingresaste: %d %d\n", l, n);
	while(n){
		scanf("%d%d",&w, &h);
		if( w < l || h < l){
			printf("UPLOAD ANOTHER\n");
		}
		else if(w >= l && h >= l){	
			if(w == h){
				printf("ACCEPTED\n");
			}
			else printf("CROP IT\n");
		}
		n--;
	}
	return 0;
}