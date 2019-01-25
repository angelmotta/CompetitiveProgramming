/**
 * You have been given an array A of size N consisting of positive integers. You need to find and print the product of all the number in this array Modulo 10^9+7.

Input Format:
The first line contains a single integer N denoting the size of the array. The next line contains N space separated integers denoting the elements of the array

Output Format:
Print a single integer denoting the product of all the elements of the array Modulo 10^9+7.
 *
 */
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    vector<int> vect;
    int n, element;
    unsigned long long int answer=1;
    int i=0;

    cin >> n;
    while(i<n){
        cin >> element;
        vect.push_back(element);
        i++;
    }
    for (i=0; i< vect.size(); i++){
        //cout << vect.at(i) << endl;
        answer = (answer * vect.at(i))%(1000000000 + 7);
        //cout << answer << endl;
    }
    cout << answer;
}
