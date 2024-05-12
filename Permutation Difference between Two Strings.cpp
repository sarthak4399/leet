#include <iostream>
#include <vector>
using namespace std;
/**
 * @brief The Solution class
 * @details The solution class contains the function findPermutationDifference which takes two strings s and t as input and returns the difference between the permutation of the two strings.
 * @details The function is defined as follows:
 * 1. Create two vectors sIndex and tIndex of size 26 and initialize all elements to -1.
 * 2. For i from 0 to the size of s, do the following:
 * 3. Set sIndex[s[i] - 'a'] to i.
 * 4. Set tIndex[t[i] - 'a'] to i.
 * 5. Create a variable difference and set it to 0.
 * 6. For i from 0 to 26, do the following:
 * 7. If sIndex[i] is not equal to -1 and tIndex[i] is not equal to -1, increment difference by the absolute value of sIndex[i] - tIndex[i].
 * 8. Return difference.
 * @note The time complexity is O(n) and the space complexity is O(1).
*/
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> sIndex(26, -1);
        vector<int> tIndex(26, -1);
        
        for(int i = 0; i < s.size(); ++i) {
            sIndex[s[i] - 'a'] = i;
            tIndex[t[i] - 'a'] = i;
        }
        
        int difference = 0;
        for(int i = 0; i < 26; ++i) {
            if(sIndex[i] != -1 && tIndex[i] != -1) {
                difference += abs(sIndex[i] - tIndex[i]);
            }
        }
        
        return difference;
    }
};
int main(){
    Solution s ;
    string s1 = "abc";
    string s2 = "bac";
    int result = s.findPermutationDifference(s1, s2);
    cout << result << " ";
    return 0;
}