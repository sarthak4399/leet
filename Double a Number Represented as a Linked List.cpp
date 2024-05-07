#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    /**
     * @brief Double the number represented by a linked list and return the result as a linked list.
     * 
     * @param head Head of the linked list representing the number.
     * @return ListNode* Head of the new linked list representing the doubled number.
     */
    ListNode* doubleIt(ListNode* head) {
        if (head == nullptr)
            return head;
        
        ListNode* reversedList = reverseList(head);
        ListNode* current = reversedList;
        ListNode* prev = nullptr;
        int carry = 0;
        
        while (current != nullptr) {
            int sum = current->val * 2 + carry;
            current->val = sum % 10;
            carry = sum / 10;
            prev = current;
            current = current->next;
        }
        
        if (carry > 0) {
            prev->next = new ListNode(carry);
        }
        
        return reverseList(reversedList);
    }
    
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};


int main() {
    ListNode* head = new ListNode();
    Solution s;
    
    cout << "Original List: ";
    for (ListNode* temp = head; temp != NULL; temp = temp->next) {
        cout << temp->val << " ";
    }
    cout << endl;

    ListNode* doubledList = s.doubleIt(head);
    
    cout << "Doubled List (reversed): ";
    for (ListNode* temp = doubledList; temp != NULL; temp = temp->next) {
        cout << temp->val << " ";
    }
    cout << endl;

    return 0;
}