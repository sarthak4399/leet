#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    map<int, int> countOccurrences(vector<int>& nums) {
        map<int, int> occurrences;
        for (int num : nums) {
            occurrences[num]++;
        }
        
        map<int, int> result;
        for (auto& pair : occurrences) {
            if (pair.second == 1) {
                result.insert(pair);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,2,3};
    map<int, int> occurrences = s.countOccurrences(nums);

    for (auto& pair : occurrences) {
        cout << pair.first << endl;
    }
    return 0;
}
