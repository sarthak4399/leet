#include<iostream>
#include<vector> 
#include<set>

using namespace std  ;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0; 
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[k]) { 
                nums[++k] = nums[i]; 
            }
        }
        return nums.empty() ? 0 : k + 1; }
};

int main () {
     Solution s ; 
     vector<int> input = {0,0,1,1,1,2,2,3,3,4} ;
     cout << s.removeDuplicates(input)<< endl ;
}