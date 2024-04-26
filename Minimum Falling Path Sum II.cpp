#include <vector>
#include <limits>
#include <iostream>

using namespace std;

int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    
    // Loop through the grid from the second last row to the first
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            int best = numeric_limits<int>::max();
            // Find the minimum value in the next row that is not in the same column
            for (int k = 0; k < n; k++) {
                if (k != j) {
                    best = min(best, grid[i + 1][k]);
                }
            }
            // Update the current element with the sum of itself and the minimum value from the next row
            grid[i][j] += best;
        }
    }
    
    // Find the minimum value in the first row which will be the minimum falling path sum
    int ans = numeric_limits<int>::max();
    for (int j = 0; j < n; j++) {
        ans = min(ans, grid[0][j]);
    }
    
    return ans;
}

int main() {
    vector<vector<int>> grid1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> grid2 = {{7}};
    
    // Output: 13
    cout << minFallingPathSum(grid1) << endl;
    // Output: 7
    cout << minFallingPathSum(grid2) << endl;
    
    return 0;
}
