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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> q;
        for(auto list : lists){
            while(list){
                q.push(list->val);
                list = list->next;
            }
        }
        if(q.empty()){
            return nullptr;
        }
        ListNode* result = new ListNode(q.top());
        ListNode* curr = result;
        q.pop();
        while(!q.empty()){
            curr->next = new ListNode(q.top());
            curr = curr->next;
            q.pop();
        }
        return result;
    }
};