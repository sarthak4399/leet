#include<iostream>
#include<vector>
#include<unordered_map> 

using namespace std ;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        for(int i = 0 ; i < nums.size(); i++) {
            nums[i] += nums[i-1] ;
        }
        unordered_map<int, int> mp ;
        mp[0] = 1 ;
        int res = 0 ;
        for (int i = 0; i < nums.size(); i++) {
            res += mp[nums[i] - k] ;
            mp[nums[i]]++ ;
        }

        return res ;
    }
};


int main() {
    Solution s ;
    vector<int> nums = {1,2,3} ;
    int k = 3 ;
    cout << s.subarraySum(nums, k) << endl ;
    return 0 ;
}