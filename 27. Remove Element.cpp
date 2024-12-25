#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std ;
 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};


int main(){
	Solution s ;
	vector<int> nums = {3,2,2,3} ;
	int val = 3 ;
	cout<< s.removeElement(nums, val) << endl ;
}