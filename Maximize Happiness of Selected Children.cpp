#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

/**
     * @brief Calculate the maximum happiness sum.
     * Given a vector of happiness values for children and an integer k,
     * this function calculates the maximum sum of happiness by selecting
     * k children according to the following rules:
     * - Select the child with the maximum happiness value.
     * - Decrease the happiness of the selected child by 1 and 
     *   the happiness of all other children by 1.
     * - The happiness of a child cannot become less than 0.
     * 
     * @param happiness Vector of happiness values for children.
     * @param k Number of children to select.
     * @return Maximum sum of happiness.
     */

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int number_ofSelections = k;
        cout << number_ofSelections << endl ;
        sort(happiness.begin(),happiness.end(),greater<int>());
        vector<bool> slected_childs(happiness.size(),false);
        long long ans  = 0 ;
        int ccount = 0 ;
        for(int i =0 ; i <happiness.size(); i++){
            if(!slected_childs[i]){
                ans += max(0,happiness[i]-ccount) ;
                ++ccount;
                slected_childs[i] =true ;
                if (ccount>=k){
                    break ;
                }
            }
        }
        return ans ;
    }
};


int main () {
    Solution s ;
    vector<int> Happiness={1,2,3};
    int K = 2  ;
   cout << s.maximumHappinessSum(Happiness,K)<<endl ;
}