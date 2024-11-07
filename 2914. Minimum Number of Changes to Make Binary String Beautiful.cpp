#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int minChanges(string s)
    {
        int n = s.length();
        int changes = 0;
        for (int i = 0; i < n; i += 2)
        {
            int count_0 = (s[i] == '0') + (s[i + 1] == '0');
            int count_1 = 2 - count_0;
            changes += std::min(count_0, count_1);
        }

        return changes;
    };
};

int main()
{
    Solution s;
    string s1 = "1001";
    string s2 = "10";
    string s3 = "0000";

    cout << s.minChanges(s1) << endl;
    cout << s.minChanges(s2) << endl;
    cout << s.minChanges(s3) << endl;

    return 0;
}