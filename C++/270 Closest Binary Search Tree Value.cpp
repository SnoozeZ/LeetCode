/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int rlt = root->val;
        TreeNode *cur = root;
        while(cur){
            if(abs(cur->val - target) < abs(rlt - target))
                rlt = cur->val;
            if(cur->val > target)
                cur = cur->left;
            else
                cur = cur->right;
        }
        return rlt;
    }
};
