#include <iostream>
#include <vector>
#include <algorithm>
#include <map>



using namespace std ;


class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

    	std::vector<int> result ;
    	std::map<int, int> arr1_map;
    	for(auto x : arr1)
    		arr1_map[x]++;
    	for(auto y : arr2)
    		if (arr1_map.find(y)!=arr1_map.end())
    		{
    			auto x = arr1_map.find(y);
    			int count = x->second ;
    			vector <int> v(count,y);
    			result.insert(result.end(),v.begin(),v.end());
    			arr1_map.erase(y);

    		}
        for (auto x : arr1_map)
        {
        	int ele = x.first;
        	int count = x.second;
        	vector<int> v(count,ele);
        	result.insert(result.end(),v.begin(),v.end());

        } return result;
    }
};
int main(){
	Solution s ;
	vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
	vector<int> arr2 = {2,1,4,3,9,6};
	s.relativeSortArray(arr1,arr2);
}
