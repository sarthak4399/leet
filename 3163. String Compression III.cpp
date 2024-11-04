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
            while (i < word.length() && word[i] == letter && count < 9) {
                count++;
                i++;
            }
            comp += to_string(count) + letter;
        }

        return comp;
    }
};

int main() { 
    Solution s;
    
    string word = "abcde";
    cout << s.compressedString(word) << endl; 

    word = "aaaaaaaaaaaaaabb";
    cout << s.compressedString(word) << endl;  
    
    }
