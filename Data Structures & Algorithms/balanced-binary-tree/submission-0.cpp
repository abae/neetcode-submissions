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
    int heightDFS(TreeNode* node, bool& balanced){
        if(node == nullptr || !balanced){
            return 0;
        }
        int leftHeight = heightDFS(node->left, balanced);
        int rightHeight = heightDFS(node->right, balanced);
        if(std::abs(leftHeight - rightHeight) > 1){
            balanced = false;
        }
        return std::max(leftHeight, rightHeight) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        heightDFS(root, balanced);
        return balanced;
    }
};
