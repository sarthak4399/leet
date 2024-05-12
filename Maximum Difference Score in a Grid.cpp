#include <vector>
#include <algorithm>
#include <limits>
using namespace std; 
/**
 * @brief The Solution class
 * @details The solution class contains the function maxScore which takes a 2D vector grid as input and returns the maximum difference score in the grid.
 * @details The function is defined as follows:
 * 1. Create a 2D vector dp of size m x n and initialize all elements to INT_MIN.
 * 2. Set dp[m - 1][n - 1] to grid[m - 1][n - 1].
 * 3. For i from m - 1 to 0, do the following:
 * 4. For j from n - 1 to 0, do the following:
 * 5. If i is less than m - 1, set dp[i][j] to the maximum of dp[i][j] and dp[i + 1][j].
 * 6. If j is less than n - 1, set dp[i][j] to the maximum of dp[i][j] and dp[i][j + 1].
 * 7. Set dp[i][j] to the maximum of dp[i][j] and grid[i][j].
 * 8. Create a variable Max and set it to INT_MIN.
 * 9. For i from 0 to m, do the following:
 * 10. For j from 0 to n, do the following:
 * 11. If i is less than m - 1, set Max to the maximum of Max and dp[i + 1][j] - grid[i][j].
 * 12. If j is less than n - 1, set Max to the maximum of Max and dp[i][j + 1] - grid[i][j].
 * 13. Return Max.
 * @note The time complexity is O(m * n) and the space complexity is O(m * n).
*/
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, INT_MIN));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i < m - 1)
                    dp[i][j] = max(dp[i][j], dp[i + 1][j]);
                if (j < n - 1)
                    dp[i][j] = max(dp[i][j], dp[i][j + 1]);
                dp[i][j] = max(dp[i][j], grid[i][j]);
            }
        }
        
        int Max = INT_MIN;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i < m - 1)
                    Max = max(Max, dp[i + 1][j] - grid[i][j]);
                if (j < n - 1)
                    Max = max(Max, dp[i][j + 1] - grid[i][j]);
            }
        }
        
        return Max;
    }
};

int main(){
    Solution s ;
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
    int result = s.maxScore(grid);
    return 0;
}
