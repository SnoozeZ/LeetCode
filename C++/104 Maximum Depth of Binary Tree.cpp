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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int max=INT_MIN;
        dfs(root, 0, max);
        return max;
    }
    
    void dfs(TreeNode* root, int cur, int& max){
        if(!root) return;
        cur++;
        max = cur>max ? cur : max; 
        
        if(root->left) dfs(root->left, cur, max);
        if(root->right) dfs(root->right, cur, max);
    }
};
