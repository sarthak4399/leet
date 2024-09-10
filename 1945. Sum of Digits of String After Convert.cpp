#include<iostream>
using namespace std ;


class Solution {
public:
    int getLucky(string s, int k) {
        
        string str = "" ;
        for(char c : s) {
            str += to_string(c - 'a' + 1) ;
        }
        int sum = 0 ;
        for(char c : str) {
            sum += c - '0' ;
        }
        for(int i = 1 ; i < k ; i++) {
            int temp = 0 ;
            while(sum) {
                temp += sum % 10 ;
                sum /= 10 ;
            }
            sum = temp ;
        }
        return sum ;
    }
};

int main() {
    Solution solution ;
    string s = "iiii" ;
    int k = 1 ;
    int res = solution.getLucky(s, k) ;
    cout << res << endl ;
    return 0 ;
}