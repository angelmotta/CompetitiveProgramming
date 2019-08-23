#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	std::map<std::string, int> mapa;
	std::vector<std::string> names_vector;

	int n, space;
	std::string country, linea;

	std::cin >> n;
	std::cin.ignore();
	//n = 4;
	while(n--){
		//std::cout << n << std::endl;
		std::getline (std::cin, linea);
		for(int i=0; i<linea.length(); i++){
			if(linea[i] == ' '){
				space = i;
				break;
			}
		}
		country = linea.substr(0,space);
		if(mapa[country] != 0){
			mapa[country] = mapa[country] + 1;
		}
		else{
			mapa[country] = 1;
		}
		//std::cout << "country: " << country << std::endl;
		//std::cout << "spain: " << mapa[country] << std::endl;
	}
	for (auto &item : mapa){
		//std::cout << item.first << " : " << item.second << std::endl;
		names_vector.push_back(item.first);
	}
	sort(names_vector.begin(), names_vector.end());

	for (auto &country : names_vector){
		std::cout << country << " " << mapa[country] << std::endl;
	}
    return 0;
}