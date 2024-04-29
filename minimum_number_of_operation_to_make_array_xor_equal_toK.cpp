#include <iostream>
#include <vector>

using namespace std ;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0 ;
        for (int bit = 0 ; bit <= 20 ; bit++) {
            int xorval =  0 ;
            for( auto el : nums){
                int bit_val = (1<< bit) & el ;
                xorval = xorval ^ bit_val;

            }
            int kBit_val = (1<< bit) & k ;
            if(xorval != kBit_val){
                ans++ ;
            }
            return ans ;
        }
    }
};
int main(){
    Solution s ; ;
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{2,4},{2,5}};
    vector<int> result = s.minOperations(edges,1);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;

}