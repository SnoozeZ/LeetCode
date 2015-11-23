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
    bool isBalanced(TreeNode* root) {
        bool balance=true;
        dfs(root, balance);
        return balance;
    }
    
    int dfs(TreeNode* root, bool& balance){
        if(!root || !balance) return 0;
        int left = dfs(root->left, balance);
        int right = dfs(root->right, balance);
        if(abs(left-right) > 1) balance = false;
        return max(left+1, right+1);
    }
};
