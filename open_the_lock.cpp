#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int openLock(vector<string> deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        unordered_set<string> visited{"0000"};

        while (!q.empty()) {
            auto [current, turns] = q.front();
            q.pop();

            if (current == target) return turns;

            if (dead.count(current)) continue;

            for (int i = 0; i < 4; ++i) {
                for (int j = -1; j <= 1; j += 2) {
                    string new_wheel = current;
                    new_wheel[i] = (new_wheel[i] - '0' + j + 10) % 10 + '0';
                    if (!visited.count(new_wheel)) {
                        visited.insert(new_wheel);
                        q.push({new_wheel, turns + 1});
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    Solution s;
    cout << s.openLock(deadends, target) << endl;
    return 0;
}
