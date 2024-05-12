#include <vector>
#include <iostream>
using namespace std ;
/**
 * @brief The Solution class
 * @details The solution class contains the function maximumEnergy which takes a vector energy and an integer k as input and returns the maximum energy that can be obtained by taking k steps.
 * @details The function is defined as follows:
 * 1. Create a variable n and set it to the size of energy.
 *  2. Create a variable maxi and set it to INT_MIN.
 * 3. For i from n - 1 to n - k, do the following:
 * 4. Create a variable ans and set it to 0.
 * 5. For j from i to 0 with a step of k, do the following:
 * 6. Increment ans by energy[j].
 * 7. Update maxi to the maximum of maxi and ans.
 * 8. Return maxi.
 * @note The time complexity is O(n) and the space complexity is O(1).
*/

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int maxi = INT_MIN;
        for (int i = n - 1; i >= n - k; i--) {
            int ans = 0;
            for (int j = i; j >= 0; j -= k) {
                ans += energy[j];
                maxi = max(maxi, ans);
            }
        }

        return maxi;
    }
};

int main(){
    Solution s ;
    vector<int> energy = {5,2,-10,-5,1};
    int k = 3;
    int result = s.maximumEnergy(energy, k);
    cout << result << " ";
    return 0;
}