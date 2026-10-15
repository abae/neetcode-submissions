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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        ListNode* result = new ListNode(l1->val + l2->val);
        ListNode* curr = result;
        bool tens = false;
        if(curr->val >= 10){
            curr->val -= 10;
            tens = true;
        }
        if(l1){l1 = l1->next;}
        if(l2){l2 = l2->next;}
        while(l1 || l2 || tens){
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int newVal = v1 + v2 + (tens ? 1 : 0);
            if(newVal >= 10){
                newVal -= 10;
                tens = true;
            }else{
                tens = false;
            }
            curr->next = new ListNode(newVal);
            curr = curr->next;
            if(l1){l1 = l1->next;}
            if(l2){l2 = l2->next;}
        }
        return result;
    }
};
