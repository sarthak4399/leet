#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;
        int rows = grid.size();
        if (rows == 0) return 0; 
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ++islandCount;
                    countLand(grid, visited, i, j);
                }
            }
        }
        return islandCount;
    }
private:
    void countLand(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0' || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        countLand(grid, visited, i + 1, j);
        countLand(grid, visited, i - 1, j); 
        countLand(grid, visited, i, j + 1); 
        countLand(grid, visited, i, j - 1);
    }
};

int main() {
    Solution s;
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                  {'1', '1', '0', '1', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '0', '0', '0'}};
    int islandCount = s.numIslands(grid);
    cout << "Number of islands: " << islandCount << endl;
    return 0;
}
