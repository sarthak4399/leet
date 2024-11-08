#include<iostream>
#include <vector>
using namespace std ;





class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector <int> ans(nums.size()) ;
        int xorSum = 0 ;
        for ( int num : nums ){
            xorSum ^=num ;
        }
        int mask = ( 1<< maximumBit )-1 ;
        for(int i =0 ; i<nums.size() ; i++){
            ans[i] = xorSum ^mask ;
            xorSum ^= nums[nums.size()-1-i] ;
        }
        return ans ;
    }
};


int main () {
    Solution s ;
    vector <int> nums ={0,1,1,3} ;
    int maxbit = 2 ;
    vector <int> res = s.getMaximumXor(nums,maxbit) ;
    for(int val : nums) {
        cout << val  ;
    }
}