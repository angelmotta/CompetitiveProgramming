#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    int opened = 0;
    std::string linea;
    char ch;
    while(scanf("%c",&ch) == 1){
        if(ch == '"'){
            if(opened){
                printf("''");
                opened = 0;
            }
            else{
                printf("``");
                opened = 1;
            }
        }
        else{
            printf("%c",ch);
        }
    }
    return 0;
}