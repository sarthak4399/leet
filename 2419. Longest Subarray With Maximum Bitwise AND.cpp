#include <iostream>
#include <vector>

using namespace std ;


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val =  *max_element(nums.begin(), nums.end()) ;
        int curr_length = 0 , max_length = 0 ;
        for (int num :nums){
            if (num == max_val){
                curr_length++ ;
                max_length = max(max_length, curr_length) ;
            } else {
                curr_length = 0 ;
            }

        }
        return max_length ;
    }
};

int main() {
    Solution s ;
    vector <int> nums = {1,2,3,3,2,2} ;
    cout << s.longestSubarray(nums) << endl ;
    return 0 ;
}