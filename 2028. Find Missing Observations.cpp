#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += rolls[i];
        }
        int total = mean * (m + n);
        int remain = total - sum;
        if (remain < n || remain > 6 * n) {
            return {};
        }
        vector<int> res(n, remain / n);
        for (int i = 0; i < remain % n; i++) {
            res[i]++;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> rolls = {3, 2, 4, 3};
    int mean = 4;
    int n = 2;
    vector<int> res = solution.missingRolls(rolls, mean, n);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}