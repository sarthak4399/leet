#include <iostream>
#include <bitset>

#include <string> 
using namespace std ;

// class Solution {
// public:
//     int numSteps(string s) {
//         int binary = atoi( s.c_str() ) ;
//         int decimal = cnv_bin(binary);
//         cout << decimal << endl ;
//         int step = 0 ;
//         while(decimal!=1){
//             if (decimal %2 !=0){
//                 decimal +=1;
//                 step ++ ;
//             }
//             else{
//                 // if even then / 2 ;
//                 decimal = decimal/2;
//                 step ++ ;
//             }
//         }
//         return step ;
//     }
// private: 
//     int cnv_bin(int binary) {
//     int decimal = 0;
//     int base = 1;
    
//     while (binary) {
//         int last_digit = binary % 10;
//         binary = binary / 10;
//         decimal += last_digit * base;
//         base = base * 2;
//     }

//     return decimal;
// }

// };
class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        while (s != "1") {
            if (s.back() == '0') {
                s.pop_back(); // remove the last character '0'
            } else {
                int i = s.length() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    --i;
                }
                if (i >= 0) {
                    s[i] = '1';
                } else {
                    s = '1' + s;
                }
            }
            ++steps;
        }
        return steps;
    }
};

int main () {
    Solution s ;
    string str = "1101";
    cout << s.numSteps(str) << endl;
    return 0;
}