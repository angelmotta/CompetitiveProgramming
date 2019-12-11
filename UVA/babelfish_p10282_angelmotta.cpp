#include <iostream>
#include <string>
#include <map>

using namespace std;

void updateDict(string& line, map<string, string> &dic_map){
	string en_word, fg_word;
	int index;
	index = line.find(" ");
	en_word = line.substr(0,index);
	fg_word = line.substr(index+1,-1);
	dic_map[fg_word] = en_word;
}

void translate(string& word, map<string, string> &dic_map){
	auto it = dic_map.find(word);
	if(it != dic_map.end()) cout << it->second << '\n';
	else cout << "eh\n";
}

int main(){
	string line_input;
	map<string, string> dic_map;
	while(getline(cin,line_input) && line_input.length() != 0){
		updateDict(line_input, dic_map);
	}
	while(getline(cin,line_input)){
		translate(line_input, dic_map);
	}
	return 0;
}
