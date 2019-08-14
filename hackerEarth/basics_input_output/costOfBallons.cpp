#include <iostream>
#include <algorithm>

int main(){
    int T, g_cost, p_cost, n, p1 = 0, p2 = 0;
    int temp_p1, temp_p2;
    std::cin >> T;
    for(int i=0; i<T; i++){
        std::cin >> g_cost >> p_cost >> n;
        //std::cout << "g_cost: " << g_cost << " p_cost: " << p_cost << " n: " << n << std::endl;
        for(int j=0; j<n; j++){
            std::cin >> temp_p1 >> temp_p2;
            p1 += temp_p1;
            p2 += temp_p2;
        }
        std::cout << std::min(p1 * g_cost + p2 * p_cost, p2 * g_cost + p1 * p_cost) << std::endl;
        p1 = 0;
        p2 = 0;
    }
}
