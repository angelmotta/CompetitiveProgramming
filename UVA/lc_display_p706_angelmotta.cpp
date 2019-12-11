#include <cstdio>
#include <string>

using namespace std;

void print(int &s, int& n);
void printNumber(char &digit,int &fila, int &rows, int &cols);
void print_0(int &fila, int &rows, int &cols);
void print_1(int &fila, int &rows, int &cols);
void print_2(int &fila, int &rows, int &cols);
void print_3(int &fila, int &rows, int &cols);
void print_4(int &fila, int &rows, int &cols);
void print_5(int &fila, int &rows, int &cols);
void print_6(int &fila, int &rows, int &cols);
void print_7(int &fila, int &rows, int &cols);
void print_8(int &fila, int &rows, int &cols);
void print_9(int &fila, int &rows, int &cols);

int main(){
	int s,n;
	while(scanf("%d %d",&s,&n) != EOF){
		if(s == 0 && n == 0) break;
		print(s, n);
		printf("\n");
		//printf("Ingresaste:%d\n",s);
	}
	return 0;
}

void print(int &s, int& n){
	int rows = 2 * s + 3;
	int cols = s + 2;
	string num = to_string(n);
	/*for(int index=0; index<num.length();++index){
		//printf("%c ", num[index]);
		printNumber(num[index], rows, cols);
	}*/
	for(int i=0; i<rows; ++i){
		for(int index=0; index<num.length();++index){
			//printf("%c ", num[i]);
			printNumber(num[index], i, rows, cols);
			if(index < num.length() - 1) printf(" ");
		}
		printf("\n");	// endl for the next row of the number
	}
}

void printNumber(char &digit,int &fila, int &rows, int &cols){
	switch(digit){
		case '0': print_0(fila, rows, cols); break;
		case '1': print_1(fila, rows, cols); break;
		case '2': print_2(fila, rows, cols); break;
		case '3': print_3(fila, rows, cols); break;
		case '4': print_4(fila, rows, cols); break;
		case '5': print_5(fila, rows, cols); break;
		case '6': print_6(fila, rows, cols); break;
		case '7': print_7(fila, rows, cols); break;
		case '8': print_8(fila, rows, cols); break;
		case '9': print_9(fila, rows, cols); break;
	}
}

void print_0(int &fila, int &rows, int &cols){
	for(int i=0; i<rows; ++i){
		if(i != fila) continue;
		for(int j=0; j<cols; ++j){
			if(i == 0 || i == rows-1){
				if(j == 0 || j == cols-1){
					printf(" ");
				}
				else printf("-");
			}
			else if(i != rows/2){
				if(j == 0 || j == cols-1) printf("|");
				else printf(" ");
			}
			else printf(" ");
		}
		//printf("\n");	// endl for the next row
	}
}

void print_1(int &fila, int &rows, int &cols){
	for(int i=0; i<rows; ++i){
		if(i != fila) continue;
		for(int j=0; j<cols; ++j){
			if(j == cols - 1){
				if(i == 0 || i == rows/2 || i == rows-1){
					printf(" ");
				}
				else printf("|");
			}
			else printf(" ");
		}
		//printf("\n");	// endl for the next row
	}
}

void print_2(int &fila, int &rows, int &cols){
	for(int i=0; i<rows; ++i){
		if(i != fila) continue;
		for(int j=0; j<cols; ++j){
			if(i == 0 || i == rows/2 || i == rows-1){
				if(j == 0 || j == cols-1){
					printf(" ");
				}
				else printf("-");
			}
			else if(i < rows/2){
				if(j != cols-1) printf(" ");
				else printf("|");
			}
			else{
				if(j == 0) printf("|");
				else printf(" ");
			}
		}
		//printf("\n");	// endl for the next row
	}
}

void print_3(int &fila, int &rows, int &cols){
	for(int i=0; i<rows; ++i){
		if(i != fila) continue;
		for(int j=0; j<cols; ++j){
			if(i == 0 || i == rows/2 || i == rows-1){
				if(j == 0 || j == cols-1){
					printf(" ");
				}
				else printf("-");
			}
			else{
				if(j != cols-1) printf(" ");
				else printf("|");
			}
		}
		//printf("\n");	// endl for the next row
	}
}

void print_4(int &fila, int &rows, int &cols){
	for(int i=0; i<rows; ++i){
		if(i != fila) continue;
		for(int j=0; j<cols; ++j){
			if(i == 0 || i == rows-1){
				printf(" ");
			}
			else if(i < rows/2){
				if(j == 0 || j == cols-1) printf("|");
				else printf(" ");
			}
			else if(i == rows/2){
				if(j == 0 || j == cols-1) printf(" ");
				else printf("-");
			}
			else{
				if(j != cols-1) printf(" ");
				else printf("|");
			}
		}
		//printf("\n");	// endl for the next row
	}
}

void print_5(int &fila, int &rows, int &cols){
	for(int i=0; i<rows; ++i){
		if(i != fila) continue;
		for(int j=0; j<cols; ++j){
			if(i == 0 || i == rows/2 || i == rows-1){
				if(j == 0 || j == cols-1){
					printf(" ");
				}
				else printf("-");
			}
			else if(i < rows/2){
				if(j == 0) printf("|");
				else printf(" ");
			}
			else{
				if(j != cols-1) printf(" ");
				else printf("|");
			}
		}
		//printf("\n");	// endl for the next row
	}
}

void print_6(int &fila, int &rows, int &cols){
	for(int i=0; i<rows; ++i){
		if(i != fila) continue;
		for(int j=0; j<cols; ++j){
			if(i == 0 || i == rows/2 || i == rows-1){
				if(j == 0 || j == cols-1){
					printf(" ");
				}
				else printf("-");
			}
			else if(i < rows/2){
				if(j == 0) printf("|");
				else printf(" ");
			}
			else{
				if(j == 0 || j == cols-1) printf("|");
				else printf(" ");
			}
		}
		//printf("\n");	// endl for the next row
	}
}

void print_7(int &fila, int &rows, int &cols){
	for(int i=0; i<rows; ++i){
		if(i != fila) continue;
		for(int j=0; j<cols; ++j){
			if(i == 0){
				if(j == 0 || j == cols-1){
					printf(" ");
				}
				else printf("-");
			}
			else if(i == rows/2 || i == rows-1) printf(" ");
			else{
				if(j != cols-1) printf(" ");
				else printf("|");
			}
		}
		//printf("\n");	// endl for the next row
	}
}

void print_8(int &fila, int &rows, int &cols){
	for(int i=0; i<rows; ++i){
		if(i != fila) continue;
		for(int j=0; j<cols; ++j){
			if(i == 0 || i == rows/2 || i == rows-1){
				if(j == 0 || j == cols-1){
					printf(" ");
				}
				else printf("-");
			}
			else{
				if(j == 0 || j == cols-1) printf("|");
				else printf(" ");
			}
		}
		//printf("\n");	// endl for the next row
	}
}

void print_9(int &fila, int &rows, int &cols){
	for(int i=0; i<rows; ++i){
		if(i != fila) continue;
		for(int j=0; j<cols; ++j){
			if(i == 0 || i == rows/2 || i == rows-1){
				if(j == 0 || j == cols-1){
					printf(" ");
				}
				else printf("-");
			}
			else if(i < rows/2){
				if(j == 0 || j == cols-1) printf("|");
				else printf(" ");
			}
			else{
				if(j != cols-1) printf(" ");
				else printf("|");
			}
		}
		//printf("\n");	// endl for the next row
	}
}