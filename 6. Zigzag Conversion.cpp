#include <iostream>
#include <vector>
using namespace std ;


class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {
            return s ;
        }
        vector<string> rows(min(numRows, int(s.size()))) ;
        int curRow = 0 ;
        bool goingDown = false ;
        for(char c : s) {
            rows[curRow] += c ;
            if(curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown ;
            }
            curRow += goingDown ? 1 : -1 ;
        }
        string res ;
        for(string row : rows) {
            res += row ;
        }
        return res ;
        
    }
};

int main() {
    Solution solution ;
    string s = "PAYPALISHIRING" ;
    int numRows = 3 ;
    string res = solution.convert(s, numRows) ;
    cout << res << endl ;
    return 0 ;
}
