#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(target - sum) < abs(target - closest)) {
                    closest = sum;
                }
                if (sum > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return closest;
    }
};


int main() {
    Solution s;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    cout << s.threeSumClosest(nums, target) << endl;
    return 0;


}