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
    bool hasPathSum_old(TreeNode* root, int sum) {
        return DFSHelper(root,0,sum);
    }
    bool DFSHelper(TreeNode* node, int value, int sum){
        if(!node) return false;
        value += node->val;
        if(!node->left && !node->right){
            if(value == sum) return true;
            else return false;
        }
        return DFSHelper(node->left, value, sum) || DFSHelper(node->right, value, sum);
    }
};