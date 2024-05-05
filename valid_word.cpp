
#include <iostream>
#include <string>
#include <cctype> 
#include <unordered_set>
  
using namespace std;

// It contains a minimum of 3 characters.
// It consists of the digits 0-9, and the uppercase and lowercase English letters. (Not necessary to have all of them.)
// It includes at least one vowel.
// It includes at least one consonant.
// This word contains a '$' character and does not have a consonant.
class Solution {
public:
    public:
    bool isValid(string word) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        bool has_vowel = false;
        bool has_consonant = false;
        
        if (word.size() < 3)
            return false;
        
        for (char c : word) {
            if (isalpha(c)) {
                if (vowels.count(c))
                    has_vowel = true;
                else
                    has_consonant = true;
            } else if (isdigit(c)) {
                continue;
            } else {
                return false; 
            }
        }
        
        return has_vowel && has_consonant;
    }

};

int main(){
    Solution s;
    string word = "a3$e";
    bool result = s.isValid(word);
    cout << "The word is: " << result << endl;
    return 0;
}