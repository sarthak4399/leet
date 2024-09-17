#include <iostream>
#include <vector> 
#include <algorithm>
using  namespace  std ;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time ;
        for (int i = 0 ; i < timePoints.size() ; i++) {
            int hour = stoi(timePoints[i].substr(0,2)) ;
            int minute = stoi(timePoints[i].substr(3,2)) ;
            time.push_back(hour*60 + minute) ;
        }
        sort(time.begin(), time.end()) ;
        int res = INT_MAX ;
        for (int i = 1 ; i < time.size() ; i++) {
            res = min(res, time[i] - time[i-1]) ;
        }
        res = min(res, time[0] + 1440 - time[time.size()-1]) ;

        return res ;
    }
};

int main() {
    Solution s ;
    vector <string> timePoints = {"23:59","00:00"} ;
    cout << s.findMinDifference(timePoints) << endl ;
    return 0 ;
}

