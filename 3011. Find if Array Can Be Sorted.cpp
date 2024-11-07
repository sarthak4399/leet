
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canBeSorted(vector<int>& nums) {
    int n = nums.size();
    vector<int> bitCounts(n);

    // Calculate the number of set bits for each number
    for (int i = 0; i < n; ++i) {
        int num = nums[i];
        int count = 0;
        while (num > 0) {
            count += num & 1;
            num >>= 1;
        }
        bitCounts[i] = count;
    }

    // Sort the array based on the number of set bits
    vector<pair<int, int>> sortedNums(n);
    for (int i = 0; i < n; ++i) {
        sortedNums[i] = {bitCounts[i], nums[i]};
    }
    sort(sortedNums.begin(), sortedNums.end());

    // Check if the sorted array is in non-decreasing order based on original values
    for (int i = 1; i < n; ++i) {
        if (sortedNums[i - 1].second > sortedNums[i].second) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> nums = {8, 4, 2, 30, 15};
    bool canSort = canBeSorted(nums);
    cout << "Can be sorted: " << canSort << endl;
    return 0;
}