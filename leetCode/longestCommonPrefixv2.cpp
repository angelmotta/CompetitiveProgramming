#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Check trivial cases
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        // Get lcp between the first and second element of the array
        string lcp = "";
        int str1Len = strs[0].length();
        int str2Len = strs[1].length();
        for(int i = 0, j = 0; i < str1Len && j < str2Len; i++, j++ ){
            if(strs[0][i] != strs[1][j]){
                break;
            }
            lcp += strs[0][i];
        }
        // Check base cases
        if(lcp.length() == 0) return "";
        if(strs.size() <= 2) return lcp;
        // Verify if lcp is present from the third element in the array until the end element
        string checkStr = "";
        for(int i = 2; i < strs.size(); i++){
            checkStr = strs[i].substr(0, lcp.length());
            //cout << "Find: " << lcp << " --> in subtr: " << checkStr << " ...of element: " << strs[i] << '\n';
            if(lcp != checkStr){
                while(lcp.length()){
                    lcp = lcp.substr(0, lcp.length() - 1);  // reduce 1 char the lcp string
                    checkStr = strs[i].substr(0, lcp.length()); // get substring reduced 1 char
                    //cout << "Now check this: " << lcp << '\n';
                    if(lcp == checkStr){
                        break;
                    }
                }
            }
            if(lcp.length() == 0){
                return "";
            }
        }
        return lcp;
    }
};

int main(){
    vector<string> vec = {"flower","flow","flight"};
    vector<string> vec2 = {"dog","racecar","car"};
    vector<string> vec3 = {"",""};
    Solution s1;
	cout << s1.longestCommonPrefix(vec3) << '\n';
    return 0;
}
