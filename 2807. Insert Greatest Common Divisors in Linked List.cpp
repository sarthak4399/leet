#include <iostream>
#include <vector>
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head) {
            return head;}
        ListNode* cur = head;
        while (cur->next) {
            int gcd_node = gcd(cur->val, cur->next->val);
            ListNode* node = new ListNode(gcd_node);
            node->next = cur->next;
            cur->next = node;
            cur = cur->next->next;
        }
        return head;
    }
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

};

int main(){
    Solution s ;
    ListNode* head = new ListNode(18) ;
    head->next = new ListNode(6) ;
    head->next->next = new ListNode(10) ;
    head->next->next->next = new ListNode(3) ;

    ListNode* res = s.insertGreatestCommonDivisors(head) ;
    while(res) {
        cout << res->val << " " ;
        res = res->next ;
    }
    cout << endl ;
    return 0 ;
}