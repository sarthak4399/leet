#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        cout << nums.size() << endl;
        int size = nums.size();
        int size_temp = 2 * size;
        vector<int> temp(size_temp); 
        
        for(int i = 0; i < size; ++i) {
            temp[i] = nums[i];
            temp[i - size] = nums[i];
        }

        cout << temp.size() << endl;
        return temp;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 1};
    vector<int> result = s.getConcatenation(nums);
    for(int nums :result) {
        cout << nums << " ";
    }
    cout << endl;

    return 0;
}
