#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high + 1, 0LL);
        const long long MOD = 1000000007;
        dp[0] = 1;  
        long long result = 0;
        for (int length = 1; length <= high; length++) {
            if (length - zero >= 0) {
                dp[length] = (dp[length] + dp[length - zero]) % MOD;
            }
            if (length - one >= 0) {
                dp[length] = (dp[length] + dp[length - one]) % MOD;
            }
            if (length >= low) {
                result = (result + dp[length]) % MOD;
            }
        }
        return (int)result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution s;
    int low = 3, high = 3, zero = 1, one = 1;
    cout << s.countGoodStrings(low, high, zero, one) << "\n";
    return 0;
}