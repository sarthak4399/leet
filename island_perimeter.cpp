#include <vector>
#include <iostream>
using namespace std;

class Solution {

public:
    int islandPerimeter(vector<vector<int> >& grid) {
        int perimeter  =0 ;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1) {
                    perimeter += countPerimeter(grid, i, j);
                }
            }
        }
        return perimeter;
    }

private:
    int countPerimeter(vector<vector <int> > & grid, int i, int j) {
        int perimeter = 0;
        if (i == 0 || grid[i-1][j] == 0) perimeter++;
        if (i == grid.size()-1 || grid[i+1][j] == 0) perimeter++;
        if (j == 0 || grid[i][j-1] == 0) perimeter++;
        if (j == grid[0].size()-1 || grid[i][j+1] == 0) perimeter++;
        return perimeter;
    }
};


int main() {
    Solution s;
    vector<vector<int>>grid = {{0,1,0,0},
                                {1,1,1,0},
                                {0,1,0,0},
                                {1,1,0,0}};
    int perimeter = s.islandPerimeter(grid);
    std::cout << perimeter << std::endl;

    return 0;
}