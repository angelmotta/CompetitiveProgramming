#include <cstdio>
#include <vector>
#include <string>

using namespace std;

void printArabic(char *num){
	//printf("Print Arabic \n");
	int num_divisors[] = {1, 5, 10, 50, 100, 500, 1000};
	char roman_letters[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	int index_arr = 0;
	int result = 0;
	for(int i=0; num[i] != '\0'; ++i){
		for(int j=0; j<7; ++j){
			if(num[i] == roman_letters[j]){
				if(num[i+1] != '\0'){
					int neg = 0;
					for(int k=j+1; k<7; ++k){
						if(num[i+1] == roman_letters[k]){
							//printf("detected ahead: %c\n",roman_letters[k]);
							//printf("resta %d \n",num_divisors[j]);
							result -= num_divisors[j];
							neg = 1;
							break;
						}
					}
					if(!neg) result += num_divisors[j];	
				}
				else result += num_divisors[j];
				break;
			}
		}
	}
	printf("%d\n", result);
}

void printRoman(int num){
	string roman_num = "";
	//printf("Print Roman number of %d \n", num);
	int num_divisors[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
	string roman_letters[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
	int index_arr = 12;
	while(num > 0){
		int quotient = num / num_divisors[index_arr];
		num = num % num_divisors[index_arr];
		while(quotient > 0){
			roman_num += roman_letters[index_arr];
			quotient--;
		}
		index_arr--;	// reduce divisor number using the index of the array num_divisors[]
	}
	printf("%s\n",roman_num.c_str());
}

int main(){
	char num[4];
	while(scanf("%s",num) != EOF){
		int isRoman = 0;
		if(num[0] >= 65) isRoman = 1;
		if(isRoman){
			printArabic(num);
		}
		else{	// number given is Arabic
			int num_arabic = atoi(num);
			printRoman(num_arabic);
		}
	}
}
