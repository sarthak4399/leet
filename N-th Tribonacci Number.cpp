#include <iostream>

class Solution {
public:
    int tribonacci(int n) {
        int array[38];
        array[0] = 0;
        array[1] = 1;
        array[2] = 1;
        for (int i = 3; i <= n; i++) {
            array[i] = array[i - 1] + array[i - 2] + array[i - 3];
        }
        return array[n];


    }
};

int main ( ) {
    Solution s;
    std::cout << s.tribonacci(25) << std::endl;
    return 0;
}