#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string compressedString(string word) {
        if (word.empty()) return "";
        
        string comp = "";
        int i = 0;

        while (i < word.length()) {
            char letter = word[i];
            int count = 0;

            // Count up to 9 consecutive occurrences of letter
            while (i < word.length() && word[i] == letter && count < 9) {
                count++;
                i++;
            }

            // Append count followed by the character to comp
            comp += to_string(count) + letter;
        }

        return comp;
    }
};

int main() { 
    Solution s;
    
    string word = "abcde";
    cout << s.compressedString(word) << endl;  // Expected output: "1a1b1c1d1e"
    
    word = "aaaaaaaaaaaaaabb";
    cout << s.compressedString(word) << endl;  // Expected output: "9a5a2b"
}
