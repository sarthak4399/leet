// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <limits>
// #include <numeric>

// using namespace std;

// // class Solution {
// // public:
// //     int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
// //         int max_val = *max_element(nums.begin(), nums.end());
// //         int total_cost =0 ;
// //         for (auto val : nums ){
// //             total_cost += max_val - val ;
// //             cout << val <<endl ;
// //         }
// //         if(cost2 >= 2*cost1){
// //             return total_cost*cost1;
// //         }
// //         int pairs  = total_cost /2 ;
// //         int leftovers = (total_cost) % 2;
// //         return (pairs*cost2 + leftovers*cost1) ;
// //     }
// // };

// class Solution {
//  public:
//   int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
//         int max_val = *max_element(nums.begin(), nums.end());
//         int min_val = *min_element(nums.begin(), nums.end());
//         int total_cost =0 ;
//         for (auto val : nums ){
//             total_cost += max_val - val ;
//             cout << val <<endl ;
//         }
//         int MOD = 1e9+7;
//         if(cost2 >= 2*cost1){
//             return total_cost*cost1;
//         }
//         int leftovers = total_cost -(max_val - min_val);
//         int pairs  = total_cost /2 ;
//         if (pairs <(max_val - min_val))return ((max_val - min_val)-leftovers)*cost1+leftovers ;

//         if (total_cost%2) return (total_cost/2)*cost2;
//         else return (total_cost/2)*cost2+cost1;
//         return (pairs*cost2 + leftovers*cost1) ;
//     }
// };

// int main() {
//     Solution s;
//     vector<int> nums = {2,3,3,3,5};
//     int cost1 = 2;
//     int cost2 = 1;
//     cout << s.minCostToEqualizeArray(nums, cost1, cost2) << endl;
//     return 0;
// }

#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;
class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        
        auto calcCost = [&](int i, int j) {
            if (i > j) return 0;
            if (dp[i][j] != -1) return dp[i][j];
            
            int mid = (i + j) / 2;
            long long cost = 0;
            for (int k = i; k <= j; ++k) {
                cost += abs(nums[k] - nums[mid]);
            }
            
            dp[i][j] = min(calcCost(i, mid - 1) + calcCost(mid + 1, j) + (j - i + 1) * cost2,
                          calcCost(i, mid) + calcCost(mid + 1, j) + (j - i + 1) * cost1);
            
            return dp[i][j];
        };
        
        return calcCost(0, n - 1) % 1000000007;
    }
};

// class Solution {
// public:
//     int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
//         int n = nums.size();
//         if (n == 1) return 0;

//         long long mod = 1e9 + 7;
//         long long sum = accumulate(nums.begin(), nums.end(), 0LL);
//         int min_val = *min_element(nums.begin(), nums.end());
//         int max_val = *max_element(nums.begin(), nums.end());

//         if (2 * cost1 <= cost2) {
//             long long result = ((n * max_val - sum) * cost1) % mod;
//             return (int)result;
//         }

//         long long result = LLONG_MAX, add = 0;
//         if (n >= 3) {
//             add += (max_val - 1) / (n - 2);
//         }
//         for (long long target = max_val; target < max_val + add + 2; target++) {
//             long long temp_cost = 0;
//             long long total_increments = n * target - sum;
//             long long min_increments = target - min_val;
//             if (total_increments - min_increments > min_increments) {
//                 temp_cost = ((total_increments / 2) * cost2 + (total_increments % 2) * cost1) % mod;
//             } else {
//                 temp_cost += ((total_increments - min_increments) * cost2) % mod;
//                 min_increments -= (total_increments - min_increments);
//                 temp_cost = (temp_cost + min_increments * cost1) % mod;
//             }
//             result = min(result, temp_cost)%mod;
//         }

//         result ;
//         return (int)result;
//     }
// };


int main() {
    Solution s;
    vector<int> nums = {1,1000000,999999};
    int cost1 = 1000000;
    int cost2 = 1;
    cout << s.minCostToEqualizeArray(nums, cost1, cost2) << endl;
    return 0;
}
