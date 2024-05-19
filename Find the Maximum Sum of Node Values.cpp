#include <iostream>
#include <vector> 
#include <queue>

using  namespace std ;


#pragma GCC optimize ("O2")
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        priority_queue<int> pq;
        long long ans = 0;
        for(int i : nums) {
            ans += i;
            pq.push((i ^ k) - i);
        }
        while(pq.size() >= 2) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a + b > 0)
                ans += a + b;
        }
        return ans;
    }
};




int main () {

    Solution s ;

    vector<int> nums = {1,2,1};
    vector<vector<int >> edges = {{0,1},{0,2}};
    int k =  3 ;
    s.maximumValueSum(nums ,k , edges);


}