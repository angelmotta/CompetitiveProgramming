#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:

    string commonPrefixUtil(string str1, string str2){ 
        string result; 
        int n1 = str1.length(), n2 = str2.length(); 
        for (int i = 0, j = 0; i <= n1 - 1 && j <= n2 - 1; i++, j++){ 
            if (str1[i] != str2[j]){ 
                break; 
            }
            result.push_back(str1[i]); 
        } 
        return (result); 
    } 

    string commonPrefix(vector<string>& arr, int low, int high){ 
        if (low == high){ 
            return (arr[low]); 
        }
        if (high > low) { 
            // Same as (low + high)/2, but avoids overflow for 
            // large low and high 
            int mid = low + (high - low) / 2; 
    
            string str1 = commonPrefix(arr, low, mid); 
            string str2 = commonPrefix(arr, mid+1, high); 
    
            return (commonPrefixUtil(str1, str2)); 
        }
        return ""; 
    } 

    string longestCommonPrefix(vector<string>& strs) {
        int lenVec = strs.size();
        string ans = commonPrefix(strs, 0, lenVec - 1);
        if(ans.length()){
            return ans;
        }
        return "";
    }
};

int main(){
    vector<string> vec = {"flower","flow","flight"};
    vector<string> vec2 = {"dog","racecar","car"};
    Solution s1;
	cout << s1.longestCommonPrefix(vec2) << '\n';
	return 0;
}