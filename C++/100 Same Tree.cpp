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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs((bool)p, (bool)q);
    }
    bool dfs(TreeNode *p, TreeNode *q){
        if(p ^ q) return false;
        if(!p) return true;
        
        if(p->val != q->val) return false;
        return dfs(p->left, q->left)&&dfs(p->right, q->right);
    }
};
