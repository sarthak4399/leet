#include <vector>
#include <iostream>
using namespace std;

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
