#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = 1000000;
        string minWord = "";
        for(auto element : strs){
            //cout << element << '\n';
            if(element.size() < minLen){
                minLen = element.size();
                minWord = element;
            }
        }
        //cout << minWord << ", len: " << minLen << '\n';
        int startIdx = 0;
        int endIdx = 0;
        int maxLen = -1;
        string res = "";
        for(int i = 0; i < minLen; i++){
            string prefix = minWord.substr(startIdx, endIdx - startIdx + 1);
            // cout << "Check prefix: " << prefix << '\n';
            // compare with all others Strings in the array
            bool isCommonPrefix = true;
            for(int j = 0; j < strs.size(); j++){
                if(strs[j].substr(startIdx, endIdx - startIdx + 1) != prefix){
                    // cout << "Not Found in " << strs[j] << '\n';
                    isCommonPrefix = false;
                    break;
                }
            }
            //cout << "--------\n";
            if(!isCommonPrefix){
                break;
            }
            res = prefix.substr(startIdx, endIdx - startIdx + 1);
            endIdx++;
        }
        cout << res << '\n';
        return res;
    }
};

int main(){
    vector<string> vec = {"flower","flow","flight"};
    vector<string> vec2 = {"dog","racecar","car"};
    Solution s1;
	s1.longestCommonPrefix(vec);
	return 0;
}