#include <iostream>
#include <string>

using namespace std ;
class Solution {
    string evaluate_operation_n_solve (string s){
        int i = 0 ;
        while (i < s.size()){
            if (s[i] == '*'){
                int j = i - 1 ;
                while (j >= 0 && s[j] != '+' && s[j] != '-'){
                    j-- ;
                }
                int k = i + 1 ;
                while (k < s.size() && s[k] != '+' && s[k] != '-'){
                    k++ ;
                }
                int a = stoi(s.substr(j+1, i-j-1)) ;
                int b = stoi(s.substr(i+1, k-i-1)) ;
                int c = a * b ;
                s = s.substr(0, j+1) + to_string(c) + s.substr(k) ;
                i = j + 1 ;
            }
            else {
                i++ ;
            }
        }
        i = 0 ;
        while (i < s.size()){
            if (s[i] == '+'){
                int j = i - 1 ;
                while (j >= 0 && s[j] != '+' && s[j] != '-'){
                    j-- ;
                }
                int k = i + 1 ;
                while (k < s.size() && s[k] != '+' && s[k] != '-'){
                    k++ ;
                }
                int a = stoi(s.substr(j+1, i-j-1)) ;
                int b = stoi(s.substr(i+1, k-i-1)) ;
                int c = a + b ;
                s = s.substr(0, j+1) + to_string(c) + s.substr(k) ;
                i = j + 1 ;
            }
            else {
                i++ ;
            }
        }
        return s ;


    };
public:
    int calculate(string s) {
        return stoi(evaluate_operation_n_solve(s)) ;
    }


} ;


int main(){
    Solution s ;
    string str = "3+2*2";
    cout << s.calculate(str) << endl ;
    str = "3/2" ;
    cout << s.calculate(str) << endl ;
    str = "3+5/2" ;
    cout << s.calculate(str) << endl ;
    return 0 ;
};
