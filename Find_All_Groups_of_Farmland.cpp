#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        for (int i = 0; i < land.size(); ++i) {
            for (int j = 0; j < land[0].size(); ++j) {
                if (land[i][j] == 1) {
                    int bottomRightRow = i, bottomRightCol = j;
                    dfs(land, i, j, bottomRightRow, bottomRightCol);
                    res.push_back({i, j, bottomRightRow, bottomRightCol});
                }


            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& land, int i, int j, int& bottomRightRow, int& bottomRightCol) {
        int rows = land.size();
        int cols = land[0].size();
        if (i < 0 || i >= rows || j < 0 || j >= cols || land[i][j] == 0) {
            return;
        }
        land[i][j] = 0; // Mark as visited
        bottomRightRow = max(bottomRightRow, i);
        bottomRightCol = max(bottomRightCol, j);
        dfs(land, i + 1, j, bottomRightRow, bottomRightCol);
        dfs(land, i - 1, j, bottomRightRow, bottomRightCol);
        dfs(land, i, j + 1, bottomRightRow, bottomRightCol);
        dfs(land, i, j - 1, bottomRightRow, bottomRightCol);
    }
};

int main() {
    vector<vector<int>> land = {{1, 0, 0}, {0, 1, 1}, {0, 1, 1}};
    Solution s;
    vector<vector<int>> result = s.findFarmland(land);

    // for (const auto& row : result) {
    //     for (int num : row) {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }
    // return 0;
}
