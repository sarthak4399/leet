#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> phone = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        result.push_back("");
        
        for (char digit : digits) {
            int digitValue = digit - '0';
            cout << digitValue << endl;
            if (digitValue < 2 || digitValue > 9) continue; 

            vector<string> temp;
            for (const string& combination : result) {
                for (char letter : phone[digitValue]) {
                    temp.push_back(combination + letter);
                }
            }
            result.swap(temp);
        }

        return result;
    }
};

int main() {
    Solution s;
    string digits = "25678";
    vector<string> result = s.letterCombinations(digits);
    for (const string& combination : result) {
        cout << combination << endl;
    }
    return 0;
}
