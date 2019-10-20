#include <cstdio>
#include <string.h>
#include <cmath>


void getMinBase(char* x, int &min_base){
	char* t;
	char max = '0';
	for(t = x; *t != '\0'; ++t){
		if(*t > max) max = *t;
	}
	//printf("end for min base: %c\n", max);
	if(max >= 65){	// base is letter
		min_base = int(max) - 55;		// ' A' has value 65 in ascii table
	}
	else{
		min_base = max - '0';
	}
	//min_base += 1;
	min_base = (min_base == 0) ? min_base + 2 : min_base + 1;
	//printf("min base: %d\n", min_base);
}

int getValueFromThisBase(char *x, int base_num){
	int value_num = 0;
	//printf("Length:%d \n", (int)strlen(x));
	int len_num = (int)strlen(x);
	int num_power = len_num - 1;
	for(int i=0; i<len_num; ++i){
		if(*x >= 65){	// number is letter
			//printf("num: %d * base: %d exponente: %d \n", *x - '7', base_num, num_power);	//casting
			value_num += (*x - '7') * pow(base_num, num_power);
		}
		else{
			//printf("num: %d * base: %d exponente: %d \n", *x - '0', base_num, num_power);	//casting
			value_num += (*x - '0') * pow(base_num, num_power);
		}
		num_power--;
		++x;
	}
	return value_num;
}

void getEqualValues(char *x, int &min_base_x, char* y, int &min_base_y){
	int value_x=0, value_y=0;
	bool equal = 0;
	while(min_base_x <= 36 && min_base_y <= 36){
		value_x = getValueFromThisBase(x,min_base_x);
		value_y = getValueFromThisBase(y,min_base_y);
		if(value_x == value_y){
			//printf("GOT IT %d - %d \n", value_x, value_y);
			printf("%s (base %d) = %s (base %d)\n",x, min_base_x, y, min_base_y);
			return;
		}
		else if(value_x > value_y){
			min_base_y++;
		}
		else{
			min_base_x++;
		}
	}
	printf("%s is not equal to %s in any base 2..36\n",x, y);
	return;
}


int main(){
	char x[100], y[100];
	int min_base_x = 0, min_base_y = 0;
	int value_x=0, value_y=0;
	while(scanf("%s %s",x,y) != EOF){
		getMinBase(x, min_base_x);
		getMinBase(y, min_base_y);
		getEqualValues(x, min_base_x, y, min_base_y);
	}
	return 0;
}