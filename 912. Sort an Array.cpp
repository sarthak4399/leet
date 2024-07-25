#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            return nums;

    }
};


int main(){
    Solution s ;

    vector<int> arr1 = { 5,2,3 ,1 };
    s.sortArray(arr1); 
    for (int i = 0 ; i<arr1.size();i++){
        cout << arr1[i] << " " ;
    }
}