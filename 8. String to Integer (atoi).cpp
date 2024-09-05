#include <iostream>
#include <string>
using namespace std ;



class Solution {
public:
    int myAtoi(string s) {
        int i = 0 ;
        int n = s.size() ;
        while(i < n && s[i] == ' ') {
            i++ ;
        }
        if(i == n) {
            return 0 ;
        }
        int sign = 1 ;
        if(s[i] == '+') {
            i++ ;
        } else if(s[i] == '-') {
            sign = -1 ;
            i++ ;
        }
        int res = 0 ;
        while(i < n && isdigit(s[i])) {
            int digit = s[i] - '0' ;
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN ;
            }
            res = res * 10 + digit ;
            i++ ;
        }
        return sign * res ; 
    }
};
int main() {
    Solution solution ;
    string s = "42" ;
    int res = solution.myAtoi(s) ;
    cout << res << endl ;
    return 0 ;
}