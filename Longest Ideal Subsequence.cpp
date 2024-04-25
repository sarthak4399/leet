#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(26, 0));
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (i == 0 || abs(s[i] - 'a' - j) <= k) {
                    dp[i][s[i] - 'a'] = max(dp[i][s[i] - 'a'], (i > 0 ? dp[i - 1][j] : 0) + 1);
                    ans = max(ans, dp[i][s[i] - 'a']);
                }
                dp[i][j] = max(dp[i][j], (i > 0 ? dp[i - 1][j] : 0));
            }
        }
        
        return ans;
    }
};
int main (){
    Solution s;
    cout << s.longestIdealString("adsgfasaaa", 1) << endl;

}