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
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        std::stack<std::tuple<TreeNode*, long long, long long>> s;
        s.push({root, LLONG_MIN, LLONG_MAX});
        while(!s.empty()){
            auto [node, lower, upper] = s.top();
            s.pop();

            if(node->val >= upper || node->val <= lower){
                return false;
            }
            if(node->left) s.push({node->left, lower, node->val});
            if(node->right) s.push({node->right, node->val, upper});
        }
        return true;
    }
};