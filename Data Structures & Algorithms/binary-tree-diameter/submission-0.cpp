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
    int maxDiameterDFS(TreeNode* node, int& maxDia){
        if(node == nullptr){
            return 0;
        }
        int leftHeight = maxDiameterDFS(node->left, maxDia);
        int rightHeight = maxDiameterDFS(node->right, maxDia);
        maxDia = std::max(maxDia, leftHeight + rightHeight);
        return std::max(leftHeight, rightHeight) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        maxDiameterDFS(root, maxDia);
        return maxDia;
    }
};
