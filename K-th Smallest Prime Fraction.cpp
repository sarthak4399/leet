#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k){
        // sort(arr.begin(),arr.end(),greater<int>());
        priority_queue<pair<float,pair<float,float>>, vector<pair<float,pair<float,float>>> , greater<pair<float,pair<float,float>>>> pq;
        vector<int> ans ;
        for(int i = 0;i<arr.size()-1;i++){
            // cout << arr[i] << endl;
            for(int j = i+1;j<arr.size();j++){
                // cout << arr[j] << endl ;
                float fraction = static_cast<float>(arr[i]) / arr[j];
                cout << arr[i] << "/" << arr[j] << " : " << fraction << endl ;
                pq.push({fraction, {arr[i],arr[j]}});
                cout << "Priority Queue: ";
                while (!pq.empty()) {
                    auto topElement = pq.top();
                    cout << topElement.first << " (" << topElement.second.first << "/" << topElement.second.second << ") ";
                    pq.pop();
                }
                cout << endl;
                }
        }
        while (k > 1) {
            pq.pop();
            k--;
        }
        ans.push_back(pq.top().second.first);
        ans.push_back(pq.top().second.second);
        return ans;
    }
};
  

int main() {
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5};
    int K = 3;
    s.kthSmallestPrimeFraction(arr, K);
}
