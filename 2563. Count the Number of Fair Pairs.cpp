#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countPairs(nums, upper) - countPairs(nums, lower - 1);
    }
    
private:
    long long countPairs(vector<int>& nums, long long target) {
        long long res = 0;
        int n = nums.size();
        int left = 0, right = n - 1;
        
        while (left < right) {
            long long sum = (long long)nums[left] + nums[right];
            if (sum <= target) {
                res += right - left;
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};

int main(){
    Solution s ;
    vector<int> nums = {0,1,7,4,45} ;
    int lower = 3 ;
    int upper = 6 ;
    cout << s.countFairPairs(nums, lower, upper) << endl ;
    return 0 ;
}