#include<iostream>
using namespace std;    


class Solution {
public:
    int checkRecord(int n) {
        int mod = 1000000007;
        long long dp[2][3] = {0};
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            long long dpNew[2][3] = {0};
            // P
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= 2; k++) {
                    dpNew[j][0] = (dpNew[j][0] + dp[j][k]) % mod;
                }
            }
            // A
            for (int k = 0; k <= 2; k++) {
                dpNew[1][0] = (dpNew[1][0] + dp[0][k]) % mod;
            }
            // L
            for (int j = 0; j <= 1; j++) {
                for (int k = 1; k <= 2; k++) {
                    dpNew[j][k] = (dpNew[j][k] + dp[j][k - 1]) % mod;
                }
            }
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= 2; k++) {
                    dp[j][k] = dpNew[j][k];
                }
            }
        }
        long long sum = 0;
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 2; k++) {
                sum = (sum + dp[j][k]) % mod;
            }
        }
        return (int)sum;
    }
};
int main(){
    Solution s ;
    cout << s.checkRecord(2) << endl;
    cout << s.checkRecord(1) << endl;
    cout << s.checkRecord(10101) << endl;
    cout << s.checkRecord(1000000007) << endl;
}