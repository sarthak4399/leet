#include<iostream>
#include<vector>

using namespace std ;

/**
 * @brief  Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return all possible palindrome partitioning of s.
 * A palindrome string is a string that reads the same backward as forward.
 * @param s
 * @return vector<vector<string>>
 
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result ;
        vector<string> curr;
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j <= i ; j++){
                if(s[i] == s[j] && (i - j <= 2 || dp[j+1][i-1])){
                    dp[j][i] = true;
                }
            }
        }
        dfs(s, 0, dp, curr, result);
        return result;
    }
    private:
    void dfs(string s, int start, vector<vector<bool>>& dp, vector<string>& curr, vector<vector<string>>& result){
        if(start == s.length()){
            result.push_back(curr);
            return;
        }
        for(int i = start ; i < s.length() ; i++){
            if(dp[start][i]){
                curr.push_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, dp, curr, result);
                curr.pop_back();
            }
        }
};
};

int main(){
    Solution s ;
    string str  = "aab ";
    s.partition(str);
}