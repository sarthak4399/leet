#include<iostream>
#include<vector>
#include<map>

using namespace std;


class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        	map<int,string , greater<int>> mp;
        	vector<string> result ;
        	for (int i = 0; i < names.size(); ++i) {
            mp[heights[i]] = names[i];
        	}
        
	        for (auto& x : mp) {
	            result.push_back(x.second);
	            cout << x.second << endl ;
	            
	        }
	        
	        return result;
        };

};

int main () {
	Solution s ;
	vector<string> namwe = {"Mary","John","Emma"};
	vector<int> heights = {180,165,170} ;

	s.sortPeople(namwe,heights) ;
}