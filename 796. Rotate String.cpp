#include<iostream>
#include<string>
using namespace std ;


#include <iostream>
#include <string>
using namespace std;

// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if (s.length() != goal.length()) {
//             return false;
//         }
//         for (int i = 0; i < s.length(); i++) {
//             if (s[i] == goal[0]) {
//                 string rvstr = "";
//                 for (int j = i; j < s.length(); j++) {
//                     rvstr += s[j];
//                 }
//                 for (int j = 0; j < i; j++) {
//                     rvstr += s[j];
//                 }

//                 if (rvstr == goal) {
//                     return true;
//                 }
//             }
//         }
        
//         return false;
//     }
// };
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        return (s + s).find(goal) != string::npos;
    }
};
int main(){
    Solution s ;
    string str = "abcde";
    string goal = "cdeab";
    cout <<  s.rotateString(str,goal);
}