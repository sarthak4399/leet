#include <iostream>
#include <vector>
using namespace std ;



class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();
        vector<int> res(m, 0);
        for(int i = 0; i < m; i++) {
            int q = queries[i];
            int maxBeauty = 0;
            for(int j = 0; j < n; j++) {
                int beauty = 0;
                bool found = false;
                for(int k = 0; k < items[j].size(); k++) {
                    if(items[j][k] == q) {
                        if(!found) {
                            beauty += q;
                            found = true;
                        }
                        beauty += q;
                    } else if(items[j][k] > 0) {
                        beauty += items[j][k];
                    }
                }
                if(found) {
                    maxBeauty = max(maxBeauty, beauty);
                }
            }
            res[i] = maxBeauty;
        }
        return res;
    }
};
int main(){
    Solution s ;
    vector<vector<int>> items = {{10,1000}} ;
    vector<int> queries = {2,3} ;
    vector<int> res = s.maximumBeauty(items, queries) ;
    for(auto i : res) cout << i << " " ;
    cout << endl ;
    return 0 ;
}