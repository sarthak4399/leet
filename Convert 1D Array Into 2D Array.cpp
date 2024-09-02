
#include <vector>
#include <iostream>

using namespace std ;


class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n) return {};
        vector<vector<int>> res(m, vector<int>(n));

        for(int i = 0 ;i<m ;i++){
            for(int j = 0 ;j<n ;j++){
                res[i][j] = original[i*n + j];
            }
        }
        return res;
        
    }
};