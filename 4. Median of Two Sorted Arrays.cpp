#include <vector>
#include <iostream>

using namespace std ;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int x = nums1.size();
        int y = nums2.size();
        int low = 0, high = x;

        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;

            int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];

            int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];
            int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            if (maxX <= minY && maxY <= minX) {
                if ((x + y) % 2 == 0) {
                    return (double)(max(maxX, maxY) + min(minX, minY)) / 2;
                } else {
                    return (double)max(maxX, maxY);
                }
            } else if (maxX > minY) {
                high = partitionX - 1;
            } else {
                low = partitionX + 1;
            }
        }
    }
};


int main(){
    Solution s;
    vector<int> nums1 = {1, 3, 5};
    vector<int> nums2 = {2, 4};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;

}