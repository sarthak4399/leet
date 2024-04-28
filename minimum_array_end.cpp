#include <iostream>

using namespace std;

class Solution {
public:
    long long minEnd(int n, int x) {
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        return sum + x;
        
    }
};

int main (){
    Solution s;
    cout << s.minEnd(3,4) << endl;
}
