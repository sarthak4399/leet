#include<iostream>
#include<vector>
using namespace  std ;


class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        if (arr.size() ==0 ) return 0;
        int size =0 ;
        int n = arr.size() ;
        int left = 0 ;
        int right = n-1 ;
        while(left < n-1 && arr[left] <= arr[left+1]) left++ ;
        if (left == n-1) return 0 ;
        while(right > 0 && arr[right] >= arr[right-1]) right-- ;
        size = min(n-left-1, right) ;
        int i = 0 ;
        int j = right ;
        while(i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                size = min(size, j-i-1) ;
                i++ ;
            } else {
                j++ ;
            }
        }

       return size ; 
    }
};

int main() { 
    Solution s ;
    vector <int> arr = {1,2,3,10,4,2,3,5} ;
    cout << s.findLengthOfShortestSubarray(arr) << endl ;
    return 0 ;

}