#include<iostream>
#include<vector>
using namespace std ;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size() ;
        for (int i = 0 ; i < n/2 ; i++){
            char temp = s[i] ;
            s[i] = s[n-i-1] ;
            s[n-i-1] = temp ;
        }
    }
};
int main(){
    Solution s ;
    vector<char> str = {'h','e','l','l','o'} ;
    s.reverseString(str) ;
    for (int i = 0 ; i < str.size() ; i++){
        cout << str[i] << " " ;
    }
    cout << endl ;
    return 0 ;
}