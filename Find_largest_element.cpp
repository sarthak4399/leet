#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
    /**
     * @brief A function to find the kth largest element in an array.
     * @param nums A vector of integers.
     * @param  An integer representing the  largest element.
     * @return An integer representing the  largest element.
     *  */
        int findKthLargest(vector<int>& nums, int k) {
                for (int i =0 ; i < nums.size()-1 ;i++){
                    cout << nums[i] << " ";
                }
                int largest = nums[0];
                int index = 0;
                for (int i = 1; i < nums.size(); i++) {
                    if (nums[i] > largest) {
                        largest = nums[i];
                        index = i;
                    }
                }
                cout << "Largest: " << largest << " Index: " << index << endl;
                /**
                    @brief Sort the array in ascending order.
                    @return  The kth largest element.
                */
                sort(nums.begin(), nums.end(), less<int>());
                cout << "Sorted Array: ";
                for (int i = 0; i < nums.size(); i++) {
                    cout << nums[i] << " ";

                }
                int kth_largest = nums[nums.size() - k];
                return kth_largest;
        }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int result = s.findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << result << endl;
    return 0;
}