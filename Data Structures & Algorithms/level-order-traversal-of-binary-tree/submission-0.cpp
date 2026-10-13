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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        std::queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> out;
        while(!q.empty()){
            int levelSize = q.size();
            vector<int> subOut;
            for(int i = 0; i < levelSize; ++i){
                TreeNode* node = q.front();
                q.pop();

                subOut.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            out.push_back(subOut);
        }
        return out;
    }
};