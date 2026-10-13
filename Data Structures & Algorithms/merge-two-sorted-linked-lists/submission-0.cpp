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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* start = new ListNode();
        ListNode* merged = start;
        while(list1 != nullptr || list2 != nullptr){
            int n1 = list1 == nullptr ? 101 : list1->val;
            int n2 = list2 == nullptr ? 101 : list2->val;
            if(n1 <= n2){
                merged->next = new ListNode(list1->val);
                merged = merged->next;
                list1 = list1->next;
            }else{
                merged->next = new ListNode(list2->val);
                merged = merged->next;
                list2 = list2->next;
            }
        }
        return start->next;
    }
};