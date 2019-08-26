#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

long long int operaciones = 0;


int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string texto, linea, word, other_word;
	vector<string> palabras;
	vector<string> anagrams_relative;
	vector<string> black_list;
	int word_active = 0;
	int anagrama_word;

	while(getline(cin, linea)){
		if(linea.length() == 1 && linea == "#"){
			break;
		}
		texto += linea;
		texto += '\n';
	}
	
	//auto t1 = std::chrono::high_resolution_clock::now();
	for(auto letra : texto){
		if(letra == ' ' || letra == '\n'){
			if(word_active){
				palabras.push_back(word);
				word = "";
				word_active = 0;
			}
			continue;
		}
		word_active = 1;
		word += letra;
	}

	int last_valid = 1;
	for(size_t i=0;i<palabras.size()-1;++i){
		operaciones += 1;
		anagrama_word = 1;		
		word = palabras[i];
		// Check Black list
		for(auto element_black_list : black_list){
			operaciones += 1;
			if(word == element_black_list){
				//cout << "Ahorrando el analisis de: " << word << '\n';
				anagrama_word = 0;
				break;
			}
		}
		if(!anagrama_word) continue;
		transform(word.begin(), word.end(), word.begin(), [](unsigned char c){return tolower(c); });	// convert word to lower
		sort(word.begin(),word.end());																	// sort word
		for(size_t j=i+1; j<palabras.size();++j){		// compara con el resto de palabras
			operaciones += 1;
			other_word = palabras[j];
			transform(other_word.begin(), other_word.end(), other_word.begin(), [](unsigned char c){return tolower(c); });	// convert word to lower
			sort(other_word.begin(),other_word.end());		// sort word
			if(word == other_word){
				black_list.push_back(palabras[j]);
				anagrama_word = 0;
				if(j == palabras.size()-1){
					last_valid = 0;
				}
			}
		}
		if(anagrama_word){
			anagrams_relative.push_back(palabras[i]);
		}
	}
	if(last_valid){
		anagrams_relative.push_back(palabras.back());
	}
	sort(anagrams_relative.begin(), anagrams_relative.end());
	for(auto element : anagrams_relative){
		cout << element << '\n';
	}
	
	/*auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
	std::cout << "duration: " <<duration << " milliseconds" << '\n';
	std::cout << "operaciones: " << operaciones << '\n';*/
	return 0;
}

