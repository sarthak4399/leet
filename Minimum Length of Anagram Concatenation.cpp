#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minAnagramLength(string s) {
        // Function to calculate the greatest common divisor
        auto calculateGCD = [](int a, int b) {
            while (b) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        };

        // Create a frequency count of characters in s
        unordered_map<char, int> charCount;
        for (char c : s)
            charCount[c]++;

        // Calculate the greatest common divisor of counts
        int commonDivisor = charCount[s[0]];
        for (const auto& entry : charCount)
            commonDivisor = calculateGCD(commonDivisor, entry.second);

        // Return the sum of counts divided by the GCD
        return s.length() / commonDivisor;
    }
};
int main () {
    Solution s;
    string string = "leetcode";
    int result = s.minAnagramLength(string);
    cout << "The minimum length of anagram concatenation is: " << result << endl;
    return 0;
};