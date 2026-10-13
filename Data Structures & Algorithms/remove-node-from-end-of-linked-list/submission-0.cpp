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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = nullptr;
        ListNode* target = head;
        ListNode* endCheck = head;
        for (int i=0; i<n; i++){
            endCheck = endCheck->next;
        }
        while (endCheck != nullptr){
            endCheck = endCheck->next;
            prev = target;
            target = target->next;
        }
        if (prev == nullptr){
            return head->next;
        }
        prev->next = target->next;
        return head;
    }
};