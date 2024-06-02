#include<iostream>
#include<bitset>
#include <vector>
using namespace std ;
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size() ;
        int count = 0 ;
        for (int i = 0 ; i < n ; i++){
            int xor_sum = arr[i] ;
            for (int j = i+1 ; j < n ; j++){
                xor_sum ^= arr[j] ;
                if (xor_sum == 0){
                    count += j-i ;
                }
            }
        }
        return count ;
    }
};
int main(){
    Solution s ;
    vector<int> arr = {2,3,1,6,7} ;
    cout << s.countTriplets(arr) << endl ;
    return 0 ;
}