class Solution {
public:
    int countSpecialLetters(string word) {
        unordered_set<char> seen;
        int count = 0;
        
        for (char c : word) {
            if (isupper(c)) {
                char lower_c = tolower(c);
                if (seen.count(lower_c)) {
                    count++;
                }
            } else {
                seen.insert(c);
            }
        }
        
        return count;
    }
};