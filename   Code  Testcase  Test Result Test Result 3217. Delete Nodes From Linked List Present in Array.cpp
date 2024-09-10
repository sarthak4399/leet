#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};



class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        while(curr) {
            if(find(nums.begin(), nums.end(), curr->val) != nums.end()) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};