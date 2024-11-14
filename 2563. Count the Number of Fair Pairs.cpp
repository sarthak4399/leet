#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());  // Sorting is crucial - must be uncommented
        return countLessEqual(nums, upper) - countLessEqual(nums, lower - 1);
    }
    
private:
    long long countLessEqual(vector<int>& nums, int target) {
        long long count = 0;
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            long long sum = nums[left] + nums[right];
            if (sum <= target) {
                count += right - left;
                left++;
            } else {
                right--;
            }
        }
        return count;
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