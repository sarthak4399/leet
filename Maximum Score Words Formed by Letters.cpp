#include <iostream>
#include <vector>
using namespace std ;

class Solution {
public:
    int a[26], b[26], ans = 0;
    void solve(int idx, vector<string>& words, vector<int>& score) {
        if (idx == words.size()) {
            int sc = 0;
            for (int i = 0; i < 26; i++) {
                if (b[i] > a[i])return;
                sc += score[i] * b[i];
            }
            ans = max(ans, sc);
            return;
        }
        solve(idx + 1, words, score);
        for (auto i : words[idx]) b[i - 'a']++;
        solve(idx + 1, words, score);
        for (auto i : words[idx]) b[i - 'a']--;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for (auto i : letters) a[i - 'a']++;
        solve(0, words, score);
        return ans;
    }
};
int main(){
    Solution s ;
    vector<string> words = {"dog","cat","dad","good"};
    vector<char> letters = {'a','a','c','d','d','d','g','o','o'};
    vector<int> score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    cout << s.maxScoreWords(words, letters, score) << endl;
}