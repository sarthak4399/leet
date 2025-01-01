#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(const string& s) {
        int n = s.size();
        vector<string> lefts;
        vector<string> rights;
        for (int splitIndex = 1; splitIndex < n; splitIndex++) {
            lefts.push_back(s.substr(0, splitIndex));
            rights.push_back(s.substr(splitIndex));
        }

        int Score = 0;
        for (int i = 0; i < (int)lefts.size(); i++) {
            const string& leftPart = lefts[i];
            const string& rightPart = rights[i];
            int zerosCount = 0;
            for (char c : leftPart) {
                if (c == '0') zerosCount++;
            }
            int onesCount = 0;
            for (char c : rightPart) {
                if (c == '1') onesCount++;
            }
            bestScore = max(bestScore, zerosCount + onesCount);
        }

        return bestScore;
    }
};

int main() {
    Solution s;
    string str = "011101";
    cout << s.maxScore(str) << endl; // Expected output: 5
    return 0;
}