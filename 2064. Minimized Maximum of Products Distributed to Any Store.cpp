#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int left = 1;
        int right = 1e9;
        int res = 0;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (isValid(quantities, mid, n)) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return res;

    }

private:
    bool isValid(vector<int>& quantities, int mid, int n) {
        long long stores = 0;
        for (int qty : quantities) {
            stores += (qty + mid - 1) / mid;  
            if (stores > n) return false;  
        }
        return true;
    }

};
int main(){
    Solution s ;
    vector<int> quantities = {11,6} ;
    cout << s.minimizedMaximum(6, quantities) << endl ;
    return 0 ;
}