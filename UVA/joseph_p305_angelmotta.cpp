#include <cstdio>

using namespace std;
// possible results
int m_results[] = {0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};		

int main(){
    int k_person;
    while(scanf("%d",&k_person) && k_person){
    	printf("%d\n",m_results[k_person]);
    }
    return 0;
}
