#include <iostream>
#include <vector>


using namespace std ;



class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> result(score.size());
        vector<int> sortedScore(score);
        sort(sortedScore.begin(), sortedScore.end(), greater<int>());
        
        for (int i = 0; i < score.size(); i++) {
            int rank = 1;
            for (int j = 0; j < sortedScore.size(); j++) {
                if (score[i] == sortedScore[j]) {
                    break;
                }
                rank++;
            }
            if (rank == 1) {
                result[i] = "Gold Medal";
            } else if (rank == 2) {
                result[i] = "Silver Medal";
            } else if (rank == 3) {
                result[i] = "Bronze Medal";
            } else {
                result[i] = to_string(rank);
            }
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