#include <iostream>
#include <vector>
using namespace std;
/**
 * @brief A class to solve the rescue boat problem.
 */
class Solution {
    /**
     * @brief A function to solve the rescue boat problem.
     * @param people A vector of integers representing the weight of people.
     * @param limit An integer representing the maximum weight limit of the boat.
     * @return An integer representing the minimum number of boats required to save all people.
    */
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        cout  << "People: " <<" ";
        for (int i = 0; i < people.size(); i++) {
            cout << people[i] << " ";
        }
        cout << endl;
        cout << "limit :  " << limit << endl;
        int i = 0, j = people.size() - 1;

        int boats = 0;

        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                i++;
            }
            j--;
            boats++;
        }
      return boats;      
    }


};


int main () {
    Solution s;
    vector<int> people = {3,2,2,1};
    cout << s.numRescueBoats(people, 3) << endl;
    return 0;
}