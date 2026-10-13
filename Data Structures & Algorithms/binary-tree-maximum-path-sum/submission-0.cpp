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
private:
    int maxPath_ = INT_MIN;

    int dfs(TreeNode* node){
        int leftDepth = 0;
        int rightDepth = 0;
        if(node->left){
            leftDepth = std::max(0, dfs(node->left));
        }
        if(node->right){
            rightDepth = std::max(0, dfs(node->right));
        }
        maxPath_ = std::max(maxPath_, leftDepth + rightDepth + node->val);
        return node->val + std::max(leftDepth, rightDepth);
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxPath_;
    }
};