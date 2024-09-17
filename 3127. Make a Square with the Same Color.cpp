#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int n = 3; 
        auto isUniformSquare = [&](int i, int j) {
            char color = grid[i][j];
            return grid[i][j + 1] == color && grid[i + 1][j] == color && grid[i + 1][j + 1] == color;
        };
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (isUniformSquare(i, j)) {
                    return true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char original = grid[i][j];
                grid[i][j] = (original == 'B') ? 'W' : 'B';
                for (int x = 0; x < n - 1; x++) {
                    for (int y = 0; y < n - 1; y++) {
                        if (isUniformSquare(x, y)) {
                            return true;
                        }
                    }
                }
                grid[i][j] = original;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<vector<char>> grid1 = {{'B', 'W', 'B'}, {'B', 'W', 'W'}, {'B', 'W', 'B'}};
    vector<vector<char>> grid2 = {{'B', 'W', 'B'}, {'W', 'B', 'W'}, {'B', 'W', 'B'}};
    vector<vector<char>> grid3 = {{'B', 'W', 'B'}, {'B', 'W', 'W'}, {'B', 'W', 'W'}};

    cout << boolalpha << s.canMakeSquare(grid1) << endl; // Output: true
    cout << boolalpha << s.canMakeSquare(grid2) << endl; // Output: false
    cout << boolalpha << s.canMakeSquare(grid3) << endl; // Output: true

    return 0;
}