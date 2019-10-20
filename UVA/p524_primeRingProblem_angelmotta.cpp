#include <cstdio> 

using namespace std;

int num_case = 0;
int n;
int ringPrime_candidate[20];
bool num_used[20];

int prime_list[] = {2,3,5,7,11,13,17,19,23,29,31};

bool isPrime(int num){
	for(int i=0; i<11; ++i){
		if(num == prime_list[i]) return true;
		if(!(prime_list[i] < num)) return false;
	}
	return false;
}

void printRingPrime(){
	for(int i = 0; i < n; i++){
		printf(i == n - 1? "%d" : "%d ", ringPrime_candidate[i]);
	}
	printf("\n");
}

void generateRingPrime(int last_valid_index) {
	// if is the last element of the ring....check if head + tail is prime -> and print the ringPrime_candidate
	if(last_valid_index == n - 1 && isPrime(ringPrime_candidate[n - 1] + ringPrime_candidate[n])) {
		printRingPrime();
		return;
	}
	for(int i = 2; i <= n; i++){
		if(!num_used[i] && isPrime(ringPrime_candidate[last_valid_index] + i)) {
			num_used[i] = true;
			ringPrime_candidate[last_valid_index + 1] = i;
			generateRingPrime(last_valid_index + 1);
			num_used[i] = false;
		}
	}
}


int main(){
	while(scanf("%d", &n) == 1){
		num_case++;
		if(num_case > 1) printf("\n");
		ringPrime_candidate[0] = ringPrime_candidate[n] = 1;  // first (head) has value '1'...Head is on index '0' and index 'n'
		printf("Case %d:\n", num_case);
		generateRingPrime(0);
	}
	return 0;
}