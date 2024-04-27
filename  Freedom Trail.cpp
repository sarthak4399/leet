#include <iostream>
#include <vector>


using namespace std ;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
       int n = ring.size();
       int m = key.size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        for (int i = 0 ; i < n ; i++){
             if (ring[i] == key[0]){
                 dp[0][i] = min(i,n-i) + 1;
             }
         }
         for (int i = 1 ; i < m ; i++){
             for (int j = 0 ; j < n ; j++){
                 if (ring[j] == key[i]){
                     for (int k = 0 ; k < n ; k++){
                         if (dp[i-1][k] != INT_MAX){
                             dp[i][j] = min(dp[i][j],dp[i-1][k] + min(abs(j-k),n-abs(j-k)) + 1);
                         }
                     }
                 }
             }
         }         
            int ans = INT_MAX;
            for (int i = 0 ; i < n ; i++){
                ans = min(ans,dp[m-1][i]);
            }
            return ans;
    }
};

int main(){
    Solution s ;
    string ring = "godding";
    string key = " ";
    cout << s.findRotateSteps(ring,key) << endl;
    return 0 ;
}