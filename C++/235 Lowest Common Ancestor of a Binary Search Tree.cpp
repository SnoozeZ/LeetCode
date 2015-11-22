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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca=nullptr;
        dfs(root, p, q, lca);
        return lca;
    }
    
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode *&lca){
        if(!root || lca!=nullptr) return;
        if(p->val > root->val && q->val > root->val) return dfs(root->right, p, q, lca);
        if(p->val < root->val && q->val < root->val) return dfs(root->left, p, q, lca);
        
        lca = root;
    }
};
