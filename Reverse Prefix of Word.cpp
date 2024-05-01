#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size() ;
        int i = 0 ;
        for(i = 0 ; i < n ; i++){
            if(word[i] == ch){
                break;
                cout << "i: " << i << endl; 
                // cout << "word[i] : " << word[i] << endl;
            }
        }
        if(i == n){

            return word ;
        }
        string ans = "";

        for(int j = i ; j >= 0 ; j--){
            ans += word[j];
            // cout << "ans first ffor : " << ans << endl;
        }
        for(int j = i+1 ; j < n ; j++){
            ans += word[j];
            // cout << "ans second for : " << ans << endl;
        }
        return ans;
    }
};

int main(){
    Solution s ;
    cout << s.reversePrefix("abcdef", 'd') << endl;
    return 0;
}
