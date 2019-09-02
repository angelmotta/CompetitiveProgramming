#include <iostream>

using namespace std;

int min_mov;

void swap(int *x,int *y){
	min_mov++;
    int temp = *x;
    *x = *y;
    *y = temp;
}  

void bubble(int* elements, int size) {
    for(int i=0; i<size; i++){
        for(int j=0; j<size-i-1; j++){
            if(elements[j] > elements[j+1]){
                swap(&elements[j], &elements[j+1]);
            }
        }
    }
}

int main(){
	int arr_size, number;
	while(scanf("%d",&arr_size) == 1){
		min_mov = 0;
		int* arr = new int[arr_size];
		for(int i=0; i<arr_size; ++i){
			scanf("%d", &number);
			//printf("%d \n", number);
			arr[i] = number;
		}
		bubble(arr, arr_size); 
		printf("Minimum exchange operations : %d\n", min_mov);
	}
}

