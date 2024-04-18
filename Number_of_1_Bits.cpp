#include <iostream>
#include <bitset>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        std::bitset<32> bits(n);
        return bits.count();
    }
};

int main() {
    Solution s;
    uint32_t n = 000;
    int hammingWeight = s.hammingWeight(n);
    std::cout << hammingWeight << std::endl;
    return 0;
}


// Path: Number_of_1_Bits.cpp
