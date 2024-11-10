#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    s.rotate(matrix);
    for(int i = 0; i < matrix.size(); i++) {
        for (int j =0 ; j<matrix.size() ; j++){
            cout << matrix[i][j] << endl ;
        }
    }
    return 0;
}
