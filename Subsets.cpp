#include <iostream>
#include <vector>
using namespace std ;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}};

        for (int num : nums) {
            int n = result.size();
            for (int i = 0; i < n; ++i) {
                vector<int> subset = result[i];
                subset.push_back(num);
                result.push_back(subset);
            }
        }

        return result;
    }
};

int main(){
    Solution s ;
    vector<int >vector = {1,2,3};
    s.subsets(vector);
}