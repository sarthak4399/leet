#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        nums1.erase(nums1.begin());
        nums1.erase(nums1.end()-1);
        // cout << "nums1: ";
        // cout << endl;
        // for (int i = 0; i < nums1.size(); i++) {
        //     cout << nums1[i] << " ";
        // }
        sort(nums2.begin(), nums2.end());
        // cout << "nums2: ";  
        // for (int i = 0; i < nums2.size(); i++) {
        //     // cout << nums2[i] << " ";
        // }
        int diff =  nums2[0] - nums1[0];
        // cout << "diff: " << diff -2 << endl;

        // for (int i = 0; i < nums2.size(); i++) {
        //     nums1[i] += diff;
        // }
        // // cout << "nums1: ";
        // // for (int i = 0; i < nums2.size(); i++) {
        // //     cout << nums1[i] << " ";
        // // }
        return  (diff - 2);
    }
};
int main (){
    Solution s;
    vector<int> nums1 = {4 ,20 , 10, 3, 8, 5, 6, 7, 9, 1, 2, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    vector<int> nums2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    s.minimumAddedInteger(nums1, nums2);
}