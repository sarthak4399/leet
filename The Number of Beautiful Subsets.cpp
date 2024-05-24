#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;


class Solution {
public:
    int dfs(vector<int> &nums, int idx, int k, unordered_map<int, int> &mp) {
    if(idx == nums.size()) return 1;
    int visited = 0;
    if(!mp[nums[idx] - k] && !mp[nums[idx] + k]) {
        mp[nums[idx]]++;
        visited = dfs(nums, idx + 1, k, mp);
        mp[nums[idx]]--;
    }
    
    int notvisited = dfs(nums, idx + 1, k, mp);
    
    return visited + notvisited;
    }

    int beautifulSubsets(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        int ans = dfs(nums, 0, k, mp);
        return ans - 1;
    }
};
 
int main(){
    Solution s ;
    vector<int> nums = {2,4,6};
    int k = 2;
    cout << s.beautifulSubsets(nums, k) << endl;
}