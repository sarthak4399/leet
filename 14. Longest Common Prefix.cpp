#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if(strs.size() == 0) return prefix;
        for (int i = 0 ; i< strs[0].size(); i++){
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++){
                if(i >= strs[j].size() || strs[j][i] != c){
                    return prefix;
                }
            }
            prefix += c;
        }
        return prefix;
    }
};

int main(){
    Solution s;
    vector<string> strs = {"dog","racecar","car"};
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}