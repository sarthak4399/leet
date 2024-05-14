#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if(grid[i][j] != 0){
                    res = max(res, dfs(grid, i, j, 0));
                }
            }
        }
        return res;
    }
    public:
    int dfs(vector<vector<int>>& grid, int i, int j,int sum ){
        int n = grid.size(), m = grid[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0){
            return sum;
        }
        int temp = grid[i][j];
        grid[i][j] = 0;
        int res = 0;
        res = max({res, dfs(grid, i+1, j, sum + temp), dfs(grid, i-1, j, sum + temp), dfs(grid, i, j+1, sum + temp), dfs(grid, i, j-1, sum + temp)});
        grid[i][j] = temp;
        
        return res;
    }
};

int main(){
    Solution s ;
    vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}};
    cout << s.getMaximumGold(grid) << endl ;
    return 0 ;
}
