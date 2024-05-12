#include <vector>
#include <iostream>
using namespace std;
/**
 * @brief The Solution class
 * @details The solution class contains the function largestLocal which takes a 2D vector grid as input and returns a 2D vector containing the largest local values.
 * @details The function is defined as follows:
 * 1. Create a variable n and set it to the size of grid.
 * 2. Create a 2D vector largestLocal of size n - 2 x n - 2 and initialize all elements to 0.
 * 3. For i from 1 to n - 1, do the following:
 * 4. For j from 1 to n - 1, do the following:
 * 5. Create a variable maxVal and set it to grid[i][j].
 * 6. For x from i - 1 to i + 1, do the following:
 * 7. For y from j - 1 to j + 1, do the following:
 * 8. Set maxVal to the maximum of maxVal and grid[x][y].
 * 9. Set largestLocal[i - 1][j - 1] to maxVal.
 * 10. Return largestLocal.
 * @note The time complexity is O(n^2) and the space complexity is O(n^2).
*/
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> largestLocal(n - 2, vector<int>(n - 2, 0));
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                int maxVal = grid[i][j];
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        maxVal = max(maxVal, grid[x][y]);
                    }
                }
                largestLocal[i - 1][j - 1] = maxVal;
            }
        }
        return largestLocal;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};
    vector<vector<int>> result = s.largestLocal(grid);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
