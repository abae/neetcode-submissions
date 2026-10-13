/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> s;
        s.push(root);
        int count = 0;
        while(!s.empty()){
            TreeNode* node = s.top();
            if(node->left){
                s.push(node->left);
                continue;
            }
            do{
                node = s.top();
                ++count;
                if(count == k) return node->val;
                s.pop();
            }while(!node->right);
            s.push(node->right);
        }
        return -1;
    }
};