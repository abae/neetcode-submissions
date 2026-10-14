/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        std::unordered_map<Node*, Node*> n2n;
        Node* curr = new Node(head->val);
        Node* result = curr;
        Node* old = head;
        while(old != nullptr){
            n2n.insert({old, curr});
            if(old->next != nullptr){
                curr->next = new Node(old->next->val);
            }
            curr = curr->next;
            old = old->next;
        }
        curr = result;
        old = head;
        while(old != nullptr){
            curr->random = n2n[old->random];
            curr = curr->next;
            old = old->next;
        }
        
        return result;
    }
};
