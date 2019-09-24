#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int prime_list[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

void print_canonical_map(map<int, int> &canonical_map, int number){
    /*printf("--- Canonical_Map: -- \n");
    for(auto itr = canonical_map.begin(); itr != canonical_map.end(); ++itr){
        printf("key: %d - Value: %d \n", itr->first, itr->second);
    }
    
    printf("--- Result:  -- \n");
    */
    int count_line = 0;
    printf("%3d! =",number);
    for(int prime_num : prime_list){
        if(count_line == 15){
            printf("\n");
            printf("%6s","");
        }
        auto it_last = canonical_map.rbegin();
        if(prime_num == it_last->first){    // only if is the last element
            printf("%3d\n", it_last->second);
            count_line++;
            break;
        }
        for(auto itr = canonical_map.begin(); itr != canonical_map.end(); ++itr){
            if(prime_num == itr->first){
                printf("%3d", itr->second);
                count_line++;
                break;
            }
            else if(prime_num > itr->first){
                continue;
            }
            else{
                printf("%3d",0);
                count_line++;
            }
        }
    }
}

void update_canonical_map(map<int, int> &canonical_map, int factor){
    auto itr = canonical_map.find(factor); 
    if(itr != canonical_map.end()){  // if key already exist
        //printf("Key already exist...updating value successfully \n");
        canonical_map[itr->first] = itr->second + 1; // Update its existing value
    }
    else{
        //printf("Insertion successful \n");
        canonical_map.insert({factor, 1});
    }
}

void get_factors(map<int, int> &canonical_map, int number){
    int divisor = 2;
    //int counter_exponent = 0;
    while(true){
        //printf("Trying divisor : %d \n", divisor);
        if(divisor == number){
            //printf("%d es primo...Update map with \n", number);
            update_canonical_map(canonical_map, number);
            break;
        }
        else if(divisor == number-1){
            //printf("%d es primo...Update map \n", number);
            update_canonical_map(canonical_map, number);
            break;
        }
        else if(!(number%divisor)){
            //printf("%d es disible entre %d \n", number, divisor);
            number = number / divisor;
            update_canonical_map(canonical_map, divisor);
            continue;
        }
        divisor++;
    }
}

void get_canonical_map(map<int, int> &canonical_map, int number){
    while(number >= 2){
        //printf("Analize number: %d \n", number);
        get_factors(canonical_map, number);
        number--;
    }
}

int main(){
    int n = 0;
    while(scanf("%d", &n) && n != 0){
        map<int, int> canonical_map {};
        get_canonical_map(canonical_map, n);
        print_canonical_map(canonical_map, n);
    }
    return 0;
}
