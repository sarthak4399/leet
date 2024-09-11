#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        vector<int> start_bin = cnv2Bin(start);
        vector<int> goal_bin = cnv2Bin(goal);

        if (start_bin.size() < goal_bin.size())
        {
            start_bin.insert(start_bin.begin(), goal_bin.size() - start_bin.size(), 0);
        }
        else if (goal_bin.size() < start_bin.size())
        {
            goal_bin.insert(goal_bin.begin(), start_bin.size() - goal_bin.size(), 0);
        }

        int count = 0;
        for (int i = 0; i < start_bin.size(); i++)
        {
            if (start_bin[i] != goal_bin[i])
            {
                count++;
            }
        }
        return count;
    }

private:
    vector<int> cnv2Bin(int num)
    {
        if (num == 0)
            return vector<int>(0);

        vector<int> binary;
        while (num > 0)
        {
            int remainder = num % 2;
            num = num / 2;
            binary.push_back(remainder);
        }
        
        reverse(binary.begin(), binary.end());
        return binary;
    }
};

int main()
{
    Solution s;
    cout << "Minimum bit flips: " << s.minBitFlips(3, 4) << endl;
    return 0;
}
