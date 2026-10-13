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
private:

public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr and fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = slow;
        ListNode* curr = slow->next;
        prev->next = nullptr;
        while (curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* left = head;
        ListNode* right = prev;
        while (right->next != nullptr){
            ListNode* nextLeft = left->next;
            ListNode* nextRight = right->next;
            left->next = right;
            right->next = nextLeft;
            left = nextLeft;
            right = nextRight;
        }
    }
};