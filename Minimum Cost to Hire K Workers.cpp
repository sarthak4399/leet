#include <iostream>
#include <vector>
#include <queue>

using namespace std ;
/**
 * @brief  This is a class Solution which contains a function mincostToHireWorkers which takes in a vector of integers quality, vector of integers wage and an integer k as input and returns a double value.
 * @param quality vector of integers
 * @param wage vector of integers
 * @param k integer
 * @return double
 * @note    The function is defined as follows: 
 * 1. Create a priority queue pq.
 * 2. Create a vector of pairs of double and int workers_with_wagebyquality_quality.
 * 3. For each element in quality, push the pair of double and int in workers_with_wagebyquality_quality.
 * 4. Sort the workers_with_wagebyquality_quality.
 * 5. Create a double variable sum_quality and initialize it to 0.
 * 6. Create a double variable res and initialize it to __DBL_MAX__.
 * 7. For each element in workers_with_wagebyquality_quality, do the following:
 * 8. Increment sum_quality by workers_with_wagebyquality_quality.second.
 * 9. Push workers_with_wagebyquality_quality.second in pq.
 * 10. If the size of pq is greater than k, decrement sum_quality by pq.top() and pop pq.
 * 11. If the size of pq is equal to k, update res to the minimum of res and workers_with_wagebyquality_quality.first * sum_quality.
 * 12. Return res.
 * @timeComplexity O(nlogn)
 * @spaceComplexity O(n)
*/
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
            priority_queue<int> pq ;
            vector<pair <double,int>> workers_with_wagebyquality_quality;
            for(int i =0 ; i < quality.size(); i++){
                // cout << quality[i] <<  " is "  << wage[i] << " " ;
                workers_with_wagebyquality_quality.push_back({(double)wage[i]/quality[i], quality[i]});
            }
            sort(workers_with_wagebyquality_quality.begin(),workers_with_wagebyquality_quality.end());
            double sum_quality=0;
            double res= __DBL_MAX__;  // __DBL_MAX__ = 1.79769e+308 maximum finte value of double ;
            for(auto workers_with_wagebyquality_quality:workers_with_wagebyquality_quality ){
                sum_quality +=workers_with_wagebyquality_quality.second;
                pq.push(workers_with_wagebyquality_quality.second);
                if(pq.size()>k )sum_quality -= pq.top() ,pq.pop();
                if(pq.size()==k)res = min(res,workers_with_wagebyquality_quality.first*sum_quality);
            }
            return res ;
    }
};


int main(){
    Solution s ;
    vector<int> quality = {3,1,10,10,1} ;
    vector<int> wages = {4,8,2,2,7} ;
    int k = 3 ;
    int result = s.mincostToHireWorkers(quality,wages ,k);
    cout << result << " ";
}