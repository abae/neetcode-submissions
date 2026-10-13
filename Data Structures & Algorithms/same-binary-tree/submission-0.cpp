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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == q){
            return true;
        }
        if(!p || !q){
            return false;
        }
        std::stack<TreeNode*> s;
        s.push(p);
        s.push(q);

        while(!s.empty()){
            int size = s.size() / 2;
            for(int i=0; i<size; ++i){
                TreeNode* qNode = s.top();
                s.pop();
                TreeNode* pNode = s.top();
                s.pop();

                bool checkValue = pNode->val == qNode->val;
                bool checkLeft = (pNode->left && qNode->left) || (!pNode->left && !qNode->left);
                bool checkRight = (pNode->right && qNode->right) || (!pNode->right && !qNode->right);
                //std::cout << pNode->val << checkValue << checkRight << std::endl;
                if (checkValue && checkLeft && checkRight){
                    if(pNode->left){
                        s.push(pNode->left);
                        s.push(qNode->left);
                    }
                    if(pNode->right){
                        s.push(pNode->right);
                        s.push(qNode->right);
                    }
                }else{
                    return false;
                }

            }
        }
        return true;
    }
};