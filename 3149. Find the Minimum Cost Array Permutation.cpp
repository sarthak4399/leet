#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(1 << n, vector<long long>(n, LLONG_MAX));
        vector<vector<int>> path(1 << n, vector<int>(n, -1));
        dp[1 << 0][0] = 0;
        for(int mask = 1 << 0; mask < (1 << n); mask++) {
            if(!(mask & 1)) continue; 
            int pos = __builtin_popcount(mask);
            for(int last = 0; last < n; last++) {
                if(!(mask & (1 << last))) continue;
                
                for(int next = 1; next < n; next++) {
                    if(mask & (1 << next)) continue;
                    
                    long long newCost = dp[mask][last] + (long long)nums[next] * (pos-1);
                    int newMask = mask | (1 << next);
                    
                    if(newCost < dp[newMask][next]) {
                        dp[newMask][next] = newCost;
                        path[newMask][next] = last;
                    }
                }
            }
        }
        
        int finalMask = (1 << n) - 1;
        int lastPos = 0;
        long long minCost = LLONG_MAX;
        
        for(int i = 0; i < n; i++) {
            if(dp[finalMask][i] < minCost) {
                minCost = dp[finalMask][i];
                lastPos = i;
            }
        }
        vector<int> result(n);
        result[0] = 0; 
        int curMask = finalMask;
        int pos = lastPos;
        
        for(int i = n-1; i > 0; i--) { 
            result[i] = pos;
            pos = path[curMask][pos];
            curMask ^= (1 << result[i]);
        }
        
        return result;
    }
};

int main () { 
    Solution s ;
    vector <int> nums = {1,0,2};
    vector <int> res = s.findPermutation(nums) ;
    for(int val  : res){
        cout << val ;
    }
    cout << endl;

}