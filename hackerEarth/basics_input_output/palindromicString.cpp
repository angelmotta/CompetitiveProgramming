#include <iostream>
#include <cstring>

int main(){
    char s [100];
    std::cin >> s;
    int midpoint = std::strlen(s);
    midpoint = midpoint/2;
    //std::cout << "midpoint: " << midpoint << std::endl;
    bool palindromo = true;
    if(strlen(s)%2 == 1){
        for(int i=1; i <= (strlen(s)-1)/2; i++){
            if(s[midpoint-i] != s[midpoint+i]){
                palindromo = false;
                break;
            }
        }
    }
    else{
        //std::cout << "par" << std::endl;
        for(int i=1; i <= strlen(s)/2; i++){
            if(i==1){
                if(s[midpoint] != s[midpoint-i]){
                    palindromo = false;
                    break;
                }
            }
            else{
                if(s[midpoint+i-1] != s[midpoint-i]){
                    palindromo = false;
                    break;
                }
            }
        }
    }
    if(palindromo){
        std::cout << "YES";
    }
    else{
        std::cout << "NO";
    }
    return 0;
}