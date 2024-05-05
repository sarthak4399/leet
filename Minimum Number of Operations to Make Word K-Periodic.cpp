#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size();
        unordered_map<string, int> segmentFrequencyMap;
        
        // Extract segments and count their frequencies
        for (int i = 0; i < n; i += k) {
            string segment = word.substr(i, k);
            segmentFrequencyMap[segment]++;
        }
        
        // Find the segment with the maximum frequency
        int maxSegmentFrequency = 0;
        for (const auto& pair : segmentFrequencyMap) {
            maxSegmentFrequency = max(maxSegmentFrequency, pair.second);
        }
        
        // The minimum number of operations needed is the number of segments
        // minus the number of times the most frequent segment appears
        return (n / k) - maxSegmentFrequency;
    }
};
int main() {
    Solution s;
    string word = "abacaba";
    int k = 2;
    cout << s.minimumOperationsToMakeKPeriodic(word, k) << endl;
    return 0;
}