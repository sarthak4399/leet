#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitcount(24,0);
        for (int candidates_val : candidates) {
        for (int i = 0; i < 24; ++i) {
            if (candidates_val & (1 << i)) { 
                bitcount[i]++;
            }
        }
    }
     return *max_element(bitcount.begin(), bitcount.end());
    }
};
int main(){
    vector<int> candidates = {16,17,71,62,12,24,14};
    Solution s;
    cout << s.largestCombination(candidates) << endl;
    return 0;
}