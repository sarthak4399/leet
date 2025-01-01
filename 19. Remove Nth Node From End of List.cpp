#include<iostream>
#include<vector>
#include<algorithm>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
    }
};


int main(){
	Solution s ;
	vector<int> v = {1,2,3,4,5} ;
	ListNode* head = new ListNode(v[0]) ;
	ListNode* temp = head ;
	for(int i=1 ; i<v.size() ; i++){
		temp->next = new ListNode(v[i]) ;
		temp = temp->next ;
	}
	int n = 2 ;
	ListNode* ans = s.removeNthFromEnd(head,n) ;
	while(ans!=NULL){
		cout<<ans->val<<" " ;
		ans = ans->next ;
	}
	return 0 ;
	
}