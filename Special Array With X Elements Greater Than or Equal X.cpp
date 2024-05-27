#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {

        for (int x = 1; x <= nums.size(); x++) {
            int count = 0;
            for (int num : nums) {
                if (num >= x) {
                    count++;
                }
            }
            if (count == x) {
                return x;
            }
        }
        return -1;
    }
};
int main(){
    Solution s ;
    vector<int> nums = {3,5};
    cout << s.specialArray(nums) << endl;
}