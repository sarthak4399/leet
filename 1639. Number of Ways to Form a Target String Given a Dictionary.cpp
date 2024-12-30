#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std ;
class Solution {
public:
    int numWays(vector<string>& words, string target) {
		const long long MOD = 1000000007;
        int m = words.size();
        int n = words[0].size();
        int t = target.size();
		vector<long long> dp(t + 1, 0);
        dp[0] = 1;
		vector<vector<long long>> freq(n, vector<long long>(26, 0));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                freq[j][words[i][j] - 'a']++;
                // cout << freq[j][words[i][j] - 'a'] << endl;
            }
        }
		for (int i = 0; i < n; i++) {
            for (int j = t - 1; j >= 0; j--) {
                dp[j + 1] = (dp[j + 1] + dp[j] * freq[i][target[j] - 'a']) % MOD;
            }
        }
		return dp[t];
		
    }
};

int main(){
	Solution s ;
	vector <string> words = {"acca","bbbb","caca"};
	string target = "aba";
	cout << s.numWays(words,target) ;

}