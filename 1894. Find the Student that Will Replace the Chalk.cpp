
#include <iostream>
#include <vector>
using namespace std ;
 


class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0 ;
        for (int i = 0 ; i < chalk.size();i++){
            sum += chalk[i] ;
        }
        k = k % sum ;
        for (int i = 0 ; i < chalk.size();i++){
            if (k < chalk[i]){
                return i ;
            }
            k -= chalk[i] ;
        }
        return 0 ;
    };
};

int main (){
    Solution s ;
    vector<int> chalk = {5,1,5} ;
    int k = 22 ;
    cout << s.chalkReplacer(chalk,k) << endl ;
    return 0 ;
}