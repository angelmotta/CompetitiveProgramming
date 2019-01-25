/**
 *
 * https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/seating-arrangement-1/
 *
 * Akash and Vishal are quite fond of travelling. They mostly travel by railways. They were travelling in a train one day and they got interested in the seating arrangement of their compartment. The compartment looked something like
So they got interested to know the seat number facing them and the seat type facing them. The seats are denoted as follows :

Window Seat : WS
Middle Seat : MS
Aisle Seat : AS

You will be given a seat number, find out the seat number facing you and the seat type, i.e. WS, MS or AS.

INPUT
First line of input will consist of a single integer T denoting number of test-cases. Each test-case consists of a single integer N denoting the seat-number.

OUTPUT
For each test case, print the facing seat-number and the seat-type, separated by a single space in a new line.

CONSTRAINTS
1<=T<=105
1<=N<=108
 */

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main(){
    int t, n;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        if((n+1)%3 == 0){   // MS
            if(n%2==0 && n%4==2){       // seats: 2,14,26,38
                cout << n + 9 << " MS" << endl;
            }
            else if(n%2==0 && n%4==0){  // seats: 8,20,32,44
                cout << n-3 << " MS" << endl;
            }
            else if(n%12==11){          // seats: 11,23,35,47
                cout << n-9 << " MS" << endl;
            }
            else if(n%12==5){           // seats: 5,17,29,41
                cout << n+3 << " MS" << endl;
            }
        } // MS
        else if(n%3==0 && (n+1)%4==0){       // AS seats: 3,15,27,39        // FALTAN AS
            cout << n+7 << " AS" << endl;
        }
        else if(n%12==10 && n%2==0){     // AS seats: 10,22,34,46
            cout << n-7 << " AS" << endl;
        }
        else if(n%4==0 && (n-1)%3==0){          // AS seats: 4,16,28,40,52
            cout << n+5 << " AS" << endl;
        }
        else if(n%12==9){    // AS seats: 9,21,33,45
            cout << n-5 << " AS" << endl;
        }// MS
        else{           // WS
            if(n%12==0){
                cout << n-11 << " WS" << endl;  //WS : 12,24,36..
            }
            else if((n-1)%12==0){               // WS: 13,25,37
                cout << n+11 << " WS" << endl;
            }
            else if(n%12==7){                   // WS: 7,19,31,43
                cout << n-1 << " WS" << endl;
            }
            else if(n%12==6){                   // WS: 6,18,30,42
                cout << n+1 << " WS" << endl;
            }
        }    // WS
    }
}