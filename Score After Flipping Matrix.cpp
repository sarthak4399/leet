#include<iostream>
#include<vector>
using namespace std ;
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = grid.size(), m = grid[0].size();
        int res = (1 << (m - 1)) * n;

        for(int j = 1; j < m; ++j) {
            int val = 1 << (m - 1 - j);
            int set = 0;

            for(int i = 0; i < n; ++i) {
                if(grid[i][j] == grid[i][0]) {
                    set++;
                }
            }

            res += max(set, n - set) * val;
        }

        return res;
    }
};
int main (){
    Solution s ;
    vector<vector<int>> grid = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    cout << s.matrixScore(grid) << endl ;
    return 0 ;
}