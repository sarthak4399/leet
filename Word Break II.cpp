#include <iostream>
#include <vector>
#include <string>
using namespace std ;


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        cout << "s: " << s << endl;
        vector<string> ans;
        for (auto i : wordDict) {
            if (s.substr(0, i.size()) == i) {
                if (i.size() == s.size()) ans.push_back(i);
                else {
                    vector<string> temp = wordBreak(s.substr(i.size()), wordDict);
                    for (auto j : temp) ans.push_back(i + " " + j);
                }
            }
        }
        return ans;
        
    }
    
};

int main(){
    Solution s ;
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    string str = "catsanddog";
    vector<string> ans = s.wordBreak(str, wordDict);
    for (auto i : ans) cout << i << endl;
}