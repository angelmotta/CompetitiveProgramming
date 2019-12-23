#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char word[21];
	scanf("%s", word);
	int len = strlen(word);
	int x=0;
	for(int i=0; i<len; ++i){
		if(word[i] != 'z') break;
		x++;
	}
	int y = len - x;
	if(2 * x == y){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}
