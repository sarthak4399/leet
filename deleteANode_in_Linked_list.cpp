#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL) {
            return;
        }
        ListNode* temp = node->next;

        if(node == 0){
            node = temp;
            free(temp);
            return;
        }
        for(int i = 0 ; temp != NULL; i++){
            node->val = temp->val;
            if(temp->next == NULL){
                node->next = NULL;
                free(temp);
                return;
            }
            node = node->next;
            temp = temp->next;
        }
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);
    s.deleteNode(head->next, 5);
    cout << "The linked list after deleting the node is: ";
    for (ListNode* temp = head; temp != NULL; temp = temp->next) {
        cout << temp->val << " ";
    }

}