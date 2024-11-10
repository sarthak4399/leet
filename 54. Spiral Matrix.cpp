#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
    
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
    
        int x = 0, y = 0;        
        int dir = 0;             
        int total = m * n;       

        
        while (res.size() < total) {
            res.push_back(matrix[x][y]);
            visited[x][y] = true;

            int nextX = x + dx[dir];
            cout << " nextX "<< nextX <<endl ;
            int nextY = y + dy[dir];
            cout << " nextY"  << nextY << endl;

            if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || visited[nextX][nextY]) {
                dir = (dir + 1) % 4;
                cout << dir << endl ;
                nextX = x + dx[dir];
                nextY = y + dy[dir];
            }
            
            x = nextX;
            y = nextY;
        }
        
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> res = s.spiralOrder(matrix);
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}