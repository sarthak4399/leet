#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0 ;
        vector<long long> count(1024, 0);
        count[0] = 1;
        long long mask = 0;
        for(auto ch : word){
            mask ^= 1 << (ch - 'a');
            ans += count[mask];
            for(int i = 0 ; i < 10 ; i++){
                ans += count[mask ^ (1 << i)];
            }
            count[mask]++;
        }
        return ans;

    }
};


int main (){
    Solution s;
    cout << s.wonderfulSubstrings("aba") << endl;
    return 0;
}