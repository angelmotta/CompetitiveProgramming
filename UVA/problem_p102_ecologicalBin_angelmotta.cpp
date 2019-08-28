#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int n1, n2, n3, n4, n5, n6, n7, n8, n9;
	map<int,char> mapa;
	mapa[0] = 'B';
	mapa[1] = 'C';
	mapa[2] = 'G';
	while(scanf("%d %d %d %d %d %d %d %d %d",&n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9) == 9){
		int bottles[] = {n1, n2, n3, n4, n5, n6, n7, n8, n9};
		int combinaciones[3] = {0,1,2};
		int index_min_movements = 0;
		int save_index_min_movements;
		long long int temp_min_movements = 2147483648;
		do{		// Generate 6 combinations and analyze earch of them
			index_min_movements++;
			int min_movements = 0;
			//cout << combinaciones[0] << " " << combinaciones[1] << " " << combinaciones[2] << '\n';
			for(int i=0; i<3; i++){	// analiza cada una de los tres caracteres
				if(combinaciones[i] == 0){
					min_movements += bottles[(i*2)+1+i];
					min_movements += bottles[(i*2)+2+i];
				}
				if(combinaciones[i] == 1){
					min_movements += bottles[(i*2)+i];
					min_movements += bottles[(i*2)+i+1];	
				}
				if(combinaciones[i] == 2){
					min_movements += bottles[(i*2)+i];
					min_movements += bottles[(i*2)+2+i];	
				}
			}
			if(min_movements < temp_min_movements){
				temp_min_movements = min_movements;
				save_index_min_movements = index_min_movements;
			}
		}while(next_permutation(combinaciones,combinaciones+3));	// End generate 6 combinations
		
		//Output result
		index_min_movements = 0;
		do{
			index_min_movements++;
			if(save_index_min_movements == index_min_movements){
				cout << mapa[combinaciones[0]] << mapa[combinaciones[1]] << mapa[combinaciones[2]] << " " << temp_min_movements << '\n';
				break;
			}
		}while(next_permutation(combinaciones,combinaciones+3));	// End output result
	}

	return 0;
}