#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxK = -1;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                if (nums[i] > maxK && find(nums.begin(), nums.end(), -nums[i]) != nums.end()) {
                    maxK = nums[i];
                }
            }
        }
        
        return maxK;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, -3, 6, -4, 5};
    cout << s.findMaxK(nums) << endl;
    return 0;
}
