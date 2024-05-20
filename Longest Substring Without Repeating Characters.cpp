#include <iostream>
#include <vector>
#include <string>

using namespace std ;
 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> index(128, -1);
        for(int i = 0, j = 0; j < n; j++) {
            i = max(i, index[s[j]] + 1);
            ans = max(ans, j - i + 1);
            index[s[j]] = j;
        }
        return ans;
    }
};


int main(){
    Solution s ;
    string str = "abcabcbb";
    cout << s.lengthOfLongestSubstring(str) << endl ;
    return 0;
}