#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<pair<char, char>> FL;  
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            FL.emplace_back(word.front(), word.back());
        }
        for (int i = 0; i < FL.size(); ++i) {
            char lastchar = FL[i].second;
            char frontchar = FL[(i + 1) % FL.size()].first;
            if (lastchar != frontchar) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    string str = "leetcode exercises sound delightful";
    cout << (s.isCircularSentence(str) ? "true" : "false") << endl;
}
