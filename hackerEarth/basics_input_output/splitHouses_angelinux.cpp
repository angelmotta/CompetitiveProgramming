#include <iostream>

using namespace std;

int main(){
	string village, ch;
	int n, h;
	cin >> n;
	cin >> village;
	h =  count(village.begin(), village.end(), 'h');
	cout << h << '\n';
	return 0;
}