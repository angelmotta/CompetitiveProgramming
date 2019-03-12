#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <stack>
#include <algorithm>

/*
 * https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/anagrams-651/
 *
 */

using namespace std;

int main() {
    //string a, b;
    int t_cases, delets;
    string a, b, a_copy, b_copy;
    bool match;

    cin >> t_cases;
    for(int i = 0; i < t_cases; i++){
        cin >> a >> b;
        delets = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        a_copy = a;
        b_copy = b;
        // recorre caracteres del string A
        //cout << "---- Recorre String A: " << a << "-----" << endl;
        for(int j = 0; j < a.length(); j++){
            match = false;
            for(int k = 0; k < b_copy.length(); k++){   // compara con caracteres de string B
                if(a[j] == b_copy[k]){
                    match = true;
                    b_copy = b_copy.substr(k+1);
                    //cout << "Match found -> Nuevo string B: " << b_copy << endl;
                    //cout << "Recorrió " << k << " caracteres que deben borrarse." << endl;
                    delets += k;
                    break;
                }
            }
            if (!match){    //si caracter de A no esta en B
                delets += 1;
                //cout << "String A - No encontró match para: " << a[j] << endl;
            }
        }

        cout << delets + b_copy.length() << endl;
    }

    return 0;
}
