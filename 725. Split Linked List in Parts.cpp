#include <iostream>


#include<vector>

using namespace std ; 



struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {} 
};
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
    for (i = 0; i < k; i++) {
      cout << "node " <<i << endl ;

    }  
  }
};


int main(){
  Solution s ;
   
   

  s.splitListToParts();

}


