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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* result = head;
        std::stack<ListNode*> hist;
        bool firstPass = true;
        ListNode* prev;
        ListNode* next;
        while(head){
            hist.push(head);
            if(hist.size() >= k){
                bool newReverse = true;
                next = head->next;
                while(!hist.empty()){
                    ListNode* node = hist.top();
                    hist.pop();
                    if(newReverse){
                        if(firstPass){
                            result = node;
                            firstPass = false;
                        }else{
                            prev->next = node;
                        }
                        newReverse = false;
                    }
                    if(!hist.empty()){
                        node->next = hist.top();
                    }else{
                        prev = node;
                        prev->next = next;
                        head = prev;
                    }
                }

            }
            head = head->next;
        }
        return result;
    }
};
