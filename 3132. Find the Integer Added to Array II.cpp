#include <iostream>
#include <vector>
using namespace std;



class Solution {


public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int res = INT_MAX ;
        sort(nums1.begin(), nums1.end()) ;
        sort(nums2.begin(), nums2.end()) ;
        
    }

};

int main() {
    Solution s ;
    vector <int> nums1 = {4,20,16,12,8} ;
    vector <int> nums2 = {14,18,10} ;
    cout << s.minimumAddedInteger(nums1, nums2) << endl ;
    return 0 ;
}