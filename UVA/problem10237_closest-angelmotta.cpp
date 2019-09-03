#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;
struct Punto{
    double x, y;
    double calculateDistance(const Punto& destino){
        return sqrt((destino.x - x)*(destino.x - x) + (destino.y - y)*(destino.y - y));
    }

}arr_points[10000];


bool customSort(const Punto& a, const Punto& b){
    return (a.x < b.x);
}

int main(){
    int number_points;
    double min_distanace, distance;
    while(scanf("%d", &number_points) && number_points){
        for(int i = 0; i < number_points; ++i){
            scanf("%lf%lf", &arr_points[i].x, &arr_points[i].y);
        }

        std::sort(arr_points, arr_points + number_points, customSort);

        min_distanace = 10000;
        for(int i = 0; i < number_points; ++i){
            for(int j = i + 1; j < number_points; ++j){
                distance = arr_points[j].x - arr_points[i].x;
                if(distance >= min_distanace) break;
                //if(point[i].x + min_distanace < point[j].x) break;
                double distance = arr_points[i].calculateDistance(arr_points[j]);
                if (distance < min_distanace){
                    min_distanace = distance;
                }
            }
        }
        if (min_distanace == 10000){
            printf("INFINITY\n");
        }
        else{
            printf("%.4lf\n", min_distanace);
        }
    }
    
    return 0;
}