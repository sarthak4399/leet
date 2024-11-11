#include<iostream>
#include<vector>
using namespace std ;



class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }
        int res = n+1;
        vector<int> ans ;
        for(int i = 0; i <= n; i++) {
            while(ans.size() && prefix[i] - prefix[ans.front()] >= k) {
                res = min(res, i - ans.front());
                ans.erase(ans.begin());
            }
            while(ans.size() && prefix[i] <= prefix[ans.back()]) {
                ans.pop_back();
            }
            ans.push_back(i);
        }
        return res == n+1 ? -1 : res;
    }
};


int main(){
    Solution s ;
    vector<int> nums ={1,2,3} ;
    cout << s.minimumSubarrayLength(nums,2) <<endl ;
}