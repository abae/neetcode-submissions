/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> seen;
        if (head == nullptr){
            return false;
        }
        while(head->next != nullptr){
            seen.insert(head);
            if (seen.contains(head->next)){
                return true;
            }
            head = head->next;
        }
        return false;
    }
};