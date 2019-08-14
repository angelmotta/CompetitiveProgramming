#include <iostream>
#include <algorithm>
#include <string>

void move_op(int x, int y){
    //std::cout << "x:" << x << " y: " << y << std::endl;
    if(x == 1 && y == 0){
        std::cout << "R" << std::endl;
    }
    else if(x == -1 && y == 0){
        std::cout << "L" << std::endl;
    }
    else if(x == 0 && y == 1){
        std::cout << "U" << std::endl;
    }
    else if(x == 0 && y == -1){
        std::cout << "D" << std::endl;
    }
    else if(x == -1 && y == 1){
        std::cout << "LU" << std::endl;
    }
    else if(x == -1 && y == -1){
        std::cout << "LD" << std::endl;
    }
    else if(x == 1 && y == 1){
        std::cout << "RU" << std::endl;
    }
    else if(x == 1 && y == -1){
        std::cout << "RD" << std::endl;
    }
}

int main(){
    std::string s, t;
    std::cin >> s >> t;
    int s_x, t_x, s_y, t_y, x_dist, y_dist, x_move=0, y_move=0, x, y;
    s_x = s[0] - 96;
    s_y = s[1] - 48;
    t_x = t[0] - 96;
    t_y = t[1] - 48;
    //std::cout << "s: " << s_x << "," << s_y << " t: " << t_x << ","<< t_y << std::endl;
    x_dist = t_x - s_x;
    y_dist = t_y - s_y;
    int sp =  std::max(abs(x_dist), abs(y_dist));
    std::cout << sp << std::endl;
    for(int i=0; i<sp; i++){
        if(x_dist > 0){
            if(x_move < x_dist){
                x_move++;
                x = 1;
            }
            else{
                x = 0;
            }
        }
        else{
            if(x_move > x_dist){
                x_move--;
                x = -1;
            }
            else{
                x = 0;
            }
        }
        if(y_dist > 0){
            if(y_move < y_dist){
                y_move++;
                y = 1;
            }
            else{
                y = 0;
            }
        }
        else{
            if(y_move > y_dist){
                y_move--;
                y = -1;
            }
            else{
                y = 0;
            }
        }
        move_op(x, y);
    }
    return 0;
}