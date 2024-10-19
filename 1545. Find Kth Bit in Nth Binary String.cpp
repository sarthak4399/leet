#include<iostream>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1){
            return '0';
        }
        int len = (1<<n) - 1;
        if(k == len/2 + 1){
            return '1';
        }
        if(k < len/2 + 1){
            return findKthBit(n-1, k);
        }
        return findKthBit(n-1, len-k+1) == '0' ? '1' : '0';
    }
};
int main(){
    Solution s;
    int n = 3, k = 1;
    std::cout<<s.findKthBit(n, k)<<std::endl;
    return 0;
}