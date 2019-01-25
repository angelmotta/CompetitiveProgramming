/**
 *
 * https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/prime-number-8/
 * You are given an integer N. You need to print the series of all prime numbers till N.
Input Format
The first and only line of the input contains a single integer N denoting the number till where you need to find the series of prime number.
Output Format
Print the desired output in single line separated by spaces.
Constraints
1<=N<=1000
 *
 */

#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;										// Reading input from STDIN
    int n=2;            // iterator
    bool prime;
    if(num>=1 && num<=1000){        //check constraint
        //cout << "constraint ok" << endl;
        while(num>=n){
            prime=true;
            for(int i=2;i<n;i++){ // validate if "n" is prime number
                if(n==2){
                    cout << num << " ";
                }
                else{
                    if(n%i==0){
                        prime=false;
                        break;
                    }
                }
            }                   // validate if n is prime number
            if(prime){
                cout << n << " ";
            }
            n++;
        }
    }
}


