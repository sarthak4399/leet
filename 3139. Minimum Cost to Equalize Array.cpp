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
        
        vector<long long> prefixSum(n), suffixSum(n);
        prefixSum[0] = nums[0];
        suffixSum[n - 1] = nums[n - 1];
        
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
            suffixSum[n - i - 1] = suffixSum[n - i] + nums[n - i - 1];
        }
        
        long long minCost = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            long long cost = 0;
            cost += (i * 1LL * nums[i]) - prefixSum[i];
            cost += suffixSum[i] - (n - i - 1) * 1LL * nums[i];
            cost += min(i, n - i - 1) * 1LL * cost2;

            minCost = min(minCost, cost);
        }
        
        return minCost % 1000000007;
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
