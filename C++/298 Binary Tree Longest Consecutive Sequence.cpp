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
    int longestConsecutive(TreeNode* root) {
        int rlt=-1;
        if(!root) return 0;
        dfs(root, 1, rlt);
        return rlt;

    }
    void dfs(TreeNode *root, int len, int& rlt){
        rlt = max(rlt, len);
        if(root->left){
            if(root->val + 1 == root->left->val){
                dfs(root->left, len+1, rlt);
            }else{
                dfs(root->left, 1, rlt);
            }
        }
        
        if(root->right){
            if(root->val + 1 == root->right->val){
                dfs(root->right, len+1, rlt);
            }else{
                dfs(root->right, 1, rlt);
            }
        }
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        int result=0;
        dfs(root, result, 1);
        return result;
    }
    
    void dfs(TreeNode *root, int &result, int cur) {
        if(cur > result) result = cur;
        if(root->left) {
            dfs(root->left, result, (root->val+1 == root->left->val) ? cur+1 : 1);
        }
        if(root->right) {
            dfs(root->right, result, (root->val+1 == root->right->val) ? cur+1 : 1);
        }
    }
};*/
