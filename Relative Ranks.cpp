#include <iostream>
#include <vector>
#include <map>

using namespace std ;
/**
 * @brief : Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
 * @param : vector<int> score
 * @return : vector<string> result
 * @note : The N is a positive integer and won't exceed 10,000. All the scores of athletes are guaranteed to be unique.
 * @example : Input: [5, 4, 3, 2, 1] Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
    * @algorithm1:
    * 1. Create a vector to store the result.
    * 2. Create a vector to store the sorted score.
    * 3. Sort the score in descending order.
    * 4. Iterate the score and assign the rank to the result.
    * 5. If the rank is 1, assign "Gold Medal" to the result.
    * 6. If the rank is 2, assign "Silver Medal" to the result.
    * 7. If the rank is 3, assign "Bronze Medal" to the result.
    * 8. If the rank is greater than 3, assign the rank to the result.
    * 9. Return the result.
    * 
    * @algorithm2:  
    * 1. Create a map to store the score and the index of the score.
    * 2. Sort the map in descending order.
    * 3. Iterate the map and assign the rank to the index of the score.
    * 4. If the rank is 1, assign "Gold Medal" to the index.
    * 5. If the rank is 2, assign "Silver Medal" to the index.
    * 6. If the rank is 3, assign "Bronze Medal" to the index.
    * 7. If the rank is greater than 3, assign the rank to the index.
    * 8. Return the result.
*/


class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // vector<string> result(score.size());
        // vector<int> sortedScore(score);
        // sort(sortedScore.begin(), sortedScore.end(), greater<int>());
        
        // for (int i = 0; i < score.size(); i++) {
        //     int rank = 1;
        //     for (int j = 0; j < sortedScore.size(); j++) {
        //         if (score[i] == sortedScore[j]) {
        //             break;
        //         }
        //         rank++;
        //     }
        //     if (rank == 1) {
        //         result[i] = "Gold Medal";
        //     } else if (rank == 2) {
        //         result[i] = "Silver Medal";
        //     } else if (rank == 3) {
        //         result[i] = "Bronze Medal";
        //     } else {
        //         result[i] = to_string(rank);
        //     }
        // }
        
        // return result;
        // by using the map 
        vector<string> result(score.size());
        map<int, int> scoreMap;
        for (int i = 0; i < score.size(); i++) {
            scoreMap[score[i]] = i;
        }
        int rank = 1;
        for (auto it = scoreMap.rbegin(); it != scoreMap.rend(); it++) {
            if (rank == 1) {
                result[it->second] = "Gold Medal";
            } else if (rank == 2) {
                result[it->second] = "Silver Medal";
            } else if (rank == 3) {
                result[it->second] = "Bronze Medal";
            } else {
                result[it->second] = to_string(rank);
            }
            rank++;
        }
        return result;
    }
};

int main() {
    Solution s ;
    vector<int> score = {5, 4, 3, 2, 1} ;
    vector<string> result = s.findRelativeRanks(score) ;
    for (string s : result) {
        cout << s << " " ;
    }
    cout << endl ;
    return 0 ;
}