#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int addedInteger(std::vector<int>& nums1, std::vector<int>& nums2) {
    int minNum1 = *min_element(nums1.begin(), nums1.end());
    int minNum2 = *min_element(nums2.begin(), nums2.end());

    return minNum2 - minNum1;
}

int main() {
    std::vector<int> nums1 = {2, 6, 4};
    std::vector<int> nums2 = {9, 7, 5};
    std::cout << addedInteger(nums1, nums2) << std::endl;

    nums1 = {10};
    nums2 = {5};
    std::cout << addedInteger(nums1, nums2) << std::endl;

    nums1 = {1, 1, 1, 1};
    nums2 = {1, 1, 1, 1};
    std::cout << addedInteger(nums1, nums2) << std::endl;

    return 0;
}
