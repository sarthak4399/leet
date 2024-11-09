#include<iostream>
#include<vector>
#include<bitset>
using namespace std ;


class Solution {
public:
    long long minEnd(int n, int x) {
        if (n == 1) return x;
        bitset<32> xBits(x);
        long long current = x;
        for (int i = 1; i < n; i++) {
            current++;
            bitset<32> currentBits(current);
            currentBits |= xBits;
            current = currentBits.to_ullong();
        }
        return current ;

    }
};

int main(){
    Solution s;
    int n = 3 ;
    int x = 4 ;
    cout << s.minEnd(3,4);
}