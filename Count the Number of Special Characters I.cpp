#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int count_special_letters(string word) {
        unordered_set<char> special;
        for (int i = 0; i < word.size(); ++i) {
            char lower = tolower(word[i]);
            char upper = toupper(word[i]);
            if (lower != upper && word.find(lower) != string::npos && word.find(upper) != string::npos) {
                special.insert(tolower(word[i]));
            }
        }
        return special.size();
    }
};
int main() {
    Solution sol;
    cout << sol.count_special_letters("aaAbcBC") << endl; // Output: 3
    cout << sol.count_special_letters("abc") << endl;     // Output: 0
    cout << sol.count_special_letters("abBCab") << endl;  // Output: 1
    return 0;
}